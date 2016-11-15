/* =========================================================================== *
 *                                                                             *
 *                          M A I R E . C P P                                  *
 *                                                                             *
 *   A CELL-CENTERED LAGRANGIAN SCHEME FOR TWO-DIMENSIONAL                     *
 *   COMPRESSIBLE FLOW PROBLEMS                                                *
 *                                                                             *
 *   P-H Maire, R Abgrall, J Breil, J. Ovadia                                  *
 *                                                                             *
 *   SIAM J. Sci. Computing                                                    *
 *   Vol. 29, No. 4, pp. 1781-1824                                             *
 *                                                                             *
 *     cell-centered properties:  density, momentum, total energy              *
 *     vertex velocitie and flux are computed dependently at the nodes         *
 *       using an original solver                                              *
 *                                                                             *
 *     primary new feature is the introduction of four pressures at each edge  *
 *     1. ensures conservation of momentum and total energy                    *
 *     2. a semidiscrete entropy inequality is enforced                        *
 *                                                                             *
 *                                                                             *
 *    Cell-Centered Hydro Notes                                                *
 *                                                                             *
 *    S. Runnels                                                               *
 *    June 7, 2010                                                             *
 *                                                                             *
 *                                                            Daniel Topa      *
 *                                                                             *
 *                                              Created on  April  6, 2011     *
 *                                              Modified on April 10, 2011     *
 *                                                                             *
 * =========================================================================== *
 */

/*
 * Basic data structures for the hydrodynamics problem
 *
 *  Vector       n-vector of doubles for position and derivatives
 *  Doublet      inventory (item, number of instances)
 *  Census       mesh structure with census of vertices, faces and cells
 *  Vertex       face and cell memberships, vertex positions, velocities
 *  face         endpoints, length, cell membership
 *  Cell         vertex and face membership, intensive and extensive properties
 *  Mesh         aggregate material properties: momentum, temperature, mass, age
 *
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <list>      // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator>  // ostream_iterator

#define spatial_dimension 2

using namespace std;
// n-vector, a fundamental data type
struct Vector
{
    double x;
    double y;
};

// inventory structure
struct Doublet
{
    int index;                                // specify item
    int census;                               // specify count
};

// fundamental mesh construct for the problem
// mesh evolves as vertices and faces are created and annihilated
struct Census
{
    int index;                                // unique identifier

    // track mesh version (version, persistence in cycles)
    vector<Doublet> tag;                      // record index at each time step

    int nVerts;                               // number of vertices
    int nCells;                               // number of cells
    int nFaces;                               // number of faces
};

// a vertex joins at least two faces
struct Vertex
{
    int index;                                // unique identifier - 1:nVerts

    Vector loc;                               // location in space
    // first time derivative
    Vector vel;                               // velocity in space
    Vector vel2;                              // velocity squared for s.d.
    // second time derivative
    Vector acc;                               // acceleration = velocity change
    Vector acc2;                              // acceleration squared for s.d.

    vector<int> faces;                        // index of faces which claim me
    vector<int> cells;                        // index of cells which claim me

    // scalar properties
    double mass;                              // in the staggered cell sense

    bool boundary;                            // is this a boundary point?
};

// a face joins exactly two vertices
struct Face
{
    int index;                                // unique identifier - 1:nfaces

    int cells[2];                             // index of cells which claim me
    int verts[2];                             // index of terminating vertices

    // used to compute slope and normal
    // avoid storing infinite numbers
    Vector delta;                             // endpoint differences
    Vector midpoint;                          // superfluous?

    double length;                            // Euclidean length
    double length2;                           // Euclidean length squared

    bool boundary;                            // is this on an edge?
};

// cells represent a constant mass partition of the media
struct Cell
{
    int index;                                // unique identifier - 1:nCells

    vector<int> verts;                        // ordered list of vertex indices

    // list quantities
    Vector loc;                               // location in space (centroid)
    // first time derivative
    Vector vel;                               // velocity in space
    Vector vel2;                              // velocity squared for s.d.
    // second time derivative
    Vector acc;                               // acceleration = velocity change
    Vector acc2;                              // acceleration squared for s.d.

    Vector geo;                               // geometric mean of vertices

    // scalar properties
    double area;
    double perimeter;                         // sum of all the edge lengths

    // scalar state variables
    double density;
    double pressure;
    double intenergy;
    double temperature;
};

// agregate properties for the mesh
struct Mesh
{
    // mesh objects
    vector<Vertex> vertex;                     // collection of vertices
    vector<Face> face;                         // collection of faces
    vector<Cell> cell;                         // collection of cells

    // populations of vertices, faces, cells
    Census counts;

    // first time derivative
    Vector vel;                               // velocity in space
    Vector vel2;                              // velocity squared for s.d.
    // second time derivative
    Vector acc;                               // acceleration = velocity change
    Vector acc2;                              // acceleration squared for s.d.

    int age;                                   // age in ticks

    double area;                               // total area of all cells
    double perimeter;                          // total perimeter of all cells
    double mass;                               // total mass of all cells
    double internalenergy;                     // internal energy of all cells
};
/*
 *  compatibility issues:
 *  M_PI  constant may not be in all math.h releases (Asin(-1) next)
 */
int init;

int main(int argc, char *argv[], char *env[])
{
   std::ostream_iterator< int > output( cout, " " );

   int i;                                     // dummy variable
   int k;                                     // generic counter

   Vector vel, vel2;                          // velocity, velocity^2
   Vector acc, acc2;                          // acceleration, acceleration^2

   Vertex vert;                               // dummy vertex for mesh loading

   cout << "Program: " << argv[0] << endl;

   cout << "Command line arguments:" << endl;

   for( i = 1; i < argc; ++i)
     cout << argv[i] << endl;
   cout << "Type <Return> to go on";
   cin.get();

   cout << "Environment strings:" << endl;
   for( i = 0; env[i] != NULL; ++i)
     cout << env[i] << endl;

   // load a predefined mesh
   Mesh pentagon;
   pentagon.age  = 0;                         // mesh creation

   // clear summation buckets

   // aggregate mesh properties
   pentagon.mass = 0.;
   pentagon.area = 0.;
   pentagon.perimeter = 0.;

   // counters
   pentagon.counts.nCells = 0;
   pentagon.counts.nVerts = 0;
   pentagon.counts.nFaces = 0;

   // sweep through the vertices                                               *
   k = 1;

   vert.index = k;
   vert.loc.x = 1.;
   vert.loc.y = 1.;

   std::list<int> lst;                        // list of faces sharing vertex

   lst.push_back( 11 );
   lst.push_back( 12 );
   lst.push_back( 13 );

   int* begin = (int*)&lst;                   // beginning of the array
   int* end   = begin + 3;                    // a pointer one passed the end
   copy(begin, end, back_inserter(vert.faces)); // copy routine
   cout << "face list size is  " << endl;

   cout<<vert.faces.size()<< endl;
   std::copy( lst.begin(), lst.end(), output );

   vert.boundary = false;                     // this is not an interior point
   pentagon.vertex.push_back(vert);           // copy to mesh

   pentagon.counts.nVerts++;

   k++;



   return EXIT_SUCCESS;
}


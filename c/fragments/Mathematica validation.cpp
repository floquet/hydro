user: dantopa, CPU: Azteca-Chicomoztoca, MM v. 8.0 for Mac OS X x86, date: Apr 18, 2011, time: 04:25:15, nb: /Users/dantopa/ nb/LANL/Hydro/mesh/C writer 01.nb

1. delete quotes
2. change # to quote
3. delete this header

#include<cstdlib>
#include<iostream>
#include<list>
#include<vector>
#include<math.h>
#include<list>                                  // list class-template definition
#include<algorithm>                             // copy algorithm
#include<iterator>                              // ostream_iterator

#define spatial_dimension 2

using namespace std;

int main(int argc,char*argv[],char*env[])
{

  std::ostream_iterator<int> 'output(cout,# #);
  std::list<int> lst;                          // dummy list for loading structures

  int i;                                       //dummy variable
  int k;                                       //generic counter

  Vector vel, vel2;                            // velocity, velocity^2
  Vector acc, acc2;                            // acceleration, acceleration^2\n
   Vertex vert;                                 // dummy vertex for mesh loading

   //diagnostics
  cout << #Program: # <<argv[0] <<endl;

  cout << #Command line arguments:# <<endl;

  for( i = 1; i < argc; ++i );
  {
  cout << argv[i] <<endl;
  }
  cout << #Type <Return> to go on#;

  cin.get();

  cout << #Environment strings:# <<endl;

  for( i = 0; env[i] != NULL; ++i;
  {
  cout << env[i] << endl;
  }

  // load a predefined mesh
  Mesh pentagon;
  pentagon.age = 0;                           // mesh creation

  // clear summation buckets

  // aggregate mesh properties

  pentagon.mass = 0.;
  pentagon.area = 0.;
  pentagon.perimeter = 0.;

  // counters
  pentagon.counts.nCells = 0;                 // total cells in mesh
  pentagon.counts.nVerts = 0;                 // total vertices in mesh
  pentagon.counts.nFaces = 0;                 // total faces in mesh

  // sweep through the vertices                                               **
  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 + Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = Sqrt(0.625 + Sqrt(5)/8.);

  // load the list of faces which share this vertex
  lst.push_back(11)
  lst.push_back(12)
  lst.push_back(13)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 - Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = Sqrt(0.625 - Sqrt(5)/8.);

  // load the list of faces which share this vertex
  lst.push_back(3)
  lst.push_back(12)
  lst.push_back(14)
  lst.push_back(15)
  lst.push_back(16)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 5;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 - Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = -Sqrt(0.625 - Sqrt(5)/8.);

  // load the list of faces which share this vertex
  lst.push_back(1)
  lst.push_back(2)
  lst.push_back(3)
  lst.push_back(4)
  lst.push_back(17)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 5;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 + Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = -Sqrt(0.625 + Sqrt(5)/8.);

  // load the list of faces which share this vertex
  lst.push_back(4)
  lst.push_back(5)
  lst.push_back(6)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = 1;
  // y location in the mesh
  vert.loc.y = 0;

  // load the list of faces which share this vertex
  lst.push_back(6)
  lst.push_back(7)
  lst.push_back(8)
  lst.push_back(10)
  lst.push_back(11)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 5;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = -2;
  // y location in the mesh
  vert.loc.y = -1.5;

  // load the list of faces which share this vertex
  lst.push_back(1)
  lst.push_back(18)
  lst.push_back(25)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = 2;
  // y location in the mesh
  vert.loc.y = -1.5;

  // load the list of faces which share this vertex
  lst.push_back(5)
  lst.push_back(7)
  lst.push_back(19)
  lst.push_back(20)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 4;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                  // increment vertex counter in mesh

  k++;                                       // increment vertex index

  vert.index = k;                            // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = 2;
  // y location in the mesh
  vert.loc.y = 1.5;

  // load the list of faces which share this vertex
  lst.push_back(10)
  lst.push_back(13)
  lst.push_back(21)
  lst.push_back(22)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 4;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = -2;
  // y location in the mesh
  vert.loc.y = 1.5;

  // load the list of faces which share this vertex
  lst.push_back(15)
  lst.push_back(23)
  lst.push_back(24)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = 2;
  // y location in the mesh
  vert.loc.y = 0;

  // load the list of faces which share this vertex
  lst.push_back(9)
  lst.push_back(20)
  lst.push_back(21)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = -2;
  // y location in the mesh
  vert.loc.y = 0;

  // load the list of faces which share this vertex
  lst.push_back(16)
  lst.push_back(17)
  lst.push_back(24)
  lst.push_back(25)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 4;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 - Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = 1.5;

  // load the list of faces which share this vertex
  lst.push_back(14)
  lst.push_back(22)
  lst.push_back(23)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = (-1 - Sqrt(5))/4.;
  // y location in the mesh
  vert.loc.y = -1.5;

  // load the list of faces which share this vertex
  lst.push_back(2)
  lst.push_back(18)
  lst.push_back(19)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = True;14// this point on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  vert.index = k;                             // key field for Vertex structure
  // x location in the mesh
  vert.loc.x = 1.5;
  // y location in the mesh
  vert.loc.y = 0;

  // load the list of faces which share this vertex
  lst.push_back(8)
  lst.push_back(9)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));// copy into the vertex structure

  vert.boundary = False;10// this point not on the boundary

  // load this vertex into the mesh
  pentagon.vertex.push_back(vert);

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

  k++;                                        // increment vertex index

  //sweep through the faces                                                   **
  Face face;                                   // create a generic face structure

  k = 1;                                        // face index
  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 1;
  face.verts(2) = 11;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(1)
  lst.push_back(11)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 2.497212040956833;

  // load the difference between the locations
  face.delta.x = 2.3090169943749475;
  face.delta.y = 0.9510565162951535;

  // load the midpoint for the face
  face.midpoint.x = 1.6909830056250525;
  face.midpoint.y = 0.9510565162951535;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 1;
  face.verts(2) = 2;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(1)
  lst.push_back(2)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 1.1755705045849463;

  // load the difference between the locations
  face.delta.x = 1.118033988749895;
  face.delta.y = 0.3632712640026804;

  // load the midpoint for the face
  face.midpoint.x = 0.5;
  face.midpoint.y = 1.5388417685876266;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 10;
  face.verts(2) = 12;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(10)
  lst.push_back(12)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 3.1844271815645686;

  // load the difference between the locations
  face.delta.x = 2.8090169943749475;
  face.delta.y = 1.5;

  // load the midpoint for the face
  face.midpoint.x = 1.1909830056250525;
  face.midpoint.y = 1.5;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 2;
  face.verts(2) = 12;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(2)
  lst.push_back(12)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 0.9122147477075269;

  // load the difference between the locations
  face.delta.x = 0.;
  face.delta.y = 0.9122147477075269;

  // load the midpoint for the face
  face.midpoint.x = 1.618033988749895;
  face.midpoint.y = 2.0877852522924734;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 2;
  face.verts(2) = 3;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(2)
  lst.push_back(3)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 1.1755705045849463;

  // load the difference between the locations
  face.delta.x = 0.;
  face.delta.y = 1.1755705045849463;

  // load the midpoint for the face
  face.midpoint.x = 1.618033988749895;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 3;
  face.verts(2) = 12;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(3)
  lst.push_back(12)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 2.0877852522924734;

  // load the difference between the locations
  face.delta.x = 0.;
  face.delta.y = 2.0877852522924734;

  // load the midpoint for the face
  face.midpoint.x = 1.618033988749895;
  face.midpoint.y = 0.9122147477075269;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 3;
  face.verts(2) = 4;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(3)
  lst.push_back(4)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 1.1755705045849463;

  // load the difference between the locations
  face.delta.x = 1.118033988749895;
  face.delta.y = 0.3632712640026804;

  // load the midpoint for the face
  face.midpoint.x = 0.5;
  face.midpoint.y = 1.5388417685876266;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 4;
  face.verts(2) = 5;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(4)
  lst.push_back(5)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 1.1755705045849463;

  // load the difference between the locations
  face.delta.x = 0.6909830056250525;
  face.delta.y = 0.9510565162951535;

  // load the midpoint for the face
  face.midpoint.x = 1.3090169943749475;
  face.midpoint.y = 0.9510565162951535;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 4;
  face.verts(2) = 5;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(4)
  lst.push_back(5)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 1.1755705045849463;

  // load the difference between the locations
  face.delta.x = 0.6909830056250525;
  face.delta.y = 0.9510565162951535;

  // load the midpoint for the face
  face.midpoint.x = 1.3090169943749475;
  face.midpoint.y = 0.9510565162951535;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 5;
  face.verts(2) = 6;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(5)
  lst.push_back(6)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 3.3541019662496847;

  // load the difference between the locations
  face.delta.x = 3.;
  face.delta.y = 1.5;

  // load the midpoint for the face
  face.midpoint.x = 1.;
  face.midpoint.y = 1.5;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 6;
  face.verts(2) = 12;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(6)
  lst.push_back(12)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 3.22776091426978;

  // load the difference between the locations
  face.delta.x = 1.1909830056250525;
  face.delta.y = 3.;

  // load the midpoint for the face
  face.midpoint.x = 2.8090169943749475;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 7;
  face.verts(2) = 12;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(7)
  lst.push_back(12)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.109814652108689;

  // load the difference between the locations
  face.delta.x = 2.8090169943749475;
  face.delta.y = 3.;

  // load the midpoint for the face
  face.midpoint.x = 1.1909830056250525;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 6;
  face.verts(2) = 7;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(6)
  lst.push_back(7)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 3.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 7;
  face.verts(2) = 8;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(7)
  lst.push_back(8)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 3.;

  // load the difference between the locations
  face.delta.x = 0.;
  face.delta.y = 3.;

  // load the midpoint for the face
  face.midpoint.x = 4.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 8;
  face.verts(2) = 9;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(8)
  lst.push_back(9)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 3.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 9;
  face.verts(2) = 10;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(9)
  lst.push_back(10)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.272001872658765;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 1.5;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 1.5;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 10;
  face.verts(2) = 11;

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(10)
  lst.push_back(11)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 2;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = False;          // this face not on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 1;
  face.verts(2) = {1}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(1)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 2;
  face.verts(2) = {2}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(2)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 4;
  face.verts(2) = {4}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(4)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 5;
  face.verts(2) = {5}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(5)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 7;
  face.verts(2) = {7}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(7)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 8;
  face.verts(2) = {8}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(8)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 9;
  face.verts(2) = {9}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(9)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

  face.index = k;                             // key field for Face structure
  // load the vertices which define the face
  face.verts(1) = 11;
  face.verts(2) = {11}[[2]];

  // load the cells which share this vertex
  // two cells = interior; one cell = boundary
  lst.push_back(11)

  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 1;                       // a pointer one passed the end
  copy(begin, end, back_inserter(face.cells));// copy into the face structure

  face.boundary = True;              // this face on the boundary

  // load the delta x, delta y for slopes and normals
  // face length
  face.length = 4.;

  // load the difference between the locations
  face.delta.x = 4.;
  face.delta.y = 0.;

  // load the midpoint for the face
  face.midpoint.x = 0.;
  face.midpoint.y = 0.;


  // load this face into the mesh
  pentagon.face.push_back(face);

  pentagon.counts.nfaces++;                                        // increment face counter in mesh

  k++;                                        // increment face index

}\n

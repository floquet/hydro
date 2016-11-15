// -------------------------------------------------------------------------- //
//                                                                            //
// These routines load an ensemble. This cpp file is written by Mathematica   //
//                                                                            //
// LoadVerts                                                                  //
// Load a collection of vertices: assign index numbers and locations          //
//                                                                            //
// LoadCells                                                                  //
// Load a collection of cells by defining an index and a                      //
//     CCW ordered set of vertices for each cell                              //
//                                                                            //
// LoadMeshes                                                                 //
// Define a mesh as a collection of cells                                     //
//                                                                            //
// LoadEnsemble                                                               //
// Define an ensemble as a collection of meshes                               //
//                                                                            //
// Runnelator                                                                 //
// Complete the connectivity: define links, cell properties (area, perimeter) //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "header.h"

// user: rdantopa1, CPU: malkovich, MM v. 8.0 for Mac OS X x86
// date: May 23, 2011, time: 15:23:24
// nb: /Users/rdantopa1/Documents/ nb/LANL/Hydro/mesh/structures alpha 01.nb

Ensemble LoadStructures()
{
	Ensemble output;
	
	std::vector<Vertex> V;
	std::vector<Cell>   C;
	std::vector<Mesh>   M;
	
	V = LoadVerts();
	cout << V.size() - 1 << " vertices loaded\n";
	
	C = LoadCells();
	cout << C.size() - 1 << " cells loaded\n";
	
	M = LoadMeshes();
	cout << M.size() - 1 << " mesh loaded\n";
	
	// load ensemble
	output.V = V;
	output.C = C;
	output.M = M;
	
	return output;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
//
//    load the universe of vertices
//    cells can grab from this list
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

std::vector<Vertex> LoadVerts()
{
	int nVertsUniverse;                  // total number of vertices in universe
	std::vector<Vertex> v;               // collection of all vertices
	
	nVertsUniverse = 12;                 // total number of vertices in universe
	
	// prepare to populate vertex list
	v.resize( nVertsUniverse + 1 );
	v[0].index = nVertsUniverse;
	
	// ---------------------------------------------------------------------- //
	// load the Cartesian coordinates for all stencils
	
	v[1].index = 1;
	v[1].loc.resize( nDim + 1 );
	v[1].loc[1] = 0.;
	v[1].loc[2] = 0.;
	
	v[2].index = 2;
	v[2].loc.resize( nDim + 1 );
	v[2].loc[1] = 1.072381498658463;
	v[2].loc[2] = 0.;
	
	v[3].index = 3;
	v[3].loc.resize( nDim + 1 );
	v[3].loc[1] = 1.9353402418644126;
	v[3].loc[2] = 0.;
	
	v[4].index = 4;
	v[4].loc.resize( nDim + 1 );
	v[4].loc[1] = 3.;
	v[4].loc[2] = 0.;
	
	v[5].index = 5;
	v[5].loc.resize( nDim + 1 );
	v[5].loc[1] = 0.;
	v[5].loc[2] = 1.0501184454855612;
	
	v[6].index = 6;
	v[6].loc.resize( nDim + 1 );
	v[6].loc[1] = 0.9279564947635319;
	v[6].loc[2] = 1.0621642203707369;
	
	v[7].index = 7;
	v[7].loc.resize( nDim + 1 );
	v[7].loc[1] = 1.9807126623349873;
	v[7].loc[2] = 0.936873695216002;
	
	v[8].index = 8;
	v[8].loc.resize( nDim + 1 );
	v[8].loc[1] = 3.;
	v[8].loc[2] = 1.0812907348721286;
	
	v[9].index = 9;
	v[9].loc.resize( nDim + 1 );
	v[9].loc[1] = 0.;
	v[9].loc[2] = 2.;
	
	v[10].index = 10;
	v[10].loc.resize( nDim + 1 );
	v[10].loc[1] = 0.9482174341994807;
	v[10].loc[2] = 2.;
	
	v[11].index = 11;
	v[11].loc.resize( nDim + 1 );
	v[11].loc[1] = 2.0201186203235397;
	v[11].loc[2] = 2.;
	
	v[12].index = 12;
	v[12].loc.resize( nDim + 1 );
	v[12].loc[1] = 3.;
	v[12].loc[2] = 2.;
	
	// ---------------------------------------------------------------------- //
	// load translation stencils
	//   0 prevents movement in a direction
	//   1 allows   movement in a direction
	//
	// Hadamard product
	// (delta x, delta y) * stencil = (delta x * stencil_x, delta y * stencil_y)
	
	v[1].stencil.resize( nDim + 1 );
	v[1].stencil[1] = 0.;
	v[1].stencil[2] = 0.;
	
	v[2].stencil.resize( nDim + 1 );
	v[2].stencil[1] = 1.;
	v[2].stencil[2] = 0.;
	
	v[3].stencil.resize( nDim + 1 );
	v[3].stencil[1] = 1.;
	v[3].stencil[2] = 0.;
	
	v[4].stencil.resize( nDim + 1 );
	v[4].stencil[1] = 0.;
	v[4].stencil[2] = 0.;
	
	v[5].stencil.resize( nDim + 1 );
	v[5].stencil[1] = 0.;
	v[5].stencil[2] = 1.;
	
	v[6].stencil.resize( nDim + 1 );
	v[6].stencil[1] = 1.;
	v[6].stencil[2] = 1.;
	
	v[7].stencil.resize( nDim + 1 );
	v[7].stencil[1] = 1.;
	v[7].stencil[2] = 1.;
	
	v[8].stencil.resize( nDim + 1 );
	v[8].stencil[1] = 0.;
	v[8].stencil[2] = 1.;
	
	v[9].stencil.resize( nDim + 1 );
	v[9].stencil[1] = 0.;
	v[9].stencil[2] = 0.;
	
	v[10].stencil.resize( nDim + 1 );
	v[10].stencil[1] = 1.;
	v[10].stencil[2] = 0.;
	
	v[11].stencil.resize( nDim + 1 );
	v[11].stencil[1] = 1.;
	v[11].stencil[2] = 0.;
	
	v[12].stencil.resize( nDim + 1 );
	v[12].stencil[1] = 0.;
	v[12].stencil[2] = 0.;
	
	return v;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
//
//    load a collection of the cells
//    meshes can grab from this list
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

std::vector<Cell> LoadCells()
{
	int nCellsUniverse;                  // total number of cells in collection
	
	std::vector<Cell> c;                 // collection of all cells
	
	nCellsUniverse = 6;                  // from the cubit surrogate
	
	// prepare to populate vertex list
	c.resize( nCellsUniverse + 1 );
	c[0].index = nCellsUniverse;
	
	// ---------------------------------------------------------------------- //
	// a cell is defined by a CCW ordering of  vertices
	
	c[1].index = 1;
	c[1].vlist.resize( 4 + 1 );
	c[1].vlist[0] =    4;
	c[1].vlist[1] =    1;
	c[1].vlist[2] =    2;
	c[1].vlist[3] =    6;
	c[1].vlist[4] =    5;
	
	c[2].index = 2;
	c[2].vlist.resize( 4 + 1 );
	c[2].vlist[0] =    4;
	c[2].vlist[1] =    2;
	c[2].vlist[2] =    3;
	c[2].vlist[3] =    7;
	c[2].vlist[4] =    6;
	
	c[3].index = 3;
	c[3].vlist.resize( 4 + 1 );
	c[3].vlist[0] =    4;
	c[3].vlist[1] =    3;
	c[3].vlist[2] =    4;
	c[3].vlist[3] =    8;
	c[3].vlist[4] =    7;
	
	c[4].index = 4;
	c[4].vlist.resize( 4 + 1 );
	c[4].vlist[0] =    4;
	c[4].vlist[1] =    5;
	c[4].vlist[2] =    6;
	c[4].vlist[3] =   10;
	c[4].vlist[4] =    9;
	
	c[5].index = 5;
	c[5].vlist.resize( 4 + 1 );
	c[5].vlist[0] =    4;
	c[5].vlist[1] =    6;
	c[5].vlist[2] =    7;
	c[5].vlist[3] =   11;
	c[5].vlist[4] =   10;
	
	c[6].index = 6;
	c[6].vlist.resize( 4 + 1 );
	c[6].vlist[0] =    4;
	c[6].vlist[1] =    7;
	c[6].vlist[2] =    8;
	c[6].vlist[3] =   12;
	c[6].vlist[4] =   11;
	
	return c;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
//
// load a collection of meshes
//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

std::vector<Mesh> LoadMeshes()
{
	
	int k;                               // dummy counter
	int nMeshes;                         // total number of meshes
	int nCells;                          // number of cells in mesh
	
	std::vector<Mesh> m;                 // collection of meshes
	
	nMeshes = 1;                         //for this case
	nCells = 6;
	
	m.resize( nMeshes + 1);
	m[0].index = nMeshes;
	
	m[1].index = 1;
	m[1].clist.resize( nCells + 1 );
	m[1].clist[0] = nCells;
	
	for ( k = 1; k <= nMeshes; k++ )
		m[1].clist[k] = k;
	
	return m;
	
}
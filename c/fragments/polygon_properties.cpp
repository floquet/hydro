// -------------------------------------------------------------------------- //
//                                                                            //
// Routines for computing polygon properties: area, centroid, perimeter       //
//                                                                            //
// All polygon properties are defined in terms of position vectors. However,  //
// the code is based on vertex indices. The top level routines accept cell    //
// indices. Mid level routines accept an ordered list of vertex indices. The  //
// bottom level routines operate on position vectors and are the computation  //
// engines for the higher level routines.                                     //
//                                                                            //
// List closure:                                                              //
// Given a cell defined by vertices (a, b, c, d). The computation is based    //
// upon the CLOSED list (a, b, c, d, a). The list is closed automatically in  //
// the vertices routines.                                                     //
//                                                                            //
// Example: compute the area of cell k which has vertices (a, b, c)           //
//  polygon_area_cell( k ) passes vertex list (a, b, c) to                    //
//  polygon_area_vertices( a, b, c ) passes location list (la, lb, lc, la) to //
//  polygon_area_locations(la, lb, lc, la) which returns the area             //
//                                                                            //
// This structure allows for operations on cells, cell collections, mesh      //
// and mesh collections.                                                      //
//                                                                            //
// Routines assume nDim = 2.                                                  //
//                                                                            //
//   polygon_area_cell                                                        //
//   polygon_area_vertices                                                    //
//   polygon_area_locations                                                   //
//                                                                            //
//   polygon_centroid_cell                                                    //
//   polygon_centroid_vertices                                                //
//   polygon_centroid_locations                                               //
//                                                                            //
//   polygon_perimeter_cell                                                   //
//   polygon_perimeter_vertices                                               //
//   polygon_perimeter_locations                                              //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "header.h"

// ************************************************************************** //
//                                                                            //
//                                   area                                     //
//                                                                            //
// ************************************************************************** //


// routines are structured for hierachal access
double polygon_area_cell( Ensemble ensemble, int MeshIndex, int CellIndex )
{
	std::vector<int> vertex_list;
	vertex_list = ensemble.C[ ensemble.M[ MeshIndex ].clist[ CellIndex] ].vlist;
	
	return double polygon_area_vertices( vertex_list );
}

// ************************************************************************** //

double polygon_area_vertices( std::vector<int> vertex_list )
{
	// container to collect position vectors
	std::vector<std::vector<double>> locations_list;
	// count the number of vertex in input list
	int nVerts = vertex_list.size();
	// position vectors correspond to vertex elements: no closure of list
	locations_list.resize( nVerts );
	
	// sweep through vertices and harvest position vectors
	for (int k = 0; k < nVerts; k++ ) 
	{
		locations_list[ k ].resize( nDim );
		for ( int mu = 0; mu < nDim; mu++ ) 
		{
			locations_list[ k ].[ mu ] = ensemble.V[ vertex_list[ k ] ].loc[ mu ]
		}
	}
	
	return double polygon_area_locations( std::vector<double> locations_list );
}

// ************************************************************************** //

// routine assumes nDim = 2
double polygon_area_locations( std::vector<double> locations_list )
{
	double xa, ya;                      // shorthand, first point
	double xb, yb;                      // shorthand, second point

	int j;                              // iterator
	
	// measure the list
	int nLocations = locations_list.sizeof();    
	
	double polygon_area = 0.;           // clear accumulator
	
	for ( j = 0; j < nLocations; j++ ) 
	{
		xa = locations_list[ j ].[ 1 ];
		ya = locations_list[ j ].[ 2 ];
		
		xb = locations_list[ j + 1 % nLocations ].[ 1 ];
		yb = locations_list[ j + 1 % nLocations ].[ 2 ];
		
		polygon_area += xa * yb;
		polygon_area -= xb * ya;
	}
	
	return polygon_area / 2.;
}

// ************************************************************************** //
//                                                                            //
//                                 perimeter                                  //
//                                                                            //
// ************************************************************************** //

// routines are structured for hierachal access
double polygon_perimeter_cell( Ensemble ensemble, int MeshIndex, int CellIndex )
{
	std::vector<int> vertex_list;
	vertex_list = ensemble.C[ ensemble.M[ MeshIndex ].clist[ CellIndex] ].vlist;
	
	return double polygon_perimeter_vertices( vertex_list );
}

// ************************************************************************** //

double polygon_perimeter_vertices( std::vector<int> vertex_list )
{
	// container to collect position vectors
	std::vector<std::vector<double>> locations_list;
	// count the number of vertex in input list
	int nVerts = vertex_list.size();
	// position vectors correspond to vertex elements: no closure of list
	locations_list.resize( nVerts );
	
	// sweep through vertices and harvest position vectors
	for (int k = 0; k < nVerts; k++ ) 
	{
		locations_list[ k ].resize( nDim );
		for ( int mu = 0; mu < nDim; mu++ ) 
		{
			locations_list[ k ].[ mu ] = ensemble.V[ vertex_list[ k ] ].loc[ mu ]
		}
	}
	
	return double polygon_perimeter_locations( std::vector<double> locations_list );
}

// ************************************************************************** //

// routine assumes nDim = 2
double polygon_perimeter_locations( std::vector<double> locations_list )
{
	double xa, ya;                      // shorthand, first point
	double xb, yb;                      // shorthand, second point
	
	int j;                              // iterator
	
	// measure the list
	int nLocations = locations_list.sizeof();    
	
	double polygon_perimeter = 0.;           // clear accumulator
	
	for ( j = 0; j < nLocations; j++ ) 
	{
		xa = locations_list[ j ].[ 1 ];
		ya = locations_list[ j ].[ 2 ];
		
		xb = locations_list[ j + 1 % nLocations ].[ 1 ];
		yb = locations_list[ j + 1 % nLocations ].[ 2 ];
		
		polygon_perimeter += xa * yb;
		polygon_perimeter -= xb * ya;
	}
	
	return polygon_perimeter / 2.;
}

// ************************************************************************** //
//                                                                            //
//                                 centroid                                   //
//                                                                            //
// ************************************************************************** //

// routines are structured for hierachal access
double polygon_centroid_cell( Ensemble ensemble, int MeshIndex, int CellIndex )
{
	std::vector<int> vertex_list;
	vertex_list = ensemble.C[ ensemble.M[ MeshIndex ].clist[ CellIndex] ].vlist;
	
	return double polygon_centroid_vertices( vertex_list );
}

// ************************************************************************** //

double polygon_centroid_vertices( std::vector<int> vertex_list )
{
	// container to collect position vectors
	std::vector<std::vector<double>> locations_list;
	// count the number of vertex in input list
	int nVerts = vertex_list.size();
	// position vectors correspond to vertex elements: no closure of list
	locations_list.resize( nVerts );
	
	// sweep through vertices and harvest position vectors
	for (int k = 0; k < nVerts; k++ ) 
	{
		locations_list[ k ].resize( nDim );
		for ( int mu = 0; mu < nDim; mu++ ) 
		{
			locations_list[ k ].[ mu ] = ensemble.V[ vertex_list[ k ] ].loc[ mu ]
		}
	}
	
	return double polygon_centroid_locations( std::vector<double> locations_list );
}

// ************************************************************************** //

// routine assumes nDim = 2
double polygon_centroid_locations( std::vector<double> locations_list )
{
	double xa, ya;                      // shorthand, first point
	double xb, yb;                      // shorthand, second point
	
	int j;                              // iterator
	
	// measure the list
	int nLocations = locations_list.sizeof();    
	
	double polygon_centroid = 0.;           // clear accumulator
	
	for ( j = 0; j < nLocations; j++ ) 
	{
		xa = locations_list[ j ].[ 1 ];
		ya = locations_list[ j ].[ 2 ];
		
		xb = locations_list[ j + 1 % nLocations ].[ 1 ];
		yb = locations_list[ j + 1 % nLocations ].[ 2 ];
		
		polygon_centroid += xa * yb;
		polygon_centroid -= xb * ya;
	}
	
	return polygon_centroid / 2.;
}

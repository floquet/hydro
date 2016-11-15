// -------------------------------------------------------------------------- //
//                                                                            //
// Definitions of the operator norms (p-norms) and dot product                //
//                                                                            //
// norm1                                                                      //
// L1 norm (taxicab norm)                                                     //
//                                                                            //
// norm2                                                                      //
// L2 norm (Euclidean norm)                                                   //
//      guards against under/overflow                                         //
//                                                                            //
// norminf                                                                    //
// L-inf norm (maximum norm)                                                  //
//                                                                            //
// normp                                                                      //
// p-norm (1 <= p < infinity)                                                 //
//      special cases of p = 1, 2 trapped                                     //
//      when p < 1, exit and return -1                                        //
//                                                                            //
// dot                                                                        //
// dot product of two vectors of length nDim                                  //
//                                                                            //
// pdot                                                                       //
// protected dot product guards against ill-conditioned subtraction           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "header.h"

// -------------------------------------------------------------------------- //
//                                                                            //
//    vector norms                                                            //
//                                                                            //
//    1. || I || = 1                             preservation of unit sphere  //
//    2. || x || = 0  <==>  x = 0                                             //
//    3. || x || > 0                             positivity                   //
//    4. || x + y || < = || x || + || y ||       triangle inequality          //
//    5. || a x || = |a| || x ||                 linearity                    //
//                                                                            //
// -------------------------------------------------------------------------- //

// ************************************************************************** //

// L1 norm (taxicab norm)
// L1( x ) = | x1 | + | x2 | + ... + | x(nDim) |
double norm1( std::vector<double> vec )
{
	int k = 0;                           // dummy counter
	
	double norm = 0;                     // accumulate norm
	
	for ( k = 1; k <= nDim; k++ )        // loop over entries
		norm += abs( vec[k] );
	
	return norm;                         // rescale and return 1-norm
}

// ************************************************************************** //

// L2 norm (Euclidean norm)
// L2( x ) = sqrt( x1^2 + x2^2 + ... + x(nDim)^2 )
//      protection against overflow for x^2
double norm2( std::vector<double> vec )
{
	int k = 0;                           // dummy counter
	
	double norm = 0;                     // accumulate norm
	double z, infnorm;
	
	infnorm = norminf( vec );            // maximum entry scales all terms
	
	for ( k = 1; k <= nDim; k++ )        // loop over entries
	{
		// normalize to avoid overflow
		z = vec[ k ] / infnorm;            // scale vectors inside unit ball
		norm += z * z;
	}
	
	return infnorm * sqrt( norm );       // rescale and return 2-norm
}

// ************************************************************************** //

// L-inf norm (max norm)
// L-inf( x ) = max( | x1 |, | x2 |, ... , | x(nDim) )
double norminf( std::vector<double> vec )
{
	int k = 0;                           // dummy counter
	
	double norm = 0;                     // accumulate norm
	double x;                            // shorthand term
	
	for ( k = 1; k <= nDim; k++ )        // loop over entries
	{
		x = abs( vec[ k ] );
		if ( x > norm )
			norm = x;                        // update maximum
	};
	
	return norm;                         // return inf-norm
}

// ************************************************************************** //

// p norm
// 1 <= p < infinity
// trap special cases
//   returns -1 when p < 1
double normp( std::vector<double> vec, double p )
{
	// trap special cases
	if ( p < 1. )
		return -1.;                        // not convex

	if ( p == 1. )
		return norm1( vec );               // L1 norm
	
	if ( p == 2. )
		return norm2( vec );               // L2 norm
	
	//declarations
	int k = 0;                           // dummy counter
	
	double norm = 0;                     // clear accumulator
	double z, infnorm;
	
	// computation
	infnorm = norminf( vec );            // grab largest element for scaling
	
	if ( infnorm == 0. )                 // trap 0 vectors
		return infnorm;
	
	for ( k = 1; k <= nDim; k++ )        // loop over entries
	{
		// normalize to avoid overflow
		z = abs( vec[ k ] ) / infnorm;
		norm += pow( z, p );
	}
	
	return infnorm * pow( norm, 1. / p );// rescale and return p-norm
}

// ************************************************************************** //

// returns the dot product of two vectors u and v of length nDim
double dot( std::vector<double> u, std::vector<double> v )
{
	int k = 0;                          // dummy iteration variable
	
	double dot_product = 0;             // clear accumulator
	
	for ( k = 1; k <= nDim; k++ )       // loop over entries
		dot_product += u[ k ] * v[ k ];
	
	return dot_product;                 // return the dot product
}

// ************************************************************************** //

// protected dot product: guards against ill-conditioned
// returns the dot product of two vectors u and v of length nDim
double pdot( std::vector<double> u, std::vector<double> v )
{
	int k = 0;                           // dummy iteration variable
	
	double U, V;                         // normalized forms
	double u2, v2;                       // norms
	double dot_product = 0.;             // clear accumulator
	
// compute vector magnitudes
	u2 = norm2( u );                     // check for magnitude 0 vectors
	if ( u2 < zeroThreshold )
		return 0.;
	
	v2 = norm2( v );                     // check for magnitude 0 vectors
	if ( v2 < zeroThreshold )
		return 0.;
	
	for ( k = 1; k <= nDim; k++ )        // loop over entries
	{
		U = u[ k ] / u2;                   // work on the unit sphere
		V = v[ k ] / v2;
		
		dot_product += U * V;              // accumulate
	}
	
	return dot_product * u2 * v2;        // rescale and return
}

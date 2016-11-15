// -------------------------------------------------------------------------- //
//                                                                            //
//  Verify the norms                                                          //
//                                                                            //
//  Mathematica creates test cases and outputs C++ code to verify the matrix  //
//  the matrix norms. A sequence of vectors is checked for multiple norms.    //
//                                                                            //
//  The differences between the C++ code and the Mathematica results using    //
//  arbitrary precision are tracked by vector and by p-norm.                  //
//                                                                            //
//  The ideal result is zero error. Here is a sample computation:             //
//                                                                            //
//      normCpp   = norm1( v );                                               //
//      normMM    = 2 * sqrt(3);                                              //
//      error     = normMM - normCpp;                                         //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "header.h"

// user: rdantopa1, CPU: crocker, MM v. 8.0 for Mac OS X x86
// date: Jun 10, 2011, time: 08:52:09
// /Users/rdantopa1/Documents/ nb/LANL/Hydro/test/vector ops/dots and norms 02.nb

int testNorms()
{
	int k, superK, nCase;
	
	// Mathematica results
	
	double normMM, normCpp;
	
	// Mathematica - C++;
	double error, cumerror, maxerror;
	double superMaxerror, superError;
	
	// p-norm index
	double p;
	
	// establish test vector
	std::vector<double> v;
	v.resize( nDim + 1 );
	cumerror = 0.;
	
	// initialize for all cases
	superError    = 0.;
	superMaxerror = 0.;
	
	
	// test case 2
	
	// initialization
	nCase = 2;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1;
	v[2] = -1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.7411011265922482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 1.5874010519681994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 1.4859942891369484;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 1.360790000174377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 1.3195079107728942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 1.2190136542044754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 2
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 3
	
	// initialization
	nCase = 3;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(2);
	v[2] = -sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 2.4622888266898326;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 2.244924096618746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 2.101513277306439;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 1.9244476737882903;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 1.8660659830736148;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 1.7239456424939554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 3
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 4
	
	// initialization
	nCase = 4;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(3);
	v[2] = -sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 3.0156756123731854;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 2.749459273997205;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 2.573817608542391;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 2.356957418733682;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 2.285454742447713;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 2.1113935842023497;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 4
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 5
	
	// initialization
	nCase = 5;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2;
	v[2] = -2;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 3.4822022531844965;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 3.1748021039363987;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 2.971988578273897;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 2.721580000348754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 2.6390158215457884;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 2.4380273084089508;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 5
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 6
	
	// initialization
	nCase = 6;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(5);
	v[2] = -sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 3.893220474761734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 3.5495366597555704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 3.322784244686694;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 3.0428189434918576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 2.9505093853369186;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 2.7257973963016293;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 6
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 7
	
	// initialization
	nCase = 7;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(6);
	v[2] = -sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 4.2648093507359475;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 3.8883225944793307;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 3.639927769075335;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 3.333241147509055;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 3.2321210929594653;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 2.985961442286502;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 7
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 8
	
	// initialization
	nCase = 8;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(7);
	v[2] = -sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 4.606520588377477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 4.199868414430174;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 3.931571338718576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 3.600311927044942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 3.491089784887484;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 3.2252069738171283;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 8
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 9
	
	// initialization
	nCase = 9;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(2);
	v[2] = -2*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 4.924577653379665;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 4.489848193237492;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 4.203026554612878;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 3.8488953475765806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 3.7321319661472296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 3.447891284987911;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 9
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 10
	
	// initialization
	nCase = 10;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3;
	v[2] = -3;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 3*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 5.223303379776745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 4.762203155904598;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 4.457982867410845;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 4.082370000523131;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 3.9585237323186826;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 3.657040962613426;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 10
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 11
	
	// initialization
	nCase = 11;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(10);
	v[2] = -sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 5.505845196716664;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 5.019802884366822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 4.699126543675564;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 4.303195817731957;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 4.172650388652575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 3.8548596461310347;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 11
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 12
	
	// initialization
	nCase = 12;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(11);
	v[2] = -sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 5.774579158971566;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 5.264813681193971;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 4.928485497678153;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 4.513229849046067;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 4.376312647939442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.043010905316288;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 12
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 13
	
	// initialization
	nCase = 13;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(3);
	v[2] = -2*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 6.031351224746371;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 5.49891854799441;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 5.147635217084782;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 4.713914837467364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 4.570909484895426;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.222787168404699;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 13
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 14
	
	// initialization
	nCase = 14;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(13);
	v[2] = -sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 6.277629387696469;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 5.72345588759682;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 5.357828604529928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 4.906398120767367;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 4.757553430672032;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.3952162357249644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 14
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 15
	
	// initialization
	nCase = 15;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(14);
	v[2] = -sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 6.514603891434317;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 5.939510871869539;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 5.560081508653155;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.09160995600057;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 4.9371465212500505;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.56113144383247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 15
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 16
	
	// initialization
	nCase = 16;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(15);
	v[2] = -sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 6.743255667354749;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 6.14797783802497;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 5.75523113438673;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.27031700836095;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.110432163612361;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.72121958153338;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 16
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 17
	
	// initialization
	nCase = 17;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4;
	v[2] = -4;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 6.964404506368993;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 6.3496042078727974;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 5.943977156547794;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.443160000697508;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.278031643091577;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 4.8760546168179015;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 17
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 18
	
	// initialization
	nCase = 18;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(17);
	v[2] = -sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 7.178743849821745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 6.545022207481475;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.126911413176269;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.610680905003231;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.440470489954726;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.026122055355214;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 18
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 19
	
	// initialization
	nCase = 19;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(2);
	v[2] = -3*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 7.386866480069498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 6.734772289856238;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.3045398319193175;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.773343021364871;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.598197949220845;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.171836927481866;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 19
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 20
	
	// initialization
	nCase = 20;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(19);
	v[2] = -sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 7.589283861300428;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 6.919320768399539;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.47729893702652;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 5.931546094140805;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.751601638261531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.313557329473544;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 20
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 21
	
	// initialization
	nCase = 21;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(5);
	v[2] = -2*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 7.786440949523468;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.099073319511141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.645568489373388;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.085637886983715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 5.901018770673837;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.451594792603259;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 21
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 22
	
	// initialization
	nCase = 22;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(21);
	v[2] = -sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 7.978727705181868;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.274385478896803;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.8096813122421604;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.235923180738053;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.046744881209824;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.586222343576732;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 22
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 23
	
	// initialization
	nCase = 23;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(22);
	v[2] = -sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 8.16648816361461;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.4455709113119335;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 6.969931032775557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.382670862628025;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.189040699900871;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.71768085512062;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 23
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 24
	
	// initialization
	nCase = 24;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(23);
	v[2] = -sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 8.350027668186394;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.612908005168863;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.1265782553056525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.526119579444997;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.328137633745152;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.846184110182453;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 24
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 25
	
	// initialization
	nCase = 25;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(6);
	v[2] = -2*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 8.529618701471895;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.776645188958661;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.27985553815067;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.66648229501811;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.4642421859189305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 5.971922884573004;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 25
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 26
	
	// initialization
	nCase = 26;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5;
	v[2] = -5;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 5*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 8.705505632961241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 7.937005259840997;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.4299714456847425;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.803950000871884;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.597539553864471;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.095068271022377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 26
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 27
	
	// initialization
	nCase = 27;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(26);
	v[2] = -sqrt(26);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 8.877908619632255;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.094188939883562;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.577113877396738;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 6.938694764791077;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.728196585371034;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.215774410124667;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 27
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 28
	
	// initialization
	nCase = 28;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(3);
	v[2] = -3*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 3*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.047026837119557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.248377821991616;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.721452825627174;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.070872256201047;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.856364227343141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.3341807526070495;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 28
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 29
	
	// initialization
	nCase = 29;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(7);
	v[2] = -2*sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.213041176754954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.399736828860348;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 7.863142677437152;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.200623854089884;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 6.982179569774968;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.450413947634257;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 29
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 30
	
	// initialization
	nCase = 30;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(29);
	v[2] = -sqrt(29);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.376116512586812;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.548416279867437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.00232414946315;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.32807841883961;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.105767563829764;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.56458943003837;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 30
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 31
	
	// initialization
	nCase = 31;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(30);
	v[2] = -sqrt(30);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.536403619322321;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.694553639704132;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.139125924841608;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.4533537912296515;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.227242475368281;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.676812763145935;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 31
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 32
	
	// initialization
	nCase = 32;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(31);
	v[2] = -sqrt(31);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.694040804723521;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.838275006667427;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.273666046425632;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.576558068266355;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.346709122073616;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.787180781682877;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 32
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 33
	
	// initialization
	nCase = 33;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(2);
	v[2] = -4*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 9.84915530675933;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 8.979696386474984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.406053109225756;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.697790695153161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.464263932294459;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 6.895782569975822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 33
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 34
	
	// initialization
	nCase = 34;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(33);
	v[2] = -sqrt(33);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.001864495667109;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.11892478821169;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.536387286344945;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.817143404784203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.579995856037402;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.002700303562855;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 34
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 35
	
	// initialization
	nCase = 35;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(34);
	v[2] = -sqrt(34);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.152276913220359;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.256059171853396;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.664761215972385;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 7.93470103000332;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.6939871525845716;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.10800997682588;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 35
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 36
	
	// initialization
	nCase = 36;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(35);
	v[2] = -sqrt(35);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.300493175364366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.391191271220128;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.791260771764586;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.050542209075754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.806314074563532;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.211782034961483;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 36
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 37
	
	// initialization
	nCase = 37;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  6;
	v[2] = -6;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 12;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 6*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.44660675955349;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.524406311809196;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 8.91596573482169;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.164740001046262;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 7.917047464637365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.314081925226852;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 37
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 38
	
	// initialization
	nCase = 38;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(37);
	v[2] = -sqrt(37);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.590704694295344;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.65578363946814;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.038950382199369;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.277362424665208;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.026253278081446;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.414970579716893;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 38
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 39
	
	// initialization
	nCase = 39;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(38);
	v[2] = -sqrt(38);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.732868165350315;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.785397273080452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.160284004287734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.388472932175084;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.133993042196767;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.514504839788449;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 39
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 40
	
	// initialization
	nCase = 40;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(39);
	v[2] = -sqrt(39);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.873173050577787;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 9.913316392196917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.280031361291694;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.49813082732954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.240324261647576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.612737830527266;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 40
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 41
	
	// initialization
	nCase = 41;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(10);
	v[2] = -2*sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.011690393433328;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.039605768733644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.398253087351128;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.606391635463915;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.34530077730515;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.709719292262069;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 41
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 42
	
	// initialization
	nCase = 42;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(41);
	v[2] = -sqrt(41);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.148486823504463;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.164326150383978;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.51500604945959;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.713307432172803;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.4489730849543;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.805495874998262;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 42
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 43
	
	// initialization
	nCase = 43;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(42);
	v[2] = -sqrt(42);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.28362493115016;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.28753460218576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.630343667211479;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.818927136116525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.551388619217024;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.9001114007178295;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 43
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 44
	
	// initialization
	nCase = 44;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(43);
	v[2] = -sqrt(43);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.417163602221622;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.409284811693793;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.74431619847939;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 8.923296770628385;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.652592007223422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 7.993607097730584;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 44
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 45
	
	// initialization
	nCase = 45;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(11);
	v[2] = -2*sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.549158317943132;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.529627362387942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.856970995356306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.026459698092134;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.752625295878884;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.086021810632577;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 45
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 46
	
	// initialization
	nCase = 46;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(5);
	v[2] = -3*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 3*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.679661424285202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.64860997926671;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 9.968352734060083;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.128456830475573;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.851528156010756;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.177392188904888;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 46
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 47
	
	// initialization
	nCase = 47;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(46);
	v[2] = -sqrt(46);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.808722374539789;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.766277750008511;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.078503621966444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.229326818919715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 8.949338066205982;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.26775285675011;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 47
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 48
	
	// initialization
	nCase = 48;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(47);
	v[2] = -sqrt(47);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.936387948285587;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.882673324607243;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.187463584491399;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.329106224875204;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.046090478755762;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.3571365663986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 48
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 49
	
	// initialization
	nCase = 49;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(3);
	v[2] = -4*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.062702449492742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.99783709598882;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.295270434169565;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.427829674934728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.141818969790853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.445574336809399;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 49
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 50
	
	// initialization
	nCase = 50;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  7;
	v[2] = -7;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 14;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 7*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.187707886145738;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.111807363777395;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.401960023958639;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.525530001220638;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.236555375410259;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.533095579431327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 50
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 51
	
	// initialization
	nCase = 51;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5*sqrt(2);
	v[2] = -5*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 10*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 5*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.311444133449163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.22462048309373;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.507566386532195;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.622238368941451;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.330329915368074;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.619728212469777;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 51
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 52
	
	// initialization
	nCase = 52;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(51);
	v[2] = -sqrt(51);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(102);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.433949082413866;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.336311000024526;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.612121861094927;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.717984392522126;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.423171305680729;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.705498764917744;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 52
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 53
	
	// initialization
	nCase = 53;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(13);
	v[2] = -2*sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.555258775392938;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.44691177519364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.715657209059856;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.812796241534734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.515106861344064;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.790432471449929;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 53
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 54
	
	// initialization
	nCase = 54;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(53);
	v[2] = -sqrt(53);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(106);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.675407529941678;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.556454096687986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.818201719760271;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.906700737503519;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.606162590201622;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.874553359141983;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 54
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 55
	
	// initialization
	nCase = 55;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(6);
	v[2] = -3*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 6*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.794428052207842;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.664967783437993;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.919783307226005;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.999723442527165;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.696363278878396;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.957884326859507;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 55
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 56
	
	// initialization
	nCase = 56;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(55);
	v[2] = -sqrt(55);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(110);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.912351540913987;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.772481280020624;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.020428598930232;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.091888740548121;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.785732571584697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.040447218060185;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 56
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 57
	
	// initialization
	nCase = 57;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(14);
	v[2] = -2*sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.029207782868633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.879021743739077;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.12016301730631;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.18321991200114;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.874293042500101;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.12226288766494;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 57
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 58
	
	// initialization
	nCase = 58;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(57);
	v[2] = -sqrt(57);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(114);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.145025240834853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.984615124734525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.219010854741812;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.273739202488601;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.96206626236536;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.20335126357818;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 58
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 59
	
	// initialization
	nCase = 59;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(58);
	v[2] = -sqrt(58);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.259831134490597;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.08928623979949;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.31699534267653;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.363467886056563;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.049072859838882;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.28373140337133;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 59
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 60
	
	// initialization
	nCase = 60;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(59);
	v[2] = -sqrt(59);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(118);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.37365151513329;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.193058840487689;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.414138715361306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.452426323581538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.135332578112207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.36342154658648;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 60
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 61
	
	// initialization
	nCase = 61;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(15);
	v[2] = -2*sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.486511334709498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.29595567604994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.51046226877346;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.5406340167219;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.220864327224723;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.44243916306676;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 61
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 62
	
	// initialization
	nCase = 62;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(61);
	v[2] = -sqrt(61);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(122);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.598434509687817;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.397998551668511;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.60598641513099;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.628109657838943;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.305686232470263;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.52080099767629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 62
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 63
	
	// initialization
	nCase = 63;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(62);
	v[2] = -sqrt(62);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.709443980238198;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.499208382412235;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.700730733400915;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.714871176249577;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.389815679246643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.59852311173395;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 63
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 64
	
	// initialization
	nCase = 64;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(7);
	v[2] = -3*sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 3*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.81956176513243;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.599605243290522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.794714016155726;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.800935781134827;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.47326935466245;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.675620921451385;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 64
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 65
	
	// initialization
	nCase = 65;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  8;
	v[2] = -8;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 16;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 8*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 13.928809012737986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.699208415745595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.887954313095587;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.886320001395015;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.556063286183154;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.752109233635803;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 65
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 66
	
	// initialization
	nCase = 66;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(65);
	v[2] = -sqrt(65);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(130);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.037206048439687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.798036430887883;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 11.980468971521757;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.971039722713055;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.638212877569996;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.82800227889176;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 66
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 67
	
	// initialization
	nCase = 67;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(66);
	v[2] = -sqrt(66);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.144772418790362;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.896107109749176;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.072274674018283;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.055110222061213;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.719732942339952;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.903313742532779;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 67
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 68
	
	// initialization
	nCase = 68;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(67);
	v[2] = -sqrt(67);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(134);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.251526932662106;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 12.993437600801144;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.163387473573753;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.138546199863649;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.800637734952536;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.978056793392968;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 68
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 69
	
	// initialization
	nCase = 69;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(17);
	v[2] = -2*sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.35748769964349;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.09004441496295;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.253822826352538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.221361810006462;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.880940979909452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.052244110710427;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 69
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 70
	
	// initialization
	nCase = 70;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(69);
	v[2] = -sqrt(69);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(138);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.462672165904713;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.185943458300299;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.343595622304957;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.30357068786877;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.960655898935297;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.125887909237857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 70
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 71
	
	// initialization
	nCase = 71;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(70);
	v[2] = -sqrt(70);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.567097147731793;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.281150062599332;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.43272021378804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.38518597653199;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.039795236391722;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.198999962721167;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 71
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 72
	
	// initialization
	nCase = 72;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(71);
	v[2] = -sqrt(71);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(142);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.670778862912377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.375679013981756;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.521210442352663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.466220351309984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.118371283063434;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.271591625873924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 72
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 73
	
	// initialization
	nCase = 73;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  6*sqrt(2);
	v[2] = -6*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 12*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 12;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 6*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.773732960138997;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.469544579712476;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.609079663838635;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.546686042729743;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.19639589844169;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.343673854963733;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 73
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 74
	
	// initialization
	nCase = 74;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(73);
	v[2] = -sqrt(73);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(146);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.875974546580741;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.562760533337283;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.696340771906549;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.62659485808052;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.273880531619717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.415257227116246;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 74
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 75
	
	// initialization
	nCase = 75;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(74);
	v[2] = -sqrt(74);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 14.97751821376088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.655340178276088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.783006220123818;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.705958201638984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.350836240904295;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.486351958433122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 75
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 76
	
	// initialization
	nCase = 76;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5*sqrt(3);
	v[2] = -5*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 10*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 5*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 5*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.078378061865926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.747296369986024;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.869088042711955;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.78478709366841;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.427273712238566;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.556967921011747;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 76
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 77
	
	// initialization
	nCase = 77;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(19);
	v[2] = -2*sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.178567722600857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.838641536799077;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 12.95459787405304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.86309218828161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.503203276523061;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.627114658947088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 77
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 78
	
	// initialization
	nCase = 78;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(77);
	v[2] = -sqrt(77);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(154);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.278100380695282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 13.929387699529741;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.039546967044796;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 11.940883790249478;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.57863492591433;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.696801403389006;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 78
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 79
	
	// initialization
	nCase = 79;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(78);
	v[2] = -sqrt(78);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.376988794156746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.019546489940401;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.12394621038637;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.018171870830328;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.653578329174065;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.766037086722394;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 79
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 80
	
	// initialization
	nCase = 80;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(79);
	v[2] = -sqrt(79);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(158);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.475245313359103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.109129168144642;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.207806144869872;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.094966082688776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.728042846135395;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.834830355931693;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 80
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 81
	
	// initialization
	nCase = 81;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(5);
	v[2] = -4*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.572881899046935;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.198146639022282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.291136978746776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.17127577396743;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.802037541347675;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.903189585206517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 81
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 82
	
	// initialization
	nCase = 82;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  9;
	v[2] = -9;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 18;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 9*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.669910139330234;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.286609467713795;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.373948602232536;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.247110001569393;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.875571196956049;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.971122887840279;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 82
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 83
	
	// initialization
	nCase = 83;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(82);
	v[2] = -sqrt(82);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.76634126573776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.374527894256534;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.456250601207799;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.322477543705066;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 11.94865232486762;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.038638127469792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 83
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 84
	
	// initialization
	nCase = 84;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(83);
	v[2] = -sqrt(83);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(166);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.862186168391988;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.461911847420069;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.538052270169917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.39738691175242;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.021289178251916;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.10574292869985;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 84
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 85
	
	// initialization
	nCase = 85;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(21);
	v[2] = -2*sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 15.957455410363735;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.548770957793606;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.619362624484321;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.471846361476105;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.093489762419647;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.172444687153464;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 85
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 86
	
	// initialization
	nCase = 86;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(85);
	v[2] = -sqrt(85);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(170);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.052159241259965;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.635114570174311;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.700190411981437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.545863903647263;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.165261845120353;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.238750578985218;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 86
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 87
	
	// initialization
	nCase = 87;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(86);
	v[2] = -sqrt(86);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.14630761009428;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.72095175530163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.780544123941395;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.619447314102704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.236612966296407;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.304667569892427;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 87
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 88
	
	// initialization
	nCase = 88;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(87);
	v[2] = -sqrt(87);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(174);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.239910177485875;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.806291320979334;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.860432005505578;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.692604143279208;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.30755044732808;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.370202423656076;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 88
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 89
	
	// initialization
	nCase = 89;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(22);
	v[2] = -2*sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 4*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.33297632722922;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.891141822623867;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 13.939862065551115;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.76534172525605;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.378081399801742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.43536171024124;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 89
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 90
	
	// initialization
	nCase = 90;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(89);
	v[2] = -sqrt(89);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(178);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.425515177273766;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 14.975511573274796;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.018842086061836;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.837667186336374;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.448212733830912;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.500151813484393;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 90
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 91
	
	// initialization
	nCase = 91;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(10);
	v[2] = -3*sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 6*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.517535590149993;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.059408653100464;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.09737963102669;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.909587453195872;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.517951165957724;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.564578938393103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 91
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 92
	
	// initialization
	nCase = 92;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(91);
	v[2] = -sqrt(91);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(182);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.609046182875538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.142840918429634;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.175482054894424;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 12.981109260625104;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.58730322666037;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.6286491180817;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 92
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 93
	
	// initialization
	nCase = 93;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(23);
	v[2] = -2*sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.700055336372788;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.225816010337725;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.253156510611305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.052239158889995;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.656275267490305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.692368220364907;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 93
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 94
	
	// initialization
	nCase = 94;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(93);
	v[2] = -sqrt(93);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(186);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.790571204427025;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.308341362814144;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.330409957266717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.122983520733234;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.724873467861245;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.755741954029792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 94
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 95
	
	// initialization
	nCase = 95;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(94);
	v[2] = -sqrt(94);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 2*sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.88060172221224;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.390424210535464;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.407249167369764;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.19334854803778;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.793103841510526;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.81877587480502;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 95
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 96
	
	// initialization
	nCase = 96;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(95);
	v[2] = -sqrt(95);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(190);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 16.97015461440984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.472071596267444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.483680733778424;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.263340278172205;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.860972242651934;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.88147539104509;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 96
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 97
	
	// initialization
	nCase = 97;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(6);
	v[2] = -4*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 8*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 17.05923740294379;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.553290377917323;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.55971107630134;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.33296459003622;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.928484371837861;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 11.943845769146009;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 97
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 98
	
	// initialization
	nCase = 98;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(97);
	v[2] = -sqrt(97);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(194);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 17.14785741435405;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.634087235256343;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.635346447990889;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.402227209823534;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 12.995645781547296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 12.005892138707726;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 98
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 99
	
	// initialization
	nCase = 99;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  7*sqrt(2);
	v[2] = -7*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 14*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 14;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 7*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 17.23602178682883;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.71446867633122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.710592941145071;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.47113371651803;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 13.062461881515302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 12.067619497457688;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 99
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 100
	
	// initialization
	nCase = 100;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(11);
	v[2] = -3*sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 3*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 17.323737476914697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.79444104358191;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.78545649303446;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.539689547138202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 13.128937943818325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 12.129032715948863;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 100
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 101
	
	// initialization
	nCase = 101;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  10;
	v[2] = -10;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 20;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 10*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 17.411011265922482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 15.874010519681994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 14.859942891369485;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 13.607900001743769;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 13.195079107728942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 12.190136542044755;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 101
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 102
	
	// initialization
	nCase = 102;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1;
	v[2] = -10;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 11;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.447398443913816;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.209722733624439;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.101231992597612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.024954020749846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.012637130837746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.000903405880523;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 102
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 103
	
	// initialization
	nCase = 103;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(2);
	v[2] = -3*sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2) + 3*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.638685155102575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.302218273773835;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.135643939762721;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.004540058914365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.980117843999242;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.952950628100611;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 103
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 104
	
	// initialization
	nCase = 104;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(3);
	v[2] = -7*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 7*sqrt(2) + sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 7*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.785950533454963;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.376783018144137;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.164591061730384;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.986129644126372;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.950005455674738;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.9058265497531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 104
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 105
	
	// initialization
	nCase = 105;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2;
	v[2] = -sqrt(97);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2 + sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.909025671273898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.440890659006216;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.190155707984397;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.969111294834208;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.921661280247621;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.859462244147108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 105
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 106
	
	// initialization
	nCase = 106;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(5);
	v[2] = -4*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(5) + 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.015999078297595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.49775360616714;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.213279664073452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.953181449565454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.894755061675692;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.813822932275217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 106
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 107
	
	// initialization
	nCase = 107;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(6);
	v[2] = -sqrt(95);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(6) + sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.111164466541826;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.549138977791452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.234499309349086;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.93815607498676;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.869081371662872;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.76889025054679;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 107
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 108
	
	// initialization
	nCase = 108;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(7);
	v[2] = -sqrt(94);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(7) + sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.197139924959043;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.596154201675331;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.254159912150799;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.923910978930806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.844499063278276;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.724655422071278;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 108
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 109
	
	// initialization
	nCase = 109;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(2);
	v[2] = -sqrt(93);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(2) + sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.275667381648534;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.639552754257629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.272501592558552;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.910356456321452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.820904835792241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.681115934925455;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 109
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 110
	
	// initialization
	nCase = 110;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3;
	v[2] = -2*sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3 + 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.347977989144452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.679877334311188;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.289700541736027;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.897424579264857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.798219699171037;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.638273690566715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 110
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 111
	
	// initialization
	nCase = 111;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(10);
	v[2] = -sqrt(91);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(10) + sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.414981427925975;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.717535549118926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.305891243254228;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.885062090150678;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.776381273585576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.596133872215274;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 111
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 112
	
	// initialization
	nCase = 112;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(11);
	v[2] = -3*sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(10) + sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.477373153421446;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.752843540073613;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.321179498694345;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.873226104212742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.755339064561658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.554704204657614;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 112
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 113
	
	// initialization
	nCase = 113;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(3);
	v[2] = -sqrt(89);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(3) + sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.535699386339124;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.786052822772554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.335650560647146;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.861881352631706;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.735051393380163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.513994443511633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 113
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 114
	
	// initialization
	nCase = 114;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(13);
	v[2] = -2*sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(13) + 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.590398626921163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.817367665099665;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.34937446840007;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.850998329967437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.715483311333013;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.474016006857527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 114
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 115
	
	// initialization
	nCase = 115;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(14);
	v[2] = -sqrt(87);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(14) + sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.641829323102003;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.846956811537982;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.36240969084892;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.84055200182302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.696605130225619;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.43478169914501;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 115
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 116
	
	// initialization
	nCase = 116;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(15);
	v[2] = -sqrt(86);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(15) + sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.690288966760512;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.874961665807739;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.374805696763527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.830520875080444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.67839135565021;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.396305496984326;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 116
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 117
	
	// initialization
	nCase = 117;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4;
	v[2] = -sqrt(85);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4 + sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.736027665913516;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.901502166366019;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.386604818923296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.820886311447563;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.660819892963058;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.358602377553106;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 117
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 118
	
	// initialization
	nCase = 118;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(17);
	v[2] = -2*sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(17) + 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.779258034541705;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.926681108582804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.397843638206671;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.81163200935369;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.643871443483219;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.321688176949294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 118
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 119
	
	// initialization
	nCase = 119;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(2);
	v[2] = -sqrt(83);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(2) + sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.820162555728468;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.950587391205325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.408554032230994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.802743605413829;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.62752903680389;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.285579469898911;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 119
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 120
	
	// initialization
	nCase = 120;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(19);
	v[2] = -sqrt(82);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(19) + sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.85889916718076;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.973298499468443;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.418763983937485;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.794208362761237;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.611777662673202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.250293464839448;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 120
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 121
	
	// initialization
	nCase = 121;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(5);
	v[2] = -9;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 9 + 2*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.895605568484557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.994882434829517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.428498214774422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.786014923754108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.596603977133304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.21584791012588;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 121
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 122
	
	// initialization
	nCase = 122;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(21);
	v[2] = -4*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(5) + sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.930402591275207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.015399235926921;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.43777868734308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.778153111228539;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.581996064994042;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.182261008279559;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 122
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 123
	
	// initialization
	nCase = 123;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(22);
	v[2] = -sqrt(79);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(22) + sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.963396870559656;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.03490219248241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.446625009295769;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.77061376693572;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.567943245697885;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.149551336018302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 123
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 124
	
	// initialization
	nCase = 124;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(23);
	v[2] = -sqrt(78);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(23) + sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.994682986798203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.053438825074002;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.455054761432848;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.763388618860578;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.554435913065037;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.117737768390992;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 124
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 125
	
	// initialization
	nCase = 125;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(6);
	v[2] = -sqrt(77);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(6) + sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.024345201608584;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.07105168395898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.463083766840876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.756470171256792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.541465401819734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.086839405767428;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 125
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 126
	
	// initialization
	nCase = 126;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5;
	v[2] = -2*sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5 + 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.052458877496282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.08777900632522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.470726313620103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.749851612754359;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.529023875524024;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.056875502754618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 126
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 127
	
	// initialization
	nCase = 127;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(26);
	v[2] = -5*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5*sqrt(3) + sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 5*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.079091649080548;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.103655261536627;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.47799534067833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.743526738995662;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.517104231799172;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.02786539835551;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 127
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 128
	
	// initialization
	nCase = 128;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(3);
	v[2] = -sqrt(74);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(3) + sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.104304396822663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.118711606853118;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.484902593837498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.737489887063292;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.505700021639308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.999828446878139;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 128
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 129
	
	// initialization
	nCase = 129;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(7);
	v[2] = -sqrt(73);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(7) + sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.128152062273253;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.132976270916075;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.491458757856671;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.73173587956311;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.494805380312625;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.972783949256549;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 129
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 130
	
	// initialization
	nCase = 130;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(29);
	v[2] = -6*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(2) + sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 6*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.150684335008185;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.146474878439964;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.497673568749759;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.726259976678246;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.484414967867846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.946751084570108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 130
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 131
	
	// initialization
	nCase = 131;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(30);
	v[2] = -sqrt(71);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(30) + sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.171946234813042;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.159230726659372;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.503555909851388;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.721057834853937;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.474523917663001;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.921748841652034;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 131
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 132
	
	// initialization
	nCase = 132;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(31);
	v[2] = -sqrt(70);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(31) + sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.191978607683707;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.171265021885633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.509113894378917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.716125471038175;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.465127791642294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.897795950766088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 132
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 133
	
	// initialization
	nCase = 133;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(2);
	v[2] = -sqrt(69);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(2) + sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.210818550399077;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.182597082843348;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.514354936694511;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.711459231609053;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.456222541327497;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.874910815405704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 133
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 134
	
	// initialization
	nCase = 134;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(33);
	v[2] = -2*sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(17) + sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.22849977548413;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.193244516152904;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.519285814048239;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.70705576528127;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.447804473679883;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.853111444335088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 134
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 135
	
	// initialization
	nCase = 135;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(34);
	v[2] = -sqrt(67);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(34) + sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.245052926096454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.20322336830629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.523912720251012;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.702911999412041;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.439870221139097;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.83241538404809;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 135
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 136
	
	// initialization
	nCase = 136;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(35);
	v[2] = -sqrt(66);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(35) + sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.260505848576306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.212548257680305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.528241312463331;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.6990251192285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.43241671526568;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.81283965186959;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 136
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 137
	
	// initialization
	nCase = 137;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  6;
	v[2] = -sqrt(65);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6 + sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.274883828982459;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.221232489493602;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.53227675207616;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.695392549580657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.425441163510957;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.794400669965873;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 137
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 138
	
	// initialization
	nCase = 138;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(37);
	v[2] = -8;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8 + sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.28820979880583;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.22928815610344;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.536023740491805;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.69201193889017;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.418941028716857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.777114200565808;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 138
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 139
	
	// initialization
	nCase = 139;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(38);
	v[2] = -3*sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(7) + sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.300504514145487;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.23672622462644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.539486550476182;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.688881145019247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.412914011012377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.760995282723457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 139
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 140
	
	// initialization
	nCase = 140;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(39);
	v[2] = -sqrt(62);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(39) + sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.311786711897854;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.243556613533531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.542669053642813;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.685998222828333;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.407358031826705;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.746058170975296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 140
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 141
	
	// initialization
	nCase = 141;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(10);
	v[2] = -sqrt(61);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(10) + sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.322073245912241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.249788259596027;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.545574744537527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.683361413227868;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.402271219782598;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.73231627626141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 141
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 142
	
	// initialization
	nCase = 142;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(41);
	v[2] = -2*sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(15) + sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.33137920557585;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.255429176334836;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.548206761717463;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.680969133559897;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.397651898270498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.719782109489822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 142
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 143
	
	// initialization
	nCase = 143;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(42);
	v[2] = -sqrt(59);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(42) + sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.339718018886586;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.260486504938353;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55056790615525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.678819969170792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.393498574534412;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.70846722812644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 143
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 144
	
	// initialization
	nCase = 144;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(43);
	v[2] = -sqrt(58);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(43) + sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.347101541735265;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.264966558458806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.552660657246522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.676912666057994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.389809930126768;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.698382186190072;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 144
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 145
	
	// initialization
	nCase = 145;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(11);
	v[2] = -sqrt(57);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(11) + sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.353540134836518;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.268874859965809;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55448718665459;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.675246124491842;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.38658481261145;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.68953648802244;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 145
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 146
	
	// initialization
	nCase = 146;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(5);
	v[2] = -2*sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(5) + 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.359042729508984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.272216175224553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55604937018815;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.67381939352943;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.38382222841341;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.681938546187444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 146
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 147
	
	// initialization
	nCase = 147;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(46);
	v[2] = -sqrt(55);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(46) + sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.363616883301658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.274994540370912;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55734879787538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.672631666350838;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.381521336729667;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.67559564383209;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 147
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 148
	
	// initialization
	nCase = 148;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(47);
	v[2] = -3*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(6) + sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.367268826287734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.277213284973191;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.558386782369551;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.671682276360098;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.379681444430986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.67051390181412;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 148
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 149
	
	// initialization
	nCase = 149;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(3);
	v[2] = -sqrt(53);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(3) + sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.370003498694015;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.27887505079815;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55916436579637;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670970694003618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.378302001896317;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.666698250868489;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 149
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 150
	
	// initialization
	nCase = 150;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  7;
	v[2] = -2*sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 7 + 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.37182458039843;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.27998180653482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.559682325131217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670496524268247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.377382599733556;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.66415240904737;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 150
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 151
	
	// initialization
	nCase = 151;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5*sqrt(2);
	v[2] = -sqrt(51);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5*sqrt(2) + sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.372734512706538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.280534858671944;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.559941176174434;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670259504829668;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.376922966350643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.66287886462663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 151
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 152
	
	// initialization
	nCase = 152;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(51);
	v[2] = -5*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5*sqrt(2) + sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.372734512706538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.280534858671944;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.559941176174434;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670259504829668;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.376922966350643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.66287886462663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 152
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 153
	
	// initialization
	nCase = 153;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(13);
	v[2] = -7;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 7 + 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.37182458039843;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.27998180653482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.559682325131217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670496524268247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.377382599733556;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.66415240904737;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 153
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 154
	
	// initialization
	nCase = 154;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(53);
	v[2] = -4*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(3) + sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.370003498694015;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.27887505079815;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55916436579637;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.670970694003618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.378302001896317;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.666698250868489;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 154
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 155
	
	// initialization
	nCase = 155;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(6);
	v[2] = -sqrt(47);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(6) + sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.367268826287734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.277213284973191;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.558386782369551;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.671682276360098;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.379681444430986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.67051390181412;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 155
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 156
	
	// initialization
	nCase = 156;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(55);
	v[2] = -sqrt(46);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(46) + sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.363616883301658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.274994540370912;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55734879787538;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.672631666350838;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.381521336729667;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.67559564383209;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 156
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 157
	
	// initialization
	nCase = 157;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(14);
	v[2] = -3*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(5) + 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.359042729508984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.272216175224553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55604937018815;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.67381939352943;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.38382222841341;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.681938546187444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 157
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 158
	
	// initialization
	nCase = 158;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(57);
	v[2] = -2*sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(11) + sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.353540134836518;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.268874859965809;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55448718665459;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.675246124491842;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.38658481261145;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.68953648802244;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 158
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 159
	
	// initialization
	nCase = 159;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(58);
	v[2] = -sqrt(43);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(43) + sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.347101541735265;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.264966558458806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.552660657246522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.676912666057994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.389809930126768;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.698382186190072;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 159
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 160
	
	// initialization
	nCase = 160;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(59);
	v[2] = -sqrt(42);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(42) + sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.339718018886586;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.260486504938353;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.55056790615525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.678819969170792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.393498574534412;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.70846722812644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 160
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 161
	
	// initialization
	nCase = 161;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(15);
	v[2] = -sqrt(41);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(15) + sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.33137920557585;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.255429176334836;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.548206761717463;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.680969133559897;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.397651898270498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.719782109489822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 161
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 162
	
	// initialization
	nCase = 162;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(61);
	v[2] = -2*sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(10) + sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.322073245912241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.249788259596027;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.545574744537527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.683361413227868;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.402271219782598;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.73231627626141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 162
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 163
	
	// initialization
	nCase = 163;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(62);
	v[2] = -sqrt(39);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(39) + sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.311786711897854;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.243556613533531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.542669053642813;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.685998222828333;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.407358031826705;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.746058170975296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 163
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 164
	
	// initialization
	nCase = 164;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(7);
	v[2] = -sqrt(38);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(7) + sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.300504514145487;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.23672622462644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.539486550476182;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.688881145019247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.412914011012377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.760995282723457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 164
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 165
	
	// initialization
	nCase = 165;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  8;
	v[2] = -sqrt(37);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 8 + sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.28820979880583;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.22928815610344;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.536023740491805;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.69201193889017;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.418941028716857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.777114200565808;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 165
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 166
	
	// initialization
	nCase = 166;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(65);
	v[2] = -6;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6 + sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.274883828982459;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.221232489493602;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.53227675207616;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.695392549580657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.425441163510957;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.794400669965873;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 166
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 167
	
	// initialization
	nCase = 167;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(66);
	v[2] = -sqrt(35);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(35) + sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.260505848576306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.212548257680305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.528241312463331;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.6990251192285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.43241671526568;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.81283965186959;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 167
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 168
	
	// initialization
	nCase = 168;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(67);
	v[2] = -sqrt(34);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(34) + sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.245052926096454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.20322336830629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.523912720251012;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.702911999412041;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.439870221139097;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.83241538404809;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 168
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 169
	
	// initialization
	nCase = 169;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(17);
	v[2] = -sqrt(33);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(17) + sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.22849977548413;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.193244516152904;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.519285814048239;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.70705576528127;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.447804473679883;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.853111444335088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 169
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 170
	
	// initialization
	nCase = 170;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(69);
	v[2] = -4*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(2) + sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.210818550399077;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.182597082843348;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.514354936694511;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.711459231609053;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.456222541327497;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.874910815405704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 170
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 171
	
	// initialization
	nCase = 171;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(70);
	v[2] = -sqrt(31);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(31) + sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.191978607683707;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.171265021885633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.509113894378917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.716125471038175;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.465127791642294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.897795950766088;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 171
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 172
	
	// initialization
	nCase = 172;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(71);
	v[2] = -sqrt(30);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(30) + sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.171946234813042;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.159230726659372;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.503555909851388;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.721057834853937;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.474523917663001;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.921748841652034;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 172
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 173
	
	// initialization
	nCase = 173;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  6*sqrt(2);
	v[2] = -sqrt(29);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 6*sqrt(2) + sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 6*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.150684335008185;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.146474878439964;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.497673568749759;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.726259976678246;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.484414967867846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.946751084570108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 173
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 174
	
	// initialization
	nCase = 174;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(73);
	v[2] = -2*sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(7) + sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.128152062273253;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.132976270916075;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.491458757856671;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.73173587956311;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.494805380312625;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.972783949256549;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 174
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 175
	
	// initialization
	nCase = 175;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(74);
	v[2] = -3*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(3) + sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.104304396822663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.118711606853118;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.484902593837498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.737489887063292;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.505700021639308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 8.999828446878139;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 175
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 176
	
	// initialization
	nCase = 176;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  5*sqrt(3);
	v[2] = -sqrt(26);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5*sqrt(3) + sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 5*sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.079091649080548;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.103655261536627;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.47799534067833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.743526738995662;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.517104231799172;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.02786539835551;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 176
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 177
	
	// initialization
	nCase = 177;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(19);
	v[2] = -5;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 5 + 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.052458877496282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.08777900632522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.470726313620103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.749851612754359;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.529023875524024;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.056875502754618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 177
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 178
	
	// initialization
	nCase = 178;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(77);
	v[2] = -2*sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(6) + sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 12.024345201608584;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.07105168395898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.463083766840876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.756470171256792;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.541465401819734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.086839405767428;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 178
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 179
	
	// initialization
	nCase = 179;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(78);
	v[2] = -sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(23) + sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.994682986798203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.053438825074002;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.455054761432848;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.763388618860578;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.554435913065037;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.117737768390992;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 179
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 180
	
	// initialization
	nCase = 180;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(79);
	v[2] = -sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(22) + sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.963396870559656;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.03490219248241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.446625009295769;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.77061376693572;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.567943245697885;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.149551336018302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 180
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 181
	
	// initialization
	nCase = 181;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(5);
	v[2] = -sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4*sqrt(5) + sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.930402591275207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 11.015399235926921;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.43777868734308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.778153111228539;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.581996064994042;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.182261008279559;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 181
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 182
	
	// initialization
	nCase = 182;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  9;
	v[2] = -2*sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 9 + 2*sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.895605568484557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.994882434829517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.428498214774422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.786014923754108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.596603977133304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.21584791012588;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 182
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 183
	
	// initialization
	nCase = 183;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(82);
	v[2] = -sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(19) + sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.85889916718076;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.973298499468443;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.418763983937485;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.794208362761237;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.611777662673202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.250293464839448;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 183
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 184
	
	// initialization
	nCase = 184;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(83);
	v[2] = -3*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(2) + sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.820162555728468;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.950587391205325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.408554032230994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.802743605413829;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.62752903680389;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.285579469898911;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 184
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 185
	
	// initialization
	nCase = 185;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(21);
	v[2] = -sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(17) + 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.779258034541705;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.926681108582804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.397843638206671;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.81163200935369;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.643871443483219;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.321688176949294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 185
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 186
	
	// initialization
	nCase = 186;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(85);
	v[2] = -4;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 4 + sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.736027665913516;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.901502166366019;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.386604818923296;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.820886311447563;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.660819892963058;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.358602377553106;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 186
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 187
	
	// initialization
	nCase = 187;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(86);
	v[2] = -sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(15) + sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.690288966760512;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.874961665807739;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.374805696763527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.830520875080444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.67839135565021;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.396305496984326;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 187
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 188
	
	// initialization
	nCase = 188;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(87);
	v[2] = -sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(14) + sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.641829323102003;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.846956811537982;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.36240969084892;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.84055200182302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.696605130225619;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.43478169914501;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 188
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 189
	
	// initialization
	nCase = 189;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(22);
	v[2] = -sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(13) + 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.590398626921163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.817367665099665;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.34937446840007;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.850998329967437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.715483311333013;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.474016006857527;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 189
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 190
	
	// initialization
	nCase = 190;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(89);
	v[2] = -2*sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(3) + sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.535699386339124;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.786052822772554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.335650560647146;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.861881352631706;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.735051393380163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.513994443511633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 190
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 191
	
	// initialization
	nCase = 191;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(10);
	v[2] = -sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3*sqrt(10) + sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.477373153421446;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.752843540073613;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.321179498694345;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.873226104212742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.755339064561658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.554704204657614;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 191
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 192
	
	// initialization
	nCase = 192;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(91);
	v[2] = -sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(10) + sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.414981427925975;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.717535549118926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.305891243254228;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.885062090150678;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.776381273585576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.596133872215274;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 192
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 193
	
	// initialization
	nCase = 193;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  2*sqrt(23);
	v[2] = -3;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 3 + 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 2*sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.347977989144452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.679877334311188;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.289700541736027;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.897424579264857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.798219699171037;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.638273690566715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 193
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 194
	
	// initialization
	nCase = 194;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(93);
	v[2] = -2*sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2*sqrt(2) + sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.275667381648534;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.639552754257629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.272501592558552;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.910356456321452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.820904835792241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.681115934925455;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 194
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 195
	
	// initialization
	nCase = 195;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(94);
	v[2] = -sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(7) + sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.197139924959043;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.596154201675331;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.254159912150799;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.923910978930806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.844499063278276;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.724655422071278;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 195
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 196
	
	// initialization
	nCase = 196;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(95);
	v[2] = -sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(6) + sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.111164466541826;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.549138977791452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.234499309349086;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.93815607498676;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.869081371662872;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.76889025054679;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 196
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 197
	
	// initialization
	nCase = 197;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  4*sqrt(6);
	v[2] = -sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(5) + 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 4*sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 11.015999078297595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.49775360616714;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.213279664073452;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.953181449565454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.894755061675692;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.813822932275217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 197
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 198
	
	// initialization
	nCase = 198;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  sqrt(97);
	v[2] = -2;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2 + sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.909025671273898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.440890659006216;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.190155707984397;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.969111294834208;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.921661280247621;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.859462244147108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 198
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 199
	
	// initialization
	nCase = 199;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  7*sqrt(2);
	v[2] = -sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 7*sqrt(2) + sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 7*sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.785950533454963;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.376783018144137;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.164591061730384;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 9.986129644126372;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.950005455674738;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.9058265497531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 199
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 200
	
	// initialization
	nCase = 200;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  3*sqrt(11);
	v[2] = -sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2) + 3*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 3*sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.638685155102575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.302218273773835;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.135643939762721;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.004540058914365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 9.980117843999242;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 9.952950628100611;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 200
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 201
	
	// initialization
	nCase = 201;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  10;
	v[2] = -1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 11;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 10.447398443913816;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 10.209722733624439;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 10.101231992597612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 10.024954020749846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 10.012637130837746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 10.000903405880523;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 201
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 202
	
	// initialization
	nCase = 202;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1;
	v[2] = -0.1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 11/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101)/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.0447398443913816;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 1.0209722733624438;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 1.0101231992597612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 1.0024954020749846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 1.0012637130837745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 1.0000903405880524;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 202
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 203
	
	// initialization
	nCase = 203;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(2);
	v[2] = -1/(3.*sqrt(11));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(2) + 1/(3*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/22)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.7560584320498891;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.7321467720068139;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.7203088495609379;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.7109917024563146;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.7092560912180161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.7073254012543576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 203
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 204
	
	// initialization
	nCase = 204;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(3);
	v[2] = -1/(7.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(7*sqrt(2)) + 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/6)/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.6290494094729687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.6051862753816841;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5928109891736703;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5824029079378708;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5802961024836175;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.5777195363668928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 204
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 205
	
	// initialization
	nCase = 205;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.5;
	v[2] = -1/sqrt(97);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/2 + 1/sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/97)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5538218690336079;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5300559145600694;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5173267760108209;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5061049461500081;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5036960366327068;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.5005383589937237;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 205
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 206
	
	// initialization
	nCase = 206;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(5);
	v[2] = -1/(4.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(5) + 1/(4*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/30)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.502809265719976;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.4791547044357456;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.4661703048434846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4542984999057473;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.4516317123556832;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.44793768294738595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 206
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 207
	
	// initialization
	nCase = 207;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(6);
	v[2] = -1/sqrt(95);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(6) + 1/sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/570);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4653954662482857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.44185480899602125;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.42867600351295243;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4162635513221062;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.41337033037697624;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.4091737861114164;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 207
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 208
	
	// initialization
	nCase = 208;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(7);
	v[2] = -1/sqrt(94);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(7) + 1/sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/658);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4365099609943424;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.41308109823234657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.39974877274734666;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3868743289229064;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.38377853013533353;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3791065385821979;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 208
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 209
	
	// initialization
	nCase = 209;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(2));
	v[2] = -1/sqrt(93);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(2)) + 1/sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/186)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.41338602286478343;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.39006492913234364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3766081806502422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.36333129578819573;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.36005184026704734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.35492693051101726;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 209
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 210
	
	// initialization
	nCase = 210;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.3333333333333333;
	v[2] = -1/(2.*sqrt(23));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/3 + 1/(2*sqrt(23));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/23)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3943694968565062;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3711513940942218;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.35759181321380873;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3439592811365836;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.34051167322918935;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3349531651850397;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 210
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 211
	
	// initialization
	nCase = 211;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(10);
	v[2] = -1/sqrt(91);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(10) + 1/sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/910);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3784029496549635;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3552828439034435;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3416369680400981;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3276866174555928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3240838834679111;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.31810874029515895;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 211
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 212
	
	// initialization
	nCase = 212;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(11);
	v[2] = -1/(3.*sqrt(10));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(10)) + 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/110)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.364774864153302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.34174780144904426;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3280286176297878;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3137917241843285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3100450281155211;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.30366843368161994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 212
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 213
	
	// initialization
	nCase = 213;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(3));
	v[2] = -1/sqrt(89);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(3)) + 1/sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/267)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.35298666876502366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.33004785644317386;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3162657710413859;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3017686687071437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.29788773497989846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2911235021641704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 213
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 214
	
	// initialization
	nCase = 214;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(13);
	v[2] = -1/(2.*sqrt(22));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(13) + 1/(2*sqrt(22));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/286)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3426773191276663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.31982217961724557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3059856706948942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.29125087126887483;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2872442857508135;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.28010515523269225;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 214
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 215
	
	// initialization
	nCase = 215;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(14);
	v[2] = -1/sqrt(87);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(14) + 1/sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1218);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.33357814079554954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.31080233063564205;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2969184019882304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2819653982262118;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.27784082909981933;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2703386942606436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 215
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 216
	
	// initialization
	nCase = 216;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(15);
	v[2] = -1/sqrt(86);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(15) + 1/sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1290);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3254845596146887;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.30278397041223165;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.28885847671520765;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.27370433416200013;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.26946869809030555;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.26161477833327845;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 216
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 217
	
	// initialization
	nCase = 217;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.25;
	v[2] = -1/sqrt(85);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/4 + 1/sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/85)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.31823773181737924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2956084819826066;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2816463673188114;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.26630617046591165;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.26196576028550717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.25377073728816996;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 217
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 218
	
	// initialization
	nCase = 218;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(17);
	v[2] = -1/(2.*sqrt(21));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(17) + 1/(2*sqrt(21));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/357)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3117122225625724;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2891506445992661;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2751561211087442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.25964331638148974;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2552039010386477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2466780276950754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 218
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 219
	
	// initialization
	nCase = 219;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(2));
	v[2] = -1/sqrt(83);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(2)) + 1/sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/166)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.30580751271876533;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2833101386825717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2692868227986285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2536134867568778;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24908039077227742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.24023357956833236;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 219
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 220
	
	// initialization
	nCase = 220;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(19);
	v[2] = -1/sqrt(82);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(19) + 1/sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1558);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3004420037175101;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.27800555027017826;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2639565682670496;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24813362048632107;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24351178802941628;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2343536836237433;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 220
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 221
	
	// initialization
	nCase = 221;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(5));
	v[2] = -0.1111111111111111;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/9 + 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/5)/18;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2955486964961833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.27317005032108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.25909812123856457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24313549553712896;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.23842954273349895;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.22896958219267602;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 221
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 222
	
	// initialization
	nCase = 222;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(21);
	v[2] = -1/(4.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(5)) + 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/105)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2910720189782711;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2687482229474575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.25465572455996893;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23856250836374643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.23377676647050608;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.22402422969531233;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 222
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 223
	
	// initialization
	nCase = 223;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(22);
	v[2] = -1/sqrt(79);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(22) + 1/sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1738);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.28696545812283436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.26469369839255746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2505827202813325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23436726927197693;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.22950582067135986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.21946987291043998;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 223
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 224
	
	// initialization
	nCase = 224;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(23);
	v[2] = -1/sqrt(78);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(23) + 1/sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1794);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.28318976619126995;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.26096736028183903;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2468397469667035;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23050978031289168;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2255764887899393;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.21526621667832796;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 224
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 225
	
	// initialization
	nCase = 225;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(6));
	v[2] = -1/sqrt(77);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(6)) + 1/sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/462)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.27971158376193517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25753596961073083;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.24339335592804978;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22695603608945275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2219545725114141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2113790147373304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 225
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 226
	
	// initialization
	nCase = 226;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.2;
	v[2] = -1/(2.*sqrt(19));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/5 + 1/(2*sqrt(19));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/19)/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2765023698325576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2543710957730709;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2402149361396958;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22367693628691213;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21861080054734483;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20777897400387638;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 226
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 227
	
	// initialization
	nCase = 227;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(26);
	v[2] = -1/(5.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(5*sqrt(3)) + 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/78)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2735375613516336;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25144827695393457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23727986976248308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22064743116277147;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.215519971064531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20444089315813196;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 227
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 228
	
	// initialization
	nCase = 228;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(3));
	v[2] = -1/sqrt(74);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(3)) + 1/sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/222)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2707959063360423;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24874635403726414;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2345668621394422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2178458433429285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2126602709523768;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20134297860032302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 228
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 229
	
	// initialization
	nCase = 229;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(7));
	v[2] = -1/sqrt(73);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(7)) + 1/sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/511)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2682589298550525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2462469373077647;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23205740532853475;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2152533246020575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21001273049896502;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19846629624109358;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 229
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 230
	
	// initialization
	nCase = 230;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(29);
	v[2] = -1/(6.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(6*sqrt(2)) + 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/58)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26591050280573914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24393397587474358;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2297353449397207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.21285341710065148;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2075607828653478;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1957943284331258;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 230
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 231
	
	// initialization
	nCase = 231;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(30);
	v[2] = -1/sqrt(71);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(30) + 1/sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2130);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26373649100368846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24179340734615795;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22758652768299947;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2106316962586937;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20528990547363687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19331261309581946;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 231
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 232
	
	// initialization
	nCase = 232;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(31);
	v[2] = -1/sqrt(70);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(31) + 1/sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2170);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26172446760820917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23981287077723173;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22559851255865254;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2085754780212126;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20318732601368017;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1910084476881448;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 232
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 233
	
	// initialization
	nCase = 233;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(2));
	v[2] = -1/sqrt(69);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(2)) + 1/sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/138)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25986347592343223;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23798146994035324;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22376033266441728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20667357735261363;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20124177986532804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1888706447878889;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 233
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 234
	
	// initialization
	nCase = 234;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(33);
	v[2] = -1/(2.*sqrt(17));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(17)) + 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/561)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2581438325936853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2362895769398308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2220622975870554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20491610781839587;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19944330876310898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18688932907382724;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 234
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 235
	
	// initialization
	nCase = 235;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(34);
	v[2] = -1/sqrt(67);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(34) + 1/sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2278);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2565569634380327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.234728668421276;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22049582858399305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20329431437330442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1977830927968567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18505576778075364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 235
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 236
	
	// initialization
	nCase = 236;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(35);
	v[2] = -1/sqrt(66);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(35) + 1/sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2310);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25509526585041914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23329118830653683;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2190533204510533;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20180043318251745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19625330955427422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18336222841505678;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 236
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 237
	
	// initialization
	nCase = 237;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.16666666666666666;
	v[2] = -1/sqrt(65);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/6 + 1/sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/65)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25375199297353435;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23197043226635697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21772802526064286;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20042757360423763;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19484701551704697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18180185882839567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 237
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 238
	
	// initialization
	nCase = 238;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(37);
	v[2] = -0.125;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/8 + 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/37)/8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25252115583993084;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23076045012793106;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2165139541452569;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19916961846312203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19355804582624142;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1803685857545612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 238
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 239
	
	// initialization
	nCase = 239;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(38);
	v[2] = -1/(3.*sqrt(7));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(7)) + 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/266)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25139744043783346;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22965596317802825;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21540579406898822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19802113952018133;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19238092931136366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17905702869599874;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 239
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 240
	
	// initialization
	nCase = 240;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(39);
	v[2] = -1/sqrt(62);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(39) + 1/sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2418);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2503761372559748;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22865229391887718;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21439883712965113;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19697732565139284;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19131081628603522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17786242665726731;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 240
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 241
	
	// initialization
	nCase = 241;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(10));
	v[2] = -1/sqrt(61);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(10)) + 1/sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/610)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(10));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24945308133176547;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22774530630363812;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21348892040647643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19603392172499465;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19034341709255984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17678057570381456;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 241
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 242
	
	// initialization
	nCase = 242;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(41);
	v[2] = -1/(2.*sqrt(15));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(15)) + 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/615)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24862460119994706;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22693135485081525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21267237474302633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19518717654648005;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1894749497580079;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17580777570622938;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 242
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 243
	
	// initialization
	nCase = 243;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(42);
	v[2] = -1/sqrt(59);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(42) + 1/sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2478);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24788747543686876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22620724133467357;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21194598115444285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1944337985433305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18870209542853592;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1749407849353555;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 243
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 244
	
	// initialization
	nCase = 244;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(43);
	v[2] = -1/sqrt(58);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(43) + 1/sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2494);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2472388957355282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2255701779884759;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21130693378931342;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19377091810561728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18802196049363434;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1741767814195023;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 244
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 245
	
	// initialization
	nCase = 245;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(11));
	v[2] = -1/sqrt(57);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(11)) + 1/sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/627)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24667643564135663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22501775635196442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21075280857221082;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19319605569679732;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18743204451093365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17351333017458592;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 245
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 246
	
	// initialization
	nCase = 246;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(5));
	v[2] = -1/(2.*sqrt(14));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(5)) + 1/(2*sqrt(14));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/70)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24619802423825618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22454792105383833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21028153681325307;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19270709501133776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18693021320512881;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17294835558143806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 246
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 247
	
	// initialization
	nCase = 247;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(46);
	v[2] = -1/sqrt(55);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(46) + 1/sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2530);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24580192420626548;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2241589479516622;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20989138320351144;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19230226058999136;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1865146759492988;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1724801183195473;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 247
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 248
	
	// initialization
	nCase = 248;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(47);
	v[2] = -1/(3.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(6)) + 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/282)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24548671378240286;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2238494261616462;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20958092772577658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19198009941567926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.186183967249486;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17210719637925875;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 248
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 249
	
	// initialization
	nCase = 249;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(3));
	v[2] = -1/sqrt(53);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(3)) + 1/sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/159)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24525127224945703;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2236182436038072;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20934905110383337;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19173946610783177;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18593693184868804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17182846976979807;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 249
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 250
	
	// initialization
	nCase = 250;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.14285714285714285;
	v[2] = -1/(2.*sqrt(13));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/7 + 1/(2*sqrt(13));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/13)/14;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24509476865754007;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22346457576792425;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20919492349379892;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19157951141453544;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18577271314825902;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.171643108622281;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 250
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 251
	
	// initialization
	nCase = 251;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(5.*sqrt(2));
	v[2] = -1/sqrt(51);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(5*sqrt(2)) + 1/sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/102)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(5*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24501665355318156;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.223387877475535;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20911799619134652;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19149967377307853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18569074471627275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1715505644582924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 251
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 252
	
	// initialization
	nCase = 252;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(51);
	v[2] = -1/(5.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(5*sqrt(2)) + 1/sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/102)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(5*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24501665355318156;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.223387877475535;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20911799619134652;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19149967377307853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18569074471627275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1715505644582924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 252
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 253
	
	// initialization
	nCase = 253;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(13));
	v[2] = -0.14285714285714285;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/7 + 1/(2*sqrt(13));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/13)/14;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24509476865754007;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22346457576792425;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20919492349379892;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19157951141453544;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18577271314825902;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.171643108622281;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 253
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 254
	
	// initialization
	nCase = 254;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(53);
	v[2] = -1/(4.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(3)) + 1/sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/159)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24525127224945703;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2236182436038072;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20934905110383337;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19173946610783177;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18593693184868804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17182846976979807;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 254
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 255
	
	// initialization
	nCase = 255;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(6));
	v[2] = -1/sqrt(47);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(6)) + 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/282)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24548671378240286;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2238494261616462;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20958092772577658;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19198009941567926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.186183967249486;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17210719637925875;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 255
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 256
	
	// initialization
	nCase = 256;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(55);
	v[2] = -1/sqrt(46);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(46) + 1/sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2530);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24580192420626548;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2241589479516622;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20989138320351144;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19230226058999136;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1865146759492988;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1724801183195473;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 256
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 257
	
	// initialization
	nCase = 257;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(14));
	v[2] = -1/(3.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(5)) + 1/(2*sqrt(14));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/70)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24619802423825618;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22454792105383833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21028153681325307;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19270709501133776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18693021320512881;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17294835558143806;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 257
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 258
	
	// initialization
	nCase = 258;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(57);
	v[2] = -1/(2.*sqrt(11));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(11)) + 1/sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/627)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24667643564135663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22501775635196442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21075280857221082;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19319605569679732;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18743204451093365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17351333017458592;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 258
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 259
	
	// initialization
	nCase = 259;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(58);
	v[2] = -1/sqrt(43);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(43) + 1/sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2494);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2472388957355282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2255701779884759;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21130693378931342;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19377091810561728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18802196049363434;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1741767814195023;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 259
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 260
	
	// initialization
	nCase = 260;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(59);
	v[2] = -1/sqrt(42);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(42) + 1/sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2478);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24788747543686876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22620724133467357;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21194598115444285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1944337985433305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18870209542853592;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1749407849353555;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 260
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 261
	
	// initialization
	nCase = 261;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(15));
	v[2] = -1/sqrt(41);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(15)) + 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/615)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24862460119994706;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22693135485081525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21267237474302633;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19518717654648005;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1894749497580079;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17580777570622938;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 261
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 262
	
	// initialization
	nCase = 262;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(61);
	v[2] = -1/(2.*sqrt(10));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(10)) + 1/sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/610)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(10));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24945308133176547;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22774530630363812;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21348892040647643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19603392172499465;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19034341709255984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17678057570381456;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 262
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 263
	
	// initialization
	nCase = 263;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(62);
	v[2] = -1/sqrt(39);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(39) + 1/sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2418);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2503761372559748;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22865229391887718;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21439883712965113;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19697732565139284;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19131081628603522;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17786242665726731;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 263
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 264
	
	// initialization
	nCase = 264;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(7));
	v[2] = -1/sqrt(38);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(7)) + 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/266)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25139744043783346;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22965596317802825;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21540579406898822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19802113952018133;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19238092931136366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17905702869599874;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 264
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 265
	
	// initialization
	nCase = 265;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.125;
	v[2] = -1/sqrt(37);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/8 + 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/37)/8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25252115583993084;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23076045012793106;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2165139541452569;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19916961846312203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19355804582624142;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1803685857545612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 265
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 266
	
	// initialization
	nCase = 266;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(65);
	v[2] = -0.16666666666666666;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/6 + 1/sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/65)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25375199297353435;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23197043226635697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21772802526064286;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20042757360423763;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19484701551704697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18180185882839567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 266
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 267
	
	// initialization
	nCase = 267;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(66);
	v[2] = -1/sqrt(35);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(35) + 1/sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2310);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25509526585041914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23329118830653683;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2190533204510533;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20180043318251745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19625330955427422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18336222841505678;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 267
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 268
	
	// initialization
	nCase = 268;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(67);
	v[2] = -1/sqrt(34);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(34) + 1/sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2278);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2565569634380327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.234728668421276;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22049582858399305;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20329431437330442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1977830927968567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18505576778075364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 268
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 269
	
	// initialization
	nCase = 269;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(17));
	v[2] = -1/sqrt(33);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(17)) + 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/561)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2581438325936853;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2362895769398308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2220622975870554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20491610781839587;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19944330876310898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18688932907382724;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 269
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 270
	
	// initialization
	nCase = 270;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(69);
	v[2] = -1/(4.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(2)) + 1/sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/138)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25986347592343223;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23798146994035324;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22376033266441728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20667357735261363;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20124177986532804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1888706447878889;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 270
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 271
	
	// initialization
	nCase = 271;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(70);
	v[2] = -1/sqrt(31);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(31) + 1/sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2170);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26172446760820917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23981287077723173;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22559851255865254;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2085754780212126;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20318732601368017;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1910084476881448;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 271
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 272
	
	// initialization
	nCase = 272;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(71);
	v[2] = -1/sqrt(30);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(30) + 1/sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/2130);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26373649100368846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24179340734615795;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22758652768299947;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2106316962586937;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20528990547363687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19331261309581946;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 272
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 273
	
	// initialization
	nCase = 273;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(6.*sqrt(2));
	v[2] = -1/sqrt(29);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(6*sqrt(2)) + 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/58)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.26591050280573914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24393397587474358;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2297353449397207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.21285341710065148;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2075607828653478;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1957943284331258;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 273
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 274
	
	// initialization
	nCase = 274;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(73);
	v[2] = -1/(2.*sqrt(7));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(7)) + 1/sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/511)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2682589298550525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2462469373077647;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23205740532853475;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2152533246020575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21001273049896502;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19846629624109358;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 274
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 275
	
	// initialization
	nCase = 275;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(74);
	v[2] = -1/(3.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(3)) + 1/sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/222)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2707959063360423;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24874635403726414;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2345668621394422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2178458433429285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2126602709523768;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20134297860032302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 275
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 276
	
	// initialization
	nCase = 276;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(5.*sqrt(3));
	v[2] = -1/sqrt(26);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(5*sqrt(3)) + 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/78)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2735375613516336;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25144827695393457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23727986976248308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22064743116277147;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.215519971064531;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20444089315813196;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 276
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 277
	
	// initialization
	nCase = 277;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(19));
	v[2] = -0.2;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/5 + 1/(2*sqrt(19));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/19)/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2765023698325576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2543710957730709;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2402149361396958;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22367693628691213;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21861080054734483;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20777897400387638;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 277
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 278
	
	// initialization
	nCase = 278;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(77);
	v[2] = -1/(2.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(6)) + 1/sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/462)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.27971158376193517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25753596961073083;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.24339335592804978;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22695603608945275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2219545725114141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2113790147373304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 278
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 279
	
	// initialization
	nCase = 279;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(78);
	v[2] = -1/sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(23) + 1/sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1794);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.28318976619126995;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.26096736028183903;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2468397469667035;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23050978031289168;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2255764887899393;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.21526621667832796;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 279
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 280
	
	// initialization
	nCase = 280;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(79);
	v[2] = -1/sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(22) + 1/sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1738);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.28696545812283436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.26469369839255746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2505827202813325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23436726927197693;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.22950582067135986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.21946987291043998;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 280
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 281
	
	// initialization
	nCase = 281;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(5));
	v[2] = -1/sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(4*sqrt(5)) + 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/105)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2910720189782711;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2687482229474575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.25465572455996893;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23856250836374643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.23377676647050608;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.22402422969531233;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 281
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 282
	
	// initialization
	nCase = 282;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.1111111111111111;
	v[2] = -1/(2.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/9 + 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/5)/18;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2955486964961833;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.27317005032108;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.25909812123856457;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24313549553712896;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.23842954273349895;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.22896958219267602;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 282
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 283
	
	// initialization
	nCase = 283;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(82);
	v[2] = -1/sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(19) + 1/sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1558);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3004420037175101;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.27800555027017826;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2639565682670496;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24813362048632107;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24351178802941628;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2343536836237433;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 283
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 284
	
	// initialization
	nCase = 284;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(83);
	v[2] = -1/(3.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(2)) + 1/sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/166)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.30580751271876533;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2833101386825717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2692868227986285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2536134867568778;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24908039077227742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.24023357956833236;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 284
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 285
	
	// initialization
	nCase = 285;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(21));
	v[2] = -1/sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(17) + 1/(2*sqrt(21));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/357)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3117122225625724;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2891506445992661;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2751561211087442;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.25964331638148974;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2552039010386477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2466780276950754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 285
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 286
	
	// initialization
	nCase = 286;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(85);
	v[2] = -0.25;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/4 + 1/sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/85)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.31823773181737924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2956084819826066;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2816463673188114;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.26630617046591165;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.26196576028550717;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.25377073728816996;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 286
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 287
	
	// initialization
	nCase = 287;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(86);
	v[2] = -1/sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(15) + 1/sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1290);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3254845596146887;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.30278397041223165;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.28885847671520765;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.27370433416200013;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.26946869809030555;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.26161477833327845;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 287
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 288
	
	// initialization
	nCase = 288;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(87);
	v[2] = -1/sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(14) + 1/sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/1218);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.33357814079554954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.31080233063564205;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2969184019882304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2819653982262118;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.27784082909981933;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2703386942606436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 288
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 289
	
	// initialization
	nCase = 289;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(22));
	v[2] = -1/sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(13) + 1/(2*sqrt(22));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/286)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3426773191276663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.31982217961724557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3059856706948942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.29125087126887483;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2872442857508135;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.28010515523269225;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 289
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 290
	
	// initialization
	nCase = 290;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(89);
	v[2] = -1/(2.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(3)) + 1/sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/267)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.35298666876502366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.33004785644317386;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3162657710413859;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3017686687071437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.29788773497989846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2911235021641704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 290
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 291
	
	// initialization
	nCase = 291;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(10));
	v[2] = -1/sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(10)) + 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/110)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.364774864153302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.34174780144904426;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3280286176297878;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3137917241843285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3100450281155211;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.30366843368161994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 291
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 292
	
	// initialization
	nCase = 292;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(91);
	v[2] = -1/sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(10) + 1/sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/910);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3784029496549635;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3552828439034435;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3416369680400981;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3276866174555928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3240838834679111;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.31810874029515895;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 292
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 293
	
	// initialization
	nCase = 293;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(23));
	v[2] = -0.3333333333333333;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/3 + 1/(2*sqrt(23));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/23)/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3943694968565062;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3711513940942218;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.35759181321380873;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3439592811365836;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.34051167322918935;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3349531651850397;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 293
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 294
	
	// initialization
	nCase = 294;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(93);
	v[2] = -1/(2.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(2)) + 1/sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/186)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.41338602286478343;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.39006492913234364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3766081806502422;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.36333129578819573;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.36005184026704734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.35492693051101726;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 294
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 295
	
	// initialization
	nCase = 295;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(94);
	v[2] = -1/sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(7) + 1/sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/658);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4365099609943424;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.41308109823234657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.39974877274734666;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3868743289229064;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.38377853013533353;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3791065385821979;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 295
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 296
	
	// initialization
	nCase = 296;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(95);
	v[2] = -1/sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(6) + 1/sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/570);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4653954662482857;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.44185480899602125;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.42867600351295243;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4162635513221062;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.41337033037697624;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.4091737861114164;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 296
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 297
	
	// initialization
	nCase = 297;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(6));
	v[2] = -1/sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(5) + 1/(4*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/30)/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.502809265719976;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.4791547044357456;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.4661703048434846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4542984999057473;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.4516317123556832;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.44793768294738595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 297
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 298
	
	// initialization
	nCase = 298;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(97);
	v[2] = -0.5;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/2 + 1/sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/97)/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5538218690336079;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5300559145600694;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5173267760108209;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5061049461500081;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5036960366327068;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.5005383589937237;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 298
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 299
	
	// initialization
	nCase = 299;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(7.*sqrt(2));
	v[2] = -1/sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(7*sqrt(2)) + 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/6)/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.6290494094729687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.6051862753816841;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5928109891736703;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5824029079378708;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5802961024836175;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.5777195363668928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 299
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 300
	
	// initialization
	nCase = 300;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(11));
	v[2] = -1/sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(2) + 1/(3*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101/22)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.7560584320498891;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.7321467720068139;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.7203088495609379;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.7109917024563146;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.7092560912180161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.7073254012543576;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 300
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 301
	
	// initialization
	nCase = 301;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.1;
	v[2] = -1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 11/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(101)/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.0447398443913816;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 1.0209722733624438;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 1.0101231992597612;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 1.0024954020749846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 1.0012637130837745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 1.0000903405880524;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 301
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 302
	
	// initialization
	nCase = 302;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1;
	v[2] = -1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.7411011265922482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 1.5874010519681994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 1.4859942891369484;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 1.360790000174377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 1.3195079107728942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 1.2190136542044754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 302
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 303
	
	// initialization
	nCase = 303;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(2);
	v[2] = -1/sqrt(2);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.231144413344916;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 1.1224620483093728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 1.0507566386532192;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.962223836894145;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.9330329915368073;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.8619728212469776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 303
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 304
	
	// initialization
	nCase = 304;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(3);
	v[2] = -1/sqrt(3);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 1.0052252041243954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.9164864246657352;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.8579392028474638;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.7856524729112275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.7618182474825712;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.7037978614007834;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 304
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 305
	
	// initialization
	nCase = 305;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.5;
	v[2] = -0.5;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.8705505632961241;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.7937005259840997;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.7429971445684742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.6803950000871885;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.6597539553864471;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.6095068271022377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 305
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 306
	
	// initialization
	nCase = 306;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(5);
	v[2] = -1/sqrt(5);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.7786440949523468;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.709907331951114;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.6645568489373388;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.6085637886983715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5901018770673837;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.5451594792603258;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 306
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 307
	
	// initialization
	nCase = 307;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(6);
	v[2] = -1/sqrt(6);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.7108015584559914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.6480537657465553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.6066546281792227;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5555401912515093;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.5386868488265776;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.4976602403810838;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 307
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 308
	
	// initialization
	nCase = 308;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(7);
	v[2] = -1/sqrt(7);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.6580743697682109;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5999812020614533;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5616530483883679;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.5143302752921346;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.49872711212678333;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.46074385340244683;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 308
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 309
	
	// initialization
	nCase = 309;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(2));
	v[2] = -1/(2.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(2);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.615572206672458;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5612310241546864;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.5253783193266096;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4811119184470725;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.46651649576840365;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.4309864106234888;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 309
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 310
	
	// initialization
	nCase = 310;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.3333333333333333;
	v[2] = -0.3333333333333333;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5803670421974161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5291336839893998;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.49533142971231614;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.45359666672479226;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.4398359702576314;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.4063378847348251;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 310
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 311
	
	// initialization
	nCase = 311;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(10);
	v[2] = -1/sqrt(10);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5505845196716664;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.5019802884366822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.46991265436755636;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.43031958177319574;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.41726503886525745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3854859646131034;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 311
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 312
	
	// initialization
	nCase = 312;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(11);
	v[2] = -1/sqrt(11);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5249617417246878;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.47861942556308823;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.4480441361525594;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.4102936226405516;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3978466043581311;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.36754644593784436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 312
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 313
	
	// initialization
	nCase = 313;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(3));
	v[2] = -1/(2.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(3);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.5026126020621977;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.4582432123328676;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.4289696014237319;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.39282623645561376;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3809091237412856;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3518989307003917;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 313
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 314
	
	// initialization
	nCase = 314;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(13);
	v[2] = -1/sqrt(13);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4828945682843438;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.4402658375074477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.4121406618869176;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3774152400590282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.36596564851323327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3380935565942281;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 314
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 315
	
	// initialization
	nCase = 315;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(14);
	v[2] = -1/sqrt(14);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.4653288493881655;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.4242507765621099;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3971486791895111;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3636864254286122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3526533229464322;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3257951031308908;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 315
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 316
	
	// initialization
	nCase = 316;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(15);
	v[2] = -1/sqrt(15);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.44955037782364987;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.40986518920166465;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.383682075625782;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.35135446722406327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3406954775741574;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.3147479721022253;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 316
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 317
	
	// initialization
	nCase = 317;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.25;
	v[2] = -0.25;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/2;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.43527528164806206;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.39685026299204984;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3714985722842371;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3401975000435942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.32987697769322355;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.30475341355111885;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 317
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 318
	
	// initialization
	nCase = 318;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(17);
	v[2] = -1/sqrt(17);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.42227904998951443;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.38500130632243973;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3604065537162511;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.33004005323548413;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3200276758796898;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2956542385503067;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 318
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 319
	
	// initialization
	nCase = 319;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(2));
	v[2] = -1/(3.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.41038147111497203;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.37415401610312427;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.35025221288440644;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.320741278964715;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.31101099717893577;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2873242737489925;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 319
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 320
	
	// initialization
	nCase = 320;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(19);
	v[2] = -1/sqrt(19);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.39943599270002245;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3641747772841862;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.34091047036981675;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.3121866365337265;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.3027158756979752;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2796609120775549;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 320
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 321
	
	// initialization
	nCase = 321;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(5));
	v[2] = -1/(2.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(5);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3893220474761734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.354953665975557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3322784244686694;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.30428189434918573;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.29505093853369185;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2725797396301629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 321
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 322
	
	// initialization
	nCase = 322;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(21);
	v[2] = -1/sqrt(21);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.37993941453246993;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3463993085188954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.32427053867819816;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.29694872289228824;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2879402324385631;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2660105877893682;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 322
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 323
	
	// initialization
	nCase = 323;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(22);
	v[2] = -1/sqrt(22);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.37120400743702764;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.33843504142326963;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.3168150469443435;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2901214028467284;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.28132003181367593;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2598945843236645;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 323
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 324
	
	// initialization
	nCase = 324;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(23);
	v[2] = -1/sqrt(23);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3630446812254954;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3309960002247332;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.30985122849155017;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.28374432954108686;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.27513641885848494;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2541819178340197;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 324
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 325
	
	// initialization
	nCase = 325;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(6));
	v[2] = -1/(2.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(6);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3554007792279957;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.32402688287327763;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.30332731408961133;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.27777009562575466;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2693434244132888;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2488301201905419;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 325
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 326
	
	// initialization
	nCase = 326;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.2;
	v[2] = -0.2;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.34822022531844965;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3174802103936399;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2971988578273897;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2721580000348754;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2639015821545789;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2438027308408951;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 326
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 327
	
	// initialization
	nCase = 327;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(26);
	v[2] = -1/sqrt(26);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.34145802383200985;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.3113149592262909;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2914274568229515;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2668728755688876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2587767917450398;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.23906824654325645;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 327
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 328
	
	// initialization
	nCase = 328;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(3));
	v[2] = -1/(3.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/(3*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/3)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3350750680414651;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.30549547488857837;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2859797342824879;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2618841576370758;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2539394158275237;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.23459928713359443;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 328
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 329
	
	// initialization
	nCase = 329;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(7));
	v[2] = -1/(2.*sqrt(7));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(7);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.32903718488410544;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.29999060103072667;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.28082652419418397;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2571651376460673;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24936355606339167;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.23037192670122342;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 329
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 330
	
	// initialization
	nCase = 330;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(29);
	v[2] = -1/sqrt(29);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3233143625029935;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2947729751678427;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.27594221205045344;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2526923592703314;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24502646771826775;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.22636515275994382;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 330
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 331
	
	// initialization
	nCase = 331;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(30);
	v[2] = -1/sqrt(30);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3178801206440774;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2898184546568044;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2713041974947202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2484451263743217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.24090808251227602;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2225604254381978;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 331
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 332
	
	// initialization
	nCase = 332;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(31);
	v[2] = -1/sqrt(31);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3127109937007588;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2851056453763687;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2668924531105043;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24440509897633406;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2369906168410844;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.21894131553815735;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 332
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 333
	
	// initialization
	nCase = 333;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(2));
	v[2] = -1/(4.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.307786103336229;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2806155120773432;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2626891596633048;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.24055595922353626;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.23325824788420182;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2154932053117444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 333
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 334
	
	// initialization
	nCase = 334;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(33);
	v[2] = -1/sqrt(33);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.3030868028990033;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.27633105418823306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2586784026165135;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2368831334783092;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.22969684412234553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.2122030395019047;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 334
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 335
	
	// initialization
	nCase = 335;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(34);
	v[2] = -1/sqrt(34);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2985963798005987;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2722370344662763;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2548459181168348;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.23337355970597998;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.22629373978189912;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20905911696546703;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 335
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 336
	
	// initialization
	nCase = 336;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(35);
	v[2] = -1/sqrt(35);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2942998050104104;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2683197506062893;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.25117887919327386;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2300154916878787;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.22303754498752945;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20605091528461378;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 336
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 337
	
	// initialization
	nCase = 337;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.16666666666666666;
	v[2] = -0.16666666666666666;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(3*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.29018352109870804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2645668419946999;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.24766571485615807;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22679833336239613;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2199179851288157;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20316894236741256;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 337
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 338
	
	// initialization
	nCase = 338;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(37);
	v[2] = -1/sqrt(37);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.28623526200798227;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.26096712539103084;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.24429595627565862;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22371249796392453;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21692576427247157;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.20040461026261874;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 338
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 339
	
	// initialization
	nCase = 339;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(38);
	v[2] = -1/sqrt(38);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2824438990881662;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25751045455474875;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.24106010537599304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.22074928768881802;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.21405244847886232;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19775012736285394;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 339
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 340
	
	// initialization
	nCase = 340;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(39);
	v[2] = -1/sqrt(39);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.278799308989174;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.25418759979992095;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2379495220844024;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.21790079044434718;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.2112903656832712;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19519840591095552;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 340
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 341
	
	// initialization
	nCase = 341;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(10));
	v[2] = -1/(2.*sqrt(10));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(10);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(10));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2752922598358332;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2509901442183411;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23495632718377818;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.21515979088659787;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20863251943262873;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1927429823065517;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 341
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 342
	
	// initialization
	nCase = 342;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(41);
	v[2] = -1/sqrt(41);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.27191431276840156;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24791039391180436;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.23207331827950223;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.21251969346762936;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20607251426717804;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.19037794817068932;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 342
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 343
	
	// initialization
	nCase = 343;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(42);
	v[2] = -1/sqrt(42);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2686577364559562;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24494130005204193;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22929389683836854;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.209974455621822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20360449093373864;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18809789049328166;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 343
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 344
	
	// initialization
	nCase = 344;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(43);
	v[2] = -1/sqrt(43);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2655154326098052;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.24207639096962308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2266120046157998;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20751852954949734;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.20122306993542846;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1858978394821066;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 344
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 345
	
	// initialization
	nCase = 345;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(11));
	v[2] = -1/(2.*sqrt(11));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(11);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2624808708623439;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23930971278154411;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2240220680762797;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.2051468113202758;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19892330217906554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.18377322296892218;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 345
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 346
	
	// initialization
	nCase = 346;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(5));
	v[2] = -1/(3.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/(3*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/5)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2595480316507822;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23663577731703797;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.22151894964577956;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20285459623279045;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.19670062568912788;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1817198264201086;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 346
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 347
	
	// initialization
	nCase = 347;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(46);
	v[2] = -1/sqrt(46);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2567113559682563;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23404951630453283;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2190979048253575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.20063753954173294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.194550827526217;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1797337577554372;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 347
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 348
	
	// initialization
	nCase = 348;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(47);
	v[2] = -1/sqrt(47);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25396570102735294;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.23154624094909027;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21675454435088085;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19849162180585542;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1924700101862928;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1778114163063532;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 348
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 349
	
	// initialization
	nCase = 349;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(3));
	v[2] = -1/(4.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.25130630103109886;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2291216061664338;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21448480071186596;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.19641311822780688;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1904545618706428;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17594946535019584;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 349
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 350
	
	// initialization
	nCase = 350;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.14285714285714285;
	v[2] = -0.14285714285714285;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2)/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24872873237032117;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2267715788525999;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21228489844813547;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1943985714534824;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18850113011041345;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17414480774349647;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 350
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 351
	
	// initialization
	nCase = 351;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(5.*sqrt(2));
	v[2] = -1/(5.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(5*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24622888266898324;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2244924096618746;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.21015132773064388;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.192444767378829;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18660659830736148;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17239456424939553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 351
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 352
	
	// initialization
	nCase = 352;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(51);
	v[2] = -1/sqrt(51);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(51);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.24380292318458557;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2222806078436181;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20808082080578286;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1905487135788652;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18476806481726918;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.17069605421407338;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 352
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 353
	
	// initialization
	nCase = 353;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(13));
	v[2] = -1/(2.*sqrt(13));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(13);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(26);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(13));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2414472841421719;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.22013291875372384;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2060703309434588;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1887076200295141;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.18298282425661663;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.16904677829711404;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 353
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 354
	
	// initialization
	nCase = 354;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(53);
	v[2] = -1/sqrt(53);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(53);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.23915863264040904;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2180463037110941;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2041170135803825;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.18691888183968905;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1812483507585212;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.16744440300267893;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 354
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 355
	
	// initialization
	nCase = 355;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(6));
	v[2] = -1/(3.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/3)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(3*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.23693385281866378;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.21601792191551838;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.2022182093930742;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.18518006375050308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1795622829421925;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.16588674679369458;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 355
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 356
	
	// initialization
	nCase = 356;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(55);
	v[2] = -1/sqrt(55);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(55);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.23477002801661795;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.21404511418219319;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.20037142907145877;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.18348888619178402;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.17792241039244905;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1643717676010943;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 356
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 357
	
	// initialization
	nCase = 357;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(14));
	v[2] = -1/(2.*sqrt(14));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(14);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(14));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.23266442469408274;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.21212538828105496;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.19857433959475554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1818432127143061;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1763266614732161;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1628975515654454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 357
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 358
	
	// initialization
	nCase = 358;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(57);
	v[2] = -1/sqrt(57);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(57);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2306144779093834;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.21025640569709692;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.19682475183757567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1802410386401509;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1747730923221993;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1614623028697926;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 358
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 359
	
	// initialization
	nCase = 359;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(58);
	v[2] = -1/sqrt(58);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(29);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(58);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.22861777818087234;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.20843596965171532;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.19512060935649184;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.17868048079407864;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.17325987689377378;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.16006433454088498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 359
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 360
	
	// initialization
	nCase = 360;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(59);
	v[2] = -1/sqrt(59);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(59);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2266720595785304;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2066620142455541;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.19345997822646285;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.17715976819629728;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.17178529793410524;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.15870206011163526;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 360
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 361
	
	// initialization
	nCase = 361;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(15));
	v[2] = -1/(2.*sqrt(15));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(15);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(30);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(15));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.22477518891182494;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.20493259460083232;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.191841037812891;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.17567723361203164;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1703477387870787;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.15737398605111266;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 361
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 362
	
	// initialization
	nCase = 362;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(61);
	v[2] = -1/sqrt(61);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(61);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2229251558965216;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.2032458778962051;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.19026207237919657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1742313058662122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.16894567594213547;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1560787048799392;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 362
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 363
	
	// initialization
	nCase = 363;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(62);
	v[2] = -1/sqrt(62);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(31);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(62);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2211200641973903;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.20160013520019732;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.18872146344195026;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.17282050284273512;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1675776722459136;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1548148888989347;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 363
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 364
	
	// initialization
	nCase = 364;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(7));
	v[2] = -1/(3.*sqrt(7));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/(3*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/7)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(7));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21935812325607026;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19999373402048443;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1872176827961226;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.17144342509737817;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.16624237070892778;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.15358128446748226;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 364
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 365
	
	// initialization
	nCase = 365;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.125;
	v[2] = -0.125;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/4;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(4*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/8;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21763764082403103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19842513149602492;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.18574928614211855;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1700987500217971;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.16493848884661177;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.15237670677555942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 365
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 366
	
	// initialization
	nCase = 366;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(65);
	v[2] = -1/sqrt(65);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(65);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21595701612984136;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19689286816750592;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1843149072541809;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1687852265032778;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1636648135010769;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.15120003505987326;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 366
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 367
	
	// initialization
	nCase = 367;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(66);
	v[2] = -1/sqrt(66);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(33);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(66);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21431473361803577;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19539556226892688;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.18291325263664063;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.16750167003123048;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.16242019609605987;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1500502082201936;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 367
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 368
	
	// initialization
	nCase = 368;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(67);
	v[2] = -1/sqrt(67);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(67);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21270935720391201;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19393190448956932;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.18154309662050375;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.16624695820692012;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.16120354828287364;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14892622079690995;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 368
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 369
	
	// initialization
	nCase = 369;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(17));
	v[2] = -1/(2.*sqrt(17));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(17);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(34);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(17));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.21113952499475722;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19250065316121986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.18020327685812554;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.16502002661774207;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1600138379398449;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14782711927515335;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 369
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 370
	
	// initialization
	nCase = 370;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(69);
	v[2] = -1/sqrt(69);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(69);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.20960394443340163;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.19110062983043913;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1788926901783327;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1638198650415764;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1588500854918159;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14675199868460662;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 370
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 371
	
	// initialization
	nCase = 371;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(70);
	v[2] = -1/sqrt(70);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(35);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(70);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2081013878247399;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18973071517999043;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17761028876840057;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.16264551395045698;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15771136051988174;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14569999946744525;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 371
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 372
	
	// initialization
	nCase = 372;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(71);
	v[2] = -1/sqrt(71);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(71);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.20663068821003344;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18838984526734867;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17635507665285438;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1614960612860561;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15659677863469623;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14467030458977356;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 372
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 373
	
	// initialization
	nCase = 373;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(6.*sqrt(2));
	v[2] = -1/(6.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(3*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/6;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(6*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.20519073555748601;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18707700805156213;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17512610644220322;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1603706394823575;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15550549858946788;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14366213687449625;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 373
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 374
	
	// initialization
	nCase = 374;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(73);
	v[2] = -1/sqrt(73);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(73);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2037804732408321;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18579124018270254;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17392247632748697;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15926842271343178;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15443671961122904;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14267475653583903;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 374
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 375
	
	// initialization
	nCase = 375;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(74);
	v[2] = -1/sqrt(74);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(37);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(74);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.20239889478055245;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18453162403075793;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17274332729897052;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15818862434647274;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15338967893113914;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1417074588977449;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 375
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 376
	
	// initialization
	nCase = 376;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(5.*sqrt(3));
	v[2] = -1/(5.*sqrt(3));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/(5*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/3)/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(5*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.2010450408248791;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.18329728493314704;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17158784056949278;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1571304945822455;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15236364949651426;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.14075957228015668;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 376
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 377
	
	// initialization
	nCase = 377;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(19));
	v[2] = -1/(2.*sqrt(19));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(19);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(38);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(19));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.19971799635001122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1820873886420931;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.17045523518490838;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15609331826686326;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1513579378489876;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13983045603877745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 377
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 378
	
	// initialization
	nCase = 378;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(77);
	v[2] = -1/sqrt(77);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(77);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.19841688806097768;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1809011389549317;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16934476580577654;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15507641286038282;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.15037188215473155;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13891949874531176;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 378
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 379
	
	// initialization
	nCase = 379;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(78);
	v[2] = -1/sqrt(78);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(39);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(78);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1971408819763685;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17973777551205639;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16825572064597907;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15407912654910672;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14940485037402643;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1380261164964409;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 379
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 380
	
	// initialization
	nCase = 380;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(79);
	v[2] = -1/sqrt(79);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(79);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1958891811817608;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17859657174866636;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16718741955531485;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15310083648973136;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14845623855867587;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1371497513409075;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 380
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 381
	
	// initialization
	nCase = 381;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(5));
	v[2] = -1/(4.*sqrt(5));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(10));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1946610237380867;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1774768329877785;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1661392122343347;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15214094717459287;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14752546926684593;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13628986981508145;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 381
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 382
	
	// initialization
	nCase = 382;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.1111111111111111;
	v[2] = -0.1111111111111111;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2)/9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/9;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.19345568073247202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17637789466313325;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16511047657077205;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15119888890826408;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14661199008587714;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13544596157827504;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 382
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 383
	
	// initialization
	nCase = 383;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(82);
	v[2] = -1/sqrt(82);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(41);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(82);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.19227245446021654;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17529912066166503;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16410061708789997;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.15027411638664712;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14571527225448314;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13461753813987548;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 383
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 384
	
	// initialization
	nCase = 384;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(83);
	v[2] = -1/sqrt(83);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(83);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1911106767276143;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1742399017761454;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16310906349602308;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1493661073705111;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1448348093765291;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13380413167108252;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 384
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 385
	
	// initialization
	nCase = 385;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(21));
	v[2] = -1/(2.*sqrt(21));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(21);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(42);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(21));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18996970726623497;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1731996542594477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16213526933909908;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14847436144614412;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14397011621928155;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1330052938946841;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 385
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 386
	
	// initialization
	nCase = 386;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(85);
	v[2] = -1/sqrt(85);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(85);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18884893225011723;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17217781847263894;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16117871072919338;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14759839886643839;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14312072758965122;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.13222059504688494;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 386
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 387
	
	// initialization
	nCase = 387;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(86);
	v[2] = -1/sqrt(86);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(43);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(86);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18774776290807302;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1711738576197864;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.16023888516210924;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1467377594663105;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14228619728251635;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1314496229057259;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 387
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 388
	
	// initialization
	nCase = 388;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(87);
	v[2] = -1/sqrt(87);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(87);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18666563422397556;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.17018725656298084;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15931531040811006;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14589200164688745;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14146609709572505;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.1306919818811043;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 388
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 389
	
	// initialization
	nCase = 389;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(22));
	v[2] = -1/(2.*sqrt(22));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(22);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(2*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(22));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18560200371851382;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16921752071163482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15840752347217174;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1450607014233642;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.14066001590683797;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12994729216183226;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 389
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 390
	
	// initialization
	nCase = 390;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(89);
	v[2] = -1/sqrt(89);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(89);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18455635030644682;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16826417498061572;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15751507961867234;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14424345153186938;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1398675588070889;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.129215188915555;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 390
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 391
	
	// initialization
	nCase = 391;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(10));
	v[2] = -1/(3.*sqrt(10));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/5)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(3*sqrt(5));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(10));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18352817322388879;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1673267628122274;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15663755145585212;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14343986059106523;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13908834628841915;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12849532153770113;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 391
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 392
	
	// initialization
	nCase = 392;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(91);
	v[2] = -1/sqrt(91);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(91);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1825169910206103;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16640484525746851;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1557745280757629;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14264955231456158;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1383220134797843;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12778735294595275;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 392
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 393
	
	// initialization
	nCase = 393;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(2.*sqrt(23));
	v[2] = -1/(2.*sqrt(23));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/sqrt(23);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(46);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(2*sqrt(23));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1815223406127477;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1654980001123666;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15492561424577508;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14187216477054343;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13756820942924247;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12709095891700986;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 393
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 394
	
	// initialization
	nCase = 394;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(93);
	v[2] = -1/sqrt(93);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(93);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.18054377639168845;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.1646058211055284;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15409042964802921;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14110734968530358;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13682659642861553;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12640582746268594;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 394
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 395
	
	// initialization
	nCase = 395;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(94);
	v[2] = -1/sqrt(94);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2/47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/sqrt(47);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(94);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.1795808693852366;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16372791713335597;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1532686081635081;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.14035477178763595;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13609684937777153;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12573165824260657;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 395
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 396
	
	// initialization
	nCase = 396;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(95);
	v[2] = -1/sqrt(95);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(95);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.17863320646747202;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16286391153965732;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15245979719766764;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1396141081912864;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13537865518580985;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12506816201100096;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 396
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 397
	
	// initialization
	nCase = 397;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(4.*sqrt(6));
	v[2] = -1/(4.*sqrt(6));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/(2*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(4*sqrt(3));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(4*sqrt(6));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.17770038961399784;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16201344143663882;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15166365704480567;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.13888504781287733;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1346717122066444;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12441506009527095;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 397
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 398
	
	// initialization
	nCase = 398;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/sqrt(97);
	v[2] = -1/sqrt(97);
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/sqrt(97);
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.17678203519952632;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16117615706449842;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.1508798602885659;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.13816729082292306;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13397572970667318;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12377208390420338;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 398
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 399
	
	// initialization
	nCase = 399;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(7.*sqrt(2));
	v[2] = -1/(7.*sqrt(2));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = sqrt(2)/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/7;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(7*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.175877773334988;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.16035172118705324;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.15010809123617416;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.13746054812773498;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13329042736240101;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12313897446385393;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 399
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 400
	
	// initialization
	nCase = 400;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  1/(3.*sqrt(11));
	v[2] = -1/(3.*sqrt(11));
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 2/(3*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = sqrt(2/11)/3;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/(3*sqrt(11));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.17498724724156262;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.15953980852102942;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.14934804538418645;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.13676454088018386;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.1326155347860437;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12251548197928146;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 400
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// test case 401
	
	// initialization
	nCase = 401;
	k = 0;
	maxerror = 0.;
	
	// data
	v[1] =  0.1;
	v[2] = -0.1;
	
	// sweep through p values
	
	// p = 1
	k++;
	normCpp   = norm1( v );
	normMM    = 1/5;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2
	k++;
	normCpp   = norm2( v );
	normMM    = 1/(5*sqrt(2));
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = infinity
	k++;
	normCpp   = norminf( v );
	normMM    = 1/10;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.25
	k++;
	normCpp   = normp( v, 1.25 );
	normMM    = 0.17411011265922482;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.5
	k++;
	normCpp   = normp( v, 1.5 );
	normMM    = 0.15874010519681994;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 1.75
	k++;
	normCpp   = normp( v, 1.75 );
	normMM    = 0.14859942891369485;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.25
	k++;
	normCpp   = normp( v, 2.25 );
	normMM    = 0.1360790000174377;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 2.5
	k++;
	normCpp   = normp( v, 2.5 );
	normMM    = 0.13195079107728944;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	// p = 3.5
	k++;
	normCpp   = normp( v, 3.5 );
	normMM    = 0.12190136542044755;
	error     = normMM - normCpp;
	cumerror += error * error;
	if ( maxerror < error )
		maxerror = error;
	
	error /= k;
	
	// output results for case 401
	cout << endl << "Results for test case " << nCase << endl;
	cout << scientific << maxerror << " = maximum error\n";
	cout << scientific <<    error << " = average error\n";
	
	// global case
	if ( superMaxerror < maxerror )
		superMaxerror = maxerror;
	
	superError += error;
	superK++;
	
	
	// cumulative results
	superError /= superK;
	
	// output results for all cases
	cout << endl << "Results for all cases" << endl;
	cout << scientific << superMaxError << " = maximum error\n";
	cout << scientific << superError    << " = average error\n";
	
	return EXIT_SUCCESS;
}
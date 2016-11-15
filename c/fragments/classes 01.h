/* 
 * File:   classes.h
 * Author: rdantopa1
 *
 * Created on May 23, 2011, 8:05 AM
 */

#ifndef CLASSES_H
#define	CLASSES_H

#include "header.h"
#pragma once;

//const int nDim = 2;

class Vertex
{
public:
    int index;
    
    std::vector<double> loc;
    std::vector<double> vel;
    std::vector<double> acc;
        
    std::vector<double> stencil;
    
    std::vector<int> clist;               // which cells touch me?
    
};

class Cell
{
public:
    int index;                             // key field
    
    std::vector<int> vlist;                // vertex indices list
    
    double area, perimeter;
    double mass, density;

};

class Mesh
{
public:
    int index;                             // key field
    
    std::vector<int> clist;                // cell membership list
    
    double area, perimeter;

};

class Link
{
public:
    int index;                             // key field
    
    double length;                         // Euclidean length
    
    int alpha, omega;                      // start, end vertex indices
    int CCW, CW;                           // cell indices
    
    std::vector<double> midpoint;
    std::vector<double> xdelta;
    std::vector<double> ydelta;

};

class Config
{
public:
    std::vector<Vertex> V;
    std::vector<Cell>   C;
    std::vector<Mesh>   M;
    std::vector<Link>   L;
};

#endif	/* CLASSES_H */

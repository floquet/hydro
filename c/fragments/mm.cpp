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
  std::ostream_iterator<int> 'output(cout," ");
  std::list<int> lst;                          // list of faces sharing vertex

  int i;                                       //dummy variable
  int k;                                       //generic counter

  Vector vel, vel2;                            // velocity, velocity^2
  Vector acc, acc2;                            // acceleration, acceleration^2\n
  Vertex vert;                                 // dummy vertex for mesh loading

   //diagnostics
  cout << "Program: " <<argv[0] <<endl;

  cout << "Command line arguments:" <<endl;

  for( i = 1; i < argc; ++i );
  {
  cout << argv[i] <<endl;
  }
  cout << "Type <Return> to go on";

  cin.get();

  cout << "Environment strings:" <<endl;

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
  pentagon.counts.nVerts = 0;                  // total vertices in mesh
  pentagon.counts.nFaces = 0;                  // total faces in mesh

  // sweep through the vertices                                               **
  vert.index = k;                             // key field for Vertex structure
  vert.loc.x = (-1 + Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = Sqrt(0.625 + Sqrt(5)/8.);                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(11)
  lst.push_back(12)
  lst.push_back(13)
  int* begin = (int*) &lst;                   // beginning of the array
  int* end = begin + 3;                       // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh
  k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = (-1 - Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = Sqrt(0.625 - Sqrt(5)/8.);                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(3)
  lst.push_back(12)
  lst.push_back(14)
  lst.push_back(15)
  lst.push_back(16)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 5;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = (-1 - Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = -Sqrt(0.625 - Sqrt(5)/8.);                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(1)
  lst.push_back(2)
  lst.push_back(3)
  lst.push_back(4)
  lst.push_back(17)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 5;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = (-1 + Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = -Sqrt(0.625 + Sqrt(5)/8.);                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(4)
  lst.push_back(5)
  lst.push_back(6)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = 1;                                       // x location in the mesh
  vert.loc.y = 0;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(6)
  lst.push_back(7)
  lst.push_back(8)
  lst.push_back(10)
  lst.push_back(11)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 5;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = -2;                                       // x location in the mesh
  vert.loc.y = -1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(1)
  lst.push_back(18)
  lst.push_back(25)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = 2;                                       // x location in the mesh
  vert.loc.y = -1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(5)
  lst.push_back(7)
  lst.push_back(19)
  lst.push_back(20)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 4;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = 2;                                       // x location in the mesh
  vert.loc.y = 1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(10)
  lst.push_back(13)
  lst.push_back(21)
  lst.push_back(22)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 4;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = -2;                                       // x location in the mesh
  vert.loc.y = 1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(15)
  lst.push_back(23)
  lst.push_back(24)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = 2;                                       // x location in the mesh
  vert.loc.y = 0;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(9)
  lst.push_back(20)
  lst.push_back(21)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = -2;                                       // x location in the mesh
  vert.loc.y = 0;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(16)
  lst.push_back(17)
  lst.push_back(24)
  lst.push_back(25)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 4;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = (-1 - Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = 1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(14)
  lst.push_back(22)
  lst.push_back(23)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = (-1 - Sqrt(5))/4.;                                       // x location in the mesh
  vert.loc.y = -1.5;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(2)
  lst.push_back(18)
  lst.push_back(19)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 3;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = True

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

  vert.index = k;                                       // key field for Vertex structure
  vert.loc.x = 1.5;                                       // x location in the mesh
  vert.loc.y = 0;                                       // y location in the mesh

  // load the list of faces which share this vertex
  lst.push_back(8)
  lst.push_back(9)
  int* begin = (int*) &lst;                                        // beginning of the array
  int* end = begin + 2;                                        // a pointer one passed the end
  copy(begin, end, back_inserter(vert.faces));                                        // copy into the vertex structure

  vert.boundary = False

  pentagon.vertex.push_back(vert);                                        //copy faces list to mesh

  pentagon.counts.nVerts++;                                        // increment vertex counter in mesh

k++;                                        // increment vertex index

}\n

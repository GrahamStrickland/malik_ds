#ifndef WEIGHTED_GRAPH_TYPE_H
#define WEIGHTED_GRAPH_TYPE_H

//****************************************************************
// Author: D.S. Malik
//
// class weightedGraphType
// This class specifies the operations to find the weight of the
// shortest path from a given vertex to every other vertex in a
// graph.
//****************************************************************

#include "graphType.h"

class weightedGraphType : public graphType {
public:
  void createWeightedGraph();
  // Function to create the graph and the weight matrix.
  // Postcondition: The graph using adjacency lists and
  //   its weight matrix is created.

  void shortestPath(int vertex);
  // Function to determine the weight of the shortest path
  // from vertex, that is, source, to every other vertex
  // in the graph.
  // Postcondition: The weight of the shortest path from vertex
  //   to every other vertex in the graph is determined.

  void printShortestDistance(int vertex);
  // Function to print the shortest weight from the vertex
  // specified by the parameter vertex to every other vertex in
  // the graph.
  // Postcondition: The weight of the shortest path from vertex
  //   to every other vertex in the graph is printed.

  weightedGraphType(int size = 0);
  // Constructor.
  // Postcondition: gSize = 0; maxSize = size;
  //   graph is an array of pointers to linked lists.
  //   weights is a two-dimensional array to store the weights
  //       of the edges.
  //   smallestWeight is an array to store the smallest weight
  //       from source to vertices.

  ~weightedGraphType();
  // Destructor.
  // The storage occupied by the vertices and the arrays
  // weights and smallestWeight is deallocated.

protected:
  double **weights;       // Pointer to create weight matrix.
  double *smallestWeight; // Pointer to create the array to store
                          // the smallest weight from source to vertices.
};
#endif // WEIGHTED_GRAPH_TYPE_H
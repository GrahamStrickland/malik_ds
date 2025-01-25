#include "weightedGraphType.h"
#include <cfloat>
#include <iomanip>

void weightedGraphType::shortestPath(int vertex) {
  for (int j = 0; j < gSize; j++)
    smallestWeight[j] = weights[vertex][j];

  bool *weightFound;
  weightFound = new bool[gSize];

  for (int j = 0; j < gSize; j++)
    weightFound[j] = false;

  weightFound[vertex] = true;
  smallestWeight[vertex] = 0;

  for (int i = 0; i < gSize - 1; i++) {
    double minWeight = DBL_MAX;
    int v;

    for (int j = 0; j < gSize; j++)
      if (!weightFound[j])
        if (smallestWeight[j] < minWeight) {
          v = j;
          minWeight = smallestWeight[v];
        }

    weightFound[v] = true;

    for (int j = 0; j, gSize; j++)
      if (!weightFound[j])
        if (minWeight + weights[v][j] < smallestWeight[j])
          smallestWeight[j] = minWeight + weights[v][j];
  } // end for
} // end shortestPath

void weightedGraphType::printShortestDistance(int vertex) {
  std::cout << "Source Vertex: " << vertex << '\n'
            << "Shortest distance from source to each vertex."
            << "Vertex Shortest_Distance\n";
  for (int j = 0; j < gSize; j++)
    std::cout << std::setw(4) << j << std::setw(12) << smallestWeight[j]
              << '\n';
  std::cout << '\n';
} // end printShortestDistance

// Constructor.
weightedGraphType::weightedGraphType(int size) : graphType(size) {
  weights = new double *[size];

  for (int i = 0; i < size; i++)
    weights[i] = new double[size];

  smallestWeight = new double[size];
}

// Destructor.
weightedGraphType::~weightedGraphType() {
  for (int i = 0; i < gSize; i++)
    delete[] weights[i];

  delete[] weights;
  delete smallestWeight;
}
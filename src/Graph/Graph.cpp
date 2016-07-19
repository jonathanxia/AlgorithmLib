#include "Graph.h"

namespace AlgLib
{
    Graph::Graph(int numVertices, dbType storageType = dbType::ADJACENCY_MATRIX)
    {
        if(storageType == dbType::ADJACENCY_MATRIX)
        {
            mGraph = new adjMatrix(numVertices);
        }
    }

    Graph::~Graph()
    {
        delete mGraph;
    }
}

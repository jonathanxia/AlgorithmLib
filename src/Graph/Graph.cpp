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
        mGraph = nullptr;
    }

    void Graph::addVertex()
    {
        mGraph->addVertex();
    }

    void Graph::addEdge(int nodeS, int nodeE, double weight)
    {
        mGraph->addEdge(nodeS, nodeE, weight);
    }

    void Graph::deleteEdge(int nodeS, int nodeE)
    {
        mGraph->deleteEdge(nodeS, nodeE);
    }

    void Graph::deleteVertex(int node)
    {
        mGraph->deleteVertex(node);
    }

    int Graph::numVertex() const
    {
        return mGraph->numVertex();
    }

    int Graph::inDegree(int node) const
    {
        return mGraph->inDegree(node);
    }

    int Graph::outDegree(int node) const
    {
        return mGraph->outDegree(node);
    }

    double Graph::inWeight(int node) const
    {
        return mGraph->inWeight(node);
    }

    double Graph::outWeight(int node) const
    {
        return mGraph->outWeight(node);
    }

    double Graph::getWeight(int nodeS, int nodeE) const
    {
        return mGraph->getWeight(nodeS, nodeE);
    }

    bool Graph::inGraph(int node) const
    {
        return mGraph->inGraph(node);
    }

    std::vector<std::tuple<int, double> > Graph::outAdj(int node) const
    {
        return mGraph->outAdj(node);
    }

    std::vector< std::tuple<int, double> > Graph::inAdj(int node) const
    {
        return mGraph->inAdj(node);
    }

}

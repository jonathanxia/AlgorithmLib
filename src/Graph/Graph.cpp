#include "Graph.h"
#include "graphDB.h"
#include "adjMatrix.h"
#include "adjList.h"
#include "Matrix.h"
#include "searching.h"
#include <tuple>
#include <utility>

namespace AlgLib
{
    Graph::Graph(int numVertices, dbType storageType)
    {
        switch(storageType)
        {
        case dbType::ADJACENCY_MATRIX:
            mGraph = new adjMatrix(numVertices);
            break;
        case dbType::ADJACENCY_LIST:
            mGraph = new adjList(numVertices);
            break;
        }
    }

    Graph::Graph(const std::vector<std::tuple<int, int, double>>& edgepairs, dbType storageType)
    {
        int numVertices = 0;
        for(auto it = edgepairs.begin(); it != edgepairs.end(); ++it)
        {
            if(std::get<0>(*it) > numVertices)
            {
                numVertices = std::get<0>(*it);
            }
            if(std::get<1>(*it) > numVertices)
            {
                numVertices = std::get<1>(*it);
            }
        }
        if(storageType == dbType::ADJACENCY_LIST)
        {
            mGraph = new adjList(numVertices);
        }
        else if(storageType == dbType::ADJACENCY_MATRIX)
        {
            mGraph = new adjMatrix(numVertices);
        }
        for(auto it = edgepairs.begin(); it != edgepairs.end(); ++it)
        {
            mGraph->addEdge(std::get<0>(*it), std::get<1>(*it), std::get<2>(*it));
        }
    }

    Graph::Graph(const Matrix<double>& adjMat, dbType storageType)
    {
        if(adjMat.numRows() != adjMat.numColumns())
        {
            throw std::invalid_argument("adjacency matrix is not a square matrix");
        }
        if(storageType == dbType::ADJACENCY_MATRIX)
        {
            mGraph = new adjMatrix(adjMat);
        }
        else if (storageType == dbType::ADJACENCY_LIST)
        {
            mGraph = new adjList(adjMat.numRows());
            for(int i = 0; i < adjMat.numRows(); i++)
            {
                for(int j = 0; j < adjMat.numColumns(); j++)
                {
                    if(adjMat.getValue(i, j) > 0)
                    {
                        mGraph->addEdge(i, j, adjMat.getValue(i, j));
                    }
                }
            }
        }
    }

    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    Graph::Graph(const std::vector<std::vector<std::tuple<int, double>>>& inAdjList, dbType storageType)
    {
        if(storageType == dbType::ADJACENCY_LIST)
        {
            mGraph = new adjList(inAdjList.size());
        }
        else if (storageType == dbType::ADJACENCY_MATRIX)
        {
            mGraph = new adjMatrix(inAdjList.size());
        }
        for(auto it = inAdjList.begin(); it != inAdjList.end(); ++it)
        {
            for(auto jt = (*it).begin(); jt != (*it).end(); ++jt)
            {
                mGraph->addEdge(std::get<0>(*jt), std::get<1>(*jt), std::get<2>(*jt));
            }
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

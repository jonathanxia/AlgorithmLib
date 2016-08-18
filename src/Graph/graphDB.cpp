#include "graphDB.h"
#include <stdexcept>
namespace AlgLib
{
    graphDB::graphDB(int numVertices) :
        isInGraph(numVertices, true)
    {
        //ctor
    }

    graphDB::~graphDB()
    {
        //dtor
    }

    bool graphDB::inGraph(int node) const
    {
        if(node < 0 || node >= (int) isInGraph.size())
            throw std::out_of_range("Node value is out of range");
        return isInGraph[node];
    }

    int graphDB::numVertex() const
    {
        int numVertices = 0;
        for(auto it = isInGraph.begin(); it != isInGraph.end(); it++)
        {
            if(*it)
                numVertices++;
        }
        return numVertices;
    }

    int graphDB::highestNode() const
    {
        return isInGraph.size() - 1;
    }

}

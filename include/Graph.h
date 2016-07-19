#ifndef GRAPH_H
#define GRAPH_H
#include "graphDB.h"

namespace AlgLib
{
    enum class dbType
    {
        ADJACENCY_MATRIX,
        ADJACENCY_LIST
    };
    class Graph
    {
        public:
            Graph(int numVertices, dbType storageType = dbType::ADJACENCY_MATRIX);
            /** Default destructor */
            virtual ~Graph();

        protected:

        private:
            graphDB * mGraph;
    };
}

#endif // GRAPH_H

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

            virtual void addVertex();
            virtual void addEdge(int nodeS, int nodeE, double weight = 1);
            virtual void deleteEdge(int nodeS, int nodeE);
            virtual void deleteVertex(int node);
            virtual int numVertex() const;
            virtual int inDegree(int node) const;
            virtual int outDegree(int node) const;
            virtual double inWeight(int node) const;
            virtual double outWeight(int node) const;
            virtual double getWeight(int nodeS, int nodeE) const;
            virtual bool inGraph(int node) const;
            virtual std::vector< std::tuple <int, double> > outAdj(int node) const;
            virtual std::vector< std::tuple <int, double> > inAdj(int node) const;

        protected:

        private:
            graphDB * mGraph;
    };
}

#endif // GRAPH_H

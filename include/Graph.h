#ifndef GRAPH_H
#define GRAPH_H
#include "graphDB.h"
#include "Matrix.h"
#include <vector>
#include <tuple>
#include <initializer_list>
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

            /**
            \brief A constructor

            \param numVertices the number of vertices for the graph to have
            \param storageType an optional parameter about how the graph should be stored.
            \see dbType for more information on the types of graph databases available
             */
            Graph(int numVertices, dbType storageType = dbType::ADJACENCY_MATRIX);

            /** \brief A constructor that takes in edge pairs
             *
             * \param edgepairs a vector containing tuples of the form (node1, node2, edgeweight) which will denote an edge from
                        node1 to node 2 with weight edgeweight
             * \param storageType an optional parameter about how the graph should be stored.
             * \see dbType for more information on the types of graph databases available
             *
             */
            Graph(const std::vector< std::tuple<int, int, double> >& edgepairs, dbType storageType = dbType::ADJACENCY_LIST);

            /** \brief Constructor that takes in an adjacency matrix
             *
             * \param adjMat the adjacency matrix to take in. Edge i->j with weight adjMat[i][j]
             * \param storageType an optional parameter about how the graph should be stored
             * \see dbType for more information on the types of graph databases available
             *
             */
            Graph(const Matrix<double>& adjMat, dbType storageType = dbType::ADJACENCY_MATRIX);

            /** \brief Takes in an adjacency list to construct a graph
             *
             * \param inAdjList the adjacency list to take in.
             * \param storageType optional parameter about how the graph should be stored
             * \see dbType for more information on the types of graph databases available
             *
             */
            Graph(const std::vector< std::vector< std::tuple<int, double> > >& inAdjList, dbType storageType = dbType::ADJACENCY_LIST);

            /** Default destructor */
            virtual ~Graph();

            /** \brief Adds a vertex to the graph.
             *
             * The node number that is added is the graph's highest node number + 1, regardless of whether other nodes
             * deleted.
             *
             */
            virtual void addVertex();

            /** \brief Adds the edge nodeS -> nodeE with the indicated weight
             *
             * \param nodeS the first node (the start)
             * \param nodeE the second node (the end)
             * \param weight the weight of the edge nodeS->nodeE
             *
             * This will create a directed edge from nodeS to nodeE with weight
             *
             */
            virtual void addEdge(int nodeS, int nodeE, double weight = 1);

            /** \brief deletes the edge nodeS->nodeE (really just sets the weight to 0)
             *
             * \param nodeS the first node of the edge
             * \param nodeE the second node of the edge
             *
             * The edge is set to 0. It is no longer considered and adjacent edge of nodeS and nodeE
             *
             */
            virtual void deleteEdge(int nodeS, int nodeE);

            /** \brief Deletes the vertex numbered "node"
             *
             * \param node The node to be removed
             *
             * The removal of this vertex will not affect the numbering of the nodes. It will simply be recorded that the node is not in the graph anymore.
             *
             */
            virtual void deleteVertex(int node);

            /** \brief Gives the number of vertices in the graph
             *
             * \return The number of vertices in the graph. Removed nodes are not counted
             * \see highestNode() for how to get the highest numbered node
             *
             */
            virtual int numVertex() const;

            /** \brief Returns the highest numbered node
            * \return The highest numbered node in the graph.
            * \see numVertex() to find the number of ways to get the number of nodes
            */

            virtual int highestNode() const;

            /** \brief Counts the number of edges going into a node
             *
             * \param node The node
             *
             * \return The number of non zero directed edges going into that node
             *
             */
            virtual int inDegree(int node) const;

            /** \brief Counts the number of edges going out of a node
             *
             * \param node The node
             *
             * \return The number of non zero directed edges going out of that node
             *
             */
            virtual int outDegree(int node) const;

            /** \brief Gives the total weight going into a node
             *
             * \param node The node
             *
             * \return The total weight going into `node`
             *
             */
            virtual double inWeight(int node) const;
            /** \brief Gives the total weight going out of a node
             *
             * \param node The node
             *
             * \return The total weight going out of `node`
             *
             */
            virtual double outWeight(int node) const;

            /** \brief Returns the weight of edge nodeS->nodeE
            * \param nodeS the first node
            * \param nodeE the second node
            * \return the weight of edge nodeS->nodeE
            */
            virtual double getWeight(int nodeS, int nodeE) const;

            /** \brief A bool value of whether the number node is in the graph
             *
             * \param node The number to see if it is a node in the graph
             *
             * \return True if node is in the graph, false otherwise.
             *
             */

            virtual bool inGraph(int node) const;

            /** \brief Gives the tuples with nodes x such that node->x
             *
             * \param node The source node
             *
             * \return A std::vector of std::tuple<int, double> where the int is the connected node and double is the weight of the edge
             *
             */
            virtual std::vector< std::tuple <int, double> > outAdj(int node) const;

            /** \brief Gives the tuples with nodes x such that x->node
             *
             * \param node The sink node
             *
             * \return A std::vector of std::tuple<int, double> where the int is the connected node and double is the weight of the edge
             *
             */
            virtual std::vector< std::tuple <int, double> > inAdj(int node) const;

        protected:

        private:
            graphDB * mGraph;
    };
}

#endif // GRAPH_H

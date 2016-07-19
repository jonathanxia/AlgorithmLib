#include "adjMatrix.h"
#include <vector>
#include <array>
namespace AlgLib
{
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
     adjMatrix::adjMatrix(int numVertices) :
         Matrix<double>(numVertices, numVertices),
         isInGraph(numVertices, true)
    {

    }

    adjMatrix::~adjMatrix()
    {

    }

    void adjMatrix::addVertex()
    {
        // Column should go before Row so that the 0-matrix can get something added
        Matrix<double>::addColumn();
        Matrix<double>::addRow();
    }

    void adjMatrix::addEdge(int nodeS, int nodeE, double weight)
    {
        (*this)[nodeS][nodeE] = weight;
    }

    void adjMatrix::deleteEdge(int nodeS, int nodeE)
    {
        (*this)[nodeS][nodeE] = 0;
    }

    void adjMatrix::deleteVertex(int node)
    {
        isInGraph[node] = false;
        for(int i = 0; i < this->numRows(); i++)
        {
            (*this)[i][node] = 0;
        }
        for(int j = 0; j < this->numColumns(); j++)
        {
            (*this)[node][j] = 0;
        }
    }

    int adjMatrix::numVertex() const
    {
        return this->numRows();
    }

    int adjMatrix::inDegree(int node) const
    {
        int degree = 0;
        for(int i = 0; i < (*this).numRows(); i++)
        {
            if( this->getValue(i, node) > 0 )
                degree++;
        }
        return degree;
    }

    int adjMatrix::outDegree(int node) const
    {
        int deg = 0;
        for(int i = 0; i < this->numColumns(); i++)
        {
            if( this->getValue(node, i) > 0 )
                deg++;
        }
        return deg;
    }

    double adjMatrix::inWeight(int node) const
    {
        double weight = 0;
        for(int i = 0; i < this->numRows(); i++)
        {
            weight += this->getValue(i, node);
        }
        return weight;
    }

    double adjMatrix::outWeight(int node) const
    {
        double weight = 0;
        for(int i = 0; i < this->numColumns(); i++)
        {
            weight += this->getValue(node, i);
        }
        return weight;
    }

    bool adjMatrix::inGraph(int node) const
    {
        return isInGraph[node];
    }

    std::vector< std::tuple <int, double> > adjMatrix::outAdj(int node) const
    {
        std::vector< std::tuple<int, double> > ret;
        ret.reserve(this->numColumns());
        for(int i = 0; i < this->numColumns(); i++)
        {
            if(this->getValue(node, i) > 0)
            {
                ret.push_back(std::make_tuple(i, this->getValue(node, i)));
            }
        }
        return ret;
    }
    std::vector< std::tuple <int, double> > adjMatrix::inAdj(int node) const
    {
        std::vector< std::tuple<int, double> > ret;
        ret.reserve(this->numRows());
        for(int i = 0; i < this->numRows(); i++)
        {
            if(this->getValue(i, node) > 0)
            {
                ret.push_back(std::make_tuple(i, this->getValue(i, node)));
            }
        }
        return ret;
    }

    double adjMatrix::getWeight(int nodeS, int nodeE) const
    {
        return this->getValue(nodeS, nodeE);
    }
}

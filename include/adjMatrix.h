#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "graphDB.h"
#include "Matrix.h"
#include <vector>
#include <tuple>
namespace AlgLib
{
    class adjMatrix : public graphDB, protected Matrix<double>
    {
        public:
            using Matrix<double>::Matrix;

            /**
            * \brief Constructor that takes in number of vertices
            * \param numVertices Defaults to 0. Is the number of vertices for the adjMatrix to have
            */
            adjMatrix(int numVertices = 0);

            /** \brief A copy constructor
             *
             * \param other The Matrix<double> to be copied. Note that since adjMatrix inherits from Matrix<double>
             *        this parameter can be of type adjMatrix
             *
             */
            adjMatrix(const Matrix<double>& other);

            /** Default destructor */
            virtual ~adjMatrix();


            virtual void addVertex() override;
            virtual void addEdge(int nodeS, int nodeE, double weight = 1) override;
            virtual void deleteEdge(int nodeS, int nodeE) override;
            virtual void deleteVertex(int node) override;

            virtual int inDegree(int node) const override;
            virtual int outDegree(int node) const override;
            virtual double inWeight(int node) const override;
            virtual double outWeight(int node) const override;
            virtual double getWeight(int nodeS, int nodeE) const override;
            virtual std::vector< std::tuple <int, double> > outAdj(int node) const override;
            virtual std::vector< std::tuple <int, double> > inAdj(int node) const override;


        protected:

        private:
    };
}
#endif // ADJMATRIX_H

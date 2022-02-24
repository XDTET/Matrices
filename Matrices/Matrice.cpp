#include "Matrice.h"
#include <iostream>

Matrice::Matrice(unsigned rowSize, unsigned colSize, double initial) {
    rows = rowSize;
    columns = colSize;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(colSize, initial);
    }
}

 Matrice Matrice::Matrice::operator+(Matrice & B)
{
     Matrice sum(rows, columns, 0.0);
     for ( unsigned int i = 0; i < rows; i++)
     {
         for (unsigned int j = 0; j < columns; j++)
         {
             sum(i, j) = this->m_matrix[i][j] + B(i, j);
         }
     }
     return sum;
}
 Matrice Matrice::operator-(Matrice & B) {
     Matrice diff(rows, columns, 0.0);
     unsigned i, j;
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             diff(i, j) = this->m_matrix[i][j] - B(i, j);
         }
     }

     return diff;
 }

 Matrice Matrice::Matrice::operator+(double scalar)
 {
     Matrice sum(rows, columns, 0.0);
     for (unsigned int i = 0; i < rows; i++)
     {
         for (unsigned int j = 0; j < columns; j++)
         {
             sum(i, j) = this->m_matrix[i][j] + scalar;
         }
     }
     return sum;
 }
 Matrice Matrice::Matrice::operator-(double scalar)
 {
     Matrice diff(rows, columns, 0.0);
     for (unsigned int i = 0; i < rows; i++)
     {
         for (unsigned int j = 0; j < columns; j++)
         {
             diff(i, j) = this->m_matrix[i][j] - scalar;
         }
     }
     return diff;
 }

 Matrice Matrice::Matrice::operator*(double scalar)
 {
     Matrice mul(rows, columns, 0.0);
     for (unsigned int i = 0; i < rows; i++)
     {
         for (unsigned int j = 0; j < columns; j++)
         {
             mul(i, j) = this->m_matrix[i][j] * scalar;
         }
     }
     return mul;
 }

 Matrice Matrice::Matrice::operator/(double scalar)
 {
     Matrice div(rows, columns, 0.0);
     for (unsigned int i = 0; i < rows; i++)
     {
         for (unsigned int j = 0; j < columns; j++)
         {
             div(i, j) = this->m_matrix[i][j] / scalar;
         }
     }
     return div;
 }

 void Matrice::print() const
 {
     std::cout << "Matrix: " << std::endl;
     for (unsigned i = 0; i < rows; i++) {
         for (unsigned j = 0; j < columns; j++) {
             std::cout << "[" << m_matrix[i][j] << "] ";
         }
         std::cout << std::endl;
     }
 }
 void Matrice::change(int i, int j, double val)
 {
     m_matrix[i][j] = val;
 }

 Matrice Matrice::transpose()
 {
     Matrice Transpose(columns, rows, 0.0);
     for (unsigned i = 0; i < columns; i++)
     {
         for (unsigned j = 0; j < rows; j++) {
             Transpose(i, j) = this->m_matrix[j][i];
         }
     }
     return Transpose;
 }
 double& Matrice::operator()(const unsigned& rowNo, const unsigned& colNo)
 {
     return this->m_matrix[rowNo][colNo];
 }

int Matrice::get_rows() const
{
	return this->rows;
}

int Matrice::get_columns() const
{
	return this->columns;
}

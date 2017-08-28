/*
 * qmatrix.cpp
 *
 *  Created on: 2017. aug. 17.
 *      Author: irusics
 */

#ifndef __QMATRIX_CPP
#define __QMATRIX_CPP

#include "qmatrix.h"

namespace Qlib
{


template <typename Mtype>
QMatrix<Mtype>::QMatrix(unsigned int _rows, unsigned int _cols, const Mtype& _initial)
{
	matrix.resize(_rows);

	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(_cols, _initial);
	}

	cols = _cols;
	rows = _rows;
}

template <typename Mtype>
QMatrix<Mtype>::QMatrix(const QMatrix<Mtype>& rhs)
{
	matrix = rhs.matrix;
	cols = rhs.GetCols();
	rows = rhs.GetRows();
}

template <typename Mtype>
QMatrix<Mtype>::~QMatrix()
{

}

template <typename Mtype>
QMatrix<Mtype>& QMatrix<Mtype>::operator=(const QMatrix<Mtype>& rhs)
{
	if (this == &rhs)
	{
		// The matrices are the same
		return *this;
	}

	unsigned int new_rows = rhs.GetRows();
	unsigned int new_cols = rhs.GetCols();

	matrix.resize(new_rows);

	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(new_cols);
	}

	for (unsigned int i = 0; i < new_rows; i++)
	{
		for (unsigned int j = 0; j < new_cols; j++)
		{
			matrix[i][j] = rhs.matrix(i,j);
		}
	}

	rows = new_rows;
	cols = new_cols;

	return *this;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator+(const QMatrix<Mtype>& rhs)
{
	QMatrix result(rows, cols, 0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = this->matrix[i][j] + rhs(i,j);
		}
	}

	return result;
}

template <typename Mtype>
QMatrix<Mtype>& QMatrix<Mtype>::operator+=(const QMatrix<Mtype>& rhs)
{
    unsigned int row = rhs.GetRows();
    unsigned int col = rhs.GetCols();

    for (unsigned int i = 0; i < row; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            this->matrix[i][j] += rhs(i,j);
        }
    }

    return *this;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator-(const QMatrix<Mtype>& rhs)
{
    QMatrix result(rows, cols, 0.0);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            result(i,j) = this->matrix[i][j] - rhs(i,j);
        }
    }

    return result;
}

template <typename Mtype>
QMatrix<Mtype>& QMatrix<Mtype>::operator-=(const QMatrix<Mtype>& rhs)
{
    unsigned int row = rhs.GetRows();
    unsigned int col = rhs.GetCols();

    for (unsigned int i = 0; i < row; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            this->matrix[i][j] += rhs(i,j);
        }
    }

    return *this;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator*(const QMatrix<Mtype>& rhs)
{
    unsigned int row = rhs.GetRows();
    unsigned int col = rhs.GetCols();

    QMatrix result(rows, col, 0.0);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            for (unsigned int k = 0; k < row ; k++)
            {
                result(i,j) += this->matrix[i][k] * rhs(k,j);
            }
        }
    }

    return result;
}

template <typename Mtype>
QMatrix<Mtype>& QMatrix<Mtype>::operator*=(const QMatrix<Mtype>& rhs)
{
    QMatrix result = (*this) * rhs;

    (*this) = result;

    return *this;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::Transpose(void)
{
	QMatrix result(rows,cols,0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = matrix[j][i];
		}
	}

	 return result;
}

template <typename Mtype>
void QMatrix<Mtype>::SetToIdentical(void)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			if (i != j)
			{
				this->matrix[i][j] = 0;
			}
			else
			{
				this->matrix[i][j] = 1;
			}
		}
	}
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator+(const Mtype& rhs)
{
	QMatrix<Mtype> result(cols,rows,0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = this->matrix[i][j] + rhs;
		}
	}

	return result;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator-(const Mtype& rhs)
{
	QMatrix<Mtype> result(rows,cols,0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = this->matrix[i][j] - rhs;
		}
	}

	return result;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator*(const Mtype& rhs)
{
	QMatrix<Mtype> result(rows,cols,0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = this->matrix[i][j] * rhs;
		}
	}

	return result;
}

template <typename Mtype>
QMatrix<Mtype> QMatrix<Mtype>::operator/(const Mtype& rhs)
{
	QMatrix<Mtype> result(rows,cols,0.0);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result(i,j) = this->matrix[i][j] / rhs;
		}
	}

	return result;
}

template <typename Mtype>
std::vector<Mtype> QMatrix<Mtype>::operator*(const std::vector<Mtype>& rhs)
{
	std::vector<Mtype> result(rhs.size(),0.0);

	for (unsigned int i = 0; i < rows; i++ )
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			result[i] += this->matrix[i][j] * rhs[j];
		}
	}

	return result;
}

template <typename Mtype>
Mtype& QMatrix<Mtype>::operator()(const unsigned int row, unsigned int col)
{
	return this->matrix[row][col];
}

template <typename Mtype>
const Mtype& QMatrix<Mtype>::operator()(const unsigned int row, unsigned int col) const
{
	return this->matrix[row][col];
}

template <typename Mtype>
void QMatrix<Mtype>::Set(unsigned int row, unsigned int col, Mtype value)
{
	if ( (row <= rows) && (col <= cols) )
	{
		this->matrix[row][col] = value;
	}
}

template <typename Mtype>
unsigned int QMatrix<Mtype>::GetRows(void) const
{
	return this->rows;
}

template <typename Mtype>
unsigned int QMatrix<Mtype>::GetCols(void) const
{
	return this->cols;
}

}


#endif

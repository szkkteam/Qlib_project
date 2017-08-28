/*
 * qmatrix.h
 *
 *  Created on: 2017. aug. 17.
 *      Author: irusics
 */

#ifndef QMATRIX_H_
#define QMATRIX_H_



#include <vector>

namespace Qlib
{



template <typename Mtype>
class QMatrix
{
public:
	QMatrix(unsigned int _rows, unsigned int _cols, const Mtype& _initial);
	QMatrix(const QMatrix<Mtype>& rhs);
	virtual ~QMatrix();

	// Operator overloading
	// Standard mathematical operations
	QMatrix<Mtype>& operator=(const QMatrix<Mtype>& rhs);

	QMatrix<Mtype> operator+(const QMatrix<Mtype>& rhs);
	QMatrix<Mtype>& operator+=(const QMatrix<Mtype>& rhs);
	QMatrix<Mtype> operator-(const QMatrix<Mtype>& rhs);
	QMatrix<Mtype>& operator-=(const QMatrix<Mtype>& rhs);

	QMatrix<Mtype> operator*(const QMatrix<Mtype>& rhs);
	QMatrix<Mtype>& operator*=(const QMatrix<Mtype>& rhs);

	QMatrix<Mtype> Transpose(void);
	void SetToIdentical(void);

	// Scalar operations
	QMatrix<Mtype> operator+(const Mtype& rhs);
	QMatrix<Mtype> operator-(const Mtype& rhs);
	QMatrix<Mtype> operator*(const Mtype& rhs);
	QMatrix<Mtype> operator/(const Mtype& rhs);

	// Matrix/Vector operations
	std::vector<Mtype> operator*(const std::vector<Mtype>& rhs);
	//std::vector<Mtype> diag_vec(void);

	// Access individual elements
	Mtype& operator()(const unsigned int row, unsigned int col);
	const Mtype& operator()(const unsigned int row, unsigned int col) const;
	void Set(unsigned int row, unsigned int col, Mtype value);

	// Access the row and columns sizes
	unsigned int GetRows(void) const;
	unsigned int GetCols(void) const;

private:
	std::vector<std::vector<Mtype> > matrix;
	unsigned int rows;
	unsigned int cols;
};

}
#include "qmatrix.cpp"

 // namespace QLib

#endif /* QMATRIX_H_ */

/*!
 * @file matrixNxN.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief Model of template class MatrixNxN
 * 
 * Modeling class of mathematical matrix with all methods. the class is a template.
 * @version 0.9
 * @date 2023-06-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vectorNd.hpp"
#include <iostream>
#include <cmath>
using std::istream;
using std::ostream;




/*!
 * @brief Template class of mathematical matrix.
 * 
 * Model of mathematical matrix. Contains 2d table _matrix[Size][Size] with values of \b T type.
 * @tparam T - type of table \see _matrix.
 * @tparam Size - _matrix type.
 */
template <typename T, unsigned int Size>
class MatrixNxN
{
private:
/*!
 * @brief Table with matrix elements.
 * 
 * Table 2d with elements of MatrixNxN.
 */
    T _matrix[Size][Size];

public:
    /*!
     * @brief Construct a new MatrixNxN object
     *
     * Default/non-parametric Constructor. Initialize table 2d \e _matrix
     * with zeros of the appropriate type.
     */
    MatrixNxN();

    /*!
     * @brief Construct a new MatrixNxN object
     *
     * Parametric constructor for _matrixNxN. Intendend to create MatrixNxN<double, 2>.
     * 
     * @param[in] a11 - value of _matrix[1][1]
     * @param[in] a12 - value of _matrix[1][2] 
     * @param[in] a21 - value of _matrix[2][1]
     * @param[in] a22 - value of _matrix[2][2]
     */
    MatrixNxN(double a11, double a12, double a21, double a22);

    /*!
     * @brief Get the Value of _matrix element.
     * 
     * @param i - index of row.
     * @param j - index of column.
     * @return T const - value of element.
     */
    T const getValue(int i, int j) { return this->_matrix[i][j]; }

    /*!
     * @brief Set the Value of _matrix element.
     * 
     * @param i - index of row.
     * @param j - index of column.
     * @param val - value of the element.
     */
    void setValue(int i, int j, double val) { this->_matrix[i][j] = val; }
    /*!
     * @brief Get the Xrotation Matrix3x3 object
     * 
     * @param angle rotation in \e X axis
     */
    void getXrotationMatrix(const double angle);
    /*!
     * @brief Get the Yrotation Matrix3x3 object
     * 
     * @param angle  rotation in \e Y axis
     */
    void getYrotationMatrix(const double angle);

    /*!
     * @brief Get the Zrotation Matrix3x3 object
     * 
     * @param angle rotation in \e Z axis
     */
    void getZrotationMatrix(const double angle);

    /*!
     * @brief Get the Identity Matrix object
     * 
     * returns identity matrix: filled with zeros and 1 on main diagonal.
     * @return MatrixNxN<T, Size> Matrix object.
     */
    static MatrixNxN<T, Size> getIdentityMatrix()
    {
        MatrixNxN<T, Size> m;
        for (uint i = 0; i < Size; ++i)
            m(i, i) = 1;
        return m;
    };

    /*!
     * @brief Overload of operator \b >> .
     * Overload of operator \b >> . Passes MatrxiNxN from stream.
     * @param istrm - input stream.
     * @param matrixx - MatrixNxN object.
     * @return std::istream& 
     */
    friend std::istream &operator>>(std::istream &istrm, MatrixNxN<T, Size> &matrixx)
    {
        T val = 0;
        for (int i = 0; i < Size; ++i)
        {
            for (int j = 0; j < Size; ++j)
            {
                istrm >> val;
                matrixx.setValue(i, j, val);
            }
        }
        return istrm;
    }

    /*!
     * @brief Overload operator \b () .
     *
     * Return value of 2dtable element in: \e i row, \e j column.
     * @param i - index of row
     * @param j - index of column
     * @return double&
     */
    double &operator()(int i, int j) { return this->_matrix[i][j]; }
};
template <typename T, unsigned int Size>
void MatrixNxN<T, Size>::getXrotationMatrix(const double angle)
{
    if (Size == 3)
    {
        MatrixNxN<T, Size> m;
        this->_matrix[0][0] = 1;
        this->_matrix[0][1] = 0;
        this->_matrix[0][2] = 0;

        this->_matrix[1][0] = 0;
        this->_matrix[1][1] = cos(angle);
        this->_matrix[1][2] = -sin(angle);

        this->_matrix[2][0] = 0;
        this->_matrix[2][1] = sin(angle);
        this->_matrix[2][2] = cos(angle);
    }
    else if (Size == 2)
    {
        this->_matrix[0][0] = cos(angle);
        this->_matrix[0][1] = sin(angle);

        this->_matrix[1][0] = sin(angle);
        this->_matrix[1][1] = cos(angle);
    }
}
template <typename T, unsigned int Size>
void MatrixNxN<T, Size>::getYrotationMatrix(const double angle)
{
    if (Size == 3)
    {

        this->_matrix[0][0] = cos(angle);
        this->_matrix[0][1] = 0;
        this->_matrix[0][2] = sin(angle);

        this->_matrix[1][0] = 0;
        this->_matrix[1][1] = 1;
        this->_matrix[1][2] = 0;

        this->_matrix[2][0] = -sin(angle);
        this->_matrix[2][1] = 0;
        this->_matrix[2][2] = cos(angle);
    }
    else if (Size == 2)
    {

        this->_matrix[0][0] = cos(angle);
        this->_matrix[0][1] = -sin(angle);

        this->_matrix[1][0] = sin(angle);
        this->_matrix[1][1] = cos(angle);
    }
}
template <typename T, unsigned int Size>
void MatrixNxN<T, Size>::getZrotationMatrix(const double angle)
{
    if (Size == 3)
    {
        MatrixNxN<T, Size> m;
        this->_matrix[0][0] = cos(angle);
        this->_matrix[0][1] = -sin(angle);
        this->_matrix[0][2] = 0;

        this->_matrix[1][0] = sin(angle);
        this->_matrix[1][1] = cos(angle);
        this->_matrix[1][2] = 0;

        this->_matrix[2][0] = 0;
        this->_matrix[2][1] = 0;
        this->_matrix[2][2] = 1;
    }
    else if (Size == 2)
    {
        this->_matrix[0][0] = cos(angle);
        this->_matrix[0][1] = -sin(angle);

        this->_matrix[1][0] = sin(angle);
        this->_matrix[1][1] = cos(angle);
    }
    else
    {
        for (int i = 0; i < int(Size); ++i)
        {
            for (int j = 0; j < int(Size); ++j)
            {
                this->_matrix[i][j] = 0;
            }
        }
    }
}

template <typename T, unsigned int Size>
MatrixNxN<T, Size>::MatrixNxN()
{
    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            this->_matrix[i][j] = 0;
        }
    }
}

template <typename T, unsigned int Size>
MatrixNxN<T, Size>::MatrixNxN(double a11, double a12, double a21, double a22)
{
    this->_matrix[0][0] = a11;
    this->_matrix[0][1] = a12;
    this->_matrix[1][0] = a21;
    this->_matrix[1][1] = a22;
    if (Size > 2)
    {
        for (int i = 2; i < Size; ++i)
        {
            for (int j = 2; j < Size; ++j)
                this->_matrix[i][j] = 0;
        }
    }
}
template <typename T, unsigned int Size>
std::ostream &operator<<(std::ostream &ostrm, MatrixNxN<T, Size> matrixx)
{
    for (int i = 0; i < int(Size); ++i)
    {
        ostrm << "| ";
        for (int j = 0; j < int(Size); ++j)
        {
            ostrm << matrixx(i, j) << " ";
        }
        ostrm << "|";
        ostrm << std::endl;
    }
    return ostrm;
}

template <typename T, unsigned int Size>
VectorNd<T, Size> operator*(MatrixNxN<T, Size> m, VectorNd<T, Size> v)
{
    VectorNd<T, Size> result;
    result.setCoords(0, 0, 0);
    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            result.setCoord(i, result[i] + (m(i, j) * v[j]));
        }
    }
    return result;
}
template <typename T, unsigned int Size>
MatrixNxN<T, Size> operator*(MatrixNxN<T, Size> m1, MatrixNxN<T, Size> m2)
{
    MatrixNxN<T, Size> result;
    // int a =0;
    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            for (int k = 0; k < int(Size); ++k)
                result(i, j) = result(i, j) + m1(i, k) * m2(k, j);
        }
    }
    return result;
}

template <typename T, unsigned int Size>
MatrixNxN<T, Size> operator+(MatrixNxN<T, Size> m1, MatrixNxN<T, Size> m2)
{
    MatrixNxN<T, Size> result;
    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            result(i, j) = m1(i, j) + m2(i, j);
        }
    }
    return result;
}
template <typename T, unsigned int Size>
bool operator==(MatrixNxN<T, Size> m1, MatrixNxN<T, Size> m2)
{
    MatrixNxN<T, Size> result;

    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            if (m1(i, j) != m2(i, j))
                return false;
        }
    }
    return true;
}

template <typename T, unsigned int Size>
bool operator==(MatrixNxN<T, Size> m1, T a)
{
    MatrixNxN<T, Size> result;
    for (int i = 0; i < int(Size); ++i)
    {
        for (int j = 0; j < int(Size); ++j)
        {
            if (m1(i, j) != a)
                return false;
        }
    }
    return true;
}

/*!
 * @brief Placeholder data type of MatrixNxN<double, 3>
 * 
 * Model of matrix 3 x 3.
 */
typedef MatrixNxN<double, 3> Matrix3x3;

#endif // MATRIX_HPP
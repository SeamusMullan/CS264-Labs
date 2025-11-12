#include "Matrix.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>


/**
 * @brief Allocates 2d array of memory for a Matrix dynamically.
 */
void Matrix::allocate()
{
    data = new int *[m_rows];
    for (unsigned int i = 0; i < m_rows; i++)
    {
        data[i] = new int[m_cols];
    }
}

/**
 * @brief Deallocates memory for the array if it exists. Deletes internal arrays first.
 */
void Matrix::deallocate()
{
    if (data != nullptr)
    {
        for (unsigned int i = 0; i < m_rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

/**
 * @brief Creates a matrix with a variable number of rows and columns
 * 
 *  uses Member initializers m_rows(), m_cols() and data() to initialize vars.
 *
 * @param m Number of rows in the array
 * @param n number of columns in the array
 */
Matrix::Matrix(unsigned int m, unsigned int n) : m_rows(m), m_cols(n), data(nullptr)
{
    allocate();
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            data[i][j] = 0;
        }
    }
}

/**
 * @brief Copies data from one Matrix into a new one.
 *
 * @param mat the matrix to copy data from.
 */
Matrix::Matrix(const Matrix &mat) : m_rows(mat.m_rows), m_cols(mat.m_cols), data(nullptr)
{
    allocate();
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

/**
 * @brief Creates a Matrix using data from a 2D array of ints.
 *
 * Initializes member vars with m_rows(), m_cols(), data()
 *
 * The new matrix can have more rows and columns than the array.
 * If it has less, the matrix will only include the data from a subsection of the 2d array.
 *
 * @param array The 2D array to be converted into a Matrix
 * @param m num rows in the matrix
 * @param n num columns in the matrix
 */
Matrix::Matrix(int **array, unsigned int m, unsigned int n) : m_rows(m), m_cols(n), data(nullptr)
{
    allocate();
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            data[i][j] = array[i][j];
        }
    }
}

/**
 * @brief Deallocates all memory associated with an instance of a Matrix
 */
Matrix::~Matrix()
{
    deallocate();
}

/**
 * @brief Overrides the = operator for Matrix objects
 *
 * @param mat The matrix whos values we assign to this matrix
 * @return a pointer to this instance of the matrix.
 */
Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        deallocate();

        m_rows = mat.m_rows;
        m_cols = mat.m_cols;

        allocate();
        for (unsigned int i = 0; i < m_rows; i++)
        {
            for (unsigned int j = 0; j < m_cols; j++)
            {
                data[i][j] = mat.data[i][j];
            }
        }
    }
    return *this;
}

/**
 * @brief Get num rows in a matrix
 *
 * @return uint number of rows
 */
unsigned int Matrix::rows() const
{
    return m_rows;
}

/**
 * @brief get num cols in a matrix
 *
 * @return uint number of cols
 */
unsigned int Matrix::columns() const
{
    return m_cols;
}

/**
 * @brief Get a value at a specific row/col in the matrix
 *
 * if there is no value, we throw an error (std::out_of_range)
 *
 * @param i the row number
 * @param j the col number
 * @return the value (if it exists)
 */
int Matrix::get(unsigned int i, unsigned int j) const
{
    if (i >= m_rows || j >= m_cols)
    {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

/**
 * @brief sets value of specific row/col in matrix
 *
 * @param i row index
 * @param j col index
 * @param value the value that we are setting
 */
void Matrix::set(unsigned int i, unsigned int j, int value)
{
    if (i >= m_rows || j >= m_cols)
    {
        throw std::out_of_range("Matrix indices out of range");
    }
    data[i][j] = value;
}

/**
 * @brief override addition operator
 *
 * doesnt work if matrixes are diff size
 *
 * @param mat matrix to add to this
 * @return the sum of both matrixes
 */
Matrix Matrix::operator+(const Matrix &mat)
{
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            result.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return result;
}

/**
 * @brief subtract operator
 *
 * doesnt work if both matrices are different sizes
 *
 * @param mat the matrix to subtract from this
 * @return new matrix which = this - mat
 */
Matrix Matrix::operator-(const Matrix &mat)
{
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }

    Matrix result(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            result.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return result;
}

/**
 * @brief multiplication operator override
 *
 * @param mat matrix to multiply this by
 * @return new matrix which = this * mat
 */
Matrix Matrix::operator*(const Matrix &mat)
{
    if (m_cols != mat.m_rows)
    {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }

    Matrix result(m_rows, mat.m_cols);
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < mat.m_cols; j++)
        {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < m_cols; k++)
            {
                result.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }
    return result;
}

/**
 * @brief transpose operator
 *
 * @return the transpose of this matrix as a new object
 */
Matrix Matrix::operator~() const
{
    Matrix result(m_cols, m_rows);
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

/**
 * @brief equivalence operator override
 *
 * doesnt work if matrixes are different size
 *
 * @param mat matrix to compare to
 * @return bool value (true if values in both this and mat are equal)
 */
bool Matrix::operator==(const Matrix &mat)
{
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
    {
        return false;
    }

    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            if (data[i][j] != mat.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Convert matrix to a string
 * 
 * uses std::ostringstream to build the string row by row, with newlines
 *
 * @return string object of the array
 */
std::string Matrix::toStr()
{
    std::ostringstream oss;
    for (unsigned int i = 0; i < m_rows; i++)
    {
        for (unsigned int j = 0; j < m_cols; j++)
        {
            oss << std::setw(5) << data[i][j];
        }
        oss << "\n";
    }
    return oss.str();
}

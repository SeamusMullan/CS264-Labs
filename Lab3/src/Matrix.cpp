#include "Matrix.h"
void Matrix::allocate() {
    data = new int*[m_rows];
    for (unsigned int i = 0; i < m_rows; i++) {
        data[i] = new int[m_cols];
    }
}

void Matrix::deallocate() {
    if (data != nullptr) {
        for (unsigned int i = 0; i < m_rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

Matrix::Matrix(unsigned int m, unsigned int n) : m_rows(m), m_cols(n), data(nullptr) {
    allocate();
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &mat) : m_rows(mat.m_rows), m_cols(mat.m_cols), data(nullptr) {
    allocate();
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::Matrix(int** array, unsigned int m, unsigned int n) : m_rows(m), m_cols(n), data(nullptr) {
    allocate();
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = array[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocate();
}

Matrix& Matrix::operator=(const Matrix &mat) {
    if (this != &mat) {
        deallocate();
        
        m_rows = mat.m_rows;
        m_cols = mat.m_cols;
        
        allocate();
        for (unsigned int i = 0; i < m_rows; i++) {
            for (unsigned int j = 0; j < m_cols; j++) {
                data[i][j] = mat.data[i][j];
            }
        }
    }
    return *this;
}

unsigned int Matrix::rows() const {
    return m_rows;
}

unsigned int Matrix::rows() const {
    return m_rows;
}

unsigned int Matrix::columns() const {
    return m_cols;
}

int Matrix::get(unsigned int i, unsigned int j) const {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

void Matrix::set(unsigned int i, unsigned int j, int value) {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    data[i][j] = value;
}

Matrix Matrix::operator+(const Matrix &mat) {
    if (m_rows != mat.m_rows || m_cols != mat.m_cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    Matrix result(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            result.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &mat) {
    if (m_rows != mat.m_rows || m_cols != mat.m_cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    
    Matrix result(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            result.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &mat) {
    if (m_cols != mat.m_rows) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }
    
    Matrix result(m_rows, mat.m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < mat.m_cols; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < m_cols; k++) {
                result.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }
    return result;
}

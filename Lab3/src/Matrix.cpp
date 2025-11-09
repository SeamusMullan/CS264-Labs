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


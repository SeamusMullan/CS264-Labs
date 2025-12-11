#ifndef MATRIX_H
#define MATRIX_H

// #ifndef was for compiler, cuz im a nerd :p

#include <string>

class Matrix
{
private:
    int **data; // ptr to data
    unsigned int m_rows; // num rows
    unsigned int m_cols; // num cols

    void allocate();

    void deallocate();

public:

    // these are all commented in Matrix.cpp

    Matrix(unsigned int m, unsigned int n);

    Matrix(const Matrix &mat);

    Matrix(int **array, unsigned int m, unsigned int n);

    ~Matrix();

    Matrix &operator=(const Matrix &mat);

    unsigned int rows() const;

    unsigned int columns() const;

    int get(unsigned int i, unsigned int j) const;

    void set(unsigned int i, unsigned int j, int value);

    Matrix operator+(const Matrix &mat);

    Matrix operator-(const Matrix &mat);

    Matrix operator*(const Matrix &mat);

    Matrix operator~() const;

    bool operator==(const Matrix &mat);

    std::string toStr();
};

#endif // MATRIX_H

# CS264 Assignment 3 - Matrix Class Implementation

## Tasks Overview

- [ ] Matrix.h
- [ ] Matrix.cpp
- [ ] TestMatrix.cpp

---

## Matrix.h

- [ ] `Matrix(unsigned int m, unsigned int n)`
- [ ] `Matrix(const Matrix &mat)`
- [ ] `Matrix(int array, unsigned int m, unsigned int n)`
- [ ] `unsigned int rows() const`
- [ ] `unsigned int columns() const`
- [ ] `int get(unsigned i, unsigned j) const`
- [ ] `void set(unsigned i, unsigned j, int value)`
- [ ] `Matrix operator+(const Matrix &mat)`
- [ ] `Matrix operator-(const Matrix &mat)`
- [ ] `Matrix operator*(const Matrix &mat)`
- [ ] `Matrix operator~() const` - Matrix transpose
- [ ] `bool operator==(const Matrix &mat)`
- [ ] `string toStr()` - String representation showing all elements
- [ ] Destructor to free dynamically allocated memory
- [ ] Private member variables for matrix data storage

---

## Matrix.cpp

- [ ] Matrix(unsigned int m, unsigned int n)` with dynamic allocation
- [ ] Matrix(const Matrix &mat)`
- [ ] Matrix(int array, unsigned int m, unsigned int n)`
- [ ] rows()`
- [ ] columns()`
- [ ] get(unsigned i, unsigned j)`
- [ ] set(unsigned i, unsigned j, int value)`
- [ ] operator+` (check dimensions match)
- [ ] operator-` (check dimensions match)
- [ ] operator*` (check inner dimensions match: cols of A = rows of B)
- [ ] operator~` (transpose: swap rows and columns)
- [ ] operator==` (check dimensions and all elements)
- [ ] toStr()` with proper formatting
- [ ] estructor to delete dynamically allocated memory

---

### Tests n stuff

- [ ] `Matrix(unsigned int m, unsigned int n)`
- [ ] `Matrix(const Matrix &mat)`
- [ ] `Matrix(int array, unsigned int m, unsigned int n)`
- [ ] `rows()`
- [ ] `columns()`
- [ ] `get()`
- [ ] `set()`
- [ ] `operator+`
- [ ] `operator-`
- [ ] `operator*`
- [ ] `operator~`
- [ ] `operator==`
- [ ] `toStr()`
- [ ] Test edge cases (empty matrices, 1×1 matrices)
- [ ] Test invalid operations (dimension mismatches)
- [ ] Test memory management (no memory leaks)

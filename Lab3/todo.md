# CS264 Assignment 3 - Matrix Class Implementation

## Tasks Overview

- [x] Matrix.h
- [x] Matrix.cpp
- [ ] TestMatrix.cpp

---

## Matrix.h

- [x] `Matrix(unsigned int m, unsigned int n)`
- [x] `Matrix(const Matrix &mat)`
- [x] `Matrix(int array, unsigned int m, unsigned int n)`
- [x] `unsigned int rows() const`
- [x] `unsigned int columns() const`
- [x] `int get(unsigned i, unsigned j) const`
- [x] `void set(unsigned i, unsigned j, int value)`
- [x] `Matrix operator+(const Matrix &mat)`
- [x] `Matrix operator-(const Matrix &mat)`
- [x] `Matrix operator*(const Matrix &mat)`
- [x] `Matrix operator~() const` - Matrix transpose
- [x] `bool operator==(const Matrix &mat)`
- [x] `string toStr()` - String representation showing all elements
- [x] Destructor to free dynamically allocated memory
- [x] Private member variables for matrix data storage

---

## Matrix.cpp

- [x] Matrix(unsigned int m, unsigned int n)` with dynamic allocation
- [x] Matrix(const Matrix &mat)`
- [x] Matrix(int array, unsigned int m, unsigned int n)`
- [x] rows()`
- [x] columns()`
- [x] get(unsigned i, unsigned j)`
- [x] set(unsigned i, unsigned j, int value)`
- [x] operator+` (check dimensions match)
- [x] operator-` (check dimensions match)
- [x] operator*` (check inner dimensions match: cols of A = rows of B)
- [x] operator~` (transpose: swap rows and columns)
- [x] operator==` (check dimensions and all elements)
- [x] toStr()` with proper formatting
- [x] estructor to delete dynamically allocated memory

---

### Tests n stuff

- [x] `Matrix(unsigned int m, unsigned int n)`
- [x] `Matrix(const Matrix &mat)`
- [x] `Matrix(int array, unsigned int m, unsigned int n)`
- [x] `rows()`
- [x] `columns()`
- [x] `get()`
- [x] `set()`
- [x] `operator+`
- [x] `operator-`
- [x] `operator*`
- [x] `operator~`
- [x] `operator==`
- [x] `toStr()`
- [ ] Test edge cases (empty matrices, 1×1 matrices)
- [ ] Test invalid operations (dimension mismatches)
- [ ] Test memory management (no memory leaks)

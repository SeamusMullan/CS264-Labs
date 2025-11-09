#include "Matrix.h"
#include <iostream>
#include <cassert>

using namespace std;

/**
 * Test case 1 for specialized constructor Matrix(m, n).
 * Tests if a matrix is properly initialized with zeros.
 */
void Test_Case_1_Constructor() {
    cout << "Test Case 1: Specialized Constructor" << endl;
    Matrix mat(3, 3);
    
    // Check dimensions
    assert(mat.rows() == 3);
    assert(mat.columns() == 3);
    
    // Check all elements are 0
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            assert(mat.get(i, j) == 0);
        }
    }
    
    cout << "Matrix created (3x3):\n" << mat.toStr() << endl;
    cout << "PASSED\n" << endl;
}

void Test_Case_2_CopyConstructor() {
    cout << "Test Case 2: Copy Constructor" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);
    
    Matrix mat2(mat1);
    
    // Check that mat2 is a copy of mat1
    assert(mat2.rows() == mat1.rows());
    assert(mat2.columns() == mat1.columns());
    assert(mat2.get(0, 0) == 1);
    assert(mat2.get(0, 1) == 2);
    assert(mat2.get(1, 0) == 3);
    assert(mat2.get(1, 1) == 4);
    
    cout << "Original matrix:\n" << mat1.toStr() << endl;
    cout << "Copied matrix:\n" << mat2.toStr() << endl;
    cout << "PASSED\n" << endl;
}
void Test_Case_3_ArrayConstructor() {
    cout << "Test Case 3: Array Constructor" << endl;
    
    // Create a 2D array
    int** array = new int*[2];
    for (int i = 0; i < 2; i++) {
        array[i] = new int[3];
    }
    
    array[0][0] = 1; array[0][1] = 2; array[0][2] = 3;
    array[1][0] = 4; array[1][1] = 5; array[1][2] = 6;
    
    Matrix mat(array, 2, 3);
    
    // Check dimensions and values
    assert(mat.rows() == 2);
    assert(mat.columns() == 3);
    assert(mat.get(0, 0) == 1);
    assert(mat.get(0, 1) == 2);
    assert(mat.get(0, 2) == 3);
    assert(mat.get(1, 0) == 4);
    assert(mat.get(1, 1) == 5);
    assert(mat.get(1, 2) == 6);
    
    cout << "Matrix from array:\n" << mat.toStr() << endl;
    
    // Clean up array
    for (int i = 0; i < 2; i++) {
        delete[] array[i];
    }
    delete[] array;
    
    cout << "PASSED\n" << endl;
}
int main() {
    cout << "========================================" << endl;
    cout << "     Matrix Class Test Suite" << endl;
    cout << "========================================\n" << endl;
    
    try {
        Test_Case_1_Constructor();
        Test_Case_2_CopyConstructor();
        
        cout << "========================================" << endl;
        cout << "   All tests passed successfully!" << endl;
        cout << "========================================" << endl;
    } catch (const exception& e) {
        cerr << "Test failed with exception: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

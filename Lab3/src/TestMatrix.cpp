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

int main() {
    cout << "========================================" << endl;
    cout << "     Matrix Class Test Suite" << endl;
    cout << "========================================\n" << endl;
    
    try {
        Test_Case_1_Constructor();
        
        cout << "========================================" << endl;
        cout << "   All tests passed successfully!" << endl;
        cout << "========================================" << endl;
    } catch (const exception& e) {
        cerr << "Test failed with exception: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

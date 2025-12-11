#include "Matrix.h"
#include <iostream>
#include <cassert>

using namespace std;

/**
 * Test case 1 for specialized constructor Matrix(m, n).
 * Tests if a matrix is properly initialized with zeros.
 */
void Test_Case_1_Constructor()
{
    cout << "Test Case 1: Specialized Constructor" << endl;
    Matrix mat(3, 3);

    // Check dimensions
    assert(mat.rows() == 3);
    assert(mat.columns() == 3);

    // Check all elements are 0
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            assert(mat.get(i, j) == 0);
        }
    }

    cout << "Matrix created (3x3):\n"
         << mat.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_2_CopyConstructor()
{
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

    cout << "Original matrix:\n"
         << mat1.toStr() << endl;
    cout << "Copied matrix:\n"
         << mat2.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_3_ArrayConstructor()
{
    cout << "Test Case 3: Array Constructor" << endl;

    // Create a 2D array
    int **array = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        array[i] = new int[3];
    }

    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[1][0] = 4;
    array[1][1] = 5;
    array[1][2] = 6;

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

    cout << "Matrix from array:\n"
         << mat.toStr() << endl;

    // Clean up array
    for (int i = 0; i < 2; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    cout << "PASSED\n"
         << endl;
}

void Test_Case_4_Rows()
{
    cout << "Test Case 4: rows() method" << endl;
    Matrix mat(5, 3);

    assert(mat.rows() == 5);

    cout << "Matrix dimensions: " << mat.rows() << " rows" << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_5_Columns()
{
    cout << "Test Case 5: columns() method" << endl;
    Matrix mat(3, 7);

    assert(mat.columns() == 7);

    cout << "Matrix dimensions: " << mat.columns() << " columns" << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_6_Get()
{
    cout << "Test Case 6: get() method" << endl;
    Matrix mat(3, 3);
    mat.set(1, 2, 42);

    assert(mat.get(1, 2) == 42);
    assert(mat.get(0, 0) == 0);

    cout << "Element at (1, 2): " << mat.get(1, 2) << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_7_Set()
{
    cout << "Test Case 7: set() method" << endl;
    Matrix mat(2, 2);

    mat.set(0, 0, 10);
    mat.set(0, 1, 20);
    mat.set(1, 0, 30);
    mat.set(1, 1, 40);

    assert(mat.get(0, 0) == 10);
    assert(mat.get(0, 1) == 20);
    assert(mat.get(1, 0) == 30);
    assert(mat.get(1, 1) == 40);

    cout << "Matrix after set():\n"
         << mat.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_8_Plus()
{
    cout << "Test Case 8: operator+ (Addition)" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 5);
    mat2.set(0, 1, 6);
    mat2.set(1, 0, 7);
    mat2.set(1, 1, 8);

    Matrix result = mat1 + mat2;

    assert(result.get(0, 0) == 6);
    assert(result.get(0, 1) == 8);
    assert(result.get(1, 0) == 10);
    assert(result.get(1, 1) == 12);

    cout << "Matrix 1:\n"
         << mat1.toStr() << endl;
    cout << "Matrix 2:\n"
         << mat2.toStr() << endl;
    cout << "Result (mat1 + mat2):\n"
         << result.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_9_Minus()
{
    cout << "Test Case 9: operator- (Subtraction)" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 10);
    mat1.set(0, 1, 9);
    mat1.set(1, 0, 8);
    mat1.set(1, 1, 7);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 0, 3);
    mat2.set(1, 1, 4);

    Matrix result = mat1 - mat2;

    assert(result.get(0, 0) == 9);
    assert(result.get(0, 1) == 7);
    assert(result.get(1, 0) == 5);
    assert(result.get(1, 1) == 3);

    cout << "Matrix 1:\n"
         << mat1.toStr() << endl;
    cout << "Matrix 2:\n"
         << mat2.toStr() << endl;
    cout << "Result (mat1 - mat2):\n"
         << result.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_10_Multiply()
{
    cout << "Test Case 10: operator* (Multiplication)" << endl;
    Matrix mat1(2, 3);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    Matrix mat2(3, 2);
    mat2.set(0, 0, 7);
    mat2.set(0, 1, 8);
    mat2.set(1, 0, 9);
    mat2.set(1, 1, 10);
    mat2.set(2, 0, 11);
    mat2.set(2, 1, 12);

    Matrix result = mat1 * mat2;

    // Result should be 2x2
    assert(result.rows() == 2);
    assert(result.columns() == 2);

    // Expected: [1*7+2*9+3*11, 1*8+2*10+3*12] = [58, 64]
    //           [4*7+5*9+6*11, 4*8+5*10+6*12] = [139, 154]
    assert(result.get(0, 0) == 58);
    assert(result.get(0, 1) == 64);
    assert(result.get(1, 0) == 139);
    assert(result.get(1, 1) == 154);

    cout << "Matrix 1 (2x3):\n"
         << mat1.toStr() << endl;
    cout << "Matrix 2 (3x2):\n"
         << mat2.toStr() << endl;
    cout << "Result (mat1 * mat2):\n"
         << result.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_11_Transpose()
{
    cout << "Test Case 11: operator~ (Transpose)" << endl;
    Matrix mat(2, 3);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(0, 2, 3);
    mat.set(1, 0, 4);
    mat.set(1, 1, 5);
    mat.set(1, 2, 6);

    Matrix result = ~mat;

    // Result should be 3x2
    assert(result.rows() == 3);
    assert(result.columns() == 2);

    assert(result.get(0, 0) == 1);
    assert(result.get(0, 1) == 4);
    assert(result.get(1, 0) == 2);
    assert(result.get(1, 1) == 5);
    assert(result.get(2, 0) == 3);
    assert(result.get(2, 1) == 6);

    cout << "Original matrix (2x3):\n"
         << mat.toStr() << endl;
    cout << "Transposed matrix (3x2):\n"
         << result.toStr() << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_12_Equality()
{
    cout << "Test Case 12: operator== (Equality)" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 0, 3);
    mat2.set(1, 1, 4);

    Matrix mat3(2, 2);
    mat3.set(0, 0, 1);
    mat3.set(0, 1, 2);
    mat3.set(1, 0, 3);
    mat3.set(1, 1, 5); // Different

    assert(mat1 == mat2);
    assert(!(mat1 == mat3));

    cout << "Matrix 1:\n"
         << mat1.toStr() << endl;
    cout << "Matrix 2:\n"
         << mat2.toStr() << endl;
    cout << "mat1 == mat2: " << (mat1 == mat2 ? "true" : "false") << endl;
    cout << "Matrix 3:\n"
         << mat3.toStr() << endl;
    cout << "mat1 == mat3: " << (mat1 == mat3 ? "true" : "false") << endl;
    cout << "PASSED\n"
         << endl;
}

void Test_Case_13_ToStr()
{
    cout << "Test Case 13: toStr() method" << endl;
    Matrix mat(2, 3);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(0, 2, 3);
    mat.set(1, 0, 4);
    mat.set(1, 1, 5);
    mat.set(1, 2, 6);

    string str = mat.toStr();

    // Check that string is not empty
    assert(!str.empty());

    cout << "String representation of matrix:\n"
         << str << endl;
    cout << "PASSED\n"
         << endl;
}

int main()
{
    cout << "========================================" << endl;
    cout << " Super fancy Matrix tests (for real)" << endl;
    cout << "========================================\n"
         << endl;

    try
    {
        Test_Case_1_Constructor();
        Test_Case_2_CopyConstructor();
        Test_Case_3_ArrayConstructor();
        Test_Case_4_Rows();
        Test_Case_5_Columns();
        Test_Case_6_Get();
        Test_Case_7_Set();
        Test_Case_8_Plus();
        Test_Case_9_Minus();
        Test_Case_10_Multiply();
        Test_Case_11_Transpose();
        Test_Case_12_Equality();
        Test_Case_13_ToStr();

        cout << "========================================" << endl;
        cout << "   All tests passed successfully!" << endl;
        cout << "========================================" << endl;
    }
    catch (const exception &e)
    {
        cerr << "Test failed (lol): " << e.what() << endl;
        return 1;
    }

    return 0;
}

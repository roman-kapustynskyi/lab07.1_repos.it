#include "pch.h"
#include "CppUnitTest.h"
#include "../PR07.1 it/FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

                TEST_METHOD(TestMethod_Calc)
                {
                    int rowCount = 2;
                    int colCount = 2;

                    int** test_mat = new int* [rowCount];
                    for (int i = 0; i < rowCount; i++) {
                        test_mat[i] = new int[colCount];
                    }

                    test_mat[0][0] = 10;
                    test_mat[0][1] = 15;
                    test_mat[1][0] = 20;
                    test_mat[1][1] = 30;

                    int S = 0;
                    int k = 0;

                    
                    Calc(test_mat, rowCount, colCount, S, k);

                    Assert::AreEqual(50, S); 
                    Assert::AreEqual(2, k); 
                    Assert::AreEqual(0, test_mat[1][0]); 
                    Assert::AreEqual(0, test_mat[1][1]);

                    for (int i = 0; i < rowCount; i++) {
                        delete[] test_mat[i];
                    }
                    delete[] test_mat;
                }

                TEST_METHOD(TestMethod_Sort)
                {
                    int rowCount = 3;
                    int colCount = 3;

                    int** test_mat = new int* [rowCount];
                    for (int i = 0; i < rowCount; i++) {
                        test_mat[i] = new int[colCount];
                    }

                    test_mat[0][0] = 5; test_mat[0][1] = 9; test_mat[0][2] = 2;
                    test_mat[1][0] = 1; test_mat[1][1] = 4; test_mat[1][2] = 8;
                    test_mat[2][0] = 7; test_mat[2][1] = 6; test_mat[2][2] = 3;

                    Sort(test_mat, rowCount, colCount);

                    Assert::AreEqual(9, test_mat[0][0]);
                    Assert::AreEqual(5, test_mat[0][1]);
                    Assert::AreEqual(2, test_mat[0][2]);

                    for (int i = 0; i < rowCount; i++) {
                        delete[] test_mat[i];
                    }
                    delete[] test_mat;
                }
            };
        }
	

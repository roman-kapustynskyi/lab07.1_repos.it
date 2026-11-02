#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
void ChangeCols(int** a, const int rowCount, int col1, int col2);
void Sort(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 62;
    int rowCount = 7;
    int colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);


    Sort(a, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Matrix after Calc:" << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] % 2 == 0 && (i + j) % 8 != 0) {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
    }
}

void ChangeCols(int** a, const int rowCount, int col1, int col2) {
    for (int i = 0; i < rowCount; i++) {
        int temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}

void Sort(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            if (
                (a[0][j] < a[0][j + 1]) ||
                (a[0][j] == a[0][j + 1] && a[1][j] > a[1][j + 1]) ||
                (a[0][j] == a[0][j + 1] && a[1][j] == a[1][j + 1] && a[2][j] > a[2][j + 1])
                ) {
                ChangeCols(a, rowCount, j, j + 1);
            }
        }
    }
}
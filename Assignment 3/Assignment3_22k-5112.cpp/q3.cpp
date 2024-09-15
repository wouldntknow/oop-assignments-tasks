#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Matrix {
public:
    int rows, cols;

    T array1[100][100]; // Assuming maximum size of 100x100
    T array2[100][100];
    T result[100][100];

    Matrix(int r, int c) : rows(r), cols(c) {}

    void setMatrix() {
        cout << "Enter the elements for Matrix 1: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> array1[i][j];
            }
        }
        cout << "Enter the elements for Matrix 2: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> array2[i][j];
            }
        }
    }

    void addMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = array1[i][j] + array2[i][j];
            }
        }
        cout << "Resultant Matrix after addition" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void subMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = array1[i][j] - array2[i][j];
            }
        }
        cout << "Resultant Matrix after Subtraction" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiplyMatrix() {
        int R2 = cols; // Number of columns in array2
        int temp = cols;
        rows = cols;
        cols = temp;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < R2; k++) {
                    result[i][j] += array1[i][k] * array2[k][j];
                }
            }
        }
        cout << "Resultant Matrix after Multiplication" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    virtual void display() = 0; // virtual function
};

class intMatrix : public Matrix<int> {
public:
    intMatrix(int r, int c) : Matrix<int>(r, c) {}

    void display() override {
        cout << "Matrix 1:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array1[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Matrix 2:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

class doubleMatrix : public Matrix<double> {
public:
    doubleMatrix(int r, int c) : Matrix<double>(r, c) {}

    void display() override {
        cout << "Matrix 1:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array1[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Matrix 2:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    intMatrix I1(2, 2);

    I1.setMatrix();

    cout << "Performing Matrix Operations for int Matrix:" << endl;
    I1.addMatrix();
    I1.subMatrix();
    I1.multiplyMatrix();

    doubleMatrix D1(2, 2);

    D1.setMatrix();

    cout << "Performing Matrix Operations for double Matrix:" << endl;
    D1.addMatrix();
    D1.subMatrix();
    D1.multiplyMatrix();

    return 0;
}

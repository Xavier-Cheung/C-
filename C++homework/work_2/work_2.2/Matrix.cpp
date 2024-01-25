#include<iostream>
#include<cstdlib>
#include"Matrix.h"

using namespace std;

Matrix::Matrix(int a, int b) {
    this -> Rows = a;
    this -> Lines = b;
    this -> matrix = new int* [Rows];
    for(int i = 0; i < Rows; i++)
        this -> matrix[i] = new int[Lines];
}

Matrix::Matrix(Matrix& q) {
    this -> Rows = q.Rows;
    this -> Lines = q.Lines;
    this->matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
		this -> matrix[i] = new int[Lines];
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Lines; j++)
			this->matrix[i][j] = q.matrix[i][j];
}

Matrix::~Matrix() {
    if(matrix != nullptr) {
        for(int i = 0; i < Rows; i++)
            delete[]matrix[i];
        delete[]matrix;
    }
    matrix = nullptr;
}

void Matrix::Input() {
    for(int i = 0; i < Rows; i++) {
        for(int j = 0; j < Lines; j++)
            cin >> this -> matrix[i][j];
    }
}

void Matrix::Output() {
    for(int i = 0; i < Rows; i++) {
        for(int j = 0; j < Lines; j++)
            cout << this -> matrix[i][j] << " ";
        cout << endl;
    }
}

void Matrix::Addition(Matrix A, Matrix B) {
    for(int i = 0; i < Rows; i++) 
        for(int j = 0; j < Lines; j++)
            this -> matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
}

void Matrix::Subtract(Matrix A, Matrix B) {
    for(int i = 0; i < Rows; i++) 
        for(int j = 0; j < Lines; j++)
            this -> matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
}

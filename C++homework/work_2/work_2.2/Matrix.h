class Matrix
{
public:
    int Lines, Rows;
    int** matrix = nullptr;
    Matrix(int a, int b);
    Matrix(Matrix& q);
    ~Matrix();
    void Input();
    void Output();
    void Addition(Matrix A, Matrix B);
    void Subtract(Matrix A, Matrix B);
    Matrix& operator = (Matrix& q) {//对=的重载
        if(matrix != nullptr) {
            delete matrix;
            matrix = nullptr;
        }
        matrix = new int* [Rows];
        for(int i = 0; i < Rows; i++)
            matrix[i] = new int[Lines];
        for(int i = 0; i < Rows; i++) {
            for(int j = 0; j < Lines; j++)
                this -> matrix[i][j] = q.matrix[i][j];
        }
        return *this;
    }
};

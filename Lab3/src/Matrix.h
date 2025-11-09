class Matrix {
private:
    int** data;
    unsigned int m_rows;
    unsigned int m_cols;

    void allocate();

    void deallocate();

public:
    Matrix(unsigned int m, unsigned int n);

    Matrix(const Matrix &mat);

    Matrix(int** array, unsigned int m, unsigned int n);

    ~Matrix();

    Matrix& operator=(const Matrix &mat);

    unsigned int rows() const;

    unsigned int columns() const;

    int get(unsigned int i, unsigned int j) const;

    void set(unsigned int i, unsigned int j, int value);

    Matrix operator+(const Matrix &mat);

    Matrix operator-(const Matrix &mat);

    Matrix operator*(const Matrix &mat);

    Matrix operator~() const;

    bool operator==(const Matrix &mat);

    std::string toStr();
};

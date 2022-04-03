#pragma once
#include <vector>
#include <iostream>
#include <string>
using std::vector;

class Matrix{

    // globaly overloaded operators
    friend std::ostream & operator<<(std::ostream & os, const Matrix &m);
    friend Matrix operator>>(std::istream & os, const Matrix &m);
    friend Matrix operator*(double scalar, const Matrix & m);
    friend Matrix operator*(const Matrix & m, double scalar );
    friend Matrix operator*(const Matrix & m, const Matrix & m2);
    


    private:
        vector<vector<double>> mat;
        
    public:
        size_t rowsNum, colsNum;
        Matrix(vector<double> vals, size_t rows, size_t cols );
        Matrix(vector<double> vals, int rows, int cols );
        Matrix(const Matrix &m);
        ~Matrix(){
            // std::cout<<"Destructor called for: "<<rowsNum <<" X " <<colsNum<<std::endl;
        }
        
        
        // overloaded operators
        //addtion and substraction
        void  operator+=(const Matrix &rhs);
        void  operator-=(const Matrix &rhs);
        Matrix operator+(const Matrix &);
        Matrix operator-(const Matrix &);
        Matrix operator-();
        Matrix operator+();
        void operator--();
        void operator++();

        //comparsions
        bool operator==(const Matrix &m);
        bool operator!=(const Matrix &m);
        bool operator>=(const Matrix &m);
        bool operator<=(const Matrix &m);
        bool operator<(const Matrix &m);
        bool operator>(const Matrix &m);
        
        // mult
        void operator*=(double scalar);

        // methods
        bool isSameDim(const Matrix &) const;
        double get(size_t,size_t) const;
        double sum() const;

};


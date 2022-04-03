#include "Matrix.hpp"
#include "helpers.hpp"

// constructors

//Used to handle dimention in ints, dellegating to the size_t constructor
Matrix::Matrix(vector<double> vals, int rows, int cols )
:Matrix(std::move(vals),static_cast<size_t>(checkPositive(rows)), static_cast<size_t>(checkPositive(cols))){
    
}

Matrix::Matrix(vector<double> vals, size_t rows, size_t cols):
    rowsNum{rows}, colsNum{cols}{

    //check dimentions are legal
    if(vals.size() != rows * cols){
        throw "Invalid dimensions";
    }
    
    for(int i = 0 ; i < rows; i++){
        this->mat.push_back(vector<double> (cols));
    }
    for(size_t i = 0 ; i < rows * cols; i++){
        
        this->mat.at(i / cols).at(i % cols) = vals.at(i);
    }


}
Matrix::Matrix(const Matrix &m) // copy constructor
    :rowsNum{m.rowsNum},colsNum{m.colsNum} {
    this->mat = m.mat;    
    // std::cout<<"copy constructor called"<<std::endl;
}

//Overloaded operators (Class members)
 void Matrix::operator+=(const Matrix &rhs){
    
    if(!isSameDim(rhs)){
        throw "Invalid operation";
    }
    
    for(size_t i = 0 ;i < rowsNum; i ++){
        for (size_t j = 0; j < colsNum; j++){
            mat.at(i).at(j) += rhs.mat.at(i).at(j);
        }
        
    }
    
}

 void Matrix::operator-=(const Matrix &rhs){
    
    if(!isSameDim(rhs)){
        throw "Invalid operation";
    }
    
    for(size_t i = 0 ;i < rowsNum; i ++){
        for (size_t j = 0; j < colsNum; j++){
            mat.at(i).at(j) -= rhs.mat.at(i).at(j);
        }
        
    }
    
}

Matrix Matrix::operator+(const Matrix &rhs){
    if(!isSameDim(rhs)){
        throw "Invalid operation";
    }

    std::vector<double> res(rowsNum * colsNum);

    for(size_t i = 0 ;i < rowsNum * colsNum; i ++){
        res.at(i) = this->mat.at(i / rowsNum).at(i % colsNum) + rhs.mat.at(i / rowsNum).at(i % colsNum);
    }
    
    return Matrix {res, rowsNum, colsNum};
}

Matrix Matrix::operator-(const Matrix &rhs){
    if(!isSameDim(rhs)){
        throw "Invalid operation";
    }

    std::vector<double> res(rowsNum * colsNum);

    for(size_t i = 0 ;i < rowsNum * colsNum; i ++){
        res.at(i) = this->mat.at(i / rowsNum).at(i % colsNum) - rhs.mat.at(i / rowsNum).at(i % colsNum);
    }
    
    return Matrix {res, rowsNum, colsNum};
}

Matrix Matrix::operator-(){

    std::vector<double> res(rowsNum * colsNum);

    for(size_t i = 0 ;i < rowsNum * colsNum; i ++){
        res.at(i) = -1 * (this->mat.at(i / rowsNum).at(i % colsNum));
    }
    
    return Matrix {res, rowsNum, colsNum};

}

Matrix Matrix::operator+(){

    std::vector<double> res(rowsNum * colsNum);

    for(size_t i = 0 ;i < rowsNum * colsNum; i ++){
        res.at(i) =  +(this->mat.at(i / rowsNum).at(i % colsNum));
    }
    
    return Matrix {res, rowsNum, colsNum};

}

void Matrix:: operator--(){

    for(size_t i =0; i < rowsNum; i++){
        for (size_t k = 0 ; k < colsNum; k++){
            mat.at(i).at(k)--;
        }
    }
}

void Matrix:: operator++(){

    for(size_t i =0; i < rowsNum; i++){
        for (size_t k = 0 ; k < colsNum; k++){
            mat.at(i).at(k)++;
        }
    }
}

bool Matrix:: operator==(const Matrix &m){
    
    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return true;
    }

    for(size_t i = 0 ; i <m.rowsNum; i++){
        for (size_t j = 0; j < m.colsNum ; j++)
        {
            if(this->get(i,j) != m.get(i,j)){
                return false;
            }
        }
        
    }

    return true;
}

bool Matrix:: operator!=(const Matrix &m){
    
    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return false;
    }

    for(size_t i = 0 ; i <m.rowsNum; i++){
        for (size_t j = 0; j < m.colsNum ; j++)
        {
            if(this->get(i,j) != m.get(i,j)){
                return true;
            }
        }
        
    }

    return false;
}

bool Matrix:: operator<=(const Matrix &m){
    
    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return true;
    }
    if(this->operator==(m)){
        return true;
    }
    return sum() < m.sum();
}

bool Matrix:: operator>=(const Matrix &m){
    
    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return true;
    }

    if(this->operator==(m)){
        return true;
    }
    return sum() > m.sum();
}

bool Matrix:: operator<(const Matrix &m){
    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return true;
    }
    return sum() < m.sum();
}

bool Matrix:: operator>(const Matrix &m){

    if(!isSameDim(m)){
        throw "Invalid operation";
    }
    if(this == &m){
        return true;
    }
    return sum() > m.sum();
}

void Matrix::operator*=(double scalar){

    for(size_t i = 0; i < mat.size() ;i++){
        for(size_t j = 0 ; j < colsNum; j++){
            mat.at(i).at(j) *= scalar;
        }
    }
    
}

// Globaly overloaded operators

std::ostream & operator<<(std::ostream &os, const Matrix &m){
    
    for(size_t i = 0 ; i <m.rowsNum; i++){
        os<<"[";
        for(size_t j = 0 ; j < m.colsNum -1; j++){
            os<<m.mat.at(i).at(j)<<" ";
        }
        os<<m.mat.at(i).at(m.colsNum -1);
        os<<"]"<<std::endl;
    }
    return os;
}


Matrix operator*(double scalar, const Matrix &m){

    std::vector<double> res(m.rowsNum * m.colsNum);

    for(size_t i = 0 ;i < m.rowsNum * m.colsNum; i ++){
        res.at(i) = scalar * (m.mat.at(i / m.rowsNum).at(i % m.colsNum));
    }
    
    return Matrix {res, m.rowsNum, m.colsNum};

}

Matrix operator*(const Matrix &m, double scalar){

    std::vector<double> res(m.rowsNum * m.colsNum);

    for(size_t i = 0 ;i < m.rowsNum * m.colsNum; i ++){
        res.at(i) = scalar * (m.mat.at(i / m.rowsNum).at(i % m.colsNum));
    }
    
    return Matrix {res, m.rowsNum, m.colsNum};

}


Matrix operator*(const Matrix &m, const Matrix &m2){

    if( m.colsNum != m2.rowsNum){
        throw "Invalid operation for given dimentions";
    }
    std::vector<double> res;

    for(size_t i = 0 ; i < m.rowsNum; i++){
        for(size_t j = 0; j < m2.colsNum; j++){
            res.push_back(0);
            for(size_t k = 0; k < m.colsNum; k++){
                res.back() += m.get(i,k) * m2.get(k, j);
            }
        }
    }

    
    return Matrix {res, m.rowsNum, m.colsNum};

}

// methods

bool Matrix::isSameDim(const Matrix &b) const{
    return rowsNum == b.rowsNum && b.colsNum == colsNum;
}

double Matrix::get(size_t r, size_t c) const{
    return this->mat.at(r).at(c);
}

double Matrix:: sum() const{

    double s = 0;
    for(auto const &vec: mat){
        for(auto arg: vec){
            s += arg;
        }
    }
    return s;
}

int checkPositive(int n){

    if(n <= 0){
        throw "Invalid dimensions";
    }

    return n;
}


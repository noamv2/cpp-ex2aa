#include "Matrix.hpp"


// constructors
Matrix::Matrix(vector<double> vals, int rows, int cols):
    rowsNum{rows}, colsNum{cols}{

    //check dimentions are legal
    if( rows <= 0 || cols <= 0 || vals.size() != rows * cols ){
        throw "Illegal dimentions";
    }

    for(int i = 0 ; i < rows; i++){
        this->mat.push_back(vector<double> (cols));
    }
    for(size_t i = 0 ; i < rows * cols; i++){
        
        this->mat.at(i / rows).at(i % cols) = vals.at(i);
    }


}
Matrix::Matrix(const Matrix &m)
    :rowsNum{m.rowsNum},colsNum{m.colsNum} {
    this->mat = m.mat;    
    std::cout<<"copy constructor called"<<std::endl;
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

    for(int i =0; i < rowsNum; i++){
        for (int k = 0 ; k < colsNum; k++){
            mat.at(i).at(k)--;
        }
    }
}

void Matrix:: operator++(){

    for(int i =0; i < rowsNum; i++){
        for (int k = 0 ; k < colsNum; k++){
            mat.at(i).at(k)++;
        }
    }
}

bool Matrix:: operator==(const Matrix &m){

    if(this == &m){
        return true;
    }
    for(int i = 0 ; i <m.rowsNum; i++){
        for (int j = 0; j < m.colsNum ; j++)
        {
            if(this->get(i,j) != m.get(i,j)){
                return false;
            }
        }
        
    }

    return true;
}

bool Matrix:: operator!=(const Matrix &m){

    if(this == &m){
        return false;
    }
    for(int i = 0 ; i <m.rowsNum; i++){
        for (int j = 0; j < m.colsNum ; j++)
        {
            if(this->get(i,j) != m.get(i,j)){
                return true;
            }
        }
        
    }

    return false;
}

bool Matrix:: operator<=(const Matrix &m){

    if(this == &m){
        return true;
    }
    return sum() <= m.sum();
}

bool Matrix:: operator>=(const Matrix &m){

    if(this == &m){
        return true;
    }
    return sum() >= m.sum();
}

bool Matrix:: operator<(const Matrix &m){

    if(this == &m){
        return true;
    }
    return sum() < m.sum();
}

bool Matrix:: operator>(const Matrix &m){

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
    std::vector<double> res(m.rowsNum * m.colsNum);

    for(size_t i = 0 ;i < m.rowsNum * m.colsNum; i ++){
        res.at(i) = (m2.mat.at(i / m2.rowsNum).at(i % m2.colsNum)) * (m.mat.at(i / m.rowsNum).at(i % m.colsNum));
    }
    
    return Matrix {res, m.rowsNum, m.colsNum};

}

// methods

bool Matrix::isSameDim(const Matrix &b) const{
    return rowsNum == b.rowsNum && b.colsNum == colsNum;
}

double Matrix::get(int r, int c) const{
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
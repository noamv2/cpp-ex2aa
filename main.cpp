#include "Matrix.hpp"

int main(){

    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> ridentity = {0, 0, 1, 0, 1, 0, 1, 0, 0};
    Matrix m {identity, 3, 3};
    Matrix m2 {ridentity, 3, 3};
    // m+= m2;
    std::cout<<(m2 * m);
    std::cout<<(m <= m);

    

    return 0;
}
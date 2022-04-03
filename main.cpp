#include "Matrix.hpp"

int main(){

    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> ridentity = {0, 0, 1, 0, 1, 0, 1, 0, 0};

    std::vector<double> v1 = {3, -8, 2, -5};
    std::vector<double> inverse_v1 = {-5, 8, -2, 3};
    std::vector<double> identity2_2 = {1, 0, 0, 1};
    Matrix m1 {v1, 2, 2};
    Matrix m1Inverse {inverse_v1, 2, 2};
    Matrix ID2 {identity2_2 , 2, 2};
    std::cout<<m1<<m1Inverse;
    std::cout<<(m1 * m1Inverse);



    return 0;
}
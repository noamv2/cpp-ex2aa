#include "doctest.h"
#include "Matrix.hpp"


std::vector<double> identity3_3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> identity2_2 = {1, 0, 0, 1};
std::vector<double> vec9 = {1, 2, 3, 4, 5, 6.3, 7, 8, 9};
std::vector<double> vec8 = {-1.1, 32.6, 13.7, 4, -45.1, 26, 77.3, 8};
std::vector<double> vec15 = {-1.1, 32.6, 13.7, 4, -45.1, 26, 77.3, 8,-9.3,0.10,-911, -12 ,143, 0.14, 5};
std::vector<double> vec15_2 = {-1.1, 32.6, 13.7, 4, -45.1, 26, 77.3, 8,-9.3,0.10,-1, -12 ,143, 0.14, 5};
std::vector<double> vec9_2 = {3, 0, 0, 0, 0, 0, 0, 0, 0};

Matrix Mat15(vec15, 5, 3);
Matrix Mat15_2(vec15_2, 5, 3);
Matrix Mat8(vec8, 4, 2);
Matrix Mat9(vec9, 3, 3);
Matrix Mat9_2(vec9_2, 3, 3);
Matrix IMAT(identity3_3, 3, 3);

TEST_CASE("Constructing - invalid input"){


    SUBCASE("non positive dimensions"){
        CHECK_THROWS((Matrix {identity3_3, -3 , 5}));
        CHECK_THROWS((Matrix {identity3_3, 3 , -3}));
        CHECK_THROWS((Matrix {identity3_3, -3 , -3}));
        CHECK_THROWS((Matrix {identity3_3, 3 , 0}));
        CHECK_THROWS((Matrix {identity3_3, 0 , 0}));
    }

    SUBCASE("Mismatch between dimensions and the number of values"){
        CHECK_THROWS((Matrix {identity3_3, 3 , 5}));
        CHECK_THROWS((Matrix {identity3_3, 1 , 5}));
        CHECK_THROWS((Matrix {identity2_2, 3 , 5}));
        CHECK_THROWS((Matrix {identity2_2, 3 , 1}));
        CHECK_THROWS((Matrix {vec9, 31 , 1}));
        CHECK_THROWS((Matrix {vec9, 10 , 5}));
        CHECK_THROWS((Matrix {vec8, 1 , 5}));
        CHECK_THROWS((Matrix {vec8, 3 , 5}));
    }
    
}


TEST_CASE("Constructing - Valid input"){    
        CHECK_NOTHROW((Matrix {identity3_3, 3 , 3}));
        CHECK_NOTHROW((Matrix {identity3_3, 9 , 1}));
        CHECK_NOTHROW((Matrix {identity3_3, 1 , 9}));
        CHECK_NOTHROW((Matrix {identity2_2, 1 , 4}));
        CHECK_NOTHROW((Matrix {identity2_2, 4 , 1}));
        CHECK_NOTHROW((Matrix {identity2_2, 2 , 2}));

        CHECK_NOTHROW((Matrix {vec8, 8 , 1}));
        CHECK_NOTHROW((Matrix {vec8, 4 , 2}));
        CHECK_NOTHROW((Matrix {vec8, 2 , 4}));
        CHECK_NOTHROW((Matrix {vec8, 1 , 8}));

        CHECK_NOTHROW((Matrix {vec15, 1 , 15}));
        CHECK_NOTHROW((Matrix {vec15, 5 , 3}));
}

TEST_CASE("Comparsions operators"){

    SUBCASE("Matrices with wrong dimensions"){
        CHECK_THROWS(std::cout<<(Mat15 == Mat9));
        CHECK_THROWS(std::cout<<(Mat8 == Mat9));
        CHECK_THROWS(std::cout<<(IMAT == Mat8));
        CHECK_THROWS(std::cout<<(IMAT == Mat15));
        CHECK_THROWS(std::cout<<(Mat15 <= Mat9));
        CHECK_THROWS(std::cout<<(Mat8 > Mat9));
        CHECK_THROWS(std::cout<<(IMAT <= Mat8));
        CHECK_THROWS(std::cout<<(IMAT >= Mat15));
        CHECK_THROWS(std::cout<<(Mat15 < Mat9));
        CHECK_THROWS(std::cout<<(Mat8 != Mat9));
        CHECK_THROWS(std::cout<<(IMAT != Mat8));
        CHECK_THROWS(std::cout<<(IMAT >= Mat15));
    }

    SUBCASE("False comparsions"){
        CHECK_FALSE((Mat15_2 == Mat15));
        CHECK_FALSE((Mat9_2 == Mat9));

        CHECK_FALSE((Mat9_2 >= Mat9));
        CHECK_FALSE((Mat15_2 <= Mat15));
        CHECK_FALSE((Mat9_2 > Mat9));
        CHECK_FALSE((Mat15_2 < Mat15));
    }

    SUBCASE("Truth comparsions"){
        CHECK((Matrix{Mat15} == Mat15)); // uses the copy constructor
        CHECK((Matrix{Mat9} == Mat9));

        CHECK((Mat15_2 != Mat15));
        CHECK((Mat9_2 != Mat9));
        
        CHECK((Mat9_2 <= Mat9));
        CHECK((Mat15_2 >= Mat15));
        CHECK((Mat9_2 < Mat9));
        CHECK((Mat15_2 > Mat15));
    }

}

TEST_CASE("Addition and substraction operators"){

    SUBCASE("Matrices with wrong dimensions"){
        CHECK_THROWS((Mat15 + Mat9));
        CHECK_THROWS((Mat8 + Mat9));
        CHECK_THROWS((IMAT - Mat8));
        CHECK_THROWS((IMAT - Mat15));
        CHECK_THROWS((Mat15 - Mat9));
        CHECK_THROWS(IMAT -= Mat8);
        CHECK_THROWS((IMAT += Mat8));
 
    }

    SUBCASE("False comparsions"){
        CHECK_FALSE(((Mat9_2 + Mat9) == Mat9 ));
        CHECK_FALSE(((Mat9_2 + Mat9) == IMAT ));
        CHECK_FALSE(((Mat15_2 + Mat15) == Mat15 ));
    }

    SUBCASE("Truth comparsions"){
        CHECK((Mat15_2 != Mat15));
        CHECK((Mat9_2 != Mat9));

        CHECK((Mat9_2 <= Mat9));
        CHECK((Mat15_2 >= Mat15));
        CHECK((Mat9_2 < Mat9));
        CHECK((Mat15_2 > Mat15));
    }

}

TEST_CASE("Mult operators"){
    
    std::vector<double> v2 = {-27, 0, 0, 0, 0, 0, 0, 0, 0};


    SUBCASE("Matrices with wrong dimensions"){
        
        CHECK_THROWS((Mat8 * Mat9));
        CHECK_THROWS((IMAT * Mat8));
    }

    SUBCASE("False comparsions"){
        CHECK_FALSE(((Mat9_2 + Mat9) == Mat9 ));
        CHECK_FALSE(((Mat9_2 + Mat9) == IMAT ));
        CHECK_FALSE(((Mat15_2 + Mat15) == Mat15 ));
    }

    SUBCASE("Truth comparsions"){
        CHECK((((Mat9_2 * -9) == (-9 * Mat9_2))) );
        CHECK((((Mat9_2 * -9) == (Matrix{v2,3, 3}))));
    }
    
}

TEST_CASE("Compound equations"){
    std::vector<double> v1 = {3, -8, 2, -5};
    std::vector<double> inverse_v1 = {-5, 8, -2, 3};
    std::vector<double> identity2_2 = {1, 0, 0, 1};
    Matrix m1 {v1, 2, 2};
    Matrix m1Inverse {inverse_v1, 2, 2};
    Matrix ID2 {identity2_2 , 2, 2};

    CHECK(((m1 * m1Inverse) == ID2));
    CHECK((((m1 * m1Inverse) + ID2) == 2 * ID2));

}

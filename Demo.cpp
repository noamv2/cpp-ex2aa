/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"


int main() {
  
  std::vector<double> identity = {1, 0, 0, 1};
  std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  std::vector<double> Mat1_3X3 = {1, 2, 3, 4, 5, 6.3, 7, 8, 9};
  std::vector<double> Mat2_4X2 = {-1.1, 32.6, 13.7, 4, -45.1, 26, 77.3, 8};
  Matrix a{Mat2_4X2, 4, 2};  // constructor taking a vector and a matrix size
  cout << a << endl;
  /* prints [1 0 0]
            [0 1 0]
            [0 0 1]*/

  cout << (-a) << endl;
  /* prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]*/
  cout << (3*a) << endl;
  /* prints [3 0 0]
            [0 3 0]
            [0 0 3]*/

  // Matrix b{arr, 3, 3};
  // a *= -3;
  // cout << (a+b) << endl;  // prints the 0 matrix
  // cout << (b-a) << endl;
  /* prints [6 0 0]
            [0 6 0]
            [0 0 6]*/

  cout << "End of demo!" << endl;
  return 0;
}


#ifndef Transformation_hpp
#define Transformation_hpp
#include <cmath>
#include <iostream>
#include <vector>

const int SIZE = 3;
const double Pi = 3.14159265;
using point = double;
using vector = std::vector<point>;
double Input_angle();
vector Input_vector();
vector Velocity_to_bound(const vector& velo_vec, double trans_matr[SIZE][SIZE]);
void Input_matrix(double trans_matr[SIZE][SIZE],
                  double Attack_angle,
                  double Slip_angle);
void Show_vec(const vector& vector);
void Zero_matrix(double trans_matr[SIZE][SIZE]);
void foo();
#endif

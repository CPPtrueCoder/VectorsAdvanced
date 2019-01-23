#include "Transformation.hpp"
#include <cstring>
void foo() {
  double Attack_angle = Input_angle() * Pi / 180;
  double Slip_angle = Input_angle() * Pi / 180;
  double trans_matr[SIZE][SIZE];
  // Zero_matrix(trans_matr);
  memset(trans_matr, 0, sizeof(trans_matr));
  vector velo_vec = Input_vector();
  Input_matrix(trans_matr, Attack_angle, Slip_angle);
  vector bound_vec = Velocity_to_bound(velo_vec, trans_matr);
  Show_vec(bound_vec);
}
double Input_angle() {
  std::cout << "Get the Attack angle and Slip angle ";
  double angle = 0.0;
  using std::cin;
  using std::cout;

  while (true) {
    if (cin >> angle) {
      return angle;
    } else {
      cout << " Bad value , input no symbols" << std::endl;
      cin.clear();
      cin.get();
      continue;
    }
  }
}
vector Input_vector() {
  std::cout << " Get the coordinates of vector: ";
  vector your_vector;
  for (int line = 0; line < SIZE; ++line) {
    double time_x = 0.0;
    std::cin >> time_x;
    your_vector.push_back(time_x);
  }
  return your_vector;
}
vector Velocity_to_bound(const vector& velo_vec,
                         double trans_matr[SIZE][SIZE]) {
  vector bound_vec(SIZE);
  for (unsigned long line = 0; line < SIZE; ++line) {
    for (unsigned long col = 0; col < SIZE; ++col) {
      bound_vec[line] += trans_matr[line][col] * velo_vec[col];
    }
  }
  return bound_vec;
}

void Show_vec(const vector& vector) {
  for (auto coordinate : vector) std::cout << coordinate << std::endl;
}
void Input_matrix(double trans_matr[SIZE][SIZE],
                  double Attack_angle,
                  double Slip_angle) {
  trans_matr[0][0] = cos(Attack_angle) * cos(Slip_angle);
  trans_matr[0][1] = sin(Attack_angle);
  trans_matr[0][2] = -cos(Attack_angle) * sin(Slip_angle);
  trans_matr[1][0] = -sin(Attack_angle) * cos(Slip_angle);
  trans_matr[1][1] = cos(Attack_angle);
  trans_matr[1][2] = sin(Attack_angle) * sin(Slip_angle);
  trans_matr[2][0] = sin(Slip_angle);
  trans_matr[2][1] = 0.0;
  trans_matr[2][2] = cos(Slip_angle);
}
void Zero_matrix(double trans_matr[SIZE][SIZE]) {
  for (int line = 0; line < SIZE; ++line) {
    for (int col = 0; col < SIZE; ++line) {
      trans_matr[line][col] = 0.0;
    }
  }
}

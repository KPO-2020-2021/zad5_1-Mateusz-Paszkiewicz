#pragma once

#include"matrix.hh"

class Prism{
private:
  double point[12][3];
  Vector3 Prism_Position;
  
public:

  Prism();

  Prism(double [12][3]);

  Prism operator * (Matrix3x3 &);

  Prism operator + (Vector3 &);

  const double &operator () (unsigned int, unsigned int) const;

  double &operator () (unsigned int, unsigned int);

  Prism AngleTrans(double Angle, char axis);

};

std::ostream &operator<<(std::ostream &out, Prism &prism);

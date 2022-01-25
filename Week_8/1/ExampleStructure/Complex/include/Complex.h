/**************************************************************************
 *  $Id$
 *  File:	Complex.h - Definition file for Complex
 *
 *  Purpose:	
 *
 *  Author:	
 *************************************************************************/
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <math.h>
using namespace std;
class Complex {
  float real, imag;
  public :
  Complex();
  Complex (float re, float im);
  Complex  operator+ (Complex num);
  Complex  operator- (Complex num);
  Complex operator* (Complex num);
  Complex operator/ (Complex num);
  Complex operator/ (float num);
  double aimag(Complex num);
  double areal(Complex num);
  void assign(double r,double i);
  void print();
};
#endif

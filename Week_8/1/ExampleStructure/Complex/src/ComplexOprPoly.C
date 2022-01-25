/*-------------------------------------------------------------------------
 *  ComplexOprPoly.C - Implements Complex arithmetic using operator
                       Polymorphism
 *  Version:	$Name$
 *  Module:	
 *
 *  Purpose:	
 *  See:	
 *
 *  Author:	Hema A Murthy (hema@localhost.localdomain)
 *
 *  Created:        Sat 09-Dec-2000 18:50:01
 *  Last modified:  Wed 02-Sep-2020 11:17:33 by hema
 *  $Id$
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 -------------------------------------------------------------------------*/
 

#include <iostream>
#include <math.h>
#include "../include/Complex.h"
using namespace std;

  Complex::Complex() {}
  Complex:: Complex (float re, float im) {
    real = re;
    imag = im;
  }
  Complex Complex::  operator+ (Complex num)
  {
    Complex Value;
    Value.real = real + num.real;
    Value.imag = imag + num.imag;
    return(Value);
  }
  Complex Complex::  operator- (Complex num)
  {
    Complex Value;
    Value.real = real - num.real;
    Value.imag = imag - num.imag;
    return(Value);
  }
  Complex Complex:: operator* (Complex num)
  {
    Complex Value;
    Value.real = real*num.real - imag*num.imag;
    Value.imag = imag*num.real + real*num.imag;
    return(Value);
  }
Complex Complex:: operator/ (Complex num) 
  {
    Complex Value;
    float magnitude;
    magnitude = num.real*num.real + num.imag*num.imag;
    Value.real = (real*num.real + imag*num.imag)/magnitude;
    Value.imag = (imag*num.real - real*num.imag)/magnitude; 
    return(Value);
  }
Complex  Complex:: operator/ (float num)
  {
    Complex Value;
    Value.real = real/num;
    Value.imag = imag/num;
    return(Value);
  }
double Complex:: aimag(Complex num)
  {
    return(num.imag);
  }
double Complex:: areal(Complex  num)
  {
    return (num.real);
  }
void Complex:: assign(double r,double i)
  {
    real = r;
    imag = i;
  }
void Complex:: print() {cout << real << "+i" << imag <<"\n";}



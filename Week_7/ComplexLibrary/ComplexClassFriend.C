#include <iostream>
#include <math.h>
using namespace std;
 int expon(int M, int num)
 {
  int Value;
  int N;
  Value = 1;
  for (N = 1; N <= num; N++)
    Value = Value*M;
  return(Value);
}

class complex {
  float real,imag;
public :
  complex (float rPart, float iPart) {
    real = rPart;
    imag = iPart;
  }
  complex () {
    real = 0.0;
    imag = 0.0;
  }
  ~complex () { }
  complex & operator = (complex num)
    {
      real = num.real;
      imag = num.imag;
      return(*this);
    }
  double aimag(complex num)
    {
      return(num.imag);
    }
  double areal(complex num)
    {
      return (num.real);
    }
  void assign(float r,float i)
    {
      real = r;
      imag = i;
    }
  void print() {cout << real << "+i" << imag <<"\n";}
  void print(char *s) {cout << s;}
private:
  friend complex  operator+ (complex num1, complex num2);
  friend complex  operator- (complex num1, complex num2);
  friend complex operator* (complex num1, complex num2);
  friend complex operator/ (complex num1, complex num2); 
  
};
 complex  operator+ (complex num1, complex num2)
  {
   complex Value;
   Value.real = num1.real + num2.real;
   Value.imag = num1.imag + num2.imag;
   return(Value);
   }
complex  operator- (complex num1, complex num2)
{
  complex Value;
  Value.real = num1.real - num2.real;
  Value.imag = num1.imag - num2.imag;
  return(Value);
}
complex operator* (complex num1, complex num2)
{
  complex Value;
  cout << "inside product" << endl;
  num1.print();
  num2.print();
  Value.real = num1.real*num2.real - num1.imag*num2.imag;
  Value.imag = num1.imag*num2.real + num1.real*num2.imag;
  cout << "computed value " << endl;
  Value.print();
  return(Value);
}
complex operator/ (complex num1, complex num2) 
{
  complex Value;
  float magnitude;
  magnitude = num2.real*num2.real + num2.imag*num2.imag;
  Value.real = (num1.real*num2.real + num1.imag*num2.imag)/magnitude;
  Value.imag = (num1.imag*num2.real - num1.real*num2.imag)/magnitude; 
  return(Value);
}

main()
{
complex A[4],B[4],C[4];
int i;
A[1].assign(1.0,0.0);
A[2].assign(1.0,0.0);
A[3].assign(0.0,0.0);
B[1].assign(5.0,2.0);
B[2].assign(2.5,3.5);
 for (i=1; i < 2; i++) {
   cout << "print A" << i << endl;
   A[i].print();
   cout << "print B" << i << endl;
   B[i].print();
  C[i] = A[i]*B[i];
  C[i].print();
 }
}







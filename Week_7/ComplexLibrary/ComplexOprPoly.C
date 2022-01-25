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
using namespace std;

class Complex {
  float real,imag;
public :
  Complex() {
  }
  Complex (float re, float im) {
    real = re;
    imag = im;
  }
  Complex  operator+ (Complex num)
  {
    Complex Value;
    Value.real = real + num.real;
    Value.imag = imag + num.imag;
    return(Value);
  }
  Complex  operator- (Complex num)
  {
    Complex Value;
    Value.real = real - num.real;
    Value.imag = imag - num.imag;
    return(Value);
  }
  Complex operator* (Complex num)
  {
    Complex Value;
    Value.real = real*num.real - imag*num.imag;
    Value.imag = imag*num.real + real*num.imag;
    return(Value);
  }
  Complex operator/ (Complex num) 
  {
    Complex Value;
    float magnitude;
    magnitude = num.real*num.real + num.imag*num.imag;
    Value.real = (real*num.real + imag*num.imag)/magnitude;
    Value.imag = (imag*num.real - real*num.imag)/magnitude; 
    return(Value);
  }
  Complex operator/ (float num)
  {
    Complex Value;
    Value.real = real/num;
    Value.imag = imag/num;
    return(Value);
  }
  double aimag(Complex num)
  {
    return(num.imag);
  }
  double areal(Complex num)
  {
    return (num.real);
  }
  void assign(double r,double i)
  {
    real = r;
    imag = i;
  }
  void print() {cout << real << "+i" << imag <<"\n";}
};

/*-------------------------------------------------------------------------
 *  main -- Main Program for Complex
 *    Args:	none
 *    Returns:	int
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
int main()
{
  Complex a(0.5,0.5), b(2.5,2.5), c(0.0,0.0), d;
 int x, y, z;
 c = a + b;
 x = 4;
 y = 6;
 z = x + y;
 c.print();
 cout << "zsum = " << z << endl;
 d = a*b;
 d.print();
 return 0;
}	/*  End of main		End of main   */



/*-------------------------------------------------------------------------
 * $Log$
 *
 * Local Variables:
 * time-stamp-active: t
 * time-stamp-line-limit: 20
 * time-stamp-start: "Last modified:[ 	]+"
 * time-stamp-format: "%3a %02d-%3b-%:y %02H:%02M:%02S by %u"
 * time-stamp-end: "$"
 * End:
 *                        End of ComplexOprPoly.C
 -------------------------------------------------------------------------*/

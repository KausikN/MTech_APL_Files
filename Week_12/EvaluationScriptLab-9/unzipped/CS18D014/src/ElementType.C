#include "ElementType.h"
void Print (ElementType x) {
  cout << x.coefft << "x^" << x.degree << " +";
}
int Compare (ElementType x, ElementType y) {
  if (x.degree == y.degree)
    return 1;
  else
    return 0;
}
 

#include <stdio.h>
#include <math.h>

int PrimeTest(int number);
void TwinPrimes (int range1, int range2);
/* Complete the above two functions*/

int PrimeTest(int number){
    /* Checks if a number is prime and returns 1 if prime, 0 if not prime */
    
    // Check if number is 1
    if (number == 1){
        return 0;
    }
    
    // Check if even
    if ((number % 2) == 0){
        return 0;
    }
    
    // For odd number n, check if divisible by any number from [3, sqroot(n)]
    int     rootN = (int) sqrt(number);
    int     i = 3;
    
    while(i <= rootN){
        if ((number % i) == 0){
            return 0;
        }
        i++;
    }
    
    // If doesnt fall under any above conditions, it is prime
    return 1;
}

void TwinPrimes (int range1, int range2){
    /* Takes two integers that indicate a range and prints aLL the twin primes in that range (both numbers inclusive) */
    
    // Check if range1 > range2 - if so, swap both
    if (range1 > range2){
        int     temp = range1;
        range1 = range2;
        range2 = temp;
    }
    
    // Check if range1 = range2 or if range1 and range2 are consequetive - no odd number pairs in range
    if ((range2 - range1) <= 1){
        printf("(# #)");
    }
    
    // If range1 is even, change it to next odd number - since all coprimes are odd
    if (range1 % 2 == 0){
        range1++;
    }
    
    // Check if coprime
    int     coprimeFound = 0;
    int     firstNum = range1;
    int     secondNum = firstNum + 2;
    int     firstNumPrime = PrimeTest(firstNum);
    int     secondNumPrime = 0;
    
    while(firstNum <= range2 - 2){
        // Check if both are prime
        secondNumPrime = PrimeTest(secondNum);
        
        if (firstNumPrime == 1 && secondNumPrime == 1){
            // Coprimes
            printf("(%d %d)", firstNum, secondNum);
            coprimeFound = 1;
        }
        firstNum += 2;
        secondNum += 2;
        firstNumPrime = secondNumPrime;
    }
    
    // Check if no coprimes
    if (coprimeFound == 0){
        printf("(# #)");
    }
}

// Main Function
int main() 
{
	int range1, range2;
	scanf ("%d %d", &range1, &range2);
	TwinPrimes (range1, range2);
	return 0;
}
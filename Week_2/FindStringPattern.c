#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    char    T[100];
    char    P[100];
    
    // Load Inputs
    scanf("%s", T);
    scanf("%s", P);
    
    // Search where P is a substring of T
    int     patternFound = 0;
    int     curIndexT = 0;
    int     curIndexP = 0;
    
    while(curIndexT < (strlen(T) - strlen(P) + 1)){
        // Check if curIndex charecter is matching for P and T
        if (T[curIndexT + curIndexP] == P[curIndexP]){
            curIndexP++;
            // Check if this is final char in P - if so, P is in T at curIndexT
            if (curIndexP == strlen(P)){
                printf("%d ", curIndexT);
                
                // Reset for next charecter in T
                curIndexT++;
                curIndexP = 0;
                patternFound = 1;
            }
        }
        else{
            // Reset for next charecter in T
            curIndexT++;
            curIndexP = 0;
        }
    }
    
    // Check if pattern not found
    if (patternFound == 0){
        printf("-1");
    }
    
    return 0;
}
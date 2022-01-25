#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    char    message[100];
    char    cipher[26];
    char    encryptedMessage[100] = "";
    
    int     a = (int)'a';
    int     checkDuplicate[256] = {0};
    
    // Load Inputs
    scanf("%s %s", message, cipher);

    // Check for duplicates in cipher
    int     duplicatesExist = 0;
    int     i = 0;
    
    while(i < strlen(cipher)){
        if (checkDuplicate[(int)cipher[i]] == 1){
            duplicatesExist = 1;
            break;
        }
        else{
            checkDuplicate[(int)cipher[i]] = 1;
        }
        i += 1;
    }
    if (duplicatesExist == 1){
        printf("INVALID CIPHER");
        return 0;
    }
    
    // Encrypt based on cipher
    i = 0;
    
    while(i < strlen(message)){
        encryptedMessage[i] = cipher[(int)message[i] - a];
        i += 1;
    }
    
    // Print Output
    printf("%s", encryptedMessage);
    
    return 0;
}
/************************************************
 * Program          : Problem2.c
 * Purpose          : Find number of occurences of a target word in a file
 * Input            : Input file path, Target Word
 * Output           : Output file
 * Uses             : GetWordFrequencyInFile - A function to get frequency of a word in a file (case insensitive)
 *                    ConvertLowerCase - A function to convert a charecter to lowercase
************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100

/*******************************************************************
*
* ConvertLowerCase: Convert a charecter to lowercase
* inputChar is the charecter to be converted
*
* Returns: input charecter in lowercase
*
* Method: convert to lowercase if charecter is uppercase by subtracting ascii by 32
*
********************************************************************/
char ConvertLowerCase(char inputChar)
{
    // Convert charecter to lowercase if it is uppercase
    if ((int)(inputChar) >= (int)('A') && (int)(inputChar) <= (int)('Z'))
    {
        inputChar = inputChar + 32;
    }

    return inputChar;
}

/*******************************************************************
*
* GetWordFrequencyInFile: Get the frequency of a target word in a file
* filePath is the path of input file
* targetWord is the target word to be searched
* targetWordSize is the length of target word
*
* Returns: frequency of target word in a file
*
* Method: Open and check if file exists at filePath
*         Read charecter by charecter in file and convert to lowercase
*         If charecter is a separator, mark as new word and terminate the current word
*         If charecter is a letter, check if it matches the checkIndex of targetWord if match, increment checkIndex
*         If not match, reset checkIndex to 0 and wait till we get a separator to start checking for next word
*         If matched char count checkIndex becomes same as size of targetWord, mark that word is found
*         Check the next char, if it is a separator, increase frequency of targetWord, if not separator, reset checkIndex as it is substring
*
********************************************************************/
int GetWordFrequencyInFile(char* filePath, char* targetWord, int targetWordSize)
{
    FILE*       file;
    char*       fileContents;
    int         frequency = 0;

    // Convert targetWord to lowercase
    for (int i = 0; i < targetWordSize; i++)
    {
        targetWord[i] = ConvertLowerCase(targetWord[i]);
    }

    file = fopen(filePath, "r");                                        // Open file

    if (file == NULL)                                                   // Check if file exists in path
    {
        return -1;
    }

    // Read file contents
    char        c;
    int         checkIndex = 0;
    int         continueCheck = 1;
    while((c = fgetc(file)) != EOF)
    {
        c = ConvertLowerCase(c);                                        // Convert charecter to lowercase

        if (continueCheck == 2                                          // If already matched and current charecter is space or newline, increment frequency
            && (c == ' ' || c == '\n' || c == '!' || c == '.' || c == '"' 
                || c == '(' || c == ')' || c == ',' || c == '?' || c == '\''))
        {
            frequency++;
        }
        else if (continueCheck == 2)                                    // If matched and current charecter is not space or newline then matched word is a substring
        {
            continueCheck = 0;
            checkIndex = 0;
        }

        if (c == ' ' || c == '\n' || c == '!' || c == '.' || c == '"' || c == '(' 
                || c == ')' || c == ',' || c == '?' || c == '\'')      // If charecter is space or newline, reset checkIndex and continueCheck
        {
            checkIndex = 0;
            continueCheck = 1;
        }
        else if (c == targetWord[checkIndex] && continueCheck == 1)    // If charecter matches target word checkIndex charecter, increment checkIndex
        {
            checkIndex++;
        }
        else                                                           // If charecter doesnt match target word, reset checkIndex and continueCheck
        {
            continueCheck = 0;
            checkIndex = 0;
        }

        if (checkIndex == targetWordSize)                              // If checkIndex matches target word size, flag as matched
        {
            continueCheck = 2;
        }
    }

    fclose(file);

    return frequency;
}

int main(int argc, char* argv[])
{
    char*       inputfilePath;
    char        targetWord [MAX_WORD_LENGTH];
    int         targetWordSize = 0;
    char*       outputfilePath;

    if (argc != 4)                                      // Check if 1 + 3 arguments are passed
    {
        return 1;
    }

    inputfilePath     = argv[1];                         // Get input file path
    outputfilePath    = argv[3];                         // Get Output file path

    while (argv[2][targetWordSize] != '\0' && targetWordSize < MAX_WORD_LENGTH)    // Get target word and size
    {
        targetWord[targetWordSize] = argv[2][targetWordSize];
        targetWordSize++;
    }
    targetWord[targetWordSize] = '\0';

    // Get frequency of target word in input file
    int wordFrequency = GetWordFrequencyInFile(inputfilePath, targetWord, targetWordSize);

    // Save frequency in output file
    FILE* outputFile = fopen(outputfilePath, "w");

    fprintf(outputFile, "Frequency of %s : %d", targetWord, wordFrequency);

    fclose(outputFile);

    return 0;
}
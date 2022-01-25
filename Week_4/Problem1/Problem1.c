/************************************************
 * Program          : Problem1.c
 * Purpose          : Merges two files into one 
 *                    after converting all charecters to lowercase
 * Input            : Input file 1, Input file 2
 * Output           : Output file
 * Uses             : ReadFileLowercase - A function to read all the charecters from a file and convert them to lowercase
 *                    ConvertLowerCase - A function to convert a charecter to lowercase
************************************************/

#include <stdio.h>
#include <stdlib.h>

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
* ReadFileLowercase: Read all the charecters from a file and convert to lowercase
* filePath is path to the file
*
* Returns: file contents as lowercase string (char array)
*
* Method: Open and check if file exists at filePath and read all charecters in it, convert to lowercase and return as char array
*
********************************************************************/
char* ReadFileLowercase(char* filePath)
{
    FILE*       file;
    char*       fileContents;
    int         fileSize;

    file = fopen(filePath, "r");                    // Open file

    if (file == NULL)                               // Check if file exists in path
    {
        return NULL;
    }

    fileSize = 0;                                   // Init file size to 0
    while(fgetc(file) != EOF)
    {
        fileSize++;
    }
    rewind(file);                                   // Rewind the file pointing charecter to beginning of file again

    fileContents = (char*) malloc(fileSize + 1);    // Allocate memory for file charecters

    // Read file contents
    char        c;
    int         i = 0;
    while((c = fgetc(file)) != EOF)
    {
        fileContents[i] = ConvertLowerCase(c);      // Convert charecter to lowercase and append to fileContents
        i++;
    }

    fclose(file);

    return fileContents;
}

int main(int argc, char* argv[])
{
    char*       inputfilePath1;
    char*       inputfilePath2;
    char*       outputfilePath;

    if (argc != 4)                                   // Check if 1 + 3 arguments are passed
    {
        return 1;
    }

    inputfilePath1 = argv[1];                        // Get input file path 1
    inputfilePath2 = argv[2];                        // Get input file path 2
    outputfilePath = argv[3];                        // Get Output file path

    // Read lowercase contents of input files
    char* inputFileContents1 = ReadFileLowercase(inputfilePath1);
    char* inputFileContents2 = ReadFileLowercase(inputfilePath2);

    // Save merged file contents in output file
    FILE* outputFile = fopen(outputfilePath, "w");

    fprintf(outputFile, "%s", inputFileContents1);
    fprintf(outputFile, " %s", inputFileContents2);   // Add space between two files (" %s")

    fclose(outputFile);

    return 0;
}
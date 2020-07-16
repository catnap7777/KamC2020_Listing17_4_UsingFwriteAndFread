
//Listing 17.4 Using fwrite and fread to direct file access - MUST USE BINARY MODE; page 433

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void)
{
    int count, array1[SIZE], array2[SIZE];
    FILE *fp;
    //initialize array1
    for(count=0; count<SIZE; count++)
    {
        array1[count]= 2*count;
    }
    //open a binary mode file

    if((fp = fopen("kamdirect.txt","wb")) == NULL)
    {
        fprintf(stderr, "Error opening file...");
        exit(1);
    }
    //save array1 to the file
    if(fwrite(array1, sizeof(int), SIZE, fp) != SIZE)
    {
        fprintf(stderr, "Error writing to file...");
        exit(1);
    }

    fclose(fp);
    //now open the same file for reading in binary mode

    if((fp = fopen("kamdirect.txt","rb")) == NULL)
    {
        fprintf(stderr, "Error opening file...");
        exit(1);
    }

    //read the data into array2
    if(fread(array2, sizeof(int), SIZE, fp) != SIZE)
    {
        fprintf(stderr, "Error reading file...");
        exit(1);
    }

    fclose(fp);

    //now display both arrays
    for(count=0; count< SIZE; count++)
    {
        printf("%d\t%d\n", array1[count],array2[count]);
    }
    return 0;

}

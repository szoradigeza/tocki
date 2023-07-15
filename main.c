#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void resetRowSumHelper(char* array,int size)
{
    int index = 0;
    while(index < size)
    {
        *array = '-';
        array++;
        index++;
    }
}

int Piramify(char* input, int numRows, char* output)
{
    const int numCols = strlen(input);
    const int modulusVal = ((numRows - 1) * 2);
    char input2[numCols];
    int loops=0,rowSumIndex=0,rowSum=0,outputIndex = 0;
    char* tempArray;
    int rowSumQuantity = (numCols/numRows)+1;
    char rowSumHelper[rowSumQuantity];

    //printf("array size: %d\n",numCols);
    for(int i=0;i<numCols;i++)
    {
        input2[i] = *input;
        input++;
    }
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            int modCol = (col % modulusVal);
            if (modCol >= numRows)
            {
                modCol -= numRows;
                modCol = ((numRows - 1) - (modCol + 1));
            }

            if (modCol == row)
            {
                //printf("%c",input2[col]);
                rowSumHelper[rowSumIndex] = input2[col];
                rowSumIndex++;
                output[outputIndex] = input2[col];
            }
            else
            {
                output[outputIndex] = ' ';
                //printf(" ");
            }
            outputIndex++;
        }
        rowSumIndex = 0;
        rowSum += atoi(rowSumHelper);
        resetRowSumHelper(rowSumHelper,rowSumQuantity);
        //printf("\n");
        output[outputIndex] = '\n';
        outputIndex++; /*increase to not overwrite the new line*/
    }
    //printf("rowSum : %d\n",rowSum);

    /*
    for(int i = 0; i < outputIndex; i++)
    {
        printf("%c",output[i]);
    }
    */
    return rowSum;
}

int main()
{
    char input[20];
    char* output;
    int height = 0;
    int outputSize = 0;
    printf("Enter the input : ");
    scanf("%s",input);
    printf("\nEnter the pyramid height :");
    scanf("%d",&height);

    printf("%s\n",input);

    printf("%lu \n",strlen(input));


    if(strlen(input) > 20)
    {
        printf("Input can't be longer than 20 chars\n");
        return 0;
    }

    if(strlen(input) < height)
    {
        printf("Height can't be bigger than the length of the input\n");
        return 0;
    }



        outputSize = (strlen(input) * height) + height;
        output = (char *)malloc(sizeof(char) * (outputSize + 1));
        printf("The Sum of Rows : %d\n",Piramify(input,height,output));
        printf("The output string in pyramid format : \n");
        for(int i = 0; i < outputSize; i++)
        {
            printf("%c",output[i]);
        }
        free(output);
}

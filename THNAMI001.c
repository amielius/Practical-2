#include <stdio.h>  //included so that input/output related functions are enabled
#include <math.h>   //included so that mathematical calculations and functions can be used
#include <string.h> //included so that string manipulation is enabled

//defining variables to be used in credential output to the screen:
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Written by: Amiel Thanarayen"
#define YEAR "Date: 2022"

//function to output an alphabet when the radix is greater than 10 and output a digit when the radix is less than 10.
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// function to reverse a string
void string_rev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a given decimal number to a given base
char* Dec2RadixI(char res[], int base, int inputNum) // I didn't use  decValue and radValue here because I used this in the loop further on as these were more descriptive names for the variables and were more useful in the more complicated part of the code
{
    int index = 0;  // Initialize index of result

    // To convert the input number to a given base, it must be repeatedly divided by the base and using the remainder in the successive calculation
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }


    res[index] = '\0';

    // Reverse the result to print the array in the correct order from left to right
    string_rev(res);

    return res;
}

//credentials of the code to inform the user before interaction
int main(){
    printf("**************************** \n");
    printf("%s\n",TITLE);
    printf("%s\n",AUTHOR);
    printf("%s\n",YEAR);
    printf("**************************** \n");

    //prompts for the user to input values
    int decValue;
    printf("Enter a decimal number: ");
    scanf("%d", &decValue);
    printf("The number you have entered is %d \n", decValue);

    int radValue;
    printf("Enter a radix for the converter between 2 and 16: ");
    scanf("%d", &radValue);
    printf("The radix you have entered is %d \n", radValue);

    while(decValue >= 0){

    printf("The log2 of the number is %.2f \n", (log2((double)decValue))); //we convert decValue to double because the log function requires a double input, answer must also be truncated to 2 decimal places.
    printf("The integer result of the number divided by %d is %d \n", radValue, decValue/radValue);
    printf("The remainder is %d \n", decValue%radValue );
    char res[100];
    printf("The radix-%d value is %s \n", radValue, Dec2RadixI(res, radValue, decValue));

    printf("Enter a decimal number: ");
    scanf("%d", &decValue);

        if(decValue >= 0){
            printf("The number you have entered is %d \n", decValue);
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d", &radValue);
            printf("The radix you have entered is %d \n", radValue);
        }
        else {
            printf("EXIT \n");
        }


    }



    return 0;
}


/***********************************************************************************************
 * Filename: cc_decrypt.c
 * Version: 1.3.1
 * Student Name: Megan Machkouri
 * Student Number: 041006409
 * Course Name/Number: CST 8234
 * Lab Section: 014
 * Assignment Name: Lab 02
 * Due Date: June 4th
 * Submission Date: June 4th
 * Professor Name: Gerald Hurdle
 * Purpose: A simple program that accepts a string as an input, converts the string into a decrypted
 *          string according to the shift key inputted by the user.
 * ********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE 80
#define MAX_ROTATION 26
#define MIN_ROTATION 0

 /* Function Prototype. */
void decrypt(char *message, int key);

/***********************************************************************************************
 * Function Name: main
 * Purpose: Allows for program execution and testing.
 * Function In parameters: nothing
 * Function Out parameters: 0 or 1 
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/

int main()
{
    char message[MAX_MESSAGE];
    int key;
    int isValid = 0;
    int isValid2 = 0;
    int input2;

    do
    {
        /* Prompt User for string message. */
        printf("Enter a message to decrypt: \n");
        /* Scan user input and intialize to variable message. */
        scanf(" %[^\n]s", message);
        
        
            do
            {
                /* Prompt User for rotation key. */
                printf("Enter a rotation key: \n");
                 /* Scan user input and intialize to variable key. */
                input2 = scanf("%d", &key);
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                /* Validate User Input*/
                if (input2 != 1) /* Check if input is integer */
                {
                    /* Output Error Message */
                    printf("Invalid input. Must be integer\n");
                }
                else
                {
                    /* Validate User Input*/
                    if ((key >= MIN_ROTATION) && (key <= MAX_ROTATION))/*Check if key is within acceptable range*/
                    {
                         /* Output original string and rotation key */
                        printf("Decrypting Message(key = %d): %s\n", key, message);
                         /* Pass original string and rotation key as parameters for decrypt function*/
                        decrypt(message, key);
                        return EXIT_SUCCESS; /* Exit Program */ 
                        
                    }
                    else
                    {
                         /* Output Error Message */
                        printf("Error - key must be in range 0 and 26. Try Again\n");
                    }
                }

            } while (isValid2 == 0); /* End While*/
        

    } while (isValid == 0); /* End While*/

    return EXIT_FAILURE; /* Exit Program */  
}/* End Main */

/***********************************************************************************************
 * Function Name: decrypt
 * Purpose: Decrypts String according to rotation key value.
 * Function In parameters: char *message, int key
 * Function Out parameters: void  
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/

void decrypt(char *message, int key)
{
    unsigned char c;
    char decrypt[MAX_MESSAGE] = "";
    int i;

    /* Copy message characters into decrypt array */
    strcpy(decrypt, message);
       
    /* Iterate decrypt character array */
    for (i = 0; decrypt[i] != '\0' ; ++i)
    {
        c = decrypt[i];
         /* Lowercase Letter */
        if (islower(c))
        {
            /* Shift Char */
            c = c - key;
            if (c < 'a')
            {
                /* Decrypt */
                c = c + 'z' - 'a' + 1;
            }
            /* Initialize */
            decrypt[i] = c;
        }
        /* Uppercase Letter */
        else if (isupper(c))
        {
            /* Shift Char */
            c = c - key;
            if (c < 'A')
            {
                /* Decrypt */
                c = c + 'Z' - 'A' + 1;
            }
            /* Initialize */
            decrypt[i] = c;
        }
    }
    /* Output decrypted string */
    printf("\n%.80s\n", decrypt);
}
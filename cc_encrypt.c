/***********************************************************************************************
 * Filename: cc_encrypt.c
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE 80
#define MAX_ROTATION 26
#define MIN_ROTATION 0

/* Function Prototype. */
void encrypt(char *message, int key);

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
        /* Prompt User for binary number. */
        printf("Enter a message to encrypt: \n");
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
                if (input2 != 1)
                {
                    /* Output Error Message */
                    printf("Error - key must be in range 0 and 26. Try Again\n");
                }
                else
                {
                    /* Validate User Input*/
                    if ((key >= MIN_ROTATION) && (key <= MAX_ROTATION))/*Check if key is within acceptable range*/
                    {
                        /* Output original string and rotation key */
                        printf("Encrypting Message(key = %d): %s\n", key, message);
                        /* Pass original string and rotation key as parameters for encrypt function*/
                        encrypt(message, key);
                        return EXIT_SUCCESS;/* Exit Program */ 
                        
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
 * Function Name: encrypt
 * Purpose: Encrypts String according to rotation key value.
 * Function In parameters: char *message, int key
 * Function Out parameters: void  
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/

void encrypt(char *message, int key)
{
    unsigned char p;
    char encrypt[MAX_MESSAGE];
    int i;
   
   
        /* Copy message characters into encrypt array */
        strcpy(encrypt, message);
    
    /* Iterate encrypt character array */
    for (i = 0; encrypt[i] != '\0'; ++i)
    {
        p = encrypt[i];
        /* Lowercase Letter */
        if (islower(p))
        {
            /* Shift Char */
            p = p + key;
            if (p > 'z')
            {
                /* Encrypt */
                p = p - 'z' + 'a' - 1;
            }
            /* Initialize */
            encrypt[i] = p;
        }
        else if (isupper(p))
        {
            /* Shift Char */
            p = p + key;
            if (p > 'Z')
            {
                /* Encrypt */
                p = p - 'Z' + 'A' - 1;
            }
            /* Initialize */
            encrypt[i] = p;
            
        }
    }
     /* Output encrypted string */
    printf("\n%.80s\n", encrypt);
}
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MESSAGE 80

int main(){
   char message[80];
    
    char encrypt[80] ="";
    int key;
    int isValid = 0;
    int isValid2 = 0;
    int input2;

    do{
         /* Prompt User for binary number. */
      printf("Enter a message to decrypt: \n");
      /* Scan user input and intialize to variable binary. */
      
      scanf(" %[^\n]s", message);
        while(getchar() != '\n' ){
             /* Chomp stdin (prevents infinite loop)*/
            }
            do{
            printf("Enter a rotation key: \n");
            input2 = scanf("%d", &key);
            
            if (input2 != 1) {
                /* Output Error Message */
                printf("Invalid input. Must be integer\n");
            }else{
                

                
                if ((key >= 0) && (key <= 26))
                {
                    unsigned char c;
                    int i;
                    for (i = 0; message[i] != '\0'; ++i){
                        encrypt[i] = message[i];
                    
                    }
                    for (i = 0; encrypt[i] != '\0'; ++i)
                    {
                        c = encrypt[i];
                        if (c >= 'a' && c <= 'z')
                        {
                            c = c + key;
                            if (c > 'z')
                            {
                                c = c - 'z' + 'a' - 1;
                            }
                            encrypt[i] = c;
                           
                        }
                        else if (c >= 'A' && c <= 'Z')
                        {
                            c = c + key;
                            if (c > 'Z')
                            {
                                c = c - 'Z' + 'A' - 1;
                            }

                            encrypt[i] = c;
                            
                        }
                        
                        
                    }
                    printf("Encrypting Message(key = %d): %s\n", key, message);
                    printf("\n%s\n", encrypt);
                    isValid2 = -1;
                    isValid = -1;
                }
                else{
                  printf("Error - key must be in range 0 and 26. Try Again\n");  
                }
                }
              
            }while (isValid2 == 0);
        

    }while (isValid == 0);

    return EXIT_SUCCESS;
}
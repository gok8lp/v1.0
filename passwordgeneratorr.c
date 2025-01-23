#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main() {
    char password[20];
    int passwordSize;
    bool check = false;
    int count = 0;

    printf("*** Only 20 characters allowed ***\n");
    printf("Enter your password:  ");
    scanf("%s", password);
    passwordSize = strlen(password);

    if (passwordSize > 20) {
        check = false;
    } else {
        check = true;
    }

    int intcheck = check; 

    switch (intcheck) {
        case 1: {  
            int numberlist[passwordSize]; 

            srand(time(NULL)); 

            while (count < passwordSize) {
                int randomNumber = rand() % passwordSize;  
                int isUnique = 1;

                for (int i = 0; i < count; i++) {
                    if (numberlist[i] == randomNumber) {
                        isUnique = 0;
                        break;
                    }
                }

                if (isUnique) {
                    numberlist[count] = randomNumber;
                    count++;
                }
            }

            char newPassword[passwordSize + 1]; 
            for (int i = 0; i < passwordSize; i++) {
                newPassword[i] = password[numberlist[i]];
            }
            newPassword[passwordSize] = '\0';  

            printf("***New Password***\n");
            printf("Password: %s\n", newPassword);
            break;  
        }

        case 0: {  
            printf("Password is too long\n");
            break;  
        }
    }

    return 0;
}
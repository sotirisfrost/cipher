#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void checkKey(char []);
void fixMessage(char []);
void toUpper(char []);
void encryptMes(char [], char [][5], char [], int, char [], char [][10]);
void decryptMes(char [], char [], char [][10], char [][5], char []);

int length;

int main(){
    char plaintext[100], key[30], key2[30], enck[10][10], encrypted[100], enc[100], encrypt[5][5]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    int choice;

    printf("************************************\n");
    printf("* Encryption/Decryption System *\n");
    printf("************************************\n");
    printf("\n");

    printf(" 1. Code the message\n 2. Decode the message\n 3. Exit\n Make your choice\n");
    scanf("%d", &choice);

    switch(choice){

    case 1:
        printf("Please enter your message: \n");
        fflush(stdin);
        scanf("%[^\n]s", &plaintext);

        fixMessage(plaintext);
        toUpper(plaintext);

        printf("%s\n", plaintext);

        printf("Please enter your keyword: \n");
        scanf("%s", &key);

        checkKey(key);
        toUpper(key);

        printf("%s\n", key);

        encryptMes(plaintext, encrypt, enc, length, key, enck);

        break;

    case 2:
        printf("Please enter your encrypted message: \n");
        scanf("%s", &encrypted);

        printf("Please enter your keyword: \n");
        scanf("%s", &key2);
        checkKey(key2);
        toUpper(key2);

        decryptMes(key2,enc,enck,encrypt,encrypted);

        break;

    case 3:
        return 0;
        break;

    default:
        printf("************************************\n");
        printf("* Encryption/Decryption System *\n");
        printf("************************************\n");
        printf("\n");

        printf(" 1. Code the message\n 2. Decode the message\n 3. Exit\n Make your choice\n");
        scanf("%d", &choice);
    break;
        }
    }



void encryptMes(char plaintext[], char encrypt[][5], char enc[], int length, char key[], char enck[][10]){
    int i, k, j, x;

    length = 0;

    for(i=0; i<100; i++){
        enc[i] = 0;
    }

    x=0;
    for(i=0; i<strlen(plaintext); i++){
        for(j=0; j<5; j++){
            for(k=0; k<5; k++){
                if(plaintext[i] == encrypt[j][k]){
                enc[x] = j;
                enc[++x] = k;
                x++;
                }
            }
        }
        if(plaintext == 'Z'){
            enc[x] = 3;
            enc[++x] = 1;
        }
        length += 2;
    }

    for(i=0; i<length; i++){
        printf("%d", enc[i]);
    }
    printf("\n");
    printf("\n");

    int length2;
    char temp[10];

    if(length%strlen(key) == 0)
        length2 = 1 + length/strlen(key);
        else
        length2 = 2 + length/strlen(key);

    x=0;
    for(i=0; i<length2; i++){
        for(j=0; j<strlen(key); j++){
            if(i==0){
                enck[i][j] = key[j];
            }
            else{
                enck[i][j] = enc[x];
                x++;
            }
        }
    }

    for(i=0; i<length2; i++){
        for(j=0; j<strlen(key); j++){
            if(i==0){
                printf("%c ", key[j]);
            }
            else if(enck[i][j] == '\0' && (i == length2 - 1))
                    printf(" ");
                else
                    printf("%d ", enck[i][j]);
                    }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<length2; i++){
        for(j=0; j<strlen(key)-1; j++)
            if(enck[0][j]>enck[0][j+1]){
                for(k=0; k<length2; k++){
                    temp[k]=enck[k][j];
                    enck[k][j]=enck[k][j+1];
                    enck[k][j+1]=temp[k];
                }
            }
        }

        for(i=0; i<length2; i++){
            for(j=0; j<strlen(key); j++){
                if(i==0){
                    printf("%c ", enck[i][j]);
                }
                else if(enck[i][j] == '\0' && (i == length2 - 1)){
                        printf("  ");
                    }
                    else
                        printf("%d ", enck[i][j]);
                    }
        printf("\n");
    }

        x=0;
        for(i=0; i<length2; i++){
            for(j=1; j<strlen(key); j++){
                enc[x] = enck[j][i];
                x++;
                }
            }

         printf("\n");
         printf("Encode message is: \n");

         for(i=0; i<x; i++){
             printf("%d", enc[i]);
         }
         printf("\n");
}

void decryptMes(char key2[], char enc[], char enck[][10], char encrypt[][5], char encrypted[]){
    int i,j,k;
    int length, length2;
    char temp[10], finalm[100];

    length = strlen(encrypted);

    if(length%strlen(key2) == 0)
        length2 = 1 + length/strlen(key2);
        else
        length2 = 2 + length/strlen(key2);

    for(i=0; i<length2; i++){
        for(j=0; j<strlen(key2); j++){
            if(i==0){
                enck[i][j] = key2[j];
            }
        }
    }

    for(i=0; i<length2; i++){
    for(j=0; j<strlen(key2)-1; j++){
        if(enck[0][j]>enck[0][j+1]){
            for(k=0; k<length2; k++){
                temp[k]=enck[k][j];
                enck[k][j]=enck[k][j+1];
                enck[k][j+1]=temp[k];
                }
            }
        }
    }

    int x=0;
    for(i=0; i<length2; i++){
        for(j=1; j<strlen(key2); j++){
            enck[j][i] = encrypted[x];
            x++;
        }
    }

     for(i=0; i<length2; i++){
        for(j=0; j<strlen(key2); j++){
            if(i==0){
                printf("%c ", enck[i][j]);
            }
            else if(enck[i][j] == '\0' && (i == length2 - 1))
                    printf(" ");
                else
                    printf("%c ", enck[i][j]);
                    }
        printf("\n");
    }

    int temp1;
    for(i=0; i<length2; i++){
    for(j=0; j<strlen(key2)-1; j++){
        if(key2[i] == enck[0][j]){
            for(k=0; k<length2; k++){
                temp1=enck[k][j];
                enck[k][j]=enck[k][i];
                enck[k][i]=temp1;
                }
            }
        }
    }

    printf("\n");

    for(i=0; i<length2; i++){
        for(j=0; j<strlen(key2); j++){
            if(i==0){
                printf("%c ", enck[i][j]);
            }
            else if(enck[i][j] == '\0' && (i == length2 - 1))
                    printf(" ");
                else
                    printf("%c ", enck[i][j]);
                    }
        printf("\n");
    }

        x=0;
        for(i=1; i<length2; i++){
            for(j=0; j<strlen(key2); j++){
                encrypted[x] = enck[i][j];
                x++;
                }
            }

        length = x;
         for(i=0; i<length; i++){
            if(encrypted[i] == '\0' || x - i < strlen(key2)){
                printf(" ");
                encrypted[i] = " ";
            }else
             printf("%c", encrypted[i]);
         }
         printf("\n");

         for(i=0; i<x; i+=2){
            printf("%c", encrypt[encrypted[i]-48][encrypted[i+1]-48]);
         }
}

void checkKey(char key[]){
    int flag = 0, i, j;

    for(i=0; i<strlen(key); i++){
        for(j=i+1; j<strlen(key); j++){
            if(key[i] == key[j]){
                flag++;
            }
        }
    }

    if(flag != 0){
        printf("Please enter a valid keyword: \n");
        scanf("%s", &key);
    }
}

void fixMessage(char string []){
    int i,j=0;

        for(i = 0; string[i] != '\0'; i++){
            string[i] = string[i + j];

            if(string[i] == ' ' || string[i] == '\t'){
                j++;
                i--;
        }
    }
}

void toUpper(char *sPtr){
    int i;

    while(*sPtr != '\0'){

        if(islower(*sPtr)){
            *sPtr = toupper(*sPtr);

            ++sPtr;
        }
    }
}

// 030430142022322200412040131230032330011040

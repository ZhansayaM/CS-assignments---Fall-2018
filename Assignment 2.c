#include <stdio.h>
#include <stdlib.h>


void keyfile(FILE *key, int i, char subarr[]){
    for (i=0; i<254; i++){ // reading the elements from the key file
        subarr[i]=fgetc(key);
    }
}

void encrypt (FILE *fin, FILE *fout, char subarr[], char pass[]){
    unsigned char sum;
    int i=0, index, n, period;
    char c;
    for (i=0; ; i++){
        if (pass[i]=='\0'){ //if the next character from the password is a NULL character (\0)then declare that this element is equal to 0 and start again the iteration
            period=i; //store the value of the location of the \0
            break;//stop the loop
        }
    }
    i=0;
    while((c=getc(fin))!=EOF){ // reading the characters from the initial file, like 'test.txt' till we reach the end of the file
        n=i%period; //finding the remainder - the location of the character in the stored elements of the password
        sum=pass[n]+c;//the sum of the ith element of the password and the read character from the initial file
        index=sum%254; //finding the modulus by 254 (the number of elements of the key file), to find the index (location) of the symbol in the key file
        fputc(subarr[index], fout); //put this symbol into the secondary file (f output, that was named by the user)
        i++; // incrementing the i in order to read the next character from the initial file and from the password
    }
}

void decrypt(FILE *fin, FILE *fout, char subarr[], char pass []){
    int j=0, i=0,n, period;
    char  index,c, ch;
    unsigned char sum;
    for (i=0; ; i++){
        if (pass[i]=='\0'){// if the next character from the password is a NULL character (\0),then declare that this element is equal to 0 and start again the iteration
            period=i;//store the value of the location of the \0
            break;//stop the loop
        }
    }
    i=0;
    while ((c=getc(fin))!=EOF){ // reading the characters from the initial file (already encrypted file) till we reach the end of the file
        for(j=0; subarr[j]!=c;j++){//check the element of the subarr ( from the key file), until it's equal to the received character from the file
        }
        n=i%period;//finding the remainder - the location of the character in the stored elements of the password
        sum=j-pass[n];// when the needed character (symbol) was found, subtract the location of that element from the ith element of the password (ascii value)
        index=sum%254;//finding the modulus from 254 (the number of elements of the key file), to get the plain character, like T or E, so on, but here we're getting the numerical representation of it, as index is int
        ch=index; // finding, translating the ascii value of the index into plain character
        fputc(ch, fout);//printing the character that we got from the previous step into the output file
        i++;// incrementing i in order to read the next character from the password
    }
}
int main(){
    // array - array for storing the elements of the key file
    // ch - decrypted character (transforming the number into the character through the ascii code)
    // sum - sum(or difference)  of the nth character from the initial file and nth character of the password
    // index - result of the modulus by 254, the index of the character in the key file
    // c - reading characters from the initial file
    // pass - password
    // option - option of the user (whether e, d, or q)
    // file1 - file name for the initial file (to read from)
    // file2 - file name for the secondary file (to write on)
    // period - the number of the password element that will repeat periodically
    int i;
    char pass[254], option[255];
    char file1[200], file2[200], array[254];

    setvbuf (stdout, NULL, _IONBF, 0);
    printf ("WELCOME to the encryption service!\n");
    printf ("ENTER your password\n");
    scanf ("%s", pass); //reading the password from the user
    printf ("MENU: <e>ncode, <d>ecode, or <q>uit\n");
    scanf("%s", option);//reading the option of the user as a string in order to user be able to input a word, not only a letter

    while(1){//this loop will return to the menu
        while(1){//this loop is used here to
            if (option[0]=='e'){//if the first character of the user's option is e, then do the following:
                FILE *fin;
                FILE *fout;
                FILE *key;
                printf ("ENTER a file to encrypt\n");
                scanf("%s", file1);//read the name of the file that is going to be encrypted
                fin=fopen(file1, "r");//open the initial file that should be created already for further encryption
                if (fin==NULL){
                    printf ("CANNOT open %s\n", file1);//if couldn't open the file, print the given message to the console window and return to the menu
                    break;
                }
                else {
                    printf ("ENTER a filename for the encrypted file\n");
                    scanf("%s", file2);//read the name of the encrypted file
                    fout=fopen(file2, "w");//open a file that should be created for writing on it the results of the encryption
                    if (fout==NULL){
                        printf ("CANNOT open %s\n", file2);//if couldn't open the file, print the given message to the console window and return to the menu
                        break;
                    }
                }
                key=fopen("key.254", "r");//opening a file that is named 'key.254' that contains the key for encryption and decryption
                keyfile(key, i, array);//call the keyfile function to perform its tasks
                encrypt(fin, fout, array, pass);//call the encrypt function to perform its tasks
                //close previously opened files
                fclose(key);
                fclose(fin);
                fclose(fout);
                break;//break is used here to go out of the inner while loop and return to the menu that is located in the outer loop
            }

            else if (option[0]=='q'){//if the first character of the entered user's option is q, then do the following:
                printf ("BYE!\n");//print the message and exit the program totally [stop the program]
                exit(0);
            }

            else if (option[0]=='d'){//if the first character of the entered user's option is q, then do the following:
                FILE *fin;
                FILE *fout;
                FILE *key;
                printf ("ENTER a file to decrypt\n");
                scanf("%s", file1);//read the name of the encrypted file that is going to be decrypted
                fin=fopen(file1, "r");//open the initial file that should be created already for further decryption
                if (fin==NULL){
                    printf ("CANNOT open %s\n", file1);//if couldn't open the file, print the given message to the console window and return to the menu
                    break;
                }
                else {
                    printf ("ENTER a filename for the decrypted file\n");
                    scanf("%s", file2);//read the name of the decrypted file
                    fout=fopen(file2, "w");//open a file that to print the results into
                    if (fout==NULL){
                        printf ("CANNOT open %s\n", file2);//if couldn't open the file, print the given message to the console window and return to the menu
                        break;
                    }
                }
                key=fopen("key.254", "r");//opening a file that is named 'key.254' that contains the key for encryption and decryption
                keyfile(key, i, array);//call the keyfile function to perform its tasks
                decrypt(fin, fout, array, pass);//call the decrypt function to perform its tasks
                //close all the opened files
                fclose(key);
                fclose(fin);
                fclose(fout);
                break;//used here to return to the menu, that is located in the outer while loop

            }

            else {
                printf ("UNRECOGNIZED %c\n", option[0]);// if the first character of the option of the user does not coincide with the given options, then print the given message to the console window
                break;//used here to return to the menu, that is located in the outer while loop
            }
        }
        printf ("MENU: <e>ncode, <d>ecode, or <q>uit\n");// printing the menu on the console window after each encryption/decryption/fail to open a file, etc
        scanf("%s", option);//reading the option of the user as a string in order to user be able to input a word, not only a letter
    }
    return 0;
}

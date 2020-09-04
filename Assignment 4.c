#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
	char strData[50];
	struct _Node *next;
}Node;

int countFileLines(char filename[]){
	int i=0,count=0; //count - to count the number of new lines in the file, because number of new lines = lines in the file
char l;//to store the characters in the file until we reach to the new line character
		FILE *file;
		file=fopen(filename,"r");//open the file
		if (file==NULL)
				{printf ("CANNOT open the file\n"); //if the file does not exist, print to the console an error message
				return 1;}
for (i=0;!feof(file);i++){
l=fgetc(file); //check all the characters until the new line character
if (l=='\n')
	count++;} //when the new line character is passed to the l, increment the count variable
fclose(file); //close the file
return count;} // return the number of new line characters

int isPalindrome(char str[]){
int l, i, m=1;
l=strlen(str); // get the string length of the given string
int k=0, n=1; // k -for false {0}, n - for true {1}
for (i=0; str[i]!='\0'; i++, m++)
{	if (str[i]==str[l-m]){ // check till the end of the string whether it is a palindrome or not by checking its first and last characters, and continue respectively
		continue;}
	else return k;} // return false
return n;} // return true

char *getPalindrome(char str[]){
int l;
	l=isPalindrome(str); // get the number (0 or 1|| true or false) for the given string to identify whether it's a palindrome or not
	if (l==1)
	return "Is_Palindrome"; // if it is a palindrome, return the message that is saying 'Is a palindrome'
	else
	return "Not_Palindrome";} // else(only the l=0 case left), return the message that is saying 'Not a palindrome'

int howManySubstrings(char subStr[], char str[]){
int k=0,count=0, i=0;
//here I used the'concept' that each element of the substring should be = to each correspondong element of the string
for (k=0;k<strlen(str);k=k+3){//continue until the last line is reached
while(subStr[i]!=str[k])
	{k++;//so first of all we should find the element of the string that is = to the first element of the substring (increment k until we find the equal element)
	if (str[k]=='\0')
	break;}
if (subStr[i]==str[k] && subStr[i+1]==str[k+1] && subStr[i+2]==str[k+2])//then we check whether substring's 3 elements are = to the k'th, (k+1)'th and (k+2)'th element of the string
{count++;}//if yes, increment the count variable and the next value of k to check will be k+3, to find non-overlapping substrings
else k=k-2;} //if no, hold the same procedure for the next element of the string
	return count;}

void writeFile2(char fileName[], char ssData[], Node **oLinkedList){
    FILE *file; //declare and open the file with the 'fileName' name that will be hardcoded, to append
    file=fopen(fileName, "a");
      fprintf(file, "%s", ssData); //print to the given file the first string from the subStrings file
    fprintf(file, "\n");
    while(*oLinkedList!=NULL){//do until we reach the end
        fprintf (file, "%s", (*oLinkedList)->strData); //print to the file the linked list data
      int x=strcmp("\n",(*oLinkedList)->strData);//compare if they are same
    if (x==0){//if they are equal(if (*oLinkedList)->strData is a \n , then
    	*oLinkedList=(*oLinkedList)->next;//advance to the next element and go out of loop
    	break;}
    else{ fprintf (file, "\n");}
        *oLinkedList=(*oLinkedList)->next;}//advance to the next element
  fclose(file); //close the opened file
 // fprintf (file, "\n");
 }

void freeLinkedlist(Node *head){
	Node *new; //declaring a new Node pointer
	while (head!=NULL){//do until we reach the end
	    new = head;          //save the head pointer into another node pointer
	    head= head->next;     //continue (shift to the next element)
	    free(new);}}//free the node

void printLinkedlist(Node *head){
   Node *new=malloc(sizeof(Node));//memory allocation of the pointer
			while (head!=NULL){ //do until reach the end
		    new = head; //save the head pointer into another node pointer
		    head = head->next; //advance to the next element
		    int x=strcmp(new->strData, "\n"); //compare if they are equal (if they both are new line characters)
        if (x==0) // if they are the same, then leave the loop
        break;
        else  printf("%s\n", new->strData); } //if they are not the same, print to the console window the linked list
        printf("\n");}

void appendNode(Node **oLinkedList, char outputLine[]){
    Node *newNode=(Node*)malloc(sizeof(Node)); //declare a new node and allocate it
    int i, j = strlen(outputLine); //j=length of the outputLine string
    for(i=0;i<=j;i++){ //do until we reach the end of the string
        newNode->strData[i]=outputLine[i];} //store into a node the data from the string
    newNode->next=*oLinkedList; //advance to the next element and assign it to the value of the *oLinkedList(address of the next element)
    *oLinkedList=newNode;} //save the newNode into the double pointer

void checkSubstringPalindrome2(char ssData[], char *iStringData[], Node **oLinkedList, int nrIOfileLines){
    int i[nrIOfileLines], m;
    char *palindrome;
    char out[nrIOfileLines][50];
    for(m=0;m<nrIOfileLines;m++){ //iterate till the last line of the file
        i[m]=howManySubstrings(ssData, iStringData[m]); //evaluate the number of substrings in the string
        palindrome= getPalindrome(iStringData[m]);//identify the palindrome (whether it is a palidrome or not)
        sprintf(out[m],"%s\t%d\t%s", iStringData[m], i[m], palindrome);//store all the received data into
        appendNode(oLinkedList, out[m]);}}//advance to the next linked list (like a chain, to connect them)

void readFile2(char filename[], char *ArrayPtr[]){//function for reading the data from the file
    int i,j,k;
    FILE *file;
    file=fopen(filename,"r"); //open the file to read from it
    i=(int)*ArrayPtr[0]; //assign the first element of the array of pointers as the number of lines of the file
    for(j=0;j<i;j++){ //do until we reach the last line of the file
        char *char1=malloc(sizeof(char)); //memory allocation of the pointer
     fgets(char1, 50, file); //get a string from a file with a max length of 50 characters
        for(k=0;;k++){
            if(char1[k]=='\r'){//if we reach the \r character, assign it to the null character (the end of the string) and leave the loop
                char1[k]='\0';
                break;}}
    ArrayPtr[j]=char1;}} //store the values of the pointer char1 into the array of pointers

void prfunc(char filename[]){ //add new function calls prfunc(print function) in order to print a new line in the existing file
  FILE *file;
  file=fopen(filename, "a");
  fprintf(file, "\n");}

int main(void) {
  remove("oStrings.txt");//to remove the previous data in the file if there one
    Node *leave=malloc(sizeof(Node));
    leave=NULL;
    //here I've hard-coded the input and output file names here
    char fout[]="oStrings.txt";
    char fin[]="iStrings.txt";
    char fin1[]="subStrings.txt";
    //variables for line numbers in the files and to make iterations
    int c,a,b,sub;
    a=countFileLines(fin);//getting the number of lines of the iStrings file
    b=countFileLines(fin1);//getting the number of lines of the subStrings file
    char *ArrayPtr[a];//declaring the first array of pointers
    ArrayPtr[0][0]=a; //not to call the countFileLines function where it should not be called, store the number of lines in the array
    readFile2(fin, ArrayPtr); //read the iStrings file and store the data into ArrayPtr array
    char *ArrayPtr1[b];//declaring the second array of pointers
    ArrayPtr1[0][0]=b;//not to call the countFileLines function where it should not be called, store the number of lines in the array
    readFile2(fin1, ArrayPtr1);//read the subStrings file and store the data into ArrayPtr1 array
    for(sub=0;sub<b;sub++){//do until we reach the last line of the subStrings file
        checkSubstringPalindrome2(ArrayPtr1[sub],ArrayPtr, &leave, a);}//
    Node *last=NULL; //declare a node to store the previous value
    for(c=0;leave!=NULL;c++){//do till we reach the end
        Node *new=malloc(sizeof(Node));//declare a node and allocate in the memory
        strcpy(new->strData, leave->strData); //copy the data from the leave->strData to the new->strData struct
        new->next=last;//assign the next element of the new node to the previous one
        last=new;//assign the last node to the new node (save data from 1 to another)
        if(c!=a){ //till we reach the last line of the file advance to the next element
            leave=leave->next;
        }else{strcpy(new->strData, "\n");}} //copy the new line character into new->strData struct
    printLinkedlist(last);//print to the console the linked list
    for(sub=0;sub<b;sub++){ // write and print until we reach the last line of the substrings file
    writeFile2(fout, ArrayPtr1[sub], &last);//write to the output file the result (substring and the linked list)
    printLinkedlist(last);} //print to the console the linked list
    prfunc(fout); //to print the last new line in the output file
    freeLinkedlist(last); //freeing the linked list
    return 0;}

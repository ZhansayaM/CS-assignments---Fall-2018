#include <stdio.h>
#include <string.h>

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

void readFile(char filename[], char twoDimArr[][50]){
    //j = rows, k = columns of the 2D array
	int i,j,k;
    FILE *file;
    file=fopen(filename,"r");//open the given file
    i=countFileLines(filename);//get the number of line of the file
    for(j=0;j<i;j++){
        fgets(twoDimArr[j], 50, file);} //get the rows of the strings from the file
        for(j=0;j<i;j++){//until we reach the last line of the file do the following:
        for(k=0;;k++){
            if(twoDimArr[j][k]=='\n'){ //if this character is a new line character, assign it to the null character to end the string
                twoDimArr[j][k]='\0';
                break;}}}}

void checkSubstringPalindrome(char subStr[], char iStringData[][50], char oStringData[][50], int nrIOfileLines){
    int i[nrIOfileLines], m;
    char *palindrome; //to hold the '*getPalindrome' function's result
    for(m=0;m<nrIOfileLines;m++){//until we reach the last line of the iStrings.txt file, do the following:
        i[m]=howManySubstrings(subStr, iStringData[m]); //store in the 'i' array the number of substrings in the string of the corresponding line
        palindrome= getPalindrome(iStringData[m]);//store the result of whether it's a palindrome or not in the 'palindrome' variable
        sprintf(oStringData[m],"%s\t%d\t%s\n", iStringData[m], i[m], palindrome);}} //store the needed data(in the given form with tabs, etc) in one array

void writeFile(char fileName[], char ssData[], char oStringData[][50], int nrIOfileLines){
	int i;
	int l=nrIOfileLines;
	FILE *file;
    file=fopen(fileName,"a");//open the file
    fprintf(file, "%s", ssData); //print to the given file the first string from the subStrings file
    fprintf (file, "\n"); //print to the file a new line to write the rest on the other line
    for(i=0;i!=l;i++){
       fprintf (file, "%s", oStringData[i]);} // until we reach the number of lines in the iStrings.txt file print to the given file(output) stored in the checkSubstringPalindrome function oStringData array with the needed data
    fprintf (file, "\n");//print to the file a new line (to have a separated blocks for different substrings)
    fclose(file);}//close the file

int main(){
  remove("oStrings.txt");
    int a,b,i;
    char fout[]="oStrings.txt";
    char fin[]="iStrings.txt";
    char fin1[]="subStrings.txt";
    a=countFileLines(fin);
    b=countFileLines(fin1);
    int c=a+b+10;
    char oStringData[c][50];
    char store[a][50];  // to store the data from the files in 2D array (twoDimArr)
    char store1[b][50];
    readFile(fin, store); //read the "iStrings.txt" file and store its characters into the 'store' array
    readFile(fin1, store1);//read the "subStrings.txt" file and store its characters into the 'store1' array
    for(i=0;i<b;i++){ //for each substring do the following:
        checkSubstringPalindrome(store1[i], store, oStringData, a);
    	writeFile(fout, store1[i], oStringData, a);}
    return 0;}

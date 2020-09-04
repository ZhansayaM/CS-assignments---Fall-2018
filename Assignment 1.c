#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c;
	int m, guess, count, random, defaul;
	int count1;
float average;
	defaul=9999;
	count=0;
	m=0;
count1=0;
	setvbuf (stdout, NULL,_IONBF, 0);
	printf ("WELCOME to the guessing game!\n");
	printf ("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
while(1)
	{scanf ("%c", &c);

if (c=='n')
{		printf ("Enter a new MAXIMUM\n");
		scanf ("%d", &defaul);
		/*while (defaul<0)
				{printf ("Enter the natural number, please\n");
					scanf ("%d", &defaul);}
		srand(time(NULL));
					random=rand()%defaul;
				printf("The secret number is BETWEEN 0 AND %d. Guess:\n", defaul);
				do {scanf ("%d", &guess);
				          count++;
				          count1++;
				             if (guess>random)
				                printf ("Too HIGH! Guess:\n");
				             else if (guess<random)
				                printf ("Too LOW! Guess:\n");
				             else if (guess==random)
				                {m++;
				                printf ("Correct: You TOOK %d guesses!\n", count1);
				                count1=0;}} while (guess!=random);*/
				            printf ("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
		scanf ("%c", &c);}
else if (c=='s')
			{srand(time(NULL));
			random=rand()%defaul;
		printf("The secret number is BETWEEN 0 AND %d. Guess:\n", defaul);
		do {scanf ("%d", &guess);
		          count++;
		          count1++;
		             if (guess>random)
		                printf ("Too HIGH! Guess:\n");
		             else if (guess<random)
		                printf ("Too LOW! Guess:\n");
		             else if (guess==random)
		                {m++;
		                printf ("Correct: You TOOK %d guesses!\n", count1);
		                count1=0;}} while (guess!=random);
		            printf ("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
scanf ("%c", &c);}

else if (c=='q')
{if (count==0)
{	average=0;
	printf ("Thanks for playing. Your guess count AVERAGE %.1f", average);
exit(0);}
else if (count!=0)
{average=count/m;
printf ("Thanks for playing. Your guess count AVERAGE %.1f", average);
exit(0);
}}


else {printf ("UNRECOGNIZED command\n");
scanf ("%c", &c);
     printf ("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
	}}
	return 0;}


/*      SECOND VARIANT


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c;
	int m, guess, count, random, defaul;
	int count1;
float average;
	defaul=9999;
	count=0;
	m=0;
count1=0;
	setvbuf (stdout, NULL,_IONBF, 0);
	printf ("WELCOME to the guessing game!\n");

	menu:
	{printf ("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
	scanf ("%c", &c);
	switch (c)
	{case 's': goto start;
	case 'n': goto nrange;
case 'q': goto quit;
	default: {
		printf ("UNRECOGNIZED command\n");
			scanf ("%c", &c);
	goto menu;}}}


	start:
	{srand(time(NULL));
		random=rand()%defaul;
	printf("The secret number is BETWEEN 0 AND %d. Guess:\n", defaul);
		for (;;)
		{scanf ("%d", &guess);
count++;
count1++;
if (guess>random)
		printf ("Too HIGH! Guess:\n");
	else if (guess<random)
		printf ("Too LOW! Guess:\n");
	else if (guess==random)
		{m++;
		printf ("Correct: You TOOK %d guesses!\n", count1);
		scanf ("%c", &c);
		count1=0;
		goto menu;

		}}}


		nrange:
	{
	printf ("Enter a new MAXIMUM");
	scanf ("%d", &defaul);
	while (defaul<0)
	{
		printf ("Enter the natural number, please");
		scanf ("%d", &defaul);
	}
	goto start;}

	quit:
	{if (count==0)
	{	average=0;
		printf ("Thanks for playing. Your guess count AVERAGE %.1f", average);}
else if (count!=0)
	{average=count/m;
	printf ("Thanks for playing. Your guess count AVERAGE %.1f", average);
}
	}
	return 0;
}
*/


//Jeffrey Warwick
//March 25th 2021
//Math Practice Part 4

#include <stdio.h>
#include <stdlib.h>

int Addition(int aNum1, int aNum2);
int Subtraction(int aNum1, int aNum2);
int Multiplication(int aNum1, int aNum2);
int Division(int aNum1, int aNum2, char lvl);
int random(char lvl);

main()
{
	int menu;
	char lvl;
	int aNum1, aNum2, ttlProblems, correctAnswers, count;
	float percent;
	// menu used to ask what the user wants to practice
	printf("Math Practice Program Main Menu \n\n");
	printf("1. Addition \n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Exit \n");
	printf("Select an option: ");
	scanf("%d", &menu);
	
	while(menu!=1 && menu!=2 && menu!=3 && menu!=4 && menu!=5)
	{
		printf("Please enter a number 1 through 5: ");	//menu navigation
		scanf("%d", &menu);
	}

	ttlProblems=0;
	correctAnswers=0;
	
	while(menu != 5)
	{
		printf("Select difficulty level(e-easy, m-medium, h-hard): ");	// deciding the difficulty of the problem
		scanf(" %c", &lvl);
		
		while(lvl != 'e' && lvl != 'm' && lvl != 'h')
		{
			printf("Please enter e, m, or h: ");
			scanf(" %c", &lvl);
		}
		aNum1=random(lvl);
		aNum2=random(lvl);
		
		if(menu == 1)
		{	
			count=Addition(aNum1, aNum2);
		}
		else
		{
			if(menu == 2)
			{
				count=Subtraction(aNum1, aNum2);
			}
			else
			{
				if(menu == 3)
				{
					count=Multiplication(aNum1, aNum2);
				}
				else
				{
					if(menu == 4)
					{
						count=Division(aNum1, aNum2, lvl);	
					}
				}
			}
		}
		correctAnswers=correctAnswers+count;
		ttlProblems=ttlProblems+1;

		printf("Math Practice Program Main Menu \n\n");
		printf("1. Addition \n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Exit \n");
		printf("Select an option: ");
		scanf("%d", &menu);
		
		while(menu!=1 && menu!=2 && menu!=3 && menu!=4 && menu!=5)
		{
			printf("Please enter a number 1 through 5: ");
			scanf("%d", &menu);
		}
		
		if(menu==5) // This is the  output for the solutions completed
		{
			percent = (float)correctAnswers / ttlProblems * 100;
			printf("You have attempted %d problems and got %d correct.\n", ttlProblems, correctAnswers);
			printf("For a percentage correct of %.2f percent\n\n", percent);
		}
		
	}
	
	return 0 ;
}


int Addition(int aNum1, int aNum2)
{
	int aAnswer;
	int count, counter;
	
	counter=1;
			
	printf("%d + %d = ? ", aNum1, aNum2);
	scanf("%d", &aAnswer);
		
	if (aAnswer == aNum1 + aNum2)
	{
		printf("This answer is correct. \n\n");
		count=1;
	}
	else
	{
		while(aAnswer!=aNum1+aNum2 && counter!=3) //giving 3 tries for each problem attempted
		{
			printf("This answer is incorrect. \n");
			printf("Please try again.  \n");
			printf("%d + %d = ? ", aNum1, aNum2);
			scanf("%d", &aAnswer);
			counter++;
		}
		if(aAnswer==aNum1+aNum2) // after the thrid try it will send the user back to the menu. 
		{
			printf("This answer is correct. \n\n");
			count=1;
		}
		else
		{
			printf("This answer is incorrect. \n");
			count=0;
		}
		
	}
	return count;	
}


int Subtraction(int aNum1, int aNum2)
{
	int aAnswer;
	int count, counter;
	
	counter=1;
			
	printf("%d - %d = ? ", aNum1, aNum2);
	scanf("%d", &aAnswer);
		
	if (aAnswer == aNum1 - aNum2)
	{
		printf("This answer is correct. \n\n");
		count=1;
	}
	else
	{
		while(aAnswer!=aNum1-aNum2 && counter!=3)
		{
			printf("This answer is incorrect. \n");
			printf("Please try again.  \n");
			printf("%d - %d = ? ", aNum1, aNum2);
			scanf("%d", &aAnswer);
			counter++;
		}
		if(aAnswer==aNum1-aNum2)
		{
			printf("This answer is correct. \n\n");
			count=1;
		}
		else
		{
			printf("This answer is incorrect. \n");
			count=0;
		}
	}
	return count;
}


int Multiplication(int aNum1, int aNum2)
{
	int aAnswer;
	int count, counter;
	
	counter=1;
			
	printf("%d * %d = ? ", aNum1, aNum2);
	scanf("%d", &aAnswer);
		
	if (aAnswer == aNum1 * aNum2)
	{
		printf("This answer is correct. \n\n");
		count=1;
	}
	else
	{
		while(aAnswer!=aNum1*aNum2 && counter!=3)
		{
			printf("This answer is incorrect. \n");
			printf("Please try again.  \n");
			printf("%d * %d = ? ", aNum1, aNum2);
			scanf("%d", &aAnswer);
			counter++;
		}
		if(aAnswer==aNum1*aNum2)
		{
			printf("This answer is correct. \n\n");
			count=1;
		}
		else
		{
			printf("This answer is incorrect. \n");
			count=0;
		}
	}
	return count;
}


int Division(int aNum1, int aNum2, char lvl) // division was difficult due to the remainder. Got it to work in the end. 
{
	int aAnswer, aAnswer2, count, counter;
	
	counter=1;

	while(aNum1 < aNum2) // this is to correct an impossible division (by 0), or decimals.
	{
		aNum1=random(lvl);
		aNum2=random(lvl);
	}		
	
	printf("%d / %d = ? ", aNum1, aNum2);
	scanf("%d", &aAnswer);
	
	printf("Enter any remainder: ");
	scanf("%d", &aAnswer2);
		
	if (aAnswer == aNum1 / aNum2 && aAnswer2 == aNum1 % aNum2)
	{
		printf("This answer is correct. \n\n");
		count=1;
	}
	else
	{
		while((aAnswer2!=aNum1%aNum2 || aAnswer!=aNum1/aNum2) && counter!=3)
		{
			printf("This answer is incorrect. \n");
			printf("Please try again.  \n");
			printf("%d / %d = ? ", aNum1, aNum2);
			scanf("%d", &aAnswer);
			printf("Enter any remainder: ");
			scanf("%d", &aAnswer2);
			counter++;
		}
		if(aAnswer==aNum1/aNum2 && aAnswer2==aNum1%aNum2)
		{
			printf("This answer is correct. \n\n");
			count=1;
		}
		else
		{
			printf("This answer is incorrect. \n");
			count=0;
		}
	}
	return count;
}

int random(char lvl) // this is to randomize the problems, as much as you can with the rand() function
{
	int aNum1, aNum2;
	
	if(lvl=='e')
	{
		aNum1=rand()%10+1;
			
		aNum2=rand()%10+1;
	}
	else if(lvl=='m')
	{
		aNum1=rand()%100+1;
			
		aNum2=rand()%100+1;
	}
		else
	{
		aNum1=rand()%1000+1;
		
		aNum2=rand()%1000+1;
	}
	return aNum1, aNum2; // the randomized numbers should be used in every module
}

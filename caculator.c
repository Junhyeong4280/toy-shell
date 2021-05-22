#include <stdio.h>

int main (void)
{
	char calc;

	int num1, num2;

	printf("Please enter an opertor : ");

	scanf("%c",&calc);

	rewind(stdin);

	printf("Enter two operational values(Using Space bar or Enter :");
	


	scanf("%d %d",&num1,&num2);

	switch (calc)
	{
		case '+' : 
			printf("%d + %d = %d\n",num1,num2,num1+num2);

		break;

		case '-' :
		printf("%d - %d = %d\n",num1,num2,num1-num2);
		
		break;

		case '*' : 
		printf("%d * %d = %d\n",num1,num2,num1*num2);

		break;

		case '/' :
		if (num2 == 0) 
		{
			printf(" I can't Proceed because an error ouccured.");
		}
		else printf("%d / %d = %3f\n", num1,num2, num1/(double)num2);
		break;
	}
	return 0 ;
}



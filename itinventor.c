#include <stdio.h>

int main(void)
{
	FILE *fp;
	int number, quantity,i;
	float price, value;
	char item[20],filename[20];

	printf("Input file name\n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	printf("Input inventory data\n");
	printf("Item name 	Number 		Price 	Quantitiy\n");

for (i=1;i<=3;i++)
{
fscanf(stdin,"%s %d %f %d", item, &number, &price, &quantity);
fprintf(fp,"%s %d %.2f %d", item, number, price, quantity);
}
fclose(fp);
fprintf(stdout,"\n\n");

fp= fopen(filename,"r");

printf("Item name	Number		Price		Quantity\n");

for(i=1;i<=3;i++)
{
	fscanf(fp,"%s 	%d 	%f 	%d", item,&number,&price,&quantity);
	value=price*quantity;

	fprintf(stdout,"%-8s %7d %8.2f %8d %11.2f\n",item,number,price,quantity,value);
}
fclose(fp);
}

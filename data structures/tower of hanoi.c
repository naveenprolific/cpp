#include<stdio.h>
#include<stdlib.h>

void towers(int,char,char,char);
int main()
{
	int num ;
	printf("enter the number of disks\n");
	scanf("%d",&num);
	printf("the sequence of moves areee\n");
	towers(num,'s','d','a');
	return 0;
}

void towers(int num,char frompeg,char topeg,char auxpeg)
{
	
	if(num==1)
	{
		printf("move disk 1 from peg %c to peg %c\n",frompeg,topeg);
		return;
	
	}
	towers(num-1,frompeg,auxpeg,topeg);
	printf("move disk %d from peg %c to peg %c \n",num,frompeg,topeg);
	towers(num-1,auxpeg,topeg,frompeg);
}

#include<stdio.h>
#include<stdlib.h>
int main()
{

	FILE *fp1,*fp2;
	fp1=fopen("decryptedOutputfile.txt","r");
	fp2=fopen("inputfile.txt","r");
	if(fp1==NULL || fp2==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	char a1,a2;
	a1=getc(fp1);
	a2=getc(fp2);
	int p=0;
	int e=0;
	while(a1!=EOF && a2!=EOF)
	{
		p++;
		if(a1!=a2)
		{
			a++;
			printf("\nat %d th position the characters are not equal",p);
		}
		a1=getc(fp1);
		a2=getc(fp2);

	}
printf("\ntotal number of positions where the two files donot match are %d",e);

}

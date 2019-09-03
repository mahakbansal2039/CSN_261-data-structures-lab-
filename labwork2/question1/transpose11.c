#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encryption(char **output,char **input,int n,int a,int b,int r,FILE* fp2)
{
		for(int i=0;i<r;i++)
		{

			for(int j=0;j<5;j++)
			{

			
				output[i][j]=input[i][(a*j+b)%n];
				fprintf(fp2,"%c",output[i][j]);

			   
			}


		
		
	}


}
int main(int count,char **string )
{

	if(count!=5 || atoi(string[1])<1)
	{
		exit(EXIT_FAILURE);


	}
	int n=atoi(string[1]);
	int a=atoi(string[2]);
	int b=atoi(string[3]);
	FILE *fp=fopen(string[4],"r");
	char buffer[n+1];
	char **initial=(char**)malloc(sizeof(char*)*200);
	for(int k=0;k<200;k++)
		initial[k]=(char*)malloc(sizeof(char)*6);
int i=0;
	while(fgets(buffer,sizeof(buffer),fp)){
		
		
		i++;
	}
i=i/5;
		char **out=(char**)malloc((i+1)*sizeof(char*));
		for(int j=0;j<=i;j++)
			out[j]=(char*)malloc(5*sizeof(char));
int k=0;
		for(int j=0;j<=i;j++)
{
for(int l=0;l<5;l++)
{
out[j][l]=buffer[k];
k++;
}}
		FILE* fp2=fopen("outputfiles.txt","w");
		if(fp2==NULL)
		{
			printf("not found");
			exit(1);

		}
		encryption(out,initial,n,a,b,i,fp2);
	}



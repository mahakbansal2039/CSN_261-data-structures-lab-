#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encryption(char **output,char **intput,int n,int a,int b,int r,FILE* fp2)
{
		for(int i=0;i<r;i++)
		{

			for(int j=0;j<5;j++)
			{

				if(input[i][(a*j+b)%n]=='\0')
					{output[i][j]='\0';
				fprintf(fp2,"\\0");
			         }

			
			else{
				output[i][j]=input[i][(a*j+b)%n];
				fprintf(fp2,"%c",output[i][j]);

			    }
			}


		
		fprintf(fp2,"\n");
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
		for(int i=0;i<5;i++)
		{
			if(buffer[i]=='\n')
				{
				buffer[i]='\0';
			     break;
			    }
		}
		for(int i=0;i<5;i++)
		{
			if(buffer[i]==' ')
			{
				buffer[i]=' ';
				break;

			}


		}
		initial[i]=(char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(initial[i],buffer);
		i++;
	}
		char **out=(char**)malloc(i*sizeof(char*));
		for(int j=0;j<i;j++)
			out[j]=(char*)malloc(5*sizeof(char));
		FILE* fp2=fopen("outputfiles.txt","w");
		if(fp2==NULL)
		{
			printf("not found");
			exit(1);

		}
		encryption(out,initial,n,a,b,i,fp2);
	}



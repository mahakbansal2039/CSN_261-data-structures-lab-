#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void decryption(int ainverse,int n,int a,int r,int b,char **initial,FILE *fp3)
{
	
	for(int i=0;i<r;i++)
	{

		for(int j=0;j<5;j++)
		{
			int y=(j-b);
			while(y<0)
			{
				y=y+n;
			}
			if(initial[i][(y*ainverse)%n]=='\\')
				continue;
			else
				fprintf(fp3,"%c",initial[i][(y*ainverse)%n]);
		}
		


	}




}



void main(int counts,char ** string)
{
	if(counts<5 || atoi(string[1])<1)
	{
		exit(EXIT_FAILURE);


	}

	int n=atoi(string[1]);
	int a=atoi(string[2]);
	int b=atoi(string[3]);
	FILE *fp=fopen(string[4],"r");
	char buffer[2*n+1];
	char **initial=(char**)malloc(sizeof(char*)*200);
	for(int k=0;k<200;k++)
		initial[k]=(char*)malloc(sizeof(char)*6);
	int j=0;
	while(fgets(buffer,sizeof(buffer),fp))
	{

		int t=0;
		for(int i=0;i<strlen(buffer);i++)
		{
			if(buffer[i]=='0')
				continue;
			else
				initial[j][t++]=buffer[i];


		}
		printf("%s",initial[j]);
		j++;



	}
	int r=j;

int ainverse;
int d=0;
while(1)
{
if((n*d+1)%a==0)
	{ainverse=(n*d+1)/a;
		break;
	}
d++;
}
printf("%d",ainverse);

FILE *fp3=fopen("decryptedOutputfile.txt","w");
decryption(ainverse, n,a,r,b,initial,fp3);
}



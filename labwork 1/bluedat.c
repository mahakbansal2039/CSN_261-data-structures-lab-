#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   void removered(int **red,int **Blue,int **Green);
   void removeblue(int **red,int **Blue,int **Green);
   void removegreen(int **red,int **Blue,int **Green);
   void preservered(int **red,int **Blue,int **Green);
   void preservegreen(int **red,int **Blue,int **Green);
   void preserveblue(int **red,int **Blue,int **Green);
   void pixelvalue(int **red,int **Blue,int **Green,int x,int y);
void main()
{
    
   
int **red=(int**)malloc(sizeof(int*)*953);
for(int i=0;i<953;i++)
red[i]=(int*)malloc(sizeof(int)*1268);

int **Green=(int**)malloc(sizeof(int*)*953);
for(int i=0;i<953;i++)
Green[i]=(int*)malloc(sizeof(int)*1268);
int **Blue=(int**)malloc(sizeof(int*)*953);
for(int i=0;i<953;i++)
Blue[i]=(int*)malloc(sizeof(int)*1268);
FILE *fp1 = fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_Input/Q3_ip_Blue.dat","r");
FILE *fp2 = fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_Input/Q3_ip_Red.dat","r");
FILE *fp3 = fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_Input/Q3_ip_Green.dat","r");

   char buffer[6000] ;   
  int i=0;
        while(fgets(buffer,sizeof(buffer),fp2))
        {
       char *token1 = strtok(buffer,","); 
        int k = 0;
        while(token1!=NULL)
        {
            int num2=atoi(token1);
            red[i][k] = num2;
            token1 = strtok(NULL,",");
          
            
            k++;
        }
         
          i++;
    }
    i=0;
        while(fgets(buffer,sizeof(buffer),fp3))
        {
       char *token2 = strtok(buffer,","); 
        int k = 0;
        while(token2!=NULL)
        {
            int num1=atoi(token2);
            Green[i][k] = num1;
            token2 = strtok(NULL,",");
          
            
            k++;
        }
        
          i++;
    }
    i=0;
        while(fgets(buffer,sizeof(buffer),fp1))
        {
       char *token3 = strtok(buffer,","); 
        int k = 0;
        while(token3!=NULL)
        {
            int num3=atoi(token3);
            Blue[i][k] = num3;
            token3 = strtok(NULL,",");
          
          
            k++;
        }
         
          i++;
    }
    printf("enter your choice");
    printf("\n1.Remove all shades of red\n");
     printf("2.Remove all shades of blue\n");
      printf("3.Remove all shades of green\n");
       printf("4.preserve red only\n");
        printf("5.preserve blue only\n");
         printf("6.preserve green only\n");
          printf("7.invalid\n");
int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:removered(red,Blue,Green);
        break;
        case 2:removeblue(red,Blue,Green);
        break;
        case 3:removegreen(red,Blue,Green);
        break;
        case 4:preservered(red,Blue,Green);
        break;
        case 5:preserveblue(red,Blue,Green);
        break;
        case 6:preservegreen(red,Blue,Green);        
        break;
        default:printf("invalid");
    }
    int x,y;
printf("enter the values of coordinates x and y :");
scanf("%d%d",&x,&y);
pixelvalue(red,Blue,Green,x,y);
FILE *filep1=fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_output/Q3_op_blue.dat","w");
FILE *filep2=fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_output/Q3_op_Green.dat","w");
FILE *filep3=fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Q3_output/Q3_op_Red.dat","w");
        for(int i=0;i<953;i++)
        {
            for(int j=0;j<1268;j++)
            {
          fprintf(filep1,"%d",red[i][j]);
           fprintf(filep2,"%d",Green[i][j]);
            fprintf(filep3,"%d",Blue[i][j]);


            }
           
        }
fclose(filep1);
fclose(filep2);
fclose(filep3);

    
   
}
void pixelvalue(int **red,int **Blue,int **Green,int x,int y)
{
    printf("RED,GREEN and Blue value of current pixel is %d %d %d:",red[x][y],Green[x][y],Blue[x][y]);

}

void removered(int **red,int **Blue,int **Green)
{

for(int i=0;i<953;i++)
    {for(int j=0;j<1268;j++)
        {
            if(red[i][j]>Blue[i][j] && red[i][j]>Green[i][j])
                red[i][j]=0;



        }
    }

}
void removeblue(int **red,int **Blue,int **Green)
{

for(int i=0;i<953;i++)
    {for(int j=0;j<1268;j++)
        {
            if(red[i][j]<Blue[i][j] && Blue[i][j]>Green[i][j])
                Blue[i][j]=0;



        }
    }

}
void removegreen(int **red,int **Blue,int **Green)
{

for(int i=0;i<953;i++)
    {for(int j=0;j<1268;j++)
        {
            if(Green[i][j]>Blue[i][j] && red[i][j]<Green[i][j])
                Green[i][j]=0;



        }
    }

}
void preservered(int **red,int **Blue,int **Green)
{
removegreen(red,Blue,Green);
removeblue(red,Blue,Green);

}
void preserveblue(int **red,int **Blue,int **Green)
{
removered(red,Blue,Green);
removegreen(red,Blue,Green);

}
void preservegreen(int **red,int **Blue,int **Green)
{
removered(red,Blue,Green);
removeblue(red,Blue,Green);

}



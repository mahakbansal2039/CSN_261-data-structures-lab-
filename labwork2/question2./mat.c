#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct point{
	int x,y;
};
struct node{

struct point topleft,bottomright;
int value;
struct node* ne;
struct node* nw;
struct node* sw;
struct node* se; 

};
struct node* createnode(struct point tpleft,struct point btright){
struct node* new=(struct node*)calloc(1,sizeof(struct node));
new->ne=NULL;
new->nw=NULL;
new->se=NULL;
new->sw=NULL;
new->topleft=tpleft;
new->bottomright=btright;

return new;


}
void maximalarray(struct node*root , int ** array);
void assign(int** array, int val,struct node* n);
void printtree(struct node *root);
void printinarray(int **array,int n);
void createtree(int **array,struct point p1,struct point p2,struct node *root);
 int level=0;
 int nodelevel=1;
 int nodevalue=1;
void main()
{
FILE *fp=fopen("L2_P2_inputsample.txt","r");
char buffer[1024];
fgets(buffer,1024,fp);
	int l=strlen(buffer)/2;
	int n=(int)pow(2,(int)(log(l)/log(2)+1));

int **matrix;
matrix=(int**)malloc(n*sizeof(int*));


    for(int i=0;i<100;i++)
	matrix[i]=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		matrix[i][j]=0;
}
int row = n-l;
int m=0;

    for(int i=row;i<n;i++)
    {
       matrix[row][i] = buffer[m]-48;
       m=m+2; 
    }
    row++; 

    while(fgets(buffer,1024,fp))
    {
        m=0;
        for(int i = (n-l) ;i<n;i++){
        matrix[row][i] = buffer[m]-48;
        m=m+2;
        }
        row++ ;
    }

   int **maximal;
maximal=(int**)malloc(n*sizeof(int*));
for(int i=0;i<100;i++)
maximal[i]=(int*)malloc(n*sizeof(int));

struct point p1,p2;
p1.x=0;
p1.y=0;
p2.x=n-1;
p2.y=n-1;
struct node* root=createnode(p1,p2);
createtree(matrix,p1,p2,root);




maximalarray(root,maximal);
int choice;
while(1)
	{
	printf("enter your choice :how would you like to view the quadtree ");
	printf("\n1.In maximal array representation");
	printf("\n2.In the form(label,bit value,level)");
	printf("\n3. enter -1 to exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("printing tree in maximal aray form\n");
				printinarray(maximal,n);
				break;
	    case 2:printtree(root);
	            break;
	    default:exit(0);
	}
	
	} 

}
void createtree(int **array,struct point p1,struct point p2,struct node *root)
{
if(abs(p1.x-p2.x)<1 && abs(p1.y-p2.y)<1)
{
	root->value=array[p1.y][p1.x];
	return;
}
bool t=false;
int k=0;
int xor=array[p1.y][p1.x];
for(int i=p1.y;i<=p2.y &&!t;i++)
{
	for(int j=p1.x;j<=p2.x &&!t;j++)
	{

		k=xor^array[i][j];
		if(k==1)
		{
			 struct point c1,c2,c3,c4,c5,c6;

                c2.x=(p1.x+p2.x)/2+1; c2.y=p1.y;
                c4.x=(p1.x+p2.x)/2; c4.y=p2.y;
                c3.x=(p1.x+p2.x)/2+1; c3.y=(p1.y+p2.y)/2+1;
                c1.x=p2.x; c1.y=(p1.y+p2.y)/2;
                c5.x=p1.x; c5.y=(p1.y+p2.y)/2+1;
                c6.x=(p1.x+p2.x)/2; c6.y=(p1.y+p2.y)/2;
                
                root->ne=createnode(p1,c6);
                createtree(array,p1,c6,root->ne);

                struct node* child2=createnode(c2,c1);
                createtree(array,c2,c1,child2);
                

                struct node* child3=createnode(c5,c4);
                createtree(array,c5,c4,child3);

                struct node* child4=createnode(c3,p2);
                createtree(array,c3,p2,child4);

                root->nw = child2;
                root->se = child3;
                root->sw = child4;

                t = true;

			}
		else
		{

			root->value=array[p1.y][p1.x];
		}
	}
}
}

void printinarray(int **array,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
            printf("%d ",array[i][j]);
            
		printf("\n");

	}


}

void printtree(struct node *root){
    if(root){
        level++;
        printtree(root->ne);
        printtree(root->nw);
        printtree(root->se);
        printtree(root->sw);
        if(!root->ne && !root->nw && !root->sw && !root->se){
            printf("%d %d %d\n",nodelevel++,root->value,level-1);
        }
        level--;
    }
}
void assign(int** array, int val,struct node* n){
    for(int i=n->topleft.y;i<=n->bottomright.y;i++){
        for(int j=n->topleft.x;j<=n->bottomright.x;j++)
            array[i][j] = val;
    }
}

void maximalarray(struct node* root , int ** array){
    if(root){
        maximalarray(root->ne,array);
        maximalarray(root->nw,array);
        maximalarray(root->se,array);
        maximalarray(root->sw,array);
        if(!root->ne && !root->nw&&!root->sw && !root->se){
            assign(array,nodevalue++,root);
        }
    }
}
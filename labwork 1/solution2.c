#include<stdio.h>
#include<stdlib.h>
struct deque{
	int front;
	int rear;
	int *arr;
	int size;
};
void createdeque(struct deque *q)
{
	q->front=-1;
	q->rear=-1;
	q->size=0;

}
void insertfront(struct deque *q)
{
	int n;
	printf("enter the number to insert:");
	scanf("%d",&n);
	if(q->front==-1 && q->rear==-1)
	{
		q->arr=(int*)(malloc(1*sizeof(int)));
		q->rear=q->rear+1;
		q->front=q->front+1;
		q->arr[q->front]=n;
		q->size=q->size+1;
	}
	else if(q->rear==q->size-1)
	{
		q->size=q->size*2;
		
		q->arr=realloc(q->arr,q->size*sizeof(int));
		for(int i=q->rear;i>=0;i--)
		{
			q->arr[i+1]=q->arr[i];

		}
		q->arr[q->front]=n;
		q->rear=q->rear+1;

	}
	else
	{
    for(int i=q->rear;i>=0;i--)
		{
			q->arr[i+1]=q->arr[i];

		}
		q->arr[q->front]=n;
		q->rear=q->rear+1;
		



	}
}
void insertrear(struct deque *q)
{
	int n;
	printf("enter the number to insert:");
	scanf("%d",&n);
	if(q->front==-1 && q->rear==-1)
	{
		q->arr=(int*)(malloc(1*sizeof(int)));
		q->rear=q->rear+1;
		q->front=q->front+1;
		q->arr[q->rear]=n;
		q->size=q->size+1;


	}
	else if(q->rear==q->size-1)
	{
		q->size=q->size*2;
		q->arr=realloc(q->arr,q->size*sizeof(int));
		q->rear=q->rear+1;
		q->arr[q->rear]=n;



	}
	else
	{
		q->rear=q->rear+1;
		q->arr[q->rear]=n;
		
	}




}
void deletefront(struct deque* q)
{

	

	if(q->front==-1 && q->rear==-1)
	{

printf("cannot delete as the deque is empty");

	}
	else if(q->rear==0)
	{
		q->front=-1;
		q->rear=-1;
		free(q->arr);

		q->size=0;

	}
	else
	{
		int d=q->arr[q->front];

		for(int i=1;i<q->rear+1;i++){

			q->arr[i-1]=q->arr[i];

		}
		q->arr[q->rear]=0;
		q->rear=q->rear-1;
		if((q->size/2)>q->rear)
		{
			printf("\nchanging the size of deque\n");
			q->arr=realloc(q->arr,sizeof(int)*(q->rear+1));
			q->size=q->rear+1;


		}
		printf("%d is deleted from front\n",d);


	}



}
void deleteback(struct deque *q)
{

	if(q->front==-1 && q->rear==-1)
	{

printf("cannot delete as the deque is empty");

	}
	else if(q->rear==0)
	{
		q->front=-1;
		q->rear=-1;
		 free(q->arr);

		q->size=0;

	}
	else
	{
		int d=q->arr[q->rear];
		q->arr[q->rear]=0;
	   q->rear=q->rear-1;
	   if((q->size/2)>q->rear)
		{
			q->arr=realloc(q->arr,sizeof(int)*(q->rear+1));
			q->size=q->rear+1;


		}
		printf("%d is deleted from back\n",d);
     }

	}
void print(struct deque *q)
{
	printf("currrent size of deque is %ld",q->size*sizeof(int));
		printf("\nprinting all elements of a deque:");
for(int i=0;i<=q->rear;i++)
{

	printf("%d  ",q->arr[i]);

}
printf("\n");

}
int search(struct deque *q)
{
	int ind=-1;
int s;
printf("enter the item to search:");
scanf("%d",&s);
for(int i=0;i<q->size;i++)
{
if(q->arr[i]==s)
	ind=i;


}
return ind;

}
void main()
{

struct deque d;
createdeque(&d);
int choice;
printf("\n1.insert at front:");
printf("\n2.insert at rear:");
printf("\n3.delete from front:");
printf("\n4.delete from rear :");
printf("\n5.search any element");
printf("\n6.print the deque");
printf("\n-1 to exit\n");
while(1)
{
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertfront(&d);
break;
case 2:insertrear(&d);
break;
case 3:deletefront(&d);
break;
case 4:deleteback(&d);
break;
case 5:printf("search any number");
	 int a;
     a=search(&d);
     if(a==-1)
	 printf("element doesnot exist\n");
     else
	 printf("element is present at %d index",a);
break;
case 6:print(&d);
break;
default:printf("invalid operation\n");

}
if(choice==-1)
	break;

}
}





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 13
struct queue{
int arr[MAX];
int front ;
int rear;
int size;


};
struct node{
int rollno;
char name[200];
char dob[200];
char address[1024];
char phoneno[25];
struct node *next;
struct node *prev;


};


void insert(int r,char *n,char *dob,char *addr,char *pno);
void sortByRollno();
void swap(int *a,int *b);
void delete(struct queue *q,int n);
void search(int n);
void modify(int roll);
void sortByName();
void printList();
struct node* createnode(int r,char *n,char *d,char *addr,char *pno);
struct node *first = NULL, *last = NULL;
int size = 0;
struct queue* createqueue(struct queue *q)
{
q->front=-1;
q->rear=-1;
q->size=0;
return q;

}
void push(struct queue *q,int n)
{
if(q->front==-1 && q->rear==-1)
{
	q->arr[0]=n;
q->front=q->front+1;
q->rear=q->rear+1;

q->size++;

}
else
{
	q->rear=q->rear+1;
	q->arr[q->rear]=n;
	
	q->size++;
}
}
int popout(struct queue *q)
{

if(q->front==-1 && q->rear==-1)
{
return -1;

}
else if(q->size==1)
{
	q->front=-1;
	q->rear=-1;
	return q->arr[0];

}
else
{
	int f=q->arr[0];
	for(int i=1;i<q->size;i++)
	{
		q->arr[i-1]=q->arr[i];

	}
	
	q->rear=q->rear-1;
	q->size--;
	return f;
}


}
bool searchq(struct queue *q,int n)
{
for(int i=0;i<q->size;i++)
{
	if(q->arr[i]==n)
		return true;
}
return false;
}
void main()
{
	int choice;
struct queue unusedroll;
createqueue(&unusedroll);
for(int i=0;i<13;i++)
{
	push(&unusedroll,101+i);
}
struct node student;

FILE *fp=fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/Student.csv","r");
char **name=(char**)malloc(sizeof(char*) *13);
char **add=(char**)malloc(sizeof(char*)*13);
char **dateofb=(char**)malloc(sizeof(char*)*13);
char **phonenum=(char**)malloc(sizeof(char*)*13);
char *line=(char*)malloc(sizeof(char)*1024);
fgets(line,1024,fp);
char *token=strtok(line,",");
 token=strtok(NULL,"\n");
int i=0;
while(fgets(line,1024,fp))
{
	token=strtok(line,",");
	token=strtok(NULL,",");
	name[i]=(char*)malloc(sizeof(char)*strlen(token));
	strcpy(name[i],token);
	token=strtok(NULL,",");
	dateofb[i]=(char*)malloc(sizeof(char)*strlen(token));
	strcpy(dateofb[i],token);
	token=strtok(NULL,"\"");
	add[i]=(char*)malloc(sizeof(char)*strlen(token));
	strcpy(add[i],token);
	token=strtok(NULL,",[^\n");
	phonenum[i]=(char*)malloc(sizeof(char)*strlen(token));
	strcpy(phonenum[i],token);
	 printf("%s\n",phonenum[i]);
	i++;
}
while(1)
{

printf("\nenter ur choice");

printf("\n1.insert \n2.delete\n3.sort\n4.search \n5.print\n 6.modify");
printf("\n enter -1 to exit the process\n");
scanf("%d",&choice);
while((getchar()) != '\n');
switch(choice)
{

case 1:printf("enter the rollno to insert\n");
	   int n;
	   scanf("%d",&n);
	   
	   int rollno;
	   if((rollno=popout(&unusedroll))!=-1)
          insert(rollno,name[n-1],dateofb[n-1],add[n-1],phonenum[n-1]);
                    else 
                    	printf("cannot insert more as list is full");
                    break;
case 2:printf("enter roll number to delete :");
		int r;
		scanf("%d",&r);
		while((getchar())!='\n');
		delete(&unusedroll,r);
		break;
case 3:printf("sorting thr linked list ");
		sortByName();
		break;
case 4:printf("enter the rollno to search");
		int rn;
		scanf("%d",&rn);
	    while((getchar())!='\n');
		search(rn);
	
		break;
case 5:printf("printing the linked list:");
		printList();
		break;
case 6:printf("enter the rollno to modify :");
		int rno;
		scanf("%d",&rno);
		while((getchar())!='\n');
		modify(rno);
		break;
default:printf("wrong choice ");

}
if(choice==-1)
break;
}
}
struct node *createnode(int r,char *n,char *d,char *addr,char *pno)
{
struct node *stud=(struct node*)malloc(sizeof(struct node));
stud->rollno=r;
strcpy(stud->name,n);
strcpy(stud->dob,d);
strcpy(stud->address,addr);
strcpy(stud->phoneno,pno);
stud->next=stud;
stud->prev=stud;
return stud;
}
void insert(int r,char *n,char *dob,char *addr,char *pno)
{

struct node *s=createnode(r,n,dob,addr,pno);
if(first==last && first==NULL)
{
first=last=s;
first->next=last->next=NULL;
last->prev=first->prev=NULL;
while((getchar())!='\n');
}
else
{
last->next=s;
s->prev=last;
last=s;
s->next=first;
first->prev=last;
sortByRollno();
while((getchar())!='\n');


}
}
void sortByRollno()
{
int swaps;
struct node *f,*l=first;
if(first==NULL)
return;
do{
swaps=0;
f=first;
while(f->next != l);
{
if(f->rollno > f->next->rollno)
{
	char t[200];
	char d[50];
	char ad[1024];
swap(&(f->rollno),&(f->next->rollno));
strncpy(t,f->name,200);
strncpy(f->name,f->next->name,200);
strncpy(f->next->name,t,200);
strncpy(d,f->dob,50);
strncpy(f->dob,f->next->dob,50);
strncpy(f->next->dob,d,50);
strncpy(ad,f->address,1024);
strncpy(f->address,f->next->address,1024);
strncpy(f->next->address,ad,1024);

strncpy(t,f->phoneno,20);
strncpy(f->phoneno,f->next->phoneno,20);
strncpy(f->next->phoneno,t,20);
swaps=1;


}
f=f->next;

}
l=f;
}while(swaps);
}

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;

}
void delete(struct queue *q,int n)
{
struct node *prev,*present;
prev=first;
present=first->next;
bool t;
do{
if(present->rollno==n)
{
	t=true;
	break;
	present=present->next;
       prev=prev->next;

}
}while(present!=first->next);
if(t && present!=first)
{
prev->next=present->next;
present->next->prev=prev;
present->next=NULL;
present->prev=NULL;
push(q,n);

}
else if( present==prev)
{first=first->next;
last->prev=first->next;

}
else
printf("unused roll  number");
}


void search(int n){
 struct node *current;
  current = first;
  bool b=false;
   do {
       int p = current->rollno;
       if(p==n){
           b= true;
           break;
       }
       current=current->next;
   }while(current!=first);
   if(b){
       printf("salad");
        printf("name:%s\n",current->name);
        printf("address:%s\n",current->address);
        printf("dob:%s\n",current->dob);
        printf("phone no:%s\n", current->phoneno);
   }
   else printf("student with roll number does not exist");
}

void modify(int roll){
   struct node *current;
    current = first;
    bool b=false;
    do {
        if(current->rollno == roll)
        {
            b=true;
            break;
        }
        current=current->next;
    }while(current!=first);
    if(b){
        printf("enter  name\n");
        scanf("%[^\n]s",current->name);
        while ((getchar()) != '\n'); 
        printf("enter  phone number\n");
        scanf("%s",current->phoneno);
        while ((getchar()) != '\n'); 
        printf("enter  address\n");
        scanf("%[^\n]s",current->address);
        while ((getchar()) != '\n'); 
        printf("enter dob\n");
        scanf("%s",current->dob);
        while ((getchar()) != '\n'); 
    }
    else printf("roll number is still unused");
}


void sortByName(){
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = first;    
    if (first == NULL) 
        return;   
    do
    { 
        swapped = 0; 
        ptr1 = first; 
        while (ptr1->next != lptr) 
        { 
            char* a=ptr1->name;
            char* b=ptr1->next->name;
            if (strcmp(a,b)>0) 
            { 
                swap(&(ptr1->rollno), &(ptr1->next->rollno)); 
                char temp[128];
                char temp2[1024];
                char temp3[20];
                strncpy(temp,ptr1->name,128);
                strncpy(ptr1->name,ptr1->next->name,128);
                strncpy(ptr1->next->name,temp,128);
                strncpy(temp2,ptr1->address,1024);
                strncpy(ptr1->address,ptr1->next->address,1024);
                strncpy(ptr1->next->address,temp2,1024);
                strncpy(temp,ptr1->dob,128);
                strncpy(ptr1->dob,ptr1->next->dob,128);
                strncpy(ptr1->next->dob,temp,128);
                strncpy(temp,ptr1->phoneno,20);
                strncpy(ptr1->phoneno,ptr1->next->phoneno,20);
                strncpy(ptr1->next->phoneno,temp,20);
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 

}
void printList(){
   struct  node *current;
    current =first;
    do{
        printf("roll no:%d\n",current->rollno);
        printf("name:%s\n",current->name);
        printf("address:%s\n",current->address);
        printf("dob:%s\n",current->dob);
        printf("phone no:%s\n", current->phoneno);
        current=current->next;
    }while(current!=first&&first->next!=NULL);
     if(first!=last)
     sortByRollno();
}



















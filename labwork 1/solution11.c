#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 13

typedef struct queue {
   int arr[MAX];
   int rear,front;
   int size;
} queue;

typedef struct node {
    int roll;
    char name[128];
    char dob[128];
    char addr[1024];
    char phno[20];
    struct node *prev;
    struct node *next;
} node;

void insert( int roll,char* name,char* dob,char* addr,char* phno);
node* newNode( int roll,char* name,char* dob,char* addr,char* phno);
void delete(int roll,queue *q);
void search(int n);
void modify(int roll);
void printList();
void sortByName();
void sortByRollNumber();
void swap_int(int *r1,int *r2);

node *first = NULL, *last = NULL;
int size = 0;

queue* init_queue(queue *q){
    q->rear=-1;
    q->front=-1;
    q->size=0;
    return q;
}

void push(queue *q,int n){
    if(q->rear==-1&&q->front==-1){
        q->arr[0]=n;
        q->front=q->rear=0;
        q->size++;
    }
    else
    {
        q->arr[++q->rear]=n;
        q->size++;
    }
}

int pop(queue *q){
    if(q->rear==-1&&q->front==-1)
        return -1; 
    else if(q->size==1) {
        q->rear=-1;
        q->front=-1;
        return q->arr[0];
    }
    else {
        int num = q->arr[0];
        for(int i=1;i<q->size;i++)
            q->arr[i-1]=q->arr[i]; 
        q->size--;
        q->rear--;
        return num;    
    }
}

bool search_queue(queue *q, int n){
    for(int i=0;i<size;i++){
        if(q->arr[i]==n)
          return true;
    }
    return false;
}

void main() {
    queue unusedRoll;
    init_queue(&unusedRoll);
    for(int i=0;i<13;i++)
        push(&unusedRoll,101+i);
    node students;
    int op;
    
    FILE *stream = fopen("/home/mahak/Desktop/CSN_261-data-structures-lab-/labwork 1/Student.csv", "r");
    char **name_data = (char**)malloc(13 * sizeof(char*));
    char **address =(char**)malloc(13 * sizeof(char*));;
    char **dtob = (char**)malloc(13 * sizeof(char*));;
    char **phone = (char**)malloc(13 * sizeof(char*));;
    char *line = (char*)malloc(1024 * sizeof(char));
    int i=0;
    fgets(line, 1024, stream);
    char* token=strtok(line, ",");
    token=strtok(NULL,"\n");
        while (fgets(line, 1024, stream))
        {
            token =  strtok(line, ","); 
            token = strtok(NULL, ","); 
            name_data[i]=(char*)malloc(strlen(token)*sizeof(char));
            strcpy(name_data[i],token);
            token = strtok(NULL, ",");
            dtob[i]=(char*)malloc(strlen(token)*sizeof(char));
            strcpy(dtob[i],token);
            token = strtok(NULL, "\"");
            address[i]=(char*)malloc(strlen(token)*sizeof(char));
            strcpy(address[i],token);
            token = strtok(NULL, ",[^\n");
            phone[i]=(char*)malloc(strlen(token)*sizeof(char));
            strcpy(phone[i],token);
            printf("%s\n",phone[i]);
            i++;
        }
    while(1){
        printf("\n1.Insertt\n2.Delete\n3.Search\n4.modify\n5.sort\n6.PrintList\n\nEnter ur choice");
        printf("\nenter -1 to exit\n");
        scanf("%d",&op);
        while ((getchar()) != '\n'); 
        switch(op){
            case 1: printf("operation insert\n");
                    printf("Enter number  for the student you want to insert\n");
                    int num;
                    int rollnum;
                    scanf("%d",&num);
                    while ((getchar()) != '\n'); 
                    if((rollnum=pop(&unusedRoll))!=-1)
                       insert(rollnum,name_data[num-1],dtob[num-1],address[num-1],phone[num-1]);
                    else 
                       printf("linked list in full\n");
                    printf("operation completed\n");   
                    break; 
            case 2: printf("operation delete\n");
                    printf("enter roll to delete\n") ;
                    int rolln;
		scanf("%d",&rolln);
                    delete(rolln,&unusedRoll);   
                    break;  
            case 3: printf("operation search\n");
                    printf("enter roll number to search for:\n");
                    int rollnumber;
                    scanf("%d",&rollnumber);
                    while ((getchar()) != '\n'); 
                    search(rollnumber);
                    printf("operation completed");                   
                    break;
            case 4: printf("operation modify");
                    int num_in;
                    scanf("%d",&num_in);
                    while ((getchar()) != '\n'); 
                    modify(num_in);
                    printf("operation completed"); 
                    break;
            case 5: printf("operation sort by name");
                    sortByName();
                    printf("operation completed");
                    break;    
            case 6: printf("operation print");
                    printList();
                    printf("operation completed");    
                    break;                 
            default: printf("wrong choice");            
        } 
        if(op==-1)
        break;
    }    
}

node* newNode( int roll,char* nome,char* dobt,char* adr,char* phnu){
   node* one_node = (node*)(malloc(sizeof(node)));
//    one_node->name = (char*)malloc(strlen(nome) * sizeof(char));
//    one_node->dob = (char*)malloc(strlen(dobt)* sizeof(char));
//    one_node->addr = (char*)malloc(strlen(adr)* sizeof(char));
//    one_node->phno = (char*)malloc(strlen(phnu)* sizeof(char));
   one_node->roll=roll;
   strcpy(one_node->name,nome);
   strcpy(one_node->dob,dobt);
   strcpy(one_node->addr,adr);
   strcpy(one_node->phno,phnu);
   one_node->next = one_node;
   one_node->prev = one_node;
   return one_node;
}

void insert( int roll,char* name,char* dob,char* addr,char* phno){
    node *nNode = newNode(roll, name,dob,addr,phno);
    if (first == last && first == NULL)
    {
       first = last = nNode;
       first->next = last->next = NULL;
       first->prev = last->prev = NULL;    
       while ((getchar()) != '\n');   
    }
    else
    {
       last->next = nNode;
       nNode->prev = last;
       last = nNode;
       last->next = first;
       first->prev = last;
       sortByRollNumber();
       while ((getchar()) != '\n'); 
    }
}

void delete(int roll,queue *q){
   node *current;
   node *prev;
   prev = first;
   current= first->next;
   bool b=false;
   do {
       if(current->roll == roll)
       {
           b=true;
           break;
       }
       current=current->next;
       prev=prev->next;
    } while(current!=first->next);
    if(b&&current!=first){
       prev->next=current->next;
       current->next->prev=prev;
       current->next=NULL;
       current->prev=NULL;
       push(q,roll);
   }
   else if(current==first){
       first=first->next;
       last->next=first;
       first->prev=last;
   }
   else printf("Roll is still unused\n");
}

void search(int n){
  node *current;
  current = first;
  bool b=false;
   do {
       int p = current->roll;
       if(p==n){
           b= true;
           break;
       }
       current=current->next;
   }while(current!=first);
   if(b){
       printf("salad");
        printf("name:%s\n",current->name);
        printf("address:%s\n",current->addr);
        printf("dob:%s\n",current->dob);
        printf("phone no:%s\n", current->phno);
   }
   else printf("student with roll number does not exist");
}

void modify(int roll){
    node *current;
    current = first;
    bool b=false;
    do {
        if(current->roll == roll)
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
        scanf("%s",current->phno);
        while ((getchar()) != '\n'); 
        printf("enter  address\n");
        scanf("%[^\n]s",current->addr);
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
            char* n1=ptr1->name;
            char* n2=ptr1->next->name;
            if (strcmp(n1,n2)>0) 
            { 
                swap_int(&(ptr1->roll), &(ptr1->next->roll)); 
                char temp[128];
                char temp2[1024];
                char temp3[20];
                strncpy(temp,ptr1->name,128);
                strncpy(ptr1->name,ptr1->next->name,128);
                strncpy(ptr1->next->name,temp,128);
                strncpy(temp2,ptr1->addr,1024);
                strncpy(ptr1->addr,ptr1->next->addr,1024);
                strncpy(ptr1->next->addr,temp2,1024);
                strncpy(temp,ptr1->dob,128);
                strncpy(ptr1->dob,ptr1->next->dob,128);
                strncpy(ptr1->next->dob,temp,128);
                strncpy(temp,ptr1->phno,20);
                strncpy(ptr1->phno,ptr1->next->phno,20);
                strncpy(ptr1->next->phno,temp,20);
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

void printList(){
    node *current;
    current =first;
    do{
        printf("roll no:%d\n",current->roll);
        printf("name:%s\n",current->name);
        printf("address:%s\n",current->addr);
        printf("dob:%s\n",current->dob);
        printf("phone no:%s\n", current->phno);
        current=current->next;
    }while(current!=first&&first->next!=NULL);
     if(first!=last)
     sortByRollNumber();
}

void sortByRollNumber() { 
    int swapped, i; 
     node *ptr1; 
     node *lptr = first; 
    if (first == NULL) 
        return;   
    do
    { 
        swapped = 0; 
        ptr1 = first; 
        while (ptr1->next != lptr) 
        { 
            if ((ptr1->roll > ptr1->next->roll)) 
            {  
                swap_int(&(ptr1->roll), &(ptr1->next->roll)); 
                char temp[128];
                char temp2[1024];
                char temp3[20];
                strncpy(temp,ptr1->name,128);
                strncpy(ptr1->name,ptr1->next->name,128);
                strncpy(ptr1->next->name,temp,128);
                strncpy(temp2,ptr1->addr,1024);
                strncpy(ptr1->addr,ptr1->next->addr,1024);
                strncpy(ptr1->next->addr,temp2,1024);
                strncpy(temp,ptr1->dob,128);
                strncpy(ptr1->dob,ptr1->next->dob,128);
                strncpy(ptr1->next->dob,temp,128);
                strncpy(temp,ptr1->phno,20);
                strncpy(ptr1->phno,ptr1->next->phno,20);
                strncpy(ptr1->next->phno,temp,20);
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
void swap_int(int *r1,int *r2){
    int temp=*r1;
    *r1=*r2;
    *r2=temp;
}

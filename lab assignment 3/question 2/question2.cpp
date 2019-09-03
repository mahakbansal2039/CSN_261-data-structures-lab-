#include<iostream>
using namespace std;
class  node{
public:
int key;
int start;
int last;
node* next;
node* prev;


};
class linkedlist{
public:
node* head;
int size;


};
linkedlist *initialize(){
linkedlist* new_linkedlist=new linkedlist;
new_linkedlist->head=NULL;
new_linkedlist->size=0;
return new_linkedlist;
}
void insert(linkedlist* list,int a)
{
	node* new_node=new node;
	new_node->key=a;
	new_node->next=NULL;
	new_node->prev=NULL;
	list->size++;
	if(list->head==NULL)
		list->head=new_node;
	else
	{
		node *tmp=list->head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=new_node;
		new_node->prev=tmp;


	}
}
void print(linkedlist* list)
{
	node*tmp=list->head;
	while(tmp!=NULL)
		{cout<<tmp->key<<" ";
	cout<<"("<<tmp->start<<","<<tmp->last<<")"<<endl;
	tmp=tmp->next;
}
cout<<list->size<<endl;

}
void getxor(linkedlist* list,linkedlist *xorarray)
{




int s=(list->size);
for(int i=0;i<s;i++)
{
	node *new_node1=new node;
new_node1->next=NULL;
new_node1->prev=NULL;
node *h=list->head;
new_node1->start=i;
new_node1->last=i;
for(int k=0;k<i;k++)
{
	h=h->next;
}

new_node1->key=h->key;

h=h->next;
xorarray->size++;
if(xorarray->head==NULL)
xorarray->head=new_node1;
else
{
	node *tmp=xorarray->head;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=new_node1;
	new_node1->prev=tmp;
}


	for(int j=i+1;j<s;j++)
	{

		node* new_node=new node;
		node *tmp=xorarray->head;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=new_node;
	new_node->prev=tmp;
	new_node->key=(new_node->prev->key)^(h->key);
	new_node->start=i;
	new_node->last=j;
	h=h->next;
	xorarray->size++;

	}
}

}
int index(linkedlist* list,int i,int j)
{
	node*tmp=list->head;
	while(tmp!=NULL)
	{
		if(tmp->start==i && tmp->last==j)
			return (tmp->key);
		tmp=tmp->next;
	}


}
void printtriplets(linkedlist* list,int n)
{
	int count=0;
for(int i=0;i<n;i++)
{
	for(int j=i+1;j<n;j++)
	{

		for(int k=j;k<n;k++)
		{
			if(index(list,i,j-1)==index(list,j,k))
			{
				count++;
				cout<<"("<<i+1<<","<<j+1<<","<<k+1<<")"<<endl;

			}


		}
	}


}
cout<<count<<endl;



}


int main()
{
linkedlist* list=initialize();
linkedlist* xorarray=initialize();
int n;
int a;
cout<<"enter number of elements\n";
cin>>n;
cout<<"enter elements of the array";
for(int i=0;i<n;i++)
{
	cin>>a;
	insert(list,a);
}

getxor(list,xorarray);
printtriplets(xorarray,n);




}
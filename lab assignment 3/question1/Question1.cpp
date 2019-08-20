#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
enum color {RED,BLACK};
vector<int >nodes;
int level=0;
struct bstnode
{
	int key;
	struct bstnode* left,*right;
};
bstnode* newnode(int k)
{

	bstnode* tmp=new bstnode;
	tmp->key=k;
	tmp->left=tmp->right=NULL;
	return tmp;
}

struct node{
	int data;
	bool color;
	node *left,*right,*parent;
	node(int key)
	{

	this->data=key;
	left=right=parent=NULL;
	this->color=RED;
	}

};
class RBTree
{
public:
node* root;
protected:
	void rotateleft(node*& root,node*& parent);
	void fix(node *&root,node *&parent);
	void rotateright(node*& root,node*& parent);
public:
	void rbprintlevelorder(node* root);

public:
RBTree()
{
	root=NULL;
}
void insert(int value);
void inorder();
void levelorder();


};
void  inorderhelper(node* root)
{
	if(root==NULL)
		return;
	inorderhelper(root->left);
	cout<<root->data <<" ";
	inorderhelper(root->right); 
}
string decidecolor(int n)
{
	return n==0 ? "RED" : "BLACK";
}
void levelorderhelper(node* root)
{
	if(root==NULL)
		return;
	std::queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		cout<<temp->data<<" "<<"["<<decidecolor(temp->color)<<"]"<<endl;
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);


	}

}
void RBTree::inorder()
{
	inorderhelper(root);
}
void RBTree::levelorder()
{
	levelorderhelper(root);
}

void RBTree::rotateleft(node *&root,node *&p)
{

	node *p_right=p->right;
	p->right=p_right->left;
	if(p->right!=NULL)
		p->right->parent=p;
	p_right->parent=p->parent;
	if(p->parent==NULL)
		root=p_right;
	else if(p==p->parent->left)
	{
		p->parent->left=p_right;
	}
	else
		p->parent->right=p_right;
	p_right->left=p;
	p->parent=p_right;

}
void RBTree::rotateright(node *&root,node *&p)
{
node *p_left=p->left;
	p->left=p_left->right;
	if(p->left!=NULL)
		p->left->parent=p;
	p_left->parent=p->parent;
	if(p->parent==NULL)
		root=p_left;
	else if(p==p->parent->left)
	{
		p->parent->left=p_left;
	}
	else
		p->parent->right=p_left;
	p_left->right=p;
	p->parent=p_left;


}
void RBTree::fix(node *&root,node *&p)
{
	node*parent_p=NULL;
	node*grand_parent_p=NULL;
	while((p!=root) &&(p->color !=BLACK) && (p->parent->color==RED))
	{
		parent_p=p->parent;
		grand_parent_p=parent_p->parent;

		if(parent_p==grand_parent_p->left)
		{
			node *sibling=grand_parent_p->right;
			if(sibling!=NULL && sibling->color==RED)
			{

				grand_parent_p->color=RED;
				sibling->color=BLACK;
				parent_p->color=BLACK;
				p=grand_parent_p;
			}
			else
			{
				if(p==parent_p->right)
				{

					rotateleft(root,parent_p);
					p=parent_p;
					parent_p=p->parent;
				}
				rotateright(root,grand_parent_p);
				swap(parent_p->color,grand_parent_p->color);
				p=parent_p;






			}



		}
	     else
	    {
	    	node *sibling=grand_parent_p->left;
	    	if((sibling!=NULL) && (sibling->color==RED))
	    	{

	    		grand_parent_p->color=RED;
	    		sibling->color=BLACK;
	    		parent_p->color=BLACK;
	    		p=grand_parent_p;
	    	}
	    	else
	    	{
	    		if(p==parent_p->left)
	    		{
	    			rotateright(root,parent_p);
	    			p=parent_p;
	    			parent_p=p->parent;

	    		}
	    		rotateleft(root,grand_parent_p);
	    		swap(parent_p->color,grand_parent_p->color);
	    		p=parent_p;


	    	}

	    }
	 }
	 root->color=BLACK;
}    	
node* BSTInsert(node* root,node *temp)
{
		if(root==NULL)
		{
			return temp;

		}
		if(temp->data <root->data)
		{
			root->left=BSTInsert(root->left,temp);
			root->left->parent=root;

		}
		else if(temp->data > root->data)
		{

			root->right=BSTInsert(root->right,temp);
			root->right->parent=root;
		}
		return root;

}
void RBTree:: insert(int value)
{
	node *new_node=new node(value);
	root=BSTInsert(root,new_node);
	fix(root,new_node);


}
bstnode* bstinsert(bstnode* root,int k)
{
if(root==NULL)
	return newnode(k);
if(k< root->key)
{

root->left=bstinsert(root->left,k);

}
else if(k > root->key)
{
	root->right=bstinsert(root->right,k);
}
return root;
}
void bstinorder(bstnode* root)
{
	
    if(root!=NULL)
	{	
	bstinorder(root->left);
	cout<<root->key<<" ";
	bstinorder(root->right);


	}	
}
int height(bstnode* node)
{
	if(node==NULL)
		return 0;
	else
	{
		int lheight=height(node->left);
		int rheight=height(node->right);
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);


	}


}

void stores(bstnode* root,vector<int>&nodes)
{
	int index=0;
	if(root==NULL)
		return;
	 stores(root->left,nodes);
	nodes.push_back(root->key);
	stores(root->right,nodes);
	
}
int getbalance(bstnode* n)
{
	if(n==NULL)
		return 0;
	return (height(n->left)-height(n->right));

}

bstnode *avlleftRotate(bstnode *x)
{
	bstnode* y=x->right;
	bstnode* z=y->left;
	y->left=x;
	x->right=z;
	return y;


}
bstnode *avlrightRotate(bstnode *x)
{
	bstnode* y=x->left;
	bstnode* z=y->right;
	y->right=x;
	x->left=z;
	return y;


}
bstnode* insertavl(bstnode* node,int data)
{
	if(node==NULL)
		{
			return(newnode(data));

		}
	if( data<node->key)
	{

		node->left=insertavl(node->left,data);

	}
	else if( data>node->key)
		node->right=insertavl(node->right,data);
	int h=height(node);
	int balancefactor=getbalance(node);
		if(balancefactor>1 && data<node->left->key)
			return avlrightRotate(node);
		if(balancefactor<-1 && data>node->right->key)
			return avlleftRotate(node);
		if(balancefactor>1 && data>node->left->key)
		{
			node->left=avlleftRotate(node->left);
			return avlrightRotate(node);

		}
		if(balancefactor<-1 &&  data< node->right->key)
		{
			node->right=avlrightRotate(node->right);
			return avlleftRotate(node);
		}
		return node;

}

bstnode* buildtree(bstnode* root)
{
	
stores(root,nodes);
bstnode* avlroot=NULL;
int n=nodes.size();
for(int i=0;i<n;i++)
avlroot=insertavl(avlroot,nodes[i]);
return avlroot;
}



int rbheight(node *node)
{
	if(node==NULL)
		return 0;
	else
	{
		int lheight=rbheight(node->left);
		int rheight=rbheight(node->right);
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);


	}


}

void printlevelorder(bstnode *root)
 {

 	if(root!=NULL)
 	{
 		for(int j=0;j<level;j++)
 			cout<<"\t";
 		level++;
 		int l=height(root->left);
 		int r=height(root->right);
 		cout<<root->key;
 		if(root->left!=NULL || root->right!=NULL)
 			cout<<"["<<abs(l-r)<<"]";
 		cout<<endl;
 		printlevelorder(root->left);
 		printlevelorder(root->right);
 		level--;


 	}




}
void RBTree::rbprintlevelorder(node * root)
{
	


 	if(root!=NULL)
 	{
 		for(int j=0;j<level;j++)
 			cout<<"\t";
 		level++;
 		int l=rbheight(root->left);
 		int r=rbheight(root->right);
 		cout<<root->data;
 		if(root->left!=NULL || root->right!=NULL)
 			cout<<"["<<abs(l-r)<<"]";
 		cout<<"["<<decidecolor(root->color)<<"]";


 		cout<<endl;
 		rbprintlevelorder(root->left);
 		rbprintlevelorder(root->right);
 		level--;


 	}

}

struct bstnode* copy(struct bstnode* r)
{

	struct bstnode *new_node1;
	if(r!=NULL)
			{

				new_node1=newnode(r->key);
				new_node1->left=copy(r->left);
				new_node1->right=copy(r->right);
			}
			else 
				return NULL;
			return new_node1;
}
void printArray(int a[],int l)
{

	for(int i=0;i<l;i++)
	{

		for(int j=i;j<l;j++)
			{cout<<a[j];
				if(j!=l-1)
					cout<<"->";
			}
		cout<<endl;
	}
	

}
void bstprintpathrecur(bstnode* node,int a[],int length)

{

	if(node==NULL)
		return;
	a[length]=node->key;
	
	length++;
	if(node->left==NULL && node->right==NULL)
		printArray(a,length);
	else
	{
		bstprintpathrecur(node->left,a,length);
		bstprintpathrecur(node->right,a,length);


	}

}

int bstprintpaths(bstnode* node)
{
	int path[10000];
	bstprintpathrecur(node,path,0);


}
void rbprintpathsrecur(node * root,int a[],int length)
{

	if(root==NULL)
		return;
	a[length]=root->data;
	length++;
	if(root->left==NULL && root->right==NULL)
		printArray(a,length);
	else
	{
		rbprintpathsrecur(root->left,a,length);
		rbprintpathsrecur(root->right,a,length);
	}

}
int rbprintpaths(RBTree tree)
{
	node* root=tree.root;
	int path[10000];
	rbprintpathsrecur(root,path,0);


}

int main()
{
	struct bstnode *broot1=NULL;
	struct bstnode *avlroot=NULL;
	RBTree tree;
	while(1)
	{
cout<<"\n1. To insert a node in the BST and in the red-black tree\n";
cout<<"2. To create AVL tree from the inorder traversal of the BST\n";
cout<<"3. To print the inorder traversal of the BST/AVL/red-black tree\n";
cout<<"4. To display all the paths in the BST/AVL tree/red-black tree\n";
cout<<"5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation\n";
cout<<"6. Exit \n";
int choice;
cin>>choice;
switch(choice)
{
 case 1:
 			cout<<"enter number";
 			int n;
 			cin>>n;
 			tree.insert(n);
 			broot1=bstinsert(broot1,n);
 			cout<<"Number is inserted in BST and RB tree\n";
 			

 			break;

case 2:		avlroot=copy(broot1);
			avlroot=buildtree(avlroot);
			cout<<avlroot->key<<endl;
			cout<<"AVL tree is created\n";
			break;
case 3:  	cout<<"inorder traversal of BST is :";
			bstinorder(broot1);
			cout<<"\ninorder traversal of AVL is :";
			bstinorder(avlroot);
			cout<<"\ninorder traversal of RED black tree is ";
			tree.inorder();
			break;
case 4:	cout<<"all paths of BST are :\n";
		bstprintpaths(broot1);
		cout<<"all paths of AVL tree are:\n";
		bstprintpaths(avlroot);
		cout<<"all paths of Red black tree are:\n";
		rbprintpaths(tree);

		break;

case 5:cout<<"level wise indentation of BST is :\n";
			printlevelorder(broot1);
		cout<<"\nlevel wise indentation of AVL Tree is :\n";
			printlevelorder(avlroot);
		cout<<"\n level wise indentation of RED black tree is \n";
		tree.rbprintlevelorder(tree.root);
			break;
case 6: exit(0);





}


	}



}
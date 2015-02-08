//level order insert into a tree
//using queue


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

struct bstnode
{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};

typedef struct bstnode Bstnode;
typedef Bstnode *Bstnodeptr;


Bstnodeptr newnode(int data)
{
	Bstnodeptr temp=(Bstnodeptr)malloc(sizeof(Bstnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

//levelorder insert using queue
void insert(Bstnodeptr *root, int data)
{
	if(*root==NULL)
	{
		*root=newnode(data);
		return;
	}

	Bstnodeptr temp = *root;
	queue<Bstnodeptr> q1;

	q1.push(temp);
	while(q1.size()!=0)
	{
		temp=q1.front();
		q1.pop();

		if(temp->left==NULL) //if left empty, insrt here
		{
			temp->left=newnode(data);
			return;
		}
		else
			q1.push(temp->left); //else push it to queue

		if(temp->right==NULL) //insert here
		{
			temp->right=newnode(data);
			return;
		}
		else //or push it to queue
			q1.push(temp->right);
	}

}

void preorder(Bstnodeptr root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}


int main()
{
	Bstnodeptr root = NULL;

	int data;

	while(1)
	{
		printf("enter data or -1 to exit: ");
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root,data);
		printf("preorder : ");
		preorder(root);
		printf("\n");
	}
	return 0;
}

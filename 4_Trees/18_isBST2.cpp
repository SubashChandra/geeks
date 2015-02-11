//given a tree check if its binary or not
//ech node visited only once
//O(n) time
//O(n) space

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


int getMax(Bstnodeptr root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root->data;
}


int getMin(Bstnodeptr root)
{

	while(root->left!=NULL)
		root=root->left;
	return root->data;
}


//isbst utility func
int isBstUtil(Bstnodeptr root, int min, int max)
{
	if(root==NULL)
		return 1;

	if(root->data <min || root->data>max)
		return 0;

	return isBstUtil(root->left,min,root->data-1) && isBstUtil(root->right,root->data+1,max);
}





int isBST(Bstnodeptr root)
{
	return isBstUtil(root, -1000,1000); //int_min ,int_max
}


int main()
{
	Bstnodeptr root = NULL;

	int data;

	printf("tree: ");
	while(1)
	{
		printf("enter data or -1 to exit: ");
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(&root,data);
	}
	printf("preorder : ");
	preorder(root);
	printf("\n");

	printf("%s\n",isBST(root)?"yes":"no");

	return 0;
}

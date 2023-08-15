#include<iostream>
using namespace std;

struct Node 
{
	int val;
	Node *right; 
	Node *left;
};

void init(Node *&root)
{
	root = NULL;
}

Node *createNode(int val)
{
	Node *temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->val = val; 
	return temp;
}

void insertNode(Node *&root,int val)
{
	Node *p = createNode(val);
	if(root == NULL)
	{
		root = p;
	}
	else
	{
		Node *q = root;
		while(q != NULL && q->val != val)
		{
			if(q->val < val)
			{
				if(q->right == NULL)
				{
					q->right = p;
					break;
				}
				else
					q = q->right;
			}
			else if(q->val > val)
			{
				if(q->left == NULL)
				{
					q->left = p;
					break;
				}
				else
					q = root->left;
			}
		}
	}
}

Node *searchNode(Node *root,int val)
{
		Node *p = root;
		while(p->val != val && p != NULL)
		{
			if(p->val <= val)
				p = p->right;
			else
				p = p->left;
		}
		return p;
}

void deleteNode(Node *&root, int x) {
   if(root != NULL)
   {
	Node *p = root;
	Node *parent = NULL;
	while(p != NULL && p->val != x)
	{
		parent = p;
		if(p->val < x)
			p = p->right;
		else
			p = p->right;
	}
	if (p != NULL)
    {
        if (p->left != NULL && p->right != NULL) // nút cần xoá có 2 cây con
        {
            parent = p;
            Node *t = p->right;
            while (t->left != NULL)
            {
                parent = t;
                t = t->left;
            }
            p->val = t->val;
            p = t;
        }
        
        Node *r = NULL;
        if (p->left == NULL)
            r = p->right;
        else
            r = p->left;
        
        if (parent == NULL) // nút cần xoá là nút gốc
            root = r;
        else
            if (parent->val > p->val)
                parent->left = r;
            else
                parent->right = r;

       delete p;
    }
}
}



void NLR(Node *root)
{
	if(root != NULL)
	{
		cout<<root->val<<" ";
		NLR(root->left);
		NLR(root->right);
	}
}

int main()
{
	Node *root;
	init(root);
	insertNode(root,10);
	insertNode(root,20);
	insertNode(root,5);
	insertNode(root,7);
	insertNode(root,30);
	insertNode(root,9);
	insertNode(root,17);
	NLR(root);
	cout<<endl;
	deleteNode(root,30);
	NLR(root);
	cout<<endl;
	return 0;
}
#include<iostream>
using namespace std;
class BST
{
 struct node
 {
  int val;
  node *left;
  node *right;
 };
 node *root;
 node* Create_BST(int item);
 public:
 BST(); 
 //Insert data In BST 
 void Insert_BST(int item);
 //delete value and return node adress
 node* delete_BST(node *root,int item);
 //Assign address in root 
 void root_pro(node *t);
 //delete value and return deleteting value 
 int Delete_BST(int item);
 //search value in BST and return value
 int Search_Val(int item);
 //Search value and Return Node Adress
 node* Search_BST(int item);
 //Travceing in PreOrder
 void PreOrder(node *root);
 //Travceing in InOrder
 void InOrder(node *root);
 //Travceing in PostOrder
 void PostOrder(node *root);
 //Return root Address
 node* Root();
 //Return Parent Node Adress from child->val = item which child node value 
 node* Parent_Node(node *root,int item);
 //Return InOrder Preceder from pointer t 
 node* InOrderPre(node *t);
 //Return InOrder Successer from pointer t
 node* InOrderSucc(node *t);
 //return the left child given node 
 node* Left_Child(node *t);
 //return the right child given node
 node* Right_Child(node *t);
 //return the parent node address from given node 
 node* parentNode(node *r);
 //rotation from left left 
 void lLRotation(node *t);
 //rotation from right right
 void rRRotation(node *t);
 //rotation from left right 
 void lRRotation(node *t);
 //rotation from right left 
 void rLRotation(node *t);
 //return balance factor of node 
 int balanceFactor(node *root);
 // return unbalanced factor node address
 node* unbalanceNode(node *t);
 //Rotation of node 
 int Rotation(node *t);
 node* Max_Element(node *t);
 node* Min_Element(node *t);
 void Swap_Val(node *t,node *r);
 //number of node in the tree or BST 
 int treeSize(node *root);
 //return height of given node 
 int treeHeight(node *root);
};
void BST :: root_pro(node *t)
{
 root=t;
}
int BST :: treeSize(node *root)
{
 if(root==NULL)
 return 0;
 else
 return 1+treeSize(root->left)+treeSize(root->right);
}
int BST :: treeHeight(node *r)
{
 if(r==NULL)
 return -1;
 else
 return (1+(treeHeight(r->left)>treeHeight(r->right)?treeHeight(r->left): treeHeight(r->right)));
}
BST :: node* BST :: Root()
{
 return(root);
}
BST :: BST()
{
 root=NULL;
}
BST :: node* BST :: parentNode(node *r)
{
 node *t=root;
 if(t==r)
 {
  t=NULL;
  return t;
 }
 while(t->left!=NULL||t->right!=NULL)
 {
  if(t->left==r)
   return t;
  if(t->right==r)
   return t;
  if(t->val>r->val)
   t=t->left;
  else if(t->val<r->val)
   t=t->right;
 }
}
int BST :: balanceFactor(node* root)
{
 int lH=treeHeight(root->left);
 int rH=treeHeight(root->right);
 if(lH>=rH)
  return(lH-rH);
 else
  return(rH-lH);
}
BST :: node*  BST :: unbalanceNode(node* t)
{
 node *p;
 p=parentNode(t);
 if(p==NULL)
  return p;
 if(balanceFactor(p)<=1){
  if(p==root)
  {p=NULL; return p;}
  unbalanceNode(p);
  //if()
 }
 else 
  return p;
 
}
void BST :: lLRotation(node *t)
{
 node *b=t->left;
 b->right=t;
}
void BST :: rRRotation(node *t)
{
 node *b=t->right;
 b->left=t;
}
void BST :: lRRotation(node *t)
{
 node *b=t->left;
 node *c = b->right;
 c->left = b;
 c->right = t;
}
void BST :: rLRotation(node *t)
{
 node *b=t->right;
 node *c = b->left;
 c->left = t;
 c->right = b;
}
BST :: node*  BST :: Create_BST(int item)
{
 node *t;
 t=(node*)new node;
 t->left=NULL;
 t->right=NULL;
 t->val=item;
 return(t);
}
int BST :: Search_Val(int item)
{
 node *t;
 t=Search_BST(item);
 return(t->val);
}
BST :: node* BST :: Search_BST(int item)
{
 node *t=root;
 while(t!=NULL)
 {
  if(t->val==item)
  return(t);
  else if(t->val<item)
  t=t->right;
  else
  t=t->left;
 }
 return(t);
}
int BST :: Rotation(node *t)
{
 node *b=unbalanceNode(t);
 if(b==NULL)
 return 1;
 cout<<b->val<<endl;
 if(b->left->left==t)
 lLRotation(b);
 else if(b->right->right==t)
 lLRotation(b);
 else if(b->left->right==t)
 lLRotation(b);
 else if(b->right->left==t)
 lLRotation(b);
 return 0;
}
void BST :: Insert_BST(int item)
{
 node *n;
 n=Create_BST(item);
 if(root==NULL)
 root=n;
 else
 {
  node *t=root;
  while(t!=NULL)
  {
   if(t->val>n->val)
   {
    if(t->left==NULL)
    {
     t->left=n;
     break;
    }
    t=t->left;
   }
   if(t->val<n->val)
   {
    if(t->right==NULL)
    {
     t->right=n;
     break;
    }
    t=t->right;
   }
  }
 }
 //node *t=unbalanceNode(n);
 //cout<<t->val<<endl;
 Rotation(n);
}
BST :: node* BST :: InOrderPre(node *t)
{
 t=t->left;
 while(t->right!=NULL)
 t=t->right;
 return(t);
}
BST :: node* BST :: InOrderSucc(node *t)
{
 t=t->right;
 while(t->left!=NULL)
 t=t->left;
 return(t);
}
BST :: node* BST :: delete_BST(node *root,int item)
{
 node *in; 
 if(root==NULL)
 return root;
 if(root->left==NULL&&root->right==NULL)
 {
  delete(root);
  return(root);
 }
 if(root->val>item)
 delete_BST(root->left,item);
 else if(root->val<item)
 delete_BST(root->right,item);
 else
 {
  in=InOrderPre(root);
  root->val=in->val;
  root->left=delete_BST(root->left,in->val);
 }
 return(root);
}
int BST :: Delete_BST(int item)
{
 if(root==NULL){
 cout<<"Tree is Empty"<<endl;
 return 0;
 }
 if(root->val==item&&(root->left==NULL&&root->right==NULL))
 { 
  int d = root->val;
  root=NULL;
  return d;
 }
 node *t,*p,*In;
 //t=root;
 t=Search_BST(item);
 if(t==NULL)
 {
  cout<<"Data Not Found"<<endl;
  return 0;
 }
 if(t->left!=NULL)
 {
  //lr=Left_Child(t);
  //cout<<lr->val<<endl;
  //m=Max_Element(lr);
  //cout<<m->val<<endl;
  In=InOrderPre(t);
  p=parentNode(In);
 // cout<<p->val<<endl;
  Swap_Val(t,In);
  //cout<<t->val<<" "<<m->val<<endl;
  if(p->left==In){
  p->left=In->left;
  In->left=NULL;
  }
  else if(p->right==In){
  p->right=In->left;
  In->left=NULL;}
  return(In->val);
/* if(p==t)
  {
   if(p->left==m)
   {
    p->left=m->right;
    m->right=NULL;
   }
   else if(p->right==m)
   {
    p->right=m->left;
    m->left=NULL;
   }
   return(m->val);
  }
  p->right=m->left;
  m->left=NULL;
  return(m->val);*/
 }
 else if(t->right!=NULL)
 {
  //lr=Right_Child(t);
  //m=Min_Element(lr);
  In=InOrderSucc(t);
  p=parentNode(In);
  Swap_Val(t,In);
  if(p->left==In){
  p->left=In->right;
  In->right=NULL;}
  else if(p->right==In){
  p->right=In->right;
  In->right=NULL;
  }
  return(In->val);
 /* if(p==t)
  {
   if(p->left==m)
   {
    p->left=m->right;
    m->right=NULL;
   }
   else if(p->right==m)
   {
    p->right=m->left;
    m->left=NULL;
   }
   return(m->val);
  }
  p->left=m->right;
  m->right=NULL;
  return(m->val);*/
 }
 else
 {
  p=parentNode(t);
  if(p->left==t)
  p->left=NULL;
  if(p->right==t)
  p->right=NULL;
  return(t->val);
 }
 cout<<"Data Not Found"<<endl;
 delete(p);
 delete(In);
 delete(t);
 return(item);
}
BST :: node* BST :: Max_Element(node *t)
{
 while(t->right!=NULL)
 t=t->right;
 return(t);
}
BST :: node* BST :: Min_Element(node *t)
{
 while(t->left!=NULL)
 t=t->left;
 return(t);
}
void BST :: Swap_Val(node *t,node *r)
{
 int temp;
 temp=t->val;
 t->val=r->val;
 r->val=temp;
}
void BST :: InOrder(node *r)
{
 if(r!=NULL)
 {
  PreOrder(r->left);
  cout<<r->val<<" ";
  PreOrder(r->right);
 }
}
void BST :: PreOrder(node *r)
{
 if(r!=NULL)
 {
  cout<<r->val<<" ";
  InOrder(r->left);
  InOrder(r->right);
 }
}
void BST :: PostOrder(node *r)
{
 if(r!=NULL)
 {
  PostOrder(r->left);
  PostOrder(r->right);
  cout<<r->val<<" ";
 }
}
/*
BST :: node* BST :: Parent_Node(node *t,int item)
{
 if(t->val==root->val)
 return(root);
 if(t!=NULL)
 {
  if(t->left->val==item)
  return(t);
  if(t->right->val==item)
  return(t);
  if(t->val>item)
  t=Parent_Node(t->left,item);
  if(t->val<item)
  t=Parent_Node(t->right,item);
 }
 return(t);
}*/
BST :: node* BST :: Left_Child(BST :: node *t)
{
 //if(t->left!=NULL)
 return(t->left);
 //else
// return(t->left)
}
BST :: node* BST :: Right_Child(BST :: node *t)
{
 //if(t->right!=NULL)
 return(t->right);
}
int main()
{
 BST b1;
 b1.Insert_BST(20);
 b1.Insert_BST(10);
 b1.Insert_BST(5);
 b1.Insert_BST(30);
 b1.Insert_BST(25);
 b1.Insert_BST(15);
 b1.Insert_BST(40);
 b1.Insert_BST(18);
 b1.Insert_BST(17);
 //b1.Rotation(b1.Search_BST(40));
 //cout<<b1.Delete_BST(5)<<endl;
 cout<<b1.treeSize(b1.Root())<<endl;
 cout<<b1.treeHeight(b1.Root())<<endl;
 cout<<b1.balanceFactor(b1.Root())<<endl;
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 //cout<<b1.Search_Val(50)<<endl;
 //cout<<b1.Max_Element(b1.Root())<<endl;
 //cout<<b1.Min_Element(b1.Root())<<endl;
 b1.Delete_BST(15);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Delete_BST(40);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Delete_BST(20);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 cout<<b1.Delete_BST(17)<<endl;
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 cout<<b1.Delete_BST(18)<<endl;
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 cout<<b1.Delete_BST(10)<<endl;
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 cout<<b1.Delete_BST(25)<<endl;
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Delete_BST(5);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Delete_BST(30);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Delete_BST(20);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 b1.Insert_BST(20);
 b1.Insert_BST(10);
 b1.Insert_BST(5);
 b1.Insert_BST(30);
 b1.Insert_BST(25);
 b1.Insert_BST(15);
 b1.Insert_BST(40);
 b1.Insert_BST(18);
 b1.Insert_BST(17);
 b1.InOrder(b1.Root());
 cout<<endl;
 b1.PreOrder(b1.Root());
 cout<<endl;
 b1.PostOrder(b1.Root());
 cout<<endl;
 return 0;
}
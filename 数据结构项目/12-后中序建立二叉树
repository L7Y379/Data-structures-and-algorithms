#include<stdio.h>
#include<stdlib.h>
#define Max 100 

typedef struct
{
    int data[Max];
    int top;
}stack;

typedef   struct  Node {   
    datatype   data; 
    struct Node *lchild,  *rchild,  *parent; 
} BinTNode,*BinTree;  

void PreInOrd( char preord[], char inord[], int i, int j, int k, int h, BinTree t){ 
/* 先序序列中从i到j，中序从序列从k到h，建立一棵二叉树放在t中*/ 
    int m; 
    (*t)=new BiNode; 
    (*t)->data=preord[i];  /*二叉树的根*/ 
    m=k; 
    while (inord[m]!=preord[i]) m++; /*在中序序列中定位树根*/ 
      /*递归调用建立左子树*/ 
    if(m==k) (*t)->lchild=NULL;    /*左子树空*/ 
    else PreInOrd(preord, inord, i+1, i+m-k, k, m-1, &((*t)->lchild)); /*递归调用建立右子树*/ 
    if(m==h) (*t)->rchild=NULL;   /*右子树空*/ 
    else PreInOrd( preord, inord, i+m-k+1, j, m+1, h, &((*t)->lchild)); 
} 
void CreateBinTree(char preord[], char inord[], int n, BinTree root){ 
    /* n 为二叉树结点的个数，建立的二叉树放在root中*/ 
    if(n<=0) root=NULL; 
    else 
    PreInOrd(preord, inord, 1, n,1, n, &root); 
} 

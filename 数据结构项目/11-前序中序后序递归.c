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


void PreOrderNoRec (BinTree BT)  { //前序遍历非递归算法 
    stack S;  
    BinTree p=BT->root;   
    while ((p != NULL) || !StackEmpty(S)){ 
        if (p!=NULL){ 
	       printf ("%c", p->data);  /*访问当前结点*/ 
            Push (S,p);                    /*将p压入栈S*/ 
            p = p->lchild; 
        }             /*将p指向其左子树*/ 
	   else{ 
	       p = Top(S);  
            Pop(S);                    /*从栈S弹出栈顶元素*/ 
            p = p->rchild; 
        }       /*将p指向其右子树*/ } 
}

void InOrderNoRec (BinTree BT)  { //中序遍历非递归算法
     stack S;  
	BinTree p=BT->root;   
	while ((p != NULL) || !StackEmpty(S)) 
 	{ 
	    if (p!=NULL){ Push (S,p);  /*将p压入栈S*/    
	        p = p->lchild; 
         }  /*将p指向其左子树*/ 
	    else{ 
	        p = Top(S);  
             Pop(S);  /*从栈S弹出栈顶元素*/       
		   printf ("%c", p->data);  /*访问当前结点*/ 
             p = p->rchild; 
         }  /*将p指向其右子树*/ 
     } 
}

void PostOrderNoRec (BinTree BT)  {    //后序遍历非递归算法
    stack S, tag;  BinTree p=BT->root;   
    while ((p != NULL) || !StackEmpty(S)) { 
         while (p!=NULL) { 
	        Push (S,p);  
		   Push (tag,0);  
		   p = p->lchild; 
	    }  /*扫描左子树*/       
	    if(!StackEmpty(S)){ 
	        if (Pop(tag)==1) /*左右子树均访问*/
		   {    p = Top(S); 
		        Pop(S); 
			   printf ("%c", p->data);  
			   Pop(tag); 
		   }  /*访问并出栈*/ 
		   else { 
		        p=Top(s);           
			   if(!StackEmpty(S))  /*扫描右子树*/ 
                  {    p = p->rchild;  
			        Pop(tag); 
				   Push(tag,1); 
			   } 
		   }
	    } 
     } 
}
 




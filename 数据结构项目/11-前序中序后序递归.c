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


void PreOrderNoRec (BinTree BT)  { //ǰ������ǵݹ��㷨 
    stack S;  
    BinTree p=BT->root;   
    while ((p != NULL) || !StackEmpty(S)){ 
        if (p!=NULL){ 
	       printf ("%c", p->data);  /*���ʵ�ǰ���*/ 
            Push (S,p);                    /*��pѹ��ջS*/ 
            p = p->lchild; 
        }             /*��pָ����������*/ 
	   else{ 
	       p = Top(S);  
            Pop(S);                    /*��ջS����ջ��Ԫ��*/ 
            p = p->rchild; 
        }       /*��pָ����������*/ } 
}

void InOrderNoRec (BinTree BT)  { //��������ǵݹ��㷨
     stack S;  
	BinTree p=BT->root;   
	while ((p != NULL) || !StackEmpty(S)) 
 	{ 
	    if (p!=NULL){ Push (S,p);  /*��pѹ��ջS*/    
	        p = p->lchild; 
         }  /*��pָ����������*/ 
	    else{ 
	        p = Top(S);  
             Pop(S);  /*��ջS����ջ��Ԫ��*/       
		   printf ("%c", p->data);  /*���ʵ�ǰ���*/ 
             p = p->rchild; 
         }  /*��pָ����������*/ 
     } 
}

void PostOrderNoRec (BinTree BT)  {    //��������ǵݹ��㷨
    stack S, tag;  BinTree p=BT->root;   
    while ((p != NULL) || !StackEmpty(S)) { 
         while (p!=NULL) { 
	        Push (S,p);  
		   Push (tag,0);  
		   p = p->lchild; 
	    }  /*ɨ��������*/       
	    if(!StackEmpty(S)){ 
	        if (Pop(tag)==1) /*��������������*/
		   {    p = Top(S); 
		        Pop(S); 
			   printf ("%c", p->data);  
			   Pop(tag); 
		   }  /*���ʲ���ջ*/ 
		   else { 
		        p=Top(s);           
			   if(!StackEmpty(S))  /*ɨ��������*/ 
                  {    p = p->rchild;  
			        Pop(tag); 
				   Push(tag,1); 
			   } 
		   }
	    } 
     } 
}
 




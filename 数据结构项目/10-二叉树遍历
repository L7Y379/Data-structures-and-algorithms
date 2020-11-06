#include<stdio.h>
#include<stdlib.h>
typedef   struct  Node {   
    datatype   data; 
    struct Node *lchild,  *rchild,  *parent; 
} BinTNode,*BinTree;  

void LevelOrderTraverse(BinTree bt){ //层次遍历 
   BinTreeNode Queue[MAXNODE];  /*定义队列*/ 
   int front, rear; 
   if (bt==NULL) return; /*空二叉树，遍历结束*/ front=-1; rear=0; 
   Queue[rear]=bt; /*根结点入队列*/ 
   while(rear!=front){ /*队列不空，继续遍历，否则，遍历结束*/       
      front++;  /*出队*/ 
      visit(Queue[front]->data);  /*访问刚出队的元素*/       
	 if (queue[front]->lchild!=NULL){ /*如果有左孩子，左孩子入队*/              
	       rear++; 
            Queue[rear]=Queue[front]->lchild; 
      } 
      if (queue[front]->rchild!=NULL){  /*如果有右孩子，右孩子入队*/            
	       rear++; 
            Queue[rear]=Queue[front]->rchild; 
      } 
   } 
} 

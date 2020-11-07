#include<stdio.h> 
# define MAXSIZE 100; 
typedef  int  ElemType; 
typedef struct { 
     ElemType data[MAXSIZE];      
	int front;      
	int rear; 
} CirQueue; 

void EnCirQueue(CirQueue  &Q,ElemType x)    //循环队列入队操作
{ 
     if ((Q.rear+1) %MAXSIZE == Q.front ) 
     { 
          printf("队列已满，无法进行插入！");           
		exit(0);      
     } 
      Q.rear =(Q.rear+1) %MAXSIZE; 
      Q.data[Q.rear]=x; 
} 

Elemtype DeCirQueue(CirQueue  &Q)           //循环队列出队操作
{ 
     if (Q.rear == Q.front ) 
     { 
          printf("队列已空，无法进行出队操作！");           
		exit(0); 
     } 
      Q.front=(Q.front+1)  % MAXSIZE; 
      return (Q.data[Q.front]); 
}

int em(CirQueue  &Q)                    //循环队列判空 
{
     if (Q.rear == Q.front ) 
     { 
          return 1;
     }
	else 
	     return 0; 
}

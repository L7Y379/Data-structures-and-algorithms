#include<stdio.h>
#include<stdlib.h> 

struct Node {                        /*链式队列的结点结构*/       
    ElemType  data;             /*队列的数据元素类型*/       
    struct Node  *next;         /*指向后继结点的指针*/ 
}; 
typedef struct node LQNode； 
typedef struct node *LinkedQNode； 
struct Queue{                      /*封装的链式队列*/         
    LQNode  	*front;           /*队头指针*/ 
    LQNode *rear;            /*队尾指针*/ 
}; 
typedef struct Queue LQueue； 
typedef struct Queue *LinkedQueue； 

void  LinkedQueueInit(LinkedQueue  Q)      //链式队列的初始化 
{   LinkedQNode  p = (LinkedQNode) malloc(sizeof(LQNode));      
    if  (p==NULL) 
     {   
	printf("头结点空间申请失败！");          
	exit(0); 
     } 
     else 
     {      p->next=NULL; 
            Q->rear=p; 
            Q->front=p; 
     } 
} 
 
int  LinkedQueueEmpty(LinkedQueue  Q)   //链式队列的判空操作
{    
    if  (Q->front== Q->rear)  
              return 1;      
    else                
		    return 0; 
} 

void  EnLinkedQueue (LinkedQueue  Q,ElemType x)  {  //链式队列的入队操作  
    LinkedQNode q = (LinkQNode) malloc(sizeof(LQNode));      
    if  (q==NULL) 
    {   
         printf("空间申请失败！"); 
         exit(0); 
    } 
    else 
    {    
         q->data=x             
         q->next=NULL;            
         Q->rear->next=q;             
	    Q->rear=q; 
    } 
} 

Elemtype  OutLinkedQueue (LinkedQueue  Q)  {    //链式队列的出队操作 
     if  (Q->front==Q->rear) 
     {   
	    printf("队列为空，无法进行出队操作！");          
	    exit(0); 
     }     
     LinkedQNode q=Q->front->next;       
     Q->front->next=q->next; 
     x=q->data;         
     free(q); 
     if    (Q->front->next=NULL)   
         Q->rear=Q->front;        
	    return x; 
} 

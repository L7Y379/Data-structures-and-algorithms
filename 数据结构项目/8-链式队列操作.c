#include<stdio.h>
#include<stdlib.h> 

struct Node {                        /*��ʽ���еĽ��ṹ*/       
    ElemType  data;             /*���е�����Ԫ������*/       
    struct Node  *next;         /*ָ���̽���ָ��*/ 
}; 
typedef struct node LQNode�� 
typedef struct node *LinkedQNode�� 
struct Queue{                      /*��װ����ʽ����*/         
    LQNode  	*front;           /*��ͷָ��*/ 
    LQNode *rear;            /*��βָ��*/ 
}; 
typedef struct Queue LQueue�� 
typedef struct Queue *LinkedQueue�� 

void  LinkedQueueInit(LinkedQueue  Q)      //��ʽ���еĳ�ʼ�� 
{   LinkedQNode  p = (LinkedQNode) malloc(sizeof(LQNode));      
    if  (p==NULL) 
     {   
	printf("ͷ���ռ�����ʧ�ܣ�");          
	exit(0); 
     } 
     else 
     {      p->next=NULL; 
            Q->rear=p; 
            Q->front=p; 
     } 
} 
 
int  LinkedQueueEmpty(LinkedQueue  Q)   //��ʽ���е��пղ���
{    
    if  (Q->front== Q->rear)  
              return 1;      
    else                
		    return 0; 
} 

void  EnLinkedQueue (LinkedQueue  Q,ElemType x)  {  //��ʽ���е���Ӳ���  
    LinkedQNode q = (LinkQNode) malloc(sizeof(LQNode));      
    if  (q==NULL) 
    {   
         printf("�ռ�����ʧ�ܣ�"); 
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

Elemtype  OutLinkedQueue (LinkedQueue  Q)  {    //��ʽ���еĳ��Ӳ��� 
     if  (Q->front==Q->rear) 
     {   
	    printf("����Ϊ�գ��޷����г��Ӳ�����");          
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

#include<stdio.h>
#include<stdlib.h> 
#define maxSize 100         //最大允许长度 

typedef char ElemType; 
struct Node {          	               //链表结点           
      ElemType  data;                   //结点数据域           
	 struct Node * next;               //结点指针域 
}; 
typedef  struct Node LNode;      
typedef  struct Node *LinkedList;
LNode * Head;                          //链表头指针

int LinkedListInit1(LNode *L) //不带头的单链表初始化 
   {    
         L=NULL;  
         return 1;     }


int LinkedListLength(LNode *L) //不带头单链表求长度 
{ 
    Lnode *p;       	//p需要声明为Lnode指针类型     
    p=L;     
    j=0; 
    while(p!=NULL) 
    {   
        j++; 
        p=p->next;       //将p向下移动一个结点 
    } 
    return j; 
}

LNode  LinkedListGet(LNode *L,int i) //不带头单链表取元素的算法
{ 
    Lnode  *p=L; 
    int j=1; 
    while((p!=NULL)&&(j<i)) 
    {  
        p=p->next;         
	   j++; 
    } 
    return p; 
}

LNode LinkedListLocate(LNode *L, ElemType e)//不带头单链表的定位操作 
{ 
    LNode *p=L; 
    while((p! = NULL)&&(p->data !=  e))        
    p=p->next;     
    return p; 
}

int LinkedListInsert(LNode *L, LNode * p,ElemType e){   //不带头单链表的插入操作代码
    LNode *q=(LNode *)malloc(sizeof(LNode));   //创建一个新的结点q     
    if(q==NULL) 
    {   printf("申请空间失败！");         
    return 0;     
    }     
    q->data=e; 
    if(p==L)       	 	//在表头插入 
    {   
    q->next=L;     
    L=q;     
    exit(0);      
    } 
     //在表的中间或末尾进行插入 
    LNode *pre=L;  
    while((pre!=NULL)&&(pre->next!=p)) 
    pre=pre->next;//找P前驱      
    q->next=pre->next;      
    pre->next=q;      
    return 1; 
}


void LinkedListDel(LNode *L, ElemType e) {  //不带头单链表的删除操作代码 
    Lnode *pre=L;      
    Lnode * p;      
    if (L->data==e)  
    {p=L;L=L->next; free(p);}      
    else {           //查找e的前驱 
       while((pre!=NULL)&&(pre->next->data!=e)) 
	     pre=pre->next; 
       if(pre!=NULL) //找到需要删除的结点 
       {  p=pre->next;            
	     pre->next=p->next;             
		free(p); 
       } 
    } 
}
 
int main(){
	int i,j;
	ElemType e;
	LNode * p;
	LNode *L1,*L2,*L3;
	ElemType a[100];
	LinkedListInit(L1);
	LinkedListInit(L2);
	LinkedListInit(L3);
	LinkedListLength(L1);
	LinkedListGet(L1,i);
	LinkedListLocate(L1,e);
	LinkedListInsert(L1,p,e);
	LinkedListDel(L1,e);
	return 0;
}
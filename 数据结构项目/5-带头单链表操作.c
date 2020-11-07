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
LNode * Head;                           //链表头指针

int LinkedListInit(LNode *L){          //带头的单链表初始化 
      L=(LNode *)malloc(sizeof(LNode));        
      if(L==NULL){
      printf("申请空间失败！"); 
      return 0;        
      }
      L->next=NULL;        
	 return 1; 
}

int LinkedListLength(LNode *L) //带头单链表求长度 
{ 
    Lnode *p;       	//p需要声明为Lnode指针类型     
    p=L->next;     
    j=0; 
    while(p!=NULL) 
    {   
        j++; 
        p=p->next;       //将p向下移动一个结点 
    } 
    return j; 
}

LNode  LinkedListGet(LNode *L,int i) //带头单链表取元素的算法
{ 
    Lnode  *p=L->next; 
    int j=1; 
    while((p!=NULL)&&(j<i)) 
    {  
        p=p->next;         
	   j++; 
    } 
    return p; 
}

LNode LinkedListLocate(LNode *L, ElemType e)//带头单链表的定位操作 
{ 
    LNode *p=L->next; 
    while((p! = NULL)&&(p->data !=  e))        
    p=p->next;     
    return p; 
}

int LinkedListInsert(LNode *L, LNode * p,ElemType e){   //带头单链表的插入操作代码
    LNode * q=(LNode *)malloc(sizeof(LNode));//创建一个新的结点q     
    if(q==NULL) 
    {   printf("申请空间失败！"); 
        return 0; 
    } 
    q->data=e;               //插入新结点     
    LNode * pre=L; 
    while((pre!=NULL)&&(pre->next!=p)) 
    pre=pre->next;           //找P前驱     
    q->next=pre->next;     
    pre->next=q;     
    return 1; 
}

void LinkedListDel(LNode *L, ElemType e) { //带头单链表的删除操作代码
    Lnode * pre=L;       //查找e的前驱 
    while((pre!=NULL)&&(pre->next->data!=e)) pre=pre->next;      
    Lnode * p=pre->next; 
    if(p!==NULL)        //找到需要删除的结点 
    { 
        pre->next=p->next;         
	   free(p); 
    } 
}
 
int LinkedListCreate1(LNode *&L, ElemType a[],int n) {  //用头插法创建带头结点的单链表   
    LNode * pre=L; 
    L=(LNode *)malloc(sizeof(LNode)); 
    if(L==NULL)    {  
    printf("申请空间失败！");return 0;    
    }     
    L->next=NULL; 
    for(int i=n-1;i>=0;i--) 
    {  LNode *p=(LNode *)malloc(sizeof(LNode));         
    if(p==NULL)  {  
        printf("申请空间失败！");
	   return 0;   
	   }         
	   p->data=a[i]; 
        p->next=L->next;        
	   L->next=p; 
    } 
    return 1; 
} 

int LinkedListCreate2(LNode *&L, ElemType a[],int n) //用尾插法创建带头结点的单链表
{  L=(LNode *)malloc(sizeof(LNode)); 
    if(L==NULL)    {  
    printf("申请空间失败！"); return 0;    
    }     
    L->next=NULL; 
    LNode * tail=L;        //设置一个尾指针，方便插入     
    for(int i=0;i<n;i++) 
    {  
    LNode *p=(LNode *)malloc(sizeof(LNode));         
    if(p==NULL) {  
        printf("申请空间失败！");  
	   return 0; } 
        p->data=a[i];      
	   p->next=NULL;         
	   tail-> next=p;      
	   tail=p; 
    } 
    return 1; 
}
 
void LinkedListMerge(LNode *La, LNode *Lb, LNode *&Lc)  //带头结点的单链表保序合并操作 
{   LNode *pa, pb, pc;     
    pa=La->next;   
    pb=Lb->next; 
    Lc=La;     
    pc=Lc;   //借用表La的头结点作为表Lc的头结点 
    while((pa!=NULL)&&(pb!=NULL))     {   
        if(pa->data<=pb->data) 
         {   
	    pc->next=pa;     
	    pc=pa;     
	    pa=pa->next;   
	    }          
	    else 
         {   
	    pc->next=pb;     
	    pc=pb;     
	    pb=pb->next;  
	    } 
    } 
    if(pa!=NULL) 
    pc->next=pa; 
    else pc->next=pb; 
    free(Lb);            //将Lb的表头释放 
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
	LinkedListCreate1(L1,a,n);
	LinkedListCreate2(L2,a,n);
	LinkedListMerge(L1, L1, L3);
	return 0;
} 





 
 


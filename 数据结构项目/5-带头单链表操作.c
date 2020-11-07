#include<stdio.h>
#include<stdlib.h> 
#define maxSize 100         //��������� 

typedef char ElemType; 
struct Node {          	               //������           
      ElemType  data;                   //���������           
	 struct Node * next;               //���ָ���� 
}; 
typedef  struct Node LNode;      
typedef  struct Node *LinkedList;
LNode * Head;                           //����ͷָ��

int LinkedListInit(LNode *L){          //��ͷ�ĵ������ʼ�� 
      L=(LNode *)malloc(sizeof(LNode));        
      if(L==NULL){
      printf("����ռ�ʧ�ܣ�"); 
      return 0;        
      }
      L->next=NULL;        
	 return 1; 
}

int LinkedListLength(LNode *L) //��ͷ�������󳤶� 
{ 
    Lnode *p;       	//p��Ҫ����ΪLnodeָ������     
    p=L->next;     
    j=0; 
    while(p!=NULL) 
    {   
        j++; 
        p=p->next;       //��p�����ƶ�һ����� 
    } 
    return j; 
}

LNode  LinkedListGet(LNode *L,int i) //��ͷ������ȡԪ�ص��㷨
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

LNode LinkedListLocate(LNode *L, ElemType e)//��ͷ������Ķ�λ���� 
{ 
    LNode *p=L->next; 
    while((p! = NULL)&&(p->data !=  e))        
    p=p->next;     
    return p; 
}

int LinkedListInsert(LNode *L, LNode * p,ElemType e){   //��ͷ������Ĳ����������
    LNode * q=(LNode *)malloc(sizeof(LNode));//����һ���µĽ��q     
    if(q==NULL) 
    {   printf("����ռ�ʧ�ܣ�"); 
        return 0; 
    } 
    q->data=e;               //�����½��     
    LNode * pre=L; 
    while((pre!=NULL)&&(pre->next!=p)) 
    pre=pre->next;           //��Pǰ��     
    q->next=pre->next;     
    pre->next=q;     
    return 1; 
}

void LinkedListDel(LNode *L, ElemType e) { //��ͷ�������ɾ����������
    Lnode * pre=L;       //����e��ǰ�� 
    while((pre!=NULL)&&(pre->next->data!=e)) pre=pre->next;      
    Lnode * p=pre->next; 
    if(p!==NULL)        //�ҵ���Ҫɾ���Ľ�� 
    { 
        pre->next=p->next;         
	   free(p); 
    } 
}
 
int LinkedListCreate1(LNode *&L, ElemType a[],int n) {  //��ͷ�巨������ͷ���ĵ�����   
    LNode * pre=L; 
    L=(LNode *)malloc(sizeof(LNode)); 
    if(L==NULL)    {  
    printf("����ռ�ʧ�ܣ�");return 0;    
    }     
    L->next=NULL; 
    for(int i=n-1;i>=0;i--) 
    {  LNode *p=(LNode *)malloc(sizeof(LNode));         
    if(p==NULL)  {  
        printf("����ռ�ʧ�ܣ�");
	   return 0;   
	   }         
	   p->data=a[i]; 
        p->next=L->next;        
	   L->next=p; 
    } 
    return 1; 
} 

int LinkedListCreate2(LNode *&L, ElemType a[],int n) //��β�巨������ͷ���ĵ�����
{  L=(LNode *)malloc(sizeof(LNode)); 
    if(L==NULL)    {  
    printf("����ռ�ʧ�ܣ�"); return 0;    
    }     
    L->next=NULL; 
    LNode * tail=L;        //����һ��βָ�룬�������     
    for(int i=0;i<n;i++) 
    {  
    LNode *p=(LNode *)malloc(sizeof(LNode));         
    if(p==NULL) {  
        printf("����ռ�ʧ�ܣ�");  
	   return 0; } 
        p->data=a[i];      
	   p->next=NULL;         
	   tail-> next=p;      
	   tail=p; 
    } 
    return 1; 
}
 
void LinkedListMerge(LNode *La, LNode *Lb, LNode *&Lc)  //��ͷ���ĵ�������ϲ����� 
{   LNode *pa, pb, pc;     
    pa=La->next;   
    pb=Lb->next; 
    Lc=La;     
    pc=Lc;   //���ñ�La��ͷ�����Ϊ��Lc��ͷ��� 
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
    free(Lb);            //��Lb�ı�ͷ�ͷ� 
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





 
 


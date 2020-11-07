#include<stdio.h>
#include<stdlib.h> 
#define maxSize 100         //��������� 

typedef int Elemtype;   	   //Ԫ�ص���������  
struct  node 
{ 
       Elemtype data[maxSize];             //�洢���� 
	  int length;  	                  //��ǰ��Ԫ�ظ��� 
}; 
typedef struct node SeqList;

void SeqListInit (SeqList &L){            //��ʼ������ 
       L.length = 0; 
} 



int SeqListLength (SeqList& L){           //�����Ա��� 
       return L.length; 
}

Elemtype SeqListGet (SeqList& L,int i){   //ȡԪ�� 
       if ((i>=1)&&(i<=L.length)) 
	      return L.data[i-1];             
       else{
            printf("i ֵ���Ϸ�"); 
            exit(0); 
       }      
} 

int SeqListLocate (SeqList& L, Elemtype e){     //��λ����   
       int i�� 
       while ((i<=L.length)&&(e!=L.data[i-1]))  
            i++;                     
		  if (i<=L.length)  
		  return i;            
		  else{ 
                  printf("��Ԫ����˳����в�����");                   
			   return 0; 
            }
}

Elemtype SeqListPrior (SeqList& L, Elemtype e){  //��ǰ������  
       int i = SeqListLocate(L,e);            
	  if (1==i){ 
            printf("��1��Ԫ��û��ǰ��");                   
		  exit(0); 
       } 
       else return L.data[i-2]; 
}

Elemtype SeqListNext (SeqList& L, Elemtype e){   //���������  
       int i = SeqListLocate(L,e); 
       if (L.length==i) { 
            printf("���1��Ԫ��û�к��");                   
		  exit(0); 
       } 
           else return L.data[i]; 
}

int SeqListInsert ( SeqList &L, int i, ElemType b){   //ǰ����� 
       if ( L.length == maxSize ){ 
       printf("���������޷�����");       
	  return 0;      
	  }   
	  if ( i < 1 || i > L.length ) {      
	  printf("i���Ϸ�");	      
	  return 0; 
       }   
       for (int j=L.length-1; j >= i-1; j--)  
	  L.data[j+1] = L.data[j]; 
       L.data[i-1] = b;         //ʵ�ʲ��������i-1��λ�� 
       L.length++; 	 	 	 
       return 1;                //����ɹ�        
} 

int SeqListDel ( SeqList& L, int i ) {                //ɾ������      
       if ( i < 1 || i > L.length) { 
           printf("i���Ϸ�");        //iֵԽ��            
           return 0; 
       } 
       for (int j = i; j <= L.length-1; j++)  
	  L.data[j-1] = L.data[j];        
	  L.length--;     
       return 1; 	                //�ɹ�ɾ�� 	 
}
 
void SeqListTraverse(SeqList &L){                      //�пձ��� 
       if (SeqListEmpty(L)) 
  	      printf("�ñ�Ϊ��"); 
       else 
       for (int i = 1; i <= L.length; i++) 
  	      printf("%d\n", L.data[i - 1]); 
}

int main(){
	int i,j;
	SeqList L1,L2;
	Elemtype e;
	SeqListInit (L1);
	SeqListInit (L2);
	SeqListLength (L1);
	SeqListGet (L1,i);
	SeqListGet (L2,i);
	SeqListLocate (L1,e);
	SeqListPrior (L1,e);
	SeqListNext (L1,e);
	SeqListInsert (L1,i,b);
	SeqListDel (L1,i);
	SeqListTraverse(L1);
	return 0;
} 







 




 

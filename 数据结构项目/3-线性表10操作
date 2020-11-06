#include<stdio.h>
#include<stdlib.h> 
#define maxSize 100         //最大允许长度 

typedef int Elemtype;   	   //元素的数据类型  
struct  node 
{ 
       Elemtype data[maxSize];             //存储数组 
	  int length;  	                  //当前表元素个数 
}; 
typedef struct node SeqList;

void SeqListInit (SeqList &L){            //初始化操作 
       L.length = 0; 
} 



int SeqListLength (SeqList& L){           //求线性表长度 
       return L.length; 
}

Elemtype SeqListGet (SeqList& L,int i){   //取元素 
       if ((i>=1)&&(i<=L.length)) 
	      return L.data[i-1];             
       else{
            printf("i 值不合法"); 
            exit(0); 
       }      
} 

int SeqListLocate (SeqList& L, Elemtype e){     //定位函数   
       int i； 
       while ((i<=L.length)&&(e!=L.data[i-1]))  
            i++;                     
		  if (i<=L.length)  
		  return i;            
		  else{ 
                  printf("次元素在顺序表中不存在");                   
			   return 0; 
            }
}

Elemtype SeqListPrior (SeqList& L, Elemtype e){  //求前驱函数  
       int i = SeqListLocate(L,e);            
	  if (1==i){ 
            printf("第1个元素没有前驱");                   
		  exit(0); 
       } 
       else return L.data[i-2]; 
}

Elemtype SeqListNext (SeqList& L, Elemtype e){   //求后驱函数  
       int i = SeqListLocate(L,e); 
       if (L.length==i) { 
            printf("最后1个元素没有后继");                   
		  exit(0); 
       } 
           else return L.data[i]; 
}

int SeqListInsert ( SeqList &L, int i, ElemType b){   //前插操作 
       if ( L.length == maxSize ){ 
       printf("表已满，无法插入");       
	  return 0;      
	  }   
	  if ( i < 1 || i > L.length ) {      
	  printf("i不合法");	      
	  return 0; 
       }   
       for (int j=L.length-1; j >= i-1; j--)  
	  L.data[j+1] = L.data[j]; 
       L.data[i-1] = b;         //实际插在数组第i-1个位置 
       L.length++; 	 	 	 
       return 1;                //插入成功        
} 

int SeqListDel ( SeqList& L, int i ) {                //删除操作      
       if ( i < 1 || i > L.length) { 
           printf("i不合法");        //i值越界            
           return 0; 
       } 
       for (int j = i; j <= L.length-1; j++)  
	  L.data[j-1] = L.data[j];        
	  L.length--;     
       return 1; 	                //成功删除 	 
}
 
void SeqListTraverse(SeqList &L){                      //判空表函数 
       if (SeqListEmpty(L)) 
  	      printf("该表为空"); 
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







 




 

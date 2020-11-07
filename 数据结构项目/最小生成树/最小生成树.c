#include<stdio.h>
#define MaxVertexNum 100     //��󶥵��� 


typedef char VertexType;     //�������� 
typedef int EdgeType;        //���ϵ�Ȩֵ

typedef struct{
	VertexType vexs[MaxVertexNum];                   //����� 
	EdgeType edges[MaxVertexNum][MaxVertexNum];      //�ڽӾ���
	int n,e;                                         //ͼ�е�ǰ�Ķ������ͱ��� 
}AdjGragh;

typedef struct{
	int u;                  //�ߵ���ʼ����
	int v;                  //�ߵ���ֹ����
	int w;                  //�ߵ�Ȩֵ 
}Edge;

AdjGragh G;
int n;
Edge E[MaxVertexNum];


void CreateMGraph(){                                   //����ͼ 
	int i,j,k,w,m;
	printf("������ͼ�еĶ�������\n");
	scanf("%d",&G.n);
	n=G.n;
	printf("������ͼ�еı�����\n");getchar();
	scanf("%d",&G.e);
	printf("������¼�붥��:\n");getchar();
	for(i=0;i<G.n;i++){                               //���������
		G.vexs[i]=getchar();getchar();
          
	}
     for(i=0;i<G.n;i++){
    	     for(j=0;j<G.n;i++){ 
	        G.edges[i][j]=0;                         //�ڽӾ����ʼ��	
	    } 
  	    
     }
     printf("�밴������������ÿ�����ϵ�Ȩֵw��\n");
     printf("i  j  w\n");
	m=0;
     for(k=0;k<G.e;k++){           
    	     scanf("%d  %d  %d",&E[m].u,&E[m].v,&E[m].w);//����ߣ�vi,vj)�ϵ�Ȩw 
    	     m=m+1;
    }
    
}

void up(){
	int i,j;	
	for(i=0;i<=n-2;i++){
		for(j=i;j<=n-2;j++){
			if(E[i].w>E[j].w){
				E[i]=E[j];
			}
		}
	}
}

void MiniSpanTree_Kruskal(){
	int i,j,k,a;
	int vset[MaxVertexNum];
	for(i=0;i<n;i++){
		vset[i]=i;		
	} 
	k=1;j=0;
	while(k<n){                                     //���ɵı���С��nʱѭ�� 
	     if(vset[E[j].u]!=vset[E[j].v]){
     		printf("(%d,%d):%d\n",E[j].u,E[j].v,E[j].w);
     		k++;
     		for(i=0;i<n;i++){                     //��������ͳһ���
		          if(vset[i]==E[j].v){
				   vset[i]=vset[E[j].u]; 
		          }		          
     	}
     	for(i=0;i<n;i++){
     	printf("%d\t",i);
     	}
     	printf("\n");
     	for(i=0;i<n;i++){
     	printf("%d\t",vset[i]);
     	}
     	printf("\n");	                                       
	     }
	     j++;                                       //ɨ����һ���� 
	}

} 



int main(){
     CreateMGraph();
	MiniSpanTree_Kruskal();
	return 0;
	
} 
#include<stdio.h>
#define MaxVertexNum 100     //最大顶点数 


typedef char VertexType;     //顶点类型 
typedef int EdgeType;        //边上的权值

typedef struct{
	VertexType vexs[MaxVertexNum];                   //顶点表 
	EdgeType edges[MaxVertexNum][MaxVertexNum];      //邻接矩阵
	int n,e;                                         //图中当前的顶点数和边数 
}AdjGragh;

typedef struct{
	int u;                  //边的起始顶点
	int v;                  //边的终止顶点
	int w;                  //边的权值 
}Edge;

AdjGragh G;
int n;
Edge E[MaxVertexNum];


void CreateMGraph(){                                   //创建图 
	int i,j,k,w,m;
	printf("请输入图中的顶点数：\n");
	scanf("%d",&G.n);
	n=G.n;
	printf("请输入图中的边数：\n");getchar();
	scanf("%d",&G.e);
	printf("请依次录入顶点:\n");getchar();
	for(i=0;i<G.n;i++){                               //建立顶点表
		G.vexs[i]=getchar();getchar();
          
	}
     for(i=0;i<G.n;i++){
    	     for(j=0;j<G.n;i++){ 
	        G.edges[i][j]=0;                         //邻接矩阵初始化	
	    } 
  	    
     }
     printf("请按升序依次输入每条边上的权值w：\n");
     printf("i  j  w\n");
	m=0;
     for(k=0;k<G.e;k++){           
    	     scanf("%d  %d  %d",&E[m].u,&E[m].v,&E[m].w);//输入边（vi,vj)上的权w 
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
	while(k<n){                                     //生成的边数小于n时循环 
	     if(vset[E[j].u]!=vset[E[j].v]){
     		printf("(%d,%d):%d\n",E[j].u,E[j].v,E[j].w);
     		k++;
     		for(i=0;i<n;i++){                     //两个集合统一编号
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
	     j++;                                       //扫描下一条边 
	}

} 



int main(){
     CreateMGraph();
	MiniSpanTree_Kruskal();
	return 0;
	
} 
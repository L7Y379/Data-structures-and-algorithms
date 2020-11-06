#include<stdio.h>
#define MAX 100

int list[MAX];
int l;

void read(){
	int i;
	printf("请输入要进行排序的表的长度：\n");
	scanf("%d",&l);
	printf("请依次录入数据：\n");
	for(i=1;i<=l;i++){
		scanf("%d",&list[i]);getchar();
	}
}

int Quick_Partition(int k,int j){  //快速排序的一次划分，左端位置为i，右端位置为j 
	list[0]=list[k];
	while(k<j){
		while(k<j&&list[j]>=list[0])j--;  //j往左移
		if(k<j){
			list[k]=list[j];
			k++;
		}                                 //比支撑点关键字小的记录交换到左边
		while(k<j&&list[k]<=list[0])k++;  //i往右移
		if(k<j){
			list[j]=list[k];
			j--;
		}                                 //比支撑点关键字大的记录交换到右边 
	}
	list[k]=list[0];    //支撑点记录置入正确位置 
	return k;           //返还支撑点位置 
}

void Quick_Sort(int s,int t){      //对表list做快速排序 
    int i;
	if(s<t){
		i=Quick_Partition(s,t);    //调用划分过程将表一分为二 
		Quick_Sort(s,i-1);         //递归调用快速排序过程 
		Quick_Sort(i+1,t);         //递归调用快速排序过程 
	}
}

void out(){
	int i;
	for(i=1;i<=l;i++){
		printf("%d\t",i);
	}
	printf("\n");
	for(i=1;i<=l;i++){
		printf("%d\t",list[i]);
	}
	printf("\n");
}

int BinSearch(int K){
	int low=1;
	int hight;
	int mid;
	hight=l;
	while(low<=hight){
		mid=(low+hight)/2;
		if(list[mid]==K){
		    return mid;
		}
          if(list[mid]>K){
              hight=mid-1;	
          }
          else{
         	    low=mid+1;
          }
              
	}
	return 0;
} 

int main(){
	int s,t,K,m;
	read();
	printf("初始表为：\n");
	out();
	printf("请输入要进行排序的段落的第一个数据的序号：");
	scanf("%d",&s);getchar();
	printf("请输入要进行排序的段落的最后一个数据的序号：");
	scanf("%d",&t);getchar();
	Quick_Sort(s,t);
	printf("进行了快速排序后的表为：\n");
	out();
	printf("请输入你想查找的数据：\n");
	scanf("%d",&K);
	m=BinSearch(K);
	if(m!=0){
		printf("所查找的数据在表中的位置为：%d\n",m);
	}
	else{
		printf("所查找的数据在表中不存在！\n"); 
	}
	return 0;
}

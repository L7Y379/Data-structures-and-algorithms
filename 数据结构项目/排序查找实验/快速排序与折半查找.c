#include<stdio.h>
#define MAX 100

int list[MAX];
int l;

void read(){
	int i;
	printf("������Ҫ��������ı�ĳ��ȣ�\n");
	scanf("%d",&l);
	printf("������¼�����ݣ�\n");
	for(i=1;i<=l;i++){
		scanf("%d",&list[i]);getchar();
	}
}

int Quick_Partition(int k,int j){  //���������һ�λ��֣����λ��Ϊi���Ҷ�λ��Ϊj 
	list[0]=list[k];
	while(k<j){
		while(k<j&&list[j]>=list[0])j--;  //j������
		if(k<j){
			list[k]=list[j];
			k++;
		}                                 //��֧�ŵ�ؼ���С�ļ�¼���������
		while(k<j&&list[k]<=list[0])k++;  //i������
		if(k<j){
			list[j]=list[k];
			j--;
		}                                 //��֧�ŵ�ؼ��ִ�ļ�¼�������ұ� 
	}
	list[k]=list[0];    //֧�ŵ��¼������ȷλ�� 
	return k;           //����֧�ŵ�λ�� 
}

void Quick_Sort(int s,int t){      //�Ա�list���������� 
    int i;
	if(s<t){
		i=Quick_Partition(s,t);    //���û��ֹ��̽���һ��Ϊ�� 
		Quick_Sort(s,i-1);         //�ݹ���ÿ���������� 
		Quick_Sort(i+1,t);         //�ݹ���ÿ���������� 
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
	printf("��ʼ��Ϊ��\n");
	out();
	printf("������Ҫ��������Ķ���ĵ�һ�����ݵ���ţ�");
	scanf("%d",&s);getchar();
	printf("������Ҫ��������Ķ�������һ�����ݵ���ţ�");
	scanf("%d",&t);getchar();
	Quick_Sort(s,t);
	printf("�����˿��������ı�Ϊ��\n");
	out();
	printf("������������ҵ����ݣ�\n");
	scanf("%d",&K);
	m=BinSearch(K);
	if(m!=0){
		printf("�����ҵ������ڱ��е�λ��Ϊ��%d\n",m);
	}
	else{
		printf("�����ҵ������ڱ��в����ڣ�\n"); 
	}
	return 0;
}

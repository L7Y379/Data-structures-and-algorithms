#include<stdio.h>
int main(){
	int i;
	int j;         //公差 
     int a[20];
     j=(330-300)/10;
	a[0]=(630-190*3)/20;
	for(i=0;i<19;i++){
		a[i+1]=a[i]+j;
	}
	printf("数列为：\n");
	for(i=0;i<20;i++){
	printf("%d\t",a[i]); 
	}
     return 0;
} 
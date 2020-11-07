#include<stdio.h> 
#define MAXSIZE 256;
 
char String [MAXSIZE];
struct Node{
	 char *str;     //����������ռ�
	 int length;    //����
}
typedef struct Node string;

void  SeqStringAssign(string *S,string *T) 
{  if((S->str)!=NULL) free(S->str);     
S->length = T->length;     if (S->length==0) { 
        S->str = (char *)malloc(sizeof(char));         
	   if(!S->str)  {   printf("�ռ����ʧ�ܣ�");   	
	   exit(0);  } 
        S->str='\0'; 
       } 
       else { 	 
               S->str = (char *)malloc((S->length+1)*sizeof(char));                
			if(!S->str) {  printf("�ռ����ʧ�ܣ�");   
			exit(0); 
			}  
			for(int i = 0; i < =S->length; i++)  
			S->str[i] = T->str[i]; 
            } 
} 

string* SeqStringAssign(string *S, char* V) //���ĸ�ֵ����
{ 
 	if ((S->str) != NULL)  	free(S->str); 
 	S->length = StrLength(V); 
 	S->str = (char*)malloc((S->length)*sizeof(char));  	
	 if (!S->str) 
 	{ 	printf("overflow");  	 	
	 exit(0); 
 	} 
 	for (int i = 0; i < S->length; i++) 
 	{ 	S->str[i] = V[i];   	}  	
	 return S; 
}

void findnext(String P,int *next)
{
     next[0]=-1;
     j=0;
     k=-1;
     while(j<Length(P)){
     	while(k==0||P[j]==P[k]){
	     	j++;
	     	k++;
	     	next[j]=k;
	     }
	     k=next[k];
     }
}

int KMP(string *S, string *P, int *next) 
{    
     findNext(P, next); 
     int i = 0, j = 0; 
     while (i <= S->length - P->length) 
     { 	while (j == -1 || (j<P->length && S->str[i] == P->str[j])) 
 	{ i++; j++; 	} 
 	if (j == P->length)  return i - P->length;  	
     else j = next[j]; 
     } 
     return -1; 
} 

int Replace(Stringtype &S,Stringtype T,Stringtype V);//����S�������Ӵ�T�滻ΪV,�������û�����
{
  for(n=0,i=1;i<=Strlen(S)-Strlen(T)+1;i++) //ע��i��ȡֵ��Χ
    if(!StrCompare(SubString(S,i,Strlen(T)),T)) //�ҵ�����Tƥ����Ӵ�
    { //�ֱ��T��ǰ��ͺ��沿�ֱ���Ϊhead��tail
      StrAssign(head,SubString(S,1,i-1));
      StrAssign(tail,SubString(S,i+Strlen(T),Strlen(S)-i-Strlen(T)+1));
      StrAssign(S,Concat(head,V));
      StrAssign(S,Concat(S,tail)); //��head,V,tail����Ϊ�´�
      i+=Strlen(V); //��ǰָ���������봮�Ժ�
      n++;
    }//if
  return n;
}//Replace

int String_Palindrome(LString s){//�б�������Ƿ���жԳ��Ե��㷨����Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(StringLength(S))�� 
	IntStack(stack);
	p=S.head;
	i=0;
	k=1;
	for(k=1;k<=S.Length){
		if(k<=S.Length/2)
		   Push(S,p->ch[i]);
          else if(k>(S.Length)/2){
          	Pop(S,c);
          	if(p->ch[i]!=c)
		       return 0;
          }
		if(++i==CHUNKSIZE){
			p=p->next;
			i=0;
		}   
	}
     return 1;  	
}
 

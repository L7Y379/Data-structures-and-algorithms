#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include"SeqStack.h"
#define StackSize 100

typedef char DataType;
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;
 
void InitStack(SeqStack *S)    
/*��ջ��ʼ��Ϊ��ջֻ��Ҫ��ջ��ָ��top��Ϊ0*/
{
S->top=0;    /*��ջ��ָ����Ϊ0*/
}
int StackEmpty(SeqStack S)   
/*�ж�ջ�Ƿ�Ϊ�գ�ջΪ�շ���1�����򷵻�0*/
{
    if(S.top==0)            /*�ж�ջ��ָ��top�Ƿ�Ϊ0*/
        return 1;          /*��ջΪ��ʱ������1�����򷵻�0*/
    else
        return 0;
}
int GetTop(SeqStack S, DataType *e)   
/*ȡջ��Ԫ�ء���ջ��Ԫ��ֵ���ظ�e��������1��ʾ�ɹ������򷵻�0��ʾʧ�ܡ�*/
{
   if(S.top<=0)       /*��ȡջ��Ԫ��֮ǰ���ж�ջ�Ƿ�Ϊ��*/
{
    printf("ջ�Ѿ���!\n");
    return 0;
}
else
{
    *e=S.stack[S.top-1];    /*��ȡջ��Ԫ��*/
    return 1;
}
}
int PushStack(SeqStack *S,DataType e)   
/*��Ԫ��e��ջ��Ԫ�ؽ�ջ�ɹ�����1�����򷵻�0.*/
{
if(S->top>=StackSize)             /*��Ԫ�ؽ�ջǰ���ж��Ƿ�ջ�Ѿ���*/
{
        printf("ջ���������ܽ�ջ��\n");
        return 0;
}
else
{
        S->stack[S->top]=e;           /*Ԫ��e��ջ*/
        S->top++;                    /*�޸�ջ��ָ��*/
        return 1;
}
}
int PopStack(SeqStack *S,DataType *e)
/*��ջ��������ջ��Ԫ�س�ջ�������丳ֵ��e����ջ�ɹ�����1�����򷵻�0*/
{
    if(S->top<=0)     /*Ԫ�س�ջ֮ǰ���ж�ջ�Ƿ�Ϊ��*/
    {
        printf("ջ�Ѿ�û��Ԫ�أ����ܳ�ջ!\n");
        return 0;
    }
    else
{
    S->top--;            /*���޸�ջ��ָ�룬����ջ*/
        *e=S->stack[S->top];  /*����ջԪ�ظ�ֵ��e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*��ջ�ĳ��ȣ���ջ��Ԫ�ظ�����ջ��ָ���ֵ�͵���ջ��Ԫ�صĸ���*/
{
    return S.top;
}

typedef struct/*������ջ�����Ͷ���*/
{
    float data[MaxSize];
    int top;                  
}OpStack;  
void TranslateExpress(char s1[],char s2[]);
float ComputeExpress(char s[]);
void mai()
{
    char a[MaxSize],b[MaxSize];
    float f;
    printf("������һ���������ʽ��\n");
    gets(a);
    printf("��׺���ʽΪ��%s\n",a);
    TranslateExpress(a,b);
    printf("��׺���ʽΪ��%s\n",b);
    f=ComputeExpress(b);
    printf("��������%f\n",f);
}   
float ComputeExpress(char a[])
/*�����׺���ʽ��ֵ*/
{  
    OpStack S;
    int i=0,value;
    float x1,x2;
    float result;
    S.top=-1;
    while(a[i]!='\0')
    {
        if(a[i]!=' '&&a[i]>='0'&&a[i]<='9')/*�����ǰ�ַ��������ַ�������ת��Ϊ���ֲ�����ջ��*/
        {
            value=0;
            while(a[i]!=' ')
            {
                value=10*value+a[i]-'0';
                i++;
            }
            S.top++;
            S.data[S.top]=value;
        }      
        else            /*�����ǰ�ַ�������������ջ�е����ݽ�����ֵ������������浽ջ��*/
        {
            switch(a[i])
            {
                 
            case '+':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x1+x2;
                S.top++;
                S.data[S.top]=result;
                break;
            case '-':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x2-x1;
                S.top++;
                S.data[S.top]=result;
                break;
            case '*':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x1*x2;
                S.top++;
                S.data[S.top]=result;
                break;
            case '/':
                x1=S.data[S.top];
                S.top--;
                x2=S.data[S.top];
                S.top--;
                result=x2/x1;
                S.top++;
                S.data[S.top]=result;
                break;
            }
            i++;
        }
    }
     
    if(!S.top!=-1)
    {
        result=S.data[S.top];
        S.top--;
        if(S.top==-1)
            return result;
        else
        {
            printf("���ʽ����");
            exit(0);
        }
    }
}
void TranslateExpress(char str[],char exp[])   
/*����׺���ʽת��Ϊ��׺���ʽ*/
{
    OpStack S;               
    char ch;   
    DataType e;
    int i=0,j=0;
    InitStack(&S);
    ch=str[i];                    
    i++;
    while(ch!='\0')               
    {
        switch(ch)
        {
        case'(':    /*��������ջ*/  
            PushStack(&S,ch);
            break;
        case')':    /*�����ǰ�ַ��������ţ���ջ�е��ַ���ջ��ֱ��ջ�е�һ�������ų�ջΪֹ*/          
            while(GetTop(S,&e)&&e!='(')    
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PopStack(&S,&e);/*�����ų�ջ*/
            break;
        case'+':
        case'-':
            while(!StackEmpty(S)&&GetTop(S,&e)&&e!='(')/*�����ǰ�ַ���+�Ż�-�ţ���ջ���ַ���ջ��ֱ������������Ϊֹ*/
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PushStack(&S,ch);/*����ǰ�ַ���ջ*/
            break;
        case'*':
        case'/':
            while(!StackEmpty(S)&&GetTop(S,&e)&&e=='/'||e=='*')/*�����ǰ�ַ���*�Ż�����/�ţ���ջ���ַ���ջ*/
            {
                PopStack(&S,&e);
                exp[j]=e;
                j++;
            }
            PushStack(&S,ch);   /*��ǰ�ַ���ջ*/
            break;
        case' ':
            break;
        default:                /*���������ַ�*/
            while(ch>='0'&&ch<='9')
            {
                exp[j]=ch;
                j++;
                ch=str[i];
                i++;
            }
            i--;
            exp[j]=' ';
            j++;
        }
        ch=str[i];
        i++;
    }
    while(!StackEmpty(S))
    {
        PopStack(&S,&e);
        exp[j]=e;
        j++;
    }
    exp[j]='\0';
}
#include <stdio.h>
//定义顺序表的最大长度
#define MAXLENGTH 100;

//定义线性表的顺序存储结构
typedef struct{
    //定义线性表里存储的数据类型为整型
    int *R;
    //定义顺序表当前的长度
    int length;
}Sqlist;

void DirectInsertSort(Sqlist &l){
    //临时变量
    int i,j;
    for(int i=2;i<l.length;i++){
        if(l.R[i] < l.R[i-1]){
        l.R[0] = l.R[i]; //建立哨兵
        for(j=i-1;l.R[0]<l.R[j];--j){
            l.R[j+1]=l.R[j]; //位置后移   
        }  
        l.R[j+1]=l.R[0]; //插入到正确位置
    }
    }
}

int main(){
    int a[7];
    a[1] = 3;
    a[2] = 18;
    a[3] = 9;
    a[4] = 4;
    a[5] = 5;
    a[6] = 1;
    for(int i=1;i<7;i++){
        printf("%d\n",a[i]);
    }
    
    printf("************************************\n");
    Sqlist l;
    l.R=a;
    l.length=7;
    DirectInsertSort(l);
     for(int i=1;i<7;i++){
        printf("%d\n",a[i]);
    }
}



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

void ShellSort(Sqlist &l, int dtk){
    int i,j;
    for(i=dtk+1;i<=l.length;i++){
        if(l.R[i] < l.R[i-dtk]){
            l.R[0] = l.R[i]; //建立哨兵
            for(j=i-dtk;  j>0 && l.R[0]<l.R[j];j-=dtk){
                l.R[j+dtk]=l.R[j]; //位置后移 
            }
             l.R[j+dtk]=l.R[0]; //插入到哨兵位置
        }
    }
}

void ShellInsert(Sqlist &l, int dlta[],int t){
    for(int k=0;k<t;k++){
        ShellSort(l,dlta[k]);
    }
}
int main(){
    int a[13];
    a[1] = 81;
    a[2] = 94;
    a[3] = 11;
    a[4] = 96;
    a[5] = 12;
    a[6] = 35;
    a[7] = 17;
    a[8] = 95;
    a[9] = 28;
    a[10] = 58;
    a[11] = 41;
    a[12] = 75;
    a[13] = 15;
    for(int i=1;i<14;i++){
        printf("%d\n",a[i]);
    }
    printf("************************************\n");
    Sqlist l;
    l.R=a;
    l.length=13;
    int dlta[3] = {5,3,1};
    ShellInsert(l, dlta, 3);
     for(int i=1;i<14;i++){
        printf("%d\n",a[i]);
    }
}



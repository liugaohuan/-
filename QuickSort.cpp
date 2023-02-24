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

int partation(Sqlist &l, int low, int high){
    l.R[0]=l.R[low];
    while(low < high){
        while(low<high && l.R[high]>l.R[0]){
            --high;
        }
        l.R[low] = l.R[high];
        while(low<high && l.R[low]<l.R[0]){
            ++low;
        }
        l.R[high] = l.R[low];
    }
    l.R[low] = l.R[0];
    return low;
}

void QSort(Sqlist &l, int low,int high){
    if(low < high){
        int  pivot = partation(l,low,high);
        QSort(l,low,pivot-1);
        QSort(l,pivot+1,high);
    }
}

void QuickSort(Sqlist &l){
    QSort(l,1,l.length);
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
    QuickSort(l);
      for(int i=1;i<14;i++){
        printf("%d\n",a[i]);
    }
}
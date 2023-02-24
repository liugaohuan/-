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

void BinaryInsertSort(Sqlist &l){
    int i;
  for(i=2;i<=l.length;i++){
    //将l.R[i]存放在l.R[0]中
    l.R[0] = l.R[i];
    int low=1;
    int high=i-1;
    int mid;
    //while循环的目的是寻找插入位置
    while(low<=high){
        mid=(low+high)/2;
        if(l.R[0]<l.R[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    //寻找到插入位置之后，接下来按照插入位置插入元素
    for(int j=i-1;j>=high+1;--j){
        l.R[j+1] = l.R[j];//记录后移
        l.R[high+1]  = l.R[0];//将r[O]即原r[i], 插入到正确位置
    }
}
}

int main(){
    int a[13];
    a[1] = 1;
    a[2] = 3;
    a[3] = 4;
    a[4] = 7;
    a[5] = 9;
    a[6] = 2;
    a[7] = 0;
    a[8] = 19;
    a[9] = 17;
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
    BinaryInsertSort(l);
     for(int i=1;i<14;i++){
        printf("%d\n",a[i]);
    }
}



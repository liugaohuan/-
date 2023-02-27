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


int findMin(Sqlist l, int n){
    int min = n;
    for(int i=n+1;i<l.length;i++){
        if(l.R[i]< l.R[min]){
            min = i;
        }
    }
    return min;
}

int main(){
    int array[9] = {17,15,13,11,9,7,5,3,1};
    for(int i=0;i<sizeof(array)/sizeof(0);i++){
        printf("%d\n",array[i]);
    }
    printf("*********************\n");
    Sqlist l;
    l.R = array;
    l.length = 9;
    int temp;
    for(int n=0;n<l.length;n++){
        //寻找最小元素所在位置
        int min = findMin(l,n);
        //将第一个元素和最小元素位置进行交换
        temp = l.R[n];
        l.R[n] = l.R[min];
        l.R[min] = temp;
    }
      for(int i=0;i<sizeof(array)/sizeof(0);i++){
        printf("%d\n",array[i]);
    }

}
#include<stdio.h>

//将两个有序序列合并为一个递增的有序序列
int  *merge(int *array1, int *array2, int length1, int length2, int array[]){
    //初始化一个新的序列，其序列长度为两个有序序列的和
    int count = 0;
    for(int i=0,j=0; i<length1 || j< length2;){
        if(array1[i] < array2[j]){
            array[count] = array1[i];
            count++;
            i++;
        }else{
            array[count] = array2[j];
             count++;
             j++;
        }
    }

    return array;
}


int main(){
    int array1[5] = {3,7,9,11,19};
    int array2[5] = {11,13,15,20,30};
    int length1 = sizeof(array1)/sizeof(array1[1]);
    int length2 = sizeof(array2)/sizeof(array2[1]);
    int array[length1+length2];
    int *p = merge(array1,array2, length1, length2,array);
    for(int i=0;i<(length1+length2);i++){
        printf("%d\n",p[i]);
    }
}
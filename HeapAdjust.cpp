#include <stdio.h>

//大顶堆调整，其中l数组里存储的是大顶堆的结点序列，s是根结点下标，m是最后一个结点下标
void BigHeapAdjust(int l[], int s, int m){
    int j; //j是根结点s中数值最大结点下标
    //将堆的根结点赋值给变量rc
    int rc = l[s];
    
    for(j=2*s;j<=m;j*=2){
        //寻找根结点左右孩子当中数值最大元素下标j
        if(j<m && l[j]<l[j+1]){
            ++j;
        }
        //如果rc(根结点数据)比l[j]还大，则表示已经是大根堆了，直接退出循环
        if(rc >= l[j] ){
            break;
        }
        //将较大值l[j]赋值给l[s]
        l[s] = l[j];
        s = j;
    }
    l[s] = rc;
}

//调整堆的操作
void LittleHeapAdjust(int l[], int s, int m){
    int j; //j是根结点s中数值最小结点下标
    //将堆的根结点赋值给变量rc
    int rc = l[s];
    
    for(j=2*s;j<=m;j*=2){
        //寻找根结点左右孩子当中数值最小元素下标j
        if(j<m && l[j]>l[j+1]){
            ++j;
        }
        //如果rc(根结点数据)比l[j]还小，则表示已经是小根堆了，直接退出循环
        if(rc <= l[j] ){
            break;
        }
        //将较小值l[j]赋值给l[s]
        l[s] = l[j];
        s = j;
    }
    l[s] = rc;
}

//将无序序列建初堆的操作
void buildHeap(int array[], int length){
    for(int i=length/2;i>=1;--i){
        LittleHeapAdjust(array,i,length);
    }
}

//第一个元素和最后一个元素交换
void swap(int array[], int s, int n){
    int temp;
    s = 1;
    temp = array[s];
    array[s] = array[n];
    array[n] = temp;
}

//首先array数组是一个无序序列
void HeapSort(int array[], int length){
        //构造堆
        buildHeap(array, length);
        for(int i=length;i>1;i--){
            //交换元素
            swap(array,1, i);
            LittleHeapAdjust(array, 1, i-1);
        }
}

int main(){
    int array[9];
    array[1]= 49;
    array[2]= 38;
    array[3]= 65;
    array[4]= 97;
    array[5]= 76;
    array[6]= 13;
    array[7]= 27;
    array[8]= 49;

    int length = (sizeof(array)/sizeof(1));

    for(int i=1;i<length;i++){
        printf("%d\n",array[i]);
    }
    printf("******************************\n");

    HeapSort(array, length);

    for(int i=1;i<length;i++){
        printf("%d\n",array[i]);
    }

}
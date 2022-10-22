#include <stdio.h>

void shell_sort(int a[], int n) {
	int k,j;
	int step = n;
	do {
		step = step / 2;    //设置增量，标准不唯一，这里设置为除以3，很多地方都是除以2
		for (int i = step; i < n; i++)
                 {
			if (a[i] < a[i - step]) 
                        {    //将相隔step的数看作一组进行插入排序（即一共step个组，每个组分别插入排序）
				k = a[i];
				for (j = i - step; j >= 0 && k < a[j]; j -= step) 
                                {
					a[j + step] = a[j];
				}
				a[j + step] = k;
			}
		}
	}
	while (step > 1);
}


int main(){

int a[25] ={8,9,2,1,5,3,10,7,6,11,3,88,10,1,33,56,99,100,33,2,6,3,4,3,9};
for (int i=0;i< sizeof(a)/4;i++){
	printf("%d", a[i]);
	if (i != (sizeof(a)/4)-1 ){
		printf("%s", ",");
	}
}

shell_sort(a, 25);
printf("\n");
printf("希尔排序后的数组如下：\n");
for (int i=0;i<sizeof(a)/4;i++){
	printf("%d", a[i]);

	if (i != (sizeof(a)/4)-1 )
	{
		printf("%s", ",");
	}
}

printf("\n");

}

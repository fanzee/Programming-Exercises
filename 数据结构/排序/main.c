#include "Sort.h"

int main(void)
{
	int arr[] = { 9,8,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;

	printf("Before:\n");
	for (i = 0; i < len; i++)
		printf("%-4d", arr[i]);
	printf("\n");

	//BubbleSort(arr, len);
	//printf("冒泡排序后的数组是：\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");

	QuickSort(arr, len);
	printf("QuickSort:\n");
	for (i = 0; i < len; i++)
		printf("%-4d", arr[i]);
	printf("\n");

	//SelectSort(arr, len);
	//printf("选择排序后的数组是：\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");

	//InsertSort(arr, len);
	//printf("插入排序后的数组是：\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");

	//BinarySort(arr, len);
	//printf("折半排序后的数组是：\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");

	//ShellSort(arr, len);
	//printf("希尔排序后的数组是：\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");


	//MergeSort(arr, len);
	//printf("MergeSort:\n");
	//for (i = 0; i < len; i++)
	//	printf("%-4d", arr[i]);
	//printf("\n");

	system("pause");
	return 0;
}
#include "Sort.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int arr[],int len)
{
	int i, j;
	int flag = 1;
	for (i = 0; i < len - 1 && flag; i++)
	{
		flag = 0;
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
	}
}

int Median3(int arr[], int left, int right)
{
	int center = (left + right) / 2;
	if (arr[left] > arr[center])
		swap(&arr[left], &arr[center]);
	if (arr[left] > arr[right])
		swap(&arr[left], &arr[right]);
 	if (arr[center] > arr[right])
		swap(&arr[center], &arr[right]);

	swap(&arr[center], &arr[right - 1]);
	return arr[right - 1];
}

void Qsort(int arr[], int left, int right)
{
	int i = left;
	int	j = right - 1;
	int pivot = Median3(arr, left, right);
	for (;;)
	{
		while (arr[++i] < pivot) {}
		while (arr[--j] > pivot) {}
		if (i < j)
			swap(&arr[i], &arr[j]);
		else
			break;
	}
	swap(&arr[i], &arr[right - 1]);
	Qsort(arr, left, i - 1);
	Qsort(arr, i + 1, right);
}

void QuickSort(int arr[], int len)
{
	Qsort(arr, 0, len - 1);
}

void SelectSort(int arr[], int len)
{
	int i, j, min;
	for (i = 0; i < len; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i)
		{
			swap(&arr[min], &arr[i]);
		}
	}
}

void InsertSort(int arr[], int len)
{
	int i, j, temp;  
	for (i = 1; i < len; i++) 
	{
		temp = arr[i];		
		for (j = i; j > 0 && temp < arr[j - 1]; j--) 
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void BinarySort(int arr[], int len)
{
	int i, j;
	int low, high, middle;
	int temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (temp < arr[middle])
				high = middle - 1;
			else
				low = middle + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
			arr[j + 1] = arr[j];
		arr[high + 1] = temp;
	}
}

void ShellSort(int arr[], int len)
{
	int i, j, d, temp;
	for (d = len / 2; d > 0; d /= 2)
	{
		for (i = d; i < len; i++)
		{
			temp = arr[i];
			for (j = i; j >= d && temp <= arr[j - d]; j -= d)
			{
				arr[j] = arr[j - d];
			}
			arr[j] = temp;
		}
	}
}

void Merge(int arr[], int temp[], int left, int right, int rightEnd)
{
	int leftEnd = right - 1;
	int tempPos = left;
	int len = rightEnd - left + 1;

	while (left <= leftEnd && right <= rightEnd)
	{
		if (arr[left] <= arr[right])
		{
			temp[tempPos++] = arr[left++];
		}
		else
		{
			temp[tempPos++] = arr[right++];
		}
	}
	while (left <= leftEnd)
	{
		temp[tempPos++] = arr[left++];
	}
	while (right <= rightEnd)
	{
		temp[tempPos++] = arr[right++];
	}
	for (int i = 0; i < len; i++, rightEnd--)
	{
		arr[rightEnd]=temp[rightEnd];
	}
}

void MSort(int arr[], int temp[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MSort(arr, temp, left, mid);
		MSort(arr, temp, mid + 1, right);
		Merge(arr, temp, left, mid + 1, right);
	}
}

void MergeSort(int arr[], int len)
{
	int *temp = (int *)malloc(len * sizeof(int));
	if (temp != NULL)
	{
		MSort(arr, temp, 0, len - 1);
		free(temp);
	}
	else
	{
		printf("分配临时数据空间失败！\n");
	}
}
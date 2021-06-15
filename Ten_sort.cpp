#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.g>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/////////////////////////
void arrprintf(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
/////////////////////////
void Insertsort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
/////////////////////////
void Shellsort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = 0;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
/////////////////////////
void bubblesort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
/////////////////////////
void choosesort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[max] < a[i])
			{
				max = i;
			}
			if (a[min] > a[i])
			{
				min =i;
			}
		}
		Swap(&a[begin], &a[min]);
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
/////////////////////////
int getkey(int* a, int left,int right)
{
	int keyi = left + (right - left) / 2;
	if (a[keyi] > a[left])
	{
		if (a[keyi] < a[right])
		{
			return keyi;
		}
		else if (a[keyi] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[keyi] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
int quicksort1(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int keyi = getkey(a, left, right);
	Swap(&a[keyi], &a[begin]);
	int povit = begin;
	int key = a[begin];
	while (begin < end)
	{
		while(a[end]>=key&& begin < end)
		{
			end--;
		}
		a[povit] = a[end];
		povit = end;
		while (a[begin] <= key && begin < end)
		{
			begin++;
		}
		a[povit] = a[begin];
		povit = begin;
	}
	povit = begin;
	a[povit] = key;
	return povit;
}
int quicksort2(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = getkey(a, left, right);
	Swap(&a[key], &a[begin]);
	int keyi = begin;
	while (begin < end)
	{
		while (a[end] >= a[keyi] && begin < end)
		{
			end--;
		}
		while (a[begin] <= a[keyi] && begin < end)
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);
	return keyi;
}
int quicksort3(int* a, int left, int right)
{
	int index = getkey(a, left, right);
	Swap(&a[left], &a[index]);
	int pevr = left, cur = left + 1;
	int key = left;
	while (cur <= right)
	{
		if (a[cur] < a[key])
		{
			pevr++;
			Swap(&a[cur], &a[pevr]);
		}
		cur++;
	}
	Swap(&a[pevr], &a[key]);
	return pevr;
}
void Quicksort(int* a, int left, int right)
{
	if (left < right)
	{
		int key = quicksort1(a, left, right);
		if (key - left - 1 > 10)
		{
			Quicksort(a, left, key - 1);
		}
		else
		{
			Insertsort(a+left, key - left);
		}
		if (right - key - 1 > 10)
		{
			Quicksort(a, key + 1, right);
		}
		else
		{
			Insertsort(a + key + 1, right - key);
		}
	}
}
/////////////////////////
void _mergesort(int* a, int left, int right,int*tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_mergesort(a, left, mid,tmp);
	_mergesort(a, mid + 1, right,tmp);
	int begin1 = left; int end1 = mid;
	int begin2 = mid + 1; int end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
void mergesort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}
	_mergesort(a, 0, n - 1,tmp);
	free(tmp);
}
/////////////////////////
void _heapsort(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && n>child+1)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void heapsort(int* a, int n)
{
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		_heapsort(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		_heapsort(a, end, 0);
		end--;
	}
}
/////////////////////////
void Countsort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}

	int ragert = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * ragert);
	if (count == NULL)
	{
		exit(-1);
	}
	memset(count,0,sizeof(int)*ragert);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < ragert; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}
/////////////////////////
void Testsortob()
{
	int num[] = { 4,6,2,3,1,5,8,7,9,10};
	int numSize = sizeof(num) / sizeof(num[0]);
	heapsort(num, numSize);
	arrprintf(num, numSize);
}
int main(void)
{
	Testsortob();
	return 0;
}

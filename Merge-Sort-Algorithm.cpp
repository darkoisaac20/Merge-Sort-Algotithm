
#include "stdafx.h"
#include<iostream>


using namespace std;
long long converge = 0;

void swapp(int &first, int &second) {

	int temp = first;
	first = second;
	second = temp;


}
int unimodal(int left, int right, int *arr) {
	int mid = (left + right) / 2;
	if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
		return arr[mid];
	}
	else if (arr[mid] > arr[mid - 1]) {
		return unimodal(mid, right - 1, arr);
	}
	else {
		return unimodal(left, mid - 1, arr);
	}

}

int merge(long int *arr, int l, int m, int r) {
	int conv = 0;
	long long int i, j, k;
	long int n1 = m - l + 1;
	long int n2 = r - m;

	/* create temp arrays */
	long int* L = new long int[n1];
	long int* R = new long int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;

		}
		else
		{
			arr[k] = R[j];
			j++;
			converge += (m - i + 1);
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	return conv;
}



int mergesort(long int *arr, int left, int right) {
	int inv = 0;
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);

	}
	return inv;

}


int partition(int *arr, int left, int right) {
	int pivor = arr[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++) {
		if (arr[j] <= pivor) {
			i++;
			swapp(arr[i], arr[j]);
		}

	}
	swapp(arr[i + 1], arr[right]);

	return (i + 1);
}

void quicksort(int *arr, int left, int right) {
	if (left < right) {
		int pi = partition(arr, left, right);
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);


	}
}


int main()
{
	//long int *myarr=new long int[100000];
	long long ii = 0;
	/*while (infile >> myarr[ii]) {
	ii++;
	}*/
	int largest = -INFINITY;
	int secondlargest = -INFINITY;
	int arr[] = { 1, 20, 6, 4, 5 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 6, 5, 4, 3, 2, 1, 0 };
	int T = 8;

	quicksort(arr2, 0, 14);
	//auto inv=mergesort(myarr, 0, ii-1);
	//auto modal = unimodal(0, 15, arr2);
	//delete[] myarr;

	return 0;
}


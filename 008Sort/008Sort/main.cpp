#include <stdio.h>
#include <stdlib.h>
#include "InsertSort.h"
#include "SwapSort.h"
#include "SelectionSort.h"


void PrintArrayWithSentinel(ElemType arr[], int n){
	if(n > 1){
		printf("%d", arr[1]);
	}

	for(int i = 2; i <= n; ++i){
		printf(",%d", arr[i]);
	}
	printf("\n");

	return;
}

void PrintArray(ElemType arr[], int n){
	if(n > 1){
		printf("%d", arr[0]);
	}

	for(int i = 1; i < n; ++i){
		printf(",%d", arr[i]);
	}
	printf("\n");

	return;
}

int main(int argc, char* argv[], char* env[]){
	//ElemType arr[MAXNUMBER + 1] = {SENTINEL, 1, 2,5,35,235,54,2,32,35,5};
	//PrintArrayWithSentinel(arr, MAXNUMBER);
	//InsertSort(arr, MAXNUMBER);
	//BinaryInsertSort(arr, MAXNUMBER);
	//ShellSort(arr, MAXNUMBER);
	//PrintArrayWithSentinel(arr, MAXNUMBER);

	//ElemType arr2[MAXNUMBER] = {1, 2,5,35,235,54,2,32,35,5};
	//PrintArray(arr2, MAXNUMBER);
	//BubbleSort(arr2, MAXNUMBER);
	//QuickSort(arr2, 0, MAXNUMBER-1);
	//PrintArray(arr2, MAXNUMBER);

	//ElemType arr3[MAXNUMBER] = {1, 2,5,35,235,54,2,32,35,5};
	//PrintArray(arr3, MAXNUMBER);
	//SelectionSort(arr3, MAXNUMBER);
	//PrintArray(arr3, MAXNUMBER);

	ElemType arr4[MAXNUMBER+1] = {SENTINEL,1,22222,5,35,235,54,2,32,35,5};
	PrintArrayWithSentinel(arr4, MAXNUMBER);
	HeapSort(arr4, MAXNUMBER);
	PrintArrayWithSentinel(arr4, MAXNUMBER);

	system("pause");
	return 0;
}
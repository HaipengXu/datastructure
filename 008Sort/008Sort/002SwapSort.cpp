#include "SortType.h"

static void Swap(ElemType &a, ElemType &b){
	a = a^b;
	b = a^b;
	a = a^b;

	return;
}

void BubbleSort(ElemType arr[], int n){
	bool flag = false;
	int i, j;

	for(i = 0; i < n-1; ++i){
		flag = false;
		for(j = n-1; j > i; --j){
			if(arr[j] < arr[j-1]){
				flag = true;
				Swap(arr[j], arr[j-1]);
			}
		}
		if(flag == false){
			return;
		}
	}
	return;
}

int Partition(ElemType arr[], int low, int high){
	ElemType pivot = arr[low];

	while(low < high){
		while(low < high && pivot <= arr[high]){
			--high;
		}
		arr[low] = arr[high];
		
		while(low < high && pivot >= arr[low]){
			++low;
		}
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void QuickSort(ElemType arr[], int low, int high){
	if(low < high){
		int pivotPosition = Partition(arr, low, high);
		QuickSort(arr, low, pivotPosition-1);
		QuickSort(arr, pivotPosition+1, high);
	}
}
#include "SortType.h"

void InsertSort(ElemType arr[], int n){
	int i, j;
	
	for(i = 2; i <= n; ++i){
		if(arr[i] < arr[i-1]){
			arr[0] = arr[i];

			for(j = i-1; j >= 1; --j){
				if(arr[0] < arr[j]){
					arr[j+1] = arr[j];
				}
				else
					break;
			}

			arr[j+1] = arr[0];
		}
	}

	return;
}

// sentinel 100 34 34 32 16
void BinaryInsertSort(ElemType arr[], int n){
	int i, j;
	int low, high, mid;

	for(i = 2; i <= n; ++i){
		low = 1;
		high = i-1;
		arr[0] = arr[i];
		while(low <= high){
			mid = (low + high)/2;
			if(arr[0] < arr[mid]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}

		for(j = i - 1; j >= high + 1; --j){
			arr[j+1] = arr[j];
		}
		arr[high+1] = arr[0];
	}

	return;
}

void ShellSort(ElemType arr[], int n){
	int d, i, j;

	for(d = n/2; d >= 1; d=d/2){
		for(i = d + 1; i <= n; ++i){
			if(arr[i] < arr[i-d]){
				arr[0] = arr[i];
				for(j = i-d; j >= 1; j=j-d){
					if(arr[0] < arr[j]){
						arr[j+d] = arr[j];
					}
					else
						break;
				}
				arr[j+d] = arr[0];
			}
		}
	}
}

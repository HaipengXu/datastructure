#include "SortType.h"

static void Swap(ElemType &a, ElemType & b){
	a = a^b;
	b = a^b;
	a = a^b;
	return;
}

void SelectionSort(ElemType arr[], int n){
	int i = 0, j = 0;
	int min = 0;

	for(i = 0; i < n-1; ++i){//���ǰn-1�������ˣ���ô�±�nһ���Ǳ�n-1��ģ����Բ��ñȽ���
		min = i;	//�洢������Сֵ�������±�
		for(j = i+1; j < n; ++j){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		if(min != i){
			Swap(arr[i], arr[min]);
		}
	}

}

void HeapAdjust(ElemType arr[], int k, int len){
	arr[0] = arr[k];
	int i = 0;

	for(i = k*2; i <= len; i = i*2){
		if(i < len && arr[i] <  arr[i+1]){
			++i;
		}
		if(arr[0] >= arr[i]){
			break;
		}
		else{
			arr[k] = arr[i];
			k = i;	//k��Զָ���,�ж�������Ƿ�Ϊ�����
		}
	}

	arr[k] = arr[0];

	return;
}

void BuildMaxHeap(ElemType arr[], int len){
	int i = 0;
	for(i = len/2; i >= 1; --i){
		HeapAdjust(arr, i, len);
	}
}

void HeapSort(ElemType arr[], int len){
	int i = 0;

	BuildMaxHeap(arr, len);

	for(i = len; i > 1; --i){
		Swap(arr[1], arr[i]);
		HeapAdjust(arr, 1, i-1);
	}
}


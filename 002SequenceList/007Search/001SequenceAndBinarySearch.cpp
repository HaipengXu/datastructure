#include "SearchType.h"


//if key is not found, function returns 0 or returns index.
int SequenceSearch(STable &ST, ElemType key){
	ST.table[0] = key;
	int i = 0;

	//�Ӻ���ǰ�Աȣ�һֱ���ڱ���λ�ã���������ڱ���λ�ã�˵��û���ҵ�
	for(i = ST.tableLength; ST.table[0]!=ST.table[i]; --i){

	}

	return i;//i must be 0;
}

int BinarySearch(STable &ST, int key){
	int low, high, mid;
	low = 0;
	high = ST.tableLength-1;

	while(low <= high){
		mid = (low + high)/2;
		if(ST.table[mid] == key){
			return mid;
		}
		else if(ST.table[mid] > key){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return -1;//����ʧ�ܷ���-1
}
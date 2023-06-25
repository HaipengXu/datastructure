#include <stdio.h>
#include "SearchType.h"
#include "SequenceAndBinarySearch.h"


int main(int argc, char* argv[], char* env[]){
	/*ElemType arr[MAXSIZE+1] = {SENTINEL,1,23,45,64,65,143,345,445,500,601};
	STable ST;
	ST.table = arr;
	ST.tableLength = MAXSIZE;

	int index = -1;

	ElemType key = 0;

	printf("{SENTINEL,1,23,45,64,65,143,345,445,500,601}\n");
	printf("To exit for inputing 9999\n");
	printf("please input key: ");
	scanf("%d", &key);

	while(key != 9999){
		index = SequenceSearch(ST, key);
		if(index == 0){
			printf("key: %d does not exist!\n", key);
		}
		else{
			printf("key: %d -- index: %d\n", key, index);
		}
		printf("please input key: ");
		scanf("%d", &key);
	}*/

	ElemType arr[MAXSIZE] = {1,23,45,64,65,143,345,445,500,601};
	STable ST;
	ST.table = arr;
	ST.tableLength = MAXSIZE;

	int index = -1;

	ElemType key = 0;
	printf("{1,23,45,64,65,143,345,445,500,601}\n");
	printf("To exit for inputing 9999\n");
	printf("please input key: ");
	scanf("%d", &key);

	while(key != 9999){
		index = BinarySearch(ST, key);
		if(index == -1){
			printf("key: %d does not exist!\n", key);
		}
		else{
			printf("key: %d -- index: %d\n", key, index);
		}
		printf("please input key: ");
		scanf("%d", &key);
	}
	return 0;
}
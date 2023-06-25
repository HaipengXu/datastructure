#ifndef ELEMTYPE
#define ELEMTYPE

typedef int ElemType;

typedef struct{
	ElemType* table;
	int tableLength;
}STable;

#define MAXSIZE 10
#define SENTINEL -1

#endif
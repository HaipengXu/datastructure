#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}LNode, *LinkList;

LinkList LinkHeadInsert(LinkList &L){
	LNode* s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}

	return L;
}

LinkList LinkTailInsert(LinkList &L){
	LNode* s;
	ElemType x;
	LNode* tail;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	tail = L;
	scanf("%d", &x);

	while(x != 9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;		//或者在退出是，直接用tail置空
		tail->next = s;
		tail = s;//tail 永远指向尾部
		scanf("%x", &x);
	}
	
	tail->next = NULL;

	return L;
}

void LinkListPrint(LinkList L){
	L = L->next;
	if(L!=NULL){
		printf("%d", L->data);
		L = L->next;
	}

	while(L != NULL){
		printf(",%d", L->data);
		L = L->next;
	}

	printf("\n");
}

bool IsIncrease(LinkList L){
	L = L->next;
	//1.如果链表为空，直接默认递增
	//2.如果链表只有一个，也是递增

	while(L != NULL){
		//是否是最后一个结点
		if(L->next == NULL){
			return true;
		}

		//当前结点大于下一个结点，不是递增
		if(L->data > L->next->data){
			return false;
		}
		else{
			L = L->next;
		}
	}

	return true;
}


//i表示获取第几个元素，头结点表示第0个元素
LNode* GetElem(LinkList L, int i){
	int currentIndex = 0;//永远指向L指向的结点索引

	if(i == 0){
		return L;
	}
	if(i < 0){
		return NULL;
	}

	L = L->next;
	currentIndex = 1;
	//直到链表为空，或者已经找了这个结点
	while(L != NULL && currentIndex < i){
		L = L->next;
		++currentIndex;
	}
	if(currentIndex < i){
		return NULL;
	}
	
	return L;

}

LinkList Reverse(LinkList &L){
	LNode * s = L->next;
	L->next = NULL;
	LNode* p = NULL;

	//类似于头插法
	while(s != NULL){
		p = s->next;
		s->next = L->next;
		L->next = s;
		s = p;
	}

	return L;
}

LNode* LocateElem(LinkList L, ElemType e){
	LNode* p = L->next;

	while(p != NULL && p->data != e){
		p = p->next;
	}

	return p;
}

bool LinkListInsert(LinkList &L, int i, ElemType e){

	int j = 0;
	LNode * p = NULL;
	LNode * s = NULL;

	if(i == 0){
		return false;
	}

	if(i < 0){
		return false;
	}

	j = 1;
	p = L->next;

	while(p != NULL && j < i-1){
		p = p->next;
		++j;
	}

	if(p == NULL){
		return false;
	}

	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

int main(int argc, char* argv[], char* env[]){
	LinkList L;
	printf("start insert. input 9999 to end inputing.\n");
	LinkHeadInsert(L);
	printf("start print.\n");
	LinkListPrint(L);

	bool result = IsIncrease(L);
	printf("whether LinkList is increaseing. : %d\n", result);

	LNode* elem = GetElem(L, 1);
	printf("this first element: %d\n", elem->data);

	printf("reverse LinkList.\n");
	Reverse(L);
	LinkListPrint(L);

	printf("insert element\n");
	LinkListInsert(L, 3, 8888);
	LinkListPrint(L);

	system("pause");

	return 0;
}
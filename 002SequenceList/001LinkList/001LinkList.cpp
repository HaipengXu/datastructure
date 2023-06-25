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
		s->next = NULL;		//�������˳��ǣ�ֱ����tail�ÿ�
		tail->next = s;
		tail = s;//tail ��Զָ��β��
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
	//1.�������Ϊ�գ�ֱ��Ĭ�ϵ���
	//2.�������ֻ��һ����Ҳ�ǵ���

	while(L != NULL){
		//�Ƿ������һ�����
		if(L->next == NULL){
			return true;
		}

		//��ǰ��������һ����㣬���ǵ���
		if(L->data > L->next->data){
			return false;
		}
		else{
			L = L->next;
		}
	}

	return true;
}


//i��ʾ��ȡ�ڼ���Ԫ�أ�ͷ����ʾ��0��Ԫ��
LNode* GetElem(LinkList L, int i){
	int currentIndex = 0;//��Զָ��Lָ��Ľ������

	if(i == 0){
		return L;
	}
	if(i < 0){
		return NULL;
	}

	L = L->next;
	currentIndex = 1;
	//ֱ������Ϊ�գ������Ѿ�����������
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

	//������ͷ�巨
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
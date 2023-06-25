#include <stdio.h>
#include <queue>
#include <stack>

typedef char ElemType;

struct TreeNode{
	ElemType data;
	struct TreeNode * leftChild;
	struct TreeNode * rightChild;
};

struct QueueNode{
	struct TreeNode * parent;
	bool isLeftIn;
};

void LevelOrder(TreeNode* root){

}

void InsertTreeNode(TreeNode* &root,std::queue<struct QueueNode*> &myQueue, ElemType data){
	if(data != '#'){
		TreeNode* pTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
		pTreeNode->data = data;
		pTreeNode->leftChild = NULL;
		pTreeNode->rightChild = NULL;

		QueueNode * pQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
		pQueueNode->parent = pTreeNode;
		pQueueNode->isLeftIn = false;
		myQueue.push(pQueueNode);

		if(root == NULL){
			root = pTreeNode;
		}
		else{
			QueueNode *pParent = myQueue.front();
			if(pParent->isLeftIn == false){
				pParent->parent->leftChild = pTreeNode;
				pParent->isLeftIn = true;
			}
			else{
				pParent->parent->rightChild = pTreeNode;
				myQueue.pop();
				free(pParent);
			}
		}
	}
	else{
		if(root != NULL){
			QueueNode* pParent = myQueue.front();
			if(pParent->isLeftIn == false){
				pParent->parent->leftChild = NULL;
				pParent->isLeftIn = true;
			}
			else{
				pParent->parent->rightChild = NULL;
				myQueue.pop();
				free(pParent);
			}
		}
		else{
			printf("empty tree!\n");
		}
		
	}
}

void visit(TreeNode* pTreeNode){
	if(pTreeNode != NULL){
		printf("%c ", pTreeNode->data);
	}
}

void PreOrder(TreeNode* root){
	if(root != NULL){
		visit(root);
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}

void PreOrderWithNoRecursion(TreeNode* root){
	std::stack<TreeNode*> treeStack;
	TreeNode * pTreeNode = root;
	while(pTreeNode != NULL || !treeStack.empty()){
		if(pTreeNode){
			visit(pTreeNode);
			treeStack.push(pTreeNode);
			pTreeNode = pTreeNode->leftChild;
		}
		else{
			pTreeNode = treeStack.top();
			pTreeNode = pTreeNode->rightChild;
			treeStack.pop();
		}
	}
}


void InOrderWithNoRecursion(TreeNode* root){
	std::stack<TreeNode*> treeStack;
	TreeNode * pTreeNode = root;
	while(pTreeNode != NULL || !treeStack.empty()){
		if(pTreeNode){
			treeStack.push(pTreeNode);
			pTreeNode = pTreeNode->leftChild;
		}
		else{
			pTreeNode = treeStack.top();
			visit(pTreeNode);
			pTreeNode = pTreeNode->rightChild;
			treeStack.pop();
		}
	}
}

void PostOrderWithNoRecursion(TreeNode* root){
	TreeNode* pTreeNode = root;
	TreeNode* lastReadedTreeNode;
	std::stack<TreeNode*> treeStack;

	while(pTreeNode != NULL || !treeStack.empty()){
		if(pTreeNode != NULL){
			treeStack.push(pTreeNode);
			pTreeNode = pTreeNode->leftChild;
		}
		else{
			pTreeNode = treeStack.top();
			if(pTreeNode->rightChild != NULL && pTreeNode->rightChild != lastReadedTreeNode){
				pTreeNode = pTreeNode->rightChild;
			}
			else{
				visit(pTreeNode);
				lastReadedTreeNode = pTreeNode;
				treeStack.pop();
				pTreeNode = NULL;
			}
		}
	}
}

//层次建树，# 表示插入NULL指针
int main(int argc, char* argv[], char* env[]){

	TreeNode* root = NULL;
	ElemType data[] = "abc##de#f##g###";
	std::queue<struct QueueNode*> myQueue;

	for(int i = 0; data[i] != '\0'; ++i){
		InsertTreeNode(root, myQueue, data[i]);
	}

	//PreOrder(root);
	PreOrderWithNoRecursion(root);
	printf("\n");
	InOrderWithNoRecursion(root);
	printf("\n");
	PostOrderWithNoRecursion(root);
	printf("\n");

	system("pause");
	return 0;
}
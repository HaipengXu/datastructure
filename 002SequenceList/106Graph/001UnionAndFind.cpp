//#include <stdio.h>
//
//#define N 1000
//
//int Father[N];
//int Height[N];
//
//void Init(int n){
//	for(int i = 0; i < n; ++i){
//		Father[i] = i;
//	}
//
//	return;
//}
//
//int Find(int x){
//	while(x != Father[x]){
//		x = Father[x];
//	}
//
//	return x;
//}
//
//int FindWithOptimization(int x){
//	int root = x;
//
//	while(root != Father[root]){
//		root = Father[root];
//	}
//	
//	//此时root指向根节点的下标
//	while(x != root){
//		int t = Father[x];
//		Father[x] = Father[root];
//		x = t;
//	}
//
//	return root;
//}
//
//bool Union(int x, int y){
//	if(Find(x) == Find(y)){
//		return false;
//	}
//	else{
//		Father[Find(y)] = Find(x);
//	}
//
//	return true;
//}
//
//bool UnionWithOptimization(int x, int y){
//	int xRoot = Find(x);
//	int yRoot = Find(y);
//
//	if(xRoot == yRoot){
//		return false;
//	}
//
//	if(Height[x] < Height[y]){
//		Father[x] = y;
//	}
//	else if(Height[y] < Height[x]){
//		Father[y] = x;
//	}
//	else{
//		Father[x] = y;
//		++Height[x];
//	}
//
//	return true;
//}
//
//int main(int argc, char* argv[], char* env[]){
//
//	return 0;
//}
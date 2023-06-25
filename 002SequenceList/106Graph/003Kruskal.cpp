#include <stdio.h>
#include <vector>
#include <algorithm>

//1.����һ�����鼯��ÿ������һ������
//2.�����ж��㰴��Ȩֵ��С��������
//3.��С���󣬱���ÿ����
//		a.���ߵĶ���x,y�Ѿ��ڲ��鼯�У�ֱ�ӱ�����һ����
//		b.�粻�ڣ���x,y����Union�����������ۼ�Ȩֵ

typedef struct Edge{
	int x;
	int y;
	int weight;
}Edge;

#define N 1000

int Father[N];

void Init(int n){
	//�±��1��ʼ
	for(int i = 1; i <= n; ++i){
		Father[i] = i;
	}

	return;
}

int Find(int x){
	while(x != Father[x]){
		x = Father[x];
	}

	return x;
}

bool Union(int x, int y){

	if(Find(x) == Find(y)){
		//���ڵ���ͬ��Unionʧ�ܣ�����false
		return false;
	}
	else{
		Father[Find(y)] = Find(x);
	}

	return true;
}

bool edgeCompare(Edge x, Edge y){
	return x.weight < y.weight;
}

int main(int argc, char* argv[], char* env[]){
	int n;
	
	printf("input 0 to exit\n");
	printf("vertex number: ");
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}

		Init(n);
		std::vector<Edge> edges;

		for(int i = 0; i < n*(n-1)/2; ++i){
			Edge edge;
			scanf("%d%d%d",&edge.x, &edge.y, &edge.weight);
			edges.push_back(edge);

		}

		std::sort(edges.begin(), edges.end(), edgeCompare);
		int totalWeight = 0;

		for(int i = 0; i < n*(n-1)/2; ++i){
			bool result = Union(edges[i].x, edges[i].y);
			if(result == true){
				totalWeight = totalWeight + edges[i].weight;
			}
		}

		printf("totalWeight: %d\n", totalWeight);

	}

	return 0;
}
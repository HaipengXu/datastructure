#include <stdio.h>
#include <vector>
#include <algorithm>

//1.建立一个并查集，每个顶点一个集合
//2.把所有顶点按照权值大小排序，升序
//3.从小到大，遍历每条边
//		a.若边的顶点x,y已经在并查集中，直接遍历下一条边
//		b.如不在，将x,y进行Union操作，并且累加权值

typedef struct Edge{
	int x;
	int y;
	int weight;
}Edge;

#define N 1000

int Father[N];

void Init(int n){
	//下标从1开始
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
		//根节点相同，Union失败，返回false
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
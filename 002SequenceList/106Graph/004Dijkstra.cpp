#include <stdio.h>

//1.初始化dist[]数组，都为-1，表示无穷
//2.确定单源路径的起点，更新dist[]
//3.找出dist[]中，权值最小的顶点，确定它。然后，以这个顶点进行更新dist[]，以此重复，直到所有结点都确定
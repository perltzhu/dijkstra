# dijkstra

##单源最短路径问题定义：

给定一个图G = (V, E)，其中每条边的权是一个非负实数。另外给定V中的一个顶点v，称为源。求从源v到所有其它各个顶点的最短路径。

##单源最短路径贪心选择策略：

选择当前从源v出发用最短的路径所到达的顶点，这就是目前的局部最优解。

##Dijkstra算法思想：

首先设置一个集合S；用数组dis[]来记录v到S中各点的当前最短路径长度。然后不断地用贪心选择来扩充这个集合，并同时记录或修订数组dis[]；直至S包含所有V中顶点。


##具体算法的例子：

###Description

用Dijkstra算法实现单源最短路径问题。

###Input

第一行：n。代表n个顶点。其中第一个顶点为源点 

第二行：c11 c12 c13....c1n (以下n行合起来为n*n的权矩阵，cij代表了i点到j点的边的权值，-1代表无穷大.每行n个数，数与数之间空格隔开) 

第三行：c21 c22 c23....c2n ... 第n行：cn1 cn2 cn3....cnn

###Output

1-2:最短距离(第i点到1的最短距离，冒号后面无空格，直接是最短距离的值。) 1-3:最短距离 ... 1-n:最短距离

###Sample Input

5 0 10 -1 30 100 10 0 50 -1 -1 -1 50 0 20 10 30 -1 20 0 60 100 -1 10 60 0

###Sample Output

1-2:10 1-3:50 1-4:30 1-5:60
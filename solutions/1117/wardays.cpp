
//author :jcvb
//非常巧妙的一份代码
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef double db;
struct edge{
	int v, next;
}e[4005]; int etot = 0; int g[2005];
void ae(int u, int v){
	e[etot].v = v;
	e[etot].next = g[u];
	g[u] = etot++;
}
db p[2005];//rozne,边断开的概率

int qu[2005];//相当于栈
int pre[2005];//v对应的u
int h[2005];//距离帝王的距离
int upe[2005];//v对应的边
int n, m;
void bfs(int rt){
	int p = 0, q = 0;
	for (int i = 1; i <= n; i++)pre[i] = h[i] = 0;
	qu[q++] = rt;
	while (p != q){
		int u = qu[p++];
		for (int i = g[u]; ~i; i = e[i].next){
			if (e[i].v != pre[u]){
				h[e[i].v] = h[u] + 1;
				pre[e[i].v] = u;
				upe[e[i].v] = i >> 1;
				qu[q++] = e[i].v;
			}
		}
	}
}

int main()
{
	memset(g, -1, sizeof(g));
	scanf("%d%d", &n, &m);
	for (int i = 1; i<n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		ae(x, y);
		ae(y, x);
	}
	while (m--){
		int x, d;
		scanf("%d%d", &x, &d);
		bfs(x);
		for (int i = 1; i <= n; i++){
			if (h[i] >= 1 && h[i] <= d + 1)
			{
				//之前未断开现在断开+之前已断开现在断开
				p[upe[i]] = 1.0 / (d + 1) + (h[i] - 1.0) / (d + 1)*p[upe[i]];
			}
		}
	}
	db su = 1.0;
	for (int i = 0; i<n - 1; i++)su += p[i];
	printf("%.10lf\n", su);
	return 0;
}


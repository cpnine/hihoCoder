#include<iostream>
using namespace std;

int pre[501];
int find(int x){
	int r = x;
	while (pre[r] != r) r = pre[r];
	int i = x;
	int j;
	while (i!=r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void join(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) pre[fx] = fy;
}
int main()
{
	int T;	
	cin >> T;
	while (T--){
		bool isTri = true;
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; i++){
			pre[i] = i;
		}
		if (M == N - 1){
			for (int i = 0; i < M; i++){
				int a, b;
				cin >> a >> b;
				join(a,b);
			}
			int father = find(1);
			for (int i = 1; i <=N; i++){
				if (find(i) != father){
					isTri = false;
					break;
				}
			}
		}
		else{
			isTri = false;
			for (int i = 0; i < M; i++){
				int a, b;
				cin >> a >> b;
			}
		}
		if (isTri)cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}


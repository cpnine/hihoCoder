#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
int main()
{
	int sum = 0;
	LL N;
	cin >> N;
	queue<LL> st;
	st.push(N);
	while (!st.empty()){
		N = st.front();
		st.pop();
		if (N == 0){ sum++; continue; }
		if (N % 2 != 0){
			N = N >> 1;
			st.push(N);
		}
		else{
			LL mm = N >> 1;
		    st.push(mm);
			mm = (N - 1) >> 1;
			st.push(mm);
		}
		
	}
	cout << sum << endl;
	return 0;
}


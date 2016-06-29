//author:cpnine

#include<iostream>
using namespace std;
int vec[101];
int getcommon(int a, int b){
	if (a < b){
		int temp = a;
		a = b;
		b = temp;
	}
	while (a%b!=0)
	{
		int t = b;
		b = a%b;
		a = t;
	}
	return b;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> vec[i];
	}
	int common = 1;
	int sum = 0;
	for (int i = 1; i <= N; i++){
		int s = vec[i];
		if (s == i)continue;
		int num = 1;
		while (s != i){
			s = vec[s];
			num++;
		}
		if (i == 1){
			common = num;
			sum = num;
		}
		else{
			common = getcommon(num, sum);
			sum = sum / common*num;
		}
	}
	cout << sum<< endl;
	return 0;
}


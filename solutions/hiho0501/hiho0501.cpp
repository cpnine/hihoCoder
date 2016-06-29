//author:cpnine
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	while (N--){
		char vec[1001];
		scanf("%s",&vec);
		int one = 0;
		int zero = 0;
		for (int i = 0; i < strlen(vec); i++){
			if (vec[i] == '1')one++;
			else zero++;
		}
		int resume = 1001;
		int zeroToone= zero;
		int oneTozero = 0;
		resume = min(resume, zeroToone);
		for (int i = 0; i < strlen(vec); i++){
			if (vec[i] == '0'){
				zeroToone--;
			}
			else{
				oneTozero++;
			}
			//假如将所有的零全改为1，需zero次，现从左往右将该为1的序列改为零，
			//本来是零，少改一个零，本来是1，需将1改为0
			resume = min(resume,zeroToone+oneTozero);
		}
		printf("%d\n",resume);
	}
	return 0;
}


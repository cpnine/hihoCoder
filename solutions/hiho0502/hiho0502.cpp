//author: 	liubiao2638
#include <stdio.h>

char s[100001], t[100001];
int n[26], N;

int put() {
	int oldci = -1;
	for (int i = 0; i < N; ++i)  {
		int ci = -1;
		for (int j = 0; j < 26; ++j) {
			if (j != oldci && n[j] != 0) {
				if (ci == -1) ci = j;
				else {
					if (2 * n[j] > N - i) {
						//if (2 * n[ci] > N - i) 
						//	return 0;//??
						ci = j;
					}
				}
			}
		}
		if (ci == -1)
			return 0;
		oldci = ci;
		n[ci]--;
		t[i] = 'a' + ci;
	}
	return 1;
}

int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) {
		n[s[i] - 'a']++;
		N++;
	}
	if (put() == 0)
		printf("INVALID\n");
	else
		printf("%s\n", t);
	return 0;
}

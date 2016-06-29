#include<string>
#include<stack>
#include<iostream>
using namespace std;
int cal(char m,int a,int b){
	if (m == '+'){
		return a + b;
	}
	else if(m=='-'){
		return a - b;
	}
	else if(m=='*'){
		return a*b;
	}
	else if (m == '/'){
		return a / b;
	}
	return 0;
}
int main()
{
	string s;
	cin >> s;
	int i = 0;
	stack<int> si;
	stack<char> sc;
	while (i<s.size())
	{
		if (isdigit(s[i])){
			int len = 0;
			int k = i;
			while (isdigit(s[i])){
				len++;
				i++;
			}
			int d = stoi(s.substr(k,len));
			si.push(d);

		}
		else{
			if (s[i] == '+' || s[i] == '-'||s[i]==')'){
				while (!sc.empty() && sc.top() != '('){
					char c = sc.top();
					sc.pop();
					int right = si.top(); si.pop();
					int left = si.top(); si.pop();
					si.push(cal(c,left,right));
				}
				if (s[i]==')'&&!sc.empty()&&sc.top() == '('){
					sc.pop();
				}
				if(s[i]!=')')sc.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/'||s[i]=='('){
				sc.push(s[i]);
			}
			
			i++;
		}
	}
	while (!sc.empty())
	{
		char c = sc.top();sc.pop();
		int right = si.top(); si.pop();
		int left = si.top(); si.pop();
		si.push(cal(c, left, right));
	}
	cout << si.top() << endl;
	return 0;
}


#include<iostream>
#include<stack>
using namespace std;
char int_to_num(int modu) {
	if (modu <= 9) {
		switch (modu)
		{
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 0: return '0'; break;
		default:
			//cout << "default" << endl;
			break;
		}
	}
	else {
		int a = 'A' - 0;
		return (char)(modu - 10 + a);
	}
}
int main() {
	long long n, b;
	int modu;
	stack<char> s;
	cin >> n >> b;
	while (n / b > 0) {
		modu = n % b;
		n /= b;
		s.push(int_to_num(modu));
		//cout << int_to_num(modu) << endl;
	}
	if (n % b > 0) {
		//cout << "!!"<<n%b<<endl;
		s.push(int_to_num(n % b));
	}
	//cout << "size : " << s.size()<<endl;
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	
}
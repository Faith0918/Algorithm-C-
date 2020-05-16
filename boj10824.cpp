#include<iostream>
#include<string>

using namespace std;

int main() {
	long long a, b, c, d;
	
	string as, bs, cs, ds;
	cin >> a >> b >> c >> d;
	as = to_string(a);
	bs = to_string(b);
	cs = to_string(c);
	ds = to_string(d);
	as = as + bs;
	bs = cs + ds;
	//string 이어붙인 후 int 범위를 넘어가는 것에 주의한다. 
	a = stoll(as);
	b = stoll(bs);
	cout << a + b;
}
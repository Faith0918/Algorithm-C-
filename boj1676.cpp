#include<iostream>
#include<algorithm>
using namespace std;

int count2 =0;
int count5 =0;

void factorial(int n) {
	cout << "??"<<n<<endl;
	if (n <= 1) {
		cout << "11";
		return;
	}
	else {
		cout << "22";
		int i = n;
		while (i % 2 == 0 || i % 5 == 0) {
			cout << "while" << endl;
			if (i % 2 == 0) {
				count2++;
				i /= 2;
			}
			if (i % 5 == 0) {
				count5++;
				i /= 5;
			}
		}
		factorial(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	factorial(n);
	cout <<"!!"<< min(count2, count5);
	
}
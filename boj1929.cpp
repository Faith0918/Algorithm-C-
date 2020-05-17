//소수 찾기 => 가장 빠른 방법 중 하나 에라토스테네스의 채
//2의 배수 지우기, 3의 배수 지우기, 4의 배수 지우기.. and so on
#include<iostream>
#include<list>
#include<math.h>

using namespace std;

int main() {
	int m, n;
	int* array = new int[1000001];
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		array[i] = 1;
	}
	array[1] = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		
		for (int j = i*i; j <= n; j= j+i) {
			array[j] = 0;

		}
	}
	for (int i = m; i <= n; i++) {
		if (array[i] == 1) {
			cout << i << "\n";
		}
	}

}
//연산자 끼워넣기
#include<iostream>

using namespace std;

long long maxx = -(long long)1e10;
long long minn = (long long) 1e10;
int n;
long long num[12] = {};
int op[4] = {};//{+,-,*,/}
int cases[11] = {};
int co = 0;
void dfs(int count, int oper[4]) {
	if (count == n-1) {
		co++;
		
		int candi = num[1];
		for (int i = 2; i <= n; i++) {
			if (cases[i - 1] == 0) {
				candi += num[i];
			}
			else if (cases[i - 1] == 1) {
				candi -= num[i]; 
			}
			else if (cases[i - 1] == 2) {
				candi *= num[i];
			}
			else if (cases[i - 1] == 3) {
				candi /= num[i];
			}
			else {
				return;
				cout << "else " << cases[i - 1] << endl;
			}
			
		}
		if (candi < minn) {
			minn = candi;
		}
		if (candi > maxx) {
			maxx = candi;
		}
		return;

	}
	else {
		int i = count + 1;
		while (i <= n - 1) {
			for (int j = 0; j < 4; j++) {
				if (op[j] > 0) {
					cases[i] = j;
					oper[j]--;
					dfs(count + 1, oper);
					oper[j]++;
					bool available = false;
					for (int k = j+1; k < 4; k++) {
						if (oper[k] > 0) {
							available = true;
						}
					}
					if (!available) {
						return;
					}
					
				}
				
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	cin >> op[0] >> op[1] >> op[2] >> op[3];
	for (int i = 1; i <= n - 1; i++) {
		cases[i] = -1;
	}
	dfs(0, op);
	//cout << co << "\n";
	cout << maxx << "\n";
	cout << minn;
}
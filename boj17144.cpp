//미세먼지 안녕!
#include<iostream>

using namespace std;


class AirFreshner {
public:
	int upper_r;
	int lower_r;

};
int r, c, t;
int map[51][51] = {};
AirFreshner af;

void printMap() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << map[i][j] << "	";
		}
		cout << endl;
	}
}
void defuse() {
	int count[51][51] = {};
	int visit[51][51][4] = {};
	int dr[4] = { 0,0,1,-1 };
	int dc[4] = { 1,-1,0,0 };
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j]/5 > 0) {
				int next_r;
				int next_c;
				for (int k = 0; k < 4; k++) {
					next_r = i + dr[k];
					next_c = j + dc[k];
					if (next_r >= 1 && next_r <= r && next_c >= 1 && next_c <= c && map[next_r][next_c] != -1) {
						count[i][j]++;
						visit[i][j][k] = 1;
					}
				}
			}
			
		}
	}
	int new_map[51][51] = {};
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			new_map[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (count[i][j] != 0) {
				int next_r;
				int next_c;
				for (int k = 0; k < 4; k++) {
					if (visit[i][j][k] == 1) {
						next_r = i + dr[k];
						next_c = j + dc[k];
						new_map[next_r][next_c] += map[i][j] / 5;
					}
				}
				new_map[i][j] -= map[i][j] / 5 * count[i][j];
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] = new_map[i][j];
		}
	}
				

}
void upFresh(int af) {
	int temp1 = map[af][c];
	for (int i = c; i >1; i--) {//right way
		map[af][i] = map[af][i-1];
	}
	map[af][2] = 0;
	int temp2 = map[1][c];
	for (int i = 1; i < af - 1; i++) {//up way
		
		map[i][c] = map[i + 1][c];
	}
	map[af - 1][c] = temp1;
	int temp3 = map[1][1];
	for (int i = 1; i < c - 1; i++) {// left way
		map[1][i] = map[1][i + 1];
	}
	map[1][c - 1] = temp2;
	for (int i = af - 1; i > 2; i--) {//down way
		map[i][1] = map[i - 1][1];
	}
	map[2][1] = temp3;

}
void lowFresh(int af) {
	int temp1 = map[af][c];
	for (int i = c; i >1; i--) {//right way
		map[af][i] = map[af][i - 1];
	}
	map[af][2] = 0;
	int temp2 = map[r][c];
	for (int i = r; i > af; i--) {//down way
		map[i][c] = map[i - 1][c];
	}
	map[af+1][c] = temp1;
	int temp3 = map[r][1];
	for (int i = 1; i < c - 1; i++) {//left way
		map[r][i] = map[r][i + 1];
	}
	map[r][c - 1] = temp2;
	for (int i = af + 1; i < r - 1; i++) {//up way
		map[i][1] = map[i + 1][1];

	}
	map[r - 1][1] = temp3;

}
void freshAir() {
	int upper = af.upper_r;
	int lower = af.lower_r;
	upFresh(upper);
	lowFresh(lower);
}

int sumDust() {
	int sum = 2;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool has_af = false;
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (!has_af) {
					af.upper_r = i;
					has_af = true;
				}
				else {
					af.lower_r = i;
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		defuse(); 
		freshAir();

	}
	
	cout<< sumDust();

}
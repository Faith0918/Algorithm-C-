#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int r, c, k, t, cur_idx;
vector<vector<int> > arr;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
		
		
	}
}
bool compare_r(int a, int b) {
	if (a > 0 && b > 0) {
		return a < b;
	}
	else {
		return a > b;
	}
}
bool compare_c(vector<int>& a, vector<int>& b) {
	int i = cur_idx;
	if (a[i] > 0 && b[i] > 0) {
		return a[i] < b[i];
	}
	else {
		return a[i] > b[i];
	}
	
}

void r_op(int R, int C) {
	//R 연산 : 모든 행에 대하여 sort
	//등장회수의 오름차줏, 숫자의 오름차순으로 정렬
	//정렬 후 숫자, 등장회수 순으로 넣는다. 
	int max_size = 0;
	for (int i = 0; i < R; i++) {
		//0을 제외한 모든 수 오름차순 정렬
		sort(arr[i].begin(), arr[i].end(), compare_r);
		//logstart --------------------------------
		cout << "R operation sort result by row : ";
		for (int j = 0; j < C; j++) {

			cout << arr[i][j] << " ";

		}
		cout << "\n";
		//log end ----------------------------------
		//각 행에 숫자가 몇번 등장하는지 센다.
		//한 행의 첫번째 숫자를 한번 센다.
		int cnt = 1;
		int state = arr[i][0];
		vector<pair<int, int> > temp;//first : state, second : count
		vector<int> new_v;
		for (int j = 1; j < C; j++) {
			if (state == 0) {
				break;
			}
			if (arr[i][j] == state) {
				//마지막 숫자가 이전 숫자와 같다면 cnt+1한 값을 vector에 추가
				if (j == C - 1) {
					temp.push_back(make_pair(state, cnt + 1));
				}
				cnt++;
			}
			else {
				temp.push_back(make_pair(state, cnt)); 
				cnt = 1;
				state = arr[i][j];
				if (state == 0) {
					break;
				}
				if (j == C - 1) {
					temp.push_back(make_pair(state, 1));
				}
			}
		}
		sort(temp.begin(), temp.end(), compare);
		for (int j = 0; j < temp.size(); j++) {
			new_v.push_back(temp[j].first);
			new_v.push_back(temp[j].second);
		}
		arr[i] = new_v;
		if (new_v.size() > max_size) {
			max_size = new_v.size();
		}
	}
	for (int i = 0; i < R; i++) {
		arr[i].resize(min(100, max_size), 0);
	}

	//log
	cout << "R 연산\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < min(100, max_size); j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void c_op(int R, int C) {
	int max_size = 0;
	vector<vector<int> > c_v;
	for (int i = 0; i < C; i++) {
		cur_idx = i;
		sort(arr.begin(), arr.end(), compare_c);
	
		//log start-------------------------------------
		cout << "C operation sort result by row : ";
		for (int j = 0; j < R; j++) {

			cout << arr[j][i] << " ";
		}
		cout << "\n";
		//log end -----------------------------------
		int cnt = 1;
		int state = arr[0][i];
		vector<pair<int, int> > temp;
		vector<int> new_v;
		for (int j = 1; j < R; j++) {
			if (state == 0) {
				break;
			}
			if (arr[j][i] == state) {
				if (j == R - 1) {
					temp.push_back(make_pair(state, cnt + 1));
				}
				cnt++;
			}
			else {
				temp.push_back(make_pair(state, cnt));
				cnt = 1;
				state = arr[j][i];
				if (state == 0) {
					break;
				}
				if (j == R - 1) {
					temp.push_back(make_pair(state, 1));
				}
			}
		}
		sort(temp.begin(), temp.end(), compare);
		for (int j = 0; j < temp.size(); j++) {
			new_v.push_back(temp[j].first);
			new_v.push_back(temp[j].second);
		}
		c_v.push_back(new_v);
		if (new_v.size() > max_size) {
			max_size = new_v.size();
		}
	}
	for (int i = R; i < min(100, max_size); i++) {
		vector<int> n_v(C, 0);
		arr.push_back(n_v);
	}
	for (int i = 0; i < C; i++) {
		c_v[i].resize(min(100, max_size), 0);
		for (int k = 0; k < min(100, max_size); k++) {
			arr[k][i] = c_v[i][k];
		}
	}
	cout << "C 연산\n";
	for (int i = 0; i < min(100, max_size); i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {
	t = 0;
	cin >> r >> c >> k;
	//그래프 입력
	for (int i = 0; i < 3; i++) {
		vector<int> v(3);
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			v[j] = a;
		}
		arr.push_back(v);
	}
	cout << "input : ";
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {

			cout << arr[i][j] << " ";
		}
	}
	
	cout << "\n";
	//arr[r-1][c-1] == k일때까지 반복
	while (1) {
		//100초가 넘어갈 때 -1 출력
		if (t > 100) {
			cout << -1;
			return 0;
		}
		//arr[r-1][c-1] == k일 때 t 반환
		if (arr.size() >= r && arr[0].size() >= c && arr[r-1 ][c-1 ] == k) {
			cout << arr[r - 1][c - 1] << endl;
			cout << arr[r ][c ] << endl;
			cout << t;
			return 0;
		}
		//arr[r-1][c-1] != k일 때 R/C연산 수행
		else {
			t++;
			int R = arr.size();
			int C = arr[0].size();
			if (R >= C) {
				r_op(R,C);
			}
			else{
				//C연산 : (1)모든 열에 대하여 sort
				//(2)등장회수의 오름차순, 숫자의 오름차순으로 정렬
				//(3)정렬 후 숫자, 등장회수 순으로 넣는다.
				c_op(R, C);
				
			}
		}
	}
	//
}

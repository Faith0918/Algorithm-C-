#include<iostream>
#include<vector>

using namespace std;

class node {
public:
	int point;
	bool isBlue;

};

class horse {
public:
	int graph_type;
	int idx;
};

int arr[11];
int maxx = 0;
vector<node> g[4];
int moving[11] = {};
int moving_idx[11] = {};
horse h[4];
int scoreboard[11] = {};

void backward(int i, int cnt) {
	
	h[i].idx -= moving[cnt];
	
	if (h[i].idx == 0 && h[i].graph_type > 0) {
		if (h[i].graph_type == 1) {
			h[i].idx = 5;
		}
		else if (h[i].graph_type == 2) {
			h[i].idx = 10;
		}
		else if (h[i].graph_type == 3) {
			h[i].idx = 15;
		}
		h[i].graph_type = 0;
	}
	
}
bool collision_check(horse candi, int i) {
	//int goal = candi.idx;

	for (int j = 0; j < 4; j++) {
		if (j != i) {

			if (h[j].graph_type == candi.graph_type && h[j].idx == candi.idx && g[candi.graph_type][candi.idx].point != 0) {
				//그래프의 종류와 인덱스가 같을 때
				return true;
			}
			if (candi.graph_type > 0 && h[j].graph_type > 0 && g[candi.graph_type][candi.idx].point == g[h[j].graph_type][h[j].idx].point && g[candi.graph_type][candi.idx].point != 0) {
				//그래프 1,2,3에서 같은 위치에 도달했을 때
				return true;
			}
			if (g[candi.graph_type][candi.idx].point == 40 && g[h[j].graph_type][h[j].idx].point == 40) {
				//그래프 0,1,2,3,4에서 같은 위치에 도달했을 때
				return true;
			}

		}

	}
	return false;
}

bool move(int i, int cnt) {
	horse candi = h[i];
	int step = arr[cnt];
	
	//already in finish line
	if (g[candi.graph_type].size()-1 == candi.idx) {
		return false;
	}
	//if starting point is blue
	if (g[candi.graph_type][candi.idx].isBlue) {
		candi.graph_type = g[candi.graph_type][candi.idx].point / 10;
		candi.idx = 0;
	}
	int goal = candi.idx + step;
	//collision check
	
	if (candi.idx + step > g[candi.graph_type].size()-1) {
		moving[cnt] = g[candi.graph_type].size() - candi.idx - 1;
		candi.idx = g[candi.graph_type].size()-1;
		//collision check
		if (collision_check(candi, i)) {
			return false;
		}
		
	}
	else {
		moving[cnt] = step;
		candi.idx += step;
		//collision check
		if (collision_check(candi, i)) {
			return false;
		}
		
	}
	
	h[i] = candi;
	
	
	scoreboard[cnt] = g[h[i].graph_type][h[i].idx].point;
	return true;	
}

void dfs(int cnt) {
	if (cnt == 10) {
		int candi = 0;
		for (int i = 0; i <= 10; i++) {
			candi += scoreboard[i];
		}
		if (candi > maxx) {
			maxx = candi;
			
		}
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			
			if (move(i, cnt)) {
				moving_idx[cnt] = i;
				dfs(cnt + 1);
				backward(i, cnt);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i <= 20; i++) {
		node n;
		n.point = i * 2;
		if (i % 5 == 0 && i < 20 && i>0) {
			n.isBlue = true;
		}
		else {
			n.isBlue = false;
		}

		g[0].push_back(n);
	}
	for (int i = 1; i <= 3; i++) {
		node n;
		n.point = i * 10;
		n.isBlue = true;
		g[i].push_back(n);
		if (i == 1) {
			for (int j = 13; j <= 19; j += 3) {
				node a;
				a.isBlue = false;
				a.point = j;
				g[i].push_back(a);
			}
		}
		else if (i == 2) {
			n.isBlue = false;
			n.point = 22;
			g[i].push_back(n);
			n.point = 24;
			g[i].push_back(n);
			
		}
		else {
			n.isBlue = false;
			for (int j = 28; j >= 26; j --) {
				n.point = j;
				g[i].push_back(n);
			}
		}
		
		for (int j = 25; j <= 40; j += 5) {
			n.point = j;
			n.isBlue = false;
			g[i].push_back(n);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		node last;
		last.point = 0;
		last.isBlue = false;
		g[i].push_back(last);
		h[i].graph_type = 0;
		h[i].idx = 0;
	}
	dfs(0);

	cout << maxx;

}
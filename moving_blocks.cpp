#include <string>
#include <vector>
#include <queue>
using namespace std;
struct State {
    vector<pair<int, int>> posi;
    int time;
};

bool isMovable(int type, vector<vector<int>> board, vector<pair<int, int>> posi) {
    pair<int, int> a = posi[0];
    pair<int, int> b = posi[1];
    if (type == 0) {
        //move right
        //TODO : need to check if the next posi is in the board
        //if right side is empty
        if (board[a.first][a.second + 1] == 0 && board[b.first][b.second + 1]==0) {
            return true;
        }
    }
    else if (type == 1) {
        //move down
        //if down side is empty
        if (board[a.first+1][a.second] == 0 && board[b.first+1][b.second ]==0) {
            return true;
        }
    }
    else if (type == 2) {
        //rotate left
        //if down side is empty
        if ( board[b.first + 1][b.second + 1] == 0 && board[b.first + 1][b.second] == 0) {
            return true;
        }
    }
    else if (type == 3) {
        //rotate right
        if (board[a.first + 1][a.second+1] == 0  && board[a.first + 1][a.second] == 0) {
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> move(int type, vector<pair<int, int>> posi) {
    vector<pair<int, int>> next_posi;

    return next_posi;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    queue<State> q;
    State init;
    vector<pair<int,int>> v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(0, 1));
    init.posi = v;
    init.time = 0;
    q.push(init);
    while (!q.empty()) {
        State cur_state = q.front();
        q.pop();
        vector<pair<int, int>> cur_posi = cur_state.posi;
        int cur_time = cur_state.time;
        //When it reached n,n
        if (cur_posi[1].first == board.size() - 1 && cur_posi[1].second == board.size() - 1) {
            answer = cur_time;
            break;
        }
        //Check if it's movable
        for (int i = 0; i < 4; i++) {
            if (isMovable(i, board, cur_posi)) {
                vector<pair<int,int>> next_posi = move(i, cur_posi);
                State next_state;
                next_state.posi = next_posi;
                next_state.time = cur_time + 1;
                q.push(next_state);
            }
        }

    }
    return answer;
}
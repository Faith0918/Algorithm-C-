#include <iostream>

using namespace std;
int n;
int result = 0;
int map[31] = { 0,5,10,15,20,50,30,35,40,45,100,55,60,65,70,75,80,85,90,95,500,1000,275,250,300,150,175,150,125,350,400 };
int score[11] = {};
int horse[5] = { 0 };
int m[31][5] = { 0 };
int main() {

    int temp[11][6] = { {5,22,23,24,25,26},
      {10,27,28,24,29,30},
      {22,23,24,25,26,15},
      {23,24,25,26,15,16},
      {24,29,30,20,21,21},
      {25,26,15,16,17,18},
      {26,15,16,17,18,19},
      {27,28,24,29,30,20},
      {28,24,29,30,20,21},
      {29,30,20,21,21,21},
      {30,20,21,21,21,21}
    };
    for (int i = 0; i < 11; i++) {
        for (int j = 1; j < 6; j++) {
            m[temp[i][0]][j] = temp[i][j];
        }

    }
    cin >> n;
    int a[11];
    int seq[11];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int w;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];

    }
    for (int i = 0; i < n; i++) {
        bool flag = false;
        bool finish = false;
        for (int j = 0; j < 11; j++) {
            if (temp[j][0] == horse[seq[i]]) {
                flag = true;
                return 0;
            }
        }
        if (flag) {
            horse[seq[i]] = m[horse[seq[i]]][a[i]];
        }
        else {
            if (horse[i] + a[i] >= 21) {
                finish = true;
                horse[i] = 21;
            }
            else {
                horse[seq[i]] += a[i];
            }

        }
        if (!finish) {
            for (int j = 1; j < 5; j++) {
                if (j != seq[i] && horse[seq[i]] == horse[seq[j]]) {
                    //crash
                    cout << "-1\n";
                    return 0;
                }
            }
        }

    }
    for (int i = 1; i < 5; i++) {
        result += a[horse[i]];
    }
    cout << result;

    return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int num_of_five(int n) {
    int num = 0;
    int div = 5;
    while (n >= div) {
        num = num + n / div;
        div = div * 5;
    }
    return num;
}

int num_of_two(int n) {
    int num = 0;
    int div = 2;
    while (n >= div) {
        num = num + n / div;
        div = div * 2;
    }
    return num;
}



int main() {
    int n, m;
    cin >> n >> m;

    int two = num_of_two(n) - num_of_two(m) - num_of_two(n - m);
    int five = num_of_five(n) - num_of_five(m) - num_of_five(n - m);
    printf("%d", min(two, five));
}

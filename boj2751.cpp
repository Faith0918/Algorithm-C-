#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int arr[1000001] = {};

void Print(int a[]){
	for(int i = 1; i<=n; i++){
		printf("%d\n",arr[i]);
	}	
}
int main(){
	
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>arr[i];
	}
	
	sort(arr+1,arr+n+1);
	Print(arr);
}

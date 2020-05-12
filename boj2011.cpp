#include<iostream>
using namespace std;
int main(){
	string num;
    int n;
    int d[5001]={0,};
    int max = (int)1e6;
    cin>>num;
    num = " "+num;
	n = num.length()-1;
	d[0] = 1;
	d[1] = 1;
	if(num[1] == '0'){
		cout<<0<<endl;
		return 0;
	}
	
    for(int i = 2; i<=n; i++){
    	int x = num[i]-'0';
    	int y = (num[i-1]-'0')*10 + x;
    	
        if(x>=1 && x<=9){
            d[i] += d[i-1];
            d[i]%=max;
        }
        
    	if(y>=10&&y<=26){
			d[i] += d[i-2];
            d[i]%=max;
//    		cout<<"i : "<<i<<"d[i] : "<<d[i]<<endl;
		}
        
        
    }
    cout<<d[n]<<endl;
    return 0;
}

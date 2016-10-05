#include <bits/stdc++.h>
using namespace std;

int main(){
	int account=0,T,i=0,donation;
	string word;
	cin >> T;
	while(i<T){
		cin >> word;
		if(word.at(0)=='d'){
			cin >> donation;
			account+=donation;
		}else{
			cout << account << endl;
		}
		i++;
	}
	return 0;
}
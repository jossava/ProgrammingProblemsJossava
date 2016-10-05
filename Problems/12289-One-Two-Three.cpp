#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,i=0;
	string word;
	cin >> T;
	while(i<T){
		cin >> word;
		if(word.size()==5){ 
			cout << 3 << endl;
		}else{			
			if((word.at(0)=='o') + (word.at(1)=='n') + (word.at(2)=='e') > 1) cout << 1 << endl;
			else cout << 2 << endl;
		}
		i++;
	}
	return 0;
}
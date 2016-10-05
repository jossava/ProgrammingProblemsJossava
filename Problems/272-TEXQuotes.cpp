#include <bits/stdc++.h>
using namespace std;

int main(){
	string line;
	while(getline(cin,line)){
		line=" "+line;
		for(int i=0 ; i<line.size()-1 ; i++){
			if(line.at(i+1)=='"'){
				if(line.at(i)==' ' || line.at(i)=='"'){
					line=line.substr(0,i+1)+"``"+line.substr(i+2,line.size());
				}else{
					line=line.substr(0,i+1)+"''"+line.substr(i+2,line.size());
				}
			}
		}
		line=line.substr(1,line.size());
		cout << line << endl;
	}
	return 0;
}
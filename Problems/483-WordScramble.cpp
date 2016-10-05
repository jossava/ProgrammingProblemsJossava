#include <bits/stdc++.h>
using namespace std;

int main(){
	string line;
	while (getline(cin, line)){
		stringstream ss(line); // El stream ss se crea con line
		string word;
		ss >> word;
		for(int i=word.size()-1; i>=0 ; i--){
			cout << word[i];
		}
		while (ss >> word){  // ss se usa igual que cin
			cout << " ";
			for(int i=word.size()-1; i>=0 ; i--){
				cout << word[i];
			}
		}
		cout << endl;
	}
	return 0;
}
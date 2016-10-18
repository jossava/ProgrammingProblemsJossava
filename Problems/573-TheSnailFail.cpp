#include <bits/stdc++.h>
using namespace std;

int main(){
    double IH,DC,HAC,HAS,H,U,D,F,day;
    bool sigue;
    while(cin >> H >> U >> D >> F){
        sigue=true;IH=0.0;DC=0.0;HAC=0.0;HAS=0.0;day=0.0;
        while(sigue){
        	if(H==0 and U==0 and D==0 and F==0) break;
        	if(HAC>=H){
        		sigue=false;
        		cout << "success on day " << day << endl;
        	}else{
        		if(HAC<0){
        			sigue=false;
        			cout << "failure on day " << day << endl;
        		}else{
        			IH=HAS;
        			DC=U-(day*(U*F)/100);
        			HAC=IH+DC;
        			HAS=HAC-D;
        			day++;
        		}
        	}
        }
    }
    return 0;
}
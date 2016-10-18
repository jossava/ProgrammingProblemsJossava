#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

vector<int> g[MAXN], grev[MAXN], sortTop;
bool state[MAXN];
int scc[MAXN], arIn[MAXN];
void dfs1(int u){
	state[u]=true;
	for(int i=0; i<g[u].size(); ++i){
		int nextNode = g[u][i];
		if(!state[nextNode]) dfs1(nextNode);
	}
	sortTop.push_back(u);
}
void dfs2(int u, int comp){
	scc[u]=comp;
	for(int i=0; i<grev[u].size(); ++i){
		int nextNode = grev[u][i];
		if(scc[nextNode]!=-1) dfs2(nextNode, comp);
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, m, x, y;
		cin >> n >> m;
		while(cin >> x >> y){
			g[x-1].push_back(y-1);
			grev[y-1].push_back(x-1);
		}
		for (int i = 0; i < sortTop.size(); ++i) sortTop[i]=0; 
		for (int i = 0; i < sortTop.size(); ++i){
			if(!state[i]){
				dfs1(i);
			}
		}
		reverse(sortTop.begin(),sortTop.end());
		for (int i = 0; i < sortTop.size(); ++i) cout << sortTop[i] << endl;
	}
	return 0;
}

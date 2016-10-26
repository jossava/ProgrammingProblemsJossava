#include <bits/stdc++.h>
using namespace std;
int const MAXN=1010;
string emp[MAXN];
vector<int> g[MAXN];
vector<int> grev[MAXN];
vector<int> topoSort;
bool seen[MAXN];
int scc[MAXN];

int buscarEmp(string empl, int n){
	for(int i=0; i<n; ++i){
		if(!emp[i].compare(empl)){
			return i;
		}
	}
	return -1;
}

void dfs1(int u){
	seen[u]=true;
	for(int i=0; i<g[u].size(); ++i){
		int v = g[u][i];
		if(!seen[v]) dfs1(v);
	}
	topoSort.push_back(u);
}

void dfs2(int u, int comp){
	scc[u]=comp;
	for(int i=0; i<grev[u].size(); ++i){
		int v=grev[u][i];
		if(scc[v]==-1) dfs2(v, comp);
	}
}

int main(){
	int P,T;
	char str1 [80], str2 [80], s1[80], s2[80];
	string person,emp1,emp2;
	cin >> P >> T;
	while(P!=0 && T!=0){
		int j=0;int k=0;
		for(int i=0; i<P; ++i){
			g[i].clear();
			grev[i].clear();
			topoSort.clear();
			seen[i]=false;
			scc[i]=-1;
			emp[i]="";
		}
		while(j<P){
			scanf("%s %s", str1, str2);
			strcat(str1," ");
			strcat(str1,str2);
			emp[j]=str1;
			j++;
		}
		while(k<T){
			scanf("%s %s", str1, str2);
			strcat(str1," ");
			strcat(str1,str2);
			int x=buscarEmp(str1,P);
			scanf("%s %s", s1, s2);
			strcat(s1," ");
			strcat(s1,s2);
			int y=buscarEmp(s1,P);
			k++;
			g[x].push_back(y);
			grev[y].push_back(x);
		}
		for(int i=0; i<P; ++i){
			if(!seen[i]) dfs1(i);
		}
		reverse(topoSort.begin(),topoSort.end());
		int comp=0;
		for(int i=0; i<P; ++i){
			int u=topoSort[i];
			if(scc[u]==-1) dfs2(u,comp++);
		}
		cout << comp << endl;
		//cout << P << " " << T << endl;
		cin >> P >> T;
	}
	return 0;
}
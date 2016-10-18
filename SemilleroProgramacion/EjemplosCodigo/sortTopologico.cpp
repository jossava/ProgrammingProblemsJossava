#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define MAXN 100
#define D(x) //cout << #x << " " << x << endl
 
vector<int> g[MAXN], ans;
int a[MAXN];
bool state[MAXN];
 
void dfs(int u) {
  state[u] = true;
  for(int i = 0; i < g[u].size(); ++i) {
    int nextNode = g[u][i];
    if(!state[nextNode]) dfs(nextNode);
  }
  ans.push_back(u);
}
 
void sortTop(int n) {
  for(int i = 0; i <= n; ++i) state[i] = false;
  for(int i = 0; i < n; ++i) {
    if(!state[i]) dfs(i);
  }
  reverse(ans.begin(), ans.end());
}
 
int main() {
  int n;
  cin >> n;
  int nodes = n;
  while(n --) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      //g[y].push_back(x);
  }
  D(nodes);
  sortTop(nodes);
  //for(int i = 0; i < 50; ++i) cout << a[i] << endl;
  for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
}
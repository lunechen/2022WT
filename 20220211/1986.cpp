//LCA(Tree distance) Tarjan
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int n, m, a, b, l;
int pa[40010];
int dis[40010];
int ans[10010];
int visited[40010];
vector <pair <int, int> > q[40010];
vector <pair <int, int> > mp[40010];

void init(){
    for (int i=0; i<40010; i++){
        pa[i]=i;
        visited[i]=0;
        q[i].clear();
        mp[i].clear();
    }
}

int find(int x){
    if (pa[x]==x) return x;
    return pa[x]=find(pa[x]);
}

void DFS(int level, int w){
    pair <int, int> tmp;
    dis[level]=w;
    visited[level]=1;

    for (int i=0; i<(int)mp[level].size(); i++){
        tmp=mp[level][i];
        if (!visited[tmp.first]){
            DFS(tmp.first, w+tmp.second);
            pa[tmp.first]=level;
        }
    }

    for (int i=0; i<(int)q[level].size(); i++){
        tmp=q[level][i];
        if (visited[tmp.first]){
            ans[tmp.second]=dis[level]+dis[tmp.first]-2*dis[find(tmp.first)];
        }
    }
}

int main(){
    init();

    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d %d %d %*c", &a, &b, &l);
        mp[a].push_back({b, l});
        mp[b].push_back({a, l});
    }

    scanf("%d", &m);
    for (int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        q[a].push_back({b, i});
        q[b].push_back({a, i});
    }

    DFS(1, 0);

    for (int i=0; i<m; i++) printf("%d\n", ans[i]);
    
    return 0;
}
//Tree Diameter DFS
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int n, m, a, b, l;
vector <pair <int, int> > mp[40010]; 

void DFS(int node, int tmp_l, int parent){
    int tmp_ll;
    for (int i=0; i<(int)mp[node].size(); i++){
        if (mp[node][i].first==parent) continue;
        tmp_ll=tmp_l+mp[node][i].second;
        if (tmp_ll>l){
            l=tmp_ll;
            a=mp[node][i].first;
        }
        DFS(mp[node][i].first, tmp_ll, node);
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        scanf("%d %d %d %*c", &a, &b, &l);
        mp[a].push_back({b, l});
        mp[b].push_back({a, l});
    }
    l=0;
    DFS(1, 0, 0);
    l=0;
    DFS(a, 0, 0);
    printf("%d\n", l);
    
    return 0;
}

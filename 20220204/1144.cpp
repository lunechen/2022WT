//Articulation Vertex
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int n, t, a, b;
int visit[110];
int trace[110];
int ap[110];
vector <int> mp[110];

void ini(){
    t=1;
    for (int i=0; i<110; i++){
        visit[i]=0;
        trace[i]=0;
        ap[i]=0;
        mp[i].clear();
    }
}

void DFS(int node, int parent){
    visit[node]=t++;
    trace[node]=node;

    int child=0;
    int cp=0;

    for (int i=0; i<(int)mp[node].size(); i++){
        int tmp=mp[node][i];
        if (tmp==parent) continue;
        if (visit[tmp]){
            if (visit[tmp]<visit[trace[node]]) trace[node]=tmp;
        }
        else{
            child++;
            DFS(tmp, node);

            if (visit[trace[tmp]]<visit[trace[node]]) trace[node]=trace[tmp];
            if (visit[trace[tmp]]>=visit[node]) cp=1;
        }
    }

    if ((node==parent && child>1) || (node!=parent && cp)) ap[node]=1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n && n){
        int ans=0; 
        ini();
        cin.ignore();
        for (int i=0; i<=n; i++){
            string s;
            stringstream ss;    
            getline(cin, s);
            ss << s;
            ss >> a;
            if (a==0) break;
            while(ss >> b){
                mp[a].push_back(b);
                mp[b].push_back(a);
            }
        }

        for (int i=1; i<=n; i++){
            if (!visit[i]) DFS(i, i);
        }

        for (int i=1; i<=n; i++){
            if (ap[i]) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}

//LCA 倍增
#include <cstdio>
#include <vector>
using namespace std;

int T, n, a, b;
int deep[10100];
int fa[10100][100];
int Log[10100];
vector <int> mp[10100];

void ini(){
    Log[0]=-1;
    Log[1]=0;
    Log[2]=1;
    for (int i=3; i<10100; i++){
        Log[i]=Log[i/2]+1;
    }
}

void DFS(int child, int parent){
    deep[child]=deep[parent]+1;
    fa[child][0]=parent;
    for (int i=1; (1<<i)<=n; i++) fa[child][i]=fa[fa[child][i-1]][i-1];

    for (int i=0; i<(int)mp[child].size(); i++){
        if (mp[child][i]==parent) continue;
        DFS(mp[child][i], child);
    }
}

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int LCA(int a, int b){
    if (deep[a]<deep[b]) swap(&a, &b);
    while(deep[a]!=deep[b]) a=fa[a][Log[deep[a]-deep[b]]];

    if (a==b) return a;
    for (int i=Log[deep[a]]; i>=0; i--){
        if (fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}

int main(){
    ini();
    scanf("%d", &T);

    while(T--){
        int in[10100]={0};
        int root;
        scanf("%d", &n);
        for (int i=0; i<10100; i++){
            mp[i].clear();
        }
        for (int i=0; i<n-1; i++){
            scanf("%d %d", &a, &b);
            in[b]=1;
            mp[a].push_back(b);
        }
        for (int i=1; i<=n; i++){
            if (in[i]==0){
                root=i;
                break;
            }
        }
        DFS(root, 0);
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }

    return 0;
}

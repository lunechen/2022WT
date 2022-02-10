//Bipartite Matching Hungarian(DFS)
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector <int> mp[200];
int T, cor, stu, n, a, ans;
int visited_cor[200], matching[310], visited_stu[310];

void init(){
    memset(matching, 0, sizeof(matching));
    memset(visited_cor, 0, sizeof(visited_cor));
    for (int i=0; i<200; i++) mp[i].clear();
    ans=0;
}

int dfs(int level){
    for (int i=0; i<(int)mp[level].size(); i++){
        int tmp=mp[level][i];
        if (!visited_stu[tmp]){
            visited_stu[tmp]=1;
            if (!matching[tmp] || dfs(matching[tmp])){
                visited_cor[level]=tmp;
                matching[tmp]=level;
                return 1;
            }
        }
    }
    return 0;
}

void hungarian(){
    for (int i=1; i<=cor; i++){
        if (!visited_cor[i]){
            memset(visited_stu, 0, sizeof(visited_stu));
            ans+=dfs(i);
        }
    }
}

int main(){
    scanf("%d", &T);

    while(T--){
        init();
        scanf("%d %d", &cor, &stu);

        for (int i=1; i<=cor; i++){
            scanf("%d", &n);
            for (int j=0; j<n; j++){
                scanf("%d", &a);
                mp[i].push_back(a);
            }
        }

        hungarian();
        if (ans==cor) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
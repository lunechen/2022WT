//floyd-warshall
#include <cstdio>
using namespace std;

int mp[110][110];

void init(){
    for (int i=0; i<110; i++){
        for (int j=0; j<110; j++){
            mp[i][j]=0x7fffffff;
            if (i==j) mp[i][j]=0;
        }
    }
}

void FloydWarshall(int n){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (mp[i][j]>mp[i][k]+mp[k][j] && mp[i][k]!=0x7fffffff && mp[k][j]!=0x7fffffff){
                    mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
    }
}

void solve(int n){
    int maxi=0x7fffffff, maxn;
    for (int i=1; i<=n; i++){
        int tmp_max=0;
        for (int j=1; j<=n; j++){
            if (mp[i][j]>tmp_max) tmp_max=mp[i][j];
        }
        if (tmp_max<maxi){
            maxi=tmp_max;
            maxn=i;
        }
    }
    if (maxi==0x7fffffff) printf("disjoint\n");
    else printf("%d %d\n", maxn, maxi);
}

int main(){
    int T, n, a, v;
    while(scanf("%d", &n)!=EOF && n){
        init();

        for (int i=1; i<=n; i++){
            scanf("%d", &T);
            while(T--){
                scanf("%d %d", &a, &v);
                mp[i][a]=v;
            }
        }

        FloydWarshall(n);
        solve(n);
    }

    return 0;
}
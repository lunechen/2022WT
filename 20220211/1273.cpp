//Max Flow Edmond Karp
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
int capacity[300][300];

int EdmondKarp(int src, int des){
    int maxflow=0;

    while(1){
        int minflow=0x7fffffff;
        int tmp;
        int pre[300]={0};
        queue <int> q;

        q.push(src);
        while(!q.empty()){
            tmp=q.front();
            q.pop();

            if (tmp==des) break;

            for (int i=1; i<=n; i++){
                if (i!=src && capacity[tmp][i]>0 && pre[i]==0){
                    pre[i]=tmp;
                    minflow=min(minflow, capacity[tmp][i]);
                    q.push(i);
                }
            }
        }
        
        if (pre[des]==0) return maxflow;
        tmp=des;
        while(tmp!=src){
            int ppre=pre[tmp];
            capacity[ppre][tmp]-=minflow;
            capacity[tmp][ppre]+=minflow;
            tmp=ppre;
        }
        maxflow+=minflow;
    }
}

int main(){
    while(scanf("%d", &m)!=EOF){
        scanf("%d", &n);

        memset(capacity, 0, sizeof(capacity));
        for (int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            capacity[a][b]+=c;
        }
        printf("%d\n", EdmondKarp(1, n));
    }

    return 0;
}
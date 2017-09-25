#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;
const int DEG = 20;
struct Edge {
    int to,next;
} edge[MAXN*2];
int head[MAXN],tot;
int n,q,B;

void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int fa[MAXN][DEG];//fa[i][j]��ʾ���i�ĵ�2^j������
int deg[MAXN];//�������
void BFS(int root)
{
    queue<int>que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        for(int i = 1; i < DEG; i++)
            fa[tmp][i] = fa[fa[tmp][i-1]][i-1];
        for(int i = head[tmp]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(v == fa[tmp][0])continue;
            deg[v] = deg[tmp] + 1;
            fa[v][0] = tmp;
            que.push(v);
        }
    }
}
int LCA(int u,int v)
{
    if(deg[u] > deg[v])swap(u,v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for(int det = hv-hu, i = 0; det ; det>>=1, i++)
        if(det&1)
            tv = fa[tv][i];
    if(tu == tv)return tu;
    for(int i = DEG-1; i >= 0; i--) {
        if(fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}
bool flag[MAXN];

void make_small()
{
    for (int i=1;i<=B;i++) {

    }
}

int main()
{
    while (scanf("%d%d",&n,&q)!=EOF) {
        init();
        for (int i=1; i<=n; i++) {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        B=sqrt(n);
        BFS(1);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        make_small();
        for (int i=1;i<=q;i++) {
            int a,b,k;
            scanf("%d%d%d",&a,&b,&k);

        }
    }
    return 0;
}

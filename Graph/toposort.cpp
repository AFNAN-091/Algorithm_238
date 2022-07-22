//           * * ببسم الله الرحمن الرحيم    * *
// ********************@Author**************************************
//     ____     _____   __  _     ____     __  _
//    / __ \   | ____| |  \| |   / __ \   |  \| |
//   / /__\ \  | |__   | |\  |  / /__\ \  | |\  |
//  /_/    \_\ |_|     |_| \_| /_/    \_\ |_| \_|
 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lcm(a,b)    a*b/__gcd(a,b)
#define endl '\n'
#define FAsT ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz 50000
typedef long long ll;
int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};
/*--------------------------------------------------------------------*/

vector<int>adj[sz];
int indeg[sz];

vector<int> toposort(int n)
{
    queue<int>q;
    vector<int>res;
    for(int i=0; i<n; i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    if(q.empty()) return res;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int i=0; i<adj[u].size(); i++)
        {
            if(--indeg[adj[u][i]]==0) q.push(adj[u][i]);
        }
    }

    return res;
}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        indeg[i] = 0;
    }
}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    cin>>n>>m;
    init(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    vector<int>ans = toposort(n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    exit(0);
}
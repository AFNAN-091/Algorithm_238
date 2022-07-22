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
#define sz 500
typedef long long ll;
int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};
/*--------------------------------------------------------------------*/

vector<int>adj[sz], w[sz];
int cost[sz],par[sz];
int dijkstra(int st, int en)
{
    priority_queue< pair<int, int> , vector<pair<int , int> >, greater<pair<int, int>>>pq;
    pq.push({0,st});
    cost[st] = 0;
    par[st] = -1;

    while(!pq.empty())
    {
        int c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int node =  adj[u][i];

            if(cost[node] > w[u][i]+c)
            {
                cost[node] = w[u][i]+c;
                pq.push({cost[node],node});
                par[node] = u;
            }
        }
    }
    return cost[en];
}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        cost[i] = INT_MAX;
    }
}

int main()
{   
    FAsT  
    
    int n, m;
    cin>>n>>m;
    int x, y,z;
    init(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }

    int st, en;
    cin>>st>>en;
    st--;
    en--;
    int cost = dijkstra(st, en);

    cout<<"Shortest path from "<<st<<" to "<<en<<" is "<<cost<<endl;

    vector<int>res;
    
    while(~en)
    {
        res.push_back(en);
        en = par[en];
    }

    reverse(res.begin(), res.end());

    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" \n"[i==res.size()-1];
    }

    exit(0);
}
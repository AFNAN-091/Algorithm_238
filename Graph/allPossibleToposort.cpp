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

vector<int>adj[sz];
int indeg[sz];
bool visited[sz];
int n;
void toposort(vector<int>&res)
{
    if(res.size()==n )
    {
         for(auto it: res)
         {
            cout<<it<<" ";
         }
         cout<<endl;
    }

    for(int i=0; i<n; i++)
    {
        if(!indeg[i] and !visited[i])
        {
            for(auto it: adj[i]) indeg[it]--;

            visited[i] = true;
            res.push_back(i);

            toposort(res);

            for(auto it: adj[i]) indeg[it]++;
            visited[i] = false;
            res.pop_back();
        }
    }
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
    ll a, b, c, d, e, f, g, h, k, len, m, p, q, r, t, x, y, z;

    cin>>n>>m;
    init(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
     vector<int>res;
     toposort(res);
   
    exit(0);
}
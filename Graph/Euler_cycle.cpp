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

void removeEdge(vector<int>adj[], int u, int v)
{
    vector<int>::iterator it;
    it = find(adj[v].begin(),adj[v].end(),u);
    *it = -1;
    it = find(adj[u].begin(),adj[u].end(),v);
    *it = -1;
}

void addedge(vector<int>adj[],int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int dfscount(vector<int>adj[], int u, vector<bool>visited)
{
    visited[u] = true;
    int cnt =1;
    for(auto av: adj[u])
    {
        if(av!=-1 and !visited[av])
        {
            cnt+=dfscount(adj,av,visited);
        }
    }
    return cnt;
}

bool isvalidNextEdge(vector<int>adj[],int u, int v,int n)
{
    int count = 0;
    for (auto av : adj[u])
    {
        if (av != -1)
            count++;
    }
    if (count == 0)
        return false;
    if (count == 1)
        return true;

    vector<bool> visited(n, false);
    int count1 = dfscount(adj, u, visited);

    removeEdge(adj, u, v);
    fill(visited.begin(), visited.end(), false);

    int count2 = dfscount(adj, u, visited);

    addedge(adj, u, v);

    return (count1 > count2) ? false : true;
}


void eulerCycle(vector<int>adj[], int u, int n)
{
     vector<int>::iterator it;
    for(auto av: adj[u])
    {
        if(av!=-1 and isvalidNextEdge(adj,u,av,n))
        {
            cout<<u<<" - "<<av<<endl;
            removeEdge(adj,u,av);
            eulerCycle(adj,av,n);
        }
    }
}

void dfs(vector<int>adj[], int u, vector<bool>&visited)
{
    visited[u] = true;
    for(auto av : adj[u])
    {
        if(!visited[av])
        {
            dfs(adj,av,visited);
        }
    }
}

bool isConnected(vector<int>adj[],int n)
{
    vector<bool>visited(n,false);
    int i=0;
    for(i=0; i<n; i++)
    {
        if(adj[i].size()!=0)
        {
            break;
        }
    }
    if(i==n)
    {
        
        return true;
    }
         
    
    dfs(adj,i,visited);

    for(int i=0; i<n; i++)
    {
        if(!visited[i] and adj[i].size()>0)
        {
            
            return false;
        }
    }

    return true;

}

int isEulerian(vector<int>adj[],int n)
{
    if(isConnected(adj,n)==false)
    {
        return 0;
    }

    int odd = 0;
    for(int i=0; i<n; i++)
    {
        if(adj[i].size()&1)
        {
            odd++;
        }
    }

    if(odd>2){
        return 0;
    }
    
    return (odd==0)?2:1;
}

int main()
{   
    FAsT  
    
    int n,m;
    cin>>n>>m;
    vector<int>adj[sz];
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    int check = isEulerian(adj,n);
    if(check==0){
        cout<<"Graph is not Eulerian"<<endl;
    }
    else if(check==1)
    {
        cout<<"Graph is semi-Eulerian and has an Euler path"<<endl;

    }
    else{
        cout<<"Graph is a Eulerian and has a Euler circuit"<<endl;
    }

    int oddDegreenode = 0;
    for(int i=0; i<n; i++)
    {
        if(adj[i].size()&1)
        {
            oddDegreenode = i;
            break;
        }
    }
   eulerCycle(adj,oddDegreenode,n);
    exit(0);
}
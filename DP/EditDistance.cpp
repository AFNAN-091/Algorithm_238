//           * * Ø¨Ø¨Ø³Ù� Ø§Ù�Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù�    * *
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
 
typedef long long ll;
 
int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
const int N = 1e6+7;
 
/*--------------------------------------------------------------------*/
 
int EditDistance(string a, string b)
{
	 int temp[a.size()+1][b.size()+1];
	int mn = a.size();
	int c;
	for(int i=0; i<a.size()+1; i++)
	{
		for(int j=0; j<b.size()+1; j++)
		{
			if(i==0 and j==0)
			{
				temp[i][j] = 0;
			}
			else if(i==0)
			{
				temp[i][j] = temp[i][j-1] + 1;
			}
			else if(j==0){
				temp[i][j] = temp[i-1][j] + 1;
			}
			else{
				if(a[i-1]!=b[j-1])
				{
					c = min(temp[i][j-1], temp[i-1][j-1] );
					c = min(c, temp[i-1][j] );
					temp[i][j] = c+1;

				}
				else{
					temp[i][j] = temp[i-1][j-1];
					c = temp[i][j];
				}
				if(mn>c)
			{
				mn = c;
			}
			    
			}
            
			
		}
        
    }
    // for(int i=0; i<a.size()+1; i++)
    // {
    // 	for(int j=0; j<b.size()+1; j++)
    // 	{
    // 		cout<<temp[i][j]<<" ";
    // 	}
    // 	cout<<endl;
        
    // }
    return temp[a.size()][b.size()];
}
 
 
 
int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()>s2.size())
		{
			cout<<EditDistance(s2,s1)<<endl;

		}
		else{
			cout<<EditDistance(s1,s2)<<endl;
		}
	}
  
 
    exit(0);
} 
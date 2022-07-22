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

typedef long long ll;

int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};

const int N = 1e6+7;

/*--------------------------------------------------------------------*/

int lps[100];

void prefix_fun(string s)
{
	int index = 0;
	for(int i=1; i<s.size();)
	{
			if(s[index] == s[i])
			{
				lps[i] = index+1;
				i++; index++;
			}
		else{
			if(index!=0)
			{
			//	cout<<index<<" i "<<i<<" "<<lps[index-1]<<" ";
				index = lps[index-1];
			//	cout<<index<<endl;
			}
			else{
				lps[i]= index; i++;
			}
		}

	}
}

void match(string s, string p)
{
	int i,j;
	i = j = 0;
	bool flag = true;

	while(i<s.size())
	{

		if(s[i]==p[j])
		{
		//	cout<<i<<" "<<j<<endl;
		//	cout<<s[i]<<" "<<p[j]<<endl;
			i++;
			j++;
		//	cout<<j<<endl;
			
		}
		else
		{
				if(j!=0)
				{
					j = lps[j-1];	
				}

				else{
					i++;
				}			
		}
		
		if(j == p.size())
		{
		//	cout<<j<<endl;
			flag = false;
			cout<<"pattern is found at index "<<i-j+1<<endl;
			
		}


	}	
	//cout<<j<<endl;
	if(flag)
	{
			cout<<"pattern is not found "<<endl;
	}

}


int main()
{   
    FAsT  
  //  ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    string s,p;
    getline(cin,s);
    getline(cin,p);

    prefix_fun(p);
 //   cout<<"size "<<p.size()<<endl;

    for(int i=0; i<p.size(); i++)
    {
    	cout<<lps[i]<<" ";
    }
    cout<<endl;

    match(s,p);

    exit(0);
}
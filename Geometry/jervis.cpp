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

struct point{
	int x;
	int y;
};

int orientation(point p, point q, point r)
{
	int val = (q.x-p.x)*(r.y-p.y)- (r.x-p.x)*(q.y-p.y);
	if(val==0) return 0;
	return (val>0)?2:1; //counterclockwise or clock wise
	
}

void convexhull(point points[], int n)
{
	
	if(n<3) 
	{
		cout<<"fd";
		return;
	}
	vector<point>hull;
	
	int l = 0;
	for(int i=1; i<n; i++)
	{
		if(points[l].x>points[i].x)
		{
			l = i;
		}
	}



	int p = l , q;

	do{
		q = (p+1)%n;
		hull.push_back(points[p]);
		for(int i=0; i<n; i++)
		{
			if(orientation(points[p], points[q],points[i])==2)
			{
				q = i;
			}
		}
		p = q;
	}while(p!=l);

	
	for(int i=0; i<hull.size(); i++)
	{
		cout<<"( "<<hull[i].x<<", "<<hull[i].y<<" )"<<endl;
	}
}

int main()
{   
    FAsT  
	
	int n;
	cin>>n;

    point points[n];
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		points[i].x = a;
		points[i].y = b;
	}

   
    convexhull(points,n);    
    
    exit(0);
}
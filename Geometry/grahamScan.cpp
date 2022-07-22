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


struct point {
	int x, y;
};

point p0;


// 0--> colliner
// 1--> clockwise
// 2--> counterclockwise
int orientation(point p, point q, point r)
{
	int val = (q.x-p.x)*(r.y-p.y) - (r.x-p.x)*(q.y-p.y);

	if(val == 0)
		return 0;
	return (val>0)? 1: 2;
}

int distance(point p1, point p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int compare(const void *vp1, const void *vp2)
{
	point p1 = *(point *)vp1;
	point p2 = *(point *)vp2;

	int o = orientation(p0, p1, p2);

	if(o==0){
		return (distance(p0,p2)>= distance(p0,p1))?-1:1;
	}

	return (o==2)?-1 : 1;
 

}

point nextToTop(stack<point>&s)
{
	point p = s.top();
	s.pop();
	point res = s.top();
	s.push(p);
	return res;
}

void convexhull(point points[], int n)
{
	int ymin = points[0].y; int min = 0;
	for(int i=1; i<n; i++)
	{
		int y = points[i].y;
		if((ymin> y) or ((ymin==y) and (points[min].x>points[i].x) ) )
		{
			ymin = points[i].y;
			min = i;
		}
	}

	swap(points[0], points[min]);

	p0 = points[0];

	qsort(&points[1], n-1, sizeof(point), compare);

	int m = 1;

	for(int i=1; i<n; i++)
	{
		while(i<n-1 and orientation(p0,points[i],points[i+1])==0)
		{
			i++;
		}
		points[m] = points[i];
		m++;
	}

	if(m<3)
		return;

	stack<point>s;
	s.push(points[0]);
	s.push(points[1]);
	s.push(points[2]);
	
	for(int i=3; i<m; i++)
	{
		while(s.size()>1 and orientation(nextToTop(s), s.top(),points[i])!=2)
		{
			s.pop();
		}
		s.push(points[i]);
	}

	while(!s.empty())
	{
		point p = s.top();
		s.pop();

		cout<<"( "<<p.x<<", "<<p.y<<" )"<<endl;
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

    

    convexhull(points, n);
   

    exit(0);
}
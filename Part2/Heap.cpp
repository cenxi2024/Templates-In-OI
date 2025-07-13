#include <bits/stdc++.h>
using namespace std;
int z,n,a[11451451];
void up(int x)
{
	if(x==1) return ;
	if(a[x/2]>a[x])
	{
		swap(a[x/2],a[x]);
		up(x/2);
	}
}
void down(int x)
{
	if(x*2>n) return ;
	if(x*2==n) 
	{
		if(a[x]>a[x*2])
		{
			swap(a[x],a[x*2]);
		}
		return;
	}
	if(a[x]<a[x*2] and a[x]<a[x*2+1])
	{
		return ;
	}
	if(a[x*2]<a[x*2+1])
	{
		swap(a[x*2],a[x]);
		down(x*2);
	}
	else
	{
		swap(a[x*2+1],a[x]);
		down(x*2+1);
	}
}
void insert(int x)
{
	++n;
	a[n]=x;
	up(n);
}
void del(int x)
{
	a[x]=a[n];
	n--;
	up(x);
	down(x);
}
void pop()
{
	a[1]=a[n];
	n--;
	down(1);
}
int main()
{
	scanf("%d",&z);
	for(int i=1;i<=z;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int y;
			scanf("%d",&y);
			insert(y);
		}
		else if(x==2)
		{
			printf("%d\n",a[1]);
		}
		else
		{
			pop();
		}
	}
	return 0;
}
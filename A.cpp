#include <cstdio>
#include <iostream>
#include <cstring>
typedef long long LL;
LL a[100002],g[100002],f[100002];
int n,x;

int main()
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&x);
		a[x]+=(LL)x;
	}
	f[0] = g[0] = 0;
	f[1] = g[1] = a[1];
	for (int i = 2;i <= 100000;i++)
	{
		f[i] = g[i-2] + a[i];
		g[i] = (g[i-1]>f[i]?g[i-1]:f[i]);
	}
	std::cout<<g[100000];
	return 0;
}
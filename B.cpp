#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
const int N = 100000;
struct node
{
	char ch;
	node *c[26];
	bool win,lose;
} tree[N+5];

node *root;
char s[100002];
int l,n,k,tt;

void read()
{
	l = 0;
	char tmp;
	for (tmp = getchar();(tmp<'a')||(tmp>'z');tmp = getchar());
	s[l] = tmp;
	for (tmp = getchar();(tmp>='a')&&(tmp<='z');tmp = getchar()) s[++l] = tmp;
}

void work(node *now,int t)
{
	if (t > l) return;
	if (now->c[s[t]-'a']!=NULL) work(now->c[s[t]-'a'],t+1);
	else
	{
		node *tp = now->c[s[t]-'a'] = tree+(++tt);
		tp->ch = s[t];
		for (int i = 0;i < 26;i++) tp->c[i] = NULL;
		work(now->c[s[t]-'a'],t+1);
	}
}

void calc_win(node *nd)
{
	nd->win = 0;
	for (int i = 0;i < 26;i++)
	if (nd->c[i]!=NULL)
	{
		calc_win(nd->c[i]);
		if (nd->c[i]->win == 0) nd->win = 1;
	}
}

void calc_lose(node *nd)
{
	nd->lose = 1;
	for (int i = 0;i < 26;i++)
	if (nd->c[i]!=NULL) nd->lose = 0;
	for (int i = 0;i < 26;i++)
	if (nd->c[i]!=NULL)
	{
		calc_lose(nd->c[i]);
		if (nd->c[i]->lose == 0) nd->lose = 1;
	}
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d",&n,&k);
	root = (tree+(tt = 0));
	for (int i = 1;i <= n;i++)
	{
		read();
		work(root,0);
	}
	calc_win(root);
	calc_lose(root);
	if ((root->win==1)&&(root->lose==1)) printf("First");
	else 
	if ((root->win==0)&&(root->lose==0)) printf("Second");
	else 
	if ((root->win==0)&&(root->lose==1)) printf("Second");
	else
	if (k%2==1) printf("First"); else printf("Second");
	return 0;
}

#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int >mp[300800];
int a[3500000];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int maxn=-1000005000;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        int mx=0,mc=0;
        int ans;
        int u;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==maxn)mx++,u=i;
            if(a[i]==maxn-1)mc++;
        }
        if(mx==1)
        {
            int cont=0;
            for(int i=0;i<mp[u].size();i++)
            {
                int v=mp[u][i];
                if(a[v]==maxn-1)cont++;
            }
            if(cont==mc)ans=maxn;
            else ans=maxn+1;
            printf("%d\n",ans);
        }
        else
        {
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                int cont=0;
                if(a[i]==maxn)cont++;
                for(int j=0;j<mp[i].size();j++)
                {
                    int v=mp[i][j];
                    if(a[v]==maxn)cont++;
                }
                if(cont==mx)flag=1;
            }
            if(flag==1)printf("%d\n",maxn+1);
            else printf("%d\n",maxn+2);
        }
    }
}
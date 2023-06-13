#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll modinv(ll b, ll n)
{
    ll r1=n,r2=b,t1=0,t2=1,q,r,t;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    if(t1<0)
        t1+=n;
    return t1;
}
ll power(ll a,ll b,ll n)
{
    ll ans=1,i;
    for(i=0; i<b; i++)
    {
        ans*=a;
        ans%=n;
    }
    return ans;
}
ll primitive_root(ll p)
{
    ll i,j,x;
    bool f;
    for(i=2; i<p; i++)
    {
        map<ll,ll>mp;
        f=true;
        for(j=0; j<p-1; j++)
        {
            x=power(i,j,p);
            mp[x]++;
            if(mp[x]>1 || x<1 || x>p-1)
            {
                f=false;
                break;
            }
        }
        if(f==true && __gcd(p,i)==1)
        {
            return i;
        }
    }
}
int main()
{
    ll p=101,g,pr_key,pu_key,k,s1,s2,tmp1,tmp2,m,v1,v2;
    g=primitive_root(p);
    cout<<"Enter message :"<<endl;
    cin>>m;
    pr_key=3;
    pu_key=power(g,pr_key,p);
    for(k=2; k<=p-2; k++)
    {
        if(__gcd(k,p-1)==1)
        {
            break;
        }
    }
    s1=power(g,k,p);
    tmp1=(m-pr_key*s1)%(p-1);
    tmp2=modinv(k,p-1);
    s2=(tmp1*tmp2)%(p-1);
    cout<<s1<<" "<<s2<<endl;
    v1=power(g,m,p);
    tmp1=power(pu_key,s1,p);
    tmp2=power(s1,s2,p);
    v2=(tmp1*tmp2)%p;
    cout<<v1<<" "<<v2<<endl;
}


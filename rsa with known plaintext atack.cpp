#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modinv(ll b,ll n)
{
    ll r1=n,r2=b,t1=0,t2=1,q,t,r;
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
    {
        t1+=n;
    }
    return t1;
}
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)
    {
        return 1;
    }
    if(b==0)
    {
        return a%mod;
    }
    ll xx=bigmod(a,b/2,mod);
    if(b%2==0)
    {
        return ((xx%mod)*(xx%mod))%mod;
    }
    else
    {
        return ((((xx%mod)*(xx%mod))%mod)*(a%mod))%mod;
    }
}
int main()
{
    ll msg,n,k,p,q,m,c,tmp1,tmp2,phi,d,e;
    p=1009,q=1013;
    cin>>m;
    n=p*q;
    phi=(p-1)*(q-1);
    for(e=2; e<phi; e++)
    {
        if(__gcd(e,phi)==1)
        {
            break;
        }
    }
    d=modinv(e,phi);
    c=bigmod(m,e,n);
    cout<<c<<endl;
    cout<<d<<endl;
    k=2;
    msg=bigmod(c,d,n);
    cout<<msg<<endl;
    while(1)
    {
      tmp1=bigmod(c,k,n)%phi;
      tmp2=(e*k)%phi;
      if(tmp1==m && tmp2==1)
      {
        break;
      }
      k++;
    }
    cout<<k<<endl;
}

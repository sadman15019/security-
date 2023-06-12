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
int main()
{
   ll phi,p,q,e,d,m,n,c,mprime;
   p=10007,q=10009;
   n=p*q;
   phi=(p-1)*(q-1);
   e=2;
   while(e<phi)
   {
       if(__gcd(e,phi)==1)
       {
           break;
       }
       e++;
   }
   d=modinv(e,phi);
   cin>>m;
   c=power(m,e,n);
   mprime=power(c,d,n);
   cout<<mprime<<endl;
}

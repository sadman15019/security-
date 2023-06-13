#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,i,j,k;
    string s,key;
    vector< pair <char,ll > >v;
    cin>>s;
    cin>>key;
    for(i=0; i<key.size(); i++)
    {
        v.push_back({key[i],i});
    }
    sort(v.begin(),v.end());
    n=(s.size()/key.size())+1;
    m=key.size();
    cout<<n<<" "<<m<<endl;
    char arr[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            arr[i][j]='-';
        }
    }
    i=j=0;
    for(k=0; k<s.size(); k++)
    {
        arr[i][j]=s[k];
        j++;
        if(j==m)
        {
            i++;
            j=0;
        }
    }
    string c="";
    k=v[0].second;
    for(k=0; k<m; k++)
    {
        i=v[k].second;
        for(j=0; j<n; j++)
        {
            c+=arr[j][i];
        }
    }
    i=0;
    j=v[0].second;
    ll p=0;
    for(k=0; k<c.size(); k++)
    {
        arr[i][j]=c[k];
        i++;
        if(i==n)
        {
            i=0;
            p++;
            j=v[p].second;
        }
    }
    string msg="";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            msg+=arr[i][j];
        }
    }
    cout<<msg<<endl;
}

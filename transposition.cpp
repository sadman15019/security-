#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,i,j,k;
    string s;
    cin>>n>>m;
    cin>>s;
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
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            c+=arr[j][i];
        }
    }
    i=j=0;
    cout<<c<<endl;
    for(k=0; k<c.size(); k++)
    {
        arr[i][j]=c[k];
        i++;
        if(i==n)
        {
            i=0;
            j++;
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

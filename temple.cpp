#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,n,i,j,m,temp;
    long long int answer;
    cin>>t;
 
    while(t--)
    {
        answer=0;
        temp=0;
        cin>>n;
        int arr[n],b[n],c[n];
 
        for(i=0;i<n;i++)
        {
            if(i==0)
                   {
                    b[i]=1;
                    c[i]=0;
                   }
            else
            {
            b[i]=0;
            c[i]=0;
            }
        }
    c[n-1]=1;
 
        for(i=0;i<n;i++)
            {
                cin>>arr[i];
                 if(i>=1)
                    b[i]=((arr[i]>b[i-1])?b[i-1]+1:arr[i]);
            }
 
                //cout<<c[i]<<" ";
         for(i=n-2;i>=0;i--)
           c[i]=((arr[i]>c[i+1])?c[i+1]+1:arr[i]);
 
           for(i=0;i<n;i++)
            b[i]=((b[i]<c[i])?b[i]:c[i]);
 
            m=b[0];
             for(i=0;i<n;i++)
            cout<<b[i]<<" ";
            cout<<endl;
 
            for(i=1;i<n;i++)
                if(b[i]>m)
            {
                m=b[i];
                temp=i;
            }
 
              i=temp-1;
              j=temp+1;
              cout<<i<<" "<<j<<endl;
 
              while(i>=0)
              {
                  b[i]=b[i+1]-1;
                  i--;
              }
 
            while(j<n)
            {
                b[j]=b[j-1]-1;
                j++;
            }
            for(i=0;i<n;i++)
            cout<<b[i]<<" ";
            cout<<endl;
            for(i=0;i<n;i++)
                answer=((b[i]<0)?answer+arr[i]:answer+(arr[i]-b[i]));
 
            cout<<answer<<endl;
 
 
 
    }
}

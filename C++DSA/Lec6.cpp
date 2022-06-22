#include<iostream>
using namespace std;

int main()
{
    int i, n, sum;
    sum = 0;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    cout<<"sum:"<<sum<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int i;
    cin>>i;

    while(i > 0)
    {
        cout<< "no entered  "<<i<<endl;
        cin>>i;
    }
    cout<<" You must have entered a negative no. sir:"<<i<<endl;
    return 0;
}
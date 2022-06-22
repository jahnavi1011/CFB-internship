#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    if(a%2 == 0){
        cout<<"A is even\n";
    }
    else{
        cout<<"A is odd\n";
    }
    return 0;
}

// int main()
// {

//     int a, b, c;
//     cin >> a >> b >> c;

//     if (a > b)
//     {
//         if (a > c)
//         {
//             cout << "A is max\n";
//         }
//         else
//         {
//             cout << "C is max\n";
//         }
//     }
//     else{
//         if(b > c)
//             {
//                 cout << "B is max\n";
//             }
//             else
//             {
//                 cout << "C is max\n";
//             }
//         }
//     return 0;
// }
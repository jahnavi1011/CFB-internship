#include <iostream>
using namespace std;

int main()
{
    int i;
    cin >> i;

    do
    {
        cout << "no entered  " << i << endl;
        cin >> i;
    } while (i > 0);

    return 0;
}

//LIBRARIES
#include <bits/stdc++.h>
//MACROS
#define for(i,n) for(int i=0;i<n;i++)

using namespace std;

//Bisection
double root(double n){
    double high = 0;
    double low = n;
    double mid;
    int step = 10000;
    while(step--){
        mid = (high + low)/2;
       if (mid*mid>n){
            low = mid;
        }else high = mid;
    }
    return mid;
}

int main()
{
    cout << root(123456) << endl;
    return 0;
}

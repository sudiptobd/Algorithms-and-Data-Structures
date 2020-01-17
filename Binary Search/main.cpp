#include<bits/stdc++.h>
using namespace std;

///Binary Search
bool binarySearch(int *a, int len, int key){
    int begin = 0;
    int end = len-1;
    while(begin<=end){
        int mid = (begin+end)/2;
        if (a[mid] == key){
            return true;
        }else if(a[mid] < key){
            begin = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return false;
}

///Lower Bound
int lowerBound(int *a, int len, int key){
    int begin = 0;
    int end = len-1;
    int lowerBound = INT_MAX;
    while(begin<=end){
        int mid = (begin+end)/2;
        if (a[mid] == key){
            end = mid - 1;
        }else if(a[mid] < key){
            begin = mid + 1;
        }else {
            end = mid - 1;
        }
        lowerBound = mid;
    }
    return lowerBound;
}

///Upper Bound
int upperBound(int *a, int len, int key){
    int begin = 0;
    int end = len-1;
    int upperBound = INT_MIN;
    while(begin<=end){
        int mid = (begin+end)/2;
        if (a[mid] == key){
           begin = mid + 1;
        }else if(a[mid] < key){
            begin = mid + 1;
        }else {
            end = mid - 1;
        }
        upperBound = mid;
    }
    return upperBound;
}


int main()
{
    freopen("in.txt","r",stdin);
    int a[100];
    int n;
    char ch;
    int i = 0;

    while(cin >> n, cin >> ch){
        a[i++]=n;
    }

    ///US
    cout << binarySearch(a,i,10) << endl;
    cout << lowerBound(a,i,9) << endl;
    cout << upperBound(a,i,10) << endl;

    ///STL method(StartingAddress,EndAddress,Key)
    cout << binary_search(a,a+i,10) << endl;
    cout << lower_bound(a,a+i,9) - a << endl;
    cout << upper_bound(a,a+i,10) - a << endl;

    return 0;
}

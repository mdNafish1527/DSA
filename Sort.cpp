//merge Sort
//*-> merge sort is stable.
//*_> time complexcity O(n logn)
//space complexcity is O (n)
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& ans,vector<int>& l,vector<int>& r){
    int i = 0 , j = 0 , k = 0;
    while(i < l.size() && j < r.size()) {
        if(l[i] < r[j]){
            ans[k++] =l[i++];
        }
        else ans[k++] = r[j++];
    }

    while(i < l.size()) ans[k++] = l[i++];
    while(j < r.size()) ans[k++] = r[j++];
    return;
}

void mergeSort(vector<int>& input){
    int n = input.size();
    if(n == 1) return;

    int n1 = n / 2;
    int n2 = n - n1;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i = 0 ; i < n ; i++){
        if(i < n1) left[i] = input[i];
        else{
            right[i - n1] = input[i];
        }
    }

    mergeSort(left);
    mergeSort(right);

    merge(input,left,right);
}

int main(){
    int ar[5] = {4,-3,2,1,0};
    vector<int> input(ar,ar + 5);

    for(int i = 0 ; i < 5 ; i++) cout << input[i] << " ";
    cout << endl << endl;

    mergeSort(input);
    for(int i = 0 ; i < 5 ; i++) cout << input[i] << " ";
    return 0;
}









//bubble sort
//stable sort
//time complexcity is O(n * n)
//space complexcity is O(1)
#include <iostream>
using namespace std;

int main(){
    int ar[] = {2,-1,4,-2,1,4};
    int n = sizeof(ar) / sizeof(ar[0]);
    for(int i = 0 ; i < n ; i++) cout << ar[i] << " ";
    cout << endl << endl;

    for(int i = 0 ; i < n - 1 ; i++){
        bool flag = true;
        for(int j = 0 ; j < n - i ; j++){
            if(ar[j] > ar[j + 1]) {
                swap(ar[j],ar[j + 1]);
                flag = false;
            }
        }
        if(flag) break;
    }

    for(int i = 0 ; i < n ; i++) cout << ar[i] << " ";
    return 0;
}




//Selection sort


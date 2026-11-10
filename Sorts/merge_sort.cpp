#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

void merge_arrays(vector<int> &A, vector<int> &B, vector<int> &C) {
    size_t i = 0, k = 0, n = 0;
    while(i < A.size() and k < B.size()) {
        if (A[i] <= B[k]) {
            C[n++] = A[i++];
        } else {
            C[n++] = B[k++];
        }
    }
    while(i < A.size()) {
        C[n++] = A[i++];

    }
    while(k < B.size()) {
        C[n++] = B[k++];
    }
}

void merge_sort(vector<int> &A) {
    int N = sz(A);
    if (N <= 1) return;
    vector<int> left;
    vector<int> right;
    for(int i = 0; i < N / 2; i++) left.push_back(A[i]);
    for(int i = N / 2; i < N; i++) right.push_back(A[i]);
    merge_sort(left);
    merge_sort(right);

    merge_arrays(left, right, A);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    merge_sort(A);
    for(int i = 0; i < n; i++) cout << A[i] << ' ';

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

vector<int> input_vector() {
    vector<int> A;
    string line;
    getline(cin, line);
    stringstream line_stream(line);
    while(not line_stream.eof()) {
        int x;
        line_stream >> x;
        A.push_back(x);
    }
    return A;
}

void print_vector(vector<int> A) {
    for (auto &x: A) {
        cout << x << ' ';
    }
    cout << '\n';
}

bool is_acsending_order(const vector<int> &A) {
    int i = 0;
    while(i < int(A.size()) - 1) {
        if (A[i] > A[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}

void insert_sort(vector<int> &A) {
    int N = A.size();
    for(int pos = 1; pos < N; pos++) {
        int i = pos;
        while(i > 0 and A[i - 1] > A[i]) {
                swap(A[i], A[i - 1]);
            i -= 1;
        }
    }
}

int main()
{
    vector<int> A;
    A = input_vector();

    insert_sort(A);
    print_vector(A);

    return 0;
}





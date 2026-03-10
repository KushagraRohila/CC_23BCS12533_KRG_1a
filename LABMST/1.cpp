#include <bits/stdc++.h>
using namespace std;

bool c(vector<int>& a, vector<int>& b){
    return (a[1] - a[0]) > (b[1] - b[0]);
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> task(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin >> task[i][0] >> task[i][1];
    }

    sort(task.begin(), task.end(), c);

    int answer = 0, carry = 0;

    for(auto &i : task){
        if(carry < i[1]){
            answer += i[1] - carry;
            carry = i[1];
        }
        carry -= i[0];
    }

    cout << answer;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int turn;
    cin >> turn;
    for (int t = 0; t < turn;t++){
        // 读入数据
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        map<int,int> b;
        for (int p = 0; p < n;p++){
            cin >> a[p];
        }
        for (int q = 0,x; q < m;q++){
            cin >> x;
            b[x]++;
        }

        int ans = 0;
        for (int i=0; i < n;i++){
            ans ^= b[a[i]];
        }
        cout << ans << endl;
    }
}
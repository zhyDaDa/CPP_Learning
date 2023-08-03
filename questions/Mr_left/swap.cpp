#include <iostream>

using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int a, b;
    cout << "请输入两个数: ";
    cin >> a >> b;
    int arr[] = {a, b};
    swap(arr[0],arr[1]);
    swap(arr[0], arr[0]);
    cout << arr[0] << " " << arr[1] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void process(int level, string from, string to, string other){
    if(level ==1){
        cout << "Move 1 from " << from << " to " << to << endl;
        return;
    }
    process(level-1, from, other, to);
    printf("Move %d from %s to %s\n", level, from.c_str(), to.c_str());
    process(level-1, other, to, from);
}

void hanoi(int n){
    if(n>0){
        process(n, "left", "right", "mid");
    }
}

int main()
{
    hanoi(5);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int id;
};

int getMaxCount(vector<meeting *> meetings)
{
    sort(meetings.begin(), meetings.end(), [](meeting *a, meeting *b) {
        return a->end < b->end;
    });
    int count = 1;
    int curTime = meetings[0]->end;
    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i]->start > curTime)
        {
            count++;
            curTime = meetings[i]->end;
        }
    }
    return count;
}

int main(){
    int M;
    cin >> M;
    vector<meeting*> meetings;
    for (int i=0;i<M;i++){
        int start, end;
        cin >> start >> end;
        meeting *m = new meeting();
        m->start = start;
        m->end = end;
        m->id = i+1;
        meetings.push_back(m);
    }
    int count = getMaxCount(meetings);
    cout << count << endl;
}
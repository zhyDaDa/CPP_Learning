/*
���һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±����Ϸ����� 1 �Σ�ѹ���ۺۺ�չ����
��ʱ�ۺ��ǰ���ȥ�ģ����ۺ�ͻ��ķ���ָ��ֽ���ı��������ֽ�����±����Ϸ��������� 2 �Σ�
ѹ���ۺۺ�չ������ʱ�������ۺۣ����ϵ������������ۺۡ����ۺۺ����ۺۡ�

����һ��������� N ������ֽ�������±����Ϸ��������� N �Ρ�
����ϵ��´�ӡ�����ۺ۵ķ�������
N=I ʱ����ӡ�� down
N = 2 ʱ����ӡ�� down down up */

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void printProcess(int i, int N, bool down)
    {
        if (i > N)
        {
            return;
        }
        printProcess(i + 1, N, true);
        cout << (down ? "down" : "up") << endl;
        printProcess(i + 1, N, false);
    }

    void printAllFolds(int N)
    {
        printProcess(1, N, true);
    }
};

int main()
{
    Solution s;
    s.printAllFolds(4);
    return 0;
}
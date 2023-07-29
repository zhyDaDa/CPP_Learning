/* ��������һ���������ȵ�1 key���Ρ�����������һ����Ϸ��һ�׸����������׻������ɸ����������ǻᰴ˳�����ض�ʱ�䵽���ж��ߣ�������Ҫ�����������ж���������
 tms����t
 ms���ڵ����Ļ�������Ϳ��Ի���������������������������ȣ���������Ļ��ʱ���ж�����������㱻�������������ô���Ƕ��ᱻ����

���������ڴ�ĸ���n
 �����������ڵ�i
 ��������˵��������ai
 msʱ�̵����ж��ߡ����ڹ���������ó�ħ�������������ֱ���˴�׮������׮��������ÿ��x
 ms�ͻ��Զ������Ļһ�Ρ�

�������������������������� (�� combo ) �Ǻ���Ҫ�ġ� ������������������ȣ�һ�λ�����Ҳ���ή�� combo��������������һ������û�л�����ô���¿�ʼ�������� (�� combo ����)�����ڹ���������Ѿ������˴�׮����������������һ������ʱ�̿�ʼ���(�����ڸ�����ʼǰ)������֪�����ܻ�õ����combo�Ƕ��١� */

#include <bits/stdc++.h>
using namespace std;

int n, x, t;
long int notes[100010];
bool isHit[100010];

void printNotes()
{
    for (int i = 0; i < n; i++)
    {
        cout << notes[i] << " ";
    }
    cout << endl;
}

void printIsHit()
{
    for (int i = 0; i < n; i++)
    {
        cout << isHit[i] << " ";
    }
    cout << endl;
}

void hit(int delta)
{
    // �ж������Ӽ�t��Χ������x�ı���+delta, �����޸�notes����, ��Ӧλ��Ϊtrue
    for (int i = 0; i < n; i++)
    {
        isHit[i] = false;
        // cout << "�Ҳ����" << (notes[i] + t - delta) / x << "\t";
        // cout << "������" << (notes[i] - t - delta) / x << "\t";
        // cout << "�ȽϽ��Ϊ: " << ((notes[i] + t - delta) / x > (notes[i] - t - delta) / x) << endl;
        if ((notes[i] + t - delta) / x > (notes[i] - t - delta) / x || (notes[i] - t - delta) % x == 0 || (notes[i] + t - delta) % x == 0)
        {
            isHit[i] = true;
        }
    }
}

int calcCombo()
{
    int combo = 0;
    int maxCombo = 0;
    for (int i = 0; i < n; i++)
    {
        if (isHit[i])
        {
            combo++;
        }
        else
        {
            maxCombo = maxCombo > combo ? maxCombo : combo;
            combo = 0;
        }
    }
    return maxCombo = maxCombo > combo ? maxCombo : combo;
}

int main()
{
    cin >> n >> x >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> notes[i];
    }
    int ans = 0;
    for (int delta = -x; delta < 0; delta++)
    {
        // cout << "delta = " << delta << endl;
        hit(delta);
        printIsHit();
        int combo = calcCombo();
        ans = ans > combo ? ans : combo;
    }
    cout << ans << endl;
}
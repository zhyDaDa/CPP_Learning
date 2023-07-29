/* 她正在玩一款最新最热的1 key音游。音游是这样一种游戏：一首歌曲的音游谱会有若干个音符，它们会按顺序在特定时间到达判定线，而她需要在音符到达判定线音符的
 tms（含t
 ms）内点击屏幕，这样就可以击打音符。由于这款音游最新最热，如果点击屏幕的时候有多个音符都满足被击打的条件，那么它们都会被击打。

现在她正在打的歌有n
 个音符，对于第i
 个音符来说，它会在ai
 ms时刻到达判定线。由于谷米莱莉娅擅长魔法，她把她的手变成了打桩机，打桩机启动后每隔x
 ms就会自动点击屏幕一次。

在音游里，击打尽量多的连续的音符 (即 combo ) 是很重要的。 由于这款音游最新最热，一次击打打空也不会降低 combo数。而如果错过了一个音符没有击打，那么重新开始计算连击 (即 combo 归零)。现在谷米莱莉娅已经启动了打桩机，她可以在任意一个整数时刻开始打歌(甚至在歌曲开始前)，她想知道她能获得的最高combo是多少。 */

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
    // 判断音符加减t范围内有无x的倍数+delta, 有则修改notes数组, 对应位置为true
    for (int i = 0; i < n; i++)
    {
        isHit[i] = false;
        // cout << "右侧的商" << (notes[i] + t - delta) / x << "\t";
        // cout << "左侧的商" << (notes[i] - t - delta) / x << "\t";
        // cout << "比较结果为: " << ((notes[i] + t - delta) / x > (notes[i] - t - delta) / x) << endl;
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
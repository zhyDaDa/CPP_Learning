#include <bits/stdc++.h>
#include <time.h>
using namespace std;

class Solution
{
public:
    int daysBetweenDates(string date1, string date2)
    {
        struct tm tm1;
        time_t time1;
        // date1格式形如"YYYY-MM-DD"，需要转换为时间戳
        sscanf(date1.c_str(), "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
        tm1.tm_year -= 1900;
        tm1.tm_mon -= 1;
        tm1.tm_hour = 0;
        tm1.tm_min = 0;
        tm1.tm_sec = 0;
        tm1.tm_isdst = 0;
        time1 = mktime(&tm1);

        struct tm tm2;
        time_t time2;
        // date2格式形如"YYYY-MM-DD"，需要转换为时间戳
        sscanf(date2.c_str(), "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);
        tm2.tm_year -= 1900;
        tm2.tm_mon -= 1;
        tm2.tm_hour = 0;
        tm2.tm_min = 0;
        tm2.tm_sec = 0;
        tm2.tm_isdst = 0;
        time2 = mktime(&tm2);

        return abs(time1 - time2) / (3600 * 24);
    }
};
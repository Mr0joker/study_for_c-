#ifndef TIME_HPP
#define TIME_HPP

#include <ctime>

//把日期和时间表示为一个结构体
//参考https://www.runoob.com/cplusplus/cpp-date-time.html
/*
struct tm
{
    int tm_sec;   //秒，正常范围从0到59，但是允许至61闰秒
    int tm_min;   //分，范围从0到59
    int tm_hour;  //时，范围从0到23
    int tm_mday;  //月的第几天，范围从1到31
    int tm_mon;   //月，范围从0到11
    int tm_year;  //年，范围从1900到9999,从1900年算起的年数
    int tm_wday;  //星期，范围从0到6，0代表星期日
    int tm_yday;  //年的第几天，范围从0到365，0代表1月1日
    int tm_isdst; //夏令时，1代表夏令时，0代表不是夏令时
};
*/


//时间对象
class Time {
private:
    static time_t local_time;  //自1970年1月1日00:00:00 UTC以来的秒数    
    static tm *local_tm;   //日期和时间
    // time_t utc_time;    //UTC秒数
    // tm *utc_tm;     //UTC日期和时间
    int m_hour;
    int m_minute;
    int m_second;
public:
    Time():m_hour(0),m_minute(0),m_second(0){}
    Time(int h,int m,int s);

    void get_time();

    static void update();
    static char *get_local_Time();
    // char *get_uct_Time();
    ~Time();
};






#endif //TIME_HPP
#include "time.hpp"
#include <iostream>
using namespace std;

time_t Time::local_time = time(0);
tm *Time::local_tm = localtime(&local_time);



Time::Time(int h,int m,int s):m_hour(h),m_minute(m),m_second(s)
{
    Time::update();
}


//更新时间
void Time::update()
{
    // 获取当前时间
    local_time = time(0);
    //localtime()函数将time_t类型的时间戳转换为tm结构的本地时间。
    local_tm = localtime(&local_time); 
    // utc_time = time(0);
    // utc_tm = gmtime(&utc_time);
}
void Time::get_time()
{
    cout << "my_time:" << m_hour << ":" << m_minute << ":" << m_second << endl;
}

char *Time::get_local_Time()
{
    
    update();
    return asctime(local_tm);
}

// char *Time::get_uct_Time()
// {
//     return asctime(utc_tm);
// }

Time::~Time(){}

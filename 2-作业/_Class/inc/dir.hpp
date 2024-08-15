#ifndef __DIR_HPP__
#define __DIR_HPP__

#include <string>
#include "forwardlist.hpp"
// using namespace std;

class Dir
{
public:
    Dir(const std::string &path);
    ~Dir();

    std::string get_path() const;
    ForwardList get_bmp_list();
    bool is_bmp(const std::string &filename) const;
    void ls();
    static void ls(const std::string &path);

private:
    std::string m_path;
};

#endif // __DIR_HPP__
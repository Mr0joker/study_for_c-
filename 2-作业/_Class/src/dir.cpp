#include "dir.hpp"
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <forward_list>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

Dir::Dir(const string &path = "./") : m_path(path) {}

Dir::~Dir() {}

string Dir::get_path() const
{
	return m_path;
}





// 获取当前目录下的所有BMP文件
ForwardList Dir::get_bmp_list()
{
	DIR *dir_ptr;
	struct dirent *dirbmp;
	ForwardList bmpList;
	dir_ptr = opendir(this->m_path.c_str());
	if (dir_ptr == nullptr)
	{
		throw runtime_error("can not open " + this->m_path);
		// fprintf(stderr, "getBMP: can not open %s", this->m_path.c_str());
		return bmpList;
	}

	// 跳过.和..
	dirbmp = readdir(dir_ptr);
	cout << dirbmp->d_name << endl;
	dirbmp = readdir(dir_ptr);
	cout << dirbmp->d_name << endl;

	while (dirbmp != nullptr)
	{
		if (strstr(dirbmp->d_name, ".bmp") != nullptr)//判断是否为BMP文件 -- 方法2 is_bmp(dirbmp->d_name);
		{
			string bmp_path = this->m_path + "/" + dirbmp->d_name;
			bmpList.push_front(bmp_path);
			cout << dirbmp->d_name << endl;
		}
		dirbmp = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	return bmpList;
}

bool Dir::is_bmp(const string &filename) const
{
	int fd = open((m_path+ "/" + filename).c_str(), O_RDONLY);
	if (fd < 0)
	{
		throw runtime_error("can not open " + m_path + "/" + filename);
	}
	char header[2];
	read(fd, header, 2);
	close(fd);
	if (header[0] == 'B' && header[1] == 'M')
	{
		return true;
	}
    return false;
}

void Dir::ls()
{
	DIR *dir_ptr;
	struct dirent *direntp;

	dir_ptr = opendir(this->m_path.c_str());
	if (dir_ptr == NULL)
	{
		// fprintf(stderr, "Ls: can not open %s", this->m_path.c_str());
		throw runtime_error("can not open " + this->m_path);
	}
	else
	{
		direntp = readdir(dir_ptr);
		while (direntp == nullptr)
		{
			printf("%s\n", direntp->d_name);
		}
		closedir(dir_ptr);
	}
	cout << m_path << endl;
}

void Dir::ls(const string &path)
{
	DIR *dir_ptr;
	struct dirent *direntp;

	dir_ptr = opendir(path.c_str());
	if (dir_ptr == NULL)
	{
		// fprintf(stderr, "Ls: can not open %s", path.c_str());
		throw runtime_error("can not open " + path);
	}
	else
	{
		direntp = readdir(dir_ptr);
		while (direntp == nullptr)
		{
			printf("%s\n", direntp->d_name);
		}
		closedir(dir_ptr);
	}
	cout << path << endl;
}

#include "split.h"

vector<string> split(const  string& s, const string& delim)
{//用来将表项分割开，得到用户名，密码，分数……
	vector<std::string> elems;
	size_t pos = 0;
	size_t len = s.length();
	size_t delim_len = delim.length();
	if (delim_len == 0) return elems;
	while (pos < len)
	{
		int find_pos = s.find(delim, pos);
		if (find_pos < 0)
		{
			elems.push_back(s.substr(pos, len - pos));
			break;
		}
		elems.push_back(s.substr(pos, find_pos - pos));//delim之前从pos开始的字符串放进容器
		pos = find_pos + delim_len;
	}
	return elems;
}
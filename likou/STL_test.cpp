#include <iostream>
#include <string>
#include <map>//map and multimap




void map_test()
{
	//create a map
	std::map<int , std::string> mymap;//id and name

	//insert a item
	// @1
	mymap.insert(std::make_pair(5, "wangwu"));
	mymap.insert(std::make_pair(4, "lisi"));
	//@2键值有就覆盖，没有就插入
	mymap[3] = "zhangsan";
	mymap[6] = "lidamazi";
	//@3
	mymap.insert(std::pair<int, std::string>(1, "one"));

	//默认情况下map按键值从小到大排序的，map键值不能重复
	mymap.insert(std::pair<int, std::string>(1, "lili"));//如果key已经有了则不能在插入
	std::cout << "insert failure:" << mymap[1];
	mymap[1] = "lili";//这里是修改，键值1有就修改，没有就插入
	std::cout << "modify the value:" << mymap[1];


	//iterator 遍历
	std::map<int, std::string>::iterator it;//usage like pointer
	for (it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;

	//按键值访问
	std::string name = mymap[3];
	std::cout << name;

	//访问没有的关键字不报错,本质是用[]是没有关键字就进行了插入操作
	name = mymap[9];
	std::cout << name;

	//判断是否存在关键字
	it = mymap.find(9);
	if (it != mymap.end())
		std::cout << "find the key:"<<it->second<<"\n";
	else
		std::cout << "cant find the key\n";

	//反向迭代器
	std::map<int, std::string>::reverse_iterator rit;
	for(rit = mymap.rbegin(); rit!=mymap.rend();rit++)
		std::cout << rit->first << ":" << rit->second << std::endl;

	//删除
	//iterator erase
	it = mymap.find(4);
	if (it != mymap.end())
	{
		mymap.erase(it);
	}
	//key erase
	mymap.erase(2);
	std::cout << "erase:4,2\n";
	for (it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;

	//size
	size_t size = mymap.size();
}




int main_STL_test()
//int main()
{
	map_test();
	return 0;
}
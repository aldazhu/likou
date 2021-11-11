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
	//@2��ֵ�о͸��ǣ�û�оͲ���
	mymap[3] = "zhangsan";
	mymap[6] = "lidamazi";
	//@3
	mymap.insert(std::pair<int, std::string>(1, "one"));

	//Ĭ�������map����ֵ��С��������ģ�map��ֵ�����ظ�
	mymap.insert(std::pair<int, std::string>(1, "lili"));//���key�Ѿ����������ڲ���
	std::cout << "insert failure:" << mymap[1];
	mymap[1] = "lili";//�������޸ģ���ֵ1�о��޸ģ�û�оͲ���
	std::cout << "modify the value:" << mymap[1];


	//iterator ����
	std::map<int, std::string>::iterator it;//usage like pointer
	for (it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;

	//����ֵ����
	std::string name = mymap[3];
	std::cout << name;

	//����û�еĹؼ��ֲ�����,��������[]��û�йؼ��־ͽ����˲������
	name = mymap[9];
	std::cout << name;

	//�ж��Ƿ���ڹؼ���
	it = mymap.find(9);
	if (it != mymap.end())
		std::cout << "find the key:"<<it->second<<"\n";
	else
		std::cout << "cant find the key\n";

	//���������
	std::map<int, std::string>::reverse_iterator rit;
	for(rit = mymap.rbegin(); rit!=mymap.rend();rit++)
		std::cout << rit->first << ":" << rit->second << std::endl;

	//ɾ��
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
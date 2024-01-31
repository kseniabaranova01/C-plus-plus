#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void seminar()
{
	/*Task 1*/
	int countA = 0;
	int counta = 0;
	std::string str;
	std::getline(std::cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			++counta;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			++countA;
		}
	}

	std::cout << countA << " " << counta;
	std::cout << std::endl;


	/*Task 2*/

	std::string k;
	std::string line;
	int count = 0;
	std::getline(std::cin, line);
	std::istringstream str2(line);
	while (getline(str2, k, ' '))
	{
		std::cout << k << std::endl;
		++count;
	}
	std::cout << count;
	std::cout << std::endl;


	/* Task 3*/
	//std::vector<std::string> words;
	std::string s;
	std::getline(std::cin, s);
	int ls = s.size();
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		int lw = rand() % (7 - 2 + 1) + 2;
		std::string w;
		while (j < lw)
		{
			int let = rand() % ls;
			if (s[let] != ' ')
			{
				w += s[let];
				++j;
			}
		}
		j = 0;
		//words.push_back(w);
		std::cout << w << std::endl;

	}

	//for (auto w : words)
	//{
	//	std::cout << w << std::endl;
	//}
	//


}

void homeworktask4()
{
	std::string str;
	std::getline(std::cin, str);
	int stringsize = str.size();
	
	std::string stringsecond;
	int i = 0;
	int j = 0;
	bool add = true;
	int length = 0;
	for (i = 0; i < stringsize; i++)
	{
		if (str[i] != ' ')  
		{
			add = true;
		}else {
			add = false;
		}
		
		for (j = 0; j < length; j++)
		{
			if (str[i] == stringsecond[j])
			{
				add = false;
			}
		}

		if (add)
		{
			stringsecond += str[i];
			++length;
		}

	}
	std::cout << stringsecond << std::endl;
	
}

void homeworktask5()
{
	const int number = 3;
	int i = 0;
	std::string strings[number];
	for (i = 0; i < number; i++)
	{
		std::getline(std::cin, strings[i]);
	}
	int maxLength = strings[0].length();
	for (i = 1; i < number; i++)
	{
		
		if (maxLength < strings[i].length())
		{
			maxLength = strings[i].length();
		
		}
	}
	for (int i = 0; i < number; i++)
	{
		if (strings[i].length() == maxLength)
		{
			std::cout << i+1 << " ";
		}
	}
	std::cout << std::endl;

}


void homeworktask6()
{
	std::string str;
	std::getline(std::cin, str);
	int stringsize = str.size();
	int i = 0;
	std::string str2;
	bool palindrom = true;
	for (i = 0; i < stringsize; i++)
	{
		if (str[i] != ' ')
		{
			str2 += str[i];
		} 
	} 
	int size2 = str2.size();
	int secondsize2 = size2 / 2;
	for (i = 0; i < secondsize2; i++)
	{
		if (str2[i] == str2[size2 - i - 1])
		{
			palindrom = true;
		}
		else {
			palindrom = false;
			break;
		}

	}
	if (palindrom)
	{
		std::cout << "Palindrom";
	}
	else {
		std::cout << "ne palindrom"<<str2;
	}
}


void homeworktask7()
{
	std::string str;
	std::getline(std::cin, str);
	int stringsize = str.size();    
	std::string podstr;
	std::getline(std::cin, podstr);
	int stringsize2 = podstr.size();
	std::string zamstr;
	std::getline(std::cin, zamstr);
	int stringsize3 = zamstr.size();
	int i = 0;
	int j = 0;
	int index = 0;
	int count = 0;
	bool zam = false;
	for (i = 0; i < stringsize; i++)
	{
		if (str[i] == podstr[0])
		{
			for (j = 0; j < stringsize2; j++)
			{
				if (str[i+j] == podstr[j])
				{
					++count;
				}
				else
				{
					count = 0;
					zam = false;
					break;
				}
				if (count == stringsize2)
				{
					zam = true;
					break;
				}
			}
		}
		if (zam)
		{
			index = i;
			break;
		}
		
	}
	if (zam) {
		str.replace(index, stringsize2, zamstr);
		std::cout << str;
	}
	else {
		std::cout << "false";
	}

}

void homeworktask8()
{
	std::string distinguished;
	std::string line;
	std::string newword;
	int Maxsize = 0;
	std::getline(std::cin, line);
	std::istringstream str2(line);
	while (getline(str2, distinguished, ' '))
	{
		//std::cout << distinguished << distinguished.size()<< std::endl;
		if (distinguished.size() > Maxsize)
		{
			Maxsize = distinguished.size();
			newword = distinguished;
		}

	}
	
	std::cout << newword<<std::endl;


}


int main()
{
	
	//seminar();
	//homeworktask4();
	//homeworktask5();
	//homeworktask6();
	//homeworktask7();
	homeworktask8();

}
#include <bits/stdc++.h>


using namespace std;

class process{
	
public:
	string WHITESPACE = " \n\r\t\f\v"; 
	string ltrim(string &s);
	string rtrim(string &s);
	string trim(string &s);
	bool is_number(const std::string& s);
	bool is_space(const std::string& s);
	bool valid_operant(string &s,int n);
	
	template<class T>
	void printStruc(T &v);
};

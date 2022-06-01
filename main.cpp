#include <bits/stdc++.h>
#include <fstream>
#include "process.h"
using namespace std;

 
string process::ltrim(string &s){
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string process::rtrim(string &s){
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
 
string process::trim(string &s) {
	s = ltrim(s);
    return rtrim(s);
}
bool process::is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
bool process::is_space(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && !std::isspace(*it)){ ++it;}
    return !(!s.empty() && it == s.end());
}
bool process::valid_operant(string &s,int n){
	if(is_number(s) && n>1){
			return true;
	}else{
		//SW  x1, 4(x0) have to work on this one
			if(!isdigit(s[0]) && !is_space(s)){
					return true;
			}
	}
	return false;
}

template <class T>
void process::printStruc(T &v){
	for(auto x: v){
		cout<<"operator: "<<x.first<<endl;
		cout<<"operants: "<<x.second.size()<<endl;
		for(auto y:x.second){
				cout<<y<<endl;
		}
	}
}
int main(){
	vector<pair<string,vector<string>> >answer;
	map<string,int> m;
	process p;
	ifstream infile("opcode_list");
	if(!infile){
		cout<<"file can not be opened!"<<endl;
		}else{
			while(!infile.eof()){
				string opcode = "";
				int n;
				infile>>opcode>>n;
				if( opcode != ""){
					m[opcode] = n;
				}
			}
			infile.close();
	}
	
	
	string s = "";
	while(getline(cin,s) ){
		stringstream check1(s);
		string intermediate;
		while(getline(check1, intermediate, '#')){
			s = intermediate;
			break;
		}
		if(s == "" || s== p.WHITESPACE){
				continue;
		}
		string op= "";
		stringstream check2(s);
		while(getline(check2, intermediate, ' ')){
			op = intermediate;
			break;
		}
		if(!m.count(op) ){
			continue;
		}
		
		
		s = s.substr(op.length());
		
				
		vector <string> tt;
		stringstream check3(s);
		int count = 1;
		while(getline(check3, intermediate, ',')){
			string var = p.trim(intermediate);
			if(var.length() != 0 && p.valid_operant(var,count)){
				count++;
				tt.push_back(var);
			}
			
		}
		
		
		if(m[op] == int(tt.size())){
			 vector<string> v;
			for(auto x: tt){
				v.push_back(x);
			}
			answer.push_back(make_pair(op,v));
		}
		
	}
	p.printStruc(answer);
	
	return 0;
}





/*
 * =====================================================================================
 *
 *       Filename:  splitstr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2012 20:15:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void StringSplit(string str, string separator, vector<string>* results){
	int found;
	found = str.find_first_of(separator);
	while(found != string::npos){
		if(found > 0){
			results->push_back(str.substr(0,found));
		}
		str = str.substr(found+1);
		found = str.find_first_of(separator);
	}
	if(str.length() > 0){
		results->push_back(str);
	}
}

int main()
{
	string a="wahaha   ha wwf";
	vector<string> vs;
	StringSplit(a," ", &vs);
	for (unsigned int i=0; i<vs.size();++i)
	{
		cout<<vs[i];
		cout<<" ";
		cout<<i;
		cout<<" ";
	}
	return 0;
}


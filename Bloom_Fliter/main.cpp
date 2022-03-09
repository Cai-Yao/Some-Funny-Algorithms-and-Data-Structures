#include "BloomFliter.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::string;
using std::ostringstream;

#define TEST_LEN1 100000
#define TEST_LEN2 200000

int main()
{
    
	ostringstream oss;
	//insert 10w
	BloomFilter bf;
	for(size_t i = 0; i < TEST_LEN1; i++)
	{
		oss.str("");
		oss << i;		
		bf.insert(oss.str());
	}

	//test false negitive
	size_t cnt = 0;
	for(size_t i = 0; i < TEST_LEN1; i++)
	{
		oss.str("");
		oss << i;
		if(!bf.contains(oss.str()))
		{
			cnt++;
		}
	}
	cout<<"False Negitive "<<cnt<<" ."<<endl;

	//test false positive
	cnt = 0;
	for(size_t i = TEST_LEN1; i < TEST_LEN2; i++)
	{
		oss.str("");
		oss << i;
		if(bf.contains(oss.str()))
		{
			cnt++;
		}
	}
	cout<<"False Positive "<<cnt<<" ."<<endl;
}
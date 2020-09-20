#include <iostream>
#include <vector>
using namespace std;

void permutation(std::vector<char>& rInut, std::vector<char>& output, std::vector<int>& count, int  iLevel)
{
	if(iLevel == rInut.size())
	{
		for(int i=0; i< rInut.size(); i++)
		{
			cout<<" "<< output.at(i) <<" ";
		}
		cout<<endl;
		return;
	}
	else{
		
		for(int i=0; i< rInut.size(); i++)
		{
			if(count[i] == 0)
			{
				continue;
			}
			else{
				output.insert(output.begin()+iLevel, rInut[i]);
				count[i]--;
				permutation(rInut, output, count, iLevel+1);
				count[i]++;
			}
		}
	}
}

int main()
{
	std::vector<char> vInput ={'A', 'B','C'};
	std::vector<char> vOut;
	std::vector<int> vCount ={1,1,1};
	permutation(vInput, vOut, vCount, 0);
	return 0;
}

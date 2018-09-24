#include "Program1.h"

using namespace std;

vector<vector<Card>> create_subarrays(vector<Card> items, vector<Card> current, vector<vector<Card>> subarrays, int pos, int size)
{
	if (size == items.size()) return subarrays;
	else 
	{
		if (pos < size)
		{
			vector<Card> temp = current;
			temp.push_back(items[pos]);
			subarrays.push_back(temp);
			return create_subarrays(items, current, subarrays, pos + 1, size);
			return create_subarrays(items, temp, subarrays, pos + 1, size + 1);
		}
	}
}

int main(int argc, char** argv)
{
	/*
	vector<vector<Card>> subarray;
	vector<Card> items, current;
	Card c1("a", 1, 1);
	Card c2("b", 2, 2);
	Card c3("c", 3, 3);

	subarray = create_subarrays(items, current, subarray, 1, 0);
	for (int i = 0; i < subarray.size(); i++)
	{
		for (int j = 0; j < subarray[i].size(); j++)
		{
			cout << subarray[i][j].name << endl;
		}
	}
	*/

	return 0;
}

#include "Program1.h"

using namespace std; 

Card::Card(string n, int m, int c)
{
	name = n;
	mPrice = m;
	cost = c;
}

void get_combinations(vector<Card> items, vector<vector<Card>>& combinations, vector<Card> current, int pos)
{
	if (pos < items.size())
	{
		get_combinations(items, combinations, current, pos + 1);
		current.push_back(items[pos]);
		combinations.push_back(current);
		get_combinations(items, combinations, current, pos + 1);
	}
	else
	{
		return;
	}
}

int sum_of_weights(vector<Card> items)
{
	int ret = 0;
	for (int i = 0; i < items.size(); i++)
	{
		ret += items[i].cost;
	}
	return ret;
}

int profit(vector<Card> items)
{
	int ret = 0;
	for (int i = 0; i < items.size(); i++)
	{
		ret += (items[i].mPrice - items[i].cost);
	}
	return ret;
}
vector<Card> computeMaxProfit(vector<Card> items, int money)
{
	int max_profit = 0;
	vector<Card> current_set, max_set, temp;
	vector<vector<Card>> all_sets;
	get_combinations(items, all_sets, temp, 0);
	if (sum_of_weights(items) <= money)
	{
		return items;
	}
	for (int i = 0; i < all_sets.size(); i++)
	{
		if (sum_of_weights(all_sets[i]) <= money)
		{
			if (profit(all_sets[i]) > max_profit)
			{
				max_profit = profit(all_sets[i]);
				max_set = all_sets[i];
			}
		}
	}
	return max_set;
}

int main (int argc, char** argv)
{
	clock_t start = clock();
	cout << start << endl;
	double duration;
	ifstream inputfile;
	inputfile.open(argv[2]);
	int num_market_cards, market_price, num_gertrude_cards, gertrude_price, money;
	string market_card_name, gertrude_card_name;
	vector<Card> market_cards, gertrude_cards, cards;
	inputfile >> num_market_cards;
	ofstream outfile("output.txt", ofstream::out);
	for (int i = 0; i < num_market_cards; i++)
	{
		inputfile >> market_card_name >> market_price;
		market_cards.push_back(Card(market_card_name, market_price, -1));
	}
	inputfile.close();
	inputfile.open(argv[4]);
	while (inputfile >> num_gertrude_cards >> money)
	{
		for (int i = 0; i < num_gertrude_cards; i++)
		{
			bool found = false;
			inputfile >> gertrude_card_name >> gertrude_price;
			for (int j = 0; j < num_market_cards; j++)
			{
				if (gertrude_card_name == market_cards[j].name)
				{
					gertrude_cards.push_back(Card(market_cards[j].name, market_cards[j].mPrice, gertrude_price));
					found = true;
				}
			}
			if (found == false)
			{
				cout << "Card not found. Exiting program" << endl;
				break;
			}
		}
		if (gertrude_cards.size() < num_gertrude_cards) break;
		duration = (clock() - start)/(double) (CLOCKS_PER_SEC/1000);
		outfile << num_gertrude_cards << "\n" << profit(computeMaxProfit(gertrude_cards, money)) << "\n"
		<< computeMaxProfit(gertrude_cards, money).size() << "\n" << duration << "\n\n";
		gertrude_cards.clear();
	}

	inputfile.close();
	outfile.close();
	return 0;
}
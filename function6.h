#pragma once
#ifndef FUNCTION_6_H
#define FUNCTION_6_H
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;

void print(vector<string> key)
{
};
bool dominating(vector<pair<string, vector<int>>> coverage_chart, int i, int j)
{
	for (const auto& pair : coverage_chart)
	{
		vector<int> row = pair.second;
		if ((row[i] == 0 && row[j] == 1))
		{
			return false;
		}
	}
	return true;
};
bool dominated(vector<pair<string, vector<int>>> coverage_chart, vector<int> r1, vector<int> r2)
{
	for (int i = 0; i < r1.size(); i++)
	{
		if ((r1[i] == 1 && r2[i] == 0))
		{
			return false;
		}
	}
	return true;
};
vector<pair<string, vector<int>>> removingDominating(vector<pair<string, vector<int>>> coverage_chart)
{
	for (int i = 0; i < coverage_chart.begin()->second.size();)
	{
		bool flag = false;
		for (int j = 0; j < coverage_chart.begin()->second.size();)
		{
			if (i != j)
			{
				if (dominating(coverage_chart, i, j))
				{
					for (auto& pair : coverage_chart)
						pair.second.erase(pair.second.begin() + i);
					flag = true;
					break;
				}
				if (dominating(coverage_chart, j, i))
				{
					for (auto& pair : coverage_chart)
						pair.second.erase(pair.second.begin() + j);
					flag = true;
					break;
				}

			}
			j++;
		}
		if (!flag)
			i++;
	}

	return coverage_chart;
};
vector<pair<string, vector<int>>> removingDominated(vector<pair<string, vector<int>>> coverage_chart)
{
	for (int i = 0; i < coverage_chart.size();)
	{
		vector<int> row1 = coverage_chart[i].second;
		bool flag = false;
		for (int j = 0; j < coverage_chart.size();)
		{
			vector<int> row2 = coverage_chart[j].second;
			if (i != j)
			{
				if (dominated(coverage_chart, row1, row2))
				{
					coverage_chart.erase(coverage_chart.begin() + i);
					flag = true;
					break;
				}
				if (dominated(coverage_chart, row2, row1))
				{
					coverage_chart.erase(coverage_chart.begin() + j);
					flag = true;
					break;
				}

			}
			j++;
		}
		if (!flag)
			i++;
	}

	return coverage_chart;
};

bool singleOne(vector<string>& keys, vector<pair<string, vector<int>>> coverage_chart)
{
	keys.clear();

	for (int i = 0; i < coverage_chart.begin()->second.size(); i++) // looping over cols to check those only one 1
	{
		string key;
		int count = 0;
		for (const auto& pair : coverage_chart)
		{
			const vector<int>& cols = pair.second;

			if (cols[i] == 1)
			{
				count++;
				key = pair.first;
			}

		}

		if (count == 1) // checking single 1's in cols for erasing
		{
			keys.push_back(key);
		}

	}

	return keys.size();


};
vector<pair<string, vector<int>>> removeSingles(vector<string>& keys, vector<pair<string, vector<int>>> coverage_chart)
{
	for (int i = 0; i < coverage_chart.begin()->second.size(); i++) // looping over cols
	{
		bool flag = false;
		for (auto& pair : coverage_chart)
		{
			string k = pair.first;
			vector<int> cols = pair.second;
			if (cols[i] == 1 && find(keys.begin(), keys.end(), k) != keys.end())
				flag = true;

		}
		if (flag)
		{
			for (auto& pair : coverage_chart)
			{
				pair.second.erase(pair.second.begin() + i); //erasing 
			}
			i--;
		}



	}
	for (int i = 0; i < keys.size(); i++)
	{
		int j = 0;
		while (j < coverage_chart.size())
		{
			if (keys[i] == coverage_chart[j].first)
			{
				coverage_chart.erase(coverage_chart.begin() + j);
				break;
			}
			else
				j++;

		}
	}


	return coverage_chart;
};
void print(vector<string> PIs, string variables)
{
	//printing EPIS
	cout << "\n\n\n~~~~~~~~~~~~~~~OUTPUT~~~~~~~~~~~~~~~\n\n";
	for (int i = 0; i < PIs.size(); i++)
	{
		for (int j = 0; j < PIs[i].length(); j++)
		{
			if (PIs[i][j] == '1')
				cout << variables[j];
			else if (PIs[i][j] == '0')
				cout << variables[j] << '\'';

		}
		if (i != PIs.size() - 1)
			cout << '+';
	}
	cout << endl;
}
string f6(vector<pair<string, vector<int>>> coverage_chart)
{
	vector<string> PIs_to_take;
	int count = 0;
	vector<int> index; // index of single ones 
	vector<string> keys; // stores the keys of columns which have one numbers of 1's
	string key;

	// function taken from sarah

	// add conditions ( if cov is empty? ) 

	// if not , check dom rows&cols 
	if (!coverage_chart.empty())
	{
		bool single = true;
		while (single && !coverage_chart.empty())
		{
			coverage_chart = removingDominating(coverage_chart);
			coverage_chart = removingDominated(coverage_chart);
			if (singleOne(keys, coverage_chart) && !coverage_chart.empty())
				coverage_chart = removeSingles(keys, coverage_chart);
			else
				single = false;
			for (int i = 0; i < keys.size(); i++)
				PIs_to_take.push_back(keys[i]);
		}

	}
	else // if it only contains the EPIS
	{
		for (const auto& pair : coverage_chart) {
			cout << pair.first << ": ";
			for (int value : pair.second) {
				cout << value << " ";
			}
			cout << endl;
		}
	}
	cout << " \n----------------------------------------------------\nLast \n";
	for (const auto& pair : coverage_chart) {
		cout << pair.first << ": ";
		for (int value : pair.second) {
			cout << value << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < PIs_to_take.size(); i++)
	{
		cout << PIs_to_take[i] << "\n";
	}

	string variables = "abcde";
	print(PIs_to_take, variables);


	return "hi";
};



#endif
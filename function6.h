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
#include "function_8.h"
#include "function_7.h"

using namespace std;

bool dominating(vector<pair<string, vector<int>>> coverage_chart, int i, int j) // check for dominating cols
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
bool dominated(vector<pair<string, vector<int>>> coverage_chart, vector<int> r1, vector<int> r2) //check for dominated rows
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
vector<pair<string, vector<int>>> removingDominating(vector<pair<string, vector<int>>> coverage_chart) // remove dominating cols
{
	for (int i = 0; i < coverage_chart.begin()->second.size();)
	{
		bool flag = false;
		for (int j = 0; j < coverage_chart.begin()->second.size();)
		{
			if (i != j)											//don't compare if they are the same position
			{
				if (dominating(coverage_chart, i, j))
				{
					for (auto& pair : coverage_chart)
						pair.second.erase(pair.second.begin() + i);
					flag = true;
					break;
				}
				if (dominating(coverage_chart, j, i))			//checking backwards
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
			i++;										//increment when we don't erase only
	}

	return coverage_chart;
};
vector<pair<string, vector<int>>> removingDominated(vector<pair<string, vector<int>>> coverage_chart) //remove dominated rows
{
	for (int i = 0; i < coverage_chart.size();)
	{
		vector<int> row1 = coverage_chart[i].second;
		bool flag = false;
		for (int j = 0; j < coverage_chart.size();)
		{
			vector<int> row2 = coverage_chart[j].second;
			if (i != j)										//don't compare if they are the same position
			{
				if (dominated(coverage_chart, row1, row2))
				{
					coverage_chart.erase(coverage_chart.begin() + i);
					flag = true;
					break;
				}
				if (dominated(coverage_chart, row2, row1))   //checking backwards
				{
					coverage_chart.erase(coverage_chart.begin() + j);
					flag = true;
					break;
				}

			}
			j++;
		}
		if (!flag)
			i++;							//increment when we don't erase only
	}

	return coverage_chart;
};

bool singleOne(vector<string>& keys, vector<pair<string, vector<int>>> coverage_chart) //returns true if the column contains a single 1 and store into keys vector
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
vector<pair<string, vector<int>>> removeSingles(vector<string>& keys, vector<pair<string, vector<int>>> coverage_chart) // remove columns with single ones as well as the intersecting columns
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
	for (int i = 0; i < keys.size(); i++) //erases the column with the single one
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
string print(vector<string> PIs, string variables) //transform PIs and EPIs to use in other functions
{
	//printing EPIS
	string temp("");
	cout << "\n\n\n~~~~~~~~~~~~~~~MINIMIZED EXPRESSION~~~~~~~~~~~~~~~\n\n";
	for (int i = 0; i < PIs.size(); i++)
	{
		for (int j = 0; j < PIs[i].length(); j++)
		{
			if (PIs[i][j] == '1')
			{
				cout << variables[j];
				temp += variables[j];
			}
			else if (PIs[i][j] == '0')
			{
				cout << variables[j] << '\'';
				temp += variables[j];
				temp += "\'";
			}

		}
		if (i != PIs.size() - 1)
		{
			cout << '+';
			temp += '+';
		}
	}
	cout << endl;
	return temp;
}
void QM_gen(vector<pair<string, vector<int>>> coverage_chart, vector<string> EPIs, string variables )
{
	vector<string> PIs_to_take;
	int count = 0;
	vector<string> keys; // stores the keys of columns which have one numbers of 1's
	string key;

	if (!coverage_chart.empty()) // add conditions ( if cov is empty? ) , if not , check dom rows&cols 
	{
		bool single = true;
		while (single && !coverage_chart.empty())
		{
			coverage_chart = removingDominating(coverage_chart);
			coverage_chart = removingDominated(coverage_chart);
			if (singleOne(keys, coverage_chart) && !coverage_chart.empty()) //remove cols with single ones
				coverage_chart = removeSingles(keys, coverage_chart);
			else
				single = false;
			for (int i = 0; i < keys.size(); i++)
				PIs_to_take.push_back(keys[i]); //PIs who have single ones in cols
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
	
	for (int k = 0; k < EPIs.size(); k++) //combining EPIS and PIS needed into one vector
	{
		
		PIs_to_take.push_back(EPIs[k]);
	}
	
	vector <string> FormattedPIs;
	for (int i = 0; i < PIs_to_take.size(); i++)
	{
		string temp("");
		for (int k = 0; k < PIs_to_take[i].length(); k++) 
		{

			if (PIs_to_take[i][k] == '1')
			{
				temp += variables[k];
			}
			else if (PIs_to_take[i][k] == '0')
			{
				temp += variables[k];
				temp += "\'";
			}
			
			
		}
		FormattedPIs.push_back(temp);
	}

	
	Kmap_gen(FormattedPIs, variables); //send after altered to merge with functions
	Circuit_gen(print(PIs_to_take, variables));	//send after altered to merge with functions


};



#endif
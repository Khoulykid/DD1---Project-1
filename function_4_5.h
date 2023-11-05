#pragma once
#ifndef FUNCTION_4_5
#define FUNCTION_4_5

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>
#include "function6.h"


using namespace std;

void print(vector<string> EPIs, vector<int> notcoveredmins, string variables)
{
    //printing EPIS
 
   
    cout << "\n\n\n~~~~~~~~~~~~~~~EPIS~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < EPIs.size(); i++)
    {
        
        for (int j = 0; j < EPIs[i].length(); j++)
        {
            if (EPIs[i][j] == '1')
            {
                cout << variables[j];
                
            }
            else if (EPIs[i][j] == '0')
            {
                cout << variables[j] << '\'';
               
            }

        }
        if (i != EPIs.size() - 1)
        {
            
            cout << '+';
            
        }

    
        
    }
    cout << endl;
    cout << "\n\n\n~~~~~~~~~MINTERMS NOT COVERED BY EPIS~~~~~~~~~\n\n";
    if (notcoveredmins.size() == 0)
        cout << "\tAll minterms are covered by EPIS \n\n";
    else
        for (int i = 0; i < notcoveredmins.size(); i++)
        {
            cout << "m" << notcoveredmins[i] << endl;
        }
   
}

void function_4_5(map<char, vector<int> > table, vector<string> PIs, vector< vector<int> > minterms, set<char> vars)
{
    string variables ("");
    int i(0);

    for (auto it = vars.begin(); it != vars.end(); it++)
    {
        variables += *it;
    }

    int n = table['X'].size();

    map <int, int> mintermfreq;
    map < int, vector<string> > mintermPIs;
    vector<string> EPIs;
    vector<int> notcoveredmins;


    for (int i = 0; i < n; i++)
        if (table['X'][i])
        {
            mintermfreq[i] = 0;
        }
    for (int i = 0; i < minterms.size(); i++)
        for (int j = 0; j < minterms[i].size(); j++)
        {
            mintermfreq[minterms[i][j]]++;
            mintermPIs[minterms[i][j]].push_back(PIs[i]);
        }


    for (auto it = mintermfreq.rbegin(); it != mintermfreq.rend(); ++it)
    {
        if (it->second == 1)
        {
            auto ier = find(EPIs.begin(), EPIs.end(), mintermPIs[it->first][0]);
            if (ier == EPIs.end())
                EPIs.push_back(mintermPIs[it->first][0]);
        }
    }
    for (auto it = mintermfreq.begin(); it != mintermfreq.end(); ++it)
    {
        int count(0);
        if (it->second != 1)
        {
            for (int i = 0; i < mintermPIs[it->first].size(); i++)
            {
                for (int j = 0; j < EPIs.size(); j++)
                {
                    if (mintermPIs[it->first][i] == EPIs[j])
                        count++;
                }
            }
            if (!count)
            {
                auto iter = find(notcoveredmins.begin(), notcoveredmins.end(), it->first);
                if (iter == notcoveredmins.end())
                    notcoveredmins.push_back(it->first);
            }
        }

    }

    print(EPIs, notcoveredmins, variables);

    vector< pair < string, vector<int> > > CoverChart;
    vector <string> temp;
    for (int i = 0; i < PIs.size(); i++)
    {
        vector <int> tempo(notcoveredmins.size(), 0);

        bool nonepi(true);
        for (int j = 0; j < EPIs.size(); j++)
        {
            if (PIs[i] != EPIs[j] && nonepi) // checking if nonepi
                nonepi = true;
            else
                nonepi = false;
        }

        if (nonepi)
        {
            temp.push_back(PIs[i]);

            for (int k = 0; k < notcoveredmins.size(); k++)
                for (int j = 0; j < minterms[i].size(); j++)
                {
                    if (minterms[i][j] == notcoveredmins[k])
                    {
                        tempo[k] = 1;
                    }

                    else if (!tempo[k])
                        tempo[k] = 0;
                }

            CoverChart.push_back(pair<string, vector<int> >(PIs[i], tempo));

        }

    }
    f6(CoverChart, EPIs, variables);
}
#endif
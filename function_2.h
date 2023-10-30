#ifndef FUNCTION_2_H
#define FUNCTION_2_H
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


map<char, vector<int>> function_2(set<char> vars, vector<string> pros, bool PoS)
{
    int n = vars.size();
    int size = 2 << n - 1;
    map<char, vector<int>> table;

    for (set<char>::iterator iter = vars.begin(); iter != vars.end(); iter++)
        table.insert(pair<char, vector<int>>(*iter, vector<int>(size)));

    table.insert(pair<char, vector<int>>('X', vector<int>(size)));
    set<char>::iterator iter = vars.end();
    iter--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int add = 1 << i - 1;
            if (table[*iter][j] == 0)
                table[*iter][j + add] = 1;
        }
        iter--;
    }
    

    
    if (!PoS)
    {
        for (int j = 0; j < pros.size(); j++)
        {

            for (int i = 0; i < size; i++)
            {
                if (table['X'][i] == 0)
                {
                    int final = 1;
                    for (int k = 0; k < pros[j].length(); k++)
                    {
                        if (pros[j][k+1] == '\'')
                            final = final && !table[pros[j][k++]][i];
                        else
                            final = final && table[pros[j][k]][i];
                    }
                    table['X'][i] = final;
                }
            }
        }
    }
    else
    {
        replace(table['X'].begin(),table['X'].end(), 0, 1 );
        for (int j = 0; j < pros.size(); j++)
        {

            for (int i = 0; i < size; i++)
            {
                if (table['X'][i] == 1)
                {
                    int final = 1;
                    for (int k = 0; k < pros[j].length(); k+=2)
                    {
                        if (pros[j][k+1] == '\'')
                            final = final && table[pros[j][k++]][i];
                        else
                            final = final && !table[pros[j][k]][i];
                    }
                    if(final)
                        table['X'][i] = 0;
                }
            }
        }
    }
    vector<string> sums;
    vector<string> products;

    for (int i = 0; i < size; i++)
    {
        if(table['X'][i])
        {
            string temp = "";
            for (set<char>::iterator ita = vars.begin(); ita != vars.end(); ita++)
            {
                temp += *ita;
                if(!table[*ita][i])
                    temp += '\'';
            }
            products.push_back(temp);
        }
    }

    for (int i = 0; i < size; i++)
    {
        if(!table['X'][i])
        {
            string temp = "";
            for (set<char>::iterator ita = vars.begin(); ita != vars.end(); ita++)
            {
                temp+= *ita;
                if(table[*ita][i])
                {
                    temp += '+';
                }
                else
                {
                    temp += '\'';
                    temp += '+';
                }
            }
            temp.erase(remove(temp.end()-1, temp.end(), '+'), temp.end());
            sums.push_back(temp);
        }
    }


//OUTPUT

    cout <<  "~~~~~~~~~~~~~~~TRUTH TABLE~~~~~~~~~~~~~~~\n";
    cout << setw(21-n);
    for (set<char>::iterator itar = vars.begin(); itar != vars.end(); itar++)
    {
        cout << *itar << " ";
    }
    cout << 'X' << '\n';
    for (int i = 0; i < size; i++)
    {
        cout << setw(21-n);
        for (set<char>::iterator itar = vars.begin(); itar != vars.end(); itar++)
        {
            cout << table[*itar][i] << " ";
            
        }
        cout << table['X'][i] << "\n";
        
    }

    cout <<  "\n\n~~~~~~~~~~~~~~~SUM OF PRODUCTS~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < products.size(); i++)
    {
        cout << products[i];
        if(i != products.size()-1)
            cout << " + ";
    }
    
    cout << "\n\n\n~~~~~~~~~~~~~~~PRODUCT OF SUMS~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < sums.size(); i++)
    {
        cout << '(' << sums[i] << ")";
    }
    cout << "\n\n\n";

    return table;

}

#endif
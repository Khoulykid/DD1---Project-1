#ifndef FUNCTION_3_H
#define FUNCTION_3_H
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool compare_terms(string x, string y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i] && x[i] != '-')
            return false;
    }
    return true;
}

void function_3(map<char, vector<int>> table, set<char> vars)
{
    vector<vector<int>> minterms;
    vector<int> old_minterms;
    vector<string> pis;
    set<string> remover;
    int size = table['X'].size();
    vector<string> terms;

    for (int i = 0; i < size; i++)
    {
        string temp = "";
        map<char, vector<int>>::iterator iter = table.begin();
        iter++;
        if (table['X'][i])
            while (iter != table.end())
            {
                temp += to_string(iter->second[i]);
                iter++;
            }
        if (temp != "")
        {
            terms.push_back(temp);
            old_minterms.push_back(i);
        }
    }

    vector<set<string>> sets(vars.size() + 1);
    size = terms.size();
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < terms[i].length(); j++)
        {
            if (terms[i][j] == '1')
                count++;
        }
        sets[count].insert(terms[i]);
    }

    size = sets.size() - 1;
    for (int i = 0; i < sets.size() - 2; i++)
    {
        if (sets[i].size() > 0)
        {
            sets.push_back(set<string>());
            size++;
        }
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
        {
            bool flag;
            for (set<string>::iterator k = sets[i + 1].begin(); k != sets[i + 1].end(); k++)
            {
                flag = false;
                int count = 0;
                int index;
                for (int z = 0; z < (*k).length(); z++)
                    if ((*k)[z] != (*j)[z])
                    {
                        flag = true;
                        index = z;
                        if (count++ == 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                if (flag)
                {
                    string temp = *k;
                    temp[index] = '-';
                    sets[size].insert(temp);
                    remover.insert(*k);
                    remover.insert(*j);
                }
            }
        }
    }

    for (vector<set<string>>::iterator iter = sets.begin(); iter != sets.end();)
        if (iter->empty())
            iter = sets.erase(iter);
        else
            ++iter;

    for (int i = 0; i < sets.size(); i++)
    {
        for (set<string>::iterator iter = sets[i].begin(); iter != sets[i].end();)
        {
            bool test = false;
            for (set<string>::iterator ita = remover.begin(); ita != remover.end();)
            {
                if (*ita == *iter)
                {
                    ita = remover.erase(ita);
                    test = true;
                    break;
                }
                else
                {
                    ita++;
                }
            }
            if (test)
                iter = sets[i].erase(iter);
            else
                iter++;
        }
    }

    for (int i = 0; i < sets.size(); i++)
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
        {
            minterms.push_back(vector<int>());
            pis.push_back(*j);
        }

    for (int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < pis.size(); j++)
        {
            if (compare_terms(pis[j], terms[i]))
                minterms[j].push_back(old_minterms[i]);
        }
    }

    for (int i = 0; i <pis.size(); i++)
    {
        cout << pis[i] << " : ";
        for (int j = 0; j < minterms[i].size(); j++)
            cout << minterms[i][j] << " ";
        cout << '\n';
    }
}

#endif
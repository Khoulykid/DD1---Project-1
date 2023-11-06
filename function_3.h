#ifndef FUNCTION_3_H
#define FUNCTION_3_H
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include "function_4_5.h"
#include  "function_8.h"

using namespace std;

bool compare_terms(string x, string y)  //Making a function that returns true if the difference between 2 strings is only -
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i] && x[i] != '-')
            return false;
    }
    return true;
}

void PI_gen(map<char, vector<int>> table, set<char> vars)
{
    vector<vector<int>> minterms;   //To store final minterms covered. First index it to which PI and 2nd index is to all the minterms
    vector<int> old_minterms;   //To store the minterms of each basic term (Like 0001 covers minterm 1)
    vector<string> pis; //To store the PIs. I made it vector because it was requested in the 4th Function
    set<string> remover;    //To store all the used "terms" or expressions to remove them from the final list as they're not PIs
    int size = table['X'].size();   //Just to stop calling the function alot
    vector<string> terms;   //To store the initial expressions

    for (int i = 0; i < size; i++)  //For loop that adds every Minterm into "terms" as 0's and 1's. It also saves what minterm each part represents/covers
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

    vector<set<string>> sets(vars.size() + 1);  //Made a vector of sets. Each set represents the group of terms and divided them on the basis of numbers of 1's in each.
    size = terms.size();
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < terms[i].length(); j++) //I count the number of ones and add it to its corresponding Set
        {
            if (terms[i][j] == '1')
                count++;
        }
        sets[count].insert(terms[i]);
    }

    size = sets.size() - 1; //Needed this to save the last index in the vector
    for (int i = 0; i < sets.size() - 2; i++)
    {
        if (sets[i].size() > 0) //Since each group we compare, we insert the new terms in a new set, I check if there is a set of implicants that we are going to compare the current one with, and if there is, then we insert a new set to insert the new ones in.
        {
            sets.push_back(set<string>());
            size++;
        }
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
        {
            bool flag;
            for (set<string>::iterator k = sets[i + 1].begin(); k != sets[i + 1].end(); k++)    //I compare the current cover with the cover from the other set
            {
                flag = false;
                int count = 0;
                int index;
                for (int z = 0; z < (*k).length(); z++)
                    if ((*k)[z] != (*j)[z])
                    {
                        flag = true;
                        index = z;
                        if (count++ == 1)   //If it finds more than 1 difference (logical distance) then we break and go to the next cover
                        {
                            flag = false;
                            break;
                        }
                    }
                if (flag)   //If the covers are used, we prepare them to remove them from the final set in the end. We also insert the new cover with '-' in the cover list
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

    for (vector<set<string>>::iterator iter = sets.begin(); iter != sets.end();)    //Deleting any empty sets. Empty sets are the products of 2 sets that do not have any elements that have 1 logical distance.
        if (iter->empty())
            iter = sets.erase(iter);
        else
            ++iter;

    for (int i = 0; i < sets.size(); i++)   //Erasing all the covers that aren't Prime.
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

    for (int i = 0; i < sets.size(); i++)   //Pushing the PIs into a vector of strings for the next user to use them. Also initializing a vector of numbers in its index to save the minterms it covers in.
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
        {
            minterms.push_back(vector<int>());
            pis.push_back(*j);
        }

    for (int i = 0; i < terms.size(); i++)  //Inserting all the minterms that each PI covers.
    {
        for (int j = 0; j < pis.size(); j++)
        {
            if (compare_terms(pis[j], terms[i]))
                minterms[j].push_back(old_minterms[i]);
        }
    }
    //OUTPUT
    bool flag(true);
    if (pis.size() == 1)
    {
        for (int i = 0; i < pis[0].length(); i++)
        {
            if (pis[0][i] != '-')
                flag = true;
            else
                flag = false;
        }
        if (!flag)
        {
            cout << "Function is always 1 (True)";
            Circuit_gen("1");
        }
    }
    else if (!pis.size())
    {
        flag = false;
        cout << "Function is always 0 (False)";
        Circuit_gen("0");
    }
    if(flag)
    {
        for (int i = 0; i < pis.size(); i++)
        {
            cout << pis[i] << " : ";
            for (int j = 0; j < minterms[i].size(); j++)
                cout << minterms[i][j] << " ";
            cout << '\n';
        }

        EPI_gen(table, pis, minterms, vars);
    }
}

#endif
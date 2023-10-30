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


void function_3(map<char, vector<int>> table, set<char> vars)
{
    vector<string> pis;
    set<string> remove1, remove2;
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
        if(temp != "")
            terms.push_back(temp);
    }

    vector<set<string>> sets(vars.size() + 1);
    size = terms.size();
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < terms[i].length(); j++)
        {
            if(terms[i][j] == '1')
                count++;
        }
        sets[count].insert(terms[i]);
    }

    size = sets.size() - 1;
    for (int i = 0; i < sets.size() - 2; i++)
    {
        if(sets[i].size() > 0)
        {
            sets.push_back(set<string>());
            size++;
        }
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
        {
            bool flag;
            for (set<string>::iterator k = sets[i+1].begin(); k != sets[i+1].end(); k++)
            {
                flag = false;
                int count = 0;
                int index;
                for (int z = 0; z < (*k).length(); z++)
                    if((*k)[z] != (*j)[z])
                    {   
                        flag = true;
                        index = z;
                        if(count++==1)
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
                    remove1.insert(*k);
                }
            }
            if (flag)
            {
                remove2.insert(*j);
            }
        }
    }



    
    for (int i = 0; i < sets.size(); i++)
    {
        for (set<string>::iterator iter1 = sets[i].begin(); iter1 != sets[i].end(); iter1++)
        {
            bool flag = true;
            for (set<string>::iterator iter2 = remove1.begin(); iter2 != remove1.end(); iter2++)
            {
                if (*iter1 == *iter2)
                {
                    flag = false;
                    break;
                }
            }
            for (set<string>::iterator iter2 = remove2.begin(); iter2 != remove2.end(); iter2++)
            {
                if (*iter1 == *iter2)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                pis.push_back(*iter1);
        }
    }

    for (int i = 0; i < sets.size(); i++)
        for (set<string>::iterator j = sets[i].begin(); j != sets[i].end(); j++)
            cout << *j << "\n";

    for (int i = 0; i < pis.size(); i++)
        cout << pis[i] << '\n';

    

    
    
    
    



}



#endif
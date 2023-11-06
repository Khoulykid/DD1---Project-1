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


map<char, vector<int>> Truth_Table_gen(set<char> vars, vector<string> pros, bool PoS)
{
    int n = vars.size();    //Storing it in a varialbe instead of calling the function everytime.
    int size = 2 << n - 1;  //Bit operation to get the number of rows in the truth table.
    map<char, vector<int>> table;   //Creating a map(truth table) with Key index as the variables in the input
    //and frequency as the vector of int that'll store the values (0,1) 

    for (set<char>::iterator iter = vars.begin(); iter != vars.end(); iter++)
        table.insert(pair<char, vector<int>>(*iter, vector<int>(size)));    //Initializing the variables in the Map (Key)

    table.insert(pair<char, vector<int>>('X', vector<int>(size)));  //Making an X as the final column to store the answers of our function
    set<char>::iterator iter = vars.end();
    iter--;
    for (int i = 1; i <= n; i++)    //Loop to fill the table with 1's and 0's
    {
        for (int j = 0; j < size; j++)
        {
            int add = 1 << i - 1;
            if (table[*iter][j] == 0)
                table[*iter][j + add] = 1;
        }
        iter--;
    }



    if (!PoS)   //checks whether it is PoS or not
    {
        for (int j = 0; j < pros.size(); j++)
        {

            for (int i = 0; i < size; i++)
            {
                if (table['X'][i] == 0) //This is so he doesn't edit a minterm that is already true
                {
                    int final = 1;
                    for (int k = 0; k < pros[j].length(); k++)
                    {
                        if (pros[j][k + 1] == '\'')
                            final = final && !table[pros[j][k++]][i];   //Checks whether it is inverted or not
                        else
                            final = final && table[pros[j][k]][i];
                    }
                    table['X'][i] = final;  //Makes the minterm on or off depending on the product
                }
            }
        }
    }
    else
    {
        replace(table['X'].begin(), table['X'].end(), 0, 1);    //Replacing all the 0's with 1's so I can make the maxterms = 0
        for (int j = 0; j < pros.size(); j++)
        {

            for (int i = 0; i < size; i++)
            {
                if (table['X'][i] == 1) //Check if it's 1 so that I do not edit over an already existing 0
                {
                    int final = 1;
                    for (int k = 0; k < pros[j].length(); k += 2) //Iterate by 2 steps to avoid checking over the +
                    {
                        if (pros[j][k + 1] == '\'')   //Checking for invert
                            final = final && table[pros[j][k++]][i];
                        else
                            final = final && !table[pros[j][k]][i];
                    }
                    if (final)
                        table['X'][i] = 0;
                }
            }
        }
    }
    vector<string> sums;
    vector<string> products;

    for (int i = 0; i < size; i++)  //Producing the products/minterms
    {
        if (table['X'][i])
        {
            string temp = "";
            for (set<char>::iterator ita = vars.begin(); ita != vars.end(); ita++)
            {
                temp += *ita;
                if (!table[*ita][i])
                    temp += '\'';
            }
            products.push_back(temp);
        }
    }

    for (int i = 0; i < size; i++)  //Producing the sums/Maxterms
    {
        if (!table['X'][i])
        {
            string temp = "";
            for (set<char>::iterator ita = vars.begin(); ita != vars.end(); ita++)
            {
                temp += *ita;
                if (table[*ita][i])
                {
                    temp += '+';
                }
                else
                {
                    temp += '\'';
                    temp += '+';
                }
            }
            temp.erase(remove(temp.end() - 1, temp.end(), '+'), temp.end());
            sums.push_back(temp);
        }
    }


    //OUTPUT

    cout << "~~~~~~~~~~~~~~TRUTH TABLE~~~~~~~~~~~~~~\n";
    cout << setw(21 - n);
    for (set<char>::iterator itar = vars.begin(); itar != vars.end(); itar++)
    {
        cout << *itar << " ";
    }
    cout << 'X' << '\n';
    for (int i = 0; i < size; i++)
    {
        cout << setw(21 - n);
        for (set<char>::iterator itar = vars.begin(); itar != vars.end(); itar++)
        {
            cout << table[*itar][i] << " ";

        }
        cout << table['X'][i] << "\n";

    }

    cout << "\n\n~~~~~~~~~~~~~~SUM OF PRODUCTS~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < products.size(); i++)
    {
        cout << products[i];
        if (i != products.size() - 1)
            cout << " + ";
    }

    cout << "\n\n\n~~~~~~~~~~~~~~PRODUCT OF SUMS~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < sums.size(); i++)
    {
        cout << '(' << sums[i] << ")";
    }
    cout << "\n\n\n";

    return table;

}

#endif
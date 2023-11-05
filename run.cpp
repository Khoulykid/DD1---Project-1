#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void function_1();

map<char, vector<int> > function_2(set<char> vars, vector<string> pros, bool PoS);

bool validate(string &user_input, bool &pos);

bool compare_terms(string x, string y);

void function_3(map<char, vector<int> > table, set<char> vars);

void print(vector<string> EPIs, vector<int> notcoveredmins, string variables);

void function_4(map<char , vector<int> > table, vector<string> PIs , vector< vector<int> > minterms , set<char> vars );

int main()
{
    function_1();

    return 0;
}

bool compare_terms(string x, string y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i] && x[i] != '-')
            return false;
    }
    return true;
}

void function_3(map<char, vector<int> > table, set<char> vars)
{
    vector<vector<int> > minterms;
    vector<int> old_minterms;
    vector<string> pis;
    set<string> remover;
    int size = table['X'].size();
    vector<string> terms;

    for (int i = 0; i < size; i++)
    {
        string temp = "";
        map<char, vector<int> >::iterator iter = table.begin();
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

    vector<set<string> > sets(vars.size() + 1);
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

    for (vector<set<string> >::iterator iter = sets.begin(); iter != sets.end();)
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

    function_4(table, pis, minterms, vars);
}

void function_1()
{
    string boolexp;
    bool Pos(false);

    cout << "Enter your Boolean Expression in either POS or SOP: \n";

    getline(cin, boolexp);

    while (!validate(boolexp, Pos))
    {
        cout << "Incorrect Syntax is used, please re-enter (max 10 variables): ";

        getline(cin, boolexp);
    }

    set<char> vars;
    vector<string> pros;
    int n = boolexp.length();
    string temp("");

    // loop to make bool exp into set of variables and vector of products
    for (int i = 0; i < n; i++)
    {

        if (isalpha(boolexp[i]))
        {
            vars.insert(boolexp[i]);
        }

        if (isalpha(boolexp[i]) || boolexp[i] == '\'')
            temp += boolexp[i];

        if (Pos)
        {
            if (boolexp[i] == '+')
                temp += boolexp[i];
            if (boolexp[i] == ')')
            {
                pros.push_back(temp);
                temp = "";
            }
        }
        else
        {

            if (boolexp[i] == '+' || boolexp[i + 1] == '\0')
            {
                pros.push_back(temp);
                temp = "";
            }
        }
    }

    function_3(function_2(vars, pros, Pos), vars);
    // outputting set
    // for (auto it = vars.begin(); it != vars.end(); ++it)
    //     cout << ' ' << *it;

    // outputting vector
    // for (auto it = pros.begin(); it != pros.end(); ++it)
    //     cout << *it << endl;
    
}

bool validate(string &user_input, bool &pos)
{
    int n = user_input.length();
    int openC(0), closedC(0), err(0), plusC(0), alphacount(0), foundalpha(0), foundplus(0);
    bool found(false);

    if (n == 1)
        if (!(user_input[0] >= 'a' && user_input[0] <= 'z'))
            return false;

    user_input.erase(remove(user_input.begin(), user_input.end(), ' '), user_input.end());
    n = user_input.length();

    for (int i = 0; i < n; i++)
    {
        if (isalpha(user_input[i]))
        {
            alphacount++;
            if (found)
                foundalpha++;
        }

        if (!islower(user_input[i]) && user_input[i] != '+' && user_input[i] != ')' && user_input[i] != '(' && user_input[i] != '\'')
        {
            cout << "use only small letters , ( , ) or + \n";

            return false;
        }

        if ((i != 0 || user_input[i] != '\0') && (user_input[i] == '\'') && (user_input[i + 1] == '(' || ((!isalpha(user_input[i - 1]) && user_input[i - 1] != '\'') && i != 0)))
        {
            cout << "incorrect value placed after ' \n";

            return false;
        }

        if (user_input[i] == '+')
        {
            plusC++;
            if (found)
                foundplus++;

            if ((i != 0 || user_input[i] != '\0') && !isalpha((user_input[i + 1])))
            {
                cout << "incorrect value placed after + \n";

                return false;
            }
        }
        if (user_input[i] == '(')
        {
            found = true;
            openC++;
            if (user_input[i + 1] == '\'' || user_input[i + 1] == '+' || (isalpha(user_input[i - 1]) && i != 0))
                return false;
        }

        if (user_input[i] == ')')
        {
            if (foundalpha > 1 && foundplus == 0)
            {
                return false;
            }
            found = false;
            foundalpha = 0;
            foundplus = 0;
            closedC++;
            if (user_input[i + 1] == '\'' || user_input[i + 1] == '+' || isalpha(user_input[i + 1]))
                return false;
        }
    }

    if (openC == closedC && openC != 0)
    {
        // if (plusC >= closedC)
        //{
        pos = true;
        return true;
        // }
        // else
        // {
        // return false;
        // }
    }
    else if (openC != closedC || alphacount == 0)
        return false;
    else if(alphacount>10)
        return false;
    for (int i = 0; i < n - 1; i++)
    {
        if (user_input[i] == '\'' && user_input[i + 1] == '\'')
        {
            user_input.erase(i, 2);
            i--;
        }
    }
    return true;
}

map<char, vector<int> > function_2(set<char> vars, vector<string> pros, bool PoS)
{
    int n = vars.size();
    int size = 2 << n - 1;
    map<char, vector<int> > table;

    for (set<char>::iterator iter = vars.begin(); iter != vars.end(); iter++)
        table.insert(pair<char, vector<int> >(*iter, vector<int>(size)));

    table.insert(pair<char, vector<int> >('X', vector<int>(size)));
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
                        if (pros[j][k + 1] == '\'')
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
        replace(table['X'].begin(), table['X'].end(), 0, 1);
        for (int j = 0; j < pros.size(); j++)
        {

            for (int i = 0; i < size; i++)
            {
                if (table['X'][i] == 1)
                {
                    int final = 1;
                    for (int k = 0; k < pros[j].length(); k += 2)
                    {
                        if (pros[j][k + 1] == '\'')
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

    for (int i = 0; i < size; i++)
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

    for (int i = 0; i < size; i++)
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

    // OUTPUT

    cout << "~~~~~~~~~~~~~~~TRUTH TABLE~~~~~~~~~~~~~~~\n";
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

    cout << "\n\n~~~~~~~~~~~~~~~SUM OF PRODUCTS~~~~~~~~~~~~~~~\n\n";
    for (int i = 0; i < products.size(); i++)
    {
        cout << products[i];
        if (i != products.size() - 1)
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

void print(vector<string> EPIs, vector<int> notcoveredmins, string variables)
{
    //printing EPIS
    cout << "\n\n\n~~~~~~~~~~~~~~~EPIS~~~~~~~~~~~~~~~\n\n";
    for(int i = 0 ; i < EPIs.size() ; i++)
    {   
        for(int j = 0 ; j < EPIs[i].length(); j++)
        {
            if(EPIs[i][j] == '1')
                cout << variables[j] ;
            else if(EPIs[i][j] == '0')
                cout << variables[j] << '\'' ;
            
        }
    if(i != EPIs.size() -1)
        cout << " + " ;
    }
    cout << endl;
    cout << "\n\n\n~~~~~~~~~MINTERMS NOT COVERED BY EPIS~~~~~~~~~\n\n";
    if(notcoveredmins.size() == 0)
        cout << "\tAll minterms are covered by EPIS \n\n";
    else
    for(int i = 0 ; i < notcoveredmins.size() ; i++)
    {
        cout << "m" << notcoveredmins[i] << endl;
    }
}

void function_4(map<char , vector<int> > table, vector<string> PIs , vector< vector<int> > minterms , set<char> vars )
{   
    string variables;
    int i (0);

    for(auto it = vars.begin(); it!= vars.end(); it++)
    {
        variables[i++] = *it;
    }
    
    int n = table['X'].size();

    map <int , int> mintermfreq;
    map < int , vector<string> > mintermPIs;
    vector<string> EPIs;
    vector<int> notcoveredmins;


    for(int i = 0; i < n; i++)
    if(table['X'][i])
    {
        mintermfreq[i] = 0;
    }
    for( int i = 0 ; i < minterms.size(); i++)
        for( int j = 0; j < minterms[i].size(); j++)
        {
            mintermfreq[minterms[i][j]]++; 
            mintermPIs[minterms[i][j]].push_back(PIs[i]);
        }
    
    for(auto it = mintermfreq.rbegin() ;it != mintermfreq.rend(); ++it)
    {
        if(it->second == 1)
        {
            auto ier = find(EPIs.begin(),EPIs.end(),mintermPIs[it->first][0]);
            if(ier == EPIs.end())
                EPIs.push_back(mintermPIs[it->first][0]);
        }
    }
    for(auto it = mintermfreq.begin() ;it != mintermfreq.end(); ++it)
    {
        int count(0);
        if(it->second != 1)
        {
            for(int i = 0 ; i < mintermPIs[it->first].size() ; i++)
            {   for(int j = 0; j < EPIs.size(); j++)
                {   
                    if(mintermPIs[it->first][i] == EPIs[j]) 
                        count++;
                }
            }
        if (!count)
                {    auto iter = find(notcoveredmins.begin(),notcoveredmins.end(),it->first);
                        if(iter == notcoveredmins.end())
                            notcoveredmins.push_back(it->first);
                }
        }
        
    }
    print(EPIs, notcoveredmins, variables);


    vector< pair < string , vector<int> > > CoverChart;
    vector <string> temp;
    for(int i = 0 ; i < PIs.size() ; i++)
    {
        vector <int> tempo (notcoveredmins.size() , 0) ;

        bool nonepi (true);
        for(int j = 0 ; j <EPIs.size(); j++)
        {
            if(PIs[i] != EPIs[j] && nonepi)
                nonepi = true;
            else 
                nonepi = false;
            
            
        }
        
        if(nonepi)
        {   
            temp.push_back(PIs[i]);            
            
            for(int k = 0; k < notcoveredmins.size(); k++)
                for(int j = 0 ; j < minterms[i].size(); j++)
                {
                    if(minterms[i][j] == notcoveredmins[k])
                    {
                        tempo[k] = 1;
                    }
                        
                    else if (!tempo[k])
                        tempo[k] = 0;
                }
             CoverChart.push_back(pair<string, vector<int> > (PIs[i],tempo));
        }
        
        
    }

    //f6(CoverChart, EPIs);

    cout << "COVERED CHART :\n" ;


    for( i = 0 ; i < CoverChart.size(); i++)
    {
        cout << CoverChart[i].first <<" ";
            for( int j = 0; j < CoverChart[i].second.size(); j++)
            {
                cout << CoverChart[i].second[j] << " ";
            }

            cout << endl;

    }
    //notcoveredmins, mintermsPIs, EPIs, variables;
}
#ifndef FUNCTION_1_H
#define FUNCTION_1_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void function_1()
{
    string boolexp;
    bool Pos(false);

    cout << "Enter your Boolean Expression in either POS or SOP: \n";

    getline(cin, boolexp);

    while (!validate(boolexp, Pos))
    {
        cout << "Incorrect Syntax is used, please re-enter: ";

        getline(cin, boolexp);
    }

    set<char> vars;
    vector<string> terms;
    int n = boolexp.length();
    string temp("");

    // loop to make bool exp into set of variables and vector of products
    for (int i = 0; i < n; i++)
    {

        if (isalpha(boolexp[i]))
        {
            vars.insert(boolexp[i]);
            temp += boolexp[i];
        }

        if (Pos)
        {
            if (boolexp[i] == '+')
                temp += boolexp[i];
            if (boolexp[i] == ')')
            {
                terms.push_back(temp); // pushing MAXTERMS
                temp = "";
            }
        }
        else
        {

            if (boolexp[i] == '+' || boolexp[i + 1] == '\0')
            {
                terms.push_back(temp); // pushing MINTERMS
                temp = "";
            }
        }
    }
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

    for (int i = 0; i < n; i++ )
    {
        if (isalpha(user_input[i]))
        {
            alphacount++;
            if (found) // alpha count per bracket
                foundalpha++;
        }

        if (!islower(user_input[i]) && user_input[i] != '+' && user_input[i] != ')' && user_input[i] != '(' && user_input[i] != '\'') // no invalid char after +
        {
            cout << "use only small letters , ( , ) or + \n";

            return false;
        }

        if ((i != 0 || user_input[i] != '\0') && (user_input[i] == '\'') && (user_input[i + 1] == '(' || ((!isalpha(user_input[i - 1]) && user_input[i - 1] != '\'') && i != 0))) // no invalid char before and after '
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
            if (user_input[i + 1] == '\'' || user_input[i + 1] == '+' || (isalpha(user_input[i - 1]) && i != 0)) // no invalid charackets after or before open bracket
                return false;
        }

        if (user_input[i] == ')')
        {
            if (foundalpha > 1 && foundplus == 0) // making sure that two consecutive letters in a bracket is invalid
            {
                return false;
            }

            found = false;
            foundalpha = 0;
            foundplus = 0; // reinitializing for next bracket check

            closedC++;

            if (user_input[i + 1] == '\'' || user_input[i + 1] == '+' || isalpha(user_input[i + 1])) // no invalid characters after closed bracket
                return false;
        }
    }

    if (openC == closedC && openC != 0) // checking the brackets to know if it is pos or sop
    {
        pos = true;
        return true;
    }
    else if (openC != closedC || alphacount == 0) // if no letter or if the brackers are unequal
        return false;

    for (int i = 0; i < n - 1; i++) // removing double negation
    {
        if (user_input[i] == '\'' && user_input[i + 1] == '\'')
        {
            user_input.erase(i, 2);
            i--;
        }
    }

    return true;
}
#endif
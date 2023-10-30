#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include "function_2.h"
#include "function_3.h"

using namespace std;


int main()
{
    set<char> vars;
    vars.insert('a');
    vars.insert('b');
    vars.insert('c');
    vars.insert('d');
    vector<string> x;
    x.push_back("a");
    x.push_back("d\'");
    map<char, vector<int>> table = function_2(vars, x, false);
    
    function_3(table, vars);
    

    

    return 0;
}
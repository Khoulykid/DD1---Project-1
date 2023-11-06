#pragma once
#ifndef FUNCTION_8_H
#define FUNCTION_8_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include<fstream>
#include<sstream>
using namespace std;
void Circuit_gen(string boolexp)
{
    vector<string> terms; 
    int n = boolexp.length();
    string temp("");
    bool x(false);
    if (boolexp == "1" || boolexp == "0")
        x = true;

    for (int i = 0; i < n; i++)
    {

        if (isalpha(boolexp[i]) || boolexp[i] == '\'' || x )
            temp += boolexp[i];
        if (boolexp[i] == '+' || boolexp[i + 1] == '\0')
        {
            terms.push_back(temp);
            temp = "";
        }
    }

    vector<int> counter;
    int count = 0;
    ofstream output("circuit.json"); //create file 
    if (output.is_open())
    {
        output << " { assign:[ \n";
        output << "     [\"out\", \n";
        if(terms.size()>1)
            output << "         [\"|\",  \n" ;
        for (int i = 0; i < terms.size(); i++) //check for terms to add the logic cicuits
        {
            for (int j = 0; j < terms[i].size(); j++)
            {
                if (isalpha(terms[i][j]) || x)
                    count++;           // counter for numof chars in each

            }
            counter.push_back(count);   //push back to vector representing num of chars in each minterms
            count = 0;
        }
    }
    for (int i = 0; i < terms.size(); i++) //loop over each minterm 
    {
        if (counter[i] > 1)
            output << "             [\"&\", ";
        for (int j = 0; j < terms[i].size(); j++) //loop over each character and add to .jpson file 
        {
            if (output.is_open())
            {
                if (terms[i][j + 1] == '\'') // check if next element is '
                {
                    output << "[\"~\", \"";
                    output << terms[i][j];
                    output << "\"]";
                    if (terms[i][j + 2] != '\0' && counter[i] != 1)
                        output << ", ";
                    j++;                        // increment to go to next character
                }
                else 
                {
                    output << "\"";
                    output << terms[i][j];
                    output << "\"";
                    if (terms[i][j + 1] != '\0')
                        output << ", ";
                }
                if (terms[i][j + 1] == '\0' && counter[i]!=1)
                    output << "]";

            }
        }
        if (i != terms.size() - 1)          // checking if it's not the last input to add ,
            output << ", \n";
    }
    output << " \n         ]\n";
    if(terms.size() > 1)
        output << "     ] \n";
    output << " ]}\n";
    output.close();

    ofstream output2("circuit.html"); //create file 
    ifstream input("circuit.json"); //create file 
    if (output2.is_open())
    {
        output2 << "<html> \n<body onload=\"WaveDrom.ProcessAll()\">\n ";
        output2 << "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/wavedrom/3.1.0/skins/default.js\" type=\"text/javascript\"></script>\n";
        output2 << "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/wavedrom/3.1.0/wavedrom.min.js\" type=\"text/javascript\"></script>\n";
        output2 << "<script type=\"WaveDrom\">\n";
        string store;
        if (input.is_open())
        {
            while (!input.eof())
            {
                getline(input, store);
                output2 << store << "\n ";
            }
        }
        output2 << "</script> \n </body> \n </html> ";
              
    }
    output2.close();
    input.close();
    string ans;
    cout << "\n\n\n~~~~~~~~~~~~~~~CIRCUIT DISPLAY~~~~~~~~~~~~~~~\n\n";
    cout << "Do you wish to display the circuit? yes/no \n";
    cin >> ans;
    if(ans == "yes" || ans == "Yes")
        system("C:/Users/noury/source/repos/DD1proj1/DD1proj1/circuit.html");

    
}




#endif
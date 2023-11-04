void print(vector<string> PIs, string variables)
{
    //printing EPIS
    cout << "\n\n\n~~~~~~~~~~~~~~~OUTPUT~~~~~~~~~~~~~~~\n\n";
    for(int i = 0 ; i < PIs.size() ; i++)
    {   
        for(int j = 0 ; j < PIs[i].length(); j++)
        {
            if(PIs[i][j] == '1')
                cout << variables[j] ;
            else if(PIs[i][j] == '0')
                cout << variables[j] << '\'' ;
            
        }
    if(i != PIs.size() -1)
        cout << '+' ;
    }
    cout << endl;
}
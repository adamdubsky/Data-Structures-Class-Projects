/**
 complete_main.cc
 Adam Dubsky
 August 30 2021
CS3610
**/




#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <array>

using namespace std;

int main(int argc,char* argv[]){

    int input = stoi(argv[1]); //sets the second command as the input
    vector<int> vector(input, 0); //initializes "empty" vector



    //check for correct amount of arguments and terminate
    if (argc != 2)
    {
        cout << "Incomplete Number of arguments" << endl;
        return 0;
    }

    //checks for in range input and terminates if not correct
    if (input > 3000)
    {
        cout << "Out of range";
        return 0;
    }
    
    


    //checks for prime number and sets the value to 1 if it is not
    for (int i = 2; i < input; i++)
    {
        for (int j = i * i; j < input; j+=i)
        {
            vector.at(j-1) = 1;
        }
        
    }

    cout << "Prime Numbers "; 

    //checks for prime value status and outputs
    for (int i = 2; i < input; i++)
    {
        if (vector.at(i-1) == 0)
        {
            cout << i << " ";
        }
        
    }
    cout << endl;
    cout << "Composite Numbers ";
    
    //checks for composite value and outputs
    for (int i = 2; i < input; i++)
    {
        if (vector.at(i-1) == 1)
        {
            cout << i << " ";
        }
        
    }
    



    return 0;
}

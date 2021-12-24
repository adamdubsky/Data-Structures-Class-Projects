//Adam Dubsky
//CS3610
//November 2021

//references
//page 700
//https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//https://stackoverflow.com/questions/1286771/adding-values-to-a-3-d-vector-in-c
//https://www.youtube.com/watch?v=Da_PPyjOUrE&ab_channel=Engineer4Free

#include <iostream>
#include <string>
#include <sstream>
#include <cfloat>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main(int argc, char** argv){

    ///Read user input
    int test_cases;  
    //holds number of cities
    vector <int> num_cities;
    //holds the city name
    vector <vector <string> > name_cities; 
    vector <vector <vector <int> > > distance; 
    int temp_cities;            
    string str;

    vector <int> smallest_dis;              
    vector <string> path;                
    vector <int> final_distancet;         
    vector <string> final_path;           
    vector <string> reverse_path;  

    bool *find_weight;

    double min_weight;       

    
    //initialize all user inputs
    cout << "How many testcases? " << endl;
    cin >> test_cases;                      
    for (int i = 0; i < test_cases; i++)    
    { 
        //create next layers for the cities and sitance arrays
        //without doing this get a seg fault error
        name_cities.push_back(vector <string>());   
        distance.push_back(vector <vector <int> >());
        //distance[i] pushback must be in loop as it gets repeated

        cout << "How many Cities? " << endl;
        //input loop that allows city inputs based on prior input
        cin >> temp_cities;                                        
        num_cities.push_back(temp_cities);                
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "names of cities"  << endl;
        for (int j = 0; j < num_cities[i]; j++)
        {
            (cin >> str).get();                            
            name_cities[i].push_back(str);                   
        }
        
        distance.push_back(vector <vector <int> >());           
        for (int j = 0; j < num_cities[i]; j++)
        {   //random kid in arc helped me with this part
            distance[i].push_back(vector <int>());   
            //use getline to prevent segerror              
            getline(cin, str);                                  
            istringstream input_stream(str);                    
            while (input_stream >> temp_cities)                        
            {
                distance[i][j].push_back(temp_cities);                    
            }
        }        
    }


    //initialize boolean vars and others that need empty
    for (int i = 0; i < test_cases; i++)                   
    {
        path.push_back(name_cities[i][0]);
        for (int j = 0; j < num_cities[i]; j++){
            smallest_dis.push_back(distance[i][0][j]);
        }
        for (int j = 1; j < num_cities.at(i); j++)
        {
            if (distance[i][0][j] != 0){
                path.push_back(name_cities[i][0]);
            }
            else
                path.push_back("");                  
        }
        








        //initialize
        find_weight = new bool[num_cities.at(i)];        
        for (int m = 0; m < num_cities.at(i); m++){
            if (m == 0)
            {
                find_weight[m] = true;
            }
            if (m != 0)
            {
                find_weight[m] = false;
            }
            
            
        }



        int v;
        
        for (int j = 0; j < num_cities.at(i) - 1; j++)  
        {
            min_weight = 10000000000000000;

            for (int k = 0; k < num_cities.at(i); k++)    
            {
                if (!find_weight[k])
                {
                    if (smallest_dis[k] < min_weight && smallest_dis[k] != 0)
                    {
                        if (smallest_dis[k] != 0)
                        {
                            v = k;
                            min_weight = smallest_dis[v];
                        }
                    }
                }
            }

            find_weight[v] = true;

            //person at arc help
            for (int k = 0; k < num_cities.at(i); k++)
            {
                if (!find_weight[k])
                {
                    if (distance[i][v][k] != 0 && (min_weight + distance[i][v][k] < smallest_dis[k] || smallest_dis[k] == 0))
                    {
                        path.at(k) = name_cities[i][v];
                        smallest_dis[k] = min_weight + distance[i][v][k];      

                    }
                }
            }
        }
        //super good youtube video that helps with this but can not find the link again:(
        int temp = name_cities[i].size() - 1;
        string str = name_cities[i][temp];
        reverse_path.push_back(str);
        while (str != name_cities[i][0])
        {
            str = path.at(temp);
            reverse_path.push_back(str);
            for (size_t k = 0; k < name_cities[i].size(); k++)
                if (name_cities[i][k] == str){
                    temp = k;
                }

        }

        final_distancet.push_back(smallest_dis.at(smallest_dis.size() - 1));

        str = "";
        for (int j = reverse_path.size() - 1; j >= 0; j--){
            str += reverse_path.at(j);
            str +=  + ' ';
        }
        final_path.push_back(str);
        
        //need to empty all values for if there is another testcase
        while (smallest_dis.size() > 0)
            smallest_dis.pop_back();     

        while (path.size() > 0)
            path.pop_back();          

        while (reverse_path.size() > 0)
            reverse_path.pop_back();            
            
    }

    ///Display output
    cout << "The Final path and distance is ...." << endl;
    for (int i = 0; i < test_cases; i++)
    {
        cout << final_path.at(i) << final_distancet.at(i) << endl;
    }
    
    return 0;
}

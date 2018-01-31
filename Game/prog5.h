#ifndef prog4_h
#define prog4_h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
//Defiing constant variables
#define GRID_SIZE 25
#define Low 0
#define High 24
#define MIN_CYCLES 1
#define MAX_CYCLES 4
#define SEED time(0)
#define PRN_CYCLES 10
using namespace std;

//Below are the Function Prototypes from source file
void init_sim(vector<vector<bool>>& , vector <unsigned>&);
unsigned release_balls (vector<vector<bool>>&,vector<unsigned>&);
void print_grid(const vector<vector<bool>>&,const unsigned&,const unsigned&);
void print_stat(const vector<vector<bool>>&,const unsigned&,const unsigned);
void update_cycles (vector <unsigned>&);
#endif

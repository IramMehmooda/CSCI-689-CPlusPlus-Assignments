/*--------------------------------------------------------------------------------
 COURSE: CS689                 ASSIGNMENT NO: 05
 ZID:    Z1818371
 PROGRAM: Our Friend the Atom
 --------------------------------------------------------------------------------- */

#include "prog5.h" //Including header file

unsigned noBallsInAir;
int main(){
	vector< vector<bool>> traps(GRID_SIZE, vector<bool>(GRID_SIZE));
	//unsigned noBallsInAir;
	noBallsInAir=1;
	unsigned clock=0;
	unsigned maxNoBallsInAir=0;
	vector <unsigned> ballCycles;
	init_sim(traps ,ballCycles);
	print_grid(traps,clock,0);
	cout<<endl;
	while (noBallsInAir>0){
		clock++;
		noBallsInAir=release_balls(traps,ballCycles);
		if(maxNoBallsInAir<noBallsInAir){
			maxNoBallsInAir=noBallsInAir;
		}
		if(clock%PRN_CYCLES==0){
		print_grid(traps,clock,noBallsInAir);
		cout<<endl;
		}
	}
	 print_grid(traps,clock,noBallsInAir);
	 print_stat(traps,maxNoBallsInAir,clock);
	 return 0;
}
/*--------------------------------------------------------------------------
Arguments:     This function takes two vectors traps and ballCycles as input.
Return Type:   Void
Action:        This function performs initial simulations 
  -------------------------------------------------------------------------*/
void init_sim(vector<vector<bool>>& traps , vector <unsigned>& ballCycles){
	for(unsigned x=0;x<GRID_SIZE;x++){      //accesing traps vector
		for(unsigned y=0;y<GRID_SIZE;y++){
			traps[x][y]=true;   //initializing each mousetrap in the grid to logical value true

		}
	}
	srand(SEED);   //initializing RNG by srand function for random values
	ballCycles.push_back(1);
	noBallsInAir=1;
	
}
/*--------------------------------------------------------------------------
  Arguments:     This function takes two vectors traps and ballCycles as input.
  Return Type:   unsigned
  Action:        This function reurns the number of balls released in the air
  -------------------------------------------------------------------------*/
	
unsigned release_balls(vector<vector<bool>>& traps,vector<unsigned>& ballCycles){
	//unsigned noBallsInAir=1;
	
	for(unsigned i=0;i<ballCycles.size();i++){  //accessing the ballCycles vector
		if(ballCycles[i]!=0){	//checking if the value of each element is greater than 0
			ballCycles[i]--; //decrementing the value by 1
			if(ballCycles[i]==0){
				int randomX=rand()%(High-Low+1)+Low; //generating a random ineteger between 0 and 25
				int randomY=rand()%(High-Low+1)+Low;
				if(traps[randomX][randomY]==true){//checking if the mousetraps has not yet sprung
					update_cycles(ballCycles);
					update_cycles(ballCycles);
					noBallsInAir=noBallsInAir+2;
					traps[randomX][randomY]=false; // marking the mousetrap as sprung
					}
				noBallsInAir--;//removing a ball from count
			}
		}
	}
	return noBallsInAir; //returns the total number of balls in air
	
}

/*--------------------------------------------------------------------------
 Arguments:     This function takes a vecctor traps and two unsigned values 
                of clock and numbe of balls in air as input.
 Return Type:   void
 Action:        This function prints the current values of simulation clock
                and total number of ballsin air 
 -------------------------------------------------------------------------*/

void print_grid(const vector<vector<bool>>& traps, const unsigned& clock, const unsigned& noBallsInAir){
		cout<<"Clock =  "<<clock<<" : NoBallsInAir = "<<noBallsInAir<<endl;   //printing clock value and the number of balls in air
			for(unsigned i=0;i<GRID_SIZE;i++){ //for each PRN_CYCLES =10
				for(unsigned j=0;j<GRID_SIZE;j++){
					if(traps[i][j]==true){ //checking if the value of mousetrap is true
						cout<<"X ";  //if true, replacing the value with X
					}
					else
						cout<<". ";   //else, replacing the value with .
					

				}
				cout<<endl;
			}
}
			
/*--------------------------------------------------------------------------
 Arguments:     This function takes a vector traps and two unsigned values 
                maxNoBallsInAir and clock as input
 Return Type:   void
 Action:        This function prints the total simulation time clock and max
                number of balls in air 
 --------------------------------------------------------------------------*/


void print_stat(const vector<vector <bool>>& traps, const unsigned& maxNoBallsInAir, const unsigned clock){
	cout<<"The total simulation time is "<<clock<<endl; //prinitng total simulation time 
	cout<<"The maximum number of balls in air are "<<maxNoBallsInAir<<endl;  //printing maximum number of balls in air
	int sprungCount=0; //initializing sprung count  
	for(unsigned i=0;i<GRID_SIZE;i++){  //accesing the traps vector
		for(unsigned j=0;j<GRID_SIZE;j++){
			if(traps[i][j]==false){ //checking if the mousetrap has sprung
				sprungCount++;  //couting the sprungs
			}
		}
	}
	double percentage=(double) (sprungCount)/(GRID_SIZE*GRID_SIZE)*100; 
	cout<<"Percentage of sprung traps = "<<percentage<<endl;  //printing the percentage of mousetraps sprung
}

/*--------------------------------------------------------------------------
 Arguments:     This function takes a vector ballCycles as input
 Return Type:   void
 Action:        This function updates the cycle values
 --------------------------------------------------------------------------*/

void update_cycles(vector<unsigned>& ballCycles){
	unsigned cycle=rand()%(MAX_CYCLES-MIN_CYCLES+1)+MIN_CYCLES;   //generating a random cycle value
	bool fl=false;   
	for(unsigned i=0;i<ballCycles.size();i++){   //accessing the ballCycles vector
		if(ballCycles[i]==0 && !fl){
			ballCycles[i]=cycle;   //assigning the generated cycle value
			fl=true;
		}
	}
	if(!fl){  
			ballCycles.push_back(cycle);}  //adding a cycle value
		       	
}


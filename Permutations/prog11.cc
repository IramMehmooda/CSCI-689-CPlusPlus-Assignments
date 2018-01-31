/*****************************************************************
Course  :  CSCI 689                                Assignment No.: 11
Author  :  Iram Mehmooda				 ZID : Z1818371
PROGRAM :  Displaying Permutations 
 *****************************************************************/

#include "/home/cs689/progs/17f/p11/prog11.h" 
/********************************************************************
Function : main()
Purpose : Takes the user input string, perform permutations and prints
          all values
 * *****************************************************************/
int main(){
	string s;
	cin>>s;
	set<string, cmp> r1;
	r1=genSub(s); //calling genPerm function
	print(r1,6); //calling the print function
	//****print(r1,6);
	return 0;
	
}

/***************************************************************
 *Function : Print
Argument : set, unsigned size to set width
Purpose : Prints all values in the desired form
 * *************************************************************/
void print ( const set < string, cmp >& s, const unsigned& sz){
	int wordsCount=0;
	for(string ss:s){ //iterating through the set
		if(ss!=""){ //checking if the string is not empty
			wordsCount++; 
		        cout<<fixed<<left<<setw(sz)<<ss;
			if(wordsCount%LSIZE==0){
				cout<<endl;
			}
		}
		
	}
	cout<<endl;
}

/***************************************************************
 *Function : genPerm
Arguments : String
return value: set
Purpose : returns the set containing permuatation of the given string
 * *************************************************************/

set < string, cmp > genPerm ( const string& s){
	/*char c=s.at(0);
	string str=s.substr(1);

	//string s1=s.substr(0,1)+s.substr(i+1);
	set<string> ss=genPerm(str);*/
	set<string,cmp> res;
	unsigned n=s.length();
	if(s==""){ //checking if the string is empty
		res.insert("");
		
	}
	else{  //else
		for(unsigned i=0;i<n;i++){ //iterating through the string
			char ch=s[i];
			string a=s.substr(0,i);
			string b=s.substr(i+1);
			string restString=a+b;
			//set<string,cmp> ss=genPerm(s); //l**
			set<string,cmp> f=genSub(restString);
			for(string s:f){ 
				res.insert(s+ch);  //inserting the string and character into result set
			}
		}
	}
	return res; //returning the set
}
/*****************************************************************
 *Function : genSub
Arguments : string
Return type: set
Purpose : generating substring of each string
 * ***************************************************************/
set < string, cmp > genSub ( const string& str){
	
	set<string,cmp> q,t;
	if(str==""){
		q.insert("");
	}
	else{
	int n=str.length(); //storing the lenght of string
	t=genPerm(str); //calling genPerm
	for(string s:t){
		q.insert(s);  //inserting the string in result set
	}
	for(int a=0; a<n;a++){  //ietrating through string
			for(int b=a; b<n-a;b++){
				string c=str.substr(a,b);

				for(string s1:t){
					
					q.insert(c);
				}
				t=genPerm(c);

			}
	}
	}
	
	return q; //returning the result set
}


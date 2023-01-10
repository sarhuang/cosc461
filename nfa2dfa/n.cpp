/* Name: Sarah Huang
 * Course: COSC 461
 * Program: NFA2DFA.cpp
 * Purpose: Simulate the conversion of NFA to DFA.
 */
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <vector>  
using namespace std;


struct DFA{
	map <char, int> moves;	//Each move is associated with an input alphabet
	vector <int> states;	//Multiple NFA states
	bool taken;				//Keep track of which states are used
};

//Search for an integer in a given vector
bool inVector(int match, vector <int> v){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == match)
			return true;
	}
	return false;
}

//Epsilon closure required for subset construction algorithm
//Set of NFA states reachable from some NFA state s in set T on e-transitions alone
vector <int> epsilonClosure(map <int, map <char, vector <int> > > nfa, vector<int> t){
	size_t i;
	vector <int> e;		//e-closure(T)
	stack <int> stacc;	//stack
	int top;			//Integer at top of stack before getting popped off
	map <char, vector <int> > currentState;
	vector <int> eMove; 

	//Initialize e-closure(T) to T & push all states of T onto stack
	for(i = 0; i < t.size(); i++){
		e.push_back(t[i]);
		stacc.push(t[i]);
	}

	while(!stacc.empty()){
		top = stacc.top();
		stacc.pop();
		currentState = nfa[top];
		eMove = currentState['E'];	//Looking for states reachable using epsilon

		//Each state u with an edge from t to u labeled e
		for(i = 0; i < eMove.size(); i++){
			//If u is not in e-closure(T)
			if(!inVector(eMove[i], e)){
				e.push_back(eMove[i]);
				stacc.push(eMove[i]);
			}
		}
	}
	sort(e.begin(), e.end());
	return e;
}


//Move required for subset construction algorithm
//Set of NFA states to which there is a transition on input symbol a from state s in T
vector<int> move(map <int, map <char, vector <int> > > nfa, vector <int> t, char alpha){
	vector <int> reachable;
	vector <int> answer;

	for(int i = 0; i < t.size(); i++){
		reachable = nfa[t[i]][alpha];
		for(int j = 0; j < reachable.size(); j++){
			if(!inVector(reachable[j], answer))
				answer.push_back(reachable[j]);
		}
	}
	return answer;
}


//Search for states that haven't been used/marked
int showNotTaken(map <int, DFA> dfa){
	for(int i = 0; i < dfa.size(); i++){
		if(!dfa[i].taken){
			return i;
		}
	}
	return -1;
}


//Print a given vector
void printVector(vector <int> v){
	cout << "{";
	for(int i = 0; i < v.size(); i++){
		if(i != v.size()-1)
			cout << v[i] << ",";
		else
			cout << v[i];
	}
	cout << "}";
}



int main(){
	size_t i;			
	stringstream ss;
	string line;			//Each line of the input file
	string stringNum;		//A number in string format
	int intNum;				//A number in int format
	int statesCounter = 1;	//Used to count number of states (first state starts at 1)
	int placeholder;		//Used to grab each move in {}s from one line	

	int initialState;	
	vector <int> finalStates;
	int totalStates;
	vector <char> alphabet;
	map <int, map <char, vector <int> > > nfaTable;
	map <char, vector <int> > tempStateMoves;
	vector <int> tempMoves;

	map <int, DFA> dfaTable;
	int dfaState = 1;		//The first state also starts at 1
	vector <int> initialStatesV;
	vector <int> eclose;
	DFA initialStateDFA;
	vector <int> t_Move;
	vector <int> ta_Move;
	DFA newState;
	vector <int> dfaFinalStates;
	int notTaken;
	int member = -1;
	map <int, vector <int> > tempDFAStates; //For printing


	/*Read a given file through standard input (./nfa2dfa < input.txt)
	  Lots of filtering the lines to grab the needed information
	  and then converting them from strings to integers.*/
	while(getline(cin, line)){
		//Intial State
		if(line.find("Initial") != -1){
			for(i = line.find(":") + 1; i < line.length(); i++){
				if(!isspace(line[i]))
					stringNum += line[i];
			}
			ss << stringNum;
			ss >> initialState;
			ss.clear();
			stringNum = "";
		}
		//Final States
		else if(line.find("Final") != -1){
			for(i = line.find("{") + 1; i < line.length(); i++){
				if(line[i] != ',' && line[i] != '}')
					stringNum += line[i];
				else{
					ss << stringNum;
					ss >> intNum;
					finalStates.push_back(intNum);
					ss.clear();
					stringNum = "";
				}
			}
		}
		//Total States
		else if(line.find("Total") != -1){
			for(i = line.find(":") + 1; i < line.length(); i++){
				if(!isspace(line[i]))
					stringNum += line[i];
			}
			ss << stringNum;
			ss >> totalStates;
			ss.clear();
			stringNum = "";
		}
		//State - figuring out alphabet
		else if(line.find("E") != -1){
			for(i = line.find("State") + 5; i < line.find("E"); i++){
				if(!isspace(line[i]))
					alphabet.push_back(line[i]);
			}
			alphabet.push_back('E');
		}
		//State - making the NFA
		else if(!line.empty()){
			for(i = 0; i < alphabet.size(); i++){
				line = line.substr(line.find("{"));
				for(int j = line.find("{") + 1; j <= line.find("}"); j++){
					if(line[j] != ',' && line[j] != '}')
						stringNum += line[j];

					else if(!stringNum.empty()){
						ss << stringNum;
						ss >> intNum;
						tempMoves.push_back(intNum);
						ss.clear();
						stringNum = "";
					}
					placeholder = j;
				}
				tempStateMoves[alphabet[i]] = tempMoves;
				tempMoves.clear();
				line = line.substr(placeholder + 1);
			}
			nfaTable[statesCounter] = tempStateMoves;
			statesCounter++;
		}
	}
	cout << "reading NFA ... done." << endl << endl;
	cout << "creating corresponding DFA ..." << endl;


	//The start of the subset construction algorithm
	//The e-closure(s0) of the initial state has not been taken/unmarked
	initialStatesV.push_back(initialState);
	eclose = epsilonClosure(nfaTable, initialStatesV);
	cout << "new DFA state:  " << dfaState;
	cout << right << setw(10) << "-->  ";
	printVector(eclose);
	cout << endl;


	initialStateDFA.taken = false;
	initialStateDFA.states = eclose;
	dfaTable[dfaState] = initialStateDFA;
	dfaState++;

	//While there is an unmarked state T in Dstates, mark T
	while(showNotTaken(dfaTable) >= 0){
		notTaken = showNotTaken(dfaTable);
		dfaTable[notTaken].taken = true;

		//For each input symbol, add U as an unmarked state to Dstates if U is not in Dstates
		for(i = 0; i < alphabet.size()-1; i++){
			//U = e-closure(move(T,a))
			t_Move = move(nfaTable, dfaTable[notTaken].states, alphabet[i]);
			ta_Move = epsilonClosure(nfaTable, t_Move);


			//Storing the final moves for printing later
			map <int, vector <int> >::iterator tit;
			tit = tempDFAStates.find(dfaState);
			if(tit == tempDFAStates.end())
				tempDFAStates.insert(make_pair(dfaState, ta_Move));
			else
				tit->second = ta_Move;
		

			//Dtran[T,a] = U
			for(int k = 0; k < dfaTable.size(); k++){
				if(dfaTable[k].states == ta_Move){
					member = k;
					break;
				}
				member = -1;
			}		

			if(member >= 0){
				dfaTable[notTaken].moves[alphabet[i]] = member;
			}
			else{
				if(!ta_Move.empty()){
					newState.taken = false;
					newState.states = ta_Move;

					dfaTable[dfaState] = newState;
					dfaTable[notTaken].moves[alphabet[i]] = dfaState;
					dfaState++;
				}
				else
					dfaTable[notTaken].moves[alphabet[i]] = -1;
			}
		}
	}

	//Printing the newly created DFA states
	for(map <int, vector <int> >::iterator tip = tempDFAStates.begin(); tip != tempDFAStates.end(); tip++){
		if(!tip->second.empty()){
			cout << "new DFA state:  " << tip->first;
			cout << right << setw(10) << "-->  ";
			printVector(tip->second);
			cout << endl;
		}
	}
	cout << "done." << endl << endl;


	//Finalizing the new DFA final states
	for(i = 0; i < dfaTable.size(); i++){
		for(int s = 0; s < finalStates.size(); s++){
			if(inVector(finalStates[s], dfaTable[i].states)){
				dfaFinalStates.push_back(i);
				break;
			}
		}
	}


	//Final Printing
	cout << "final DFA:" << endl;
	cout << left << setw(16) << "Initial State:" << initialState << endl;
	cout << left << setw(16) << "Final States:" << "{";
	for(i = 0; i < dfaFinalStates.size(); i++){
		if(i == dfaFinalStates.size()-1)
			cout << dfaFinalStates[i] << "}" << endl;
		else
			cout << dfaFinalStates[i] << ",";
	}
	cout << left << setw(16) << "Total States:" << dfaFinalStates[dfaFinalStates.size()-1] << endl;

	cout << "State	";
	for(i = 0; i < alphabet.size()-1; i++){
		cout << left << setw(17) << alphabet[i];
	}
	cout << endl;


	for(i = 1; i < dfaTable.size(); i++){
		cout << left << setw(8) << i;
		for(int a = 0; a < alphabet.size()-1; a++){
			string temp = "{";
			if(dfaTable[i].moves[alphabet[a]] != -1 && dfaTable[i].moves[alphabet[a]] != 0)
				temp += to_string(dfaTable[i].moves[alphabet[a]]);
			temp += "}";
			cout << left << setw(17) << temp;
		}
		cout << endl;
	}
	return 0;
}

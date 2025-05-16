#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	stack<int> s; //creata a new stack
	string line; //create a string to contain command input
	
	while (getline(cin, line)){
		
		//use stirngstream to seperate words from input stream
		stringstream ss(line);
		string command;
		ss >> command;
		
		//case test
		if (command == "init"){
			//reinit stack
			while(!s.empty()) s.pop();
		}
		else if (command == "push"){
			int x;
			ss >> x; //extract x into command to display
			s.push(x);//push x to the top stack
		}
		else if (command == "pop"){
			if(!s.empty()){
                s.pop();
            }
		}
        else if (command == "top"){
            //print value at the top of stack
            if(s.empty()){
                cout << -1 << endl;
            }
            else{
                cout << s.top() << "\n";
            }
        }
        else if (command == "size"){
            //return size of stack
            cout << s.size() << "\n";
        }
        else if (command == "empty"){
            //return 1 if stack empty and opposite
            cout << (s.empty() ? 1 : 0) << "\n"; 
        }
        else if (command == "end"){
            //exit 
            break;
        }
	}
	return 0;
}
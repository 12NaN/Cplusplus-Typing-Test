#include <iostream>
#include <fstream>
#include "test.h"
#include "leaderboard.h"
using namespace std;

Test test;
Leaderboard view;
int main()
{
	int choice;
	
	do{
		cout << "\t\t=================================\n"
	     	 << "\t\t=\tTyping Test\t\t=\n"
		  	 << "\t\t=================================\n"	
		     <<  "\n\n\t\t1) Start Test\n"
		     <<  "\t\t2) Scoreboard\n"
		     <<  "\t\t3) Exit\n";
		cin >> choice;
		
		if (choice == 1){
			test.start();
		}
		else if (choice == 2)
		{
			int x = 0;
			view.leaderboard(x);
		}
		else if (choice == 3)
		{
			return 0;
		}
		else{
			cout << "That is not a choice\n";
		}
	}while (choice != 3);
	
}


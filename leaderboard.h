#ifndef LEADERBOARD
#define LEADERBOARD

class Leaderboard
{
	public:
		void load_lb();
		void add_lb();
		void leaderboard(int); //(int);	
		int places;
		struct LB
		{
			std::string name;
			int wpm;
		
		};
		LB players[100];
};

void Leaderboard::load_lb()
{
	int i = 0;
	std::ifstream board("Leaderboard.txt"); // Write to file.
	
	if (board.is_open()) // Checks if file is open.
	{
		board >> places;
		
		if (places > 0) // Checks if there are winners.
		{
			do
			{
				board >> players[i].name;
				board >> players[i].wpm;
				i++;
			}while(!board.eof()); // Runs until it reaches the end of the file.
			std::cout << "Leaderboard loaded successfully...\n"; // Prints when the loading is successful.
		}
	}
	else
		std::cout << "File doesn't exist\n"; // Prints if the file doesn't exist.	
}

void Leaderboard::add_lb()
{
	load_lb();
	
	std::fstream board("Leaderboard.txt");
	std::cout << "Type name: ";
	std::cin >> players[places].name;
	
	places++;
	
	if(board.is_open())
	{
		board << places << std::endl;
		
		for (int i = 0; i < places; i++)
		{
			board << players[i].name << "\n";
		}
		board.close();
	}
	else
		std::cout << "Error\n";
}

void Leaderboard::leaderboard(int x)
{
	load_lb(); // Loads file.
	
	system("cls"); // Clears the previous screen.
	std::cout << "\t\t\t===================\n" // Hall of Fame Logo.
	   		 << "\t\t\t=   Leaderboard  =\n"
			 << "\t\t\t===================\n";
			 		
	if(places > 0) // If there are winners it will run.
	{			
		for(int i = 0; i < places; i++)
		{
			std::cout << (i+1) << ") " << players[i].name << "\n";
		}
	}
	else
		std::cout << "No data available...\n"; // Prints if no one is in the Hall of Fame.
		
	system("pause"); // Pauses the screen until there a key is pressed.	
	
}


#endif

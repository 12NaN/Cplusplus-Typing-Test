#ifndef TEST
#define TEST
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <conio.h>
#include <fstream>
#include  "leaderboard.h"
class Test
{
	public:
		void start();
		void results(int, int);	
};

void Test::start()
{
	int words_typed_length = 0;
	int incorrect_words = 0;
	std::string word, answer, n;
	std::ifstream dict ("Dictionary.txt");
	std::vector<std::string> words;
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(60);
	
	std::cout << "You have one minute to test your typing speed. When you are ready to start, press any key...\n";
	system("pause>nul");
	
	if (dict.fail())
	{
		std::cout << "Error. Press any key to exit.\n";
		getch();
		return;
	}
	else if(dict.is_open())
	{
		while(getline(dict, word) && !(std::chrono::steady_clock::now() > tend))
		{
			words.push_back(word);
			srand(time(NULL));
			n = words[rand() % words.size()];
			std::cout << n << std::endl;
			std::cin >> answer;
			words_typed_length = words_typed_length + (sizeof(word));
			if(answer != n)
			{
				incorrect_words = incorrect_words + (sizeof(n)/sizeof(word));
				std::cout << "\aIncorrect\n\n" << std::endl;
				std::cout << n << std::endl;				
				std::cin  >> answer;	
			}	
		}
		dict.close();
		std::cout << "TIME! Press any key to continue and see your results!\n";
		system("pause>nul");
		results(words_typed_length, incorrect_words);
	}	
}
void Test::results(int x, int y)
{
	Leaderboard lb_update;
	int Gross_WPM = 0;
	
	Gross_WPM = (x/5)/ 1.0;
	std::cout << "==============================\n"
		 << "=          Results           =\n"
		 << "==============================\n"
		 << "Characters typed: " << x << "\n"
		 << "Incorrect words: " << y << "\n"
		 << "Gross WPM: " << Gross_WPM << "\n"
	     << "Press any key to return to the main menu...\n";
	lb_update.leaderboard(Gross_WPM);

	system("pause>nul");
	system("cls");
		 
}

#endif

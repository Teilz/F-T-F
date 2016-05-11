#include <iostream>
#include "klava.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <windows.h>

void mainLoop (clock_t delay);

int main() {
	srand (time (NULL) + rand ());
	const int size = 7;
	int difficulty;
	float seconds;
	
	system ("color 3");
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);
	
	std::cout << "\t\tВыберите сложность дальнейшей работы:\n";
	std::cout << "Кнопка 1:  Режим смертного;\n";
	std::cout << "Кнопка 2:  Режим царя;\n";
	std::cout << "Кнопка 3:  Режим бога;\n";
	std::cout << "Кнопка 4:  Тайная кнопка;\n";
	std::cout << "... ";

	std::cin >> difficulty;
	
	switch (difficulty) {
		case 1:
			seconds = 10;
			break;
			
		case 2:
			seconds = 7;
			break;
			
		case 3:
			seconds = 4;
			break;
			
			case 4:
			std::cout << "\nОго-го, какой ты хитрец... Там же было написано, не нажимать, а ты нажал?";
					Beep (659.26,200);
          Beep(1568, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1245, 1000);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1175, 1000);
			exit (0);
			
		default:
			std::cout << "\nОшибка, такого выбора нет.";
	
			exit (0);
	}
	
	std::cout << "Нажмите \"пробел\" чтобы очистить экран";
	getch();	
	system ("cls");
	clock_t delay = seconds * CLOCKS_PER_SEC;
	mainLoop (delay);
	
	return 0;
}

void mainLoop (clock_t delay) {	
	srand (time (NULL) + rand ());
	clock_t start = clock();
	const int buff = 100;
	int count = 0;
	
    std::string words [buff];
	std::ifstream myWords ("words.txt");
	
	for (; count < buff; count++) {
		myWords >> words [count];
		if (myWords.eof())
			break;
	}
		
	KEYS curKey = NOKEY;
	
	std::string curString = words [0 + rand () % count];
	std::string enteredString;
	
	while (clock() - start < delay ) {
		system ("cls");
		std::cout << "Таймер: " << clock() << "\n";
		std::cout << "-> " << curString;
	    curKey = keyPressed ();
		
		switch (curKey) {
			case a:
				enteredString += "a";
				break;
				
			case b:
				enteredString += "b";
				break;
				
			case c:
				enteredString += "c";
				break;
				
			case d:
				enteredString += "d";
				break;
				
			case e:
				enteredString += "e";
				break;
				
			case f:
				enteredString += "f";
				break;
				
			case g:
				enteredString += "g";
				break;
				
			case h:
				enteredString += "h";
				break;
				
			case i:
				enteredString += "i";
				break;
				
			case j:
				enteredString += "j";
				break;
				
			case k:
				enteredString += "k";
				break;
				
			case l:
				enteredString += "l";
				break;
			
			case m:
				enteredString += "m";
				break;
				
			case n:
				enteredString += "n";
				break;
				
			case o:
				enteredString += "o";
				break;
				
			case p:
				enteredString += "p";
				break;
				
			case q:
				enteredString += "q";
				break;
				
			case r:
				enteredString += "r";
				break;
				
			case s:
				enteredString += "s";
				break;
				
			case t:
				enteredString += "t";
				break;
				
			case u:
				enteredString += "u";
				break;
			
			case v:
				enteredString += "v";
				break;	
				
			case w:
				enteredString += "w";
				break;
				
			case x:
				enteredString += "x";
				break;
				
			case y:
				enteredString += "y";
				break;
				
			case z:
				enteredString += "z";
				break;
				
			default:
					if (curKey == space) {
						std::string source = "";
						enteredString = source;
					}
					curKey = NOKEY;
				break;
		}
		
		std::cout << "\n... " << enteredString;
		Sleep (100);
		 
		if (curString.size() == enteredString.size()) {
				if (curString  != enteredString ) {
					Beep(659.25,200);   
    				Beep(698.46,200);   
    				Beep(784,400);   
    				Beep(698.46,200);   
    				Beep(659.25,200);   
    				Beep(587.33,200);
					std::cout << "\nПровал!";
					system ("PAUSE >> NULL");
					exit (0);
				}
				else {
					Beep(247, 500);
                    Beep(417, 500);
                    Beep(417, 500);
                    Beep(370, 500);
                    Beep(417, 500);
                    Beep(329, 500);
					std::cout << "\nОтлично!";
					mainLoop (delay);
				}
		}
    }
    
    system ("cls");
    Beep (160, 220);
    std::cout << "Время вышло. Ты проиграл. Плачь.";
    system ("PAUSE >> NULL");
}

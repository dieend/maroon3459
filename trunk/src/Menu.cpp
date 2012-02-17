#include "Menu.h"
#include <iostream>
//additional includes


using namespace std;

Menu::Menu()
{
}

void Menu::display_main_menu() const 
{
	cout << "Here is the MAIN MENU \n";
}
void Menu::display_info() const
{
	cout << "Here is the Info requested \n";//display Project Part I, team name and team members
}

void Menu::read()
{
	cout << "Read file name then read store data \n";
	
}
void Menu::show() const 
{
	cout << "Show queries \n";
		
}
void Menu::find() const 
{
	cout << "Find queries \n";
}
void Menu::update()  
{
	cout << "Update queries \n";
}
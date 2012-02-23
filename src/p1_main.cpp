//============================================================================
// Name        : p1_main.cpp
// Authors     : Muhammad Adinata, Aldo Suwandi, Selvin Perez
// Version     : 0.8
// Copyright   : Your copyright notice
// Description : C++ project part 1  
//============================================================================
//

#include "Menu.h"
#include <stdlib.h>


using namespace std;

int main()
try {
   Menu m;
   int option;
  
   m.display_main_menu();
   do {
      cout << "> ";
	  while (!(cin >> option) || option < Menu::Info || option > Menu::Exit) {
         if (cin.fail()) {    // we found something that wasn’t an integer 
            cin.clear();      // enable us to look at the characters
            char ch;
            while (cin>>ch && !isdigit(ch)) {
               cerr << "Invalid input; please try again" << endl;
               cout << "> ";
            }
            cin.unget();
         } else {  // option < Menu::Info || option > Menu::Exit */
            cerr << "Invalid input; please try again" << endl;
            cout << "> ";
         }
      }
		system("cls");
			
      switch(option) { 
      case Menu::Info:
         m.display_info();
         break;
	  case Menu::Read:
         try {
            m.read();
         } catch (const Menu::InvalidFile& excp) {
            cerr << excp.what() << endl;
         } catch (const Menu::InvalidData& excp) {
            cerr << excp.what() << endl;
         }
         break;
	  case Menu::Find:
         m.find();
         break;
	  case Menu::Show:
         m.show();
         break;
	  case Menu::Update:
         m.update();
         break;
    case Menu::Exit:
         cout<<"Are you sure you want to exit?\nEnter 1 for yes OR 2 for no\n";
            int q;
            cin>>q;
            if (q==1)return 0;
            if (q==2)  main();
            else {
                cerr << "Invalid input" << endl;
                main();
             }
      }
	  
      m.display_main_menu();
   } while (option != Menu::Exit);
   return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;   
}
catch (...) {
	cerr << "unknown exception\n";
}



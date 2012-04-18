#include "DisplaySP.h"
#include <stdio.h>
vector<Cart> DisplaySP::Cart_v;
DisplaySP::DisplaySP() {	
		
}



void DisplaySP::display() {
	int repeat=0;
	int highest=0;
	for (int i = 0; i < Cart_v.size()-1 ; i++) {
		for (int j = i+1; j < (int)Cart_v.size() ; j++) {
			if (Cart_v[i].get_cust_id() == Cart_v[j].get_cust_id()) {
				repeat++;
				if(repeat>highest){
				highest = repeat;				
				Cart temp = Cart_v[i];
				Cart_v[i] = Cart_v[j];
				Cart_v[j] = temp;
				

				}
			}
		}	
	}

	string pesan1 = " Customer id: ";
	string pesan2 = " Cart id : ";
	string enter = "\n";
	string message[3];
	std::string ss;
	std::stringstream out;
	ss = out.str();
	for (int i = 0; i < 3;i++) {
		
		message[i].append(pesan1);
				out.str("");
		out << Cart_v[i].get_cust_id();
		message[i].append(out.str());
		message[i].append(enter);
		message[i].append(pesan2);
				out.str("");
		out << Cart_v[i].get_cart_id();
		message[i].append(out.str());
		message[i].append(enter);
		cout << message;


	}

	Graph_lib::Window ab(600, 400, "Display SP");
	ab.color(Color::white);

	Text msgx(Point(15,30), "Top 3 Most Frequent Customers");
	msgx.set_color(Color::black);
	ab.attach(msgx);

	Text msg(Point(15,50), message[0]);
	msg.set_color(Color::black);
	ab.attach(msg);

	Text msg1(Point(15,70), message[1]);
	msg1.set_color(Color::black);
	ab.attach(msg1);

	Text msg2(Point(15,90), message[2]);
	msg2.set_color(Color::black);
	ab.attach(msg2);


	bool val = true;
	while(val) {
		Fl::wait();
		if (!ab.active()) {
			val = false;
			cout << "Close";
			ab.detach(msg);
			Fl::redraw;
		}
	}
	
}


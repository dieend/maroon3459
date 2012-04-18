#include "DisplayAS.h"

vector<Cart_item> DisplayAS::Acart_items;

DisplayAS::DisplayAS() {	
		
}



void DisplayAS::display() {
	for (int i = 0; i < Acart_items.size()-1 ; i++) {
		for (int j = i+1; j < (int)Acart_items.size() ; j++) {
			if (Acart_items[i].get_prod_qty() < Acart_items[j].get_prod_qty()) {
				Cart_item temp = Acart_items[i];
				Acart_items[i] = Acart_items[j];
				Acart_items[j] = temp;
			}
		}	
	}
	for (int i = 0; i < Acart_items.size()-1 ; i++) {
		for (int j = i+1; j < (int)Acart_items.size() ; j++) {
			if (Acart_items[i].get_prod_qty() < Acart_items[j].get_prod_qty()) {
				Cart_item temp = Acart_items[i];
				Acart_items[i] = Acart_items[j];
				Acart_items[j] = temp;
			}
		}
		
	}
	string pesan1 = " Cart id : ";
	string pesan2 = " Item id : ";
	string pesan3 = " Product id : ";
	string pesan4 = " Prod Qty : ";
	string enter = "\n";
	string message[5];
	char as[10];
	std::string s;
	std::stringstream out;
	s = out.str();
	for (int i = 0; i < 5;i++) {
		
		message[i].append(pesan1);
		out << Acart_items[i].get_cart_id();
		message[i].append(out.str());
		message[i].append(enter);
		message[i].append(pesan2);
		out << Acart_items[i].get_item_id();
		message[i].append(out.str());
		message[i].append(enter);
		message[i].append(pesan3);
		out << Acart_items[i].get_prod_id();
		message[i].append(out.str());
		message[i].append(enter);
		message[i].append(pesan4);
		out << Acart_items[i].get_prod_qty();
		message[i].append(out.str());
		message[i].append(enter);
		cout << message;


	}

	Graph_lib::Window ab(600, 400, "Display AS");
	ab.color(Color::white);

	Text msgx(Point(15,30), "Top 5 Best Selling Products");
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

	Text msg3(Point(15,110), message[3]);
	msg3.set_color(Color::black);
	ab.attach(msg3);

	Text msg4(Point(15,130), message[4]);
	msg4.set_color(Color::black);
	ab.attach(msg4);

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


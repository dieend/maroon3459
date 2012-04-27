#include "GraphicsSP.h"
#include <stdio.h>
vector<Cart> GraphicsSP::cartsV;
vector<Cart_item> GraphicsSP::cart_itemsV;
GraphicsSP::GraphicsSP() {	
		
}



void GraphicsSP::display() {
	vector<int>cart_ids_by_date;
	vector<int>total_sales_by_date;
	int total=0;
	
		for (int m = 1; m < 13 ; m++) {
		for (int j =0; j < cartsV.size(); j++) {
			if(cartsV[j].get_date().month() == m){
				cart_ids_by_date.push_back(cartsV[j].get_cart_id());
				}
			}
		for (int a=0; a<(int)cart_ids_by_date.size(); a++) {
        		for (int b=0; b<(int)cart_itemsV.size();b++) {
        			if (cart_itemsV[b].get_cart_id() == cart_ids_by_date[a]) {
					total += cart_itemsV[b].get_prod_qty();
					}
				}
			}
			total_sales_by_date.push_back(total);
			total = 0;
			cart_ids_by_date.clear();	
		
		}
		
	Graph_lib::Window ab(600, 400, "Graphics SP");
	ab.color(Color::white);
	
	string enter = "\n";
	string message[12];
	std::string ss;
	std::stringstream out;
	ss = out.str();

	
	Text msgx(Point(150,50), "Total cart sales by month");
	msgx.set_color(Color::black);
	ab.attach(msgx);

  // position and size graph
	Point startPoint(100, 300);
	int xSize = 400;
	int ySize = 240;

	// generate the graph
	Axis xa(Axis::x, startPoint, xSize, total_sales_by_date.size() == 0 ? 1 : total_sales_by_date.size(), "Months");
	Axis ya(Axis::y, startPoint, ySize, 1, "Total sales");
	ab.attach(xa);
	ab.attach(ya);

	// width each bar
	int xPart = 0;
	if (cartsV.size() > 0) {
		xPart = xSize/12;
	}
	
	float barHeight;
	Graph_lib::Rectangle *barChart;
	Point *barChartPosition;

	Text *text;
	for (int i=0; i<total_sales_by_date.size(); ++i) {
		barHeight = total_sales_by_date[i];
		barChartPosition = new Point((startPoint.x + (i*xPart) + (xPart/2)), startPoint.y - barHeight);
		barChart = new Graph_lib::Rectangle(*barChartPosition, xPart, barHeight);
		barChart->set_color(Color::black);
		barChart->set_fill_color(2206020 + (10000 * i));
		ab.attach(*barChart);

	}

	bool val = true;
	while(val) {
		Fl::wait();
		if (!ab.active()) {
			val = false;
			cout << "Close";
			ab.detach(*barChart);
			ab.detach(xa);
			ab.detach(ya);
			Fl::redraw;
		}
	}
	
}


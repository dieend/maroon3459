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

    
  // position and size graph
    Point startPoint(100, 300);
    int xSize = 400;
    int ySize = 240;

    // generate the graph
    Axis xa(Axis::x, startPoint, xSize, 1, "Months");
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

    Text msgx(Point(250,50), "Total cart sales by month");
    msgx.set_color(Color::black);
    ab.attach(msgx);

    Text msg(Point(20,250), "Number of sales");
    msg.set_color(Color::black);
    ab.attach(msg);
    
    Text msg2(Point(300,350), "Month");
    msg2.set_color(Color::black);
    ab.attach(msg2);
    
    bool val = true;
    while(val) {
        Fl::wait();
        if (!ab.active()) {
            val = false;
            cout << "Close";
            ab.detach(*barChart);
            ab.detach(xa);
            ab.detach(ya);
            ab.detach(msgx);
            ab.detach(msg);
            Fl::redraw;
        }
    }
    
}



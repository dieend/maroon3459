/* 
 * File:   DisplayMA.cpp
 * Author: dieend
 * 
 * Created on April 18, 2012, 10:48 AM
 */

#include "DisplayMA.h"
#include "Product.h"

const vector<Cart>* DisplayMA::Acarts = NULL;
const vector<Cart_item>* DisplayMA::Acart_item = NULL;
const vector<Product>* DisplayMA::Aprod = NULL;
void DisplayMA::display(){
    if (Acarts == NULL || Acart_item == NULL || Aprod==NULL) return;
    
    const vector<Cart>& carts = *Acarts;
    const vector<Cart_item>& cart_items = *Acart_item;
    const vector<Product>& prods = *Aprod;
    
    vector<double> price(carts.size(),0.0);
    for (int i=0; i<(int)carts.size(); i++){
        for (int j=0; j<cart_items.size(); j++){
            if (carts[i].get_cart_id() == cart_items[j].get_cart_id()){
                const Product& p = prods[Product::getProductById(prods, cart_items[j].get_prod_id())];
                const Cart_item& c = cart_items[j];
                price[i] += c.get_prod_qty() * p.product_cost();
            }
        }
    }
    
    int m = 0;
    for (int i=0; i < (int)carts.size(); i++){
        if (price[m] < price[i]){
            m = i;
        }
    }
    int s = carts.size();
    //const Cart& bestcart = carts[m];
    stringstream message;
    
    Graph_lib::Window ab(600, 400, "Display MA");
    ab.color(Color::white);
    Text* msgx;
    vector<Text*> tmp;
    message << "Cart information with the largest check out total";
    msgx = new Text(Point(15,30), message.str());
    msgx->set_color(Color::black);
    tmp.push_back(msgx);
    ab.attach(*msgx);
    message.str("");
    
    message << "Cart id: " << carts[m].get_cart_id();
    msgx = new Text(Point(15,50), message.str());
    msgx->set_color(Color::black);
    tmp.push_back(msgx);
    ab.attach(*msgx);
    message.str("");
//    
    message << "items:";
    msgx = new Text(Point(15,70), message.str());
    msgx->set_color(Color::black);
    tmp.push_back(msgx);
    ab.attach(*msgx);
    message.str("");
    
    int cnt = 0;
    for (int i=0; i<(int)cart_items.size(); i++){
        if (cart_items[i].get_cart_id() == carts[m].get_cart_id()){
            cnt++;
            const Cart_item& c =cart_items[i];
            const Product& p = prods[Product::getProductById(prods, c.get_prod_id())];
            message << p.get_name() << "\tx" << c.get_prod_qty() << "\t@" << p.product_cost();
            msgx = new Text(Point(15,70+20*cnt), message.str());
            msgx->set_color(Color::black);
            tmp.push_back(msgx);
            ab.attach(*msgx);
            message.str("");
        }
    }
    message << "Total: " << price[m];
    msgx = new Text(Point(15,90+cnt*20), message.str());
    msgx->set_color(Color::black);
    tmp.push_back(msgx);
    ab.attach(*msgx);
    message.str("");
    
    
    
    bool val = true;
    while(val) {
            Fl::wait();
            if (!ab.active()) {
                    val = false;
                    cout << "Close";
                    for (int i=0; i<(int)tmp.size(); i++){
                        ab.detach(*tmp[i]);
                    }
                    Fl::redraw;
            }
    }
    
}
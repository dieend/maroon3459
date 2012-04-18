/* 
 * File:   DisplayMA.h
 * Author: dieend
 *
 * Created on April 18, 2012, 10:48 AM
 */

#ifndef DISPLAYMA_H
#define	DISPLAYMA_H
#include <vector>
#include "Cart.h"
#include "Cart_item.h"
#include "Product.h"
#include "Simple_window.h"
#include <sstream>
using namespace std;
class DisplayMA {
public:
    static const vector<Cart>* Acarts;
    static const vector<Cart_item>* Acart_item;
    static const vector<Product>* Aprod;
    static void display();
private:

};

#endif	/* DISPLAYMA_H */


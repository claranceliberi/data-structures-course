//
// Created by ntwar on 1/28/2021.
//

#ifndef POLYMORPHISM_DISCOUNTSALE_H
#define POLYMORPHISM_DISCOUNTSALE_H


class DiscountSale : public Sale{
public:
    DiscountSale();
    DiscountSale( double thePrice, double theDiscount);

    double getDiscount() const;
    void setDiscount(double newDiscount);
    double bill() const;

private:
    double discount;
};

 DiscountSale::DiscountSale() : discount(0){}
 DiscountSale::DiscountSale(double thePrice, double theDiscount) : Sale(thePrice){
   discount = theDiscount;
 }


double DiscountSale::bill() const{
    double fraction = discount /100;
    return (1 - fraction) * getPrice();
}


double DiscountSale::getDiscount() const{
    return discount;
}

void DiscountSale::setDiscount(double newDiscount){
    discount = newDiscount;
}

#endif //POLYMORPHISM_DISCOUNTSALE_H

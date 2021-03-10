//
// Created by ntwar on 1/28/2021.
//

#ifndef POLYMORPHISM_SALE_H
#define POLYMORPHISM_SALE_H

class Sale{
public :
    Sale();
    Sale(double thePrice);

    double getPrice() const;
    virtual double bill() const;
    double savings(const Sale& other) const;

private:
    double price;
};

 Sale::Sale() : price(0){}
 Sale::Sale(double thePrice){
   price = thePrice;
 }


double Sale::savings(const Sale& other) const{
    return (bill() - other.bill());
}

double operator < (const Sale& first, const Sale& second){
    return (first.bill() < second.bill());
}

double Sale::getPrice() const{
    return price;
}

#endif //POLYMORPHISM_SALE_H


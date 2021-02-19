//
//  Costumer.hpp
//  Question #4
//
//  Created by Victor Serrano Reyes  on 04/02/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#ifndef Costumer_hpp
#define Costumer_hpp
#include <string>
#include <cstdio>
#include "Account.hpp"
class Customer{
private:
    std::string adress,name,dob;
    int card_number;
    int pin;
    void verifyPassword();
    Account cuentas[2];
};
#endif /* Costumer_hpp */

//
//  Bank.hpp
//  Question #4
//
//  Created by Victor Serrano Reyes  on 04/02/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <cstdio>
#include <string>
#include "Costumer.hpp"
#include "Account.hpp"
class Bank{
private:
    std::string code;
    std::string adress;
    void manages();
    void maintains();
    Customer costumer;
    Account cuenta;
};
#endif /* Bank_hpp */

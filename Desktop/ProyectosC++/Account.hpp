//
//  Account.hpp
//  Question #4
//
//  Created by Victor Serrano Reyes  on 04/02/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#include <string>
#include <cstdio>
class Account{
private:
    int numeber;
    float balance;
public:
    void deposit();
    void withdraw();
    void createTransaction();
};
#endif /* Account_hpp */

//
//  main.cpp
//  Revistas
//
//  Created by Victor Serrano Reyes on 30/12/19.
//  Copyright © 2019 Victor Serrano Reyes. All rights reserved.
//

#include <iostream>
#include "revclass.hpp"
using namespace std;
int main() {
    int n=1;
    int z=1;
    Ceditorial editorial[51];
    editorial[0].CapturaGeneral();
    while(n!=4){
        editorial[n].CapturaTodasRevistas();
        n+=1;
    }
    while(z!=4){
        editorial[z].ImprimeTodasRevistas();
        z+=1;
    }
    
    return 0;
}

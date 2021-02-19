//
//  main.cpp
//  Aritmética de Apuntadores
//
//  Created by Victor Serrano Reyes  on 02/06/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    double arreglo[15],*apr;
    for(int i=0;i<=15;i++){
        arreglo[i]=1.1+0.5;
    }
    apr=arreglo;
    for(int i=0;i<=15;i++){
        cout<<*(apr)--<<endl;
    }
    return 0;
}

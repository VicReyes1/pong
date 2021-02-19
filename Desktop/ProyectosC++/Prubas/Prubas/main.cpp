//
//  main.cpp
//  Prubas
//
//  Created by Victor Serrano Reyes  on 07/01/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    float faren,cel;
    cout<<"Ingresa la temperatura en farenheit"<<endl;cin>>faren;
    cel=(5*(faren-32)/9);
    cout<<"El calculo en celsius es: "<<cel<<endl;
    if (cel<=0){
        cout<<"El estado es solido!!"<<endl;
    }else if(cel>0 && cel<100){
        cout<<"El estado es liquido!!"<<endl;
    }else{
        cout<<"El estado es gaseoso!!"<<endl;
    }
    
}

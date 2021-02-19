//
//  main.cpp
//  Rectangulo
//
//  Created by Victor Serrano Reyes  on 09/06/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#include <iostream>
template<class T>
class CPuntos{
private:
    T p1a;
    T p1b;
    T p2a;
    T p2b;
public:
    CPuntos(T _p1a,T _p1b,T _p2a,T _p2b){
        p1a=_p1a;
        p1b=_p1b;
        p2a=_p2a;
        p2b=_p2b;
    }
    T nuevopunto(T,T);
};
template<class T>
T CPuntos<T>::nuevopunto(T _nuevoA,T _nuevoB){
    T A=_nuevoA;
    T B=_nuevoB;
    if (A>p1a && B>p2b){
        std::cout<<"No se puede crear, fuera de rango  "<<std::endl;
    }else if (A>p2a&& B>p1b){
        std::cout<<"No se puede crear, fuera de rango  "<<std::endl;
    }
    return 0;
}
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,a2,b2,nuevoA,nuevoB;
    cout<<"Ingresa punto en a :"<<endl;
    cin>>a;
    cout<<"Ingresa punto en b :"<<endl;
    cin>>b;
    cout<<"Ingresa punto en a2 :"<<endl;
    cin>>a2;
    cout<<"Ingresa punto en b2 :"<<endl;
    cin>>b2;
    CPuntos<int> Recta(a,b,a2,b2);
    cout<<"Rectangulo generado "<<endl;
    cout<<"Puntos a evaluar "<<endl;
    cout<<"Ingresa nuevo punto en a :"<<endl;
    cin>>nuevoA;
    cout<<"Ingresa  nuevo punto en b :"<<endl;
    cin>>nuevoB;
    Recta.nuevopunto(nuevoA,nuevoB);
    
       return 0;
}

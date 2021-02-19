//
//  revclass.cpp
//  Revistas
//
//  Created by Victor Serrano Reyes on 30/12/19.
//  Copyright © 2019 Victor Serrano Reyes. All rights reserved.
//

#include "revclass.hpp"
#include <iostream>
using namespace std;
Ceditorial::Ceditorial(){
    name="";
    canti=0;
    
}
Ceditorial::~Ceditorial(){
    
}
void Ceditorial::CapturaGeneral(){
    name="";
    canti=0;
    cout<<"Ingresa el nombre de la editorial: ";cin>>name;
    cout<<"Ingresa la cantidad de libros: ";cin>>canti;
}
void Ceditorial::CapturaTodasRevistas(){
    name="";
    canti=0;
    cout<<"Ingresa el nombre de la revista: ";cin>>name;
    cout<<"Ingresa el numero de páginas: ";cin>>canti;
}
void Ceditorial::ImprimeTodasRevistas(){
    cout<<"El nombre de la revista es: "<<name<<endl;
    cout<<"Y el número de paginas es:\n\n "<<canti<<endl;
}

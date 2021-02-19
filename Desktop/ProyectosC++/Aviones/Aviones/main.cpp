//
//  main.cpp
//  Aviones
//
//  Created by Victor Serrano Reyes  on 08/01/20.
//  Copyright © 2020 Victor Serrano Reyes . All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
void pesoAviones(float pesoAvionesArr[50]);
void calcularDispersiones(float &varianza,float &des,float pesAviones[50]);
void consultarAvion(float pesoAvionesArr[50]);
void cambiarPeso(float pesoAvionesArr[50]);
void ordenarArray(float pesoAvionesArr[50]);
int main(){
    float pesoAvionesArr[50],varianza=0, des=0;
    int n=0,op;
    pesoAviones(pesoAvionesArr);
    while (n!=1){
        cout<<"Escoge las siguientes opciones del menu:\n<0> Salir (Termina el programa)\n<1> Calcular desviación estandar y varianza\n<2> Consultar el peso del i-esimo avión \n<3> Cambiar el valor de un elemento del arreglo\n<4>Ordenar los valores del arreglo"<<endl;cin>>op;
        if(op==0){
            n+=1;
        }else if(op==1){
            calcularDispersiones(varianza, des, pesoAvionesArr);
        }else if (op==2){
            consultarAvion(pesoAvionesArr);
        }else if (op==3){
            cambiarPeso(pesoAvionesArr);
        }else if(op==4){
            
        }
    }
    return 0;
}
void pesoAviones(float pesoAvionesArr[50]){
    int x;
    for(x=0;x<50;x++){
        pesoAvionesArr[x]=5+rand()%1001-5;
    }
}
void calcularDispersiones(float &varianza,float &des,float pesoAvionesArr[50]){
    float suma=0,prom=0,s=0;
    int x;
    for (x=0;x<50;x++){
        suma+=pesoAvionesArr[x];
    }
    prom=(suma/50);
    for(x=0;x<50;x++){
        s+=pow((prom-pesoAvionesArr[x]),2);
    }
    varianza=s/49;
    des=sqrt(s/49);
    cout<<"La varianza del peso de los aviones es: "<<varianza<<endl;
    cout<<"La desviacion estandar es: "<<des<<endl;
}
void consultarAvion(float pesoAvionesArr[50]){
    int selc,n=0;
    while (n!=1){
    cout<<"Indice del avion a consultar : ";cin>>selc;
        if (selc<50){
            cout<<"El peso del avión número: "<<selc<<".- es: "<<pesoAvionesArr[selc]<<endl;
            n+=1;
        }else if (selc>=50){
            cout<<"Ingrese de nueva cuenta el avion a consultar"<<endl;
        }
    }
}
void cambiarPeso(float pesoAvionesArr[50]){
    int selc,n=0;
    float val;
    while (n!=1){
       cout<<"Indice del avion a consultar para cambiar : ";cin>>selc;
           if (selc<50){
               cout<<"El peso del avión número: <"<<selc<<"> es: "<<pesoAvionesArr[selc]<<endl;
               cout<<"Ingrea el nuevo valor: ";cin>>val;
               if (val>=5&&val<=1000){
                   pesoAvionesArr[selc]=val;
                   n+=1;
               }else{
                   cout<<"Valor no válido"<<endl;
               }
           }else if (selc>=50){
               cout<<"Ingrese de nueva cuenta el avion a consultar"<<endl;
           }
       }
}
void ordenarArray(float pesoAvionesArr[50]){
    int x;
    float otroArray[50];
    for(x=0;x<50;x++){
        if (pesoAvionesArr[x]>otroArray[x]){
            
    }
}
}

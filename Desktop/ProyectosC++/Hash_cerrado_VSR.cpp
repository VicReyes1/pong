#include <iostream>
using namespace std;
class TablaHashCerrada{
public:
    int propietario;
    int noTarjeta;
    int CLABE;
   
    TablaHashCerrada(){
        propietario = 0;
        noTarjeta = 0;
        CLABE = 0;
    }
    void obtenDatos(int _propietario, int _noTarjeta, int _CLABE){
        propietario = _propietario;
        noTarjeta = _noTarjeta;
        CLABE = _CLABE;
    }
    
};

bool validarPrimo(int n){
    bool var;
    for (int i = 2; i < n; i++)
    {
        if ((n % i == 0) && (n != i) && (n < 50))
        {
            var = false;
            break;
        }
        else
        {
            var = true;
        }
        
        
    }
    return var;
    
};
int main(){
    int num = 0, numRandom,op;
    int contadorFull = 0;
    srand((unsigned)time(NULL));
    while (true)
    {
        cout<<"Ingresa un numero, para el tamanio de la tabla Hash"<<endl;
        
        cout<<"Numero: ";cin>> num;
        if (validarPrimo(num) == false)
        {
            cout<<"El número no es un número primo o es mayor a 50, intente con uno nuevo"<<endl;
        }
        else
        {
            break;
        }
        
         
    }
    

    TablaHashCerrada listaHash[50];
    while (true)
    {
        if (contadorFull >= ((num * 60)/100)){
                    cout<<"¡¡¡La tabla Hash tiene una capacidad mayor al 60% puede ser que su redimiento se vea afectado!!!"<<endl<<endl;
        }
        cout<<"         PROGRAMA DE HASH CERRADO "<<endl<<endl;;
        cout<<"1.- Ingresar Nuevos datos cliente \n 2.- Buscar una cliente \n 3.- Mostrar todos los elementos \n 4.- Salir"<<endl;
        cout<<"Opcion: ";cin>>op;
        if (op == 1){
            if (contadorFull >= ((num * 60)/100)){
                    cout<<"¡¡¡La tabla Hash tiene una capacidad mayor al 60% puede ser que su redimiento se vea afectado!!!"<<endl<<endl;
            }
            int noTarjeta;
            int CLABE;
            cout<<"Ingresa No.Tarjeta: ";cin>>noTarjeta;
            cout<<"Ingresa CLABE interbancaria: ";cin>>CLABE;
            cout<<"Generando id de propietario aletaroriamente... "<<endl;
            numRandom = rand()%150 + 1;
            cout<<"El id es: "<<numRandom<<endl;
            while (true)
            {
               
                if (listaHash[numRandom % num].propietario == 0)
                {
                    listaHash[numRandom % num].obtenDatos(numRandom,noTarjeta,CLABE);
                    cout<<"El dato ha sido guardado con éxito "<<endl;
                    contadorFull +=1;
                    break;
                }
                else
                {
                    numRandom += 1;
                    cout<<"La clave para el usuario con No.Tarjeta: "<<noTarjeta<<" ha cambiado"<<endl;
                    cout<<"Su nueva clave(id) es: "<<numRandom<<endl;;
                }
                
                
            }
            
        }else if(op == 2){
            if (contadorFull >= ((num * 60)/100)){
                    cout<<"¡¡¡La tabla Hash tiene una capacidad mayor al 60% puede ser que su redimiento se vea afectado!!!"<<endl<<endl;
            }
            int id;
            cout<<"Ingrese la clave(id), de el cliente a buscar: ";cin>>id;
            while (true)
            {
                if (listaHash[id % num].propietario == 0)
                {
                    cout<<"El usuario y esa tarjeta no existen "<<endl;
                    break;
                }
                else
                {
                    cout<<"___________________________"<<endl;
                    cout<<"El id del cliente es : "<<listaHash[id % num].propietario<<endl;
                    cout<<"Su numero de tarjeta es: "<<listaHash[id % num].noTarjeta<<endl;
                    cout<<"Su CLABE interbancaria es: "<<listaHash[id % num].CLABE<<endl;
                    cout<<"___________________________"<<endl;
                    break;
                }
                
                
            }
            
        }else if(op == 3){
            if (contadorFull >= ((num * 60)/100)){
                    cout<<"¡¡¡La tabla Hash tiene una capacidad mayor al 60% puede ser que su redimiento se vea afectado!!!"<<endl<<endl;
            }
            for (int i = 0; i < num; i++)
            {
                if (listaHash[i].propietario != 0)
                {
                    cout<<"___________________________"<<endl;
                    cout<<"El id del cliente es : "<<listaHash[i].propietario<<endl;
                    cout<<"Su numero de tarjeta es: "<<listaHash[i].noTarjeta<<endl;
                    cout<<"Su CLABE interbancaria es: "<<listaHash[i].CLABE<<endl;
                    cout<<"___________________________"<<endl;
                }
                
            }
            
        }else if(op == 4){
            break;
        }
        else
        {
            cout<<"Opcion no valida "<<endl;
        }
    }    
    return 0;
}
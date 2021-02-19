#include <iostream>
using namespace std;
class ClistaHash{
public:
    string contrasenia[50] = {""};
    int cuenta;
    int clave;
    ClistaHash(){
        cuenta = 0;
    }
    void insertarContra(string _contrasenia,int _clave){
        contrasenia[cuenta] = _contrasenia;
        cout<<"Guardando contraseña en Hash"<<endl;
        clave = _clave;
        cuenta+=1;
    }
    bool buscaContra(int index,string _contrasenia2){
        if (contrasenia[index] == _contrasenia2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    bool chequeoNulo(int _i){
        if (contrasenia[_i] != "")
        {
            return  false;
        }else
        {
            return true;
        }
        

        
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
    string contrasenia2;
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
    
    ClistaHash listaAbierta[50];
    int clave;
    while (true)
    {
        cout<<"PROGRAMA DE HASH ABIERTO "<<endl;
        cout<<"1.- Ingresar Nueva contraseña \n 2.- Buscar una contraseña \n 3.- Mostrar todos los elementos \n 4.- Salir"<<endl;
        cout<<"Opcion: ";cin>>op;
        if (op == 1){

            cout<<"Ingresa la contraseña "<<endl;
            numRandom = rand()%150 + 1;
            cout<<"Clave asiganda: "<<numRandom<<endl;
            cout<<"Ingrese la contraseña a guardar: ";cin>>contrasenia2;
            listaAbierta[numRandom % num].insertarContra(contrasenia2,numRandom);
            cout<<"¡Contraseña guardada con éxito!"<<endl;
            
        }
        else if(op == 2){
            cout<<"Ingresa tu contraseña a buscar: ";cin>>contrasenia2;
            cout<<"Ingresa la clave asignada: ";cin>>clave;
            for (int i = 0; i <= listaAbierta[clave % num].cuenta; i++)
            {
                if (listaAbierta[clave % num].contrasenia[i] == contrasenia2)
                {
                    cout<<"___________________________"<<endl;
                    cout<<"La contraseña: "<<contrasenia2<<" SI EXISTE"<<endl;;
                    cout<<"Ubicación en tabla Hash: "<<clave % num<<endl;
                    cout<<"La clave asinada es: "<<clave<<endl;
                    cout<<"___________________________"<<endl;
                    break;
                }else if((i == listaAbierta[clave % num].cuenta) && (contrasenia2 != listaAbierta[clave % num].contrasenia[i]) ){
                    cout<<"¡La contraseña no existe en tabla Hash! "<<endl;
                }
                
            }
            
            
        }else if(op == 3){
            for (int i = 0; i < num; i++)
            {
                for (int i2 = 0; i2 <= listaAbierta[i].cuenta; i2++)
                {
                    if (listaAbierta[i].chequeoNulo(i2) == false )
                    {
                        cout<<"___________________________"<<endl;
                        cout<<"Posicion en Tabla Hash: "<<i<<endl;
                        cout<<"Posicion dentro de el indice: "<<i2<<endl;
                        cout<<"Contra: "<<listaAbierta[i].contrasenia[i2]<<endl;
                        cout<<"La clave asinada es: "<<listaAbierta[i].clave<<endl;
                        cout<<"___________________________"<<endl;
                    }
                    
                }
                
            }
            
        }
        else if(op == 4){
            break;
        }
        else
        {
            cout<<"Opcion no valida "<<endl;
        }
        
    }
    
    
    return 0;
}
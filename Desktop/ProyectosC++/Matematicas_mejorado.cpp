#include <iostream>
using namespace std;
void creaMat(int mat[51][51], int _dimension, int vector[51]){
    int valor;
    for (int i = 0; i < _dimension; i++)
    {
        for (int y = 0; y < _dimension; y++)
        {
            cout<<"Ingresa el valor para ["<<i<<"] "<<"["<<y<<"]: ";cin>>valor;
            mat[i][y] = valor;
        }
        
    }

    
    
}

void imprimeMat(int mat[51][51], int _dimension){
    cout<<"[";
    for (int i = 0; i < _dimension; i++)
    {
        for (int y = 0; y < _dimension; y++)
        {
            cout<<mat[i][y]<<", ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}

void creaVector(int n,int mat[51][51], int vector[51]){
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < n; y++)
        {
            vector[(n*i)+y] = mat[i][y];
        }
        
    }

    cout<<"Imprimiendo vector creado a partir de la matriz... "<<endl;
    cout<<"[";
    for (int x = 0; x < (n*n); x++)
    {
        cout<<vector[x]<<" ";
    }
    cout<<"]"<<endl;
}

void operacionesVector(int vector1[51], int vector2[51],int dimension, int _op){
    if (_op == 1)
    {
        int vectorC[dimension*dimension];
        cout<<"Vector resultante de la suma "<<endl;
        cout<<"[ ";
        for (int i = 0; i < dimension*dimension; i++)
        {

            vectorC[i] = vector1[i]+vector2[i];
            cout<<vectorC[i]<<" ";
        }
        cout<<"]"<<endl;

        cout<<"Cambio a bidimencional"<<endl;
        int matrizC[dimension][dimension];
        for (int i = 0; i < dimension * dimension; i++)
        {
            matrizC[i / dimension][i % dimension] = vectorC[i];
        }
        cout<<"[";
        for (int i = 0; i < dimension; i++){

            for (int y = 0; y < dimension; y++){

                cout<<matrizC[i][y]<<", ";
            }
        cout<<endl;
        }
        cout<<"]"<<endl;
     
    }else if(_op == 2){
        int vectorC[dimension*dimension];
        cout<<"Vector resultante de la resta "<<endl;
        cout<<"[ ";
        for (int i = 0; i < dimension*dimension; i++)
        {

            vectorC[i] = vector1[i]-vector2[i];
            cout<<vectorC[i]<<" ";
        }
        cout<<"]"<<endl;

        cout<<"Cambio a bidimencional"<<endl;
        int matrizC[dimension][dimension];
        for (int i = 0; i < dimension * dimension; i++)
        {
            matrizC[i / dimension][i % dimension] = vectorC[i];
        }
        cout<<"[";
        for (int i = 0; i < dimension; i++){

            for (int y = 0; y < dimension; y++){

                cout<<matrizC[i][y]<<", ";
            }
        cout<<endl;
        }
        cout<<"]"<<endl;
    }else
    {
        int vectorC[dimension*dimension];
        cout<<"Vector resultante de la multiplicacion "<<endl;
        cout<<"[ ";
        int x=0, x2=0, multiplicador=0;
        while (x < (dimension * dimension))
        {
            vectorC[x] += vector1[x]+vector2[x+(dimension*multiplicador)];
            cout<<vectorC[x]<<" ";
            if (multiplicador == (dimension - 1))
            {
                x++;
                multiplicador = 0;
            }else{
                multiplicador++;
            }
            
        }
        cout<<"]"<<endl;
        

        cout<<"Cambio a bidimencional"<<endl;
        int matrizC[dimension][dimension];
        for (int i = 0; i < dimension * dimension; i++)
        {
            matrizC[i / dimension][i % dimension] = vectorC[i];
        }
        cout<<"[";
        for (int i = 0; i < dimension; i++){

            for (int y = 0; y < dimension; y++){

                cout<<matrizC[i][y]<<", ";
            }
        cout<<endl;
        }
        cout<<"]"<<endl;
    }
    
}

int main(){
    int op;
    int matrizA[51][51],matrizB[51][51], dimension, vectorA[51], vectorB[51];
    cout<<"Ingresa la dimension de las matrices cuadradas (max: 50): "; cin>>dimension;
    cout<<"Primera Matriz: "<<endl;
    creaMat(matrizA,dimension,vectorA);
    imprimeMat(matrizA,dimension);
    cout<<"Conversion a vector: "<<endl;
    creaVector(dimension,matrizA,vectorA);

    cout<<"Segunda Matriz: "<<endl;
    creaMat(matrizB,dimension,vectorB);
    imprimeMat(matrizB,dimension);
    cout<<"Conversion a vector: "<<endl;
    creaVector(dimension,matrizB,vectorB);

    while (true)
    {
        cout<<"Operación a realizar \n 1.- Suma \n 2.- Resta \n 3.- Multiplicacion \n 0.- Salir "<<endl;
        cout<<"Opcion: ";cin>>op;

        if ( op == 0)
        {
            break;
        }else
        {
            operacionesVector(vectorA,vectorB,dimension,op);
        }
        
        
    }
    return 0;
}
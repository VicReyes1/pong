#include <iostream>
using namespace std;

class pruebaC
{
private:
    int num;
public:
    pruebaC();
    ~pruebaC();
    void saludar();
};

pruebaC::pruebaC()
{
    num = 5;
};

pruebaC::~pruebaC()
{
};
void pruebaC::saludar(){
    cout<<"Hola mundo "<<endl;
};

int main(){
    pruebaC unaPrueba;
    unaPrueba.saludar();

};

#include <iostream>
using namespace std;

struct nodo{
            string  ciudadNombre;//nombre del vertice o nodo
            bool estatus;
            struct nodo *sgte;
            struct arista *ady;//puntero hacia la primera arista del nodo
            };

struct arista{
              string  ciudadNombre;
              struct nodo *destino;//puntero al nodo de llegada
              struct arista *sgte;
              int peso;
              };
typedef struct nodo *Tnodo;//  Tipo Nodo
typedef struct arista *Tarista; //Tipo Arista

class pila {
public:
    //Inicializa el elemento ultimo
    pila() : ultimo(NULL) {}
    ~pila();

    void Push(nodo* registro);
    nodo* Pop();

private:
    Tnodo ultimo;
};

//Su desctructor, elimina el elemento que se ha sacado de la pila
pila::~pila()
{
    Tnodo aux;
    while (ultimo) {
        aux = ultimo;
        ultimo = ultimo->sgte;
        delete aux;
    }
}


void pila::Push(nodo* registro)
{
    Tnodo nuevo;
    nuevo = new struct nodo;
    ultimo = nuevo;
}
nodo* pila::Pop()
{
    Tnodo nodoN;
    nodo* v;
    if (!ultimo) return NULL;
    nodoN = ultimo;
    ultimo = ultimo->sgte;
    v = nodoN;
    delete nodoN;
    return v;
}

Tnodo p;

void menu();
void insertar_nodo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();
void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();
void busquedaProfunda();
/*                        Funcion Principal
---------------------------------------------------------------------*/
int main(void)
{   p=NULL;
    int op;
         // opcion del menu

    system("color 0b");

    do
    {
        menu();
        cin>>op;

        switch(op)
        {
            case 1:
                    insertar_nodo();
                    break;
            case 2: insertar_arista();
                    break;
            case 3: eliminar_nodo();
                    break;
            case 4: eliminar_arista();
                    break;
            case 5: mostrar_grafo();
                    break;
            case 6: mostrar_aristas();
                    break;
            case 7: busquedaProfunda();
                    break;
            default: cout<<"OPCION NO VALIDA...!!!";
                     break;


        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=8);
    return 0;
}

/*                          Menu
---------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
    cout <<"1. Agregar una nueva ciudad      " << endl;
    cout <<"2. Asignar un tiempo a un recorrido" << endl;
    cout<<"3. Eliminar ciudad                "<<endl;
    cout<<"4. Eliminar arista             "<<endl;
    cout <<"5. Mostrar todos los reccoridos disponibles" << endl;
    cout<<"6. Mostrar aristas de un nodo       "<<endl;
    cout<<"7. Busqueda de Profunidad                          "<<endl;
    cout<<"8. Salir "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertar_nodo()
{
    Tnodo t,nuevo=new struct nodo;
    cout<<"INGRESE VARIABLE:";
    cin>>nuevo->ciudadNombre;
    nuevo->estatus = false;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(p==NULL)
     {
        p = nuevo;
        cout<<"PRIMER NODO...!!!";
      }
    else
     {
        t = p;
        while(t->sgte!=NULL)
         {
            t = t->sgte;
          }
        t->sgte = nuevo;
        cout<<"NODO INGRESADO...!!!";
      }

 }

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo, int _peso)
{
    Tarista q;
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        aux->ady->peso = _peso;
        nuevo->destino=aux2;
        cout<<"PRIMERA ARISTA....!";
    }
    else
    {   q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;  
        nuevo->destino=aux2;
        q->sgte=nuevo;
        nuevo->peso = _peso;
        cout<<"ARISTA AGREGADA...!!!!";
    }

}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista()
{   string ini, fin;
    int peso2;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;

    if(p==NULL)
     {
         cout<<"GRAFO VACIO...!!!!";
         return;
     }
    nuevo->sgte=NULL;
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    cout<<"INGRESE EL TIEMPO (PESO): ";
    cin>>peso2;
    aux=p;
    aux2=p;
    while(aux2!=NULL)
    {
        if(aux2->ciudadNombre == fin)
        {
            break;
        }

        aux2=aux2->sgte;
        
    }
    while(aux!=NULL)
    {
        if(aux->ciudadNombre == ini)
        {
            agrega_arista(aux,aux2, nuevo, peso2);
            return;
        }

        aux = aux->sgte;
    }
}

/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
    esta funcion es utilizada al borrar un nodo pues si tiene aristas
    es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void vaciar_aristas(Tnodo &aux)
{
    Tarista q,r;
    q=aux->ady;
    while(q->sgte!=NULL)
    {
        r=q;
        q=q->sgte;
        delete(r);
    }
}
/*                      ELIMINAR NODO
    funcion utilizada para eliminar un nodo del grafo
    pero para eso tambien tiene que eliminar sus aristas por lo cual
    llama a la funcion vaciar_aristas para borrarlas
---------------------------------------------------------------------*/
void eliminar_nodo()
{   string var;
    Tnodo aux,ant;
    aux=p;
    cout<<"ELIMINAR UN NODO\n";
    if(p==NULL)
     {
         cout<<"GRAFO VACIO...!!!!";
         return;
     }
    cout<<"INGRESE NOMBRE DE VARIABLE:";
    cin>>var;

    while(aux!=NULL)
    {
        if(aux->ciudadNombre == var)
        {
            if(aux->ady!=NULL)
                vaciar_aristas(aux);

            if(aux==p)
            {

                    p=p->sgte;
                    delete(aux);
                    cout<<"NODO ELIMINADO...!!!!";
                    return;



            }
            else
            {
                ant->sgte = aux->sgte;
                delete(aux);
                cout<<"NODO ELIMINADO...!!!!";
                return;
            }
        }
        else
        {
            ant=aux;
            aux=aux->sgte;
         }
    }

}

/*                      ELIMINAR ARISTA
    funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
void eliminar_arista()
{
    string ini, fin;
    Tnodo aux, aux2;
    Tarista q,r;
    cout<<"\n ELIMINAR ARISTA\n";
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL)
    {
        if(aux2->ciudadNombre == fin)
        {
            break;
        }
        else
        aux2=aux2->sgte;
    }
     while(aux!=NULL)
    {
        if(aux->ciudadNombre == ini)
        {
            q=aux->ady;
            while(q!=NULL)
            {
                if(q->destino==aux2)
                {
                    if(q==aux->ady)
                        aux->ady=aux->ady->sgte;
                    else
                        r->sgte=q->sgte;
                    delete(q);
                    cout<<"ARISTA  "<<aux->ciudadNombre<<"----->"<<aux2->ciudadNombre<<" ELIMINADA.....!!!!";
                    return;
                }
            }
            r=q;
            q=q->sgte;
        }
        aux = aux->sgte;
    }
}
/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrar_grafo()
{   Tnodo ptr;
    Tarista ar;
    ptr=p;
    cout<<"NODO|LISTA DE ADYACENCIA\n";

    while(ptr!=NULL)
    {   cout<<"   "<<ptr->ciudadNombre<<"|";
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;
            while(ar!=NULL)
            {   cout<<" "<<ar->destino->ciudadNombre<<"("<<ar->peso<<")";
                ar=ar->sgte;
             }

        }
        ptr=ptr->sgte;
        cout<<endl;
    }
}

/*                      MOSTRAR ARISTAS
    funcion que muestra todas las aristas de un nodo seleccionado
---------------------------------------------------------------------*/
void mostrar_aristas()
{
    Tnodo aux;
    Tarista ar;
    string var;
    cout<<"MOSTRAR ARISTAS DE NODO\n";
    cout<<"INGRESE NODO:";
    cin>>var;
    aux=p;
    while(aux!=NULL)
    {
        if(aux->ciudadNombre == var)
        {
            if(aux->ady==NULL)
            {   cout<<"EL NODO NO TIENE ARISTAS...!!!!";
                return;
             }
            else
            {
                cout<<"NODO|LISTA DE ADYACENCIA\n";
                cout<<"   "<<aux->ciudadNombre<<"|";
                ar=aux->ady;

                while(ar!=NULL)
                {
                    cout<<ar->destino->ciudadNombre<<"("<<ar->peso<<")"<<" ";
                    ar=ar->sgte;
                }
                cout<<endl;
                return;
            }
        }
        else
        aux=aux->sgte;
    }
}
void busquedaProfunda(){
    Tnodo aux;
    nodo* aux2;
    Tarista ar;
    pila miPila;
    aux = p;
    miPila.Push(aux);
    aux2 = aux;
    while (true)
    {
        if (aux->estatus == false && (aux2))
        {
            aux2 = miPila.Pop();
            cout<<aux2->ciudadNombre<<endl;
            cout<<"____________________"<<endl;
            aux2->estatus = true;
            while (aux != NULL)
            {
                if (aux->ady != NULL)
                {
                    ar = aux->ady;
                    while (ar != NULL && ar->peso > 0)
                    {
                        miPila.Push(ar->destino);
                        ar=ar->sgte;   
                    }
                    
                }
                aux = ar->destino;
                
                
            }
            
            
            
        }else if(aux ->estatus == true && (aux2)){
            aux2 = miPila.Pop();
            while (aux != NULL)
            {
                if (aux->ady != NULL)
                {
                    ar = aux->ady;
                    while (ar != NULL && ar->peso > 0)
                    {
                        miPila.Push(ar->destino);
                        ar=ar->sgte;   
                    }
                    
                }
                aux = ar->destino;
                
                
            }
       
        
        }else
        {
            break;
        }
        
     
  
    }
}

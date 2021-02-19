class pila {
public:
    //Inicializa el elemento ultimo
    pila() : ultimo(NULL) {}
    ~pila();

    void Push(ciudad* registro);
    ciudad* Pop();

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


void pila::Push(ciudad* registro)
{
    Tnodo nuevo;
    nuevo = new struct nodo;
    ultimo = nuevo;
}
ciudad* pila::Pop()
{
    Tnodo nodo;
    ciudad* v;
    if (!ultimo) return NULL;
    nodo = ultimo;
    ultimo = ultimo->sgte;
    v = nodo->Ciudad;
    delete nodo;
    return v;
}

void busquedaProfunda(){
    Tnodo aux;
    ciudad *aux2;
    Tarista ar;
    pila miPila;
    aux = p;
    miPila.Push(aux->Ciudad);

    while (aux2)
    {
        while(aux!=NULL){
            if (aux->ady == NULL)
            {
                aux2 = miPila.Pop();
                if (aux2->estatutus == false)
                {
                    cout<<aux2->nombre<<endl;
                    cout<<"_________________"<<endl;
                }
                
            }else
            {
                aux2 = miPila.Pop();
                cout<<aux2->nombre<<endl;
                cout<<"_________________"<<endl;
                aux2->estatutus = true;
                ar = aux->ady;
                while (ar != NULL)
                {
                    miPila.Push(ar->destino->Ciudad);
                    ar=ar->sgte;
                }
                
            }
            
            
        }
        
    }
    
}
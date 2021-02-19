#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class CFunko{
public:
    string nombre;
    string linea;
    int qr;
    int no_en_linea;
    int precio;
    CFunko(){
        nombre = "";
        linea = "";
        no_en_linea = 0;
        precio = 0;
    }
    void mostrarCaracteristicas(){
        cout<< "___________________"<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Linea a la que pertenece: "<<linea<<endl;
        cout<<"No: "<<no_en_linea<<endl;
    }
    void infoFunko(string _nombre, string _linea, int _no_en_linea, int _precio, int _qr){
        nombre = _nombre;
        linea = _linea;
        no_en_linea = _no_en_linea;
        precio = _precio;
        qr = _qr;
    }

};


class CUsuario{
private:
    string correo;
    string contrasenia;
public:
    string aliasUsuario;
    int idUsuario;
    int conta;
    CFunko miFunko[50];
    CUsuario(){
        correo = "";
        contrasenia = "";
        aliasUsuario = "";
        conta = 0;
    }
    
    void obtenerDatos(string _correo, string _contrasenia, string _aliasUsuario, int _idUsuario ){
        correo = _correo;
        contrasenia = _contrasenia;
        aliasUsuario = _aliasUsuario;
        idUsuario = _idUsuario;
    }
    
    bool comparaDatos(string _correoEntrada, string _contraEntrada){
        if ((correo == _correoEntrada) && (contrasenia == _contraEntrada))
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    void agregaFunko(CFunko _funko){
        miFunko[conta] = _funko;
        conta+=1;
    }
};
class Node {
public:
	Node(std::string name);
	virtual ~Node();
	void addChild(Node* child);
	std::string _name;
	Node* _first;
	Node* _last;
	Node* _next;
	int _depth;
	friend class Tree;
};
Node::Node(std::string name) :_name(name) ,_first(NULL), _last(NULL), _next(NULL), _depth(0)
{

}


Node::~Node()
{

}

void Node::addChild(Node *child)
{
	child -> _depth = _depth + 1;
    
	if(_first == NULL)
	{
		_first = child;
		_last = child;
	}else
	{
		_last -> _next = child; 
		
        _last = child; 
	}
}
class Tree {
public:
	Tree(Node* root);
	virtual ~Tree();
	void traverse();
	void traverse(Node* node);
private:
	Node* _root;
};

Tree::~Tree() {
	
}

Tree::Tree(Node *root) : _root(root)
{
}

void Tree::traverse(Node *node)
{
    
	for(int i = 0 ; i < node -> _depth ; i++)
	{
		cout << "\t";
	}
	cout << node -> _name << endl;
	Node* i = node -> _first; 
	while(i != NULL)
	{
		traverse(i);
		i = i -> _next;
	}
}


void Tree::traverse()
{
	traverse(_root);
}





int main(){
    srand((unsigned)time(NULL));
    CFunko funkos[50];
    int sumaUsuario = 0,op;
    funkos[0].infoFunko("Woody","Toy_Story",04,330,1);
    funkos[1].infoFunko("Mewtwo","Pokemon",05,399,2);
    funkos[2].infoFunko("The_Starchild - Kiss","Icons",07,599,3);
    funkos[3].infoFunko("Joker-1989","DC",03,299,4);
    Node* gp = new Node("Funkos");
    Node* Disney = new Node("Disney");
    Node* Pokemon = new Node("Pokemon");
    Node* Icons = new Node("Icons");
    Node* DC = new Node("DC");
    Node* Funko0 = new Node(funkos[0].nombre);
    Node* Funko1 = new Node(funkos[1].nombre);
    Node* Funko2 = new Node(funkos[2].nombre);
    Node* Funko3 = new Node(funkos[3].nombre);

    
    Tree* tree = new Tree(gp);
    gp->addChild(Disney);
    gp->addChild(Pokemon);
    gp->addChild(Icons);
    gp->addChild(DC);

    CUsuario usuarios[50];

    while (true)
    {
        cout<<"TU MUNDO FUNKO "<<endl<<endl;
    cout<< "(`;-.          ___,"<<endl;
    cout<<"`.`\_...._/`.-"<<endl;
    cout<<"\        /      ,"<<endl;
    cout<<"/()   () \    .' `-._"<<endl;
    cout<<"|)  .    ()\  /   _.'"<<endl;
    cout<<"\  -'-     ,; '. <"<<endl;
    cout<<".__     ,;|   > \ "<<endl;
    cout<<"/ ,    / ,  |.-'.-' "<<endl;
    cout<<"(_/    (_/ ,;|.<` "<<endl;
    cout<< "\    ,     ;-` "<<endl;
    cout<<">   \    / "<<endl;
    cout<<"(_,-'`> .' "<<endl;
    cout<< "  (_,')"<<'\n';
        cout<<" 1.- Ingresar a tu mundo Funko \n 2.- Crear cuenta \n 3.-Cualquier otro (Salir) "<<endl;
        cout<<"Opcion: ";cin>>op;
        if (op == 1)
        {
            string correo2;
            string contra2;
            string op2;
            int id2;
            int qr2;
            cout<<"Ingresa tu correo: ";cin>>correo2;
            cout<<"Ingresa tu contrasenia: ";cin>>contra2;
            cout<<"Ingresa tu id: ";cin>>id2;
            if (usuarios[id2 % 51].comparaDatos(correo2,contra2) == true)
            {
                cout<<"TU MUNDO FUNKO"<<endl<<endl;
                while (true)
                {
                   tree->traverse(); 
                    cout<<"¿Registrar funko? ";cin>>op2;
                    if (op2 == "si")
                    {
                        cout<<"Registra qr: ";cin>>qr2;
                        for (int i = 0; i < 51; i++)
                        {
                            if (qr2 == funkos[i].qr)
                            {
                                usuarios[id2 % 51].agregaFunko(funkos[i]);
                                if (funkos[i].linea == "Toy_Story")
                                {
                                    Disney->addChild(Funko0);
                                }
                                else if (funkos[i].linea == "Pokemon")
                                {
                                    Pokemon->addChild(Funko1);
                                }
                                if (funkos[i].linea == "Icons")
                                {
                                    Icons->addChild(Funko2);
                                }
                                if (funkos[i].linea == "DC")
                                {
                                    DC->addChild(Funko3);
                                }
                                
                                
                                cout<<"Se ha guardado correctamente"<<endl;
                                break;
                            }
                            
                        }
                        
                    }else
                    {
                        break;
                    }
                    
                    
                }
                
                
            }else
            {
                cout<<"Alguno de los elementos son incorrectos o el usuario no existe "<<endl;
            }
            
            
        }else if(op == 2){
            string correo2;
            string contra2;
            string alias;
            int numRandom;
            cout<<"Ingresa un correo: ";cin>>correo2;
            cout<<"Ingresa una contrasenia: ";cin>>contra2;
            numRandom = rand()%150;
            
            while (true)
            {
                if(usuarios[numRandom % 51].aliasUsuario == ""){
                cout<<"El id generado para tu cuenta es: "<<numRandom<<endl;
                cout<<"Crea un alias para tu usuario, este será público: ";cin>>alias;
                usuarios[numRandom % 51].obtenerDatos(correo2,contra2,alias,numRandom);
                break;
                }
                else{
                    numRandom+=1;
                }
            
            }
            
            
        }
        else
        {
            break;
        }
        
        
        
    }
    

    return 0;
}
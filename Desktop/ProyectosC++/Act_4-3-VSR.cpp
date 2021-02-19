#include<iostream>
#include<string>
#include <queue>
using namespace std;
struct nodo {
	int id;//id del vertice o nodo
	string nom;
	int capacidad;
	int estado;
	struct nodo* sgte;
	struct arista* ady;//puntero hacia la primera arista del nodo
};
struct arista {
	struct nodo* destino;//puntero al nodo de llegada
	struct arista* sgte;
};
typedef struct nodo* Tnodo;//  Tipo Nodo
typedef struct arista* Tarista; //Tipo Arista
Tnodo p;

void menu();
void insertar_nodo();
void agrega_arista(Tnodo&, Tnodo&, Tarista&);
void insertar_arista();
void vaciar_aristas(Tnodo&);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();
void busqueda(nodo ini);
bool cambiaestado(nodo x);


/*                        Funcion Principal
---------------------------------------------------------------------*/
int main(void)
{
	p = NULL;
	int op;     // opcion del menu


	system("color 0b");

	do
	{
		menu();
		cin >> op;

		switch (op)
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
		case 8:
			//cout << p->id << endl
			queue<nodo> myqueue;
			myqueue.push(*p);
			Tnodo aux;
			Tnodo aux2=NULL;
			Tarista ar;
			char var;
			var = p->id;
			aux = p;
			

				while (aux != NULL)
				{

						if (aux->ady == NULL)
						{
							break;
							//cout << "EL NODO NO TIENE ARISTAS...!!!!";
						}
						else
						{
							int con = 0;
							ar = aux->ady;
							while (ar != NULL)
							{

								if (cambiaestado(*ar->destino)) {
									myqueue.push(*ar->destino);
									if (con == 0) {
										con++;
										aux = ar->destino;
										//var = aux2->id;
									}
								}
								ar = ar->sgte;
							}
							cout << endl;
							//break;
						}

						//aux = aux->sgte;

				}
				//aux = aux2;
			
			while (!myqueue.empty())
			{

                cout<<"________________________"<<endl;
				cout <<"ID ciudad: " <<myqueue.front().id << endl;
				cout<<"Nombre ciudad: "<<myqueue.front().nom<<endl;
				myqueue.pop();
				cout<<"________________________"<<endl;
			}
		
			break;
		/*default: 
			cout << "OPCION NO VALIDA...!!!";
			break;*/


		}

		cout << endl << endl;
		system("pause");  system("cls");

	} while (op != 7);
	//getch();
	return 0;
}

/*                          Menu
---------------------------------------------------------------------*/
void menu()
{
	cout << "\n\tSISTEMA DE INSTALACIÓN Y CONSULTA DE TUBERÍAS\n\n";
	cout << " 1. INSERTAR CIUDAD               " << endl;
	cout << " 2. INSERTAR TUBERIA              " << endl;
	cout << " 3. RETIRAR CIUDAD DE SERVICIO                 " << endl;
	cout << " 4. RETIRAR TUBERÍA             " << endl;
	cout << " 5. MOSTRAR  CONEXIONES DE TUBERIAS                   " << endl;
	cout << " 6. MOSTRAR CIUDAD SERVICIO EN CIUDAD ESPECÍFICA       " << endl;
	cout << " 8. Breadth_First                           " << endl;
	cout << " 7. SALIR                            " << endl;

	cout << "\n INGRESE OPCION: ";
}

/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertar_nodo()
{
	Tnodo t, nuevo = new struct nodo;
	cout << "INGRESE ID:";
	cin >> nuevo->id;
	cout << "INGRESE NOMBRE DE LA CIUDAD A INSTALAR TUBERIA:";
	cin >> nuevo->nom;
	cout << "INGRESE CAPACIDAD EN LITROS:";
	cin >> nuevo->capacidad;
	//cout << "INGRESE ESTADO(0 y 1):";
	//cin >> nuevo->estado;
	nuevo->estado = 0;
	nuevo->sgte = NULL;
	nuevo->ady = NULL;

	if (p == NULL)
	{
		p = nuevo;
		cout << "PRIMERA CIUDAD...!!!";
	}
	else
	{
		t = p;
		while (t->sgte != NULL)
		{
			t = t->sgte;
		}
		t->sgte = nuevo;
		cout << "CIUDAD INGRESADA...!!!";
	}

}

/*                      AGREGAR ARISTA
	funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agrega_arista(Tnodo& aux, Tnodo& aux2, Tarista& nuevo)
{
	Tarista q;
	if (aux->ady == NULL)
	{
		aux->ady = nuevo;
		nuevo->destino = aux2;
		cout << "CONEXIÓN HECHA....!";
	}
	else
	{
		q = aux->ady;
		while (q->sgte != NULL)
			q = q->sgte;
		nuevo->destino = aux2;
		q->sgte = nuevo;
		cout << "CONEXIÓN HECHA...!!!!";
	}

}
/*                      INSERTAR ARISTA
	funcion que busca las posiciones de memoria de los nodos
	y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista()
{
	int ini, fin;
	Tarista nuevo = new struct arista;
	Tnodo aux, aux2;

	if (p == NULL)
	{
		cout << "AUN NO SE MONTA RED DE TUBERIAS...!!!!";
		return;
	}
	nuevo->sgte = NULL;
	cout << "INGRESE ID DE CIUDAD INICIO:";
	cin >> ini;
	cout << "INGRESE ID CIUDAD DE LLEGADA DE EL AGUA :";
	cin >> fin;
	aux = p;
	aux2 = p;
	while (aux2 != NULL)
	{
		if (aux2->id == fin)
		{
			break;
		}

		aux2 = aux2->sgte;
	}
	while (aux != NULL)
	{
		if (aux->id == ini)
		{
			agrega_arista(aux, aux2, nuevo);
			return;
		}

		aux = aux->sgte;
	}
}

/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
	esta funcion es utilizada al borrar un nodo pues si tiene aristas
	es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void vaciar_aristas(Tnodo& aux)
{
	Tarista q, r;
	q = aux->ady;
	while (q->sgte != NULL)
	{
		r = q;
		q = q->sgte;
		delete(r);
	}
}
/*                      ELIMINAR NODO
	funcion utilizada para eliminar un nodo del grafo
	pero para eso tambien tiene que eliminar sus aristas por lo cual
	llama a la funcion vaciar_aristas para borrarlas
---------------------------------------------------------------------*/
void eliminar_nodo()
{
	int var;
	Tnodo aux, ant;
	aux = p;
	ant = aux;
	cout << "ELIMINAR UN NODO\n";
	if (p == NULL)
	{
		cout << "AUN NO SE HA MONTADO RED DE TUBERIAS...!!!!";
		return;
	}
	cout << "INGRESE ID DE CIUDAD:";
	cin >> var;

	while (aux != NULL)
	{
		if (aux->id == var)
		{
			if (aux->ady != NULL)
				vaciar_aristas(aux);

			if (aux == p)
			{

				p = p->sgte;
				delete(aux);
				cout << "SISTEMA ELIMINADO EN CIUDAD...!!!!";
				return;



			}
			else
			{
				ant->sgte = aux->sgte;
				delete(aux);
				cout << "SISTEMA ELIMINADO EN CIUDAD...!!!!";
				return;
			}
		}
		else
		{
			ant = aux;
			aux = aux->sgte;
		}
	}

}

/*                      ELIMINAR ARISTA
	funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
void eliminar_arista()
{
	int ini, fin;
	Tnodo aux, aux2;
	Tarista q, r;
	cout << "\n RETIRAR TUBERIA \n";
	cout << "INGRESE ID DE CIUDAD INICIO:";
	cin >> ini;
	cout << "INGRESE ID CIUDAD DONDE LLEGA EL AGUA:";
	cin >> fin;
	aux = p;
	aux2 = p;
	q = aux->ady;
	r = q;;
	while (aux2 != NULL)
	{
		if (aux2->id == fin)
		{
			break;
		}
		else
			aux2 = aux2->sgte;
	}
	while (aux != NULL)
	{
		if (aux->id == ini)
		{
			q = aux->ady;
			while (q != NULL)
			{
				if (q->destino == aux2)
				{
					if (q == aux->ady)
						aux->ady = aux->ady->sgte;
					else
						r->sgte = q->sgte;
					delete(q);
					cout << "TUBERIA " << aux->id << "----->" << aux2->id << " DESISNTALADA.....!!!!";
					return;
				}
			}
			r = q;
			q = q->sgte;
		}
		aux = aux->sgte;
	}
}
/*                      MOSTRAR GRAFO
	funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrar_grafo()
{
	Tnodo ptr;
	Tarista ar;
	ptr = p;
	cout << "CIUDAD ORIGEN|CIUDADES DONDE REDISTRIBUYE EL AGUA\n";

	while (ptr != NULL)
	{
		//cout << "   " << ptr->id << "|";
		cout << " " << ptr->nom;
		if (ptr->ady != NULL)
		{
			ar = ptr->ady;
			while (ar != NULL)
			{
				//cout << " " << ar->destino->id;
				cout << " " << ar->destino->nom;
				ar = ar->sgte;
			}

		}
		ptr = ptr->sgte;
		cout << endl;
	}
}

/*                      MOSTRAR ARISTAS
	funcion que muestra todas las aristas de un nodo seleccionado
---------------------------------------------------------------------*/
void mostrar_aristas()
{
	Tnodo aux;
	Tarista ar;
	int var;
	cout << "MOSTRAR LA DISTRIBUCIÓN DE UNA CIUDAD\n";
	cout << "INGRESE ID DE CIUDAD:";
	cin >> var;
	aux = p;
	while (aux != NULL)
	{
		if (aux->id == var)
		{
			if (aux->ady == NULL)
			{
				cout << "LA CIUDAD AUN NO TIENE SISTEMA DE TUBERIAS...!!!!";
				return;
			}
			else
			{
				cout << "CIUDAD ORIGEN|CIUDADES DONDE REDISTRIBUYE EL AGUA\n";
				cout << "   " << aux->id << aux->nom << "|";
				ar = aux->ady;

				while (ar != NULL)
				{
					cout << ar->destino->id << " ";
					cout << ar->destino->nom << " ";
					ar = ar->sgte;
				}
				cout << endl;
				return;
			}
		}
		else
			aux = aux->sgte;
	}
}

void busqueda(nodo ini)
{
	ini = *p;
	cout << 'inf?';
	queue<nodo> myqueue;
	myqueue.push(ini);
	Tnodo aux;
	Tarista ar;
	int var;
	var = ini.id;
	aux = p;
	
	while (aux != NULL)
	{
		
		if (aux->id == var)
		{
			if (aux->ady == NULL)
			{
				break;
				//cout << "EL NODO NO TIENE ARISTAS...!!!!";
			}
			else
			{
				ar = aux->ady;
				while (ar != NULL)
				{
					if (cambiaestado(*ar->destino)) myqueue.push(* ar->destino);
					ar = ar->sgte;
					
				}
				cout << endl;
				return;
			}
		}
		else
			aux = aux->sgte;
	}

	while (!myqueue.empty())
	{

		cout << myqueue.front().id <<endl;
		myqueue.pop();
	}
}

bool cambiaestado(nodo x)
{
	if (x.estado == 0) {
		x.estado = 1;
		return true;
	}
	else return false;
	
}

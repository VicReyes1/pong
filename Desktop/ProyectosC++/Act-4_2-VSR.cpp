#include<iostream>
#include <queue>
#include <stack>
using namespace std;
struct nodo {
	string nombre;//nombre del vertice o nodo
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
bool cambiaestado(nodo x);

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main(void)
{
	p = NULL;
	int op;     // opcion del menu


	system("color 0b");
	stack<nodo> mystack;
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

		case 9:
			mystack.push(*p);
			Tnodo aux2;
			Tarista ar2;
			aux2 = p;
			while (aux2 != NULL)
			{

				if (aux2->ady == NULL)
				{
					break;
					//cout << "EL NODO NO TIENE ARISTAS...!!!!";
				}
				else
				{
					int con = 0;
					ar2 = aux2->ady;
					while (ar2 != NULL)
					{

							mystack.push(*ar2->destino);
							if (con == 0) {
								con++;
								aux2 = ar2->destino;
								//var = aux2->id;
							}
						
						ar2 = ar2->sgte;
					}
					cout << endl;
					//break;
				}

				//aux = aux->sgte;

			}
			//aux = aux2;

			while (!mystack.empty())
			{
				if(cambiaestado(mystack.top())) cout << mystack.top().nombre << endl;
				mystack.pop();
			}
			break;
		case 8:
			//cout << p->id << endl
			queue<nodo> myqueue;
			myqueue.push(*p);
			Tnodo aux;
			Tarista ar;
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

				cout << myqueue.front().nombre << endl;
				myqueue.pop();
			}

			break;

		

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
	cout << "\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
	cout << " 1. INSERTAR UNA CIUDAD                " << endl;
	cout << " 2. INSERTAR UNA RUTA ENTRE CIUDADES              " << endl;
	cout << " 3. ELIMINAR UNA CIUDAD                 " << endl;
	cout << " 4. ELIMINAR UN CAMINO              " << endl;
	cout << " 5. MOSTRAR  RUTAS                  " << endl;
	cout << " 6. MOSTRAR RUTAS DE UNA CIUDAD EN ESPECÍFICO      " << endl;
	cout << " 7. SALIR                            " << endl;
	cout << " 8. Breadth First        " << endl;
	cout << " 9. Depth First                            " << endl;

	cout << "\n INGRESE OPCION: ";
}

/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertar_nodo()
{
	Tnodo t, nuevo = new struct nodo;
	cout << "INGRESE VARIABLE:";
	cin >> nuevo->nombre;
	nuevo->sgte = NULL;
	nuevo->ady = NULL;
	nuevo->estado = 0;

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
		cout << "PRIMERA RUTA....!";
	}
	else
	{
		q = aux->ady;
		while (q->sgte != NULL)
			q = q->sgte;
		nuevo->destino = aux2;
		q->sgte = nuevo;
		cout << "RUTA AGREGADA...!!!!";
	}

}
/*                      INSERTAR ARISTA
	funcion que busca las posiciones de memoria de los nodos
	y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista()
{
	string ini, fin;
	Tarista nuevo = new struct arista;
	Tnodo aux, aux2;

	if (p == NULL)
	{
		cout << "NO HAY CIUDADES...!!!!";
		return;
	}
	nuevo->sgte = NULL;
	cout << "INGRESE CIUDAD DE INICIO:";
	cin >> ini;
	cout << "INGRESE CIUDAD DE DESTINO:";
	cin >> fin;
	aux = p;
	aux2 = p;
	while (aux2 != NULL)
	{
		if (aux2->nombre == fin)
		{
			break;
		}

		aux2 = aux2->sgte;
	}
	while (aux != NULL)
	{
		if (aux->nombre == ini)
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
	string var;
	Tnodo aux, ant;
	aux = p;
	ant = aux;
	cout << "ELIMINAR UNA CIUDAD\n";
	if (p == NULL)
	{
		cout << "GRAFO VACIO...!!!!";
		return;
	}
	cout << "INGRESE NOMBRE DE CIUDAD:";
	cin >> var;

	while (aux != NULL)
	{
		if (aux->nombre == var)
		{
			if (aux->ady != NULL)
				vaciar_aristas(aux);

			if (aux == p)
			{

				p = p->sgte;
				delete(aux);
				cout << "CIUDAD ELIMINADA...!!!!";
				return;



			}
			else
			{
				ant->sgte = aux->sgte;
				delete(aux);
				cout << "CIUDAD ELIMINADA...!!!!";
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
	string ini, fin;
	Tnodo aux, aux2;
	Tarista q, r;
	cout << "\n ELIMINAR RUTA\n";
	cout << "INGRESE CIUDAD DE INICIO:";
	cin >> ini;
	cout << "INGRESE CIUDAD DE DESTINO:";
	cin >> fin;
	aux = p;
	aux2 = p;
	q = aux->ady;
	r = q;;
	while (aux2 != NULL)
	{
		if (aux2->nombre == fin)
		{
			break;
		}
		else
			aux2 = aux2->sgte;
	}
	while (aux != NULL)
	{
		if (aux->nombre == ini)
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
					cout << "CIUDAD  " << aux->nombre << "----->" << aux2->nombre << " ELIMINADA.....!!!!";
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
	cout << "CIUDAD|CIUDADES CON LAS QUE HAY RUTA\n";

	while (ptr != NULL)
	{
		cout << "   " << ptr->nombre << "|";
		if (ptr->ady != NULL)
		{
			ar = ptr->ady;
			while (ar != NULL)
			{
				cout << " " << ar->destino->nombre;
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
	string var;
	cout << "MOSTRAR RUTAS DE CIUDAD\n";
	cout << "INGRESE CIUDAD:";
	cin >> var;
	aux = p;
	while (aux != NULL)
	{
		if (aux->nombre == var)
		{
			if (aux->ady == NULL)
			{
				cout << "LA CIUDAD AUN NO TIENE RUTAS...!!!!";
				return;
			}
			else
			{
				cout << "CIUDAD|RUTAS\n";
				cout << "   " << aux->nombre << "|";
				ar = aux->ady;

				while (ar != NULL)
				{
					cout << ar->destino->nombre << " ";
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

bool cambiaestado(nodo x)
{
	if (x.estado == 0) {
		x.estado = 1;
		return true;
	}
	else return false;

}

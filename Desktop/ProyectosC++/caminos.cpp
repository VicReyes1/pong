#include <iostream>
#include <cstring>
#include <cstdlib>    
#include <string>
#include <queue>
using namespace std;
class Ccd {
public:
	Ccd(string n, int i, int e) {
		nombre = n; estado = e; id = i;
	}
	string nombre;
	int estado;
	int id;
};


class grafo {
public:
	string nom[20];
	int estado[20];
	grafo();
	int mat[20][20];
	int contador;
	queue<int> myqueue;
	void insertarcd(string s);
	void mostrar();
	void editar();
	void agregarrecorrido(int r, int r2, int val);
	int buscar(string ida, string vuelta);
	int buscar2(string ida, string vuelta);
	int indiceNombre(string nombreEstado);
	void Breadth_First(int c);
	//void Breadth_First();
	//friend class CLista;
	friend class Ccd;
	//CLista hoa;

};

class ciudad {
public:
	string nombre;
	bool estatutus;
	ciudad() {
		nombre = "";
		estatutus = false;
	}
	void getDato(string _nombre) {
		nombre = _nombre;
	}
	void imprimieDatos() {
		cout << "La ciudad es :" << nombre << endl;
		cout << "_________" << endl;
		cout << endl;
	}
};

class nodo {

public:
	nodo(ciudad* registro, nodo* sig = NULL)
	{
		informacion = registro;
		siguiente = sig;
	}

private:
	int valor;
	ciudad* informacion;
	nodo* siguiente;

	friend class pila;
};

typedef nodo* pnodo;

class pila {
public:
	//Inicializa el elemento ultimo
	pila() : ultimo(NULL) {}
	~pila();

	void Push(ciudad* registro);
	ciudad* Pop();

private:
	pnodo ultimo;
};

//Su desctructor, elimina el elemento que se ha sacado de la pila
pila::~pila()
{
	pnodo aux;
	while (ultimo) {
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
	}
}

//En este mÃ©️todo, se declara un nuevo nodo, al cual se le deposita la informacion de la clase CAlumno_registro, de ahÃ­ esta infromaciÃ³n es guardada ahora en ultimo, para saber cual es el ultimo registro.
void pila::Push(ciudad* registro)
{
	pnodo nuevo;
	nuevo = new nodo(registro, ultimo);
	ultimo = nuevo;
}

//Este mÃ©️todo se encarga de regresar la ultima infrormaciÃ³n que se ha introducido en la pila y pasar a el atributo ultimo, la informaciÃ³n que se encuentra en la direcciÃ³n de memoria siguiente.
ciudad* pila::Pop()
{
	pnodo nodo;
	ciudad* v;
	if (!ultimo) return NULL;
	nodo = ultimo;
	ultimo = ultimo->siguiente;
	v = nodo->informacion;
	delete nodo;
	return v;
}

typedef nodo* pnodo;
int main()
{
	bool w = true;
	grafo migrafo;
	ciudad Ciudad[20];
	pila miPila;
	while (w)
	{
		cout << "Grafo de rutas" << endl;
		cout << "Opciones del programa:" << endl;
		cout << "1. - Agregar una nueva ciudad" << endl;
		cout << "2. - Asignar un tiempo a un recorrido" << endl;
		cout << "3. - Mostrar todos los reccoridos disponibles" << endl;
		cout << "4. - Buscar si hay un recorrido entre dos ciudades y cual es su duración" << endl;
		cout << "5. - Editar un tiempo a un recorrido" << endl;
		cout << "6. - Recorrido por anchura " << endl;
		cout << "7. - Recorrido por profundidad" << endl;
		cout << "8. - Terminar el programa" << endl;
		int x; cin >> x;
		string n;
		string c1, c2;
		int contador;
		int num = 0;
		int y2 = 0;
		switch (x)
		{
		case 1:
			cout << "Nombre: " << endl;
			cin >> n;
			migrafo.insertarcd(n);
			break;
		case 2:
			contador = migrafo.contador;
			cout << "\n";
			for (int i = 0; i < contador; i++)
			{
				cout << i << ". " << migrafo.nom[i] << endl;
			}
			int cd1, cd2, duracion;
			cout << "Ciudad 1: ";
			cin >> cd1;
			cout << "Ciudad 2: ";
			cin >> cd2;
			cout << "Duracion; ";
			cin >> duracion;
			migrafo.agregarrecorrido(cd1, cd2, duracion);
			break;
		case 3:
			migrafo.mostrar();
			break;
		case 4:

			cout << "Ciudad 1: ";
			cin >> c1;
			cout << "Ciudad 2: ";
			cin >> c2;
			migrafo.buscar2(c1, c2);
			break;
		case 5:
			migrafo.editar();
			break;
		case 6:
			migrafo.Breadth_First(0);
			break;
		case 7:
            int cuenta;
			for (int i = 0; i < migrafo.contador; i++) {
				Ciudad[i].getDato(migrafo.nom[i]);
			}
			miPila.Push(&Ciudad[num]);
			while (num >= 0)
			{
                num = y2;
				if (Ciudad[num].estatutus == false)
				{
					Ciudad[num].imprimieDatos();
					miPila.Pop();
					for (int y = 0; y < migrafo.contador; y++)
					{
						if (migrafo.mat[num][y] > 0)
						{
							miPila.Push(&Ciudad[y]);
							y2 = y;
						}

					}
					Ciudad[num].estatutus = true;

				}
				else if (Ciudad[num].estatutus == true) {
                    for (int i2 = 0; i2 < migrafo.contador; i2++)
                    {
                        if (Ciudad[i2].estatutus == true)
                        {
                            cuenta+=1;
                            cout<<cuenta<<endl;
                        }
                        
                    }
                    
					if (y2 > 0) {
						miPila.Pop();
						y2 = y2 - 1;
					} else if(y2 == 0 && cuenta != migrafo.contador){
                        miPila.Pop();
					    for (int y = 0; y < migrafo.contador; y++){

						    if (migrafo.mat[num][y] > 0)
						   {
							miPila.Push(&Ciudad[y]);
							y2 = y;
						   }

					   }
                    } else if(y2 == 0 && cuenta == migrafo.contador){
                         num = -1;
                    } 
					
				}

			}
			break;
		case 8:
			w = false;
			break;
		default:
			break;
		}
	}


}


grafo::grafo()
{
	mat[0][0] = -1;
	mat[0][1] = 7;
	mat[0][2] = 1;
	mat[0][3] = 5;
	mat[0][4] = 7;
	mat[0][5] = 12;
	mat[1][0] = 7;
	mat[1][1] = -1;
	mat[1][2] = 8;
	mat[1][3] = 6;
	mat[1][4] = 4;
	mat[1][5] = 18;
	mat[2][0] = 1;
	mat[2][1] = 8;
	mat[2][2] = -1;
	mat[2][3] = -1;
	mat[2][4] = -1;
	mat[2][5] = -1;
	mat[3][0] = 5;
	mat[3][1] = 6;
	mat[3][2] = 5;
	mat[3][3] = -1;
	mat[3][4] = 3;
	mat[3][5] = -1;
	mat[4][0] = 7;
	mat[4][1] = 4;
	mat[4][2] = -1;
	mat[4][3] = 3;
	mat[4][4] = -1;
	mat[4][5] = 15;
	mat[5][0] = 12;
	mat[5][1] = 18;
	mat[5][2] = -1;
	mat[5][3] = -1;
	mat[5][4] = 15;
	mat[5][5] = -1;
	nom[0] = "CDMX";
	nom[1] = "Monterrey";
	nom[2] = "Hidalgo";
	nom[3] = "Acapulco";
	nom[4] = "Guadalajara";
	nom[5] = "Cancun";
	contador = 6;
	estado[0] = 0;
	estado[1] = 0;
	estado[2] = 0;
	estado[3] = 0;
	estado[4] = 0;
	estado[5] = 0;
}

void grafo::insertarcd(string s)
{
	if (contador <= 19) nom[contador] = s;
	for (int i = 0; i < contador; i++)
	{
		mat[contador][i] = -1;
	}
	for (int i = 0; i < contador; i++)
	{
		mat[i][contador] = -1;
	}
	mat[contador][contador] = -1;
	contador++;
	estado[contador] = 0;
}

void grafo::mostrar() {
	for (int x = 0; x < contador; x++) {
		for (int y = 0; y < contador; y++) {
			if (mat[x][y] != -1) cout << "De " << nom[x] << " a " << nom[y] << " son: " << mat[x][y] << "  horas" << endl;
		}
		cout << endl;
	}
};

void grafo::agregarrecorrido(int r, int r2, int val)
{
	/*
	cout << "\n";
	for (int i = 0; i < contador; i++)
	{
		cout << i << ". " << nom[i] << endl;
	}*/
	for (int i = 0; i < contador; i++)
	{
		for (int j = 0; j < contador; j++)
		{
			if ((i == r && j == r2) || (i == r2 && j == r)) {
				mat[i][j] = val;
			}
		}
	}
}



int grafo::indiceNombre(string nombreEstado) {
	int indice = 0;
	for (int n1 = 0; n1 <= contador; n1++) {
		if (nombreEstado == nom[n1]) {
			indice = n1;
			break;
		}
	}
	return indice;
}
void grafo::Breadth_First(int c)
{

	if (estado[c] == 0) myqueue.push(c);
	if (!myqueue.empty()) {
		cout << nom[myqueue.front()] << endl;
		myqueue.pop();
	}
	int con = 0, cd = c, orden[20], x = 0;
	for (int i = 0; i < contador; i++)
	{
		if (mat[c][i] > 0) {

			con++;
			orden[x] = con;
			x++;

			//cout << "f";
		}
	}

	if (con > 0) {
		for (int i = 0; i < con; i++)
		{
			//cout << con;
			if (estado[orden[i]] == 0) {
				//cout << "sali";
				myqueue.push(orden[i]);
			}
		}
		if (estado[myqueue.front()] == 0) {
			estado[c] = 1;
			Breadth_First(myqueue.front());
		}
	}
	while (!myqueue.empty())
	{
		if (indiceNombre(nom[myqueue.front()]) == 0) {
			cout << nom[myqueue.front()] << endl;
			myqueue.pop();
		}
		else
		{
			break;
		}
	}

}
;
void grafo::editar() {
	string origen, destino;
	int destinoIndex, origenIndex, numeroEditado;
	cout << "Trayecto que desea editar " << endl;
	cout << "Origen: "; cin >> origen;
	origenIndex = indiceNombre(origen);
	for (int n = 0; n <= contador; n++) {

		if (origen != nom[n]) {

			cout << nom[n] << endl;
		}
	}

	cout << "Que destino editará la ruta: "; cin >> destino;
	destinoIndex = indiceNombre(destino);
	if (mat[origenIndex][destinoIndex] == 0) {
		cout << "La ruta no existe " << endl;

	}
	else if (mat[origenIndex][destinoIndex] > 0) {
		cout << "Ruta: " << origen << " - " << destino << endl;
		cout << "Duracion: " << mat[origenIndex][destinoIndex] << " hrs" << endl;
		cout << "Editando duracion... " << endl;
		cout << "Ingrese la cantidad en horas a editar: "; cin >> numeroEditado;
		mat[origenIndex][destinoIndex] = numeroEditado;
		mat[destinoIndex][origenIndex] = numeroEditado;
		cout << "Se ha editado exitosamente " << endl;
	}
}
int grafo::buscar(string ida, string vuelta)
{
	int c1 = 0, c2 = 0, cc1 = 0, cc2 = 0;
	string r = "";
	for (int x = 0; x < 20; x++)
	{
		if (nom[x] == ida) c1 = 1;
		if (nom[x] == vuelta) c2 = 1;
	}
	if ((c1 == 0 || c2 == 0) || ida == vuelta)
	{
		//cout << "Datos inválidos, ciudad repetida o ciudad(es) inesistentes " << endl;
	}
	else
	{
		for (int y = 0; y < 20; y++)
		{
			if (nom[y] == ida)
			{
				for (int w = 0; w < 20; w++)
				{
					if (nom[w] == vuelta)
					{
						break;
					}
					else
					{
						cc2++;
					}
				}
				break;
			}
			else
			{
				cc1++;
			}
		}
		//cout << "De: " + ida + " a " + vuelta + " se hacen: " << mat[cc1][cc2] << " horas" << endl;

	}
	if (mat[cc1][cc2] > 0) return 1;
	else return 0;
}
int grafo::buscar2(string ida, string vuelta)
{
	int c1 = 0, c2 = 0, cc1 = 0, cc2 = 0;
	string r = "";
	for (int x = 0; x < 20; x++)
	{
		if (nom[x] == ida) c1 = 1;
		if (nom[x] == vuelta) c2 = 1;
	}
	if ((c1 == 0 || c2 == 0) || ida == vuelta)
	{
		cout << "Datos inválidos, ciudad repetida o ciudad(es) inesistentes " << endl;
	}
	else
	{
		for (int y = 0; y < 20; y++)
		{
			if (nom[y] == ida)
			{
				for (int w = 0; w < 20; w++)
				{
					if (nom[w] == vuelta)
					{
						break;
					}
					else
					{
						cc2++;
					}
				}
				break;
			}
			else
			{
				cc1++;
			}
		}
		cout << "De: " + ida + " a " + vuelta + " se hacen: " << mat[cc1][cc2] << " horas" << endl;

	}
	if (mat[cc1][cc2] > 0) return 1;
	else return 0;
}
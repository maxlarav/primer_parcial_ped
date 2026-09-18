//Maximiliano Xavier Rivera Lara 00067826
#include <iostream>
#include <math.h>
using namespace std;
struct PuntoTrayectoria
{
    int identificador;
    string nombre;
    float coordenadas[3]; // las coordenadas son x,y,z 
    float distanciaOrigen;
    string clasificacion;
};
void registrarPunto(PuntoTrayectoria &punto);
float calcularDistancia(PuntoTrayectoria *punto); // funcion es la q calcula la distancia del punto al origen

int main()
{
    PuntoTrayectoria puntos[10];
    int cantidad;
    do
    {
        cout << "Hola, Ingrese la cantidad de puntos del 1 al 10 ";
        cin >> cantidad;s
        if (cantidad < 1 || cantidad > 10)
        {
            cout << "la cantidad no es valida" << endl;
        }
    } while (cantidad < 1 || cantidad > 10);
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\nRegistro del punto " << i + 1 << endl;
        registrarPunto(puntos[i]);
    }
    return 0;
}


void registrarPunto(PuntoTrayectoria &punto)
{
    cout << "Ingrese el identificador: ";
    cin >> punto.identificador;
    cout << "Ingrese el nombre o descripcion: "; //revisar luego
    cin >> punto.nombre;
    cout << "Ingrese la coordenada X: ";
    cin >> punto.coordenadas[0];
    cout << "Ingrese la coordenada Y: ";
    cin >> punto.coordenadas[1];
    cout << "Ingrese la coordenada Z: ";
    cin >> punto.coordenadas[2];
}
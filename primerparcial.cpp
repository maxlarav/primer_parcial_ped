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
float calcularDistancia(PuntoTrayectoria *punto);
void clasificarPunto(PuntoTrayectoria &punto);

PuntoTrayectoria* obtenerPuntoMasAlejado(
    PuntoTrayectoria puntos[],
    int cantidad
);

int main() {
  PuntoTrayectoria puntos[10];
  int cantidad;

  do {
    cout << "Hola, Ingrese la cantidad de puntos del 1 al 10 " << endl;
    cin >> cantidad;

    if (cantidad < 1 || cantidad > 10) {
      cout << "la cantidad no es valida" << endl;
    }
  } while (cantidad < 1 || cantidad > 10);

  for (int i = 0; i < cantidad; i++) {
    cout << "\nRegistro del punto " << i + 1 << endl;
    registrarPunto(puntos[i]);
  }

  PuntoTrayectoria *puntero = puntos;

  for (int i = 0; i < cantidad; i++) {
    calcularDistancia(puntero);
    clasificarPunto(*puntero);
    puntero++;
  }

  PuntoTrayectoria *puntoMasAlejado =
      obtenerPuntoMasAlejado(puntos, cantidad);

  cout << "\nPunto mas alejado:" << endl;
  cout << "ID: " << puntoMasAlejado->identificador << endl;
  cout << "Nombre: " << puntoMasAlejado->nombre << endl;
  cout << "Coordenada X: "
       << puntoMasAlejado->coordenadas[0] << endl;
  cout << "Coordenada Y: "
       << puntoMasAlejado->coordenadas[1] << endl;
  cout << "Coordenada Z: "
       << puntoMasAlejado->coordenadas[2] << endl;
  cout << "Distancia al origen: "
       << puntoMasAlejado->distanciaOrigen << endl;
  cout << "Clasificacion: "
       << puntoMasAlejado->clasificacion << endl;

  return 0;
}

void registrarPunto(PuntoTrayectoria &punto)
{
    cout << "Ingrese el identificador: " << endl;
    cin >> punto.identificador;

    cout << "Ingrese el nombre o descripcion: " << endl;
  
}

float calcularDistancia(PuntoTrayectoria *punto)
{
   float x = punto->coordenadas[0];
   float y = punto->coordenadas[1];
   float z = punto->coordenadas[2];

   punto->distanciaOrigen = sqrt(x * x + y * y + z * z);

   return punto->distanciaOrigen;
}

void clasificarPunto(PuntoTrayectoria &punto)
{
    if (punto.distanciaOrigen <= 5) {
        punto.clasificacion = "CERCANO";
    } else if (punto.distanciaOrigen <= 10) {
        punto.clasificacion = "INTERMEDIO";
    } else if (punto.distanciaOrigen <= 20) {
        punto.clasificacion = "LEJANO";
    } else {
        punto.clasificacion = "EXTREMO";
    }
}

PuntoTrayectoria* obtenerPuntoMasAlejado(
    PuntoTrayectoria puntos[],
    int cantidad
)
{
    PuntoTrayectoria *puntoMasAlejado = &puntos[0];

    for (int i = 1; i < cantidad; i++) {
        if (puntos[i].distanciaOrigen
            > puntoMasAlejado->distanciaOrigen) {
            puntoMasAlejado = &puntos[i];
        }
    }

    return puntoMasAlejado;
}
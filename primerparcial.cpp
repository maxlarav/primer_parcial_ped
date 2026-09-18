//Maximiliano Xavier Rivera Lara 00067826

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct PuntoTrayectoria
{
    int identificador;
    string nombre;
    float coordenadas[3];
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

void corregirCoordenadas(
    PuntoTrayectoria &punto,
    float desplazamientoX,
    float desplazamientoY,
    float desplazamientoZ
);

void generarInforme(
    PuntoTrayectoria puntos[],
    int cantidad
);

int main() {
  PuntoTrayectoria puntos[10];
  int cantidad;

  do {
    cout << "Hola, Ingrese la cantidad de puntos del 1 al 10 "
         << endl;
    cin >> cantidad;

    if (cantidad < 1 || cantidad > 10) {
      cout << "La cantidad no es valida" << endl;
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

  int opcion;

  do {
    cout << "\nMenu" << endl;
    cout << "1. Generar informe" << endl;
    cout << "2. Mostrar punto mas alejado" << endl;
    cout << "3. Corregir coordenadas" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: " << endl;
    cin >> opcion;

    switch (opcion) {
      case 1:
        generarInforme(puntos, cantidad);
        break;

      case 2: {
        PuntoTrayectoria *puntoMasAlejado =
            obtenerPuntoMasAlejado(puntos, cantidad);

        cout << "\nPunto mas alejado:" << endl;
        cout << "ID: "
             << puntoMasAlejado->identificador << endl;
        cout << "Nombre: "
             << puntoMasAlejado->nombre << endl;
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

        break;
      }

      case 3: {
        int posicion;
        float desplazamientoX;
        float desplazamientoY;
        float desplazamientoZ;

        do {
          cout << "\nIngrese la posicion del punto a corregir "
               << "(1-" << cantidad << "): " << endl;
          cin >> posicion;

          if (posicion < 1 || posicion > cantidad) {
            cout << "La posicion no es valida" << endl;
          }
        } while (posicion < 1 || posicion > cantidad);

        cout << "Ingrese el desplazamiento en X: " << endl;
        cin >> desplazamientoX;

        cout << "Ingrese el desplazamiento en Y: " << endl;
        cin >> desplazamientoY;

        cout << "Ingrese el desplazamiento en Z: " << endl;
        cin >> desplazamientoZ;

        corregirCoordenadas(
            puntos[posicion - 1],
            desplazamientoX,
            desplazamientoY,
            desplazamientoZ
        );

        calcularDistancia(&puntos[posicion - 1]);
        clasificarPunto(puntos[posicion - 1]);

        cout << "\nPunto corregido:" << endl;
        cout << "ID: "
             << puntos[posicion - 1].identificador << endl;
        cout << "Nombre: "
             << puntos[posicion - 1].nombre << endl;
        cout << "Coordenada X: "
             << puntos[posicion - 1].coordenadas[0] << endl;
        cout << "Coordenada Y: "
             << puntos[posicion - 1].coordenadas[1] << endl;
        cout << "Coordenada Z: "
             << puntos[posicion - 1].coordenadas[2] << endl;
        cout << "Distancia al origen: "
             << puntos[posicion - 1].distanciaOrigen << endl;
        cout << "Clasificacion: "
             << puntos[posicion - 1].clasificacion << endl;

        break;
      }

      case 4:
        cout << "Programa finalizado" << endl;
        break;

      default:
        cout << "Opcion no valida" << endl;
    }

  } while (opcion != 4);

  return 0;
}

void registrarPunto(PuntoTrayectoria &punto)
{
    cout << "Ingrese el identificador: " << endl;
    cin >> punto.identificador;

    cout << "Ingrese el nombre o descripcion: " << endl;
    cin >> punto.nombre;

    cout << "Ingrese la coordenada X: " << endl;
    cin >> punto.coordenadas[0];

    cout << "Ingrese la coordenada Y: " << endl;
    cin >> punto.coordenadas[1];

    cout << "Ingrese la coordenada Z: " << endl;
    cin >> punto.coordenadas[2];
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
        punto.clasificacion = "cercano";
    } else if (punto.distanciaOrigen <= 10) {
        punto.clasificacion = "intermedio";
    } else if (punto.distanciaOrigen <= 20) {
        punto.clasificacion = "lejano";
    } else {
        punto.clasificacion = "extremo";
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

void corregirCoordenadas(
    PuntoTrayectoria &punto,
    float desplazamientoX,
    float desplazamientoY,
    float desplazamientoZ
)
{
    punto.coordenadas[0] =
        punto.coordenadas[0] + desplazamientoX;

    punto.coordenadas[1] =
        punto.coordenadas[1] + desplazamientoY;

    punto.coordenadas[2] =
        punto.coordenadas[2] + desplazamientoZ;
}

void generarInforme(
    PuntoTrayectoria puntos[],
    int cantidad
)
{
    int cantidadCercanos = 0;
    int cantidadIntermedios = 0;
    int cantidadLejanos = 0;
    int cantidadExtremos = 0;

    float sumaDistancias = 0;

    cout << "\n------ INFORME DE TRAYECTORIA ------"
         << endl;

    cout << "ID\tNombre\tX\tY\tZ\tDistancia\tClasificacion"
         << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << puntos[i].identificador << "\t";
        cout << puntos[i].nombre << "\t";
        cout << puntos[i].coordenadas[0] << "\t";
        cout << puntos[i].coordenadas[1] << "\t";
        cout << puntos[i].coordenadas[2] << "\t";
        cout << puntos[i].distanciaOrigen << "\t";
        cout << puntos[i].clasificacion << endl;

        sumaDistancias =
            sumaDistancias + puntos[i].distanciaOrigen;

        if (puntos[i].clasificacion == "cercano") {
            cantidadCercanos++;
        } else if (puntos[i].clasificacion == "intermedio") {
            cantidadIntermedios++;
        } else if (puntos[i].clasificacion == "lejano") {
            cantidadLejanos++;
        } else if (puntos[i].clasificacion == "extremo") {
            cantidadExtremos++;
        }
    }

    float distanciaPromedio = sumaDistancias / cantidad;

    cout << "\nCantidad de puntos cercanos: "
         << cantidadCercanos << endl;

    cout << "Cantidad de puntos intermedios: "
         << cantidadIntermedios << endl;

    cout << "Cantidad de puntos lejanos: "
         << cantidadLejanos << endl;

    cout << "Cantidad de puntos extremos: "
         << cantidadExtremos << endl;

    cout << "Distancia promedio: "
         << distanciaPromedio << endl;
}
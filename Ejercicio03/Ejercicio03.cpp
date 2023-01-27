// 3. Hacer un programa para ingresar los valores de los pesos de distintas encomiendas que se deben enviar 
//    a distintos clientes y que finaliza cuando se ingresa un peso negativo. Se deben agrupar las encomiendas 
//    en camiones que pueden transportar hasta 200 kilos en total.
//    Por ejemplo:
//    10, 20, 140,    70, 100,    40, 10, 50, 80,    90, 30, 40,    50, -10.
//      Camión 1.     Camión 2        Camión 3         Camión 4     Camión 5
// 
//    Se pide determinar e informar :
//       a. El número de camión y peso total de encomiendas (Camión 1: 170kg, Camión 2: 170kg, etc.).
//       b. El número de camión que transporta mayor cantidad de encomiendas (en el ejemplo anterior sería 
//          el camión 3 con 4 encomiendas).
//       c. La cantidad de camiones que se terminaron cargando.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int Camion = 0, maxCamE = 0, encomiendas, maxEncomiendas = 0;
    float pesoEncomienda, pesoTotal = 0;

    cout << "Camion 1: " << pesoTotal << " kg.";
    cout << "\nIngrese el peso del paquete (kg): ";
    cin >> pesoEncomienda;

    if (pesoEncomienda <= 0) {
        cout << "\n---------------------------------------------------------";
        cout << "\nProceso finalizado." << endl;
        return 0;
    }
    else if (pesoEncomienda > 200) {
        cout << "\n---------------------------------------------------------";
        cout << "\nError: un camion solo puede cargar hasta 200 kilogramos." << endl;
        return 0;
    }

    while (pesoEncomienda > 0 && pesoEncomienda <= 200) {
        Camion++;
        pesoTotal = 0;
        bool fCam = false;
        encomiendas = 0;

        while (!fCam && pesoEncomienda > 0) {
            if (pesoEncomienda + pesoTotal <= 200) {
                pesoTotal += pesoEncomienda;
                encomiendas++;
                cout << "\nCamion " << Camion << ": " << pesoTotal << " kg.";
                cout << "\nIngrese el peso del paquete (kg): ";
                cin >> pesoEncomienda;
            }
            else {
                fCam = true;
            }
        }

        if (encomiendas > maxEncomiendas) {
            maxCamE = Camion;
            maxEncomiendas = encomiendas;
        }

        cout << "\n---------------------------------------------------------";
        cout << "\nNumero de camion: " << Camion << ": " << pesoTotal << "kg.";
        cout << "\n---------------------------------------------------------" << endl;

    }

    cout << "\n---------------------------------------------------------";
    cout << "\nCamion que transporta mas paquetes: " << maxCamE << " (" << maxEncomiendas << " paquetes).";
    cout << "\nCantidad de camiones cargados: " << Camion;
    cout << "\n---------------------------------------------------------" << endl;
    return 0;
}

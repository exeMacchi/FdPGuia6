/*
   3. Hacer un programa para ingresar los valores de los pesos de distintas encomiendas que se deben enviar
      a distintos clientes y que finaliza cuando se ingresa un peso negativo. Se deben agrupar las encomiendas
      en camiones que pueden transportar hasta 200 kilos en total.
      Por ejemplo:
      10, 20, 140,    70, 100,    40, 10, 50, 80,    90, 30, 40,    50, -10.
        Cami�n 1.     Cami�n 2        Cami�n 3         Cami�n 4     Cami�n 5

      Se pide determinar e informar :
         a. El n�mero de cami�n y peso total de encomiendas (Cami�n 1: 170kg, Cami�n 2: 170kg, etc.).
         b. El n�mero de cami�n que transporta mayor cantidad de encomiendas (en el ejemplo anterior ser�a
            el cami�n 3 con 4 encomiendas).
         c. La cantidad de camiones que se terminaron cargando.
*/


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
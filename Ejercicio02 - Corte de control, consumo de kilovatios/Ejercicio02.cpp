/*
   2. Una compañía de electricidad necesita calcular anualmente el consumo que ha registrado cada uno de
      sus usuarios y el monto pagado por cada uno de ellos. Para ello tiene un lote de registros por cada 
      uno de los usuarios con los siguientes datos:
         • Zona (numérico entero).
         • Número de cliente(número de cuatro dígitos no correlativos).
         • Cantidad de kilovatios consumidos en el periodo.
      El lote se encuentra agrupado (no ordenado) por zona y finaliza con un registro con zona igual a cero.

      Se pide generar un listado con el siguiente formato :
         Zona: XX
         Cantidad de usuarios de la zona: XX
         Total facturado en la zona: XX
 
         Zona: XX
         Cantidad de usuarios de la zona: XX
         Total facturado en la zona: XX
 
      El precio es escalonado según la siguiente escala :
         • $ 0.10 por kv por los primeros 100 kv de consumo.
         • $ 0.12 por kv por el consumo de 101 a 200 kvs.
         • $ 0.15 por kv por el consumo de 201 kvs en adelante.
*/ 

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int Z, zAct, numC, canKv, conCliente;
    float totalF, totalC;
    float const P1 = 0.10;
    float const P2 = 0.12;
    float const P3 = 0.15;

    cout << "Zona: ";
    cin >> Z;

    if (Z == 0)
    {
        cout << "\nProceso finalizado." << endl;
        return 0;
    }
    cout << "Numero de cliente: ";
    cin >> numC;
    cout << "Cantidad de kilovatios consumidos: ";
    cin >> canKv;

    while (Z != 0)
    {
        zAct = Z;
        conCliente = 0;
        totalF = 0;
        while (Z == zAct)
        {
            totalC = 0;
            conCliente++;
            if (canKv > 200)
            {
                totalC = canKv * P3;
            }
            else if (canKv <= 200 && canKv > 100)
            {
                totalC = canKv * P2;
            }
            else
            {
                totalC = canKv * P1;
            }
            totalF += totalC;


            cout << "\nZona: ";
            cin >> Z;
            if (Z == zAct)
            {
                cout << "Numero de cliente: ";
                cin >> numC;
                cout << "Cantidad de kilovatios consumidos: ";
                cin >> canKv;
            }
            else
            {
                cout << "\n------------------------------------------------------------";
            }
        }
        cout << "\nZona: " << zAct;
        cout << "\nCantidad total de clientes: " << conCliente;
        cout << "\nTotal facturado en la zona: $" << totalF;
        cout << "\n------------------------------------------------------------" << endl;

        cout << "\nZona: ";
        cin >> Z;
        if (Z == 0)
        {
            cout << "\nProceso finalizado." << endl;
            return 0;
        }
        cout << "Numero de cliente: ";
        cin >> numC;
        cout << "Cantidad de kilovatios consumidos:: ";
        cin >> canKv;
    }
    return 0;
}
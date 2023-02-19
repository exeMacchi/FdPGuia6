/*
   4. Una compañía de turismo aventura registró los paquetes vendidos durante la última temporada vacacional.
      Para cada venta se ingresó:
         • Número de paquete(4 dígitos no correlativos).
         • Cantidad de personas incluidas.
         • Precio por persona.
         • Horas totales de actividades.
         • Tipo de aventura(“M” = Montaña; “T” = Trekking; “R” = Rafting; “B” = Bicicleta; “C” = Canopy;
                            “E” = Escalar; “K” = Sky; “S” = Snowboard; “J” = Jumping; “P” = Parapente).
      El lote se encuentra no ordenado y agrupado por tipo de aventura y corta con número de paquete cero.
      En el lote no se ingresan registros cuyo tipo de aventura no se haya vendido.
      A partir de dichos datos, se solicita informar:
         a. La cantidad de paquetes vendidos de cada tipo de aventura.
         b. La cantidad total de personas que disfrutaron de las aventuras durante la temporada.
         c. El total recaudado por cada venta.
         d. La venta con mayor importe de cada tipo de aventura.
         e. El paquete con menos horas incurridlas y en qué tipo de actividad fue.
*/


#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numPaquete, canPersonas, hsTotales;
    float precioPorPersona, totalRecaudado, ventaMayorImporte;
    char TAventura, TAAct, aventuraPaqueteMenosHoras;
    int P, cantPerTotal = 0, PMHs, minHs, paqueteMenosHoras, aventuraMenosHoras;
    bool Aventura = false;

    cout << "Tipo de aventura: "; cin >> TAventura;
    cout << "Numero de paquete: "; cin >> numPaquete;
    cout << "Cantidad de personas incluidas: "; cin >> canPersonas;
    cout << "Precio por persona: $"; cin >> precioPorPersona;
    cout << "Horas totales de actividad: "; cin >> hsTotales;

    while (numPaquete != 0)
    {
        TAAct = TAventura;
        P = 0;
        ventaMayorImporte = 0;

        while (TAventura == TAAct && numPaquete != 0)
        {
            P++;
            cantPerTotal += canPersonas;
            totalRecaudado = canPersonas * precioPorPersona;
            if (totalRecaudado > ventaMayorImporte)
            {
                ventaMayorImporte = totalRecaudado;
            }
            if (P == 1)
            {
                PMHs = P;
                minHs = hsTotales;
            }
            else if (hsTotales < minHs)
            {
                PMHs = P;
                minHs = hsTotales;
            }

            cout << "-------------------------------- Ingresos totales de la venta: $" << totalRecaudado;

            cout << "\nTipo de aventura: "; cin >> TAventura;
            if (TAventura == TAAct)
            {
                cout << "Numero de paquete: "; cin >> numPaquete;
                if (numPaquete != 0)
                {
                    cout << "Cantidad de personas incluidas: "; cin >> canPersonas;
                    cout << "Precio por persona: $"; cin >> precioPorPersona;
                    cout << "Horas totales de actividad: "; cin >> hsTotales;
                }
            }
        }
        if (!Aventura)
        {
            aventuraPaqueteMenosHoras = TAAct;
            paqueteMenosHoras = PMHs;
            aventuraMenosHoras = minHs;
        }
        else if (minHs < aventuraMenosHoras)
        {
            aventuraPaqueteMenosHoras = TAAct;
            paqueteMenosHoras = PMHs;
            aventuraMenosHoras = minHs;
        }

        cout << "\n------------------------------------------------------------------";
        cout << "\nEn el tipo aventura " << TAAct << ", " << P << " paquetes fueron vendidos.";
        cout << "\nEn el tipo aventura " << TAAct << ", la mayor venta fue: $" << ventaMayorImporte;
        cout << "\n------------------------------------------------------------------" << endl;

        cout << "\nTipo de aventura: "; cin >> TAventura;
        cout << "Numero de paquete: "; cin >> numPaquete;
        if (numPaquete != 0)
        {
            cout << "Cantidad de personas incluidas: "; cin >> canPersonas;
            cout << "Precio por persona: $"; cin >> precioPorPersona;
            cout << "Horas totales de actividad: "; cin >> hsTotales;
        }

    }
    cout << "\n------------------------------------------------------------------";
    cout << "\n------------------------------------------------------------------";
    cout << "\nCantidad total de personas de la temporada: " << cantPerTotal;
    cout << "\nEl paquete numero " << paqueteMenosHoras << " de la aventura tipo " << aventuraPaqueteMenosHoras
        << " fue el paquete con menos horas.";
    cout << "\n------------------------------------------------------------------";
    cout << "\n------------------------------------------------------------------" << endl;
    return 0;
}
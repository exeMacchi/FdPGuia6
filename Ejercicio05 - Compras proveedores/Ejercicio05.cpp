// 5. Una empresa registró las compras realizadas a sus distintos proveedores durante todo el año anterior. 
//    Para cada compra se registraron los siguientes datos:
//       • Número de proveedor(número de cuatro cifras no correlativo).
//       • Día (1 a 31).
//       • Mes (1 a 12).
//       • Tipo de Factura (Responsable inscripto: "A" / Consumidor Final: "B" / Monotributo: "C").
//       • Número de Producto (número no correlativo).
//       • Cantidad comprada.
//       • Precio unitario del producto.
//    Este lote finaliza con un registro con número de proveedor igual a 0.
//    Los registros están agrupados por número de proveedor. En el lote anterior no aparecen registros de 
//    los proveedores a los que que no se les hayan realizado compras.
// 
//    Se pide determinar e informar :
//       a. El monto máximo registrado en una sola compra por cada proveedor y el número de proveedor al que se 
//          le compró.
//       b. La inversión total de todo el año discriminada por tipo de factura.
//       c. La compra con menor monto registrada durante el mes de Agosto junto al número de producto comprado.
//       d. La cantidad de compras que se realizaron a cada proveedor.
//       e. El número de producto con mayor cantidad comprada en una sola compra y en qué proveedor se compró.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numProveedor, numProveedorAct, Dia, Mes, numProducto, cantComprada, numProveedorMax, 
        numProductoMin, Compras, mayorCompra = 0, numProductoMayorCompra, numProveedorMayorCompra;
    float precioUnitario, montoCompra, montoMax, montoMin, TFA = 0, TFB = 0, TFC = 0;
    char TFactura;
    bool Agosto = false;

    cout << "Numero de proveedor: "; cin >> numProveedor;
    if (numProveedor != 0) {
        cout << "Dia: "; cin >> Dia;
        cout << "Mes (1 a 12): "; cin >> Mes;
        cout << "Tipo de factura (A, B o C): "; cin >> TFactura;
        if (TFactura == 'A' || TFactura == 'a' || TFactura == 'B' || TFactura == 'b' || TFactura == 'C' 
            || TFactura == 'c') {
            cout << "Numero de producto: "; cin >> numProducto;
            cout << "Cantidad comprada: "; cin >> cantComprada;
            cout << "Precio unitario del producto: $"; cin >> precioUnitario;
        }
        else {
            cout << "\nError: fallo tipografico del tipo de factura." << endl;
            return 0;
        }
    }
    else {
        cout << "\nError: el primer lote no puede tener un numero de proveedor igual a 0." << endl;
        return 0;
    }

    while (numProveedor != 0) {
        numProveedorAct = numProveedor;
        montoMax = 0;
        Compras = 0;

        while (numProveedor == numProveedorAct) {
            Compras++;
            montoCompra = cantComprada * precioUnitario;

            if (montoCompra > montoMax) {
                montoMax = montoCompra;
                numProveedorMax = numProveedorAct;
            }

            switch (TFactura) {
                case 'A': case 'a':
                    TFA += montoCompra;
                    break;

                case 'B': case 'b':
                    TFB += montoCompra;
                    break;
                case 'C': case 'c':
                    TFC += montoCompra;
                    break;
                default:
                    cout << "Error: fallo tipografico del tipo de factura." << endl;
                    return 0;
            }

            if (Mes == 8) {
                if (!Agosto) {
                    montoMin = montoCompra;
                    numProductoMin = numProducto;
                    Agosto = true;
                }
                else if (montoCompra < montoMin) {
                    montoMin = montoCompra;
                    numProductoMin = numProducto;
                }
            }

            if (cantComprada > mayorCompra) {
                mayorCompra = cantComprada;
                numProductoMayorCompra = numProducto;
                numProveedorMayorCompra = numProveedorAct;
            }

            cout << "\nNumero de proveedor: "; cin >> numProveedor;
            if (numProveedor == numProveedorAct) {
                cout << "Dia: "; cin >> Dia;
                cout << "Mes (1 a 12): "; cin >> Mes;
                cout << "Tipo de factura (A, B o C): "; cin >> TFactura;
                cout << "Numero de producto: "; cin >> numProducto;
                cout << "Cantidad comprada: "; cin >> cantComprada;
                cout << "Precio unitario del producto: $"; cin >> precioUnitario;
            }
        }

        cout << "\n--------------------------------------------------------";
        cout << "\nImporte maximo registrado para el proveedor " << numProveedorAct << ": $" << montoMax;
        cout << "\nNumero total de compras al proveedor " << numProveedorAct << ": " << Compras;
        cout << "\n--------------------------------------------------------" << endl;

        if (numProveedor != 0) {
            cout << "\nNumero de proveedor: "; cin >> numProveedor;
            cout << "Dia: "; cin >> Dia;
            cout << "Mes (1 a 12): "; cin >> Mes;
            cout << "Tipo de factura (A, B o C): "; cin >> TFactura;
            cout << "Numero de producto: "; cin >> numProducto;
            cout << "Cantidad comprada: "; cin >> cantComprada;
            cout << "Precio unitario del producto: $"; cin >> precioUnitario;
        }

    }

    cout << "\n--------------------------------------------------------";
    cout << "\n--------------------------------------------------------" << endl;

    cout << "\nImporte total de la inversion (Factura A): $" << TFA;
    cout << "\nImporte total de la inversion (Factura B): $" << TFB;
    cout << "\nImporte total de la inversion (Factura C): $" << TFC << endl;

    if (Agosto) {
        cout << "\nLa compra de menor importe registrada durante el mes de agosto: $" << montoMin 
             << " (numero de producto " << numProductoMin << ")" << endl;
    }
    else {
        cout << "\nNo se registraron compras en el mes de agosto." << endl;
    }

    cout << "\nEl producto con la mayor cantidad adquirida en una sola compra fue el numero " << numProductoMayorCompra 
         << " por el proveedor " << numProveedorMayorCompra << " con " << mayorCompra << " unidades." << endl;

    cout << "\n--------------------------------------------------------";
    cout << "\n--------------------------------------------------------" << endl;
    return 0;
}

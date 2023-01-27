// 1. Se dispone de una lista de 10 grupos de números enteros separados entre ellos por ceros. 
//    Se pide determinar e informar:
//       a. El número de grupo con mayor porcentaje de números impares positivos respecto al total de números 
//          que forman el grupo.
//       b. Para cada grupo, el último número primo y en qué orden apareció en ese grupo.
//          Si en un grupo no hubiera números primos, informarlo con un cartel aclaratorio.
//       c. Informar cuántos grupos están formados por todos números ordenados de mayor a menor.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int N, PorcenImp = 0, GMPImp = 0;
    bool banNum = false;
    bool banBanNum = false;
    int GOMAM = 0;

    cout << "--------------------------- Grupo 1 ---------------------------";
    cout << "\n1. Ingrese el primer numero del grupo: ";
    cin >> N;

    for (int i = 0; i < 3; i++) {
        int G = i + 1;
        int conNum = 0, conImp = 0;
        int CNT = 0, PImpP = 0;
        int Pos = 0, posPri = 0, UNPri = 0;
        int MaxN;
        bool GNO = false;
        bool Par = false, Primo = false;

        if (N != 0) {
            banNum = true;
        }

        while (N != 0) {
            Pos++;
            int conPri = 0;
            if (N > 0) {
                if (N % 2 == 0) {
                    Par = true;
                }
                else {
                    Par = false;
                }

                if (!Par) {
                    conImp++;
                }
                else {
                    conNum++;
                }
            }
            else {
                conNum++;
            }

            
            for (int i = 1; i <= N; i++) {
                if (N % i == 0) {
                    conPri++;
                }
            }
            if (conPri == 2) {
                Primo = true;
            }
            else {
                Primo = false;
            }

            if (Primo) {
                UNPri = N;
                posPri = Pos;
            }

            if (Pos == 1) {
                MaxN = N;
            }
            else if (N < MaxN) {
                MaxN = N;
            }
            else {
                GNO = true;
            }

            cout << Pos + 1 << ". Ingrese otro numero (presione '0' para finalizar el proceso): ";
            cin >> N;

        }

        if (banNum) {
            banBanNum = true;
            CNT = conImp + conNum;
            PImpP = conImp * 100 / CNT;
            if (PImpP > PorcenImp) {
                PorcenImp = PImpP;
                GMPImp = G;
            }
            if (UNPri != 0) {
                cout << "\nEl ultimo numero primo es " << UNPri << " y su posicion es " << posPri << "." << endl;
            }
            else {
                cout << "\nEn este grupo, no se escribio ningun numero primo." << endl;
            }
            if (!GNO) {
                GOMAM++;
            }
        }

        banNum = false;

        if (i != 2) {
            cout << "\n--------------------------- Grupo " << G + 1 << " ---------------------------";
            cout << "\n1. Ingrese el primer numero del grupo: ";
            cin >> N;
        }
    }

    if (banBanNum) {
        cout << "\n---------------------------------------------------------------";
        if (GMPImp != 0) {
            cout << "\nEl grupo con mayor porcentaje de numeros impares positivos: grupo " << GMPImp << endl;
        }
        else {
            cout << "\nNo se escribieron números impares positivos en ningún grupo." << endl;
        }
        if (GOMAM != 0) {
            cout << "Cantidad de grupos ordenados de mayor a menor: " << GOMAM << endl;
        }
        else {
            cout << "Ningun grupo esta ordenado de mayor a menor." << endl;
        }
    }
    else {
        cout << "\n---------------------------------------------------------------";
        cout << "\nError: ningun numero fue registrado en ningun grupo." << endl;
    }

    return 0;
}

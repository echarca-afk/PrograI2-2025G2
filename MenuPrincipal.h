#include <iostream>
using namespace std;

void mostrarMenu(string RegistroTXT) {
    int opcion;
    do {
        system("cls");
        cout << "\n=====================================\n";
        cout << "   SISTEMA VETERINARIA GO CAN\n";
        cout << "=====================================\n";
        cout << "1. Registrar Duenio\n";
        cout << "2. Registrar Mascota\n";
        cout << "3. Registrar Consulta\n";
        cout << "4. Registrar Tratamiento\n";
        cout << "5. Registrar Historial Clinico\n";
        cout << "6. Registrar Facturacion\n";
        cout << "7. Mostrar Reportes\n";
        cout << "0. Salir\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nFuncion para registrar duenio\n";
                break;
            case 2:
                cout << "\nFuncion para registrar mascota\n";
                break;
            case 3:
                cout << "\nFuncion para registrar consulta\n";
                break;
            case 4:
                cout << "\nFuncion para registrar tratamiento\n";
                break;
            case 5:
                cout << "\nFuncion para registrar historial clínico\n";
                break;
            case 6:
                cout << "\nFuncion para registrar facturación\n";
                break;
            case 7:
                cout << "\nFuncion para mostrar reportes\n";
                break;
            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }
    } while(opcion != 0);
}
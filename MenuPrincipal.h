#include <bits/stdc++.h>
#include "ABM_Duenio.h"
#include "ABM_Mascota.h"
#include "ABM_Consulta.h"
#include "ABM_Diagnostico.h"
#include "ABM_Tratamiento.h"
#include "ABM_Historial.h"
#include "ABM_Facturacion.h"
#include "Reportes.h"
using namespace std;

void mostrarMenu(string ArchivoDuenios, string ArchivoMascotas, string ArchivoConsultas, string ArchivoDiagnosticos, string ArchivoTratamientos, string ArchivoHistorialClinico, string ArchivoFacturacion, string ArchivoVeterinarios) {
    int opcion=0;
    do {
        system("cls");
        cout << "\n=====================================\n";
        cout << "   SISTEMA VETERINARIA GO CAN\n";
        cout << "=====================================\n";
        cout << "1. ABM Duenio\n";
        cout << "2. ABM Mascota\n";
        cout << "3. ABM Consulta\n";
        cout << "4. ABM Diagnostico\n";
        cout << "5. ABM Tratamiento\n";
        cout << "6. ABM Historial Clinico\n";
        cout << "7. ABM Facturacion\n";
        cout << "8. Mostrar Reportes\n";
        cout << "0. Salir\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ABM_Duenio(ArchivoDuenios);
                break;
            case 2:
                ABM_Mascota(ArchivoMascotas);
                break;
            case 3:
                ABM_Consulta(ArchivoConsultas);
                break;
            case 4:
                ABM_Diagnostico(ArchivoDiagnosticos);
                break;
            case 5:
                ABM_Tratamiento(ArchivoTratamientos);
                break;
            case 6:
                ABM_Historial(ArchivoHistorialClinico);
                break;
            case 7:
                ABM_Factura(ArchivoFacturacion);
                break;
            case 8:
                MostrarReportes(ArchivoDuenios, archivoMascotas, archivoConsultas, archivoHistorial, archivoFacturacion, archivoVeterinarios);
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while(opcion != 0);
}
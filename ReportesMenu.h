#include <iostream>
#include <fstream>
#include <string>
#include "ReporteDuenios.h"
#include "ReporteMascotas.h"
#include "ReporteConsultasPorFecha.h"
#include "ReporteHistorialPorMascota.h"
#include "ReporteFacturacion.h"
#include "ReporteVeterinarios.h"
using namespace std;
void mostrarMenu(string archivoDuenios, string archivoMascotas, string archivoConsultas, string archivoDiagnosticos, string archivoTratamientos,  string archivoHistorial, string archivoFacturacion, string archivoVeterinarios);
void MostrarReportes(string archivoDuenios, string archivoMascotas, string archivoConsultas, string archivoDiagnosticos, string archivoTratamientos, string archivoHistorial, string archivoFacturacion, string archivoVeterinarios)
{
    mostrarMenu(archivoDuenios, archivoMascotas, archivoConsultas, archivoDiagnosticos, archivoTratamientos,archivoHistorial, archivoFacturacion, archivoVeterinarios);
}
void mostrarMenu(string archivoDuenios, string archivoMascotas, string archivoConsultas, string archivoDiagnosticos, string archivoTratamientos, string archivoHistorial, string archivoFacturacion, string archivoVeterinarios) {
    int opcion;
    string archivoTxt = "ReporteGeneral.txt";

    do 
    {
        system("cls");
        cout << "\n=====================================\n";
        cout << "       MENU DE REPORTES - GO CAN\n";
        cout << "=====================================\n";
        cout << "1. Reporte de Dueños Registrados\n";
        cout << "2. Reporte de Mascotas Registradas\n";
        cout << "3. Reporte de Consultas Diagnóstico/Tratamiento por Fecha\n";
        cout << "4. Reporte de Historial Clínico por Mascota\n";
        cout << "5. Reporte de Facturación Emitida\n";
        cout << "6. Reporte de Veterinarios y Consultas Atendidas\n";
        cout << "0. Volver al menú principal\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) 
        {
            case 1: 
                ReporteDuenios(archivoDuenios, archivoTxt); 
                break;
            case 2: 
                ReporteMascotas(archivoMascotas, archivoDuenios,archivoTxt); 
                break;
            case 3: 
                ReporteConsultasPorFecha(archivoConsultas,archivoDiagnosticos,archivoTratamientos, archivoTxt); 
                break;
            case 4: 
                ReporteHistorialClinico(archivoHistorial, archivoTxt); 
                break;
            case 5: 
                ReporteFacturacion(archivoFacturacion, archivoTxt); 
                break;
            case 6: 
                ReporteVeterinarios(archivoTratamientos, archivoTxt); 
                break;
            case 0: 
                cout << "Volviendo al menú principal...\n"; 
                break;
            default: 
                cout << "Opción inválida.\n"; system("pause");
        }
    } while(opcion != 0);

}


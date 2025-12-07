#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void ReporteDuenios(string archivoDuenios, string archivoTxt);
void ReporteMascotas(string archivoMascotas, string archivoTxt);
void ReporteConsultasPorFecha(string archivoConsultas, string archivoTxt);
void ReporteHistorialPorMascota(string archivoHistorial, string archivoTxt);
void ReporteFacturacion(string archivoFacturacion, string archivoTxt);
void ReporteVeterinarios(string archivoTratamientos, string archivoTxt);

void MostrarReportes(string archivoDuenios, string archivoMascotas, string archivoConsultas, string archivoHistorial, string archivoFacturacion, string archivoVeterinarios){

    mostrarMenu(archivoDuenios, archivoMascotas, archivoConsultas, archivoHistorial, archivoFacturacion, archivoVeterinarios);
}

void mostrarMenu(string archivoDuenios, string archivoMascotas, string archivoConsultas, string archivoHistorial, string archivoFacturacion, string archivoVeterinarios) {
    int opcion;
    string archivoTxt = "ReporteGeneral.txt";

    do {
        system("cls");
        cout << "\n=====================================\n";
        cout << "       MENU DE REPORTES - GO CAN\n";
        cout << "=====================================\n";
        cout << "1. Reporte de Dueños Registrados\n";
        cout << "2. Reporte de Mascotas Registradas\n";
        cout << "3. Reporte de Consultas Diagnóstico/Tratamiento por Fecha\n";
        cout << "5. Reporte de Historial Clínico por Mascota\n";
        cout << "6. Reporte de Facturación Emitida\n";
        cout << "10. Reporte de Veterinarios y Consultas Atendidas\n";
        cout << "0. Volver al menú principal\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: 
            ReporteDuenios(archivoDuenios, archivoTxt); 
            break;
            case 2: 
            ReporteMascotas(archivoMascotas, archivoTxt); 
            break;
            case 3: 
            ReporteConsultasPorFecha(archivoConsultas, archivoTxt); 
            break;
            case 4: 
            ReporteHistorialPorMascota(archivoHistorial, archivoTxt); 
            break;
            case 5: 
            ReporteFacturacion(archivoFacturacion, archivoTxt); 
            break;
            case 6: 
            ReporteVeterinarios(archivoVeterinarios, archivoTxt); 
            break;
            case 0: cout << "Volviendo al menú principal...\n"; 
            break;
            default: 
            cout << "Opción inválida.\n"; system("pause");
        }
    } while(opcion != 0);
}
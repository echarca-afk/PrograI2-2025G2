#include <iostream>
#include <fstream>
#include <string>
#include "ABM_Duenio.h"
#include "ABM_Mascota.h"
#include "ABM_Consulta.h"
#include "ABM_Diagnostico.h"
#include "ABM_Tratamiento.h"
#include "ABM_Historial.h"
#include "ABM_Facturacion.h"
#include "ReportesMenu.h"
using namespace std;

void mostrarMenuPrincipal(string ArchivoDuenios, string ArchivoMascotas, string ArchivoConsultas, string ArchivoDiagnosticos, string ArchivoTratamientos, string ArchivoHistorialClinico, string ArchivoFacturacion, string ArchivoVeterinarios);
int main()
{
    string ArchivoDuenios = "Duenios.bin";
    string ArchivoMascotas = "Mascotas.bin";
    string ArchivoConsultas = "Consultas.bin";
    string ArchivoDiagnosticos = "Diagnosticos.bin";
    string ArchivoTratamientos = "Tratamientos.bin";
    string ArchivoHistorialClinico = "HistorialClinico.bin";
    string ArchivoFacturacion = "Facturacion.bin";
    string ArchivoVeterinarios = "Veterinarios.bin";
    string ArchivoVeterinariaGoCanTXT = "ArchivoGenericoVeterinaria.txt";
    mostrarMenuPrincipal(ArchivoDuenios, ArchivoMascotas, ArchivoConsultas, ArchivoDiagnosticos, ArchivoTratamientos, ArchivoHistorialClinico, ArchivoFacturacion, ArchivoVeterinarios);
    return 0;
}
void mostrarMenuPrincipal(string ArchivoDuenios, string ArchivoMascotas, string ArchivoConsultas, string ArchivoDiagnosticos, string ArchivoTratamientos, string ArchivoHistorialClinico, string ArchivoFacturacion, string ArchivoVeterinarios) {
    int opcion=0;
    do 
    {
        system("chcp 65001");
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
                MostrarReportes(ArchivoDuenios, ArchivoMascotas, ArchivoConsultas, ArchivoDiagnosticos,ArchivoTratamientos,ArchivoHistorialClinico, ArchivoFacturacion, ArchivoVeterinarios);
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while(opcion != 0);
}
/*Duenio = datos de la persona responsable
Mascota = los datos básicos del animal
Consulta = cada visita/chequeo
Tratamiento = medicinas o procesos que recibe
HistorialClinico = junta consultas + tratamientos
RegistroVeterinaria = une mascota + historial en un solo registro*/

/* cout << "\n=====================================\n";
        cout << "       MENU DE REPORTES - GO CAN\n";
        cout << "=====================================\n";
        cout << "1. Reporte de Dueños Registrados\n";
        cout << "2. Reporte de Mascotas Registradas\n";
        cout << "3. Reporte de Consultas Diagnnostico tratamiento por Fecha\n";
        cout << "4. Reporte de Historial Clínico por Mascota\n";
        cout << "5. Reporte de Facturación Emitida\n";
        cout << "5. Reporte de Veterinarios y Consultas Atendidas\n";
        cout << "0. Volver al menú principal\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opción: ";*/


#include <bits/stdc++.h>
#include "ABM_Duenio.h"
#include "ABM_Mascota.h"
#include "ABM_Consulta.h"
#include "ABM_Diagnostico.h"
#include "ABM_Tratamiento.h"
#include "ABM_Historial.h"
#include "ABM_Facturacion.h"
#include "ReportesMenu.h"
using namespace std;
struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct Duenio{
    int idDuenio;  
    char nombre[30];
    char apellido[30];
    char direccion[50];
    char telefono[15];
    char email[30];
    bool eliminado;
};
struct Mascota{
    int idMascota;    // ID único de la mascota
    int idDuenio;
    char nombre[30];
    char especie[20]; 
    char raza[30];
    char sexo[10]; 
    int edad;
    bool eliminado;   
};
struct consulta{
    int idConsulta;
    int idMascota;
    fecha fecha_consulta;
    char motivo[100];
    bool eliminado;
};
struct Diagnostico
{
    int idDiagnostico;
    int idMascota;
    fecha fechaDiagnostico;
    char diagnostico[300];
    bool eliminado;
};
struct Tratamiento
{
    int idTratamiento;
    int idDiagnostico;
    char nombreVeterinario[100];
    char tratamiento[300];
    float monto;
    bool eliminado;
};
struct HistorialClinico{
    int idHistorial; 
    int idMascota;  
    int idConsulta;
    fecha fechaHistorial;
    char diagnostico[100];
    char veterinario[30];
    int idTratamiento;
    bool eliminado;
};
struct Factura {
    int nroFactura;            
    int idTratamiento;         
    char descripcion[200];      
    float monto;                
    int nit;                    
    char beneficiario[100];     
    fecha fechaFactura;       
    char formaPago[30];        
    bool eliminado;
};
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
                MostrarReportes(ArchivoDuenios, ArchivoMascotas, ArchivoConsultas, ArchivoHistorialClinico, ArchivoFacturacion, ArchivoVeterinarios);
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while(opcion != 0);
}
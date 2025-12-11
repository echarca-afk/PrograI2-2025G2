#include <bits/stdc++.h>
#include "MenuPrincipal.h"

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
int main(){
    string ArchivoDuenios = "Duenios.bin";
    string ArchivoMascotas = "Mascotas.bin";
    string ArchivoConsultas = "Consultas.bin";
    string ArchivoDiagnosticos = "Diagnosticos.bin";
    string ArchivoTratamientos = "Tratamientos.bin";
    string ArchivoHistorialClinico = "HistorialClinico.bin";
    string ArchivoFacturacion = "Facturacion.bin";
    string ArchivoVeterinarios = "Veterinarios.bin";
    string ArchivoVeterinariaGoCanTXT = "ArchivoGenericoVeterinaria.txt";
    mostrarMenu(ArchivoDuenios, ArchivoMascotas, ArchivoConsultas, ArchivoDiagnosticos, ArchivoTratamientos, ArchivoHistorialClinico, ArchivoFacturacion, ArchivoVeterinarios);
    return 0;
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

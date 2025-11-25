#include <bits/stdc++.h>
#include "MenuPrincipal.h"
using namespace std;
struct Duenio{
    int idDuenio;  
    char nombre[30];
    char apellido[30];
    char direccion[50];
    char telefono[15];
    char email[30];
};
struct Mascota{
    int idMascota;    // ID único de la mascota
    int idDuenio;
    char nombre[30];
    char especie[20]; 
    char raza[30];
    char sexo[10]; 
    int edad;      
};

struct consulta{
    int idConsulta;
    int idMascota;
    char fecha_consulta[11];
    char motivo[100];
};

struct Tratamiento {
    int idTratamiento;
    char nombre[30];
    char descripcion[100];
    float costo;
};

struct HistorialClinico{
    int idHistorial; 
    int idMascota;  
    int idConsulta;
    char fecha[11];   // Formato: DD/MM/AAAA
    char diagnostico[100];
    char veterinario[30];
    int idTratamiento;
};

struct facturacion{
    int idTratamiento;
    float costo;
    int nit;
    char beneficiario[100];
    char fecha_facturacion[11];
};
/*Duenio = datos de la persona responsable
Mascota = los datos básicos del animal
Consulta = cada visita/chequeo
Tratamiento = medicinas o procesos que recibe
HistorialClinico = junta consultas + tratamientos
RegistroVeterinaria = une mascota + historial en un solo registro*/
int main(){
    string RegistroTXT = "RegistroVeterinaria.txt";
    mostrarMenu(RegistroTXT);
    return 0;
}

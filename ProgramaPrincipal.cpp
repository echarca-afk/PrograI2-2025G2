#include <iostream>
#include "libEmiliano.h"
using namespace std;
struct Duenio {
    int idDuenio;      // ID único del dueño
    char nombre[30];
    char apellido[30];
    char direccion[50];
    char telefono[15];
    char email[30];
};
struct Mascota {
    int idMascota;    // ID único de la mascota
    int idDuenio;     // Relación con dueño
    char nombre[30];
    char especie[20]; // Ej: perro, gato
    char raza[30];
    char sexo[10];    // Ej: macho, hembra
    int edad;         // En años
};
struct HistorialClinico {
    int idHistorial;  // ID único del historial
    int idMascota;    // Relación con mascota
    char fecha[11];   // Formato: DD/MM/AAAA
    char motivoConsulta[50];
    char diagnostico[100];
    char tratamiento[100];
    char veterinario[30];
};

int main(){
    
    return 0;
}

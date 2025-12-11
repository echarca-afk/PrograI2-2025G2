#include <bits/stdc++.h>
using namespace std;
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

void ReporteMascotas(string archivoMascotas, string archivoDuenios) {
    Mascota m;
    ifstream archivo(archivoMascotas, ios::binary);
    ofstream reporte("ReporteMascotas.txt");
    if (archivo.good()) {
        reporte << "MASCOTAS REGISTRADAS" << endl;
        reporte << "====================" << endl;
        reporte << "ID\tNombre\t\tEspecie\t\tRaza\t\tEdad\tDueño" << endl;
        reporte << "------------------------------------------------------------------------" << endl;
        while (archivo.read((char*)&m, sizeof(Mascota))) {
            if (!m.eliminado) {
                reporte << m.idMascota << "\t"
                        << m.nombre << "\t"
                        << m.especie << "\t"
                        << m.raza << "\t"
                        << m.edad << "\t"
                        << ObtenerNombreDuenio(archivoDuenios, m.idDuenio)
                        << endl;
            }
        }
        reporte << "------------------------------------------------------------------------" << endl;
    }
    archivo.close();
    reporte.close();
}
string ObtenerNombreDuenio(string archivoDuenios, int idDuenio) {
    Duenio _duenio;
    ifstream archivo;
    string nombreCompleto = "";
    archivo.open(archivoDuenios, ios::binary);
    if (archivo.good()) {
        while (archivo.read((char*)&_duenio, sizeof(Duenio))) {
            if (_duenio.idDuenio == idDuenio && !_duenio.eliminado) {
                nombreCompleto = string(_duenio.nombre) + " " + string(_duenio.apellido);
            }
        }
    }
    archivo.close();
    return nombreCompleto;
}

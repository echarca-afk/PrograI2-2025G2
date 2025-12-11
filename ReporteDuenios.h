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
void ReporteDuenios(string archivoDuenios) {
    Duenio d;
    ifstream archivo(archivoDuenios, ios::binary);
    ofstream reporte("ReporteDuenios.txt");
    if (archivo.good()) {
        reporte << "DUEÑOS REGISTRADOS" << endl;
        reporte << "==================" << endl;
        reporte << "ID\tNombre\t\tApellido\t\tDireccion\tTelefono\tEmail" << endl;
        reporte << "------------------------------------------------------------------------" << endl;
        while (archivo.read((char*)&d, sizeof(Duenio))) {
            if (!d.eliminado) {
                reporte << d.idDuenio << "\t" << d.nombre << "\t" << d.apellido
                        << "\t" << d.direccion << "\t" << d.telefono
                        << "\t" << d.email << endl;
            }
        }
        reporte << "------------------------------------------------------------------------" << endl;
    }
    archivo.close();
    reporte.close();
}
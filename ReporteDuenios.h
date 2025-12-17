#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReporteDuenios(string archivoDuenios, string archivoTxt) {
    Duenio d;
    ifstream archivo(archivoDuenios, ios::binary);
    ofstream reporte(archivoTxt);
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
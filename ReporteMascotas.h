#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string ObtenerNombreDuenio(string archivoDuenios, int idDuenio);
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

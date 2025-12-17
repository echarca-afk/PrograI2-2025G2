#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReporteVeterinarios(string archivoTratamientos, string archivoTxt) {
    Tratamiento t;
    ifstream archivo(archivoTratamientos, ios::binary);
    ofstream reporte(archivoTxt);

    if (archivo.good()) {
        reporte << "VETERINARIOS Y CONSULTAS ATENDIDAS" << endl;
        reporte << "==================================" << endl;
        reporte << "Veterinario\tTratamiento\tMonto" << endl;
        reporte << "------------------------------------------------------------------------" << endl;

        while (archivo.read((char*)&t, sizeof(Tratamiento))) {
            if (!t.eliminado) {
                reporte << t.nombreVeterinario << "\t"
                        << t.tratamiento << "\t"
                        << t.monto << endl;
            }
        }

        reporte << "------------------------------------------------------------------------" << endl;
    } else {
        cout << "No se pudo abrir el archivo de tratamientos." << endl;
    }

    archivo.close();
    reporte.close();
}
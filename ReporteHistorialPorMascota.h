#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReporteHistorialClinico(string archivoHistorial, string archivoTxt) {
    HistorialClinico h;
    ifstream archivo(archivoHistorial, ios::binary);
    ofstream reporte(archivoTxt);
    int idMascota;
    cout << "Ingrese el ID de la mascota: ";
    cin >> idMascota;

    if (archivo.good()) {
        reporte << "HISTORIAL CLINICO DE MASCOTA" << endl;
        reporte << "============================" << endl;
        reporte << "ID Historial\tID Mascota\tID Consulta\tFecha\tDiagnostico\tVeterinario\tID Tratamiento" << endl;
        reporte << "------------------------------------------------------------------------" << endl;

        while (archivo.read((char*)&h, sizeof(HistorialClinico))) {
            if (!h.eliminado && h.idMascota == idMascota) {
                reporte << h.idHistorial << "\t" << h.idMascota << "\t" << h.idConsulta
                        << "\t" << h.fechaHistorial.dia << "/" << h.fechaHistorial.mes << "/" << h.fechaHistorial.anio
                        << "\t" << h.diagnostico << "\t" << h.veterinario << "\t" << h.idTratamiento << endl;
            }
        }

        reporte << "------------------------------------------------------------------------" << endl;
        cout << "Reporte generado en: " << archivoTxt << endl;
    } else {
        cout << "No se pudo abrir el archivo de historial clínico." << endl;
    }

    archivo.close();
    reporte.close();
}
#include <bits/stdc++.h>
using namespace std;
struct fecha
{
    int dia;
    int mes;
    int anio;
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
void ReporteHistorialClinico(string archivoHistorial, int idMascota) {
    HistorialClinico h;
    ifstream archivo(archivoHistorial, ios::binary);
    ofstream reporte("ReporteHistorialClinico.txt");
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
    }
    archivo.close();
    reporte.close();
}
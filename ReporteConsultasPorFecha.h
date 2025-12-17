#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string ObtenerDiagnostico(string archivoDiagnosticos, int idMascota);
string ObtenerTratamiento(string archivoTratamientos, int idMascota);
float ObtenerMontoTratamiento(string archivoTratamientos, int idMascota);
void ReporteConsultasPorFecha(string archivoConsultas,string archivoDiagnosticos,string archivoTratamientos,string archivoTxt) {
    Consulta c;
    ifstream archivo(archivoConsultas, ios::binary);
    ofstream reporte(archivoTxt);
    fecha fechaFiltro;
    cout << "Ingrese la fecha (dd mm aaaa): ";
    cin >> fechaFiltro.dia >> fechaFiltro.mes >> fechaFiltro.anio;

    if (archivo.good()) {
        reporte << "CONSULTAS, DIAGNOSTICOS Y TRATAMIENTOS" << endl;
        reporte << "======================================" << endl;
        reporte << "ID Consulta\tID Mascota\tFecha\tMotivo\tDiagnostico\tTratamiento\tMonto" << endl;
        reporte << "------------------------------------------------------------------------" << endl;

        while (archivo.read((char*)&c, sizeof(Consulta))) {
            if (!c.eliminado &&
                c.fecha_consulta.dia == fechaFiltro.dia &&
                c.fecha_consulta.mes == fechaFiltro.mes &&
                c.fecha_consulta.anio == fechaFiltro.anio) {

                string diag = ObtenerDiagnostico(archivoDiagnosticos, c.idMascota);
                string trat = ObtenerTratamiento(archivoTratamientos, c.idMascota);
                float monto = ObtenerMontoTratamiento(archivoTratamientos, c.idMascota);

                reporte << c.idConsulta << "\t" << c.idMascota << "\t"
                        << c.fecha_consulta.dia << "/" << c.fecha_consulta.mes << "/" << c.fecha_consulta.anio
                        << "\t" << c.motivo << "\t" << diag << "\t" << trat << "\t" << monto << endl;
            }
        }

        reporte << "------------------------------------------------------------------------" << endl;
    }
    archivo.close();
    reporte.close();
}
string ObtenerDiagnostico(string archivoDiagnosticos, int idMascota) {
    Diagnostico d;
    ifstream archivo(archivoDiagnosticos, ios::binary);
    string textoDiagnostico = "";
    if (archivo.good()) {
        while (archivo.read((char*)&d, sizeof(Diagnostico))) {
            if (d.idMascota == idMascota && !d.eliminado) {
                textoDiagnostico = d.diagnostico;
            }
        }
    }
    archivo.close();
    return textoDiagnostico;
}
string ObtenerTratamiento(string archivoTratamientos, int idMascota) {
    Tratamiento t;
    ifstream archivo(archivoTratamientos, ios::binary);
    string textoTratamiento = "";
    if (archivo.good()) {
        while (archivo.read((char*)&t, sizeof(Tratamiento))) {
            if (!t.eliminado) {
                textoTratamiento = t.tratamiento;
            }
        }
    }
    archivo.close();
    return textoTratamiento;
}
float ObtenerMontoTratamiento(string archivoTratamientos, int idMascota) {
    Tratamiento t;
    ifstream archivo(archivoTratamientos, ios::binary);
    float monto = 0.0;
    if (archivo.good()) {
        while (archivo.read((char*)&t, sizeof(Tratamiento))) {
            if (!t.eliminado) {
                monto = t.monto;
            }
        }
    }
    archivo.close();
    return monto;
}
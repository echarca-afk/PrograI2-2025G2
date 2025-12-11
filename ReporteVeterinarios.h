#include <bits/stdc++.h>
using namespace std;
struct Tratamiento
{
    int idTratamiento;
    int idDiagnostico;
    char nombreVeterinario[100];
    char tratamiento[300];
    float monto;
    bool eliminado;
};
void ReporteVeterinarios(string archivoTratamientos) {
    Tratamiento t;
    ifstream archivo(archivoTratamientos, ios::binary);
    ofstream reporte("ReporteVeterinarios.txt");

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
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct fecha {
    int dia;
    int mes;
    int anio;
};
struct Diagnostico {
    int idDiagnostico;       // ID único del diagnóstico
    int idMascota;           // Relación con la mascota
    fecha fechaDiagnostico;  // Fecha estructurada
    char diagnostico[300];   // Texto del diagnóstico
    bool eliminado;          // Baja lógica
};
void MenuDiagnosticos(string archivoBin);
void IngresarDiagnostico(string archivoBin);
void MostrarDiagnosticos(string archivoBin);
void EncontrarDiagnostico(string archivoBin);
void ModificarDiagnostico(string archivoBin);
void EliminarDiagnostico(string archivoBin);


void ABM_Diagnostico(string ArchivoDiagnosticos) {
    MenuDiagnosticos(ArchivoDiagnosticos);
}

void MenuDiagnosticos(string archivoBin) {
    int opcion;
    do {
        system("cls");
        cout << "=== ABM DIAGNOSTICOS ===\n";
        cout << "1. Ingresar diagnostico\n";
        cout << "2. Mostrar diagnosticos\n";
        cout << "3. Buscar diagnostico\n";
        cout << "4. Modificar diagnostico\n";
        cout << "5. Eliminar diagnostico\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: IngresarDiagnostico(archivoBin); break;
            case 2: MostrarDiagnosticos(archivoBin); break;
            case 3: EncontrarDiagnostico(archivoBin); break;
            case 4: ModificarDiagnostico(archivoBin); break;
            case 5: EliminarDiagnostico(archivoBin); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; system("pause");
        }
    } while(opcion != 0);
}

void IngresarDiagnostico(string archivoBin) {
    Diagnostico d;
    ofstream archivo(archivoBin, ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "Ingrese ID del diagnostico: ";
    cin >> d.idDiagnostico;
    cout << "Ingrese ID de la mascota: ";
    cin >> d.idMascota;
    cout << "Ingrese fecha del diagnostico:\n";
    cout << "Dia: "; cin >> d.fechaDiagnostico.dia;
    cout << "Mes: "; cin >> d.fechaDiagnostico.mes;
    cout << "Anio: "; cin >> d.fechaDiagnostico.anio;
    cin.ignore();
    cout << "Ingrese descripcion del diagnostico: ";
    cin.getline(d.diagnostico, 300);
    d.eliminado = false;

    archivo.write((char*)&d, sizeof(Diagnostico));
    archivo.close();
    cout << "Diagnostico registrado correctamente.\n";
    system("pause");
}

void MostrarDiagnosticos(string archivoBin) {
    Diagnostico d;
    ifstream archivo(archivoBin, ios::binary);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "=== LISTA DE DIAGNOSTICOS ===\n";
    while (archivo.read((char*)&d, sizeof(Diagnostico))) {
        if (!d.eliminado) {
            cout << "ID Diagnostico: " << d.idDiagnostico << endl;
            cout << "ID Mascota: " << d.idMascota << endl;
            cout << "Fecha: " << d.fechaDiagnostico.dia << "/"
                 << d.fechaDiagnostico.mes << "/"
                 << d.fechaDiagnostico.anio << endl;
            cout << "Descripcion: " << d.diagnostico << endl;
            cout << "--------------------------\n";
        }
    }
    archivo.close();
    system("pause");
}

void EncontrarDiagnostico(string archivoBin) {
    Diagnostico d;
    ifstream archivo(archivoBin, ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del diagnostico a buscar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&d, sizeof(Diagnostico)) && !encontrado) {
        if (d.idDiagnostico == idBuscado && !d.eliminado) {
            cout << "Diagnostico encontrado:\n";
            cout << "ID Mascota: " << d.idMascota << endl;
            cout << "Fecha: " << d.fechaDiagnostico.dia << "/"
                 << d.fechaDiagnostico.mes << "/"
                 << d.fechaDiagnostico.anio << endl;
            cout << "Descripcion: " << d.diagnostico << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Diagnostico no encontrado.\n";
    archivo.close();
    system("pause");
}

void ModificarDiagnostico(string archivoBin) {
    Diagnostico d;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del diagnostico a modificar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&d, sizeof(Diagnostico)) && !encontrado) {
        if (d.idDiagnostico == idBuscado && !d.eliminado) {
            cout << "Diagnostico encontrado. Ingrese nuevos datos:\n";
            cout << "Nueva fecha:\n";
            cout << "Dia: "; cin >> d.fechaDiagnostico.dia;
            cout << "Mes: "; cin >> d.fechaDiagnostico.mes;
            cout << "Anio: "; cin >> d.fechaDiagnostico.anio;
            cin.ignore();
            cout << "Nueva descripcion: ";
            cin.getline(d.diagnostico, 300);

            archivo.seekp(-sizeof(Diagnostico), ios::cur);
            archivo.write((char*)&d, sizeof(Diagnostico));
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Diagnostico no encontrado.\n";
    archivo.close();
    system("pause");
}

void EliminarDiagnostico(string archivoBin) {
    Diagnostico d;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del diagnostico a eliminar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&d, sizeof(Diagnostico)) && !encontrado) {
        if (d.idDiagnostico == idBuscado && !d.eliminado) {
            d.eliminado = true;
            archivo.seekp(-sizeof(Diagnostico), ios::cur);
            archivo.write((char*)&d, sizeof(Diagnostico));
            cout << "Diagnostico eliminado.\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Diagnostico no encontrado.\n";
    archivo.close();
    system("pause");
}
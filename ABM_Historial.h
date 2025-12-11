#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct fecha {
    int dia;
    int mes;
    int anio;
};
struct HistorialClinico {
    int idHistorial;       // ID único del historial
    int idMascota;         // Relación con la mascota
    int idConsulta;        // Relación con la consulta
    fecha fechaHistorial;  // Fecha estructurada
    char diagnostico[100]; // Diagnóstico
    char veterinario[30];  // Nombre del veterinario
    int idTratamiento;     // Relación con tratamiento
    bool eliminado;        // Baja lógica
};
void MenuHistorial(string archivoBin);
void IngresarHistorial(string archivoBin);
void MostrarHistoriales(string archivoBin);
void EncontrarHistorial(string archivoBin);
void ModificarHistorial(string archivoBin);
void EliminarHistorial(string archivoBin);

void ABM_Historial(string ArchivoHistorialClinico) {
    MenuHistorial(ArchivoHistorialClinico);
}
void MenuHistorial(string archivoBin) {
    int opcion;
    do {
        system("cls");
        cout << "=== ABM HISTORIAL CLINICO ===\n";
        cout << "1. Ingresar historial\n";
        cout << "2. Mostrar historiales\n";
        cout << "3. Buscar historial\n";
        cout << "4. Modificar historial\n";
        cout << "5. Eliminar historial\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: 
                IngresarHistorial(archivoBin); 
                break;
            case 2: 
                MostrarHistoriales(archivoBin); 
                break;
            case 3: 
                EncontrarHistorial(archivoBin); 
                break;
            case 4: 
                ModificarHistorial(archivoBin); 
                break;
            case 5: 
                EliminarHistorial(archivoBin); 
                break;
            case 0: 
                cout << "Saliendo...\n"; 
                break;
            default: 
                cout << "Opcion invalida.\n"; 
                system("pause");
        }
    } while(opcion != 0);
}

void IngresarHistorial(string archivoBin) {
    HistorialClinico h;
    ofstream archivo(archivoBin, ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "Ingrese ID del historial: ";
    cin >> h.idHistorial;
    cout << "Ingrese ID de la mascota: ";
    cin >> h.idMascota;
    cout << "Ingrese ID de la consulta: ";
    cin >> h.idConsulta;
    cout << "Ingrese ID del tratamiento: ";
    cin >> h.idTratamiento;
    cout << "Fecha del historial:\n";
    cout << "Dia: "; cin >> h.fechaHistorial.dia;
    cout << "Mes: "; cin >> h.fechaHistorial.mes;
    cout << "Anio: "; cin >> h.fechaHistorial.anio;
    cin.ignore();
    cout << "Diagnostico: ";
    cin.getline(h.diagnostico, 100);
    cout << "Veterinario: ";
    cin.getline(h.veterinario, 30);
    h.eliminado = false;

    archivo.write((char*)&h, sizeof(HistorialClinico));
    archivo.close();
    cout << "Historial registrado correctamente.\n";
    system("pause");
}

void MostrarHistoriales(string archivoBin) {
    HistorialClinico h;
    ifstream archivo(archivoBin, ios::binary);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "=== LISTA DE HISTORIALES CLINICOS ===\n";
    while (archivo.read((char*)&h, sizeof(HistorialClinico))) {
        if (!h.eliminado) {
            cout << "--------------------------\n";
            cout << "ID Historial: " << h.idHistorial << endl;
            cout << "ID Mascota: " << h.idMascota << endl;
            cout << "ID Consulta: " << h.idConsulta << endl;
            cout << "ID Tratamiento: " << h.idTratamiento << endl;
            cout << "Fecha: " << h.fechaHistorial.dia << "/"
                 << h.fechaHistorial.mes << "/"
                 << h.fechaHistorial.anio << endl;
            cout << "Diagnostico: " << h.diagnostico << endl;
            cout << "Veterinario: " << h.veterinario << endl;
        }
    }
    archivo.close();
    system("pause");
}

void EncontrarHistorial(string archivoBin) {
    HistorialClinico h;
    ifstream archivo(archivoBin, ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del historial a buscar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&h, sizeof(HistorialClinico)) && !encontrado) {
        if (h.idHistorial == idBuscado && !h.eliminado) {
            cout << "Historial encontrado:\n";
            cout << "ID Mascota: " << h.idMascota << endl;
            cout << "ID Consulta: " << h.idConsulta << endl;
            cout << "ID Tratamiento: " << h.idTratamiento << endl;
            cout << "Fecha: " << h.fechaHistorial.dia << "/"
                 << h.fechaHistorial.mes << "/"
                 << h.fechaHistorial.anio << endl;
            cout << "Diagnostico: " << h.diagnostico << endl;
            cout << "Veterinario: " << h.veterinario << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Historial no encontrado.\n";
    archivo.close();
    system("pause");
}

void ModificarHistorial(string archivoBin) {
    HistorialClinico h;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del historial a modificar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&h, sizeof(HistorialClinico)) && !encontrado) {
        if (h.idHistorial == idBuscado && !h.eliminado) {
            cout << "Historial encontrado. Ingrese nuevos datos:\n";
            cout << "Nueva fecha:\n";
            cout << "Dia: "; cin >> h.fechaHistorial.dia;
            cout << "Mes: "; cin >> h.fechaHistorial.mes;
            cout << "Anio: "; cin >> h.fechaHistorial.anio;
            cin.ignore();
            cout << "Nuevo diagnostico: ";
            cin.getline(h.diagnostico, 100);
            cout << "Nuevo veterinario: ";
            cin.getline(h.veterinario, 30);
            cout << "Nuevo ID de tratamiento: ";
            cin >> h.idTratamiento;

            archivo.seekp(-sizeof(HistorialClinico), ios::cur);
            archivo.write((char*)&h, sizeof(HistorialClinico));
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Historial no encontrado.\n";
    archivo.close();
    system("pause");
}

void EliminarHistorial(string archivoBin) {
    HistorialClinico h;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del historial a eliminar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&h, sizeof(HistorialClinico)) && !encontrado) {
        if (h.idHistorial == idBuscado && !h.eliminado) {
            h.eliminado = true;
            archivo.seekp(-sizeof(HistorialClinico), ios::cur);
            archivo.write((char*)&h, sizeof(HistorialClinico));
            cout << "Historial eliminado.\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Historial no encontrado.\n";
    archivo.close();
    system("pause");
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Tratamiento {
    int idTratamiento;          // ID único del tratamiento
    int idDiagnostico;          // Relación con diagnóstico
    char nombreVeterinario[100];// Nombre del veterinario
    char tratamiento[300];      // Detalle del tratamiento
    float monto;                // Costo del tratamiento
    bool eliminado;         
};
void MenuTratamientos(string archivoBin);
void IngresarTratamiento(string archivoBin);
void MostrarTratamientos(string archivoBin);
void EncontrarTratamiento(string archivoBin);
void ModificarTratamiento(string archivoBin);
void EliminarTratamiento(string archivoBin);


void ABM_Tratamiento(string ArchivoTratamientos) {
    MenuTratamientos(ArchivoTratamientos);
}
void MenuTratamientos(string archivoBin) {
    int opcion=0;
    do {
        system("cls");
        cout << "=== ABM TRATAMIENTOS ===\n";
        cout << "1. Ingresar tratamiento\n";
        cout << "2. Mostrar tratamientos\n";
        cout << "3. Buscar tratamiento\n";
        cout << "4. Modificar tratamiento\n";
        cout << "5. Eliminar tratamiento\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: IngresarTratamiento(archivoBin); break;
            case 2: MostrarTratamientos(archivoBin); break;
            case 3: EncontrarTratamiento(archivoBin); break;
            case 4: ModificarTratamiento(archivoBin); break;
            case 5: EliminarTratamiento(archivoBin); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; system("pause");
        }
    } while(opcion != 0);
}

void IngresarTratamiento(string archivoBin) {
    Tratamiento t;
    ofstream archivo(archivoBin, ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "Ingrese ID del tratamiento: ";
    cin >> t.idTratamiento;
    cout << "Ingrese ID del diagnostico: ";
    cin >> t.idDiagnostico;
    cin.ignore();
    cout << "Nombre del veterinario: ";
    cin.getline(t.nombreVeterinario, 100);
    cout << "Detalle del tratamiento: ";
    cin.getline(t.tratamiento, 300);
    cout << "Monto: ";
    cin >> t.monto;
    t.eliminado = false;

    archivo.write((char*)&t, sizeof(Tratamiento));
    archivo.close();
    cout << "Tratamiento registrado correctamente.\n";
    system("pause");
}

void MostrarTratamientos(string archivoBin) {
    Tratamiento t;
    ifstream archivo(archivoBin, ios::binary);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "=== LISTA DE TRATAMIENTOS ===\n";
    while (archivo.read((char*)&t, sizeof(Tratamiento))) {
        if (!t.eliminado) {
            cout << "--------------------------\n";
            cout << "ID Tratamiento: " << t.idTratamiento << endl;
            cout << "ID Diagnostico: " << t.idDiagnostico << endl;
            cout << "Veterinario: " << t.nombreVeterinario << endl;
            cout << "Detalle: " << t.tratamiento << endl;
            cout << "Monto: " << t.monto << endl;
        }
    }
    archivo.close();
    system("pause");
}

void EncontrarTratamiento(string archivoBin) {
    Tratamiento t;
    ifstream archivo(archivoBin, ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del tratamiento a buscar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&t, sizeof(Tratamiento)) && !encontrado) {
        if (t.idTratamiento == idBuscado && !t.eliminado) {
            cout << "Tratamiento encontrado:\n";
            cout << "ID Diagnostico: " << t.idDiagnostico << endl;
            cout << "Veterinario: " << t.nombreVeterinario << endl;
            cout << "Detalle: " << t.tratamiento << endl;
            cout << "Monto: " << t.monto << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Tratamiento no encontrado.\n";
    archivo.close();
    system("pause");
}

void ModificarTratamiento(string archivoBin) {
    Tratamiento t;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del tratamiento a modificar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&t, sizeof(Tratamiento)) && !encontrado) {
        if (t.idTratamiento == idBuscado && !t.eliminado) {
            cout << "Tratamiento encontrado. Ingrese nuevos datos:\n";
            cout << "Nuevo ID Diagnostico: ";
            cin >> t.idDiagnostico;
            cin.ignore();
            cout << "Nuevo nombre del veterinario: ";
            cin.getline(t.nombreVeterinario, 100);
            cout << "Nuevo detalle del tratamiento: ";
            cin.getline(t.tratamiento, 300);
            cout << "Nuevo monto: ";
            cin >> t.monto;

            archivo.seekp(-sizeof(Tratamiento), ios::cur);
            archivo.write((char*)&t, sizeof(Tratamiento));
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Tratamiento no encontrado.\n";
    archivo.close();
    system("pause");
}

void EliminarTratamiento(string archivoBin) {
    Tratamiento t;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID del tratamiento a eliminar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&t, sizeof(Tratamiento)) && !encontrado) {
        if (t.idTratamiento == idBuscado && !t.eliminado) {
            t.eliminado = true;
            archivo.seekp(-sizeof(Tratamiento), ios::cur);
            archivo.write((char*)&t, sizeof(Tratamiento));
            cout << "Tratamiento eliminado.\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Tratamiento no encontrado.\n";
    archivo.close();
    system("pause");
}
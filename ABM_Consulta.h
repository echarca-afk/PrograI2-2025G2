#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct fecha {
    int dia;
    int mes;
    int anio;
};
struct Consulta {
    int idConsulta;       // ID único de la consulta
    int idMascota;        // Relación con la mascota
    fecha fecha_consulta; // Fecha estructurada
    char motivo[100];     // Motivo de la consulta
    bool eliminado;      
};
void MenuConsultas(string archivoBin);
void IngresarConsulta(string archivoBin);
void MostrarConsultas(string archivoBin);
void EncontrarConsulta(string archivoBin);
void ModificarConsulta(string archivoBin);
void EliminarConsulta(string archivoBin);

void ABM_Consulta(string ArchivoConsultas) {
    MenuConsultas(ArchivoConsultas);
}
void MenuConsultas(string archivoBin) {
    int opcion;
    do {
        system("cls");
        cout << "=== ABM CONSULTAS ===\n";
        cout << "1. Ingresar consulta\n";
        cout << "2. Mostrar consultas\n";
        cout << "3. Buscar consulta\n";
        cout << "4. Modificar consulta\n";
        cout << "5. Eliminar consulta\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: 
                IngresarConsulta(archivoBin); 
                break;
            case 2: 
                MostrarConsultas(archivoBin); 
                break;
            case 3: 
                EncontrarConsulta(archivoBin); 
                break;
            case 4: 
                ModificarConsulta(archivoBin); 
                break;
            case 5: 
                EliminarConsulta(archivoBin); 
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

void IngresarConsulta(string archivoBin) {
    Consulta c;
    ofstream archivo(archivoBin, ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "Ingrese ID de la consulta: ";
    cin >> c.idConsulta;
    cout << "Ingrese ID de la mascota: ";
    cin >> c.idMascota;
    cout << "Ingrese fecha de la consulta:\n";
    cout << "Dia: "; cin >> c.fecha_consulta.dia;
    cout << "Mes: "; cin >> c.fecha_consulta.mes;
    cout << "Año: "; cin >> c.fecha_consulta.anio;
    cin.ignore();
    cout << "Ingrese motivo: ";
    cin.getline(c.motivo, 100);
    c.eliminado = false;

    archivo.write((char*)&c, sizeof(Consulta));
    archivo.close();
    cout << "Consulta registrada correctamente.\n";
    system("pause");
}

void MostrarConsultas(string archivoBin) {
    Consulta c;
    ifstream archivo(archivoBin, ios::binary);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "=== LISTA DE CONSULTAS ===\n";
    while (archivo.read((char*)&c, sizeof(Consulta))) {
        if (!c.eliminado) {
            cout << "ID Consulta: " << c.idConsulta << endl;
            cout << "ID Mascota: " << c.idMascota << endl;
            cout << "Fecha: " << c.fecha_consulta.dia << "/"
                 << c.fecha_consulta.mes << "/"
                 << c.fecha_consulta.anio << endl;
            cout << "Motivo: " << c.motivo << endl;
            cout << "--------------------------\n";
        }
    }
    archivo.close();
    system("pause");
}

void EncontrarConsulta(string archivoBin) {
    Consulta c;
    ifstream archivo(archivoBin, ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID de la consulta a buscar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&c, sizeof(Consulta)) && !encontrado) {
        if (c.idConsulta == idBuscado && !c.eliminado) {
            cout << "Consulta encontrada:\n";
            cout << "ID Mascota: " << c.idMascota << endl;
            cout << "Fecha: " << c.fecha_consulta.dia << "/"
                 << c.fecha_consulta.mes << "/"
                 << c.fecha_consulta.anio << endl;
            cout << "Motivo: " << c.motivo << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Consulta no encontrada.\n";
    archivo.close();
    system("pause");
}

void ModificarConsulta(string archivoBin) {
    Consulta c;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID de la consulta a modificar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&c, sizeof(Consulta)) && !encontrado) {
        if (c.idConsulta == idBuscado && !c.eliminado) {
            cout << "Consulta encontrada. Ingrese nuevos datos:\n";
            cout << "Nueva fecha:\n";
            cout << "Dia: "; cin >> c.fecha_consulta.dia;
            cout << "Mes: "; cin >> c.fecha_consulta.mes;
            cout << "Año: "; cin >> c.fecha_consulta.anio;
            cin.ignore();
            cout << "Nuevo motivo: ";
            cin.getline(c.motivo, 100);

            archivo.seekp(-sizeof(Consulta), ios::cur);
            archivo.write((char*)&c, sizeof(Consulta));
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Consulta no encontrada.\n";
    archivo.close();
    system("pause");
}

void EliminarConsulta(string archivoBin) {
    Consulta c;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese ID de la consulta a eliminar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&c, sizeof(Consulta)) && !encontrado) {
        if (c.idConsulta == idBuscado && !c.eliminado) {
            c.eliminado = true;
            archivo.seekp(-sizeof(Consulta), ios::cur);
            archivo.write((char*)&c, sizeof(Consulta));
            cout << "Consulta eliminada.\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Consulta no encontrada.\n";
    archivo.close();
    system("pause");

}

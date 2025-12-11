#include <bits/stdc++.h>
using namespace std;

struct Mascota {
    int idMascota;      // ID único
    int idDuenio;       // Relación con dueño
    char nombre[30];
    char especie[20];
    char raza[30];
    char sexo[10];
    int edad;          
    bool eliminado;    
};
void Menu(string archivoNombre);
void AgregarMascota(string archivoNombre);
void ListarMascotas(string archivoNombre);
void BuscarMascota(string archivoNombre);
void ModificarMascota(string archivoNombre);
void EliminarMascota(string archivoNombre);

void ABM_Mascota(string ArchivoMascotas){
    Menu(ArchivoMascotas);
}
void Menu(string archivoNombre) {
    int opcion=0;

    do {
        system("cls");
        cout << "==== MENU MASCOTAS ====\n";
        cout << "1. Registrar Mascota\n";
        cout << "2. Listar Mascotas\n";
        cout << "3. Buscar Mascota\n";
        cout << "4. Modificar Mascota\n";
        cout << "5. Eliminar Mascota\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: 
                AgregarMascota(archivoNombre); 
                break;
            case 2: 
                ListarMascotas(archivoNombre); 
                break;
            case 3: 
                BuscarMascota(archivoNombre); 
                break;
            case 4: 
                ModificarMascota(archivoNombre); 
                break;
            case 5: 
                EliminarMascota(archivoNombre); 
                break;
            case 0: 
                break;
            default: 
                cout << "Opción inválida.\n"; system("pause");
        }
    } while (opcion != 0);
}
void AgregarMascota(string archivoNombre) {
    Mascota m;
    ofstream archivo(archivoNombre, ios::binary | ios::app);

    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    cin.ignore();
    cout << "Ingrese ID de la mascota: ";
    cin >> m.idMascota;
    cout << "Ingrese ID del duenio: ";
    cin >> m.idDuenio;
    cin.ignore();

    cout << "Nombre: "; 
    cin.getline(m.nombre, 30);
    cout << "Especie: "; 
    cin.getline(m.especie, 20);
    cout << "Raza: "; 
    cin.getline(m.raza, 30);
    cout << "Sexo: "; 
    cin.getline(m.sexo, 10);
    cout << "Edad: "; 
    cin >> m.edad;
    m.eliminado = false;
    archivo.write((char*)&m, sizeof(Mascota));
    archivo.close();
}

void ListarMascotas(string archivoNombre) {
    Mascota m;
    ifstream archivo(archivoNombre, ios::binary);

    if (!archivo.good()){
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    system("cls");
    cout << "LISTA DE MASCOTAS\n";

    while (archivo.read((char*)&m, sizeof(Mascota))) {
        if (!m.eliminado) {
            cout << "----------------------------\n";
            cout << "ID Mascota: " << m.idMascota << endl;
            cout << "ID Duenio: " << m.idDuenio << endl;
            cout << "Nombre: " << m.nombre << endl;
            cout << "Especie: " << m.especie << endl;
            cout << "Raza: " << m.raza << endl;
            cout << "Sexo: " << m.sexo << endl;
            cout << "Edad: " << m.edad << endl;
        }
    }
    archivo.close();
    system("pause");
}
void BuscarMascota(string archivoNombre) {
    Mascota m;
    ifstream archivo(archivoNombre, ios::binary);
    string buscado;
    bool encontrado = false;

    cin.ignore();
    cout << "Ingrese nombre de mascota a buscar: ";
    getline(cin, buscado);

    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    while (archivo.read((char*)&m, sizeof(Mascota))) {
        if (buscado == m.nombre && !m.eliminado) {
            cout << "MASCOTA ENCONTRADA:\n";
            cout << "----------------------------\n";
            cout << "ID Mascota: " << m.idMascota << endl;
            cout << "ID Duenio: " << m.idDuenio << endl;
            cout << "Nombre: " << m.nombre << endl;
            cout << "Especie: " << m.especie << endl;
            cout << "Raza: " << m.raza << endl;
            cout << "Sexo: " << m.sexo << endl;
            cout << "Edad: " << m.edad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Mascota no encontrada.\n";

    archivo.close();
    system("pause");
}
void ModificarMascota(string archivoNombre) {
    Mascota m;
    fstream archivo(archivoNombre, ios::binary | ios::in | ios::out);
    string buscado;
    bool encontrado = false;
    cin.ignore();
    cout << "Ingrese nombre de mascota a modificar: ";
    getline(cin, buscado);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&m, sizeof(Mascota))) {
        if (buscado == m.nombre && !m.eliminado) {
            cout << "Mascota encontrada, modifique datos:\n";

            cout << "Nueva edad: ";
            cin >> m.edad;
            cin.ignore();

            cout << "Nueva raza: ";
            cin.getline(m.raza, 30);

            archivo.seekp(-sizeof(Mascota), ios::cur);
            archivo.write((char*)&m, sizeof(Mascota));

            encontrado = true;
            break;
        }
    }
    if (!encontrado)
        cout << "Mascota no encontrada.\n";
    archivo.close();
    system("pause");
}
void EliminarMascota(string archivoNombre) {
    Mascota m;
    fstream archivo(archivoNombre, ios::binary | ios::in | ios::out);
    string buscado;
    bool encontrado = false;
    cin.ignore();
    cout << "Ingrese nombre de mascota a eliminar: ";
    getline(cin, buscado);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&m, sizeof(Mascota))) {
        if (buscado == m.nombre && !m.eliminado) {
            m.eliminado = true;

            archivo.seekp(-sizeof(Mascota), ios::cur);
            archivo.write((char*)&m, sizeof(Mascota));

            cout << "Mascota eliminada.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Mascota no encontrada.\n";
    archivo.close();
    system("pause");
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct fecha {
    int dia;
    int mes;
    int anio;
};
struct Factura {
    int nroFactura;             // ID único de la factura
    int idTratamiento;          // Relación con tratamiento
    char descripcion[200];      // Detalle del servicio
    float monto;                // Monto total
    int nit;                    // NIT del beneficiario
    char beneficiario[100];     // Nombre del beneficiario
    fecha fechaFactura;         // Fecha estructurada
    char formaPago[30];         // Efectivo, tarjeta, transferencia
    bool eliminado;             // Baja lógica
};

void MenuFacturacion(string archivoBin);
void IngresarFactura(string archivoBin);
void MostrarFacturas(string archivoBin);
void BuscarFactura(string archivoBin);
void ModificarFactura(string archivoBin);
void EliminarFactura(string archivoBin);

void ABM_Factura(string ArchivoFacturacion) {
    MenuFacturacion(ArchivoFacturacion);
}

void MenuFacturacion(string archivoBin) {
    int opcion;
    do {
        system("cls");
        cout << "=== ABM FACTURACION ===\n";
        cout << "1. Ingresar factura\n";
        cout << "2. Mostrar facturas\n";
        cout << "3. Buscar factura\n";
        cout << "4. Modificar factura\n";
        cout << "5. Eliminar factura\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: IngresarFactura(archivoBin); break;
            case 2: MostrarFacturas(archivoBin); break;
            case 3: BuscarFactura(archivoBin); break;
            case 4: ModificarFactura(archivoBin); break;
            case 5: EliminarFactura(archivoBin); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; system("pause");
        }
    } while(opcion != 0);
}

void IngresarFactura(string archivoBin) {
    Factura f;
    ofstream archivo(archivoBin, ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "Ingrese número de factura: ";
    cin >> f.nroFactura;
    cout << "Ingrese ID del tratamiento: ";
    cin >> f.idTratamiento;
    cin.ignore();
    cout << "Descripción: ";
    cin.getline(f.descripcion, 200);
    cout << "Monto: ";
    cin >> f.monto;
    cout << "NIT: ";
    cin >> f.nit;
    cin.ignore();
    cout << "Beneficiario: ";
    cin.getline(f.beneficiario, 100);
    cout << "Fecha de la factura:\n";
    cout << "Dia: "; cin >> f.fechaFactura.dia;
    cout << "Mes: "; cin >> f.fechaFactura.mes;
    cout << "Anio: "; cin >> f.fechaFactura.anio;
    cin.ignore();
    cout << "Forma de pago (Efectivo/Tarjeta/Transferencia): ";
    cin.getline(f.formaPago, 30);
    f.eliminado = false;

    archivo.write((char*)&f, sizeof(Factura));
    archivo.close();
    cout << "Factura registrada correctamente.\n";
    system("pause");
}

void MostrarFacturas(string archivoBin) {
    Factura f;
    ifstream archivo(archivoBin, ios::binary);
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "=== LISTA DE FACTURAS ===\n";
    while (archivo.read((char*)&f, sizeof(Factura))) {
        if (!f.eliminado) {
            cout << "--------------------------\n";
            cout << "Nro Factura: " << f.nroFactura << endl;
            cout << "ID Tratamiento: " << f.idTratamiento << endl;
            cout << "Descripcion: " << f.descripcion << endl;
            cout << "Monto: " << f.monto << endl;
            cout << "NIT: " << f.nit << endl;
            cout << "Beneficiario: " << f.beneficiario << endl;
            cout << "Fecha: " << f.fechaFactura.dia << "/"
                 << f.fechaFactura.mes << "/"
                 << f.fechaFactura.anio << endl;
            cout << "Forma de pago: " << f.formaPago << endl;
        }
    }
    archivo.close();
    system("pause");
}

void BuscarFactura(string archivoBin) {
    Factura f;
    ifstream archivo(archivoBin, ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese número de factura a buscar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&f, sizeof(Factura)) && !encontrado) {
        if (f.nroFactura == idBuscado && !f.eliminado) {
            cout << "Factura encontrada:\n";
            cout << "ID Tratamiento: " << f.idTratamiento << endl;
            cout << "Descripcion: " << f.descripcion << endl;
            cout << "Monto: " << f.monto << endl;
            cout << "NIT: " << f.nit << endl;
            cout << "Beneficiario: " << f.beneficiario << endl;
            cout << "Fecha: " << f.fechaFactura.dia << "/"
                 << f.fechaFactura.mes << "/"
                 << f.fechaFactura.anio << endl;
            cout << "Forma de pago: " << f.formaPago << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Factura no encontrada.\n";
    archivo.close();
    system("pause");
}

void ModificarFactura(string archivoBin) {
    Factura f;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese número de la factura a modificar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&f, sizeof(Factura)) && !encontrado) {
        if (f.nroFactura == idBuscado && !f.eliminado) {
            cout << "Factura encontrada. Ingrese nuevos datos:\n";
            cin.ignore();
            cout << "Nueva descripcion: ";
            cin.getline(f.descripcion, 200);
            cout << "Nuevo monto: ";
            cin >> f.monto;
            cout << "Nuevo NIT: ";
            cin >> f.nit;
            cin.ignore();
            cout << "Nuevo beneficiario: ";
            cin.getline(f.beneficiario, 100);
            cout << "Nueva fecha:\n";
            cout << "Dia: "; cin >> f.fechaFactura.dia;
            cout << "Mes: "; cin >> f.fechaFactura.mes;
            cout << "Anio: "; cin >> f.fechaFactura.anio;
            cin.ignore();
            cout << "Nueva forma de pago: ";
            cin.getline(f.formaPago, 30);

            archivo.seekp(-sizeof(Factura), ios::cur);
            archivo.write((char*)&f, sizeof(Factura));
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Factura no encontrada.\n";
    archivo.close();
    system("pause");
}

void EliminarFactura(string archivoBin) {
    Factura f;
    fstream archivo(archivoBin, ios::in | ios::out | ios::binary);
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese número de la factura a eliminar: ";
    cin >> idBuscado;
    if (!archivo.good()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (archivo.read((char*)&f, sizeof(Factura)) && !encontrado) {
        if (f.nroFactura == idBuscado && !f.eliminado) {
            f.eliminado = true;
            archivo.seekp(-sizeof(Factura), ios::cur);
            archivo.write((char*)&f, sizeof(Factura));
            cout << "Factura eliminada.\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Factura no encontrada.\n";
    archivo.close();
    system("pause");
}
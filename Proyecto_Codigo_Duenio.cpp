#include<bits/stdc++.h>
using namespace std;
struct Duenio {
    int idDuenio;      // ID único del dueño
    char nombre[30];
    char apellido[30];
    char direccion[50];
    char telefono[15];
    char email[30];
    bool eliminado;   

};
void IngresarDatosDuenio(string NombreArchivo);
void MostrarDatosDuenio(string NombreArchivo);
void EncontrarInfDuenio(string NombreArchivo);
void ModificarInfDuenio(string NombreArchivo);
void MenuOpciones(string nombreArchivo);
int main()
{
    string nombreArchivo = "AgendaTelefonica.bin";
    MenuOpciones(nombreArchivo);
    return 0;
}

void IngresarDatosDuenio(string NombreArchivo)
{
    Duenio Datosduenio;
    ofstream archivo;
    // Abrir el archivo en modalidad BINARIO para agregar datos al final
    archivo.open(NombreArchivo, ios::binary | ios::app);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Ingresar los datos del contacto en la variable persona que es de tipo Agenda
        cin.ignore();
        cout << "Ingrese su id 'Duenio': ";
        cin >> Datosduenio.idDuenio;
        cout << "Ingrese su nombre: ";
        cin.getline(Datosduenio.nombre, 30);
        cout << "Ingrese su apellido: ";
        cin.getline(Datosduenio.apellido, 30);
        cin.ignore();
        cout << "Ingrese su direccion corespondiente: ";
        cin.getline(Datosduenio.direccion,50);
        cout << "Ingrese su telefono : ";
        cin.getline(Datosduenio.telefono,15);
        cout << "Ingrese el email: ";
        cin.getline(Datosduenio.email,30);
        Datosduenio.eliminado = false;
        // Escribir los datos en el archivo binario
        archivo.write((char*)&Datosduenio, sizeof(Duenio));
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    // Cerrar el archivo
    archivo.close();
}
void MostrarDatosDuenio(string NombreArchivo)
{
    Duenio DatosDuenio;
    ifstream archivo;
    // Abrir el archivo en modalidad BINARIO, para leer los datos 
    archivo.open(NombreArchivo, ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        system("cls");
        cout << "LISTADO DE CONTACTOS" << endl;
        // Leer los datos del archivo binario y mostrarlos en pantalla
        while (archivo.read((char*)&DatosDuenio, sizeof(Duenio)))
        {
            // Verificar que el contacto no esté eliminado
            if (!DatosDuenio.eliminado)
            {
                cout << "DATOS ID:" << DatosDuenio.idDuenio << endl;
                cout << "--------------------------------" << endl;
                cout << "\tNombre: " << DatosDuenio.nombre << endl;
                cout << "\tApellido: " << DatosDuenio.apellido << endl;
                cout << "\tDireccion: " << DatosDuenio.direccion << endl;
                cout     << "--------------------------------" << endl;
                cout << "\tTelefono: " << DatosDuenio.telefono << endl;
                cout << "\tEmail: " << DatosDuenio.email << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}
void EncontrarInfDuenio(string NombreArchivo)
{
    Duenio DatosDuenio;
    ifstream archivo;
    string nombreBuscado;
    bool encontrado = false;

    system("cls");
    cout << "Ingrese el nombre del contacto a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    archivo.open(NombreArchivo, ios::binary);

    if (archivo.good())
    {
        while (archivo.read((char*)&DatosDuenio, sizeof(Duenio)) && !encontrado)
        {
            if (nombreBuscado == DatosDuenio.nombre && !DatosDuenio.eliminado)
            {
                cout << "DATOS ID ENCONTRADOS: " << DatosDuenio.idDuenio << endl;
                cout << "--------------------------------" << endl;
                cout << "\tNombre: " << DatosDuenio.nombre << endl;
                cout << "\tApellido: " << DatosDuenio.apellido << endl;
                cout << "\tDireccion: " << DatosDuenio.direccion << endl;
                cout << "--------------------------------" << endl;
                cout << "\tTelefono: " << DatosDuenio.telefono << endl;
                cout << "\tEmail: " << DatosDuenio.email << endl;

                encontrado = true;   // Está dentro del if correcto
            }
        }

        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

    system("pause");
    archivo.close();
}
void ModificarInfDuenio(string NombreArchivo)
{
    Duenio  DatosDuenio;
    fstream archivo;
    string nombreBuscado;
    // Variable para indicar si se encontró el contacto
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    // Abrir el archivo en modalidad BINARIO, para leer y escribir los datos al mismo tiempo
    archivo.open(NombreArchivo,  ios::in | ios::out | ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Leer los datos del archivo binario y buscar el contacto
        while (archivo.read((char*)&DatosDuenio, sizeof(Duenio)) && !encontrado)
        {
            if (nombreBuscado == DatosDuenio.nombre && !DatosDuenio.eliminado)
            {
                cout << "DATOS ID ENCONTRADOS: " << DatosDuenio.idDuenio << endl;
                cout << "--------------------------------" << endl;
                cout << "\tNombre: " << DatosDuenio.nombre << endl;
                cout << "\tApellido: " << DatosDuenio.apellido << endl;
                cout << "\tDireccion: " << DatosDuenio.direccion << endl;
                cout << "--------------------------------" << endl;
                cout << "\tTelefono: " << DatosDuenio.telefono << endl;
                cout << "\tEmail: " << DatosDuenio.email << endl;
                
                encontrado = true;
                // Mover el puntero de escritura al inicio del registro encontrado
                archivo.seekp(-sizeof(Duenio), ios::cur);
                // Ingresar los nuevos datos del contacto
                cout << "Ingrese la nueva direccion: ";
                cin.getline(DatosDuenio.direccion, 50);
                cout << "Ingrese el nuevo telefono: ";
                cin.getline(DatosDuenio.telefono, 15);
                cin.ignore();
                cout << "Ingrese el nuevo email: ";
                cin.getline(DatosDuenio.email, 30);
                // Escribir los nuevos datos en el archivo binario
                archivo.write((char*)&DatosDuenio, sizeof(Duenio));
            }
        }
        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void EliminarInfDuenio(string NombreArchivo)
{
    Duenio DatosDuenio;
    fstream archivo;
    string nombreBuscado;
    // Variable para indicar si se encontró el contacto
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a eliminar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    // Abrir el archivo en modalidad BINARIO, para leer y escribir los datos al mismo tiempo
    archivo.open(NombreArchivo,  ios::in | ios::out | ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Leer los datos del archivo binario y buscar el contacto
        while (archivo.read((char*)&DatosDuenio, sizeof(Duenio)) && !encontrado)
        {
            if (nombreBuscado == DatosDuenio.nombre && !DatosDuenio.eliminado)
            {
                cout << "DATOS ID ENCONTRADOS ELIMINADOS: " << DatosDuenio.idDuenio << endl;
                cout << "--------------------------------" << endl;
                cout << "\tNombre: " << DatosDuenio.nombre << endl;
                cout << "\tApellido: " << DatosDuenio.apellido << endl;
                cout << "\tDireccion: " << DatosDuenio.direccion << endl;
                cout << "--------------------------------" << endl;
                cout << "\tTelefono: " << DatosDuenio.telefono << endl;
                cout << "\tEmail: " << DatosDuenio.email << endl;
               
                encontrado = true;
                // Mover el puntero de escritura al inicio del registro encontrado
                archivo.seekp(-sizeof(Duenio), ios::cur);
                // Marcar el contacto como eliminado
                DatosDuenio.eliminado = true;                
                // Escribir los nuevos datos en el archivo binario
                archivo.write((char*)&DatosDuenio, sizeof(Duenio));
            }
        }
        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void MenuOpciones(string nombreArchivo)
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. Crear nueva Informacion de Duenio" << endl;
        cout << "\t2. Listar Informaciones de Duenios" << endl;
        cout << "\t3. Encontrar Informacion de Duenio" << endl;
        cout << "\t4. Modificar Informacion de Duenio" << endl;
        cout << "\t5. Eliminar Informacion de Duenio" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                IngresarDatosDuenio(nombreArchivo);
                break;
            case 2:
                MostrarDatosDuenio(nombreArchivo);
                break;
            case 3:
                EncontrarInfDuenio(nombreArchivo);
                break;
            case 4:
                ModificarInfDuenio(nombreArchivo);
                break;
            case 5:
                EliminarInfDuenio(nombreArchivo);
                break;
            default:
                if (opcion != 0)
                {
                    cout << "Opcion no valida." << endl;
                    system("pause");
                }
                
                break;
        }
    } while (opcion != 0);
    system("cls");
}








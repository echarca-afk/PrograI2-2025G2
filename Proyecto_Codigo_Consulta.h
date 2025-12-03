#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Mascota 
{
    int idMascota;
    int idDuenio;
    char nombre[30];
    char especie[20];
    char raza[30];
    char sexo[10];
    int edad;
    char doctor[50];
};

struct Consulta 
{
    int idConsulta;
    int idMascota;
    char fecha_consulta[11];
    char motivo[100];
};

void BuscarPacienteAntiguo();
void RegistrarPacienteNuevo();
void ImprimirConsulta(int idMascota, const char* nombreMascota, const char* doctor);
int BuscarMascotaPorID(int idBuscado, Mascota &mascotaEncontrada);
void GuardarMascota(const Mascota &mascota);
void Menu();

int main() 
{
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    Menu();

    return 0;
}

void BuscarPacienteAntiguo() 
{
    system("cls");
    cout<<"=== BUSCAR PACIENTE ANTIGUO ===\n";
    
    int idBuscado;
    cout<<"Ingrese el ID de la mascota: ";
    cin>>idBuscado;
    
    Mascota mascotaEncontrada;
    int resultado=BuscarMascotaPorID(idBuscado, mascotaEncontrada);
    
    if (resultado==1) 
    {
        cout<<"\nMascota encontrada:\n";
        cout<<"Nombre: "<<mascotaEncontrada.nombre<<endl;
        cout<<"Especie: "<<mascotaEncontrada.especie<<endl;
        cout<<"Raza: "<<mascotaEncontrada.raza<<endl;
        
        cin.ignore();
        char nuevoDoctor[50];
        cout<<"\nIngrese el nombre del doctor que la atendera: ";
        cin.getline(nuevoDoctor, 50);
        
        ImprimirConsulta(mascotaEncontrada.idMascota, mascotaEncontrada.nombre, nuevoDoctor);
    } 
    else 
    {
        cout<<"Mascota no encontrada en el sistema\n";
        system("pause");
    }
}

void RegistrarPacienteNuevo() 
{
    system("cls");
    cout<<"=== REGISTRAR PACIENTE NUEVO ===\n";
    
    Mascota nuevaMascota;
    
    cout<<"ID del dueño: ";
    cin>>nuevaMascota.idDuenio;
    cout<<"ID de la mascota: ";
    cin>>nuevaMascota.idMascota;
    cin.ignore();
    
    cout<<"Nombre: ";
    cin.getline(nuevaMascota.nombre, 30);
    cout<<"Especie: ";
    cin.getline(nuevaMascota.especie, 20);
    cout<<"Raza: ";
    cin.getline(nuevaMascota.raza, 30);
    cout<<"Sexo: ";
    cin.getline(nuevaMascota.sexo, 10);
    cout<<"Edad: ";
    cin>>nuevaMascota.edad;
    cin.ignore();
    
    cout<<"Doctor asignado: ";
    cin.getline(nuevaMascota.doctor, 50);
    
    GuardarMascota(nuevaMascota);
    ImprimirConsulta(nuevaMascota.idMascota, nuevaMascota.nombre, nuevaMascota.doctor);
    
    cout<<"\nPaciente registrado exitosamente\n";
    system("pause");
}

void ImprimirConsulta(int idMascota, const char* nombreMascota, const char* doctor) 
{
    Consulta nuevaConsulta;
    
    nuevaConsulta.idConsulta=(rand()%30)+1;
    nuevaConsulta.idMascota=idMascota;
    
    cout<<"\nIngrese la fecha de consulta (DD/MM/AAAA): ";
    cin.getline(nuevaConsulta.fecha_consulta, 11);
    
    cout<<"Ingrese el motivo de la consulta: ";
    cin.getline(nuevaConsulta.motivo, 100);
    
    ofstream archivoTxt("Consulta.txt");
    if (archivoTxt.is_open()) 
    {
        archivoTxt<<"=== CONSULTA VETERINARIA ===\n";
        archivoTxt<<"Nombre de la mascota: "<<nombreMascota<<endl;
        archivoTxt<<"Fecha de consulta: "<<nuevaConsulta.fecha_consulta<<endl;
        archivoTxt<<"Numero de atencion: "<<nuevaConsulta.idConsulta<<endl;
        archivoTxt<<"Doctor: "<<doctor<<endl;
        archivoTxt<<"Motivo: "<<nuevaConsulta.motivo<<endl;
        archivoTxt.close();
        cout<<"\nArchivo 'Consulta.txt' generado exitosamente\n";
    } 
    else 
    {
        cout<<"Error al crear el archivo de consulta\n";
    }
    
    ofstream archivoBin("Consultas.bin", ios::binary | ios::app);
    if (archivoBin.is_open()) 
    {
        archivoBin.write((char*)&nuevaConsulta, sizeof(Consulta));
        archivoBin.close();
        cout<<"Respaldo guardado en archivo binario\n";
    } 
    else 
    {
        cout<<"Error al guardar en archivo\n";
    }
    
    system("pause");
}

int BuscarMascotaPorID(int idBuscado, Mascota &mascotaEncontrada) 
{
    ifstream archivo("Mascotas.bin", ios::binary);
    
    if (!archivo.good()) 
    {
        return 0;
    }
    
    Mascota mascotaTemp;
    while (archivo.read((char*)&mascotaTemp, sizeof(Mascota))) 
    {
        if (mascotaTemp.idMascota==idBuscado) 
        {
            mascotaEncontrada=mascotaTemp;
            archivo.close();
            return 1;
        }
    }
    
    archivo.close();
    return -1;
}

void GuardarMascota(const Mascota &mascota) 
{
    ofstream archivo("Mascotas.bin", ios::binary | ios::app);
    
    if (archivo.is_open()) 
    {
        archivo.write((char*)&mascota, sizeof(Mascota));
        archivo.close();
    }
}

void Menu() 
{
    int opcion;
    
    do 
    {
        system("cls");
        cout<<"=== SISTEMA VETERINARIO ===\n";
        cout<<"1. Buscar paciente antiguo\n";
        cout<<"2. Registrar paciente nuevo\n";
        cout<<"3. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        
        switch (opcion) 
        {
            case 1:
                BuscarPacienteAntiguo();
                break;
            case 2:
                RegistrarPacienteNuevo();
                break;
            case 3:
                cout<<"Saliendo del sistema...\n";
                break;
            default:
                cout<<"Opcion invalida. Intente nuevamente.\n";
                system("pause");
        }
        
    } while (opcion!=3);

}

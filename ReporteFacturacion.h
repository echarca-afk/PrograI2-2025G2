#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReporteFacturacion(string archivoFacturas) {
    Factura f;
    ifstream archivo(archivoFacturas, ios::binary);
    ofstream reporte("ReporteFacturas.txt");
    if (archivo.good()) {
        reporte << "FACTURACION EMITIDA" << endl;
        reporte << "===================" << endl;
        reporte << "Nro Factura\tID Tratamiento\tDescripcion\tMonto\tNIT\tBeneficiario\tFecha\tForma de Pago" << endl;
        reporte << "------------------------------------------------------------------------" << endl;
        while (archivo.read((char*)&f, sizeof(Factura))) {
            if (!f.eliminado) {
                reporte << f.nroFactura << "\t" << f.idTratamiento << "\t" << f.descripcion
                        << "\t" << f.monto << "\t" << f.nit << "\t" << f.beneficiario
                        << "\t" << f.fechaFactura.dia << "/" << f.fechaFactura.mes << "/" << f.fechaFactura.anio
                        << "\t" << f.formaPago << endl;
            }
        }
        reporte << "------------------------------------------------------------------------" << endl;
    }
    archivo.close();
    reporte.close();
}
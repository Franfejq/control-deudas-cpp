#include <iostream>
#include "frn_deuda.h"

/*Fecha Inicial*/
#define DIA 21
#define MES 7
#define ANO 2026

const double DEUDA_INICIAL = 7399.00;

/*Nombre del archivo .csv*/
const std::string file_name = "../Pagos.csv";


int main()
{
    RegistroPago pago;
    pago.fecha.dia = DIA;
    pago.fecha.mes = MES;
    pago.fecha.ano = ANO;

    pago.deudaRestante = DEUDA_INICIAL;

    /*1.-Abrimos el archivo en modo lectura*/
    leer_historial_deuda(file_name, pago);

    std::cout << "Deuda actual: $" << pago.deudaRestante << " MXN  Fecha: " << pago.fecha.dia << "/" << pago.fecha.mes << "/" << pago.fecha.ano << std::endl;

    if (pago.deudaRestante <= 0)
    {
        std::cout << "La deuda esta completamente pagada." << std::endl;
        return 0;
    }

    /*2.- Solicitamos el Pago*/
    std::cout << "Ingresa el monto del pago: $";
    std::cin >> pago.monto;

    std::cout << "Ingresa el fecha del pago: ";
    std::cin >> pago.fecha.dia;
    std::cout << "/";
    std::cin >> pago.fecha.mes;
    std::cout << "/";
    std::cin >> pago.fecha.ano;

    /*3.- Si el pago es valido insertamos el pago y deuda actual al final del archivo(MODO APPEND)*/
    pagar_insertar_deuda(file_name, pago);

    return 0;
}
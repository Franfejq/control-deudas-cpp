#include <iostream>
#include "frn_deuda.h"

const double DEUDA_INICIAL = 7399.00;

/*Nombre del archivo .csv*/
const std::string file_name = "Pagos.csv";

int main()
{
    RegistroPago pago;
    pago.deudaRestante = DEUDA_INICIAL;

    /*1.-Abrimos el archivo en modo lectura*/
    leer_historial_deuda(file_name, pago);

    std::cout << "Deuda actual: $" << pago.deudaRestante << " MXN" << std::endl;

    if (pago.deudaRestante <= 0)
    {
        std::cout << "La deuda esta completamente pagada." << std::endl;
        return 0;
    }

    /*2.- Solicitamos el Pago*/
    std::cout << "Ingresa el monto del pago: $";
    std::cin >> pago.monto;

    /*3.- Si el pago es valido insertamos el pago y deuda actual al final del archivo(MODO APPEND)*/
    pagar_insertar_deuda(file_name, pago);

    return 0;
}
//
// Created by fran_linx on 7/31/26.
//

#ifndef DEUDAPROJECT_FRN_DEUDA_H
#define DEUDAPROJECT_FRN_DEUDA_H

#include <string>
#include <fstream>
#include <sstream>

typedef struct
{
    double monto, deudaRestante;
}RegistroPago;

void leer_historial_deuda(const std::string& nombre_archivo, RegistroPago& historial);

#endif //DEUDAPROJECT_FRN_DEUDA_H

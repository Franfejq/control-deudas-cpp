//
// Created by fran_linx on 7/31/26.
//

#ifndef DEUDAPROJECT_FRN_DEUDA_H
#define DEUDAPROJECT_FRN_DEUDA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

typedef struct {
    int dia;
    int mes;
    int ano;
}FechaPago;

typedef struct
{
    double monto, deudaRestante;
    FechaPago fecha;
}RegistroPago;

void leer_historial_deuda(const std::string& nombre_archivo, RegistroPago& historial);
void pagar_insertar_deuda(const std::string& nombre_archivo, RegistroPago& historial);
bool validar_fecha(RegistroPago& historial);

#endif //DEUDAPROJECT_FRN_DEUDA_H

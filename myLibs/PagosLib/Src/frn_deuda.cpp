//
// Created by fran_linx on 7/31/26.
//
#include "frn_deuda.h"

void leer_historial_deuda(const std::string& nombre_archivo, RegistroPago& historial)
{
    std::ifstream r_file(nombre_archivo);
    if (r_file.is_open())
    {
        std::string line, last_line;

        //Leemos el archivo hasta el final y guardamos en la variable last_line la ultima linea del archivo
        while (std::getline(r_file, line))
        {
            if (!line.empty())
            {
                last_line = line;
            }
        }
        r_file.close(); //Cerramos el archivo para evitar conflictos

        //Comprobamos que la ultima linea no sea el encabezado y que sea valida
        if (!last_line.empty() && last_line.find("Pagos") == std::string::npos)
        {
            std::stringstream ss(last_line);
            std::string pago_str, deuda_str;

            //Avanzamos solo hasta encontrar una coma (,) y guardar los datos de Pago y Deuda en las variables antes creadas
            std::getline(ss, pago_str, ',');
            std::getline(ss, deuda_str, ',');

            //Comprobamos que el campo de deuda no este vacío y parseamos ese tipo de dato String a double para guardarlo en nuestra deuda actual
            if (!deuda_str.empty())
            {
                historial.deudaRestante = std::stod(deuda_str); //String -> Double
            }
        }
    }
    else
    {
        //Si falla en abrir el archivo o no existe o no se encuentra ahí, asi que lo creamos e insertamos nuestro encabezado estandar
        std::ofstream new_file(nombre_archivo);
        new_file << "Pagos,Deuda T\n";
        new_file.close();
    }
}

void pagar_insertar_deuda(const std::string& nombre_archivo, RegistroPago& historial)
{
    if ( historial.monto > 0)
    {
        historial.deudaRestante -= historial.monto; //Deuda - Pago

        //Abrimos el archivo en modo escritura con el parametro std::ios::app para no sobreescribir nada
        std::ofstream w_file(nombre_archivo, std::ios::app);
        if (w_file.is_open())
        {
            w_file << historial.monto << "," << historial.deudaRestante << "\n";
            w_file.close();

            std::cout << "Se inserto el pago exitosamente. Deuda restante: $" << historial.deudaRestante << " MXN\n";
        }
    }
}
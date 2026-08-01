#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

const double DEUDA_INICIAL = 7399.00;

/*Nombre del archivo .csv*/
const std::string file_name = "Pagos.csv";

int main()
{
    double deuda_actual = DEUDA_INICIAL;

    /*1.-Abrimos el archivo en modo lectura*/
    std::ifstream r_file(file_name);
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
                deuda_actual = std::stod(deuda_str); //String -> Double
            }
        }
    }
    else
    {
        //Si falla en abrir el archivo o no existe o no se encuentra ahí, asi que lo creamos e insertamos nuestro encabezado estandar
        std::ofstream new_file(file_name);
        new_file << "Pagos,Deuda T\n";
        new_file.close();
    }

    std::cout << "Deuda actual: $" << deuda_actual << " MXN" << std::endl;

    if (deuda_actual <= 0)
    {
        std::cout << "La deuda esta completamente pagada." << std::endl;
        return 0;
    }

    /*2.- Solicitamos el Pago*/
    double pago;
    std::cout << "Ingresa el monto del pago: $";
    std::cin >> pago;

    /*3.- Si el pago es valido insertamos el pago y deuda actual al final del archivo(MODO APPEND)*/
    if ( pago > 0)
    {
        deuda_actual -= pago; //Deuda - Pago

        //Abrimos el archivo en modo escritura con el parametro std::ios::app para no sobreescribir nada
        std::ofstream w_file(file_name, std::ios::app);
        if (w_file.is_open())
        {
            w_file << pago << "," << deuda_actual << "\n";
            w_file.close();

            std::cout << "Se inserto el pago exitosamente. Deuda restante: $" << deuda_actual << " MXN\n";
        }
    }

    return 0;
}
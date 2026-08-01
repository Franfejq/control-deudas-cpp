#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

const double DEUDA_INICIAL = 7399.00;
const std::string file_name = "Pagos.csv";

int main()
{
    double deuda_actual = DEUDA_INICIAL;

    std::ifstream r_file(file_name);

    if (r_file.is_open())
    {
        std::string line, last_line;

        while (std::getline(r_file, line))
        {
            if (!line.empty())
            {
                last_line = line;
            }
        }
        r_file.close();

        if (!last_line.empty() && last_line.find("Pagos") == std::string::npos)
        {
            std::stringstream ss(last_line);
            std::string pago_str, deuda_str;

            std::getline(ss, pago_str, ',');
            std::getline(ss, deuda_str, ',');

            if (!deuda_str.empty())
            {
                deuda_actual = std::stod(deuda_str);
            }
        }
    }
    else
    {
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

    double pago;
    std::cout << "Ingresa el monto del pago: $";
    std::cin >> pago;

    if ( pago > 0)
    {
        deuda_actual -= pago; //Deuda - Pago
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
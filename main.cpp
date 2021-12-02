#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char paridad (const string& datosBinario)
{
    int numUnos = 0;
    for (auto b : datosBinario)
    {
        if (b == '1')
            numUnos++;
    }
    if (numUnos%2 == 0)
        return '0';
    else
        return '1';
}

string codificaBinario (int base10Num)
{
    string base2Num;

    while (base10Num > 0)
    {
        base2Num = (char)(base10Num % 2 + 48) + base2Num;

        base10Num /= 2;
    }

    for (int i = base2Num.size(); i < 7; i++)
        base2Num = '0' + base2Num;

    return base2Num;
}

int main()
{
    int opcion;
    string aux;
    cout << "[1] Generar codigo de paridad" << endl
         << "[2] Verificar paridad del codigo" << endl
         << "Ingrese una opcion: ";
    cin >> opcion;
    getline(cin, aux);
    cout << "\n";

    char c;
    string datos;

    if (opcion == 1)
    {
        cout << "Ingrese texto a codificar: ";
        getline(cin, datos);
        cout << "\n";

        stringstream ss(datos);

        string datosBinario;
        char bitParidad;
        string datosCodificados;

        while (ss.get(c))
        {
            datosBinario = codificaBinario((int)c);
            bitParidad = paridad(datosBinario);

            cout << c << " = " << bitParidad << " " << datosBinario << endl;

            datosCodificados += bitParidad;
            datosCodificados += datosBinario;
        }

        cout << "Texto codificado: " << datosCodificados;
    }
    else if (opcion == 2)
    {
        cout << "Ingrese codigo a verificar: ";
        getline(cin, datos);
        cout << "\n";

        stringstream ss(datos);

        string caracter;
        bool correcto = true;

        for (int i=0; ss.get(c); i++)
        {
            caracter += c;
            if ((i+1)%8 == 0)
            {
                if (paridad(caracter) != '0')
                {
                    correcto = false;
                    cout << "El caracter #" << (i+1)/8 << " presenta un error" << endl;
                }
                caracter = "";
            }
        }

        if (correcto)
            cout << "Datos aceptados :)" << endl;
    }

    return 0;
}

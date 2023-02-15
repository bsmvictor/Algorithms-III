#include <iostream>
#include <iomanip>

using namespace std;

// função peso ideal
float ideal(float h, char sexo)
{
    float Peso;

    if (sexo == 'M' || sexo == 'm')
        Peso = (72.7 * h) - 58;

    else if (sexo == 'F' || sexo == 'f')
        Peso = (62.1 * h) - 44.7;

    return Peso;
}

int main()
{
    float altura; // altura da pessoa
    char sexo;    // sexo da pessoa
    float peso;   // peso ideal

    cin >> altura;
    cin >> sexo;

    // chamada de função
    peso = ideal(altura, sexo);

    cout << fixed << setprecision(2);
    cout << "Peso ideal = " << peso << " kg" << endl;

    return 0;
}
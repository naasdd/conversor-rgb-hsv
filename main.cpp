#include <iostream>
#include <algorithm>

using namespace std;

void rgbParaHSV(double red, double green, double blue, double &h, double &s, double &v){
        double r = red / 255.0;
        double g = green / 255.0;
        double b = blue / 255.0;
    
        double valorMAX = max({r, g, b});
        double valorMIN = min({r, g, b});
        double diferenca = valorMAX - valorMIN;
    
        
        // V
        v = valorMAX;
    
        // S
        if (valorMAX == 0)
        {
            s = 0;
        }
        else
        {
            s = diferenca / valorMAX;
        }
    
        // Matiz
        if (diferenca == 0)
        {
            h = 0;
        }
        else if (valorMAX == r)
        {
            h = 60 * ((g - b) / diferenca);
        }
        else if (valorMAX == g)
        {
            h = 60 * ((b - r) / diferenca + 2);
        }
        else
        {
            h = 60 * ((r - g) / diferenca + 4);
        }
    

        if (h < 0)
        {
            h += 360;
        }
    
        cout << "HSV GERADO: H = " << h << ", S = " << s * 100 << "%, V = " << v * 100 << "%. \n\n";
    
}

void receberValores(double &h, double &s, double &v)
{
    double red, green, blue;
    cout << "\nInsira o valor de red: ";
    cin >> red;
    cout << "\nInsira o valor de green: ";
    cin >> green;
    cout << "\nInsira o valor de blue: ";
    cin >> blue;

    cout << "RED: " << red << ", GREEN: " << green << ", BLUE: " << blue << endl;

    rgbParaHSV(red, green, blue, h, s, v);
}


int main()
{
    double h, s, v;
    cout << "Inicio do Conversor de RGB para HSV. \n\n";
    cout << "1 - Iniciar conversao\n";
    cout << "0 - Sair do programa\n";
    int opcao;
    cin >> opcao;
    if (opcao)
    {
        receberValores(h, s,v );
    }
    else
    {
        return 0;
    }

    return 0;
}
#include <iostream>
using namespace std;
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <conio.h>


#include "Graficas.h"
#include "Funciones.h"
#include "Productos.h"
#include "Ingredientes_x_Torta.h"
#include "Tortas.h"
#include "Clientes.h"
#include "Tortas_x_Pedido.h"
#include "Pedidos.h"
#include "Ventas.h"
#include "Opciones.h"
#include "Menus.h"



int main()
{
    system("title Tortas");
    system("mode 105,54");

    int Opcion;
    while (true)
    {
        system("cls");
        recuadro(38, 6, 28, 16);
        gotoxy(50,7);
        cout << "Men""\243"  << endl;
        gotoxy(39,8);
        cout << "---------------------------" << endl;
        gotoxy(40,9);
        cout << "1-    Men""\243" " Ventas" << endl;
        gotoxy(40,11);
        cout << "2-    Men""\243" " Mercaderia" << endl;
        gotoxy(40,13);
        cout << "3-    Men""\243" " Tortas" << endl;
        gotoxy(40,15);
        cout << "4-    Men""\243" " Clientes" << endl;
        gotoxy(40,17);
        cout << "5-    Agregar Stock" << endl;
        gotoxy(40,19);
        cout << "9-    Opciones " << endl;
        gotoxy(40,21);
        cout << "0-    Salir " << endl;

        recuadro(38, 24, 28, 2);
        gotoxy(43,25);
        cout << "Ingrese la Opcion: ";
        cin >> Opcion;

        switch(Opcion)
        {
        case 1:
            SwitchVentas();
            break;

        case 2:
            SwitchMercaderia();
            break;

        case 3:
            SwitchTortas();
            break;
        case 4:
            SwitchClientes();
            break;
        case 5:
            system("cls");
            AgregarStock();
            break;

        case 9:
            Opciones();
            break;

        case 0:
            gotoxy(15,35);
            return 0;
            break;

        default:
            cout << "Numero Incorrecto. Ingrese Nuevamente" << endl;
            system("pause");
        }
    }
}

#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

int SwitchVentas()
{
    int opc;
    while (true)
    {
        system("cls");
        recuadro(36, 5, 32, 12);
        gotoxy(49,6);
        cout << "Ventas" << endl;
        gotoxy(37,7);
        cout << "-------------------------------" << endl;
        gotoxy(37,8);
        cout << "1- Ingresar Venta a Particular" << endl;
        gotoxy(37,10);
        cout << "2-  Ingresar Venta a Cliente" << endl;
        gotoxy(37,12);
        cout << "3-      Ventas Realizadas" << endl;
        gotoxy(37,14);
        cout << "4-    Ordenar por Ganancia" << endl;
        gotoxy(37,16);
        cout << "0-       Volver al Men""\243" << endl;

        recuadro(38, 24, 28, 2);
        gotoxy(43,25);
        cout << "Ingrese la Opcion: ";
        cin >>opc;
        switch(opc)
        {
        case 1:
            system("cls");
            CrearVentaParticular();
            break;
        case 2:
            system("cls");
            CrearVentaCliente();
            break;
        case 3:
            system("cls");
            MostrarVenta();
            break;
        case 4:
            system("cls");
            OrdenarPorGanancia();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Numero Incorrecto. Ingrese Nuevamente" << endl;
            system("pause");

        }
    }
}

int SwitchMercaderia()
{
    int opc;
    while(true)
    {
        system("cls");

        recuadro(33, 5, 38, 19);
        gotoxy(48,6);
        cout << "Mercaderias" << endl;
        gotoxy(34,7);
        cout << "-------------------------------------" << endl;
        gotoxy(34,8);
        cout << "1-      Ingresar Nueva Mercaderia" << endl;
        gotoxy(34,10);
        cout << "2-        Modificar Mercaderia" << endl;
        gotoxy(34,12);
        cout << "3-     Mostrar Toda la Mercaderia" << endl;
        gotoxy(34,14);
        cout << "4-     Dar de Baja una Mercaderia" << endl;
        gotoxy(34,16);
        cout << "5-     Dar de Alta una Mercaderia" << endl;
        gotoxy(34,18);
        cout << "6-         Ordenar por Codigo" << endl;
        gotoxy(34,20);
        cout << "7-         Ordenar por Precio" << endl;
        gotoxy(34,22);
        cout << "0-           Volver al Men""\243" << endl;
        recuadro(38, 26, 28, 2);

        gotoxy(43,27);
        cout << "Ingrese la Opcion: ";
        cin >> opc;
        switch(opc)
        {
        case 1:
            system("cls");
            CrearMer();
            break;

        case 2:
            system("cls");
            ModificarMer();
            break;

        case 3:
            system("cls");
            MostrarMer();
            break;

        case 4:
            system("cls");
            BajaMer();
            break;

        case 5:
            system("cls");
            AltaMer();
            break;

        case 6:
            system("cls");
            OrdenarXCodigo();
            break;
        case 7:
            system("cls");
            OrdenarXPrecio();
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Numero Incorrecto. Ingrese Nuevamente" << endl;
            system("pause");

        }

    }
}

int SwitchTortas()
{
    class Tortas Tor;
    int opc;
    while(true)
    {
        system("cls");
        recuadro(36, 5, 32, 16);
        gotoxy(49,6);
        cout << "Tortas" << endl;
        gotoxy(37,7);
        cout << "-------------------------------" << endl;
        gotoxy(37,8);
        cout << "1-     Ingresar Nueva Torta" << endl;
        gotoxy(37,10);
        cout << "2-      Modificar Una Torta" << endl;
        gotoxy(37,12);
        cout << "3-      Mostrar Las Tortas" << endl;
        gotoxy(37,14);
        cout << "4-      Producir Una Torta" << endl;
        gotoxy(37,16);
        cout << "5-     Dar de Baja una Torta " << endl;
        gotoxy(37,18);
        cout << "6-     Dar de Alta una Torta " << endl;
        gotoxy(37,20);
        cout << "0-       Volver al Men""\243" << endl;
        recuadro(38, 24, 28, 2);
        gotoxy(43,25);
        cout << "Ingrese la Opcion: ";
        cin >> opc;
        switch(opc)
        {
        case 1:
            system("cls");
            CrearTor();
            break;
        case 2:
            system("cls");
            ModificarTorta();
            break;
        case 3:
            system("cls");
            MostrarTortas();
            break;
        case 4:
            system("cls");
            Tor.ProducirTorta();
            break;
        case 5:
            system("cls");
            BajaTor();
            break;
        case 6:
            system("cls");
            AltaTor();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Numero Incorrecto. Ingrese Nuevamente" << endl;
            system("pause");

        }
    }
}

int SwitchClientes()
{
    int opc;
    while(true)
    {
        system("cls");
        recuadro(36, 5, 32, 16);
        gotoxy(49,6);
        cout << "Clientes" << endl;
        gotoxy(37,7);
        cout << "-------------------------------" << endl;
        gotoxy(37,8);
        cout << "1-   Ingresar Cliente Nuevo" << endl;
        gotoxy(37,10);
        cout << "2-      Mostrar Clientes" << endl;
        gotoxy(37,12);
        cout << "3-      Cargar un Pedido" << endl;
        gotoxy(37,14);
        cout << "4-  Mostrar Pedidos Pendientes" << endl;
        gotoxy(37,16);
        cout << "5-  Mostrar Pedidos Entregados" << endl;
        gotoxy(37,18);
        cout << "6-  Mostrar Todos los Pedidos" << endl;
        gotoxy(37,20);
        cout << "0-       Volver al Menu" << endl;

        recuadro(38, 24, 28, 2);
        gotoxy(43,25);
        cout << "Ingrese la Opcion: ";
        cin >> opc;
        switch(opc)
        {
        case 1:
            system("cls");
            CrearCliente();
            break;
        case 2:
            system("cls");
            MostrarClientes();
            break;
        case 3:
            system("cls");
            CrearPedido();
            break;
        case 4:
            system("cls");
            MostrarPedidosPendientes();
            break;
        case 5:
            system("cls");
            MostrarPedidosEntregados();
            break;
        case 6:
            system("cls");
            MostrarTodosPedidos();
            break;
        case 0:
            return 0;
            break;

        default:
            cout << "Numero Incorrecto. Ingrese Nuevamente" << endl;
            system("pause");

        }
    }
}

#endif // MENUS_H_INCLUDED

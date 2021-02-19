#ifndef OPCIONES_H_INCLUDED
#define OPCIONES_H_INCLUDED

int Opciones()
{
    int Opc;
    FILE *p,*bp; ///Backup y Apertura del Archivo de Mercarderias
    FILE *t,*bv;///Backup y Apertura del Archivo de Ventas
    class Mercaderias Mer;
    class Ventas Ven;
    while(true)
    {
        system("cls");
        recuadro(27, 5, 50, 12);
        gotoxy(49,6);
        cout << "Opciones" << endl;
        gotoxy(28,7);
        cout << "-------------------------------------------------" << endl;
        gotoxy(28,8);
        cout << "1-          Borrar Datos de las Mercarderias" << endl;
        gotoxy(28,10);
        cout << "2-        Restaurar Datos de las Mercarderias" << endl;
        gotoxy(28,12);
        cout << "3-            Borrar Datos de las Ventas" << endl;
        gotoxy(28,14);
        cout << "4-          Restaurar Datos de las Ventas" << endl;
        gotoxy(28,16);
        cout << "0-                 Volver al Menu" << endl;
        recuadro(38, 24, 28, 2);
        gotoxy(43,25);
        cout << "Ingrese la Opcion: ";
        cin >> Opc;
        switch(Opc)
        {
        case 1:
            bp=fopen("BackupMercarderias.dat","wb");
            p=fopen("Mercarderias.dat","rb");
            while(fread(&Mer,sizeof(Mercaderias),1,p)==1)
            {
                     fwrite(&Mer,sizeof(Mercaderias),1,bp);
            }
            fclose(bp);
            fclose(p);
            p=fopen("Mercarderias.dat","wb");
            fclose(p);
            cout << "Los Datos de los Mercarderias se Eliminaron" << endl;
            break;

        case 2:
            bp=fopen("BackupMercarderias.dat","rb");
            p=fopen("Mercarderias.dat","ab");
            while(fread(&Mer,sizeof(Mercaderias),1,bp)==1)
            {
                     fwrite(&Mer,sizeof(Mercaderias),1,p);
            }
            fclose(bp);
            fclose(p);
            break;
            cout << "Los Datos de los Mercarderias se Restauraron" << endl;
            break;

        case 3:
            bv=fopen("BackupVentas.dat","wb");
            t=fopen("Ventas.dat","rb");
            while(fread(&Ven,sizeof(Ventas),1,t)==1)
            {
                    fwrite(&Ven,sizeof(Ventas),1,bv);
            }
            fclose(bv);
            fclose(t);
            t=fopen("Ventas.dat","wb");
            fclose(t);
            cout << "Los Datos de las Ventas se Eliminaron" << endl;
            break;

        case 4:
            bv=fopen("BackupVentas.dat","rb");
            t=fopen("Ventas.dat","ab");
            while(fread(&Ven,sizeof(Ventas),1,bv)==1)
            {
                    fwrite(&Ven,sizeof(Ventas),1,t);
            }
            fclose(bv);
            fclose(t);
            break;
            cout << "Los Datos de las Ventas se Restauraron" << endl;
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
#endif // OPCIONES_H_INCLUDED

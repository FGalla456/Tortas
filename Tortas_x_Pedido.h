#ifndef TORTAS_X_PEDIDO_H_INCLUDED
#define TORTAS_X_PEDIDO_H_INCLUDED

void MostrarTorP(int);

class Tortas_x_Pedido{
    protected:
        int CodPed;
        int CodTor;
        float PVenta;
        float CVenta;

    public:

    int getCodTor(){
        return CodTor;
    }

    int getCodPed(){
        return CodPed;
    }

    float getPVenta(){
        return PVenta;
    }

    float getCVenta(){
        return PVenta;
    }

    float CargarTortasPed(int CodP,float *CTotal){
        FILE *p;
        class Tortas Tor;
        int Pos;
        float PVTotal=0;
        char SC='s';
        p=fopen("TortasPed.dat","ab");
        MostrarCodT(3,10);
        while (SC=='s' || SC== 'S'){
            CodPed=CodP;
            recuadro(32,18,40,4);
            gotoxy(33,20);
            cout << "Codigo de Torta: ";
            cin >> CodTor;
            Pos=BuscarTor(CodTor);
            while(Pos==-1){
                gotoxy(7,20);
                cout << "El Codigo de la Torta no Existe. Presione Enter" << endl;
                gotoxy(33,1);
                system("pause");
                gotoxy(33,20);
                cout << "Codigo de Torta:                    ";
                gotoxy(50,20);
                cin >> CodTor;
                Pos=BuscarTor(CodTor);
            }
            Tor.leerRegistroT(Pos);
            CVenta=Tor.getCosto();
            *CTotal+=CVenta;
            recuadro(32,24,40,4);
            gotoxy(33,26);
            cout << "Costo de Produccion: $" << CVenta << endl;
            recuadro(32,30,40,4);
            gotoxy(33,32);
            cout << "Precio de la Venta: $";
            cin >> PVenta;
            while(PVenta<=0){
                gotoxy(33,32);
                cout << "Precio Negativo. Presione Enter" << endl;
                gotoxy(33,1);
                system("pause");
                gotoxy(33,32);
                cout << "Precio de la Venta: $          ";
                gotoxy(54,32);
                cin >> PVenta;
            }
            PVTotal+=PVenta;
            fwrite(this,sizeof(Tortas_x_Pedido),1,p);
            recuadro(32,36,50,4);
            gotoxy(33,38);
            cout << char(168) << "Cargar Otra Torta al Pedido? S/N: ";
            cin >> SC;
            while (SC!='s'|| SC!='S' || SC!='n' || SC!='N'){
                gotoxy(33,38);
                cin >> SC;
            }
        }
        fclose(p);
        return PVTotal;
    }
};

void MostrarTorP(int CP){
    class Tortas_x_Pedido TP;
    FILE *p;
    p=fopen("TortasPed.dat","rb");
    while(fread(&TP,sizeof(Ingredientes_x_Torta),1,p)==1){
       if(CP==TP.getCodPed()){
            cout << "Codigo de Torta: " << TP.getCodTor() << endl;

            cout << "Costo de Produccion: $" << TP.getCVenta() << endl;

            cout << "Precio de Venta: $" << TP.getPVenta() << endl;
       }

}
}

#endif // TORTAS_X_PEDIDO_H_INCLUDED

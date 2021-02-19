#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

float BuscarCosto(int);
int ContarRegistrosV();
int EliminarProducida(int, int);
int OrdenarPorGanancia();
void ordenarGan(class Ventas *,long);
int TortasPed(int);


class Ventas
{
protected:
    int CodTor;
    int CodP;
    int CodCli;
    float Precio;
    float Costo;
    float Ganancia;
    bool Cliente;

public:

    bool getCliente(){
        return Cliente;
    }

    int getCodTor(){
        return CodTor;
    }

    float getPrecio(){
        return Precio;
    }

    float getCosto(){
        return Costo;
    }

    float getGanancia(){
        return Ganancia;
    }

    void GrabarDiscoV(){
        FILE *p;
        p=fopen("Ventas.dat","rb");
        fwrite(this,sizeof*this,1,p);
        fclose(p);
        }

    int cargarVentas (){
        int pos,VS=0;
        MostrarCodT(3,4);
        recuadro(32,10,40,4);
        gotoxy(33,12);
        cout << "Codigo de Torta: ";
        gotoxy(50,12);
        cin >> CodTor;
        pos=BuscarTor(CodTor);
        while(pos==-1)
        {
            gotoxy(33,12);
            cout << "Codigo Incorrecto. Presione Enter";
            gotoxy(32,1);
            system("pause");
            gotoxy(33,12);
            cout << "Codigo de Torta:                 ";
            gotoxy(50,12);
            cin >> CodTor;
            pos=BuscarTor(CodTor);
        }
        VS=EliminarProducida(CodTor,pos);
        if(VS==-1){
            recuadro(32,16,40,4);
            gotoxy(33,18);
            cout << "No Tiene esa Torta en Stock" << endl;
            system("pause");
            return 0;
        }
        recuadro(32,16,40,4);
        gotoxy(33,18);
        cout << "Precio de la Venta: $";
        gotoxy(53,18);
        cin >> Precio;
        while (Precio<0)
        {
            gotoxy(33,18);
            cout << "Precio Invalido. Presione Enter";
            gotoxy(32,1);
            system("pause");
            gotoxy(33,18);
            cout << "Precio de la Venta: $          ";
            gotoxy(52,18);
            cin >> Precio;
        }
        Costo=BuscarCosto(pos);
        recuadro(32,22,40,4);
        gotoxy(33,24);
        cout << "Costo: $" << Costo << endl;
        Ganancia=Precio-Costo;
        recuadro(32,28,40,4);
        gotoxy(33,30);
        cout << "Ganancia: $" << Ganancia << endl;
        Cliente=false;
        system("pause");
        return 0;
    }

    int cargarVentasCli(){
        class Pedidos Ped;
        int pos,CP,VTP=0;
        MostrarPedPen(3,4);
        recuadro(32,10,40,4);
        gotoxy(33,12);
        cout << "Ingrese El N" << char(167) <<" de Pedido: ";
        gotoxy(58,12);
        cin >> CP;
        pos=BuscarPedido(CP);
        while(pos==-1){
            gotoxy(33,12);
            cout << "Pedido Inexistente. Presione Enter";
            gotoxy(32,1);
            system("pause");
            gotoxy(33,12);
            cout << "Ingrese El N" << char(167) <<" de Pedido:          ";
            gotoxy(58,12);
            cin >> CP;
            pos=BuscarPedido(CP);
        }
        CodP=CP;
        VTP=TortasPed(CP);
        while(VTP==-1){
            return 0;
        }
        Ped.LeerRegistroP(pos);
        CodCli=Ped.getCodCli();
        Costo=Ped.getCTotal();
        Precio=Ped.getPVTotal();
        recuadro(32,16,40,4);
        gotoxy(33,18);
        cout << "Costo Total de Produccion: $" << Costo << endl;
        recuadro(32,22,40,4);
        gotoxy(33,24);
        cout << "Precio de Venta: $" << Precio << endl;
        Ganancia=Precio-Costo;
        recuadro(32,28,40,4);
        gotoxy(33,30);
        cout << "Ganancia: $" << Ganancia << endl;
        Cliente=true;
        Ped.setEstado(false);
        Ped.GrabarRegistroP(pos);
        system("pause");
        return 0;
    }

    int LeerRegistro(int pos){
        int x;
        FILE *p;
        p=fopen("Ventas.dat","rb");
        fseek(p,pos*sizeof(this),0);
        x=fread(this,sizeof*this,1,p);
        fclose(p);
        return x;
        }

    void MostrarV(){

        recuadro(32,4,40,4);
        gotoxy(33,6);
        cout << "Codigo de Torta: " << CodTor << endl;
        recuadro(32,10,40,4);
        gotoxy(33,12);
        cout << "Precio de la Venta: $" << Precio << endl;
        recuadro(32,16,40,4);
        gotoxy(33,18);
        cout << "Costo de Produccion: $" << Costo << endl;
        recuadro(32,22,40,4);
        gotoxy(33,24);
        cout << "Ganancia: $" << Ganancia << endl;

    }

    void MostrarVentaCli(){
        char V;
        recuadro(32,4,40,4);
        gotoxy(33,6);
        cout << "N" << char(167) <<" de Pedido: " << CodP << endl;
        recuadro(32,10,40,4);
        gotoxy(33,12);
        cout << "Precio de la Venta: $" << Precio << endl;
        recuadro(10,16,40,4);
        gotoxy(11,18);
        cout << "Costo de Produccion: $" << Costo << endl;
        recuadro(60,16,40,4);
        gotoxy(61,18);
        cout << "Ganancia: $" << Ganancia << endl;
        recuadro(32,22,50,4);
        gotoxy(33,24);
        cout << char(168) << "Quiere ver la Informacion de lo Vendido? S/N : ";
        gotoxy(56,24);
        cin >> V;

        if(V=='S' || V=='s'){
            recuadro(10,28,40,4);
            gotoxy(11,30);
            cout << "Codigo de Cliente: " << CodCli << endl;
            MostrarTorP(CodP);
            }

        system("pause");
        }

};

void CrearVentaCliente(){
        FILE *p;
        class Ventas Ven;
        p=fopen("Ventas.dat","ab");
        Ven.cargarVentasCli();
        Ven.GrabarDiscoV();
        fclose(p);
    }

void CrearVentaParticular (){
        FILE *p;
        class Ventas Ven;
        p=fopen("Ventas.dat","ab");
        Ven.cargarVentas();
        Ven.GrabarDiscoV();
        fclose(p);
    }

int TortasPed(int CP){
    class Tortas_x_Pedido TP;
    FILE *p;
    int posT,VS=0,CodT;
    p=fopen("TortasPed.dat","rb");
    while(fread(&TP,sizeof(Ingredientes_x_Torta),1,p)==1){
       if(CP==TP.getCodPed()){
            CodT=TP.getCodTor();
            posT=BuscarTor(CodT);
            VS=EliminarProducida(CodT,posT);
            if(VS==-1){
                recuadro(32,16,40,4);
                gotoxy(33,18);
                cout << "No Tiene es esa Torta en Stock" << endl;
                system("pause");
                return 0;
                }

        }
    }
    return 0;
}

int EliminarProducida(int CodTor,int pos){
        class Tortas Tor;
        int Sto;
        Tor.leerRegistroT(pos);
        Sto=Tor.getStock();
        if(Sto>0){
        Sto--;
        Tor.setStock(Sto);
        Tor.grabarRegistroT(pos);
        }
        else{
            return -1;
        }
        return 0;
    }

int MostrarVenta(){
        FILE *p;
        int pos=0;
        Ventas Ven;
        p=fopen("Ventas.dat","rb");
        if(p==NULL){
            cout << "El Archivo no pudo ser abierto" << endl;
            return 1;
        }
        while(Ven.LeerRegistro(pos++)==1){
            if(Ven.getCliente()==false){

                Ven.MostrarV();
                gotoxy(32,52);
                cout << "Presione Enter Para Ver el Siguiente Registro.";
                gotoxy(32,1);
                system("pause");
                system("cls");
            }
            else{
                Ven.MostrarVentaCli();
                gotoxy(32,52);
                cout << "Presione Enter Para Ver el Siguiente Registro.";
                gotoxy(32,1);
                system("pause");
                system("cls");
            }
            }
    fclose(p);
    return 0;
    }

float BuscarCosto(int pos){
        FILE *p ;
        int x;
        Tortas Tor;
        p=fopen("Tortas.dat","rb");
        fseek(p,pos*sizeof(Tortas),0);
        x=fread(&Tor,sizeof(Tortas),1,p);
        if(x==0){
            cout << "No se Pudo Encontrar el Costo" << endl;
        }
        fclose(p);
        return Tor.getCosto();
    }

int CopiarEnMemoria(class Ventas *V,long Cant){
    FILE *p;

    p=fopen("Ventas.dat","rb");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        exit(1);
    }
    fread(V,sizeof(class Ventas),Cant,p);
    fclose(p);
    return 0;
    }

int ContarRegistrosV(){
    FILE *p;
    long x; ///Contiene el valor total que tiene el Archivo
    p=fopen("Ventas.dat","rb");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        return 1;
    }
    fseek(p,0,2);
    x=ftell(p);
    return x/sizeof(class Ventas);
    }

void MostrarXGan(class Ventas *V,long cant){

    int i;
        for(i=0;i<cant;i++){
                recuadro(32,4,40,4);
                gotoxy(33,6);
                cout << "Codigo de Torta: " << V[i].getCodTor() << endl;
                recuadro(32,10,40,4);
                gotoxy(33,12);
                cout << "Precio de Venta: $" << V[i].getPrecio() << endl;
                recuadro(32,16,40,4);
                gotoxy(33,18);
                cout << "Costo de Produccion: $" << V[i].getCosto() << endl;
                recuadro(32,22,40,4);
                gotoxy(33,24);
                cout << "Ganancia de la Venta: $" << V[i].getGanancia() << endl;
                gotoxy(33,28);
                cout << "Presione Enter Para Ver el Siguiente Registro.";
                gotoxy(32,1);
                system("pause");
                system("cls");
        }
    }

int OrdenarPorGanancia(){
    class Ventas *Ven;
    long Cant;
    Cant=ContarRegistros();
    Ven=(class Ventas *) malloc(Cant*sizeof(class Ventas));
    if(Ven==NULL) { ///Ingresa aca si el Vector no pudo ser creado
        return 1;
    }
    CopiarEnMemoria(Ven,Cant);
    ordenarGan(Ven,Cant);
    MostrarXGan(Ven,Cant);
    system("pause");
    free(Ven);
    return 0;
}

void ordenarGan(class Ventas *V,long Cant){
    int i, t, posmin;
    class Ventas Aux;
    for(i=0;i<Cant-1;i++){
        posmin=i;
        for(t=i+1;t<Cant;t++){
            if(V[posmin].getGanancia()>V[t].getGanancia()){
                posmin=t;
            }
        }
    Aux=V[i];
    V[i]=V[posmin];
    V[posmin]=Aux;
    }

}

#endif // VENTAS_H_INCLUDED

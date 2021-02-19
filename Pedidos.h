#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

int BuscarPedido(int );
void MostrarPedPen(int ,int );
void PonerEnCero(int*,float*,float*);
int CodPedAut();
void MostrarPedPen(int,int);
int BuscarPedido(int);

class Pedidos
{
protected:
    int CodPed;
    int CodCli;
    float CTotal;   ///Costo Total(Suma todos los Costos Ingresados del registro)
    float PVTotal; ///Precio de Venta Total(Suma todos los PVentas Ingresados del registro)
    bool Estado; ///True = Pendiente de entrega / False = Entregado
public:

///Inicio de los Getters///

    int getCodPed(){
        return CodPed;
    }

    int getCodCli(){
        return CodCli;
    }

    float getPVTotal(){
        return PVTotal;
    }

    float getCTotal(){
        return CTotal;
    }

    bool getEstado(){
        return Estado;
    }

///Fin de los Getters///

///Inicio de los Setters///

    void setCodPed(int CP){
        CodPed=CP;
    }

    void setCodCli(int cc){
        CodCli=cc;
    }

    void setEstado(bool Est){
        Estado=Est;
    }

///Fin de los Setters///

///Inicio de las Funciones///


    int LeerRegistroP(int pos){         ///Lee un Registro de Pedidos
        int x=0;
        FILE *p ;
        p=fopen("Pedidos.dat","rb");
        if(p==NULL)
        {
            cout << "Error Al Abrir el Archivo" << endl;
            return -1;
        }
        fseek(p,pos*sizeof *this,0);
        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
    }

    int GrabarRegistroP(int pos){
        FILE *p;
        p=fopen ("Pedidos.dat","rb+");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fseek(p,pos * sizeof *this,0);
        fwrite(this, sizeof *this,1,p);
        fclose(p);
        return 0;
    }

    int GrabarDiscoP(){
    FILE *p;
        p=fopen ("Pedidos.dat","ab");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fwrite(this, sizeof *this,1,p);
        fclose(p);
        return 0;
    }

    void CargarPedido(){    ///Carga los Datos del Pedido
    int C,VC;
    class Tortas_x_Pedido TP;

    PVTotal=0;
    CTotal=0;
    MostrarCodCli(3,4);
    recuadro(14,10,30,4);
    gotoxy(15,12);
    cout << "Pedido N"<< char(167) << ": ";
    C=CodPedAut()+1;
    CodPed=C;
    gotoxy(26,12);
    cout << CodPed << endl;
    recuadro(50,10,50,4);
    gotoxy(51,12);
    cout << "Codigo de Cliente: ";
    gotoxy(70,12);
    cin >> CodCli;
    VC=BuscarCli(CodCli);
    while(VC==-1){
        gotoxy(51,12);
        cout << "El Codigo de Cliente no Existe. Presione Enter" << endl;
        gotoxy(15,1);
        system("pause");
        gotoxy(51,12);
        cout << "Codigo de Cliente:                            ";
        gotoxy(70,12);
        cin >> CodCli;
        VC=BuscarCli(CodCli);
    }
    system("cls");
    recuadro(9,3,40,4);
    gotoxy(10,5);
    cout << "Pedido N"<< char(167) << ": " << CodPed;
    recuadro(59,3,40,4);
    gotoxy(60,5);
    cout << "Codigo de Cliente: " << CodCli;
    PVTotal=TP.CargarTortasPed(CodPed,&CTotal);
    recuadro(10,46,40,4);
    gotoxy(11,48);
    cout << "Costo Total de Produccion: $" << CTotal << endl;
    recuadro(58,46,40,4);
    gotoxy(59,48);
    cout << "Precio de Venta Total: $" << PVTotal << endl;
    Estado=true;
    system("pause");
    }

    void MostrarPedido(){   ///Muestra un Pedido
        char V;
        recuadro(14,4,30,4);
        gotoxy(15,6);
        cout << "Pedido N" << char(167) << ": " << CodPed << endl;
        recuadro(50,4,30,4);
        gotoxy(51,6);
        cout << "Codigo de Cliente: " << CodCli << endl;
        recuadro(38,18,30,4);
        gotoxy(399,20);
        cout << "Costo Total de Produccion: $" << CTotal << endl;
        recuadro(40,24,30,4);
        gotoxy(41,26);
        cout << "Precio de Venta Total: $" << PVTotal << endl;
        recuadro(32,30,45,4);
        gotoxy(33,32);
        cout << char(168) << "Quiere ver las Tortas del Pedido? S/N : ";
        gotoxy(56,32);
        cin >> V;
        if(V=='S' || V=='s'){
            MostrarTorP(CodPed);
        }
    }
};

void CrearPedido(){     ///Crea el Pedido
        FILE *p;
        class Pedidos Ped;
        p=fopen("Pedidos.dat","ab");
        Ped.CargarPedido();
        Ped.GrabarDiscoP();
        fclose(p);
    }

void MostrarPedPen(int x, int y){   ///Muestra los Codigos de Pedidos Pendientes
    int C=0;
    FILE *p;
    class Pedidos Ped;
    p=fopen("Pedidos.dat","rb");
    recuadro(x-1,y-1,100,6);
    gotoxy(40,2);
    cout << "Pedidos Pendientes: " << endl;
    while(fread(&Ped,sizeof(Pedidos),1,p)==1)
    {
        if(Ped.getEstado()==true){
        gotoxy(x,y);
        cout << Ped.getCodPed() << endl;

        y++;
        C++;
        if(C%4==0)
        {
            x+=15;
            for(int i=4; i<=8; i++)
            {
                gotoxy(x,i-8+y);
                cout << char (186) << endl;
            }
            x+=15;
            y=4;
        }
        }
    }
}

int BuscarPedido(int cod){ ///Busca un Pedido Especifico
        FILE *p;
        int pos=0;
        class Pedidos Ped;
        p=fopen("Pedidos.dat","rb");
        while(fread(&Ped,sizeof(Pedidos),1,p)==1){
            if(Ped.getCodPed()==cod){
                return pos;
            }
            pos++;
        }
        return -1;
    }

void MostrarTodosPedidos(){         ///Lee Todos los Pedidos
        int Pos=0;
        Pedidos Ped;
        while (Ped.LeerRegistroP(Pos)==1)
        {
                Ped.MostrarPedido();
                if(Ped.getEstado()==true){
                    gotoxy(32,53);
                    cout << "El Pedido No fue Entregado" << endl;
                    gotoxy(32,54);
                    cout << "Presione Enter para el Siguiente Pedido" << endl;
                    gotoxy(32,1);
                    system("pause");
                    system("cls");
                }
                else{
                    gotoxy(32,53);
                    cout << "El Pedido fue Entregado" << endl;
                    gotoxy(32,54);
                    cout << "Presione Enter para el Siguiente Pedido" << endl;
                    gotoxy(32,1);
                    system("pause");
                    system("cls");
                }
                Pos++;
        }

    }

void MostrarPedidosPendientes(){    ///Lee Todos los Pedidos Pendientes de Entrega
        int Pos=0;
        Pedidos Ped;
        while (Ped.LeerRegistroP(Pos)==1)
        {
            if(Ped.getEstado()==true)
            {
                Ped.MostrarPedido();
                gotoxy(32,53);
                cout << "Presione Enter para el Siguiente Pedido" << endl;
                gotoxy(32,1);
                system("pause");
                system("cls");
            }
            Pos++;
        }

    }

void MostrarPedidosEntregados(){    ///Lee Todos los Pedidos Entregados
        int Pos=0;
        Pedidos Ped;
        while (Ped.LeerRegistroP(Pos)==1)
        {
            if(Ped.getEstado()==false)
            {
                Ped.MostrarPedido();
                gotoxy(32,53);
                cout << "Presione Enter para el Siguiente Pedido" << endl;
                gotoxy(32,1);
                system("pause");
                system("cls");
            }
            Pos++;
        }

    }

int CodPedAut(){    ///Genera un Codigo AutoNumerico para el Pedido
    FILE *p;
    long x;
    p=fopen("Pedidos.dat","rb");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        return 1;
    }
    fseek(p,0,2);
    x=ftell(p);
    return x/sizeof(class Pedidos);
    }
#endif // PEDIDOS_H_INCLUDED

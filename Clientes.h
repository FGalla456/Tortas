#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

int CodAutCli();
void CrearCliente();
void MostrarClientes();
void MostrarCodCli(int ,int);
int BuscarCli(int );

class Cliente
{
protected:
    int CodCli;
    char Nombre[30];
    char Apellido[30];
    int Telefono;
    char Domicilio [50];
    ///Pedidos
    bool Estado;

public:

///Inicio de los Prototipos///

///Fin de los Prototipos///

///Inicio de los Getters///

    int getCodCli(){
        return CodCli;
    }

    bool getEstado(){
        return Estado;
    }

    char getLNombre(int L){
        return Nombre[L];
    }

    char *getApellido(){
        return Apellido;
    }

///Fin de los Getters///

///Inicio de las Funciones///

    int LeerRegistroC(int pos){       ///Lee un Registro de Cliente
        int x=0;
        FILE *p ;
        p=fopen("Clientes.dat","rb");
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

    int GrabarDiscoC(){
        FILE *p;
        p=fopen ("Clientes.dat","ab");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fwrite(this, sizeof *this,1,p);
        fclose(p);
        return 1;
    }

    int GrabarRegistroC(int pos){       ///Graba un Registro de Cliente
        FILE *p;
        p=fopen ("Clientes.dat","rb+");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fseek(p,pos * sizeof *this,0);
        fwrite(this, sizeof *this,1,p);
        fclose(p);
    }

    void CargarCliente(){   ///Carga los Datos del Cliente
        int C=0;
        recuadro(30,4,45,4);
        gotoxy(31,6);
        cout << "Codigo de Cliente: ";
        C=CodAutCli()+1;
        CodCli=C;
        gotoxy(50,6);
        cout << CodCli << endl;

        recuadro(5,14,45,4);
        gotoxy(6,16);
        cout << "Nombre: ";
        cin.ignore(30,'\n');
        gotoxy(14,16);
        cin.getline (Nombre,30);

        recuadro(55,14,45,4);
        gotoxy(56,16);
        cout << "Apellido: ";
       // cin.ignore(30,'\n');
        gotoxy(66,16);
        cin.getline (Apellido,30);

        recuadro(30,24,45,4);
        gotoxy(31,26);
        cout << "Telefono: ";
        gotoxy(42,26);
        cin >> Telefono;

        recuadro(30,34,45,4);
        gotoxy(31,36);
        cout << "Domicilio: ";
        cin.ignore(50,'\n');
        gotoxy(43,36);
        cin.getline(Domicilio,50);

        Estado=true;
   }

    void MostrarCliente(int x, int y){  ///Muestra un Cliente

    recuadro(x-1,y,45,6);
    gotoxy(x,y+1);
    cout << "Codigo de Cliente: " << CodCli << endl;
    gotoxy(x,y+2);
    cout << "Nombre: " << Nombre << endl;
    gotoxy(x,y+3);
    cout << "Apellido: " << Apellido << endl;
    gotoxy(x,y+4);
    cout << "Telefono: " << Telefono << endl;
    gotoxy(x,y+5);
    cout << "Domicilio: " << Domicilio << endl;
    }


};

void CrearCliente(){    ///Crea un Registro de Cliente ///externa
        FILE *p;
        class Cliente Cli;
        p=fopen("Clientes.dat","ab");
        Cli.CargarCliente();
        Cli.GrabarDiscoC();
        fclose(p);
   }

void MostrarClientes(){     ///Lee Todos los Clientes ///externa
    int Pos=0;
    Cliente Cli;
    int x=5,y=5;
    while (Cli.LeerRegistroC(Pos)==1)
    {
        if(Cli.getEstado()==true)
        {
            Cli.MostrarCliente(x,y);
            x+=50;
                if(Pos%2==1 && Pos!=0){
                    y+=10;
                    x=5;
                    if(Pos%4==3 && Pos!=0){
                            gotoxy(15,1);
                        }
                }
        }
        gotoxy(15,1);
        system("pause");
        Pos++;
        }
    }

void MostrarCodCli(int x, int y) ///Muestra los Codigos Ya Utilizados ///externa
{
    int C=0;
    FILE *p;
    class Cliente Cli;
    p=fopen("Clientes.dat","rb");
    recuadro(x-1,y-1,100,6);
    gotoxy(40,2);
    cout << " Codigo Ya utilizados: " << endl;
    while(fread(&Cli,sizeof(Cliente),1,p)==1)
    {

        gotoxy(x,y);
        cout << Cli.getCodCli() << " = " << Cli.getLNombre(0)  << "." << Cli.getApellido() << endl;

        y++;
        C++;
        if(C%4==0)
        {
            x+=20;
            for(int i=4; i<=8; i++)
            {
                gotoxy(x,i-8+y);
                cout << char (186) << endl;
            }
            x+=10;
            y=4;
        }
    }
}

int CodAutCli(){       ///Genera un Codigo de Cliente AutoNumerico ///externa
    FILE *p;
    long x;
    p=fopen("Clientes.dat","rb");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        return 1;
    }
    fseek(p,0,2);
    x=ftell(p);
    return x/sizeof(class Cliente);
    }

int BuscarCli(int cod){    ///Busca un Cliente Especifico ///externa
        FILE *p;
        int pos=0;
        Cliente Cli;
        p=fopen("Clientes.dat","rb");
        while(fread(&Cli,sizeof(Cli),1,p)==1){
            if(Cli.getCodCli()==cod){
                return pos;
            }
            pos++;
        }
        return -1;
    }



#endif // CLIENTES_H_INCLUDED

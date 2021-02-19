#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

void MostrarCod(int ,int );
int ContarRegistros();
void CopiarEnMemoria(class Mercaderias *,long );
int BuscarCod(int);
void ordenarCod(class Mercaderias *, long);
void MostraXCod(Mercaderias*, long);
void ordenarPre(class Mercaderias *, long);
void MostrarXPre(Mercaderias *,long);
void CrearCliente();
void ModificarIT(int, float);
void MostrarUnidades();

class Mercaderias
{

protected:
    int Codigo;
    char Nombre[30];
    float Precio;
    float Stock;
    char Unidad;
    float PUnitario;
    bool Estado;

public:

///Inicio de los Setters///

    void setCod(int cod)
    {
        Codigo=cod;
    }

    void setPrecio(float pre)
    {
        Precio=pre;
    }

    void setStock(float sto)
    {
        Stock=sto;
    }

    void setEstado(bool est)
    {
        Estado=est;
    }

    void setPrecioU(float pu)
    {
        PUnitario=pu;
    }

///Fin de los Setters///

///Inicio de los Getters///

    int getCod()
    {
        return Codigo;
    }

    bool getEstado()
    {
        return Estado;
    }

    char *getNombre()
    {
        return Nombre;
    }

    float getPrecio()
    {
        return Precio;
    }

    float getStock()
    {
        return Stock;
    }

    float getPUnitario()
    {
        return PUnitario;
    }

    char getUnidad(){
        return Unidad;
    }
///Fin de los Getters///

///Inicio de las Funciones///

    void mostrarMercaderia (int x, int y)  ///Muestra El Registro
    {
        recuadro(x-1,y,45,7);
        gotoxy(x,y+1);
        cout << "Codigo: "<< Codigo <<endl;
        gotoxy(x,y+2);
        cout << "Nombre: "<< Nombre <<endl;
        gotoxy(x,y+3);
        cout << "Unidad: " << Unidad << endl;
        gotoxy(x,y+4);
        cout << "Precio: " << Precio << endl;
        gotoxy(x,y+5);
        cout << "Stock: "<< Stock <<endl;
        gotoxy(x,y+6);
        cout << "Precio Unitario: " << PUnitario << endl;
        gotoxy(x,y+8);
        system("pause");
    }

    char VerificarUnidad(char Uni)  /// Verifica que el dato ingresado sea correcto
    {
        switch(Uni)
        {
        case 'u':
            return 'U';
            break;
        case 'U':
            return 'U';
            break;
        case 'l':
            return 'L';
            break;
        case 'L':
            return 'L';
            break;
        case 'K':
            return 'K';
            break;
        case 'k':
            return 'K';
            break;
        case 'g':
            return 'G';
            break;
        case 'G':
            return 'G';
            break;

        default:
            return 0;
            break;
        }
    }

    void cargarMercaderia()  ///Ingresa los datos del registro que posteriormente se guardan en el Archivo
    {
        int Ve=0,VeU=0;
        MostrarCod(3,4);
        recuadro(14,10,30,4);
        gotoxy(15,12);
        cout << "Codigo: ";
        cin >> Codigo;
        Ve=BuscarCod(Codigo);
        while(Ve!=-1)
        {
            gotoxy(15,12);
            cout << "Codigo ya usado. Codigo: ";
            cin >> Codigo;
            Ve=BuscarCod(Codigo);
        }
        recuadro(50,10,40,4);
        gotoxy(51,12);
        cout << "Nombre: ";
        cin.ignore(30,'\n');
        cin.getline (Nombre,30);
        recuadro(14,19,30,4);
        MostrarUnidades();
        gotoxy(15,21);
        cout << "Medida: ";
        cin >> Unidad;
        VeU=VerificarUnidad(Unidad);
        while(VeU==0)
        {
            gotoxy(15,21);
            cout << "Medida no Valida. Medida: ";
            cin >> Unidad;
            VeU=VerificarUnidad(Unidad);
        }
        Unidad=VeU;
        recuadro(14,28,40,4);
        gotoxy(15,30);
        cout << "Precio: $";
        cin >> Precio;
        while (Precio < 0)
        {
            gotoxy(15,30);
            cout << "Precio Invalido. Precio: $";
            cin >> Precio;
        }
        recuadro(50,28,30,4);
        gotoxy(51,30);
        cout << "Stock: ";
        cin >> Stock;
        while(Stock < 0)
        {
            gotoxy(51,30);
            cout << "Stock Invalido. Stock: ";
            cin >> Stock;
        }
        PUnitario=Precio/Stock;
        recuadro(50,34,40,4);
        gotoxy(51,36);
        cout << "Precio por Unidad: $" << PUnitario << endl;
        gotoxy(13,45);
        system("pause");
        Estado=true;
    }

    int leerRegistroMer(int pos)    ///Lee un Registro de Mercaderia
    {
        int x=0;
        FILE *p ;
        p=fopen("Mercaderia.dat","rb");
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

    int grabarRegistroMer(int pos)  ///Sobrescribe un Registro Modificado
    {
        FILE *p;
        p=fopen ("Mercaderia.dat","rb+");
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

    int grabarDiscoMer()
        {
        FILE *p;
        p=fopen ("Mercaderia.dat","ab");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fwrite(this, sizeof *this,1,p);
        fclose(p);
        return 0;
        }

};

    void CrearMer()  ///Crea y guarda un registro
    {
        Mercaderias Mer;
        FILE *p;
        p=fopen("Mercaderia.dat","ab");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            exit(1);
        }
        Mer.cargarMercaderia();
        Mer.grabarDiscoMer();
        fclose(p);
    }

    void MostrarCod(int x, int y) ///Muestra los Codigos Ya Utilizados
    {
    int C=0;
    FILE *p;
    class Mercaderias Mer;
    p=fopen("Mercaderia.dat","rb");
    recuadro(x-1,y-1,100,6);
    gotoxy(40,y-2);
    cout << " Codigo Ya utilizados: " << endl;
    while(fread(&Mer,sizeof(Mercaderias),1,p)==1)
    {

        gotoxy(x,y);
        cout << Mer.getCod() << " = " << Mer.getNombre() << endl;

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

    void CopiarEnMemoria(class Mercaderias *M, long Cant)  ///Copia todo el Archivo a la Memoria
    {
        FILE *p;
        p=fopen("Mercaderia.dat","rb");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            exit(1);
        }
        fread(M,sizeof(class Mercaderias),Cant,p);
        fclose(p);
    }

    int ContarRegistros()  ///Cuenta Los registros que hay en el Archivo
    {
        FILE *p;
        long x; ///Contiene el valor total que tiene el Archivo
        p=fopen("Mercaderia.dat","rb");
        if(p==NULL)
        {
            cout << "El Archivo no Pudo ser Abierto" << endl;
            return 1;
        }
        fseek(p,0,2);
        x=ftell(p);
        return x/sizeof(class Mercaderias);
    }

    int BuscarCod(int Cod)  /// Busca el codigo Ingresado y Devuelve la posicion, Tambien funciona para saber si el codigo existe
    {
        Mercaderias Mer;
        int pos=0;
        while(Mer.leerRegistroMer(pos)==1)
        {
            if(Cod==Mer.getCod())
            {
                return pos;
            }
            pos++;
        }
        pos=0;
        return -1;
    }

    void MostrarMer()  ///Muestra los Registros Mientras su estado sea Activo(1). Se muestran en el Orden que fueron cargados
    {
        class Mercaderias Mer;
        int Pos=0;
        int x=5,y=5;
        while (Mer.leerRegistroMer(Pos)==1)
        {
            if(Mer.getEstado()==1)
            {
                Mer.mostrarMercaderia(x,y);
                x+=50;
                if(Pos%2==1 && Pos!=0){
                    y+=10;
                    x=5;
                    if(Pos%4==3 && Pos!=0){
                            gotoxy(15,1);
                            system("pause");
                    }
                }

            }
            Pos++;
        }

    }

    int ModificarMer()  ///Modifica un Registro
    {
        class Mercaderias Mer;
        int Cod,V;
        MostrarCod(3,4);
        recuadro(14,10,45,4);
        gotoxy(15,12);
        cout << "Ingrese el Codigo: " ;
        cin >> Cod;
        V=BuscarCod(Cod);
        if(V==-1)
        {
            gotoxy(15,12);
            cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
            system("pause");
            return 0;
        }
        Mer.leerRegistroMer(V);
        if(Mer.getEstado()==true)
        {
            Mer.cargarMercaderia();
            Mer.setCod(Cod);
            Mer.grabarRegistroMer(V);
            recuadro(44,38,30,3);
            gotoxy(45,40);
            cout << "El Registro fue Modificado" << endl;
            system("pause");
        }
        return 0;
    }

    int BajaMer()  ///Hace una Baja Logica de un Registro
    {
        class Mercaderias Mer;
        int Cod,Pos;
        MostrarCod(3,4);
        recuadro(14,10,45,4);
        gotoxy(15,12);
        cout << "Ingrese el Codigo: " ;
        cin >> Cod;
        Pos=BuscarCod(Cod);
        if(Pos==-1)
        {
            gotoxy(15,12);
            cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
            system("pause");
            return 0;
        }
        Mer.leerRegistroMer(Pos);
        if(Mer.getEstado()==true)
        {
            Mer.setEstado(false);
            Mer.grabarRegistroMer(Pos);
            recuadro(44,23,30,3);
            gotoxy(45,25);
            cout << "El Registro fue dado de Baja" << endl;
            system("pause");
        }
        else
        {
            recuadro(44,23,30,3);
            gotoxy(45,25);
            cout << "El Registro ya fue dado de Baja" << endl;
            system("pause");
        }
        return 0;
    }

    int AltaMer() ///Hace un Alta Logica de un Registro
    {
        class Mercaderias Mer;
        int Cod,Pos;
        MostrarCod(3,4);
        recuadro(14,10,45,4);
        gotoxy(15,12);
        cout << "Ingrese el Codigo: " ;
        cin >> Cod;
        Pos=BuscarCod(Cod);
        if(Pos==-1)
        {
            gotoxy(15,12);
            cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
            system("pause");
            return 0;
        }
        Mer.leerRegistroMer(Pos);
        if(Mer.getEstado()==false)
        {
            Mer.setEstado(true);
            Mer.setCod(Cod);
            Mer.grabarRegistroMer(Pos);
            recuadro(44,23,30,3);
            gotoxy(45,25);
            cout << "El Registro fue dado de Alta Nuevamente" << endl;
            system("pause");
        }
        else
        {
            recuadro(44,23,30,3);
            gotoxy(45,25);
            cout << "El Registro esta dado de Alta" << endl;
            system("pause");
        }
        return 0;
    }

    float AgregarStock()    ///Agrega Stock a una Mercaderia en Especial
    {
        class Mercaderias Mer;
        int Cod,Pos;
        float Sto,Pre;
        MostrarCod(3,4);
        recuadro(14,10,45,4);
        gotoxy(15,12);
        cout << "Ingrese el Codigo de Mercaderia: ";
        cin >> Cod;
        Pos=BuscarCod(Cod);
        if(Pos==-1)
        {
            gotoxy(15,12);
           cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
            gotoxy(15,22);
            system("pause");
            return 0;
        }
        Mer.leerRegistroMer(Pos);
        recuadro(14,20,40,4);
        gotoxy(15,22);
        cout << "Ingrese el Stock a Agregar: ";
        cin >> Sto;
        recuadro(14,30,40,4);
        gotoxy(15,32);
        cout << "Ingrese el Precio de Compra: $";
        cin >>Pre;
        Sto=Mer.getStock()+Sto;
        Pre=Mer.getPrecio()+Pre;
        Mer.setPrecioU(Pre/Sto);
        recuadro(14,40,40,4);
        gotoxy(15,42);
        cout << "Nuevo Precio por Unidad: $" << Mer.getPUnitario()<< endl;
        Mer.setStock(Sto);
        Mer.setPrecio(Pre);
        Mer.grabarRegistroMer(Pos);
        ModificarIT(Cod,Pre/Sto);
        system("pause");
        return 0;
    }

    void MostrarXCod(class Mercaderias *M,long cant) ///Muestra Toda la Mercaderia Ordenada por Codigo
    {

        int i,x=5,y=5;
        for(i=0; i<cant; i++)
        {
            if(M[i].getEstado()==1)
            {
                recuadro(x-1,y,45,6);
                gotoxy(x,y+1);
                cout << "Codigo: "<< M[i].getCod() <<endl;
                gotoxy(x,y+2);
                cout << "Nombre: "<< M[i].getNombre() <<endl;
                gotoxy(x,y+3);
                cout << "Precio: $" << M[i].getPrecio() << endl;
                gotoxy(x,y+4);
                cout << "Unidad: " << M[i].getUnidad() << endl;
                gotoxy(x,y+5);
                cout << "Stock: "<< M[i].getStock() <<endl;
            }
            x+=50;
            if(i%2==1 && i!=0){
                    y+=10;
                    x=5;
                    if(i%4==3 && i!=0){
                            gotoxy(15,1);
                            system("pause");
                    }
                }

        }

    }

    int OrdenarXCodigo()  ///Ordena Por Codigo Los datos del Archivo y los muestra. El Cambio NO es Permanente
    {
        class Mercaderias *Merc;
        long Cant;
        Cant=ContarRegistros();
        Merc=(class Mercaderias *) malloc(Cant* sizeof(class Mercaderias));
        if(Merc==NULL)
        {
            cout << "El Archivo no pudo ser Abierto" << endl;
            return 1;
        }
        CopiarEnMemoria(Merc,Cant);
        ordenarCod(Merc,Cant);
        MostrarXCod(Merc,Cant);
        system("pause");
        free(Merc);
        return 0;
    }

    int OrdenarXPrecio()  ///Ordena Por Precio Los datos del Archivo y los muestra. El Cambio NO es Permanente
    {
        class Mercaderias *Mer;
        long Cant;
        Cant=ContarRegistros();
        Mer=(class Mercaderias *) malloc(Cant*sizeof(class Mercaderias));
        if(Mer==NULL)   ///Ingresa aca si el Vector no pudo ser creado
        {
            return 1;
        }
        CopiarEnMemoria(Mer,Cant);
        ordenarPre(Mer,Cant);
        MostrarXPre(Mer,Cant);
        gotoxy(1,1);
        system("pause");
        free(Mer);
        return 0;
    }

    void ordenarPre(class Mercaderias *M,long cant) ///Ordena la Mercaderia Por Precio (FOR DE ORDENAMIENTO)
    {
        int i, t, posmin;
        class Mercaderias Aux;
        for(i=0; i<cant-1; i++)
        {
            posmin=i;
            for(t=i+1; t<cant; t++)
            {
                if(M[posmin].getPrecio()>M[t].getPrecio())
                {
                    posmin=t;
                }
            }
            Aux=M[i];
            M[i]=M[posmin];
            M[posmin]=Aux;
        }
    }

    void ordenarCod(class Mercaderias *M,long Cant) ///Ordena la Mercaderia Por Codigo (FOR DE ORDENAMIENTO)
    {
        int i, t, posmin;
        class Mercaderias Aux;
        for(i=0; i<Cant-1; i++)
        {
            posmin=i;
            for(t=i+1; t<Cant; t++)
            {
                if(M[posmin].getCod()>M[t].getCod())
                {
                    posmin=t;
                }
            }
            Aux=M[i];
            M[i]=M[posmin];
            M[posmin]=Aux;
        }

    }

     void MostrarXPre(class Mercaderias *M,long cant) ///Muestra Toda la Mercaderia Ordenada por Precio
    {

        int i,x=5,y=5;
        for(i=0; i<cant; i++)
        {
            if(M[i].getEstado()==1)
            {
                recuadro(x-1,y,45,6);
                gotoxy(x,y+1);
                cout << "Codigo: "<< M[i].getCod() <<endl;
                gotoxy(x,y+2);
                cout << "Nombre: "<< M[i].getNombre() <<endl;
                gotoxy(x,y+3);
                cout << "Precio: $" << M[i].getPrecio() << endl;
                gotoxy(x,y+4);
                cout << "Unidad: " << M[i].getUnidad() << endl;
                gotoxy(x,y+5);
                cout << "Stock: "<< M[i].getStock() <<endl;
            }
            x+=50;
            if(i%2==1 && i!=0){
                    y+=10;
                    x=5;
                    if(i%4==3 && i!=0){
                            gotoxy(15,1);
                            system("pause");
                    }
                }

        }

    }


    void MostrarUnidades(){
        recuadro(65,18,20,6);
        gotoxy(66,19);
        cout << "  Tipos de Unidad:" << endl;
        gotoxy(66,20);
        cout << "    U = Unidad" << endl;
        gotoxy(66,21);
        cout << "    K = Kilos" << endl;
        gotoxy(66,22);
        cout << "    G = Gramos" << endl;
        gotoxy(66,23);
        cout << "    L = Litros" << endl;

    }
#endif // PRODUCTOS_H_INCLUDED

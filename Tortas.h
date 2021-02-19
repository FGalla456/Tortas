#ifndef TORTAS_H_INCLUDED
#define TORTAS_H_INCLUDED

int BuscarTor(int );
float BuscarCodMer(int , int);
int VerificarCodTor(int );
void MostrarCodT(int ,int);
void PonerEnCeroT(int *);
int EliminarStock(int);
float RestarStock(float, int );
void CostoTotal(int );

class Tortas
{
protected:
    int CodTor;
    char Nombre[50];
    float Costo; ///Costo Total de la Produccion
    int Stock; /// Cantidad de Tortas Producidas
    bool Estado;
public:

///Inicio de los Getters///

    int getCodTor(){
    return CodTor;
    }

    float getCosto(){
    return Costo;
    }

    char *getNombreT(){
        return Nombre;
    }

    bool getEstado(){
        return Estado;
    }

    int getStock(){
        return Stock;
    }

///Fin de los Getters///

///Inicio de los Setters///

    void setStock(int Sto){
        Stock=Sto;
    }

    void setCosto(float Cos){
        Costo=Cos;
    }

    void setEstado(bool Est){
        Estado=Est;
    }

///Fin de los Setters///


///Inicio de las Funciones

    int grabarRegistroT(int pos){   ///Graba un Registro Modificado
    FILE *p;
    p=fopen ("Tortas.dat","rb+");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        return 0;
    }
    fseek(p,pos * sizeof *this,0);
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return 1;
    }

    int grabarDiscoT(){  ///Graba Un Registro Nuevo
    FILE *p;
    p=fopen ("Tortas.dat","rb+");
    if(p==NULL){
        cout << "El Archivo no Pudo ser Abierto" << endl;
        return 0;
    }
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return 1;
    }

    int leerRegistroT(int pos){ ///Lee el Archivo, Posiciona el puntero en el registro a modificar y Devuelve si se pudo leer o no
        int x=0;
        FILE *p ;
        p=fopen("Tortas.dat","rb");
        if(p==NULL){
            cout << "Error Al Abrir el Archivo" << endl;
            return -1;}
        fseek(p,pos*sizeof *this,0);
        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
    }

    void cargarTortas(int Ca){  /// Carga los Datos Que Posteriormente van a ser Guardados
        class Ingredientes_x_Torta IT;
        int VCT;
        char opc;
        MostrarCodT(3,4);
        recuadro(9,10,40,4);
        gotoxy(10,12);
        cout << "Codigo de la Torta: ";
        cin >> CodTor;
        VCT=VerificarCodTor(CodTor);
        while (CodTor<=0 || VCT==1){
            if(VCT!=1){
            gotoxy(10,12);
            cout << "Codigo Invalido. Presione Enter" << endl;
            system("pause");
            gotoxy(10,12);
            cout << "Codigo de la Torta:             ";
            gotoxy(29,12);
            cin >> CodTor;
            }
            else{
            gotoxy(10,12);
            cout << "Codigo ya Usado. Presione Enter" << endl;
            system("pause");
            gotoxy(10,12);
            cout << "Codigo de la Torta:             ";
            gotoxy(29,12);
            cin >> CodTor;
            }
        }
        recuadro(59,10,40,4);
        gotoxy(60,12);
        cout << "Nombre: ";
        cin.ignore(50,'\n');
        cin.getline (Nombre,50);
        opc='a';
        if(Ca==1){
            recuadro(45,16,55,4);
            gotoxy(46,17);
            cout << "A = Agregar Mas Ingredientes" << endl;
            gotoxy(46,18);
            cout << "E = Eliminar Ingredientes, y Volver a Ingresarlos" << endl;
            gotoxy(46,19);
            cout << "Cualquier Otro Sigue Sin Realizar Nada" << endl;

            recuadro(3,16,30,4);
            gotoxy(4,18);
            cout << char(168) <<"Que Decide Hacer?: ";
            cin >> opc;
        }
        system("cls");
        recuadro(9,3,40,4);
        gotoxy(10,5);
        cout << "Codigo de la Torta: " << CodTor;
        recuadro(59,3,40,4);
        gotoxy(60,5);
        cout << "Nombre: " << Nombre;
        switch(opc){
        case 'a':
        case 'A':
            IT.CargarIngredientes(CodTor);
            break;

        case 'E':
        case 'e':
            BajaIng(CodTor);
            IT.CargarIngredientes(CodTor);
            break;
        }
        Costo=CalcularCosto(CodTor);
        recuadro(27,43,50,4);
        gotoxy(28,45);
        cout << "El Costo de Produccion Aprox es: $" << Costo << endl;
        Estado=true;
        Stock=0;
        system("pause");
    }

    void MostrarTorta(){ ///Muestra el Registro en el que esta posicionado
        recuadro(32,4,40,4);
        gotoxy(33,6);
        cout << "Codigo de Torta: " << CodTor << endl;
        recuadro(32,10,40,4);
        gotoxy(33,12);
        cout << "Nombre: " << Nombre << endl;
        MostrarIngredientes(CodTor);
        recuadro(32,35,40,4);
        gotoxy(33,37);
        cout << "Costo: " << Costo << endl;
        recuadro(32,41,40,4);
        gotoxy(33,43);
        cout << "Stock: " << Stock << endl;

    }

    int ProducirTorta(){    ///Agrega Stock
            int VS,CodT,Pos;
            MostrarCodT(3,4);
            recuadro(32,10,40,4);
            gotoxy(33,12);
            cout << "Codigo de la Torta: ";
            cin >> CodT;
            Pos=BuscarTor(CodT);
            if(Pos==-1){
                recuadro(32,18,40,4);
                gotoxy(33,20);
                cout << "El Codigo de Torta no Existe" << endl;
                system("pause");
                return 0;
            }
            VS=EliminarStock(CodT);
            if(VS==-1)
            {
                recuadro(32,18,40,4);
                gotoxy(33,20);
                cout <<"Stock Insuficiente para Producir la Torta" << endl;
                system("pause");
                return 0;
            }
            leerRegistroT(Pos);
            Stock++;
            grabarRegistroT(Pos);
            return 0;
    }

};

void CrearTor(){  ///Crea y guarda un registro del Archivo Tortas
        FILE *p;
        class Tortas Tor;
        p=fopen("Tortas.dat","ab");
        Tor.cargarTortas(0);
        Tor.grabarDiscoT();
        fclose(p);
    }

void MostrarTortas(){ ///Muestra Todas las tortas Activas del archivo
    int Pos=0;
    class Tortas Tor;
    while (Tor.leerRegistroT(Pos)==1)
    {
        if(Tor.getEstado()==true)
        {
            Tor.MostrarTorta();
            gotoxy(32,47);
            cout << "Presione Enter para la Siguiente Torta" << endl;
            gotoxy(32,1);
            system("pause");
            system("cls");
        }
        Pos++;
    }

}

void MostrarCodT(int x,int y){ ///Muestra los Codigos ya Utilizados
    int C=0;
    FILE *p;
    class Tortas Tor;
    p=fopen("Tortas.dat","rb");
    recuadro(x-1,y-1,100,6);
    gotoxy(40,2);
    cout << " Codigo ya Utilizados: " << endl;
    while(fread(&Tor,sizeof(Tortas),1,p)==1)
    {
        gotoxy(x,y);
        cout << Tor.getCodTor() << " = " << Tor.getNombreT() << endl;

        y++;
        C++;
        if(C%4==0)
        {
            x+=25;
            for(int i=4; i<=8; i++)
            {
                gotoxy(x,i-8+y);
                cout << char (186) << endl;
            }
            x+=5;
            y=4;
        }
    }
}

int BuscarTor(int cod){ ///Busca una Torta en Especifica
        FILE *p;
        int pos=0;
        Tortas Tor;
        p=fopen("Tortas.dat","rb");
        while(fread(&Tor,sizeof(Tortas),1,p)==1){
            if(Tor.getCodTor()==cod){
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

int VerificarCodTor(int cod){ ///Verifica si Existe el Codigo de Torta Ingresado
        FILE *p;
        Tortas Tor;
        p=fopen("Tortas.dat","rb");
        while(fread(&Tor,sizeof(Tortas),1,p)==1){
            if(Tor.getCodTor()==cod){
                return 1;
            }
        }
        return -1;
    }

int ModificarTorta(){   ///Modifica Un Registro de Torta Existente
    int Cod,Pos;
    Tortas Tor;
    MostrarCodT(3,4);
    recuadro(9,10,40,4);
    gotoxy(10,12);
    cout << "Ingrese el Codigo: " ;
    cin >> Cod;
    Pos=BuscarTor(Cod);
        if(Pos==-1){
        gotoxy(10,12);
        cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
        system("pause");
        return 0;
    }
        Tor.leerRegistroT(Pos);
        if(Tor.getEstado()==true){
        Tor.cargarTortas(1);
        Tor.grabarRegistroT(Pos);
        recuadro(44,38,30,3);
        gotoxy(45,40);
        cout << "El Registro fue Modificado" << endl;
        system("pause");
        return 1;
    }
    return 1;
    }

int AltaTor(){  ///Da de Alta un Registro que Anteriormente fue Dado de Baja
    int Cod,Pos;
    Tortas Tor;
    MostrarCodT(3,4);
    recuadro(9,10,40,4);
    gotoxy(10,12);
    cout << "Ingrese el Codigo: " ;
    cin >> Cod;
    Pos=BuscarTor(Cod);
        if(Pos==-1){
        gotoxy(10,12);
        cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
        system("pause");
        return 0;
    }
        Tor.leerRegistroT(Pos);
        if(Tor.getEstado()==false){
        Tor.setEstado(true);
        Tor.grabarRegistroT(Pos);
        recuadro(44,23,30,3);
        gotoxy(45,25);
        cout << "El Registro fue Dado de Alta" << endl;
        system("pause");
    }
    return 0;
}

int BajaTor(){ ///Da de Baja un Registro
    int Cod,Pos;
    Tortas Tor;
    MostrarCodT(3,4);
    recuadro(9,10,40,4);
    gotoxy(10,12);
    cout << "Ingrese el Codigo: " ;
    cin >> Cod;
    Pos=BuscarTor(Cod);
        if(Pos==-1){
        gotoxy(10,12);
        cout << "Codigo Inexistente. Volvera al Men""\243" << endl;
        system("pause");
        return 0;
    }
        Tor.leerRegistroT(Pos);
        if(Tor.getEstado()==true){
        Tor.setEstado(false);
        Tor.grabarRegistroT(Pos);
        recuadro(44,23,30,3);
        gotoxy(45,25);
        cout << "El Registro fue Dado de Baja" << endl;
        system("pause");
    }
    return 0;
}

int EliminarStock(int CodT){ ///Elimina lo Utilizado al Producir una Torta
        class Ingredientes_x_Torta IT;
        int Pos,Cod,V;
        FILE *p;
        float Cant;
        p=fopen("Ingredientes.dat","rb");
        while(fread(&IT,sizeof(Ingredientes_x_Torta),1,p)==1)
        {
           if(CodT==IT.getCodTor()){
                Cod=IT.getCodMer();
                Pos=BuscarCodMer(Cod,1);
                Cant=IT.getCantidad();
                V=RestarStock(Cant,Pos);
                if(V==-2)
                {
                    fclose(p);
                    return -1;
                }
            fclose(p);
            }
        }
    return 1;
    }

float RestarStock(float cant, int pos){ ///Calculos para Restar el Stock, Fija = Stock,Precio Unitario y Precio Total
        Mercaderias Mer;
        FILE *p;
        float Tot, Pre, PU;
        p=fopen("Mercaderia.dat","rb+");
        if(p==NULL){
            cout << "Error Al Abrir el Archivo" << endl;
            return -2;
        }
        fseek(p,pos*sizeof(Mercaderias),0);
        fread(&Mer,sizeof(Mercaderias),1,p);
        Tot=Mer.getStock();
            if(cant<=Tot){
                Pre=Mer.getPrecio();
                Pre=Pre-((Pre/Tot)*cant);
                Tot=Tot-cant;
                PU=Pre/Tot;
                if(Tot==cant){
                    PU=0;
                }
                Mer.setStock(Tot);
                Mer.setPrecio(Pre);
                Mer.setPrecioU(PU);
                Mer.grabarRegistroMer(pos);
                fclose(p);
                return 1;
            }
            else{
            cout << "Stock Insuficiente" << endl;
            fclose(p);
            return -2;}
    }

void ModificarIT(int CodM,float PU){
    int Pos=0;
    FILE *p;
    class Ingredientes_x_Torta IT;
    p=fopen("Ingredientes.dat","rb");
    while(fread(&IT,sizeof(Ingredientes_x_Torta),1,p)==1){
        if(IT.getCodMer()==CodM){
            IT.leerRegistroIT(Pos);
            IT.setCosto(IT.getCantidad()*PU);
            IT.GrabarRegistroIT(Pos);
            CostoTotal(IT.getCodTor());
        }
        Pos++;
    }
    fclose(p);
}

void CostoTotal(int CodT){
        int Pos;
        FILE *p;
        float Cost=0;
        class Ingredientes_x_Torta IT;
        class Tortas Tor;
        p=fopen("Ingredientes.dat","rb");
        while(fread(&IT,sizeof(Ingredientes_x_Torta),1,p)==1){
            if(IT.getCodTor()==CodT){
                Cost+=IT.getCosto();
            }
        }
        fclose(p);
        Pos=BuscarTor(CodT);
        if (Pos==-1){
            cout << "Felicidades Logro Bugear el Programa" << endl;
            system("pause");
        }
        Tor.leerRegistroT(Pos);
        Tor.setCosto(Cost);
        Tor.grabarRegistroT(Pos);
    }


#endif // TORTAS_H_INCLUDED

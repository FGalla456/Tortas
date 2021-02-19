#ifndef INGREDIENTES_X_TORTA_H_INCLUDED
#define INGREDIENTES_X_TORTA_H_INCLUDED

float BuscarCodMer(int, int );
void MostrarIngredientes(int);


class Ingredientes_x_Torta{
    protected:
        int CodTor;
        int CodMer;
        float Cantidad;
        float Costo;
        bool Estado;
    public:

///Inicio de los Getters///

    int getCodTor(){
            return CodTor;
        }

    int getCodMer(){
            return CodMer;
        }

    float getCantidad(){
            return Cantidad;
        }

    float getCosto(){
            return Costo;
        }

    bool getEstado(){
        return Estado;
    }

///Fin de los Getters///

///Inicio de los Setters///

    void setCosto(float Cos){
        Costo=Cos;
    }

    void setEstado(bool Est){
        Estado=Est;
    }

///Fin de los Setters///

///Inicio de las Funciones

    int leerRegistroIT(int pos){
        int x=0;
        FILE *p ;
        p=fopen("Ingredientes.dat","rb");
        if(p==NULL){
            cout << "Error Al Abrir el Archivo" << endl;
            return -1;}
        fseek(p,pos*sizeof *this,0);
        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
        }

    int GrabarRegistroIT(int pos){
            FILE *p;
            p=fopen ("Ingredientes.dat","rb+");
            if(p==NULL){
                cout << "El Archivo no Pudo ser Abierto" << endl;
                return 0;
            }
            fseek(p,pos * sizeof *this,0);
            fwrite(this, sizeof *this,1,p);
            fclose(p);
            return 1;
        }

    float CargarIngredientes(int CodT){
            FILE *p;
            char SC='s';
            int X;
            float Cost=0;
            p=fopen("Ingredientes.dat","ab");
            MostrarCod(3,10);
            while (SC=='s' || SC== 'S'){
                CodTor=CodT;
                recuadro(32,18,40,4);
                gotoxy(33,20);
                cout << "Codigo de Mercaderia: ";
                cin >> CodMer;
                X=BuscarCodMer(CodMer,1);
                while(X==-1){
                    gotoxy(33,20);
                    cout << "Codigo Inexistente. Presione Enter.";
                    gotoxy(32,1);
                    system("Pause");
                    gotoxy(32,1);
                    cout << "                                   ";
                    gotoxy(33,20);
                    cout << "Codigo de Mercaderia:              ";
                    gotoxy(55,20);
                    cin >> CodMer;
                    X=BuscarCodMer(CodMer,1);
                }
                recuadro(32,24,40,4);
                gotoxy(33,26);
                cout << "Cantidad a Utilizar: ";
                cin >> Cantidad;
                while (Cantidad <= 0){
                    gotoxy(33,26);
                    cout << "Cantidad Negativa. Presione Enter.";
                    gotoxy(32,1);
                    system("Pause");
                    gotoxy(32,1);
                    cout << "                                   ";
                    gotoxy(33,26);
                    cout << "Cantidad a Utilizar:               ";
                    gotoxy(54,26);
                    cin >> Cantidad;
                }
                Costo=BuscarCodMer(CodMer,2)*Cantidad;
                Estado=true;
                fwrite(this,sizeof(Ingredientes_x_Torta),1,p);
                recuadro(32,28,50,4);
                gotoxy(33,32);
                cout << char(168) << "Cargar Otro Ingrediente? S/N: ";
                cin >> SC;
                while (SC!='s'|| SC!='S' || SC!='n' || SC!='N'){
                    gotoxy(33,32);
                    cout << "Cargar Otro Ingrediente? S/N: ";
                    cin >> SC;
                }
            }
            fclose(p);
            return Cost;
    }

    void MostrarIngrediente(int y){
            char U;
            U=BuscarCodMer(CodMer,3); ///Muestra la unidad
            gotoxy(12,16);
            cout << "Codigo de Mercaderia: " << endl;
            gotoxy(17,y);
            cout<< CodMer << endl;
            gotoxy(42,16);
            cout << "Cantidad Utilizada: " << endl;
            gotoxy(47,y);
            cout << Cantidad << " " << U <<endl;
            gotoxy(75,16);
            cout << "Costo:" << endl;
            gotoxy(76,y);
            cout << "$" << Costo << endl;

        }

};

float BuscarCodMer(int Cod, int C){  /// Busca el codigo Ingresado y Devuelve la posicion, Tambien funciona para saber si el codigo existe
        FILE *p;
        Mercaderias Mer;
        int pos=0;
        float Cost=0;
        char U;
        p=fopen("Mercaderia.dat","rb");
        if(p==NULL){
            cout << "El Archivo no pudo ser Abierto" << endl;
            return -1;
        }
        while(fread(&Mer,sizeof(Mercaderias),1,p)==1)
        {
            if(Cod==Mer.getCod())
            {
               if(C==1){ ///Si es 1 devuelve la Posicion
                    fclose(p);
                    return pos;
               }
                if(C==2){ ///Si es 2 Devuelve el Precio
                Cost=Mer.getPUnitario();
                fclose(p);
                return Cost;
                }
                if(C==3){ ///Si es 3 Devuelve la Unidad
                    U=Mer.getUnidad();
                    return U;
                }
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

void MostrarIngredientes(int CodT){
    int Pos=0,y=17;
    class Ingredientes_x_Torta IT;
    while (IT.leerRegistroIT(Pos)==1)
        {
            if(CodT==IT.getCodTor()){
                 if(IT.getEstado()==true){
                    IT.MostrarIngrediente(y);
                    y++;
                    }
            }
            Pos++;
        }
    }

float CalcularCosto(int CodT){
    float Cost=0,Pos=0;
    class Ingredientes_x_Torta IT;
    while (IT.leerRegistroIT(Pos)==1)
            {
                if(CodT==IT.getCodTor()){
                    if(IT.getEstado()==true){
                        Cost+=IT.getCosto();
                    }
                    }
                Pos++;
            }
    return Cost;
}

void BajaIng(int CodT){
    int Pos=0;
    class Ingredientes_x_Torta IT;
    while (IT.leerRegistroIT(Pos)==1)
            {
                if(CodT==IT.getCodTor()){
                    IT.setEstado(false);
                    }
                Pos++;
            }
}


#endif // INGREDIENTES_X_TORTA_H_INCLUDED

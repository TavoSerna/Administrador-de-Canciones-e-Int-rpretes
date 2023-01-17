#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

bool validarNacionalidad(int n);


class Genero{
    private:
        int ID;
        char nombre[40];
        int pais;
        int instrumentacion;
        bool estado;
    public:
        Genero(int i=0, const char *n="vacio", int p=0, int inst=0){
            ID=i;
            strcpy(nombre, n);
            pais=p;
            instrumentacion=inst;
        }


        int getID(){return ID;}
        const char *getNombre(){return nombre;}
        int getPais(){return pais;}
        int getInstrumentacion(){return instrumentacion;}
        bool getEstado(){return estado;}


        void setID(int i){ID=i;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setPais(int p){if(p>=1&&p<=100)pais=p;}
        void setInstrumentacion(int inst){if(inst<=1&&inst>=5);instrumentacion=inst;}
        void setEstado(bool e){estado=e;}

        int Cargar(int i=0);
        void Mostrar();
        int grabarEnDisco();
        int modificarEnDisco(int pos);
        int leerDeDisco(int pos);
};

int Genero::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen(ARCHIVO_GENEROS, "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Genero) ,1, p);
    fclose(p);
    return escribio;
}


int Genero::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen(ARCHIVO_GENEROS, "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Genero)*pos, 0);
    modifico=fwrite(this, sizeof(Genero) ,1, p);
    fclose(p);
    return modifico;
}

int Genero::leerDeDisco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen(ARCHIVO_GENEROS, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Genero)*pos, 0);
    leyo=fread(this, sizeof(Genero) ,1, p);
    fclose(p);
    return leyo;


}

void Genero::Mostrar(){
    if(estado==true){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"GENERO: ";
        cout<<nombre<<endl;
        cout<<"PAIS DE ORIGEN: ";
        cout<<pais<<endl;
        cout<<"TIPO DE INSTRUMENTACION: ";
        cout<<instrumentacion<<endl;
        cout<<"----------------------"<<endl;
    }
}

int Genero::Cargar(int i){
        int nac,tipo,f=0;
        ID=i;
        cout<<"INGRESE EL NOMBRE DEL NUEVO GENERO: ";
        cargarCadena(nombre,39);
        cout<<"INGRESE EL PAIS DE ORIGEN: ";
        cin>>nac;
         if(validarNacionalidad(nac)==true){
              pais=nac;
                } else {
        cout<<"LA NACIONALIDAD INGRESADA NO ESTA REGISTRADA";
             return 0;
        }
        cout<<"TIPO DE INSTRUMENTACION: ";
        cin>>tipo;
        if (tipo>=1&&tipo<=5){
               setInstrumentacion(tipo);
              }
            else {
                while(f==0){
                   cout<<"INGRESE DE NUEVO, LOS TIPOS VAN DEL 1 AL 5: ";
                   cin>>tipo;
                      if (tipo>=1&&tipo<=5){}
                      setInstrumentacion(tipo);
                      f=1;
                      }
                    }
        estado=true;
        return 1;
    }
#endif // CLASE_GENERO_H_INCLUDED

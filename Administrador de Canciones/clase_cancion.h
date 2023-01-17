#ifndef CLASE_CANCION_H_INCLUDED
#define CLASE_CANCION_H_INCLUDED

int validarInterprete(int c);
int validarDuracion(int d);


class Cancion{
    private:
        int ID;
        char nombre[30];
        char autor[30];
        int idInterprete;
        Fecha fechaEstreno;
        int genero;
        float duracion;
        bool estado;
    public:
        Cancion(int i=0,const char *n="vacio", const char *a="vacio", int g=0,float d=0){
            ID=i;
            strcpy(nombre, n);
            strcpy(autor, a);
            genero=g;
            duracion=d;
        }

        ///Sets
        void setID(int i){ID=i;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setAutor(const char *a){strcpy(autor, a);}
        void setGenero(int g){genero=g;}
        void setDuracion(float d){duracion=d;}
        void setEstado(bool e){estado=e;}
        void setFechaEstreno(Fecha f){fechaEstreno=f;}
        void setIdInterprete(int inte){idInterprete=inte;}

        ///Gets
        int getID(){return ID;}
        const char *getNombre(){return nombre;}
        const char *getAutor(){return autor;}
        int getGenero(){return genero;}
        float getDuracion(){return duracion;}
        bool getEstado(){return estado;}
        Fecha getFechaEstreno(){return fechaEstreno;}
        int getIdInterprete(){return idInterprete;}

        int Cargar(int i=0);
        void Mostrar();
        int grabar_en_disco();
        int modificar_en_disco(int pos);
        int leer_de_disco(int pos);

};

int Cancion::grabar_en_disco(){
    FILE *p;
    int escribio;
    p=fopen(ARCHIVO_CANCIONES, "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Cancion),1, p);
    fclose(p);
    return escribio;
}


int Cancion::modificar_en_disco(int pos){
    FILE *p;
    int modifico;
    p=fopen(ARCHIVO_CANCIONES, "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Cancion)*pos, 0);
    modifico=fwrite(this, sizeof(Cancion) ,1, p);
    fclose(p);
    return modifico;
}

int Cancion::leer_de_disco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen(ARCHIVO_CANCIONES, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Cancion)*pos, 0);
    leyo=fread(this, sizeof(Cancion) ,1, p);
    fclose(p);
    return leyo;
}

int Cancion::Cargar(int i){
     int inter,dura;
    setID(i);
    cout<<"INGRESE EL NOMBRE DE LA CANCION: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE EL AUTOR: ";
    cargarCadena(autor, 29);
    cout<<"INGRESE ID INTERPRETE: ";
    cin>>inter;
    if (validarInterprete(inter)==1){
        idInterprete=inter;
       } else {
          return 0;
       }
    cout<<"INGRESE FECHA DE ESTRENO: ";
    fechaEstreno.Cargar();
    cout<<"INGRESE DURACION: ";
    cin>>dura;
    if (validarDuracion(dura)==1){
        duracion=dura;
           } else {
          return 0;
       }
    cout<<"INGRESE GENERO MUSICAL: ";
    cin>>genero;

    cout<<"----------------------"<<endl;
    estado=true;
    return 1;
}

void Cancion::Mostrar(){
    if(estado==true){
    cout<<"ID: ";
    cout<<ID<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"AUTOR: ";
    cout<<autor<<endl;
    cout<<"ID INTERPRETE: ";
    cout<<idInterprete<<endl;
    cout<<"FECHA DE ESTRENO: ";
    fechaEstreno.Mostrar();
    cout<<"DURACION: ";
    cout<<duracion<<endl;
    cout<<"GENERO: ";
    cout<<genero<<endl;
    cout<<"----------------------"<<endl;
}
}


#endif // CLASE_CANCION_H_INCLUDED

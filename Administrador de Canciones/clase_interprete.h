#ifndef CLASE_INTERPRETE_H_INCLUDED
#define CLASE_INTERPRETE_H_INCLUDED

bool validarNacionalidad(int c);
int validarTipoInterprete(int t);
int validarGenero(int g);


class Interprete{
private:
    int ID;
    Fecha fechaInicioActividad;
    char nombre[20];
    int nacionalidad;
    int tipoInterprete;
    int genero;
    bool estado;
public:
    Interprete(int i=0, const char *n="vacio",int nac=0,int t=0,int g=0){
        ID=i;
        strcpy(nombre, n);
        nacionalidad=nac;
        tipoInterprete=t;
        genero=g;
    }
    ///Gets
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getNacionalidad(){return nacionalidad;}
    int getTipoInterprete(){return tipoInterprete;}
    int getGenero(){return genero;}
    bool getEstado(){return estado;}
    Fecha getFechaInicioActividad(){return fechaInicioActividad;}

    ///Sets
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setNacionalidad(int nac){nacionalidad=nac;}
    void setTipoInterprete(int t){tipoInterprete=t;}
    void setGenero(int g){genero=g;}
    void setEstado(bool e){estado=e;}
    void setFechaInicoActividad(Fecha f){fechaInicioActividad=f;}

    int Cargar(int);
    void Mostrar();
    int grabar_en_disco();
    int modificar_en_disco(int pos);
    int leer_de_disco(int pos);
};

int Interprete::grabar_en_disco(){
    FILE *p;
    int escribio;
    p=fopen(ARCHIVO_INTERPRETES,"ab");
    if(p==NULL)return -1;
    escribio=fwrite(this,sizeof(Interprete),1,p);
    fclose(p);
    return escribio;
}


int Interprete::modificar_en_disco(int pos){
    FILE *p;
    int modifico;
    p=fopen(ARCHIVO_INTERPRETES,"rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Interprete)*pos,0);
    modifico=fwrite(this,sizeof(Interprete),1,p);
    fclose(p);
    return modifico;
}

int Interprete::leer_de_disco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen(ARCHIVO_INTERPRETES, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Interprete)*pos, 0);
    leyo=fread(this, sizeof(Interprete),1,p);
    fclose(p);
    return leyo;


}

void Interprete::Mostrar(){
    if(estado==true){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"NACIONALIDAD: ";
        cout<<nacionalidad<<endl;
        cout<<"TIPO DE INTERPRETE: ";
        cout<<tipoInterprete<<endl;
        cout<<"GENERO MUSICAL: ";
        cout<<genero<<endl;
        cout<<"FECHA DE INICIO DE ACTIVIDAD: ";
        fechaInicioActividad.Mostrar();
        cout<<"----------------------"<<endl;
    }
}

int Interprete::Cargar(int i){
    int nac,t,g;
    setID(i);
    cout<<"NOMBRE: ";
    cargarCadena(nombre,19);
    cout<<"NACIONALIDAD: ";
    cin>>nac;
    if(validarNacionalidad(nac)==true){
        nacionalidad=nac;
    } else {
        cout<<"LA NACIONALIDAD INGRESADA NO ESTA REGISTRADA";
        return 0;
    }
    cout<<"TIPO DE INTERPRETE: ";
    cin>>t;
    if(validarTipoInterprete(t)==1){
        tipoInterprete=t;
    } else {
        return 0;
    }
    cout<<"GENERO MUSICAL: ";
    cin>>g;
    if(validarGenero(g)==1){
            genero=g;
          } else {
                 return 0;
                 }
    cout<<"FECHA DE INICIO DE ACTIVIDAD: ";
    fechaInicioActividad.Cargar();
    cout<<"----------------------"<<endl;
    estado=true;
    return 1;
}



#endif // CLASE_INTERPRETE_H_INCLUDED

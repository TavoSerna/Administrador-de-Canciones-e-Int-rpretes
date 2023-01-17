#ifndef CLASE_TIPOINTERPRETE_H_INCLUDED
#define CLASE_TIPOINTERPRETE_H_INCLUDED

class TipoInterprete{
private:
    int ID;
    char nombre[40];
    bool estado;
public:
    TipoInterprete(int i=0, const char *n="vacio"){
        ID=i;
        strcpy(nombre, n);
    }
    ///Gets
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    ///Sets
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setEstado(bool e){estado=e;}

    void Cargar(int);
    void Mostrar();
    int grabar_en_disco();
    int modificar_en_disco(int pos);
    int leer_de_disco(int pos);
};

int TipoInterprete::grabar_en_disco(){
    FILE *p;
    int escribio;
    p=fopen(ARCHIVO_TIPO_INTERPRETES,"ab");
    if(p==NULL)return -1;
    escribio=fwrite(this,sizeof(TipoInterprete),1,p);
    fclose(p);
    return escribio;
}


int TipoInterprete::modificar_en_disco(int pos){
    FILE *p;
    int modifico;
    p=fopen(ARCHIVO_TIPO_INTERPRETES,"rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(TipoInterprete)*pos,0);
    modifico=fwrite(this,sizeof(TipoInterprete),1,p);
    fclose(p);
    return modifico;
}

int TipoInterprete::leer_de_disco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen(ARCHIVO_TIPO_INTERPRETES, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(TipoInterprete)*pos, 0);
    leyo=fread(this, sizeof(TipoInterprete),1,p);
    fclose(p);
    return leyo;


}

void TipoInterprete::Mostrar(){
    if(estado==true){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"----------------------"<<endl;
    }
}


void TipoInterprete::Cargar(int i){
    setID(i);
    cout<<"INGRESE EL NOMBRE DEL TIPO DE INTERPRETE: ";
    cargarCadena(nombre,39);
    estado=true;
}


#endif // CLASE_TIPOINTERPRETE_H_INCLUDED

#ifndef CLASE_PAIS_H_INCLUDED
#define CLASE_PAIS_H_INCLUDED

class Pais{
private:
    int ID;
    char nombre[30];
    char continente[30];
    bool estado;
public:
    Pais(int i=0, const char *n="vacio",const char *c="vacio"){
        ID=i;
        strcpy(nombre, n);
        strcpy(continente,c);
    }
    ///Gets
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    const char *getContinente(){return continente;}
    bool getEstado(){return estado;}

    ///Sets
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setContinente(const char *c){strcpy(continente,c);}
    void setEstado(bool e){estado=e;}

    void Cargar(int);
    void Mostrar();
    int grabar_en_disco();
    int modificar_en_disco(int pos);
    int leer_de_disco(int pos);
};

int Pais::grabar_en_disco(){
    FILE *p;
    int escribio;
    p=fopen(ARCHIVO_PAISES,"ab");
    if(p==NULL)return -1;
    escribio=fwrite(this,sizeof(Pais),1,p);
    fclose(p);
    return escribio;
}


int Pais::modificar_en_disco(int pos){
    FILE *p;
    int modifico;
    p=fopen(ARCHIVO_PAISES,"rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Pais)*pos,0);
    modifico=fwrite(this,sizeof(Pais),1,p);
    fclose(p);
    return modifico;
}

int Pais::leer_de_disco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen(ARCHIVO_PAISES, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Pais)*pos, 0);
    leyo=fread(this, sizeof(Pais),1,p);
    fclose(p);
    return leyo;


}

void Pais::Mostrar(){
    if(estado==true){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"CONTINENTE: ";
        cout<<continente<<endl;
        cout<<"----------------------"<<endl;
    }
}


void Pais::Cargar(int i){
    setID(i);
    cout<<"INGRESE EL NOMBRE DEL PAIS: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE EL NOMBRE DEL CONTINENTE AL QUE PERTENECE: ";
    cargarCadena(continente, 29);
    estado=true;
    cout<<"----------------------"<<endl;
}


#endif // CLASE_PAIS_H_INCLUDED

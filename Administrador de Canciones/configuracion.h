#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

///PROTOTIPOS
bool backup_interpretes();
bool backup_canciones();
bool backup_generos();
bool restaurar_interpretes();
bool restaurar_canciones();
bool restaurar_genero();
int menuDatosInicio();

bool backup_interpretes(){
    FILE *r;
    r=fopen(BACK_UP_INTERPRETES, "wb");
    if(r==NULL) return false;
    Interprete reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
        fwrite(&reg, sizeof reg, 1, r);
        pos++;
    }
    fclose(r);
    if(pos==0)return false;
    return true;
}

bool backup_canciones(){
    FILE *r;
    r=fopen(BACK_UP_CANCIONES, "wb");
    if(r==NULL) return false;
    Cancion reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
        fwrite(&reg, sizeof reg, 1, r);
        pos++;
    }
    fclose(r);
    if(pos==0)return false;
    return true;
}
bool backup_generos(){
    FILE *r;
    r=fopen(BACK_UP_GENEROS, "wb");
    if(r==NULL) return false;
    Genero reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        fwrite(&reg, sizeof reg, 1, r);
        pos++;
    }
    fclose(r);
    if(pos==0)return false;
    return true;
}


bool backupPaises(){
    FILE *r;
    r=fopen(BACK_UP_PAISES, "wb");
    if(r==NULL) return false;
    Pais reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
        fwrite(&reg, sizeof reg, 1, r);
        pos++;
    }
    fclose(r);
    if(pos==0)return false;
    return true;
}



bool backupTipoInterprete(){
    FILE *r;
    r=fopen(BACK_UP_TIPO_INTERPRETES, "wb");
    if(r==NULL) return false;
    TipoInterprete reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
        fwrite(&reg, sizeof reg, 1, r);
        pos++;
    }
    fclose(r);
    if(pos==0)return false;
    return true;
}



bool restaurar_interpretes(){
    FILE *r, *p;
    r=fopen(BACK_UP_INTERPRETES, "rb");
    if(r==NULL) return false;
    p=fopen(ARCHIVO_INTERPRETES, "wb");
    if(p==NULL) return false;
    fclose(p);
    Interprete reg;
    bool leyo;
    while(fread(&reg,sizeof reg,1,r)==1){
        reg.grabar_en_disco();
        leyo=1;
    }
    fclose(r);
    if(leyo==0)return false;
    return true;
}

bool restaurar_canciones(){
    FILE *r, *p;
    r=fopen(BACK_UP_CANCIONES, "rb");
    if(r==NULL) return false;
    p=fopen(ARCHIVO_CANCIONES, "wb");
    if(p==NULL) return false;
    fclose(p);
    Cancion reg;
    bool leyo;
    while(fread(&reg,sizeof reg,1,r)==1){
        reg.grabar_en_disco();
        leyo=1;
    }
    fclose(r);
    if(leyo==0)return false;
    return true;
}

bool restaurar_generos(){
    FILE *r, *p;
    r=fopen(BACK_UP_GENEROS, "rb");
    if(r==NULL) return false;
    p=fopen(ARCHIVO_GENEROS, "wb");
    if(p==NULL) return false;
    fclose(p);
    Genero reg;
    bool leyo;
    while(fread(&reg,sizeof reg,1,r)==1){
        reg.grabarEnDisco();
        leyo=1;
    }
    fclose(r);
    if(leyo==0)return false;
    return true;
}

bool restaurarPaises(){
    FILE *r, *p;
    r=fopen(BACK_UP_PAISES, "rb");
    if(r==NULL) return false;
    p=fopen(ARCHIVO_PAISES, "wb");
    if(p==NULL) return false;
    fclose(p);
    Pais reg;
    bool leyo;
    while(fread(&reg,sizeof reg,1,r)==1){
        reg.grabar_en_disco();
        leyo=1;
    }
    fclose(r);
    if(leyo==0)return false;
    return true;
}

bool restaurarTipoInterprete(){
    FILE *r, *p;
    r=fopen(BACK_UP_TIPO_INTERPRETES, "rb");
    if(r==NULL) return false;
    p=fopen(ARCHIVO_TIPO_INTERPRETES, "wb");
    if(p==NULL) return false;
    fclose(p);
    TipoInterprete reg;
    bool leyo;
    while(fread(&reg,sizeof reg,1,r)==1){
        reg.grabar_en_disco();
        leyo=1;
    }
    fclose(r);
    if(leyo==0)return false;
    return true;
}

int menuDatosInicio(){
   int opc;
    while(true){
        system("cls");
        cout<<"DATOS DE INICIO"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR PAIS"<<endl;
        cout<<"2) AGREGAR TIPO DE INTERPRETE "<<endl;
        cout<<"3) AGREGAR GENERO"<<endl;
        cout<<"4) AGREGAR INTERPRETE"<<endl;
        cout<<"5) AGREGAR CANCION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU CONFIGURACION"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:if(agregarPais()){
                 cout<<"PAIS AGREGADO";
             }
              break;
           case 2:if(agregarTipoInterprete()){
                 cout<<"TIPO DE INTERPRETE AGREGADO";
             }
              break;
               case 3:if(agregar_genero()){
                 cout<<"GENERO AGREGADO";
             }
              break;
               case 4:if(agregar_interprete()){
                 cout<<"INTERPRETE AGREGADO";
             }else {
               cout<<endl<<endl;
               return 0;
             }
              break;
               case 5:if(agregar_cancion()){
                 cout<<"CANCION AGREGADA";
             }else {
               cout<<endl<<endl;
               return 0;
             }
              break;
        case 0:
            return 0;
        default:
                cout<<"LA OPCION INGRESADA NO ES VALIDA. INGRESE OTRA OPCION."<<endl;
        }
        cout<<endl;
        system("pause");
}

}


#endif // CONFIGURACION_H_INCLUDED

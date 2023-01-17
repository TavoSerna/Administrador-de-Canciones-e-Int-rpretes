#ifndef FUNCIONES_GENERO_H_INCLUDED
#define FUNCIONES_GENERO_H_INCLUDED

int agregar_genero();
int listar_generos();
int buscar_genero_ID(int ID);
int modificar_instrumentacion();
int listar_genero_ID();


int agregar_genero(){
    Genero obj;
    int pos=0,aux,valor;
    while(obj.leerDeDisco(pos)==1){
            pos++;
        }
    aux=obj.Cargar(pos+1);
    if(aux==0){
        return 0;
    } else {
    valor=obj.grabarEnDisco();
        return valor;
    }
}

int listar_genero_ID(){
    int pos,ID;
    Genero obj;
    cout<<"INGRESE EL ID DEL GENERO: ";
    cin>>ID;
    pos=buscar_genero_ID(ID);
    if(pos==-1) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int listar_generos(){
    Genero reg;
    int leyo=0, pos=0;

    while(reg.leerDeDisco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}

int modificar_instrumentacion(){
    Genero obj;
    int pos=0, ID,escribio, nueva_instrumentacion;
    cout<<"INGRESE EL ID DEL GENERO A MODIFICAR: ";
    cin>>ID;
    pos=buscar_genero_ID(ID);
    if(pos>=0){
        obj.leerDeDisco(pos);
        cout<<"INGRESE NUEVA INSTRUMENTACION: ";
        cin>>nueva_instrumentacion;
        obj.setInstrumentacion(nueva_instrumentacion);
        escribio=obj.modificarEnDisco(pos);
    }
    else{
        cout<<"NO EXISTE EL GENERO"<<endl;
        return -2;
    }
    return escribio;
}


int buscar_genero_ID(int ID){
    Genero reg;
    int pos=0;
     while(reg.leerDeDisco(pos)==1){
            if(reg.getID()==ID){
                if(reg.getEstado()==true){
                   return 1;
                } else {
                   return -2;
                }

            }
            pos++;
    }
    return -1;
}





#endif // FUNCIONES_GENERO_H_INCLUDED

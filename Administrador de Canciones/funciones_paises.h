#ifndef FUNCIONES_PAISES_H_INCLUDED
#define FUNCIONES_PAISES_H_INCLUDED

int agregarPais(){
    Pais obj;
    int pos=0,valor;
    while(obj.leer_de_disco(pos)==1){
            pos++;
        }
    obj.Cargar(pos+1);
    valor=obj.grabar_en_disco();
        return valor;
    }

int buscarPaisID(int ID, bool borrado){
    Pais reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
            if(reg.getID()==ID){
                if(reg.getEstado()==true){
                    return pos;
                }
                else{
                    if(borrado==false){
                        return -1;
                    }
                    else{
                        return -2;
                    }
                }
            }
            pos++;
    }
    return -1;
}


int listarPaisesID(){
    int pos,ID;
    Pais obj;
    cout<<"INGRESE ID DEL PAIS: ";
    cin>>ID;
    pos=buscarPaisID(ID,true);
    if(pos==-1) return -1;
    obj.leer_de_disco(pos);
    obj.Mostrar();
    return 1;
}

int listarPaises(){
    Pais reg;
    int leyo=0, pos=0;
    while(reg.leer_de_disco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}




#endif // FUNCIONES_PAISES_H_INCLUDED

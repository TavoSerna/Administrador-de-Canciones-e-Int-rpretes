#ifndef FUNCIONES_CANCION_H_INCLUDED
#define FUNCIONES_CANCION_H_INCLUDED

int agregar_cancion();
int listar_canciones();
int listar_canciones_ID();
int buscar_cancion_ID(int ID);
int cambiar_fecha_estreno();
int eliminar_cancion();
int buscar_ID_interprete(int i);
int buscarIDyEstado(int c);

int agregar_cancion(){
    Cancion obj;
    int pos=0,valor,aux;
    while(obj.leer_de_disco(pos)==1){
            pos++;
        }
    aux=obj.Cargar(pos+1);
    if(aux==0){
        return 0;
    }
    valor=obj.grabar_en_disco();
        return valor;
    }

int listar_canciones_ID(){
    int pos,ID;
    Cancion obj;
    cout<<"INGRESE ID DE LA CANCION: ";
    cin>>ID;
    pos=buscar_cancion_ID(ID);
    if(pos==-1){
        return -1;
       }
    if(pos==-2){
         return -2;
        }
    obj.leer_de_disco(pos);
    obj.Mostrar();
    return 1;
}

int listar_canciones(){
    Cancion reg;
    int leyo=0, pos=0;

    while(reg.leer_de_disco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}

int cambiar_fecha_estreno(){
    Cancion obj;
    Fecha reg;
    int pos=0, escribio,ID;
    cout<<"INGRESE EL ID DE LA CANCION A MODIFICAR: ";
    cin>>ID;
    pos=buscar_cancion_ID(ID);
    if(pos==-1){
        return -1;
      }
    if(pos==-2){
        return -2;
      }
    obj.leer_de_disco(pos);
    cout<<"INGRESE NUEVA FECHA: ";
    reg.Cargar();
    obj.setFechaEstreno(reg);
    escribio=obj.modificar_en_disco(pos);
    return escribio;
}

int eliminar_cancion(){
    int pos,ID;
    Cancion obj;
    cout<<"INGRESE EL ID DE LA CANCION: ";
    cin>>ID;
    pos=buscar_cancion_ID(ID);
    if(pos==-1){
        return -1;
      }
    if(pos==-2){
      return -2;
      }
    obj.leer_de_disco(pos);
    obj.setEstado(false);
    obj.modificar_en_disco(pos);
    return 1;
}


int buscar_cancion_ID(int ID){
    Cancion reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
            if(reg.getID()==ID){
                if(reg.getEstado()==true){
                    return pos;
                }
                else{
                        return -2;
                    }
                }
            pos++;
    }
    return -1;
}

int validarInterprete(int c){
    int aux;
    aux=buscarIDyEstado(c);
    if (aux==-1) {
       cout<<"INTERPRETE NO REGISTRADO";
       return 0;
        }
    if (aux==-2){
          cout<<"INTERPRETE DADO DE BAJA";
          return 0;
     }
    return aux;
}

int validarDuracion(int d){
     if(d>=0){
        return 1;
     } else {
    cout<<"LA DURACION NO PUEDE SER NEGATIVA";
      return 0;
     }
}

int buscarIDyEstado(int c){
  Interprete reg;
   int pos=0;
   while(reg.leer_de_disco(pos)==1){
            if(reg.getID()==c){
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

#endif // FUNCIONES_CANCION_H_INCLUDED

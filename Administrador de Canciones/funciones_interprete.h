#ifndef FUNCIONES_INTERPRETE_H_INCLUDED
#define FUNCIONES_INTERPRETE_H_INCLUDED

///PROTOTIPOS
int agregar_interprete();
int listar_interpretes();
int grabar_registro_interprete(Interprete);
int buscar_interprete_ID(int ID);
int listar_interprete_ID();
int cambiar_genero_musical();
int eliminar_interprete();
int validarTipoInterprete(int t);
int buscarEstadoTipoInterprete(int t);

///

int agregar_interprete(){
   Interprete obj;
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

int listar_interpretes(){
    Interprete reg;
    int leyo=0,pos=0;
    while(reg.leer_de_disco(pos++)==1){
            reg.Mostrar();
            leyo=1;
            cout<<endl;
    }
    return leyo;
}

int listar_interprete_ID(){
    int ID,pos;
    Interprete obj;
    cout<<"INGRESE EL ID DEL INTERPRETE: ";
    cin>>ID;
    pos=buscar_interprete_ID(ID);
    if(pos==-1) return -1;
    obj.leer_de_disco(pos);
    obj.Mostrar();
    return 1;
}

int buscar_interprete_ID(int ID){
    Interprete reg;
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

int eliminar_interprete(){
    int ID ,pos;
    Interprete obj;
    cout<<"INGRESE EL ID DEL INTERPRETE: ";
    cin>>ID;
    pos=buscar_interprete_ID(ID);
    if(pos==-1){
        return -1;
      }if(pos==-2){
      return -2;
      }
    obj.leer_de_disco(pos);
    obj.setEstado(false);
    obj.modificar_en_disco(pos);
    return 1;
}

int cambiar_genero_musical(){
    Interprete obj;
    int pos=0, escribio, nuevo_genero,ID;
    cout<<"INGRESE EL ID DEL INTERPRETE A MODIFICAR: ";
    cin>>ID;
    pos=buscar_interprete_ID(ID);
     if(pos==-1){
         return -1;
     }
     if(pos==-2){
          return -2;
      }
      if(pos>=0){
        obj.leer_de_disco(pos);
        cout<<"INGRESE NUEVO GENERO: ";
        cin>>nuevo_genero;
        obj.setGenero(nuevo_genero);
        escribio=obj.modificar_en_disco(pos);
    }
    return escribio;
}

bool validarNacionalidad(int c){
    Pais reg;
    int pos=0;
    while(reg.leer_de_disco(pos)==1){
            if(reg.getID()==c){
            return true;
            }
            pos++;
    }
    return false;
}

int validarTipoInterprete(int t){
    int aux;
    aux=buscarEstadoTipoInterprete(t);
    if (aux==-1) {
       cout<<"TIPO DE INTERPRETE NO REGISTRADO";
       return 0;
        }
    if (aux==-2){
          cout<<"TIPO DE INTERPRETE DADO DE BAJA";
          return 0;
     }
    return aux;
     }


  int buscarEstadoTipoInterprete(int t){
   TipoInterprete reg;
   int pos=0;
   while(reg.leer_de_disco(pos)==1){
            if(reg.getID()==t){
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




int buscarEstadoGenero(int c){
   Genero reg;
   int pos=0;
   while(reg.leerDeDisco(pos)==1){
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

int validarGenero(int g){
    int aux;
    aux=buscarEstadoGenero(g);
    if (aux==-1) {
       cout<<"GENERO NO REGISTRADO";
       return 0;
        }
    if (aux==-2){
          cout<<"GENERO DADO DE BAJA";
          return 0;
     }
    return aux;
}




#endif // FUNCIONES_INTERPRETE_H_INCLUDED

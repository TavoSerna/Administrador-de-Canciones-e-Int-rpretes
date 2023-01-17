#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


///Punto 1


class InterNac{
 private:
     int ID;
    char nombre[40];
    int cantInter;
 public:
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setCantInter(int c){cantInter=c;}




    void Mostrar(){
        cout<<"ID PAIS: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"CANTIDAD DE INTERPRETES: ";
        cout<<cantInter<<endl;
        cout<<"----------------------"<<endl;
    }

    int grabar_en_disco(){
    FILE *p;
    int escribio;
    p=fopen("cantInterpretesNac.dat","ab");
    if(p==NULL)return -1;
    escribio=fwrite(this,sizeof(InterNac),1,p);
    fclose(p);
    return escribio;
}

    int leer_de_disco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen("cantInterpretesNac.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(InterNac)*pos, 0);
    leyo=fread(this, sizeof(InterNac),1,p);
    fclose(p);
    return leyo;
}

};


int contarInterpretes(int c){
   Interprete reg;
   int pos=0,cant=0;
   while(reg.leer_de_disco(pos++)){
      if(reg.getNacionalidad()==c){
        cant++;
      }
   }
   return cant;
}

void cantInterpretesNac(){
   Pais reg;
   InterNac obj;
   int pos=0,pos2=0,aux;

   while(reg.leer_de_disco(pos)==1){
        aux=contarInterpretes(reg.getID());
         obj.setID(reg.getID());
         obj.setNombre(reg.getNombre());
         obj.setCantInter(aux);
         obj.grabar_en_disco();
         pos++;
         }

  while(obj.leer_de_disco(pos2++)){
      obj.Mostrar();
      cout<<endl;
  }

}


///Punto 2

int contInter(int i){
   Interprete reg;
   int pos=0,cant=0;
   while(reg.leer_de_disco(pos++)){
      if(reg.getGenero()==i){
        cant++;
      }
   }
   return cant;
}


void generosInter(){
   Genero reg;
   int pos=0,aux;
   while(reg.leerDeDisco(pos++)){
     aux=contInter(reg.getID());
     if(aux>=2){
        cout<<"Generos con 2 interpretes o mas: "<<reg.getID()<<" "<<reg.getNombre()<<endl;
       }
   }
}


///Punto 3

void listarCancionesAnio(){
    Cancion obj;
    int pos=0,anio;
    cout<<"INGRESE ANIO DE ESTRENO DE LA CANCION: ";
    cin>>anio;
    while(obj.leer_de_disco(pos++)){
        if(obj.getFechaEstreno().getAnio()==anio){
            obj.Mostrar();
        }
}

}

///Punto 4

int contarRegistros(){
  Genero reg;
  int pos=0,cant=0;
  while(reg.leerDeDisco(pos++)){
    cant++;
  }
  return cant;
}



void cargarGeneroDinamico(){
   Genero obj;
   Genero *v;
   int pos=0,aux,i=0,e;
   aux=contarRegistros();
   v=new Genero[aux];
   if(v==NULL){
     cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
   }
   while(obj.leerDeDisco(pos++)){
        v[i]=obj;
        i++;
    }
   for(e=0;e<aux;e++){
    v[e].Mostrar();
    cout<<endl;
   }
   delete v;
}



#endif // REPORTES_H_INCLUDED

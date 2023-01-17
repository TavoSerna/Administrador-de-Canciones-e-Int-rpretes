#ifndef FUNCIONES_TIPOINTERPRETE_H_INCLUDED
#define FUNCIONES_TIPOINTERPRETE_H_INCLUDED

int agregarTipoInterprete(){
    TipoInterprete obj;
    int pos=0,valor;
    while(obj.leer_de_disco(pos)==1){
            pos++;
        }
    obj.Cargar(pos+1);
    valor=obj.grabar_en_disco();
        return valor;
    }


int listarTipoInterprete(){
    TipoInterprete reg;
    int leyo=0, pos=0;
    while(reg.leer_de_disco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}

#endif // FUNCIONES_TIPOINTERPRETE_H_INCLUDED

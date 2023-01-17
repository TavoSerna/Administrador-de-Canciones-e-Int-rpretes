#ifndef CLASE_FECHA_H_INCLUDED
#define CLASE_FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Mostrar();
        void Cargar();
        void Cargar_fecha_compra();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        ~Fecha(){};
};

void Fecha::Mostrar(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}

void Fecha::Cargar(){
    int d,e=0,f=0,g=0;
    cout<<endl;
    cout<<"DIA: ";
    cin>>d;
    if (d>=1&&d<=31){
        setDia(d);
          }
    else {
        while(e==0){
        cout<<"INGRESE UN DIA VALIDO"<<endl;
        cout<<"DIA: ";
        cin>>d;
        if (d>=1&&d<=31){
        setDia(d);
        e=1;
          }
        }
    }
    cout<<"MES: ";
    cin>>d;
    if (d>=1&&d<=12){
        setMes(d);
          }
    else {
        while(f==0){
        cout<<"INGRESE UN MES VALIDO"<<endl;
        cout<<"MES: ";
        cin>>d;
        if (d>=1&&d<=12){
        setMes(d);
        f=1;
          }
        }
    }
    cout<<"ANIO: ";
    cin>>d;
    if (d>=1900&&d<=2022){
        setAnio(d);
          }
    else {
        while(g==0){
        cout<<"INGRESE UN ANIO VALIDO"<<endl;
        cout<<"ANIO: ";
        cin>>d;
        if (d>=1900&&d<=2022){
        setAnio(d);
        g=1;
          }
        }
    }
}


#endif // CLASE_FECHA_H_INCLUDED

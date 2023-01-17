# include<iostream>
# include<cstdlib>
# include<cstring>


///Gustavo Serna DNI 21946123


using namespace std;

const char *ARCHIVO_CANCIONES="canciones.dat";
const char *ARCHIVO_INTERPRETES="interpretes.dat";
const char *ARCHIVO_GENEROS="generos.dat";
const char *ARCHIVO_PAISES="paises.dat";
const char *ARCHIVO_TIPO_INTERPRETES="tipoInterpretes.dat";
const char *BACK_UP_CANCIONES="canciones.bkp";
const char *BACK_UP_INTERPRETES="interpretes.bkp";
const char *BACK_UP_GENEROS="generos.bkp";
const char *BACK_UP_PAISES="paises.bkp";
const char *BACK_UP_TIPO_INTERPRETES="tipoInterpretes.bkp";
const char *INICIO_CANCIONES="inicio_canciones.bkp";
const char *INICIO_INTERPRETES="inicio_interpretes.bkp";
const char *INICIO_GENEROS="inicio_generos.bkp";



# include "cargar_cadena.h"
# include "clase_fecha.h"
# include "clase_pais.h"
# include "clase_tipoInterprete.h"
# include "clase_genero.h"
# include "clase_interprete.h"
# include "funciones_interprete.h"
# include "clase_cancion.h"
# include "funciones_genero.h"
# include "funciones_cancion.h"
# include "funciones_paises.h"
# include "funciones_tipoInterprete.h"
# include "configuracion.h"
# include "reportes.h"
# include "Submenus.h"


int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-------------------------------"<<endl<<endl;
        cout<<"1) MENU CANCIONES"<<endl;
        cout<<"2) MENU INTERPRETES"<<endl;
        cout<<"3) MENU GENEROS"<<endl;
        cout<<"4) MENU PAISES"<<endl;
        cout<<"5) MENU TIPO DE INTERPRETES"<<endl;
        cout<<"6) REPORTES"<<endl;
        cout<<"7) CONFIGURACION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES:"<<endl;
        cin>>opc;
        switch(opc){
            case 1: menuCanciones();
                break;
            case 2: menuInterpretes();
                break;
            case 3: menuGeneros();
                break;
            case 4: menuPaises();
                break;
            case 5: menuTipoInterpretes();
                break;
            case 6: menuReportes();
                break;
            case 7: menuConfiguracion();
                break;
            case 0: return 0;
                break;
            default: cout<<"LA OPCION INGRESADA NO ES VALIDA. INGRESE OTRA OPCION."<<endl;

        }
        cout<<endl;
        system("pause");
    }
    return 0;
}

#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED


int menuCanciones();
int menuInterpretes();
int menuGeneros();
int menuPaises();
int menuTipoInterpretes();
int menuReportes();
int menuConfiguracion();



int menuCanciones(){
    int opc,aux;
    while(true){
        system("cls");
        cout<<"MENU CANCIONES"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR CANCION"<<endl;
        cout<<"2) LISTAR CANCION POR ID"<<endl;
        cout<<"3) LISTAR TODAS LAS CANCIONES"<<endl;
        cout<<"4) MODIFICAR FECHA DE ESTRENO"<<endl;
        cout<<"5) ELIMINAR CANCION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
             case 1: if(agregar_cancion()==1){
                 cout<<"CANCION AGREGADA";
             }
                break;
            case 2:aux=listar_canciones_ID();
                if(aux==-1){
                    cout<<"NO EXISTE LA CANCION";
                } else {
                    cout<<"LA CANCION FUE DADA DE BAJA";
                }
                break;
            case 3:aux=listar_canciones();
                switch(aux){
                    case 1: cout<<"FIN DE LISTADO";
                        break;
                    case -1:cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                        break;
                    case 0: cout<<"NO HAY REGISTRO PARA LISTAR";
                        break;
                }
                break;
            case 4:aux=cambiar_fecha_estreno();
                  switch(aux){
                     case 1: cout<<"CANCION MODIFICADA";
                        break;
                    case -1:cout<<"NO EXISTE LA CANCION";
                        break;
                    case -2: cout<<"LA CANCION FUE DADA DE BAJA";
                   break;
                   }
                break;
            case 5:aux=eliminar_cancion();
                switch(aux){
                    case 1: cout<<"CANCION ELIMINADA";
                        break;
                    case -1:cout<<"LA CANCION NO EXITE";
                        break;
                    case -2: cout<<"LA CANCION YA FUE DADA DE BAJA";
                   break;
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

int menuInterpretes(){
    int opc,aux;
    while(true){
        system("cls");
        cout<<"MENU INTERPRETES"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR INTERPRETE"<<endl;
        cout<<"2) LISTAR INTERPRETE POR ID"<<endl;
        cout<<"3) LISTAR TODOS LOS INTERPRETES"<<endl;
        cout<<"4) MODIFICAR GENERO MUSICAL PRINCIPAL"<<endl;
        cout<<"5) ELIMINAR INTERPRETE"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregar_interprete()==1){
                 cout<<"INTERPRETE AGREGADO";
             }
                break;
            case 2: aux=listar_interprete_ID();
                if(aux==-1){
                    cout<<"NO EXISTE EL ID";
                } else {
                    cout<<"EL ID FUE DADO DE BAJA";
                }
                break;
            case 3:aux=listar_interpretes();
                switch(aux){
                    case 1: cout<<"FIN DE LISTADO";
                        break;
                    case -1:cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                        break;
                    case 0: cout<<"NO HAY REGISTRO PARA LISTAR";
                        break;
                }
                break;
            case 4:aux=cambiar_genero_musical();
                  switch(aux){
                     case 1: cout<<"INTERPRETE MODIFICADO";
                        break;
                    case -1:cout<<"NO EXISTE EL ID DE INTERPRETE";
                        break;
                    case -2: cout<<"EL INTERPRETE FUE DADO DE BAJA";
                   break;
                   }
                break;
            case 5:aux=eliminar_interprete();
                switch(aux){
                    case 1: cout<<"INTERPRETE ELIMINADO";
                        break;
                    case -1:cout<<"EL INTERPRETE NO EXITE";
                        break;
                    case -2: cout<<"EL INTERPRETE YA FUE DADO DE BAJA";
                   break;
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

int menuGeneros(){
    int opc,aux;
    while(true){
        system("cls");
        cout<<"MENU GENEROS"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR GENERO"<<endl;
        cout<<"2) LISTAR GENERO POR ID"<<endl;
        cout<<"3) LISTAR TODOS LOS GENEROS"<<endl;
        cout<<"4) MODIFICAR TIPO DE INSTRUMENTACION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
           case 1: if(agregar_genero()==1){
                 cout<<"GENERO AGREGADO";
             }
                break;
            case 2:aux=listar_genero_ID();
                if(aux==-1) cout<<"NO EXISTE EL ID DE GENERO";
                break;
            case 3:aux=listar_generos();
                switch(aux){
                    case 1: cout<<"FIN DE LISTADO";
                        break;
                    case -1:cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                        break;
                    case 0: cout<<"NO HAY REGISTRO PARA LISTAR";
                        break;
                }
                break;
            case 4:if(modificar_instrumentacion()!=1) cout<<"ERROR DE ARCHIVO"<<endl;
                    else cout<<"INSTRUMENTACION MODIFICADA"<<endl;
            case 0:
            return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES VALIDA. INGRESE OTRA OPCION."<<endl;
        }
        cout<<endl;
        system("pause");
    }
}


int menuPaises(){
    int opc,aux;
    while(true){
        system("cls");
        cout<<"MENU PAISES"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR PAISES"<<endl;
        cout<<"2) LISTAR PAISES"<<endl;
        cout<<"3) LISTAR PAISES POR ID"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:if(agregarPais()==1){
                 cout<<"PAIS AGREGADO";
             }
              break;
        case 2:aux=listarPaises();
             switch(aux){
                case 1: cout<<"FIN DEL LISTADO";
                        break;
                case -1:cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                        break;
                case 0: cout<<"NO HAY REGISTROS PARA LISTAR";
                        break;
                }
              break;
        case 3:aux=listarPaisesID();
              if(aux==-1) cout<<"NO EXISTE EL ID DE PAIS";
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

int menuTipoInterpretes(){
    int opc,aux;
    while(true){
        system("cls");
        cout<<"MENU TIPO INTERPRETES"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR TIPO INTERPRETE"<<endl;
        cout<<"2) LISTAR TIPOS DE INTERPRETES"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:if(agregarTipoInterprete()==1){
                 cout<<"TIPO DE INTERPRETE AGREGADO";
             }
              break;
        case 2:aux=listarTipoInterprete();
             switch(aux){
                case 1: cout<<"FIN DEL LISTADO";
                        break;
                case -1:cout<<"NO SE PUDO ABRIR EL ARCHIVO";
                        break;
                case 0: cout<<"NO HAY REGISTROS PARA LISTAR";
                        break;
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



int menuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES"<<endl;
        cout<<"5) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPOS DE INTERPRETES"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
        cout<<"9) RESTAURAR EL ARCHIVO DE PAISES"<<endl;
        cout<<"10) RESTAURAR EL ARCHIVO TIPO DE INTERPRETES"<<endl;
        cout<<"11) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
           case 1:if(backup_canciones()) cout<<"COPIA DE SEGURIDAD REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 2:if(backup_interpretes()) cout<<"COPIA DE SEGURIDAD REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 3:if(backup_generos()) cout<<"COPIA DE SEGURIDAD REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 4:if(backupPaises()) cout<<"COPIA DE SEGURIDAD REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                 break;
            case 5:if(backupTipoInterprete()) cout<<"COPIA DE SEGURIDAD REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 6: if(restaurar_canciones()) cout<<"RESTAURACION REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA RESTAURACION"<<endl;
                break;
            case 7:if(restaurar_interpretes()) cout<<"RESTAURACION REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA RESTAURACION"<<endl;
                break;
            case 8:if(restaurar_generos()) cout<<"RESTAURACION REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA RESTAURACION"<<endl;
                break;
            case 9:if(restaurarPaises()) cout<<"RESTAURACION REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA RESTAURACION"<<endl;
                 break;
            case 10:if(restaurarTipoInterprete()) cout<<"RESTAURACION REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA RESTAURACION"<<endl;
                break;
            case 11:menuDatosInicio();
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

int menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES (Recupero el 1 parcial)"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) Archivo cantidad de interpretes por nacionalidad"<<endl;
        cout<<"2) Generos con al menos 2 interpretes"<<endl;
        cout<<"3) Listar canciones segun anio ingresado"<<endl;
        cout<<"4) Cargar y mostrar Generos con vector dinamico"<<endl;

        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:cantInterpretesNac();
                break;
            case 2:generosInter();
                break;
            case 3:listarCancionesAnio();
                break;
            case 4:cargarGeneroDinamico();
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

#endif // SUBMENUS_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include<string.h>
#include "comandos.h"

using namespace std;

int buscar_cuadrante(int x, int y, int i, int j);






    class Enemy{   ///MODELO INICIAL DE ENMIGOS;
        private:
                char identidad;
                int coordenadaX;
                int coordenadaY;
                int vida;
                int vision;
                int ataque;
                int velocidad;
                int semilla_drop;
                bool vivo;
        public:

            Enemy(){ ///CONSTRUCTOR BASICO;

            this->identidad='Q';
            this->coordenadaX=25;
            this->coordenadaY=25;
            this->vida=1000;
            this->vision=3;
            this->ataque=30;
            this->velocidad=1;
            this->vivo=true;
            }

           ///  FALTA DESTRUCTOR

            ///SETTERS
            int set_x(int x){
            this->coordenadaX=x;
            }
            int set_y(int y){
            this->coordenadaY=y;
            }

            ///GETTERS
            char get_identidad (){
            return identidad;}

            int get_x(){
            return coordenadaX;}

            int get_y(){
            return coordenadaY;}

            int get_vision(){
            return vision;}

            int get_velocidad(){
            return velocidad;}


            ///METHADOS

            int mirar(Level reg){

                int x=this->get_x(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                int y=this->get_y(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                    cout<<"ESTE ES EL VALOR DE X="<<x<<endl;
                    cout<<"ESTE ES EL VALOR DE Y="<<y<<endl;
                int v=this->get_vision();       ///LA VISION DEL OBJETO
                    cout<<"ESTE ES EL VALOR DE LA VISION="<<v<<endl;
                int m=this->get_velocidad();    ///CUADRADOS QUE SE MUEVE EL OBJETO
                    cout<<"ESTE ES EL VALOR DEL MOVIMIENTO="<<m<<endl;
                int i=x-v; int I=x+v;           ///INICIO Y FIN DEL FOR EN X
                    cout<<"ESTE ES EL VALOR DEL i="<<i<<endl;
                int j=y-v; int J=y+v;           ///INICIO Y FIN DEL FOR EN Y
                    cout<<"ESTE ES EL VALOR DEL j="<<j<<endl;

                int cuadrante=0;                ///CUADRANTE INICIAL

                    for(i; i<=I; i++ ){
                            cout<<"ACA SALE LO QUE ESTA LEYENDO EL FOR DE I== ";
                            cout<<i<<endl;
                        for(j; j<=J; j++ ){
                            cout<<"ACA SALE LO QUE ESTA LEYENDO EL FOR DE J== ";
                            cout<<j<<endl;
                            system("pause");

                            if(reg.caso[i][j]=='@'){

                                    cout<<"aca esta lo que se saca de mirar al rededor  <<i="<<i<<"    <<j="<<j<<"   ";
                                    cout<<reg.caso[i][j]<<endl;
                                    system("pause");

                                cuadrante=buscar_cuadrante(x, y, i, j);
                                return cuadrante;
                                cout<<"Valor del cuadrante "<<cuadrante<<endl;
                                system ("pause");

                            }
                    }
                }


            }

                            //DEVUELVE UN REGISTRO ACTUALIZADO CON LA POSICION DEL ENEMIGO

            Level mov( Level reg, int x, int y){


                int m=this->get_velocidad();
                int cuadrante=this->mirar(reg);

                reg.caso[x][y]='.';

                cout<<"LLEGAMOS A LA INSTANCIA DEL SWITCH";
                            system("pause");

                switch (cuadrante)
                {
                case 1: reg.caso[x-m][y-m]= this->get_identidad(); set_x(x-m); set_y(y-m);break; ///izquieraArriba
                case 2: reg.caso[x][y-m]=   this->get_identidad(); set_x(x); set_y(y-m);break; ///arriba
                case 3: reg.caso[x+m][y-m]= this->get_identidad(); set_x(x+m); set_y(y-m);break; ///derechaArriba
                case 4: reg.caso[x][y-m]=   this->get_identidad(); set_x(x); set_y(y-m);break; ///izquierda
                case 6: reg.caso[x][y+m]=   this->get_identidad(); set_x(x); set_y(y+m);break; ///derecha
                case 7: reg.caso[x-m][y+m]= this->get_identidad(); set_x(x-m); set_y(y+m);break; ///izquierdaAbajo
                case 8: reg.caso[x+m][y]=   this->get_identidad(); set_x(x+m); set_y(y);break; ///abajo
                case 9: reg.caso[x+m][y+m]= this->get_identidad(); set_x(x+m); set_y(y+m);break; ///derechaAbajo

                default: reg.caso[x][y]=this->get_identidad(); set_x(x); set_y(y); break; ///derechaArriba
                }
                    return reg;
                };




            void evento_esqueleto(){
            char op;

                cout<<"\t\tElije que hacer con: " << "ESQUELETO.NOMBRE"<<endl;
                cout<<"\t\tJ) JUGAR\n";
                cout<<"\t\tK) GOLPEAR\n";
                cout<<"\t\tL) LANZAR\n";

            op=getch();
                switch (op)
                {
                case 'j': case 'J': cout<< "\t\tDecidiste agarrarlo de la mano y ponerte a bailar con el, recibes una maldicion";break;
                case 'k': case 'K': cout<< "\t\tDecidiste terminar con su no vida solo que tus golpes de niñE centennial no le hacen nada";break;
                case 'l': case 'L': cout<< "\t\tDecidiste vomitarle el contenido de tu estomago... porque lanzar en Argentina es vomitar";break;
                default:            cout<< "\t\tDecidiste marcharte";  break;
                }
                system("pause>NULL");
            }

    };

    class Items{ /// MODELO INICIAL DE INTEMS
        public:

            char status[30][51];

            Items(){
                        strcpy(status[0], "##################################################");
                        strcpy(status[29],"##################################################");
                    for (int m=1; m<29 ; m++ )
                    {
                        strcpy(status[m], "# .............................................. #");
                    }
                        strcpy(status[3], "# ESPADA LUMINISCENTE 71-100......[CORTANTE-LUZ] #");
                        strcpy(status[5], "# MAZA DISRUPTIVA 50-80....[CONTUNDENTE-DISPELL] #");
                        strcpy(status[6], "# LANZA VENTISCA 67-93............[CORTANTE-AIRE #");
                        strcpy(status[7], "# DAGA OXIDADA 27-200.............[CORTANTE-...] #");
            }

    };

///LA APERTURA DEL ARCHIVO Y LA CREACION DEL REGISTRO  ESTAN BIEN
/*class Level crearNivel(){

    ///CREO UNA VARIABLE CLASE QUE RECIBE PARAMETROS PARA EL CASO DE MATRIZ 30[30][101]

                                  ///SE LLENA CON ASTERISCOS Y PUNTOS
            Level lev;
            strcpy(lev.caso[0],"####################################################################################################");
            strcpy(lev.caso[29],"####################################################################################################");

    for (int i=1; i<29; i++)
        {
            strcpy(lev.caso[i],"#..................................................................................................#");
        }

           strcpy(lev.caso[10],"#......-......|.........Q..............Z...........     ................$....#####..&..........Ç...#");

        ///ABRO UN ARCHIVO NUEVO DONDE ALMACENAR EL REGISTRO, ESTE SE LLAMA NIVELES.DAT
    FILE *p;
    p=fopen("Niveles.dat","ab");
    if (p==NULL){cout<<"Error en apertura de Niveles linea 15";
    system("pause");
    exit (1);
    }else{
        fwrite(&lev, sizeof lev, 1, p);

        cout<<"NIVEL CREADO SATISFACTORIABLEMENTISTICO\n";
        system("pause");
        }

        fclose(p);
        return lev;
    }
*/


/// CARGA DEL NIVEL EN MEMORIA
        class Level mostrar_mapa(){

        FILE *p;
        Level reg;
        int contador=0;
        p=fopen("Niveles.dat","rb");
        if (p==NULL){cout<<"Error en lectura de Niveles linea 45";
         system("pause");
         exit (1);
        }
        else{
            cout<<"<FILE ABIERTO, PROCEDE A LEER REGISTRO EN DISCO: \n";
            system("pause");
            while(fread(&reg, sizeof reg, 1, p)==1){

            contador++;
                for (int x=0; x<30 ; x++ )
                    {
                     cout<<reg.caso[x];
                cout<<endl;
                    }
                    cout<<endl<<endl;
            }
                cout<<"CANTIDAD DE REGISTROS: "<<contador<<endl;


            system("pause");
        }
        return reg;
        fclose(p);
        }


    /// UBICACION DEL PERSONAJE EN EL MAPA
    class Level posicion_jugador(int x, int y, Level reg){

    reg.caso[x][y]='@';                                                 /// UBICACION DEL JUGADOR EN LA MATRIZ
    return reg;
    }


    ///UBICACION DEL ENEMIGO DE PRUEBA
    class Level posicion_enemigo(int x, int y, Level reg, Enemy obj){

    x=obj.get_x();
    y=obj.get_y();

    reg.caso[x][y]=obj.get_identidad();                                ///UBICACION DEL ENEMIGO EN LA MATRIZ

    return reg;
    };


    /// IDENTIFICACION DE CUADRANTES
    int buscar_cuadrante(int x, int y, int i, int j){ ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


    if(y<j&&x<i){ ///PRIMER *
        return 9;
    }else if(y==j&&x<i){///SEGUNDO *
        return 8;
    }else if(y>j&&x<i){///TERCER *
        return 7;
    }else if(y<j&&x==i){///CUARTO *
        return 6;                   ///QUINTO ES LA POSICION DEL OBJETO ENEMIGO *
    }else if(y>j&&x==i){///SEXTO *
        return 4;
    }else if(y<j&&x>i){///SEPTIMO *
        return 3;
    }else if(y==j&&x>i){///OCTAVO *
        return 2;
    }else if(y>j&&x>i){///NOVENO *
        return 1;
    }


    }



///MAIN
    int main(){

    bool run_game=true;
    char tecla, teclaAnt;
    char opcion;

    int x=15, y=15;///POSICION INICIAL DEL JUGADOR

    Level reg;
    Items mochila;
    Enemy esqueleto;

   ///reg=crearNivel();
  /* cout<<"PROCEDE A CARGA DE MAPA DESDE EL DISCO, PREVIA CREACION: \n";
   system("pause");
   system("cls");
*/
   reg=mostrar_mapa();

    cout<<endl<<endl<<"ESPERA INSTRUCCIONES\n";
    system("pause>NULL");

  /*  cout<<"ABSTRACCION DEL MAPA: \n\n";

     for (int x=0; x<30 ; x++ )
                {
                 cout<<reg.caso[x];
                 cout<<endl;
                }
*/
    cout<<"MAPA CARGADO EN MEMORIA, LISTO A SER MODIFICADO\n";
    system("pause>NULL");
    system("cls");

    cout<<"ESTABLECIENDO LA POSICION INICIAL DEL JUGADOR\n";

    reg=posicion_jugador(x,y, reg);
    reg=posicion_enemigo(x,y, reg, esqueleto);

    system("pause");

    while(run_game){
            system("cls");

    cout<<"ESPERANDO INGRESO POR TECLADO W/A/S/D\n\n\n";

    ///MAPA ABSTRAIDO DEL DISCO CON CARACTER JUGADOR INCLUIDO EN MEMORIA.
     for (int i=0; i<30 ; i++ )
                {
                 cout<<reg.caso[i]<<"  "<< mochila.status[i];
                 cout<<endl;
                }



  ///INICIO DE INTERACCION DE PERSONAJE VS ENTORNO

     tecla=getch();
    switch (tecla)
    {
        ///MOVIMIENTO
    case 's': case 'S':
        if(reg.caso[x+1][y]=='.'){
        reg.caso[x][y]='.'; reg.caso[x+1][y]='@'; x+=1; ///CHECK
        }else{
        opcion=reg.caso[x+1][y];
        evento_interaccion(opcion);
        } break;

    case 'a': case 'A':
        if(reg.caso[x][y-1]=='.'){
        reg.caso[x][y]='.'; reg.caso[x][y-1]='@'; y-=1; ///CHECK
        }else{
        opcion=reg.caso[x][y-1];
        evento_interaccion(opcion);
        } break;

    case 'w': case 'W':
        if(reg.caso[x-1][y]=='.'){
        reg.caso[x][y]='.'; reg.caso[x-1][y]='@'; x-=1; ///CHECK
        }else{
        opcion=reg.caso[x-1][y];
        evento_interaccion(opcion);
        } break;

    case 'd': case 'D':
        if(reg.caso[x][y+1]=='.'){
        reg.caso[x][y]='.'; reg.caso[x][y+1]='@'; y+=1; ///CHECK
        }else{
        opcion=reg.caso[x][y+1];
        evento_interaccion(opcion);
        } break;
        ///ACCIONES

    case 'k': case 'K':
        switch (teclaAnt)
        {
        case 'd': case 'D':   ///DERECHA

           reg.caso[x][y+1]='#'; break;

            case 'w': case 'W':
                reg.caso[x-1][y]='#'; break;

                case 'a': case 'A':
                     reg.caso[x][y-1]='#'; break;

                    case 's': case 'S':
                         reg.caso[x+1][y]='#'; break;
        } break;
        default: cout<<"MENSAJE DE DEFAULT GENERICO "; break;

    }
    teclaAnt=tecla;
   // reg.movimiento(esqueleto.get_x(), esqueleto.get_y(), esqueleto.get_velocidad(), esqueleto.get_vision(), esqueleto);

   reg=esqueleto.mov( reg, esqueleto.get_x() , esqueleto.get_y());

   buscame_caracteres(reg);
    }
       return 0;
    }


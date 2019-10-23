#include <iostream>
using namespace std;
#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED







class Level{ /// CLASE NIVEL, LA CUAL VA A CARGAR NIVELES DE TAMAÑO ESTATICO
    public:
    char caso[30][101];

    /// METODOS PARA ALTERAR EL MAPA;
};



evento_interaccion(char opcion){

///SERIE DE ELEMENTOS A CHEQUEAR POR LA FUNCION CON MENSAJES UNICOS

switch (opcion)
{
case 'Q': cout<<"Esqueleto\n";          break;
case 'Z': cout<<"Zombie\n";             break;
case '#': cout<<"Roca\n";               break;
case '$': cout<<"Cofre abandonado\n";   break;
case '-':
case '|': cout<<"Puerta\n";             break;
case '&': cout<<"objeto extraño \n";    break;
case ' ': cout<<"Agujero en el piso";   break;
case 'Ç': cout<<"MUERTE INMINENTE!";    break;
}

system("pause>NULL");
}


void buscame_caracteres( Level reg){

for (int i=22 ; i<29 ; i++ )
    {for ( int j=22;j<29; j++ )
    {
                if(reg.caso[i][j]=='@'||reg.caso[i][j]=='Q'||reg.caso[i][j]==' '||reg.caso[i][j]=='Z'){
                cout<<"EL CARACTER: "<<reg.caso[i][j]<<"  ";
                cout<<"SE ENCUENTRA EN X=  "<<i<<"  Y=  "<<j;
                system("pause");
                }
    }
    }
}
#endif // COMANDOS_H_INCLUDED

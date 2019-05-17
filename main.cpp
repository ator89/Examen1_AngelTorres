#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//Menú de opciones
void menu();

char** createMatrix();//Crear matriz
void initMatrix(char**);//Inicializar
void printMatrix(char**);//Imprimir
void freeMatrix(char**&);//Liberar espacio reservado


void jugar();//Loop de turnos
void moverNegras(char**,int,int,int,int);//mover
void moverBlancas(char**,int,int,int,int);

int main(){

    bool menuActivo = true;
    int menuOpcion = -1;

    while(menuActivo){
        do{
            menu();
            cin >> menuOpcion;
            switch(menuOpcion){
                case 1://Jugar
                    jugar();
                    break;
                case 0://Salir
                    break;
                default:
                    cout << "Opción inválida.\n\n";
                    break;
            }
        }while(menuOpcion != 0);
        menuActivo = false;
    }

    return 0;
}

void jugar(){
    
    bool captura = true;
    int turno = 0;
    char** matrix = NULL;

    matrix = createMatrix();
    initMatrix(matrix);
    printMatrix(matrix);
    freeMatrix(matrix);
    cout << "Comienza el juego\n";

    int inicioX, inicioY, finalX, finalY;

    while(captura){
        
        if(turno%2 == 0){
            cout << "Jugador 1\n";
        }else{
            cout << "Jugador 2\n";
            //captura = false;
        }
        if(turno == 10){
            captura = false;
        }
        turno++;
    }
    
}

//Crear matriz
char** createMatrix(){
    char** matrix = new char*[12];
    for(int i = 0; i < 12; i++){
        matrix[i] = new char[12];
    }
    return matrix;
}

//Inicializar la matriz
void initMatrix(char** matrix){
    
    for(int i = 0; i< 12; i++){
        for(int j = 0; j < 12; j++){
            if((i == 1 && j == 1) || (i == 1 && j == 11)){
                matrix[i][j] = 'X';
            }        
           // else if(i == 11 &&  j==0){ 
           //     matrix[i][j] = 'X';
           // }
            else if(i == 11 && j == 11){
                matrix[i][j] = 'X';
            }
            else if(i == 6 && j == 6){
                matrix[i][j] = 'W';
            }
            else{
                matrix[i][j] = ' ';
            }
        }
    }
    matrix[0][0] = '.';
    matrix[1][0] = 'A';
    matrix[2][0] = 'B';
    matrix[3][0] = 'C';
    matrix[4][0] = 'D';
    matrix[5][0] = 'E';
    matrix[6][0] = 'F';
    matrix[7][0] = 'G';
    matrix[8][0] = 'H';
    matrix[9][0] = 'I';
    matrix[10][0] = 'J';
    matrix[11][0] = 'K';
    matrix[11][1] = 'X';
    matrix[0][1] = '0';
    matrix[0][2] = '1';
    matrix[0][3] = '2';
    matrix[0][4] = '3';
    matrix[0][5] = '4';
    matrix[0][6] = '5';
    matrix[0][7] = '6';
    matrix[0][8] = '7';
    matrix[0][9] = '8';
    matrix[0][10] = '9';
    matrix[0][11] = 'd';

    //Negras superior
    matrix[1][5] = 'm';
    matrix[1][6] = 'm';
    matrix[1][7] = 'm';
    matrix[2][7] = 'm';
    matrix[2][5] = 'm';
    matrix[3][6] = 'm';
    //Negras inferior
    matrix[11][5] = 'm';
    matrix[11][6] = 'm';
    matrix[11][7] = 'm';
    matrix[10][7] = 'm';
    matrix[10][5] = 'm';
    matrix[9][6] = 'm';
    //Negras izquierda
    matrix[5][1] = 'm';
    matrix[6][1] = 'm';
    matrix[7][1] = 'm';
    matrix[5][2] = 'm';
    matrix[7][2] = 'm';
    matrix[6][3] = 'm';
    //Negras derecha
    matrix[5][11] = 'm';
    matrix[6][11] = 'm';
    matrix[7][11] = 'm';
    matrix[5][10] = 'm';
    matrix[7][10] = 'm';
    matrix[6][9] = 'm';

    //Blancas
    matrix[4][6] = 's';
    matrix[6][4] = 's';
    matrix[6][8] = 's';
    matrix[8][6] = 's';
    matrix[5][5] = 's';
    matrix[5][6] = 's';

    matrix[5][7] = 's';
    matrix[6][5] = 's';
    matrix[6][7] = 's';
    matrix[7][7] = 's';
    matrix[7][5] = 's';
    matrix[7][6] = 's';
}

//Mover negras
void moverNegras(char** matrix, int inicioX, int inicioY, int finalX, int finalY){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j< 12; j++){
            if(matrix[inicioY][inicioX] == matrix[finalY][finalY]){
                cout << "Está moviendo en la misma posición\n";
            }
            if(matrix[finalY][finalX] == 'm' || matrix[finalY][finalX] == 's'){
                cout << "La casilla está ocupada\n";
            }
            if(matrix[finalY][finalX] == 'X'){
                cout << "No puede acceder a las esquinas\n";
            }else{
                matrix[inicioY][inicioX] = ' ';
                matrix[finalY][finalX] = 'm';
            }
        }
    }
}

//Mover blancas
void moverBlancas(char** matrix, int inicioX, int inicioY, int finalX, int finalY){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j< 12; j++){
            if(matrix[inicioY][inicioX] == matrix[finalY][finalY]){
                cout << "Está moviendo en la misma posición\n";
            }
            if(matrix[finalY][finalX] == 'm' || matrix[finalY][finalX] == 's'){
                cout << "La casilla está ocupada\n";
            }
            if(matrix[finalY][finalX] == 'X'){
                cout << "No puede acceder a las esquinas\n";
            }
            if(matrix[inicioY][inicioX] == 'W' && matrix[finalY][finalX] == 'X'){
                cout << "Los suecos ganaron la partida";
            }
            else{
                matrix[inicioY][inicioX] = ' ';
                matrix[finalY][finalX] = 's';
            }
        }
    }
}

//Imprimir matriz
void printMatrix(char** matrix){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cout << '[' << matrix[i][j] << ']';
        }
        cout << endl;
    }
}

//Liberar espacio reservado para la matriz
void freeMatrix(char**& matrix){
    for(int i = 0; i < 12; i++){
        delete[] matrix[i];
        matrix[i] = NULL;
    }
    delete[] matrix;
    matrix = NULL;
}

//Menú de opciones
void menu(){
    cout << "\n\tMenú\n"
        << "1 - Jugar\n"
        << "0 - Salir\n"
        << "Seleccionar: ";
}

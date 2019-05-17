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

void jugar();

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
    char** matrix = new char*[11];
    for(int i = 0; i < 11; i++){
        matrix[i] = new char[11];
    }
    return matrix;
}

//Inicializar la matriz
void initMatrix(char** matrix){
    for(int i = 0; i< 11; i++){
        for(int j = 0; j < 11; j++){
            //casilla inicial del rey
            if((i == 0 && j == 0) || (i == 0 && j == 10) || (i == 10 && j ==0) || (i == 10 && j == 10)){
                matrix[i][j] = 'X';
            }
            else if(i == 5 && j == 5){
                matrix[i][j] = 'W';
            }else{
                matrix[i][j] = '.';
            }
        }
    }
}

//Imprimir matriz
void printMatrix(char** matrix){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            cout << '[' << matrix[i][j] << ']';
        }
        cout << endl;
    }
}

//Liberar espacio reservado para la matriz
void freeMatrix(char**& matrix){
    for(int i = 0; i < 11; i++){
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

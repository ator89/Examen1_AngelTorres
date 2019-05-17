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

int main(){

    bool menuActivo = true;
    int menuOpcion = -1;

    while(menuActivo){
        do{
            menu();
            cin >> menuOpcion;
            switch(menuOpcion){
                case 1://Jugar
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
            if(i == 6 && j == 6){
                matrix[i][j] = 'R';
            }
            matrix[i][j] = ' ';
        }
    }
}

void printMatrix(char** matrix){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            cout << ' ' << matrix[i][j];
        }
        cout << endl;
    }
}

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

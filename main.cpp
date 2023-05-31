#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>


// Invierte una subcadena desde el inicio hasta el índice especificado
void invertirSubcadena(char arreglo[], int indice){
    char temporal;
    int inicio = 0;
    while (inicio < indice) {
        temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[indice];
        arreglo[indice] = temporal;
        inicio++;
        indice--;
    }
}

// Realiza la búsqueda en amplitud para encontrar la secuencia ordenada
std::string busquedaEnAmplitud(std::string inicio, std::string fin, int& contadorNodos){
    std::queue<std::string> cola;
    std::set<std::string> visitados;
    cola.push(inicio);
    visitados.insert(inicio);

    while (!cola.empty()){
        std::string actual = cola.front();
        cola.pop();
        contadorNodos++;

        if (actual == fin){
            return actual;
        }

        for (int i = 1; i < actual.size(); i++){
            std::string siguiente = actual;
            invertirSubcadena(&siguiente[0], i);
            if (visitados.count(siguiente) == 0){
                cola.push(siguiente);
                visitados.insert(siguiente);
            }
        }
    }

    return "";
}

int main(){
    int longitudCadena;
    std::cout << "Introduce la longitud de la cadena a ordenar: ";
    std::cin >> longitudCadena;
    std::string panqueques = "abcdefghiklmnopqrstuvwxyz";
    panqueques = panqueques.substr(0, longitudCadena);
    std::string panquequesOrdenados = panqueques;
    std::random_shuffle(panqueques.begin(), panqueques.end());
    int contadorNodos = 0;
    std::string resultado = busquedaEnAmplitud(panqueques, panquequesOrdenados, contadorNodos);
    std::cout << "Panqueques: ";
    std::cout << panqueques << std::endl;
    std::cout << std::endl;
    std::cout << "Panqueques ordenados: ";
    std::cout << panquequesOrdenados << std::endl;
    std::cout << std::endl;
    if (resultado != ""){
        std::cout << "Panqueques resueltos: " << resultado << std::endl;
    }
    else {
        std::cout << "No se encontro una solucion" << std::endl;
    }
    std::cout << "Nodos visitados: " << contadorNodos << std::endl;
    return 0;
}

#include <iostream>
#include <algorithm>

// Francisco Javier Romo Juarez A01643189
// Diego Enrique Vargas Ramírez A01635782

// Cambio de monedas

 

// Algoritmo Dinámico

int cambioDinamico(int denominaciones[], int n, int p, int q) { 
    int cambio = q - p;
    int F[cambio + 1]; // Arreglo para guardar el numero de monedas
    int usado[cambio + 1]; // Arreglo que guarda denominaciones usadas
    int usados[n] = {0}; // Arreglo que cuenta el uso de cada denominacion

    // Inicializar el arreglo con un valor maximo del cual ir trabajando
    // X valor que no se pueda entregar cambio exacto tendrian valor INT_MAX
    for(int i = 0; i <= cambio; i++) {
        F[i] = INT_MAX;
    }

    F[0] = 0; // Base case: no coins needed to make 0 change

    // Iterar por el arreglo F
    for (int i = 1; i <= cambio; i++) {
        for(int j = 0; j < n; j++) {
            if(denominaciones[j] <= i && F[i - denominaciones[j]] != INT_MAX) {
                if(F[i] > F[i - denominaciones[j]] + 1) {
                    F[i] = F[i - denominaciones[j]] + 1;
                    usado[i] = j; // Mantenemos cuenta de las denominaciones usadas
                }
            }
        }
    }

    // Si F[cambio] sigue en INT_MAX, no hay solucion
    if(F[cambio] == INT_MAX) {
        std::cout << "No se puede dar cambio preciso" << std::endl;
        return -1;
    }

    // Utilizar el arreglo creado para obtener el numero de monedas
    int faltante = cambio;
    while(faltante > 0) {
        int temp = usado[faltante];
        usados[temp] += 1;
        faltante -= denominaciones[temp];
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        std::cout << "Moneda: " << denominaciones[i] << " -> Cantidad: " << usados[i] << std::endl;
    }

    return 0;
}

// Algoritmo Avaro

int cambioAvaro(int* denominaciones, int n, int p, int q) {
    int* max = std::max_element(denominaciones, denominaciones + n);
    int cambio_total = q - p;
    int cambio = 0;
    int contador = 0;
    
    while (cambio_total > cambio) {
        if (cambio + max[0] <= cambio_total) {
            cambio += max[0];
            contador++;
        } else {
            std::cout << "Moneda: " << max[0] << " -> Cantidad: " << contador << std::endl;
            int* new_denominaciones = new int[n - 1];
            int new_n = 0;
            contador = 0;
            
            for (int i = 0; i < n; ++i) {
                if (denominaciones[i] != max[0]) {
                    new_denominaciones[new_n++] = denominaciones[i];
                }
            }

            delete[] denominaciones; 
            denominaciones = new_denominaciones;  
            n = new_n;
            max = std::max_element(denominaciones, denominaciones + n);
        }
    }
    if (contador > 0) {
        std::cout << "Moneda: " << max[0] << " -> Cantidad: " << contador << std::endl;
    }

    return 0;
}

// Main function

int main() {
    std::cout << "Numero de denominaciones" << std::endl;
    int n; // Numero de denominaciones (tamaño del arreglo)
    std::cin >> n;
    int* denominaciones = new int[n]; // Arreglo de denominaciones
    std::cout << "Denominaciones " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> denominaciones[i];
    }
    std::cout << "Precio" << std::endl;
    int p; // Precio del producto
    std::cin >> p;
    std::cout << "Cantidad a cambiar" << std::endl;
    int q; // Cantidad a cambiar (billete con el que pago)
    std::cin >> q;

    if(p > q){
        std::cout << "Cantidad insuficiente" << std::endl;
        return -1;
    }

    std::cout << "Cambio Dinamico" << std::endl;
    cambioDinamico(denominaciones,n,p,q);

    std::cout << "Cambio Avaro" << std::endl;
    cambioAvaro(denominaciones, n, p, q);


    delete [] denominaciones; 
    return 0;
}
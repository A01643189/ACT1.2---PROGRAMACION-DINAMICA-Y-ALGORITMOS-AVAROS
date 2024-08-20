#include <iostream>
#include <algorithm>

// Francisco Javier Romo Juarez A01643189
// Diego Enrique Vargas Ramírez A01635782

// Cambio de monedas

 

// Algoritmo Dinámico

int cambioDinamico(int denominaciones[], int p, int q) {

    int cambio = q-p;
    int restante = cambio;
    int F[cambio];
    F[0] = 0;

    int usados[cambio];
    
    for (int i = 0; i <= sizeof(denominaciones); i++){
        for(int i = 1; i <= sizeof(F); i++){
             if(cambio <= denominaciones[i]){
                continue;
             }
        }
    }
    
}

// Algoritmo Avaro

int cambioAvaro(int* denominaciones, int n, int p, int q) {
    int* max = std::max_element(denominaciones, denominaciones + n);
    int cambio_total = q - p;
    int cambio = 0;
    
    while (cambio_total > cambio) {
        if (cambio + max[0] <= cambio_total) {
            cambio += max[0];
            std::cout << max[0] << std::endl;
        } else {
            int* new_denominaciones = new int[n - 1];
            int new_n = 0;
            
            for (int i = 0; i < n; ++i) {
                if (denominaciones[i] != max[0]) {
                    new_denominaciones[new_n++] = denominaciones[i];
                }
            }

            delete[] denominaciones;  // Free the old array memory
            denominaciones = new_denominaciones;  // Point to the new array
            n = new_n;
            max = std::max_element(denominaciones, denominaciones + n);
        }
    }

    return cambio;
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

    cambioAvaro(denominaciones, n, p, q);

    delete [] denominaciones; 
    return 0;
}
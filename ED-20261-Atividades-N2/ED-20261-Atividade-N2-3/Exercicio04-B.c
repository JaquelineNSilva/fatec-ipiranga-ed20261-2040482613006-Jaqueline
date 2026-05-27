//Fatec Ipiranga - Pastor Enéas Tognini
//Professor: Carlos Veríssimo - Estrutura de dados
//RA: 2040482613006 - Jaqueline Neves da Silva
//Atividade Final N2-3 - Exercício 4 - B


#include <stdio.h>

int chamadasRapida = 0;
int chamadasIngenua = 0;

// Calcula base^exp de forma eficiente dividindo o problema pela metade.
// Caso base: qualquer numero elevado a 0 eh 1.
// Caso recursivo: divide o expoente pela metade (par ou impar).
// Complexidade: O(log exp)
long long potenciaRapida(long long base, int exp) {
    chamadasRapida++;

    if (exp == 0)
        return 1;

    long long metade = potenciaRapida(base, exp / 2);

    if (exp % 2 == 0)
        return metade * metade;
    else
        return metade * metade * base;
}

// Versao ingenua: subtrai 1 do expoente a cada chamada.
// Caso base: exp == 0 retorna 1.
// Caso recursivo: b^n = b * b^(n-1)
// Complexidade: O(n)
long long potenciaIngenua(long long base, int exp) {
    chamadasIngenua++;

    if (exp == 0)
        return 1;

    return base * potenciaIngenua(base, exp - 1);
}

int main() {
    long long resultado;

    // 2^10
    chamadasRapida = 0; 
    chamadasIngenua = 0;
    resultado = potenciaRapida(2, 10);
    potenciaIngenua(2, 10);
    printf("\n 2^10 = %lld\n Rapida: %d chamadas\n Ingenua: %d chamadas\n",
           resultado, chamadasRapida, chamadasIngenua);
    printf("----------------------\n");       

    // 3^7
    chamadasRapida = 0; 
    chamadasIngenua = 0;
    resultado = potenciaRapida(3, 7);
    potenciaIngenua(3, 7);
    printf(" 3^7  = %lld\n Rapida: %d chamadas\n Ingenua: %d chamadas\n",
           resultado, chamadasRapida, chamadasIngenua);
    printf("----------------------\n");

    // 5^0
    chamadasRapida = 0; 
    chamadasIngenua = 0;
    resultado = potenciaRapida(5, 0);
    potenciaIngenua(5, 0);
    printf(" 5^0  = %lld\n Rapida: %d chamada\n Ingenua: %d chamada\n", resultado, chamadasRapida, chamadasIngenua);
    printf("----------------------\n");
    
    // 7^12
    chamadasRapida = 0; 
    chamadasIngenua = 0;
    resultado = potenciaRapida(7, 12);
    potenciaIngenua(7, 12);
    printf(" 7^12 = %lld\n Rapida: %d chamadas\n Ingenua: %d chamadas\n", resultado, chamadasRapida, chamadasIngenua);
    printf("----------------------\n");       

    // A diferenca de chamadas fica clara especialmente em expoentes grandes.
    // Na versao rapida o expoente e dividido pela metade a cada nivel,
    // enquanto na ingenua diminui 1 por vez — por isso a diferenca cresce
    // bastante conforme o expoente aumenta (7^12: 5 vs 13 chamadas).

    return 0;
}
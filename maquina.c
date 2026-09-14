#include <stdio.h>


int main()
{
    char produtos[8][30] = {
        "Coca", "Guarana", "Pepsi", "Agua", "Doritos", "Batata Chips", "Barra de chocolate", "Red Bull"};
    int quantidade[8] = {
        9,5,2,5,10,5,12,7};
    int preco[8] = {
        6,5,6,3,7,5,4,8};
    
    for(int i = 0;i<8;i++)
    {
        printf("produto: %s | preço: R$%d | quantidade: %d |\n", produtos[i], preco[i], quantidade[i]);
    }
return 0;
}
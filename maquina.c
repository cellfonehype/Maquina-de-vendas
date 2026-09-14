#include <stdio.h>


int main()
{
    //layout da maquina de vendas
    char produtos[8][30] = {
        "1-Coca", "2-Guarana", "3-Pepsi", "4-Agua", "5-Doritos", "6-Batata Chips", "7-Barra de chocolate", "8-Red Bull"};
    int quantidade[8] = {
        9,2,2,5,10,5,12,7};
    int preco[8] = {
        6,5,6,3,7,5,4,8};

    //sistema de compra
    int opcao;
    

    printf("Bem vindo\nDigite oque vc deseja:\n");
    for(int i = 0;i<8;i++)
    {
        printf("produto: %s      | preço: R$%d |      quantidade: %d |\n", produtos[i], preco[i], quantidade[i]);

    }


    do{
        scanf("%d", &opcao);
        
        if(opcao <= -1)
        {
            printf("vc saiu ate a proxima!!");
            break;
        }
        opcao--;
        if(opcao >= 0 && opcao < 8 && quantidade[opcao] != 0)
        {
            printf("vc escolheu: %s | R$:%d",produtos[opcao], preco[opcao]);

        }

    }while(1);


return 0;
}
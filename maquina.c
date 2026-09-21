#include <stdio.h>

void linha(void){
    printf("==============================================================\n");
}
void painel(char produtos[][30],int preco[], int quantidade[])
{   
    linha();
        printf("                        !!BEM VINDO A LOJA!!\n");
        printf("                       DIGITE OQUE VC PRECISA\n:");
    linha();
    for(int i = 0;i<8;i++)
    {
        printf("produto: %-15s | preço: R$%-2d |      quantidade: %-2d |\n",
             produtos[i],           preco[i],          quantidade[i]);
    
    }

}
int transacao(int preco[], int quantidade[], int opcao, int valor_pago)
{
    int troco,quitacao,escolha;
    int falta, cont;

    do{
    if (valor_pago >= preco[opcao])
    {
        quantidade[opcao] --;
        troco = valor_pago - preco[opcao];
        linha();
        printf("Compra feita com sucesso\nValor do seu troco R$%d\n",troco);
        linha();

        return 1;
    }
    else
    {   

        falta = preco[opcao] - valor_pago;
        printf("Compra recusada\nFalta R$%d\n",falta);
        linha();
        printf("vc dejesa completar o valor:\n1-sim\n2-não\n");
        scanf("%d", &escolha);
        if(escolha == 2)
        {
            printf("que pena\nvolte sempre!!");
            break;
        }
        else if (escolha == 1)
        {
            linha();
            printf("Quanto deseja colocar,\n falta R$%d",falta);
            scanf("%d", quitacao);
            
            cont = falta - quitacao;

            if(cont >= preco[opcao])
            {
                quantidade[opcao]--;
                printf("compra realizada\nParabens!!\n");
            }
            else if(cont < preco[opcao])
            {
                continue;
            }

        }
    }
        return 0;
    }while(valor_pago >= preco[opcao]);
    
}
/*int transacao_negada(int preco[], int quantidade[], int opcao, int valor_pago)
{
    int quitacao,escolha;
    printf("Vc deseja pagar o restante:\n1-sim\n-2-não");
    scanf("%d", &escolha);

    if (escolha == 2)
    {
        printf("Que pena volte sempre\n");
    }
    else if(escolha == 1)
    {   
        do{
        printf("Quanto vc deseja adicionar:");
        scanf("%d", &quitacao);

        valor_pago = 

        }while(valor_pago >= preco[opcao]);
    }



*/




int main()
{
    //layout da maquina de vendas
    char produtos[8][30] = {
        "1-Coca", "2-Guarana", "3-Pepsi", "4-Agua", "5-Doritos", "6-Chips", "7-chocolate", "8-Red Bull"};
    int quantidade[8] = {
        9,2,2,5,10,5,12,7};
    int preco[8] = {
        6,5,6,3,7,5,4,8};

    //sistema de compra
    int opcao,pagamento;
    
    

    do{
        painel(produtos,preco,quantidade);
        printf("Escolha: ");
        scanf("%d", &opcao);
        opcao--;
        if(opcao <= -1)
        {
            printf("vc saiu ate a proxima!!");
            break;
        }
        if(opcao >= 0 && opcao < 8 && quantidade[opcao] != 0)
        {
            printf("vc escolheu: %s | R$:%d\n",produtos[opcao], preco[opcao]);
            printf("Deposite o valor:");
            scanf("%d", &pagamento);

            int resultado_pagamento = transacao(preco,quantidade,opcao,pagamento);

        }
        else if(opcao >= 0 && opcao < 8 && quantidade[opcao] == 0)
        {
            printf("Esse item esta fora de estoque\nEscolha outro ou saia com 0");
            continue;
        }


    }while(1);
printf("vc saiu ate a proxima!!");

return 0;
}

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
    int falta;

    do{
    if (valor_pago >= preco[opcao])
    {
        quantidade[opcao] --;
        troco = valor_pago - preco[opcao];
        linha();
        printf("Compra feita com sucesso\nValor do seu troco R$%d\n",troco);
        linha();

    }
    else
    {   

        falta = preco[opcao] - valor_pago;
        printf("Compra recusada\nFalta R$%d\n",falta);
        linha();
        printf("vc dejesa completar o valor:\n1-sim\n2-não\n");
        scanf("%d", &escolha);
        linha();
        if(escolha == 2)
        {
            printf("que pena\nvolte sempre!!\n");
            return 2;
            break;
        }
        else if (escolha == 1)
        {
            linha();
            printf("Quanto deseja colocar,\nfalta R$%d\n",falta);
            scanf("%d", &quitacao);
            
            valor_pago = valor_pago + quitacao;

            if(valor_pago >= preco[opcao])
            {

                troco = valor_pago-preco[opcao];
                quantidade[opcao]--;
                printf("compra realizada\nParabens!!\nVc recebeu R$%d\n",troco);
                break;
            }
            else if(valor_pago < preco[opcao])
            {
                continue;
            }
            

        }
        else
        {
            printf("opção invalida!!\n");
        }
    }
    }while(valor_pago < preco[opcao]);
    return 0;
}





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

            if(resultado_pagamento == 2)
            {
                break;
            }
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

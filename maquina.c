#include <stdio.h>

linha(void){
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
    int opcao,pagamento,troco,denovo;
    int reinterar, pagadivid;
    
    painel(produtos,preco,quantidade);

    do{
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

                if(pagamento >= preco[opcao])
                {   
                    quantidade[opcao]--;
                    troco = pagamento - preco[opcao];
                    printf("Deposito aceito!!\nVc recebeu R$:%d de troco\n",troco);

                }
                else if(pagamento < preco[opcao])
                {
                    troco = preco[opcao] - pagamento;
                    printf("Dinheiro insuficiente!!\nfalta R$%d\n", troco);
                        do{
                    printf("vc deseja colocar mais dinheiro:\n1-sim\n2-não\n");
                    scanf("%d", &reinterar);

                    if (reinterar == 1)
                    {   
                        
                        printf("falta R$%d quanto vc vai colocar:\n", troco);
                        scanf("%d", &pagadivid);
                        troco = troco - pagadivid;
                      
                        
                        if (troco >= 1)
                        {
                        printf("ainda esta faltando R$%d ", troco);
                        continue;
                        }



                    }

                    if (pagadivid >= troco )
                    {
                        troco = troco * -1;
                        printf("pagamento concluido pegue sue item!!\nvc recebeu R$%d de troco\n ", troco);
                        
                    }
                        }while(troco <= 0);
                     


                }

                printf("deseja comprar denovo:\n1-sim\n2-não\n");
                scanf("%d", &denovo);


                if(denovo == 1)
                {
                        for(int i = 0;i<8;i++)
                        {
                        printf("produto: %s      | preço: R$%d |      quantidade: %d |\n", produtos[i], preco[i], quantidade[i]);
                            continue;
                        }
                }
                else
                {
                    break;
                }
        }
        else if(quantidade[opcao] == 0 )
        {
            printf("Esse item esta fora de estoque\nEscolha outro ou saia com 0");
            continue;
        }


    }while(1);
printf("vc saiu ate a proxima!!");

return 0;
}
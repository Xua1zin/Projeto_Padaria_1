#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //i=item, q=quantidade, mp=modo de pagamento, a=acrescimo, c=compra, d=desconto, vt=valor total, vp=valor pago, vm=valor mensal, p=parcela, vtp=valor total pago, t=troco.;

    int i, q, mp;
    float a, c = 0, d, vt, vp, vm, p = 0, vtp, t;

    do
    {
        printf("Lista:\n   C�DIGO    |        NOME        |   PRE�O\n      1         P�o de forma         R$7.50\n      2         P�o de centeio       R$8.69\n      3         Broa de milho        R$5.00\n      4         Sonho                R$4.50\n      5         Tuba�na              R$3.25\n");

        printf("\nSelecione o c�digo do item: ");
        scanf("%d", &i);

        switch (i)
        {

            case 1:
                printf("Selecionado: P�o de forma\n");
                c = 7.50;
                break;

            case 2:
                printf("Selecionado: P�o de centeio\n");
                c = 8.69;
                break;

            case 3:
                printf("Selecionado: Broa de milho\n");
                c = 5.00;
                break;

            case 4:
                printf("Selecionado: Sonho\n");
                c = 4.50;
                break;

            case 5:
                printf("Selecionado: Tuba�na\n");
                c = 3.25;
                break;

            default:
                c = 0;
                printf("\nC�digo inv�lido\n\n");
        }
    }
    while(c < 1);

        printf("\nSelecione a quantidade: ");
        scanf("%d", &q);

        vt = c * q;

        printf("\nValor total da compra: %.2f\n", vt);

        do
        {
        printf("\n� vista: 1\nA prazo: 2\nEscolha a forma de pagamento: ");
        scanf("%d", &mp);

        if (mp == 1)
        {
            printf("Pagamento � vista\n");

            if (vt <= 50)
            {
                printf ("\nDesconto de 5%%\n");
                d = vt * 0.05;
                p = 2;
            }

            else if ((vt > 50) && (vt < 100))
            {
                printf ("Desconto de 10%%\n");
                d = vt * 0.1;
                p = 3;
            }

            else
            {
                printf ("Desconto de 18%%\n");
                d = vt * 0.18;
                p = 3;
            }
            vp = vt - d;
            printf("Valor total: %.2f\n", vp);

            printf("\nDigite o valor pago: ");
            scanf("%f", &vtp);
            t = vtp - vp;
        }

        else if (mp == 2)
        {
            printf("Pagamento a prazo\n");
            printf("\nDigite quantas parcelas: ");
            scanf("%f", &p);

            if ((p != 1) && (p <= 3))
            {
                printf ("Acr�scimo de 5%%\n");
                a = vt * 0.05;
            }

            else if (p > 3)
            {
                printf ("Acr�scimo de 8%%\n");
                a = vt * 0.08;
            }
            else
            {
                printf("\nEnt�o � � vista\n");
            }
            if (p > 1)
            {
            vp = vt + a;
            vm = vp / p;

            printf ("\nValor total: %.2f\n", vp);
            printf ("Valor parcela: %.2f\n", vm);

            printf ("\nDigite o valor pago: ");
            scanf ("%f", &vtp);

            t = vtp - vm;
            }
        }
        else
        {
            printf("\nC�digo inv�lido\n");
        }
        }
        while(p < 2);
        if (t >= 0)
        {
            printf("\nTroco: %.2f\n", t);
            printf("\nCompra finalizada\n");
        }
        else
        {
            printf("\nValor insuficiente\n\nCompra cancelada\n");
        }
    return 0;
}

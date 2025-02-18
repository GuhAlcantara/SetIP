#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opcao;

    printf("Bem vindos(as)\n");
    printf("-----------------\n");

    do
    {
        printf("Escolha a opcao que deseja:\n");
        printf("1. Setar IP Estatico (USAR NA REDE *x*)\n"); // x = Nome da Rede do trabalho
        printf("2. Resetar IP Dinamico (usar FORA do Trabalho)\n");
        printf("3. Saiba Mais.\n");
        printf("4. Sair.\n");
        printf("Digite: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // name="Nome da Conexão" static [IP] [Máscara de Sub-rede] [Gateway Padrão]
            //  Foi escolhido xxx.xxx.x.120 pela cliente
            system("netsh interface ip set address name=Wi-Fi static 192.168.2.120 255.255.255.0 192.168.2.1");

            // Resultado para a cliente
            printf("interface = Wi-Fi\n");       // Nome da interface (verifique com "netsh interface show interface")
            printf("ip = 192.168.2.120\n");      // Endereço IP configurado
            printf("Netmask = 255.255.255.0\n"); // Máscara de rede configurado
            printf("gateway = 192.168.2.1\n");   // Gateway padrão
            printf("dns = 8.8.8.8\n");           // Servidor DNS (ex: Google DNS)

            printf("IP estatico configurado com sucesso!\n\n");

            break;

        case 2:

            system("netsh interface ip set address name=Wi-Fi dhcp"); // Volta o IP para dinamico
            system("netsh interface ip set dns name=Wi-fi dhcp");     // Volta o DNS para dinamico

            // Resultado para a cliente
            printf("IP dinamico configurado com sucesso!\n\n");

            break;

        case 3:
            printf("\nOpcao 3 : Saiba Mais \n -------------------- \n");
            printf("Para entender melhor como o programa funciona\n");
            printf("\nOpcao 1 - IP Estatico: O programa configura seu PC para usar um IP fixo, garantindo que ele sempre tenha o mesmo endereco de rede. Isso e util para servidores, acesso remoto e dispositivos que precisam de um IP constante.\n");
            printf("\nOpcaoo 2 - IP Dinamico (Padrao de Fabrica): O programa retorna seu PC a configuracao original, permitindo que o roteador atribua um IP automaticamente. Isso e ideal para redes domesticas e uso comum, garantindo maior flexibilidade.\n");

            break;

        case 4:
            printf("Saindo...");

            break;

        default:

            printf("Opcao invalida , Tente novamente\n\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}
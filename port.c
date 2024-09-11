#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h> // Para utilizar strerror

int main(int argc, char *argv[]) {
    int meusocket;
    int porta;
    int inicio = 0;
    int final = 65535;
    char *destino;
    destino = argv[1];

    struct sockaddr_in alvo;

    // Criar o socket
    meusocket = socket(AF_INET, SOCK_STREAM, 0);
    if (meusocket == -1) {
        perror("socket");
        return 1;
    }

    // Configurar a estrutura sockaddr_in
    alvo.sin_family = AF_INET;
    alvo.sin_addr.s_addr = inet_addr(destino);

    // Varrer as portas
    for (porta = inicio; porta < final; porta++) {
        alvo.sin_port = htons(porta);

        // Tentar conectar
        if (connect(meusocket, (struct sockaddr*)&alvo, sizeof alvo) == 0) {
            printf("Porta %d - status [ABERTA] \n", porta);
        } else {
            printf("Falha ao conectar à porta %d: %s\n", porta, strerror(errno));
        }
    }

    // Fechar o socket
    close(meusocket);
    return 0;
}

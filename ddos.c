#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h> // Para utilizar strerror
#include <unistd.h> // Para utilizar close
#include <time.h>   // Para utilizar sleep

int main(int argc, char *argv[]) {
    int meusocket;
    int porta = 21; // Definindo a porta que deseja atacar
    const char *destino = "127.0.0.1"; // Definindo o endereço IP do destino, por exemplo, localhost

    struct sockaddr_in alvo;

    while (1) { // Loop infinito
        // Criar o socket
        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        if (meusocket == -1) {
            perror("socket");
            return 1;
        }

        // Configurar a estrutura sockaddr_in
        memset(&alvo, 0, sizeof(alvo)); // Limpar a estrutura antes de configurar
        alvo.sin_family = AF_INET;
        alvo.sin_addr.s_addr = inet_addr(destino);
        alvo.sin_port = htons(porta); // Converter a porta para a rede byte order

        // Tentar conectar
        if (connect(meusocket, (struct sockaddr*)&alvo, sizeof(alvo)) == 0) {
            printf("Porta %d - status [ATACANDO] \n", porta);
        } else {
            printf("Falha ao conectar à porta %d: %s\n", porta, strerror(errno));
        }

        // Pausar por 2 segundos antes de tentar novamente
        sleep(2);
    }

    return 0; // Embora esse ponto nunca seja alcançado
}

#include "get_next_line.h"

char *get_next_line(int fd)
{
    size_t  bits;
    bits = 3;
    char buffer[1024];
    int line_len = 0;
    char    *line;
    // int read(int fileDescriptor, void *buffer, size_t bytesToRead);
    int bytesRead = read(fd, buffer, bits);

    int newline_pos = find_newline(buffer, bytesRead);
    if(bytesRead == -1 || bits <= 0) {
        free(buffer)
        return NULL;
    }

    line = malloc(newline_pos+1);

    // printf("%d",bytesRead);
    // printf("%s",buffer);

    // buffer[bytesRead] = '\0';

    for (int i = 0; i < newline_pos; i++) {
        line[line_len+1] = buffer[i];
    }
    line[line_len + newline_pos] = '\0';

    return line;
    

    
}

int find_newline(char *buffer, int len)
{
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '\n')
            return i;
    }
    return -1;
}

int main()
{
    int fd = open("nome_do_arquivo.txt", O_RDONLY);
    char *linha = get_next_line(fd);
    if (linha != NULL) {
        printf("Linha lida: %s\n", linha);
        free(linha); // Libera a memória
    }

    close(fd);
}
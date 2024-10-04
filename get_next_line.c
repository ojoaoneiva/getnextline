#include "get_next_line.h"

char *get_next_line(int fd)
{
    size_t  bits;
    bits = 3;
    char buffer[1024];
    // int read(int fileDescriptor, void *buffer, size_t bytesToRead);
    int bytesRead = read(fd, buffer, bits);
    printf("%d",bytesRead);
    printf("%s",buffer);
}

int main()
{
    
}
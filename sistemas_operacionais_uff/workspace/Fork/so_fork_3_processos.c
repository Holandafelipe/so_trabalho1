#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    char c = 'x';
    pid_t pid = fork(); //essa variável receberá uma espécie de identificador o processo, uma espécie de ID
                        //Caso o retorno seja negativo, significa que algo deu erro
                        //Caso recebamos "0" significa que estamos no processo filho
                        //Caso recebamos outro valor, significa que estamos no processo pai, e esse valor é o ID do processo
    
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        printf("Caractere: %c e Endereco: %p (filho)\n",c,&c);
        
        char s = 'w';
        pid_t pid2 = fork(); 
        
        if (pid2 < 0)
        {
            perror("fork");
            exit(1);
        }
        
        if (pid2 == 0)
        {
            printf("Caractere: %c e Endereco: %p (filho do filho)\n",s,&s);
        }
        
        else
        {
            s = 'q';
            printf("Caractere: %c e Endereco: %p (filho do pai)\n",s,&s);
        }
        
        
    }
    else
    {
        c = 'z';
        printf("Caractere: %c e Endereco: %p (pai)\n",c,&c);
    }
    return 0; 
}

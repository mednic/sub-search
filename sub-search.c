#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// program banner
void banner
()
{

    system("clear");


    printf("███████╗██╗   ██╗██████╗       ███████╗███████╗ █████╗ ██████╗  ██████╗██╗  ██╗    ██████╗\n");
    printf("██╔════╝██║   ██║██╔══██╗      ██╔════╝██╔════╝██╔══██╗██╔══██╗██╔════╝██║  ██║   ██╔════╝\n");
    printf("███████╗██║   ██║██████╔╝█████╗███████╗█████╗  ███████║██████╔╝██║     ███████║   ██║     \n");
    printf("╚════██║██║   ██║██╔══██╗╚════╝╚════██║██╔══╝  ██╔══██║██╔══██╗██║     ██╔══██║   ██║     \n");
    printf("███████║╚██████╔╝██████╔╝      ███████║███████╗██║  ██║██║  ██║╚██████╗██║  ██║██╗╚██████╗\n");
    printf("╚══════╝ ╚═════╝ ╚═════╝       ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝ ╚═════╝\r\n");
    printf("by: \n");
    printf("   https://github.com/mednic\n");
    printf("   https://github.com/Un1c-sys\n");

}

// main function
int main
(int argc, char *argv[])
{

    // Domain
    char *domain;
    domain = argv[1];

    // List
    char *lista;
    lista = argv[2];

    // Output text 
    char txt[50];

    // Files

    FILE *words;// wordlist words
    
    FILE *outputFile = NULL;// final file

    if(argc < 2)// without enough arguments 
    {

        banner();

	    sleep(0.87);
	    
        printf("\r\n[+] ERROR \n");
        printf("[+] Use: ./sub-search domain dns.txt\n");

        return 0;

    }
    else
    {
        // open wordlist
        words = fopen(lista, "r");

        // create/open the output file
        outputFile = fopen("output.txt", "w");

        if(words == NULL){

            banner();

	        sleep(0.87);
            
            printf("\n[+] Wordlist not found !\n");
            
            return 0;

        }
        else
        {
            banner();

            struct hostent *host;

            char *resu, *outpString;

	        sleep(0.87);
            
            printf("\r\n\t+===========================+\n");
            printf("\t         TESTING...             \n");
            printf("\t+===========================+\n");

	        sleep(1);
            
            printf("\r\n\t\t[HOSTS Found] \r\n\n");

            while(fscanf(words, "%s", *(&txt)) != EOF)
            {

                resu = (char *) strcat(txt,domain);
                
                host = gethostbyname(resu);

                if(host == NULL)
                    continue;
                
                printf("[+]     %s      -      %s \n", resu, inet_ntoa(*((struct in_addr *)host -> h_addr)));
                
                outpString = (char *) strcat(resu,"   -   ");
                outpString = (char *) strcat(outpString,inet_ntoa(*((struct in_addr *)host -> h_addr)));
                outpString = (char *) strcat(outpString,"\n");

                fputs(outpString, outputFile);


            }

            fclose(outputFile);

        } 
    
    }
    
}



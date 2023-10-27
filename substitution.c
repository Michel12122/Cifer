#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
    if (argc != 2 || argv[1] == NULL )
    {
        printf("./substitution key\n"); // Uso incorrecto
        return 1;
    }

    string input_key = argv[1];
    int log_key = strlen(input_key);

    if(log_key < 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string palabras = get_string("plaintext: ");
    int palabras_len = strlen(palabras);
    char abc[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char abc_min[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char caracteres_esp[3] = {' ', ','};

    char cifer[palabras_len]; // Convierto a char el abecedario
    int cifer_len = 0;

    int i = 0, j = 0, h = 0;

    while (abc[i] != '\0' && abc_min[i] != '\0' && cifer_len < palabras_len)
    {
        for(h = 0; h < caracteres_esp[h];h++){
            if (palabras[j] == caracteres_esp[h]){
                cifer[j] = caracteres_esp[h];
                j++;
            }
        }

        if (isupper(input_key[i]))
            {
                if (abc[i] == palabras[j])
                {
                    cifer[j] = input_key[i];
                    j++;
                    i = 0; // Reiniciar el contador de la clave si se llega al final
                }
            }
            if (isupper(input_key[i]) && (abc_min[i] == palabras[j]))
            {
                cifer[j] = tolower(input_key[i]);
                j++;
                i = 0; // Reiniciar el contador de la clave si se llega al final
            }
            i++;
            cifer_len = j;
        }

    cifer[j] = '\0'; // Terminar la cadena con un carácter nulo
    printf("ciphertext: %s\n", cifer);

    return 0;
}

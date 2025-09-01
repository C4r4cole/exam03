#include <stdio.h>   
#include <string.h> 
#include <unistd.h>  
#include <stdlib.h>  

#define MAX_INPUT_BUFFER_SIZE (10000 + 1)

int ft_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] == s2[i]) {
        i++;
    }
    if (i == n) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv)
{
	char *buff = (char *)malloc(MAX_INPUT_BUFFER_SIZE);
	char *search_str = argv[1];           
	char current_char;                  
	ssize_t bytes_read_result;          
	int buff_idx = 0;                   
	int search_len = strlen(search_str); 
	int process_idx = 0;

	if (argc != 2 || argv[1] == NULL || strlen(argv[1]) == 0) {
        return 1;
    }
    if (buff == NULL) {
        fprintf(stderr, "Error: "); 
        perror("");
        return 1;
    }
    while ((bytes_read_result = read(STDIN_FILENO, &current_char, 1)) > 0) {
        if (buff_idx >= MAX_INPUT_BUFFER_SIZE - 1) {
            break; 
        }
        buff[buff_idx++] = current_char;
    }
    if (bytes_read_result == -1) {
        fprintf(stderr, "Error: "); 
        perror("");                 
        free(buff);                 
        return 1;                   
    }
    buff[buff_idx] = '\0';
    while (buff[process_idx] != '\0') { 
        if (process_idx + search_len <= buff_idx &&
            ft_strncmp(&buff[process_idx], search_str, search_len) == 1)
        {
            for (int y = 0; y < search_len; y++) {
                write(STDOUT_FILENO, "*", 1); // write one '*' at a time.
            }
            process_idx += search_len;
        } else {
            write(STDOUT_FILENO, &buff[process_idx], 1);
            process_idx++;
        }
    }
    free(buff);
    return 0;
}
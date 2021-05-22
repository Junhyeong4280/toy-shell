#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LEN_LINE    100

int main(void)
{
    char command[MAX_LEN_LINE];
    char *args[] = {command, NULL};
    int ret, status;
    pid_t pid, cpid;
    
    while (true) {
        char *s;
        int len;
        
        printf("Myshell file name\n(ex: calculator,iteminventor,oedistributor) :  ");
        s = fgets(command, MAX_LEN_LINE, stdin);
        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        
        len = strlen(command);
        printf("The number of strings in the file name is %d, so this is a viable situation. Run it.\n", len);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }
        
        printf("Name of file to run : [%s]\n", command);
      
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
            if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
            }
            printf("Child process terminated\n");
            if (WIFEXITED(status)) {
                printf("Exit status is %d\n", WEXITSTATUS(status)); 	
            return 0;
	     
	     	    }
        }
        else {  /* child */
            ret = execve(args[0], args, NULL);
            if (ret < 0) {
                fprintf(stderr, "execve failed\n");   
                return 1;
            }
        } 
    }
    return 0;

}

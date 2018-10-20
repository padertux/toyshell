#include <stdlib.h>
#include "stdio.h"
#include "string"
#include "iostream"
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


char *trimwhitespace(char *str)
{
	  char *end;

	  //Trim leading space
	  while(isspace((unsigned char)*str)) str++;
	    
	  if(*str == 0)  // All spaces?
	         return str;
	    
	  // Trim trailing space
	  end = str + strlen(str) - 1;
	  while(end > str && isspace((unsigned char)*end)) end--;
	    
	  // Write new null terminator
	  *(end+1) = 0;
	    
	  return str;
}


int main()
{
	char* input, shell_prompt[100];

	// Create prompt string from user name and current working directory.
	snprintf(shell_prompt, sizeof(shell_prompt), "\x1B[32m%s:%s$ \x1B[0m", getenv("USER"), getcwd(NULL, 1024)); 

	while(true)
	{
	rl_bind_key('\t', rl_complete);

	input = readline(shell_prompt); //todo: free input
	add_history(input);

	pid_t pid = fork();
	if(pid > 0) 	//parent process
	{
		waitpid(pid, NULL, 0);
		//printf("parent\n");
	}
	else		//child process
	{
		//printf("child\n");
		char *const paramList[] = {"", NULL};
		execvp(trimwhitespace(input), paramList);
		fflush(NULL);
	}

	}

	return 0;
}

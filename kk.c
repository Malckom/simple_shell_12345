/*
 * #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
*/
#include "main.h"

void update_pwd(void) {
	    char cwd[PATH_MAX];
	        if (getcwd(cwd, sizeof(cwd)) != NULL) {
			        setenv("PWD", cwd, 1);
				    } else {
					            perror("getcwd");
						        }
}

int change_directory(const char *new_dir) {
	    if (new_dir == NULL) {
		            new_dir = getenv("HOME");
			            if (new_dir == NULL) {
					                fprintf(stderr, "cd: HOME not set\n");
							            return 1;
								            }
				        } else if (strcmp(new_dir, "-") == 0) {
						        const char *old_dir = getenv("OLDPWD");
							        if (old_dir == NULL) {
									            fprintf(stderr, "cd: OLDPWD not set\n");
										                return 1;
												        }
								        new_dir = old_dir;
									    }

	        if (chdir(new_dir) == -1) {
			        perror("cd");
				        return 1;
					    }

		    update_pwd();
		        setenv("OLDPWD", getenv("PWD"), 1);

			    return 0;
}
/*
int main(int argc, char *argv[]) {
	    if (argc == 1) {
		            return change_directory(NULL);
			        } else if (argc == 2) {
					        return change_directory(argv[1]);
						    } else {
							            fprintf(stderr, "Usage: %s [DIRECTORY]\n", argv[0]);
								            return 1;
									        }
}
*/

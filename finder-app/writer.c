#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Open the syslog connection
    openlog("writer", LOG_CONS | LOG_PID, LOG_USER);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <string_write>\n", argv[0]);
        closelog();

        return 1;
    }

    const char *filename = argv[1];
    const char *string_write = argv[2];
    
    

    FILE *file=fopen(filename, "w");
    if (file ==NULL) {
        syslog(LOG_ERR, "Error opening file: %s", filename);
    	perror("errror in opening file");
        closelog();

    	return 1;
    }

    if(fprintf(file,"%s\n",string_write )<0){
        syslog(LOG_ERR, "Error writing to file: %s", filename);
    	perror("Error writing to file");
        fclose(file);
        closelog();

        return 1;
    
    }
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", string_write, filename);
    closelog();

    return 0;
}

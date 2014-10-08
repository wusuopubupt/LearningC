/*
 * Reference : http://blog.csdn.net/wusuopubupt/article/details/36428063
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void write_log(char *log_str) {
    FILE *file;
    file = fopen("/tmp/daemon_test.log","a+");   //  attention: dir is "/tmp" !!!

    char time_buff[20];
    struct tm *sTm;
    time_t now  = time(0);
    sTm = gmtime(&now);
    strftime(time_buff, sizeof(time_buff), "%Y-%m-%d %H:%M:%S", sTm);

    fprintf(file,"%s %s\n",time_buff, log_str); /*writes*/
    fclose(file);
}

void demonize(const char* path)
{
    /* Our process ID and Session ID */
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }

    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0)
    {
        FILE *file = fopen(path, "w");
        if (file == NULL)
            printf("Invalid pid file\n");

        fprintf(file, "%d", pid);
        fclose(file);
        printf("forked, exiting...\n");
        exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);

    /* Open any logs here */

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0)
    {
        /* Log the failure */
        exit(EXIT_FAILURE);
    }

    /* Change the current working directory */
    if ((chdir("/tmp")) < 0)
    {
        /* Log the failure */
        exit(EXIT_FAILURE);
    }

    /* Close out the standard file descriptors */
    //close(STDIN_FILENO);
    //close(STDOUT_FILENO);
    //close(STDERR_FILENO);
    close(0);
    close(1);
    close(2);

    while(1) {
    	// Do something here...
        write_log("test");
        sleep(2);
    }
}

int main() {
    demonize("/tmp/test.pid");

    return 0;
}

#include "_public.h"

CLogFile logfile(10);

int main(int argc, char *argv[])
{
    // inifile outpath logfile
    if (argc != 4)
    {
        printf("Using:./crtsurfdata1 inifile outpath logfile\n");
        return -1;
    }

    if (logfile.Open(argv[3]) == false)
    {
        printf("logfile.Open(%s) failed", argv[3]);
        return -1;
    }

    logfile.Write("crtsurfdata1 starts running. \n");

    // add code here

    logfile.Write("crtsurfdata1 finished running. \n");

    return 0;
}
#include "_public.h"

// Weather station parameters
struct st_stcode
{
    char provname[31]; // province
    char obtid[11];    // station id
    char obtname[31];  // province
    double lat;        // latitude
    double lon;        // longtitude
    double height;     // height
};

// A container for storing weather station parameter data
vector<struct st_stcode> vstcode;

// Load the station parameter data file into the vstcode container
bool LoadSTCode(const char *inifile);

CLogFile logfile(10);

int main(int argc, char *argv[])
{
    // inifile outpath logfile
    if (argc != 4)
    {
        printf("Using:./crtsurfdata inifile outpath logfile\n");
        printf("Example:./crtsurfdata /home/guikai/proj/Data-Center/idc1/ini/stcode.ini /tmp/surfdata log/idc/crtsurfdata.log\n");
        return -1;
    }

    if (logfile.Open(argv[3]) == false)
    {
        printf("logfile.Open(%s) failed. \n", argv[3]);
        return -1;
    }

    logfile.Write("crtsurfdata starts running. \n");

    if (LoadSTCode(argv[1]) == false)
        return -1;

    logfile.WriteEx("crtsurfdata finished running. \n");

    return 0;
}

// Load the station parameter data file into the vstcode container
bool LoadSTCode(const char *inifile)
{
    CFile File;

    if (File.Open(inifile, "r") == false)
    {
        logfile.Write("File.Open(%s) failed.\n", inifile);
        return false;
    }

    char strBuffer[301];

    CCmdStr CmdStr;

    struct st_stcode stcode;

    while (true)
    {
        // read station info from file
        if (File.Fgets(strBuffer, 300, true) == false)
            break;

        // split the string
        CmdStr.SplitToCmd(strBuffer, ",", true);
        // ignore illegal rows
        if (CmdStr.CmdCount() != 6)
            continue;

        // store params into the struct
        CmdStr.GetValue(0, stcode.provname, 30);
        CmdStr.GetValue(1, stcode.obtid, 10);
        CmdStr.GetValue(2, stcode.obtname, 30);
        CmdStr.GetValue(3, &stcode.lat);
        CmdStr.GetValue(4, &stcode.lon);
        CmdStr.GetValue(5, &stcode.height);

        vstcode.push_back(stcode);
    }

    // test the result
    // for (int ii = 0; ii < vstcode.size(); ii++)
    // {
    //     logfile.Write("prov: %s \n", vstcode[ii].provname);
    // }

    return true;
}
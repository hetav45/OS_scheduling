#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{
    int rtime, wtime, ret=-1;

    int pid=fork();

    if(pid == 0) 
    {
        exec(argv[1], argv);
        printf(2, "Exec failed for process %s\n", argv[1]);
        exit();
    }
    else 
    {
        ret = waitx(&wtime, &rtime);
    }
    printf(1, "process %s with id %d\nruntime : %d ticks\nwaitime : %d ticks\n", argv[1], ret, rtime, wtime);
 
    exit();
    return 0;
}
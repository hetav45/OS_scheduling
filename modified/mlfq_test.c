#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "pinfo.h"

int main(void)
{
    struct proc_stat p;
    
    for (int i = 0; i < 1; i++)
    {
        int pid = fork();

        if (pid == 0)
        {
            int flag = 1;
            while (1)
            {
                pinfo(&p);
                printf(1, "process %d with id %d\nruntime : %d ticks\nnum_run : %d\ncurr_q : %d\nticks : %d %d %d %d %d\n", i, p.pid, p.rtime, p.num_run, p.curr_q, p.ticks[0], p.ticks[1], p.ticks[2], p.ticks[3], p.ticks[4]);
                sleep(100);
            }
        }
    }
    while (1)
        ;
}
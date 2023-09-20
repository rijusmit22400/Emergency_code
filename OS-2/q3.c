#include <linux/module.h>     
#include <linux/kernel.h>   
#include <linux/init.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PL4N3T-(optional)");
MODULE_DESCRIPTION("Printing Hello World"); 

int count_running_processes(void)
{
    struct task_struct *task;
    int count = 0;
    for_each_process(task) {
        struct thread_info *info = task_thread_info(task);
        if (info->status == TASK_RUNNING)
            count++;
    }

    return count;
}

static int __init showing_init(void)
{    
    int kek = count_running_processes();
    
    printk(KERN_INFO "Upar Wale ki barkat\n.\n.\n.\n.\n|\n|\n.\n.\n.\n.\nbabji ki booty.");
    printk(KERN_INFO "\n[%d] By this is the number of the running processes glad to help.",kek);
    return 0;
}


static void __exit leaving_cleanup(void)
{
    printk(KERN_INFO "babaji ki jai ho\n.\n.\n.\n.\n|\n|\n.\n.\n.\n.\nJai ho babaji ki.");
}

module_init(showing_init);      
module_exit(leaving_cleanup);   
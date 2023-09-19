#include <linux/module.h>     
#include <linux/kernel.h>   


MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKANKSHA-SINGAL");
MODULE_DESCRIPTION("Printing Hello World"); 


static int __init display_init(void)
{    
    printk(KERN_INFO "Hello World");
    return 0;
}


static void __exit display_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.");
}

module_init(display_init);      
module_exit(display_cleanup);   
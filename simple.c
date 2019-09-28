#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/types.h>
#include<linux/slab.h>
struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
};
static LIST_HEAD(birthday_list);
int simple_init(void){


	int i;
	struct birthday *ptr=NULL;
	for(i=0;i<5;i++){
        	struct birthday *person[i];

        	person[i] = kmalloc(sizeof(*person[i]),GFP_KERNEL);
        	person[i]->day = 2+i;
        	person[i]->month = 8+i;
        	person[i]->year = 1995+i;
        	INIT_LIST_HEAD(&person[i]->list);

        	list_add_tail(&(person[i]->list),&birthday_list);
	}
	list_for_each_entry(ptr,&birthday_list,list){
		printk("day:%d",ptr->day);
		printk("month:%d",ptr->month);
		printk("year:%d",ptr->year);
	}

	printk(KERN_INFO "Loading Module\n");

	return 0;
}
void simple_exit(void){
	  
	struct birthday *ptr=NULL,*next=NULL;
	list_for_each_entry_safe(ptr,next,&birthday_list,list){
		list_del(&ptr->list);
		printk("Delete susseccful");
		kfree(ptr);
        }

	printk(KERN_INFO "Removing Module\n");
}
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");


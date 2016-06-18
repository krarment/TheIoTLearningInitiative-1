#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>

static struct kobject *sensor_kobject;
static int sensor;
int i, lessthan100;

static ssize_t sensor_show(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf)
{
        get_random_bytes(&i, sizeof(i));
        lessthan100 = i % 100;
        return sprintf(buf, "%d\n", lessthan100);
}

static ssize_t sensor_store(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf, size_t count)
{
        sscanf(buf, "%du", &sensor);
        return count;
}

static struct kobj_attribute sensor_attribute = __ATTR(status, 0660, sensor_show, sensor_store);

static int module_init_function(void)
{

        int error = 0;

        printk(KERN_INFO "Hello Sensor\n");

        sensor_kobject = kobject_create_and_add("sensor", NULL);
        if(!sensor_kobject)
                return -ENOMEM;

        error = sysfs_create_file(sensor_kobject, &sensor_attribute.attr);

        return 0;
}

static void module_exit_function(void)
{
        printk(KERN_INFO "Bye Hello Sensor\n");
        kobject_put(sensor_kobject);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("xe1gyq");
MODULE_DESCRIPTION("My First Linux Kernel Sensor Module");

module_init(module_init_function);
module_exit(module_exit_function);

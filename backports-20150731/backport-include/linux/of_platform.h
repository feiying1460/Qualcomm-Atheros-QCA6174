#ifndef __BACKPORT_LINUX_OF_PLATFORM_H
#define __BACKPORT_LINUX_OF_PLATFORM_H
#include_next <linux/of_platform.h>
#include <linux/version.h>
#include <linux/of.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0) && !defined(CONFIG_OF_DEVICE)
struct of_dev_auxdata;
#define of_platform_populate LINUX_BACKPORT(of_platform_populate)
static inline int of_platform_populate(struct device_node *root,
					const struct of_device_id *matches,
					const struct of_dev_auxdata *lookup,
					struct device *parent)
{
	return -ENODEV;
}
#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,11,0) && !defined(CONFIG_OF_DEVICE)
extern const struct of_device_id of_default_bus_match_table[];
#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(3,11,0) */

#endif /* __BACKPORT_LINUX_OF_PLATFORM_H */

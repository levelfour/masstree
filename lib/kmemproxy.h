#ifndef __KMEMPROXY_H__
#define __KMEMPROXY_H__

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#include <stdbool.h>
#include <masstree.h>

masstree_t  *mastree_init();
// void   *masstree_get(masstree_t *, const void *, size_t);
// bool    masstree_put(masstree_t *, const void *, size_t, void *);

__END_DECLS

#endif // __KMEMPROXY_H__

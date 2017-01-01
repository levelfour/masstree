#include "masstree.c"

#include <fcntl.h>
#include <sys/mman.h>

#include "kmemproxy.h"

#define PROXY_PATH "/dev/kmemproxy"

int proxy_fd = -1;
static void *proxy_alloc(size_t size);
static void proxy_free(void *addr, size_t size);
static const masstree_ops_t proxy_ops = {
  .alloc = proxy_alloc,
  .free  = proxy_free
};

masstree_t *masstree_init() {
  proxy_fd = open(PROXY_PATH, O_RDWR);
  if (proxy_fd < 0) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  return masstree_create(&proxy_ops);
}

static void *proxy_alloc(size_t size) {
  return mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, proxy_fd, 0);
}

static void proxy_free(void *addr, size_t size) {
  munmap(addr, size);
}

/*
    Caching file system proxy
 	Copyright (C) 2008  Nan Dun <sshfsm@gmail.com>

    This program can be distributed under the terms of the GNU GPL.
    See the file COPYING.
*/

#ifndef	_SSHFSM_CACHE_H_
#define	_SSHFSM_CACHE_H_

#include <fuse.h>
#include <fuse_opt.h>

#ifndef FUSE_VERSION
#define FUSE_VERSION (FUSE_MAJOR_VERSION * 10 + FUSE_MINOR_VERSION)
#endif

typedef struct fuse_cache_dirhandle *fuse_cache_dirh_t;
typedef int (*fuse_cache_dirfil_t) (fuse_cache_dirh_t h, const char *name,
                                    const struct stat *stbuf);

struct fuse_cache_operations {
    struct fuse_operations oper;
    int (*cache_getdir) (const char *, fuse_cache_dirh_t, fuse_cache_dirfil_t);
};

struct fuse_operations *cache_init(struct fuse_cache_operations *oper);
void cache_destroy();
int cache_parse_options(struct fuse_args *args);
void cache_add_attr(const char *path, const struct stat *stbuf);
void cache_invalidate(const char *path);

#endif	/* _SSHFSM_CACHE_H_ */

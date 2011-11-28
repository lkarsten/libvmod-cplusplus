#include <stdlib.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int hello(const char *msg, char *buf, size_t buflen);

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return (0);
}

const char *
vmod_hello(struct sess *sp, const char *name)
{
	char *p;
	unsigned u, v;

	u = WS_Reserve(sp->wrk->ws, 0); /* Reserve some work space */
	p = sp->wrk->ws->f;		/* Front of workspace area */
	v = hello(name, p, u);
	v++;
	if (v > u) {
		/* No space, reset and leave */
		WS_Release(sp->wrk->ws, 0);
		return (NULL);
	}
	/* Update work space with what we've used */
	WS_Release(sp->wrk->ws, v);
	return (p);
}

/*

Example C++ shim layer between C++ and C of Varnish.

It exists because C++-reserved words like "class" is used in the Varnish sources,
so building the whole vmod with C++ was not trivial. 

Author: Lasse Karstensen <lasse@varnish-software.com>, November 2011.
Copyright 2011 Varnish Software AS.
*/

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifndef AZ
#define AZ(x) assert(x == 0)
#endif

extern "C" {
int hello(const char *msg, char *buf, size_t buflen) {
	// this will be some funky c++ code.
	strncpy(buf, msg, sizeof(buflen));
	return (strlen(buf));
}

#ifdef JUICYPARTS_TEST
int main() {
	//test_loading(2);
	//test_lookup();
	char buf[1024];
	int result;
	result = hello("world", (char *)&buf, sizeof(buf));
	printf("buf is: %s\n", buf);
	return (0);
}
#endif 
} // extern "C"

#ifndef CCHESS_TEST_H
#define CCHESS_TEST_H

#include <stdio.h>
#include <stdlib.h>

static int assertions_run = 0;
static int assertions_failed = 0;

static inline const char *filename(const char *path)
{
	const char *tail = path;

	for (; *path; path++)
		if (*path == '/' || *path == '\\')
			tail = path + 1;

	return tail;
}

#define expect(condition) \
	do { \
		assertions_run++;   \
		if (!(condition)) { \
			fprintf(stderr, "FAIL: %s (%s:%d)\n", #condition, \
			        filename(__FILE__), __LINE__);            \
			assertions_failed++;                              \
		}                   \
	} while (0)

#define exit_test() \
	do { \
		if (assertions_failed) { \
			fprintf(stderr, "(%d/%d) assertions failed in %s\n", \
			        assertions_failed, assertions_run,           \
			        filename(__FILE__));                         \
			exit(EXIT_FAILURE);                                  \
		}                        \
		exit(EXIT_SUCCESS);      \
	} while (0)

#endif /* CCHESS_TEST_H */

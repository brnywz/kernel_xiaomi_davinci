/*
 * Configuration file for Mini-XML, a small XML file parsing library.
 *
 * Copyright 2003-2017 by Michael R Sweet.
 *
 * These coded instructions, statements, and computer programs are the
 * property of Michael R Sweet and are protected by Federal copyright
 * law.  Distribution and use rights are outlined in the file "COPYING"
 * which should have been included with this file.  If this file is
 * missing or damaged, see the license at:
 *
 *     https://michaelrsweet.github.io/mxml
 */

/*
 * Beginning with VC2005, Microsoft breaks ISO C and POSIX conformance
 * by deprecating a number of functions in the name of security, even
 * when many of the affected functions are otherwise completely secure.
 * The _CRT_SECURE_NO_DEPRECATE definition ensures that we won't get
 * warnings from their use...
 *
 * Then Microsoft decided that they should ignore this in VC2008 and use
 * yet another define (_CRT_SECURE_NO_WARNINGS) instead.  Bastards.
 */

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

/*
 * Include necessary headers...
 */

#include <linux/string.h>
#include <stdarg.h>
#include <linux/ctype.h>
/*#include <io.h>*/
#include "board_opr_interface.h"

/*
 * Microsoft also renames the POSIX functions to _name, and introduces
 * a broken compatibility layer using the original names.  As a result,
 * random crashes can occur when, for example, strdup() allocates memory
 * from a different heap than used by malloc() and free().
 *
 * To avoid moronic problems like this, we #define the POSIX function
 * names to the corresponding non-standard Microsoft names.
 */

/*
 * Version number...
 */

#define MXML_VERSION "Mini-XML v2.11"
#define HAVE_LONG_LONG 1
#define HAVE_SNPRINTF 1
#define HAVE_VSNPRINTF 1
#define HAVE_STRDUP 1


#ifndef HAVE_STRDUP
extern char *_mxml_strdup(const char *);
#define strdup _mxml_strdup
#endif /* !HAVE_STRDUP */

#ifndef HAVE_STRLCPY
extern size_t _mxml_strlcpy(char *, const char *, size_t);
#define strlcpy _mxml_strlcpy
#endif /* !HAVE_STRLCPY */

extern char *_mxml_strdupf(const char *, ...);
extern char *_mxml_vstrdupf(const char *, va_list);

#ifndef HAVE_SNPRINTF
extern int _mxml_snprintf(char *, size_t, const char *, ...);
#define snprintf _mxml_snprintf
#endif /* !HAVE_SNPRINTF */

#ifndef HAVE_VSNPRINTF
extern int _mxml_vsnprintf(char *, size_t, const char *, va_list);
#define vsnprintf _mxml_vsnprintf
#endif /* !HAVE_VSNPRINTF */

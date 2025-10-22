/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Default location to look for game data files */
#define DEFAULT_LIBDIR LOCAL_STATE_DIR "/sillymud"

/* Define as 1 to allow for named groups */
#define GROUP_NAMES 1

/* Define as 1 to use hash tables for rooms (more cpu, less storage) */
/* #undef HASH */

/* Define to 1 if you have the 'arc4random' function. */
#define HAVE_ARC4RANDOM 1

/* Define to 1 if you have the 'arc4random_buf' function. */
#define HAVE_ARC4RANDOM_BUF 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the 'bzero' function. */
#define HAVE_BZERO 1

/* Define to 1 if you have the <crypt.h> header file. */
/* #undef HAVE_CRYPT_H */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the 'gethostbyaddr' function. */
#define HAVE_GETHOSTBYADDR 1

/* Define to 1 if you have the 'gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the 'gethostname' function. */
#define HAVE_GETHOSTNAME 1

/* Define to 1 if you have the 'getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the 'gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the 'hstrerror' function. */
#define HAVE_HSTRERROR 1

/* Define to 1 if you have the 'htonl' function. */
#define HAVE_HTONL 1

/* Define to 1 if you have the 'inet_addr' function. */
#define HAVE_INET_ADDR 1

/* Define to 1 if you have the 'inet_ntoa' function. */
#define HAVE_INET_NTOA 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the 'isascii' function. */
#define HAVE_ISASCII 1

/* Define to 1 if your system has a GNU libc compatible 'malloc' function, and
   to 0 otherwise. */
#define HAVE_MALLOC 1

/* Define to 1 if you have the <malloc.h> header file. */
/* #undef HAVE_MALLOC_H */

/* Define to 1 if you have the 'memcmp' function. */
#define HAVE_MEMCMP 1

/* Define to 1 if you have the 'memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the 'rand' function. */
#define HAVE_RAND 1

/* Define to 1 if your system has a GNU libc compatible 'realloc' function,
   and to 0 otherwise. */
#define HAVE_REALLOC 1

/* Define to 1 if you have the 'select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the 'sigaddset' function. */
#define HAVE_SIGADDSET 1

/* Define to 1 if you have the 'sigemptyset' function. */
#define HAVE_SIGEMPTYSET 1

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if you have the 'sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if you have the 'socket' function. */
#define HAVE_SOCKET 1

/* Define to 1 if you have the 'srand' function. */
#define HAVE_SRAND 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the 'strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the 'strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the 'strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the 'strrchr' function. */
#define HAVE_STRRCHR 1

/* Define to 1 if you have the 'strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the 'time' function. */
#define HAVE_TIME 1

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define as 1 to restrict each level 58+ god to one site or set of sites */
#define IMPL_SECURITY 1

/* Define as 1 to enable loss of level at low experience levels */
#define LEVEL_LOSS 1

/* Define as 1 to limit items above a specific rent cost */
/* #undef LIMITED_ITEMS */

/* Define as 1 to allow lower exp loss for lower levels */
#define NEWEXP 1

/* Define as 1 to use newer (more expensive) rent */
#define NEW_RENT 1

/* Define as 1 to modify some commands to make item duplication nearly
   impossible */
/* #undef NODUPLICATES */

/* Define as 1 to disable tracking (lower cpu) */
/* #undef NOTRACK */

/* Name of package */
#define PACKAGE "sillymud"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "sillymud"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "sillymud 87aa9ca"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "sillymud"

/* Define to the home page for this package. */
#define PACKAGE_URL "https://github.com/jonm/SillyMUD"

/* Define to the version of this package. */
#define PACKAGE_VERSION "87aa9ca"

/* Define as 1 to require new players to be authorized */
/* #undef PLAYER_AUTH */

/* Define as 1 to save objects and mobs too */
/* #undef SAVE_WORLD */

/* Define as 1 to add commands for locking out specific hosts */
/* #undef SITELOCK */

/* The size of 'void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "87aa9ca"

/* Define to rpl_malloc if the replacement function should be used. */
/* #undef malloc */

/* Define to rpl_realloc if the replacement function should be used. */
/* #undef realloc */

/* Define as 'unsigned int' if <stddef.h> doesn't define. */
/* #undef size_t */


#if (SIZEOF_VOID_P == 8)
#define PTR_SZ_INT long
#elif (SIZEOF_VOID_P == 4)
#define PTR_SZ_INT int
#else
#error "Not sure what integer type is equivalently sized to a (void *)"
#endif

#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif


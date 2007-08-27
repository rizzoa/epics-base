//
// Default version of osdWireConfig.h that might
// work on UNIX like systems that define <sys/param.h>
//
//	Author Jeffrey O. Hill
//	johill@lanl.gov
//

#ifndef osdWireConfig_h
#define osdWireConfig_h

// if compilation fails because this wasnt found then you may need to define an OS 
// specific osdWireConfig.h
#include <sys/param.h>

#ifdef __BYTE_ORDER
#   if __BYTE_ORDER == __LITTLE_ENDIAN
#	    define EPICS_BYTE_ORDER EPICS_ENDIAN_LITTLE
#   elif __BYTE_ORDER == __BIG_ENDIAN
#	    define EPICS_BYTE_ORDER EPICS_ENDIAN_BIG
#   else
#       error EPICS hasn�t been ported to run on the <sys/param.h> specified __BYTE_ORDER 
#   endif
#else
#   ifdef BYTE_ORDER
#       if BYTE_ORDER == LITTLE_ENDIAN
#	        define EPICS_BYTE_ORDER EPICS_ENDIAN_LITTLE
#       elif BYTE_ORDER == BIG_ENDIAN
#	        define EPICS_BYTE_ORDER EPICS_ENDIAN_BIG
#       else
#           error EPICS hasn�t been ported to run on the <sys/param.h> specified BYTE_ORDER 
#       endif
#   else
#       error <sys/param.h> doesnt specify __BYTE_ORDER or BYTE_ORDER - is an OS specific osdWireConfig.h needed?
#   endif
#endif

#ifdef __FLOAT_WORD_ORDER
#   if __FLOAT_WORD_ORDER == __LITTLE_ENDIAN
#	    define EPICS_FLOAT_WORD_ORDER EPICS_ENDIAN_LITTLE
#   elif __FLOAT_WORD_ORDER == __BIG_ENDIAN
#	    define EPICS_FLOAT_WORD_ORDER EPICS_ENDIAN_BIG
#   else
#       error EPICS hasn�t been ported to <sys/param.h> specified __FLOAT_WORD_ORDER
#   endif
#else
#   if FLOAT_WORD_ORDER == LITTLE_ENDIAN
#	    define EPICS_FLOAT_WORD_ORDER EPICS_ENDIAN_LITTLE
#   elif FLOAT_WORD_ORDER == BIG_ENDIAN
#	    define EPICS_FLOAT_WORD_ORDER EPICS_ENDIAN_BIG
#   else
        // make the assumption that if __FLOAT_WORD_ORDER and FLOAT_WORD_ORDER 
        // arent defined then weird fp ordered archs like arm nwfp aren't supported
#       define EPICS_FLOAT_WORD_ORDER EPICS_BYTE_ORDER
#   endif
#endif

#endif // ifdef osdWireConfig_h
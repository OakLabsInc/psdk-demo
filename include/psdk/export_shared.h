
#ifndef PSDK_EXPORT_H
#define PSDK_EXPORT_H

#ifdef PSDK_STATIC_DEFINE
#  define PSDK_EXPORT
#  define PSDK_NO_EXPORT
#else
#  ifndef PSDK_EXPORT
#    ifdef PaymentSdk_shared_EXPORTS
        /* We are building this library */
#      define PSDK_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define PSDK_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef PSDK_NO_EXPORT
#    define PSDK_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef PSDK_DEPRECATED
#  define PSDK_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PSDK_DEPRECATED_EXPORT
#  define PSDK_DEPRECATED_EXPORT PSDK_EXPORT PSDK_DEPRECATED
#endif

#ifndef PSDK_DEPRECATED_NO_EXPORT
#  define PSDK_DEPRECATED_NO_EXPORT PSDK_NO_EXPORT PSDK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PSDK_NO_DEPRECATED
#    define PSDK_NO_DEPRECATED
#  endif
#endif

#endif /* PSDK_EXPORT_H */

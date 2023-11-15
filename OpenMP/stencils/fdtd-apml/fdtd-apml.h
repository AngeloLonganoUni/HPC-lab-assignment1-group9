#ifndef FDTD_APML_H
# define FDTD_AMPL_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# if !defined(CZ) && ! defined(CYM) && !defined(CXM)
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define CZ 32
#   define CYM 32
#   define CXM 32
#  endif

#  ifdef SMALL_DATASET
#   define CZ 64
#   define CYM 64
#   define CXM 64
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define CZ 256
#   define CYM 256
#   define CXM 256
#  endif

#  ifdef LARGE_DATASET
#   define CZ 512
#   define CYM 512
#   define CXM 512
#  endif

#  ifdef EXTRALARGE_DATASET
#   define CZ 1000
#   define CYM 1000
#   define CXM 1000
#  endif
# endif /* !N */

# define _PB_CZ POLYBENCH_LOOP_BOUND(CZ,cz)
# define _PB_CYM POLYBENCH_LOOP_BOUND(CYM,cym)
# define _PB_CXM POLYBENCH_LOOP_BOUND(CXM,cxm)

# ifndef DATA_TYPE
#  define DATA_TYPE double
#  define DATA_PRINTF_MODIFIER "%0.2lf "
# endif


#endif /* !FDTD_APML */

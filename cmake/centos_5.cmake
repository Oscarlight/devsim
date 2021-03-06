# Redhat 6.5 64 bit (not tested on 32 bit)
#IF (${DEVSIM_CONFIG} STREQUAL "redhat_6.5")
SET (EXTERNAL_LIB ${PROJECT_SOURCE_DIR}/external)
SET (SUPERLULOCATE  ${EXTERNAL_LIB}/SuperLU_4.3)
SET (SUPERLU_INCLUDE ${SUPERLULOCATE}/SRC)
SET (SUPERLU_ARCHIVE ${SUPERLULOCATE}/lib/libsuperlu_4.3.a)
SET (TCL_INCLUDE "$ENV{HOME}/anaconda/include")
SET (PTHREAD_LIB -lpthread)
SET (SQLITE3_INCLUDE $ENV{HOME}/anaconda/include)

SET (CGNS_ARCHIVE ${EXTERNAL_LIB}/cgnslib/lib/libcgns.a)
SET (CGNS_INCLUDE ${EXTERNAL_LIB}/cgnslib/include)

SET (SYMDIFF_ARCHIVE ${EXTERNAL_LIB}/symdiff/lib/libsymdiff_static.a)
SET (SYMDIFF_INCLUDE ${EXTERNAL_LIB}/symdiff/include)
ADD_DEFINITIONS(-DTCL_THREADS -pthread -fvisibility=hidden)
SET (FLEX /usr/bin/flex)
SET (BISON /usr/bin/bison)
SET (PYTHON_INCLUDE $ENV{HOME}/anaconda/include/python2.7)
# use /opt/acml5.3.0/util/cpuid.exe to find support
# ACML 5.3 available at developer.amd.com
SET (ZLIB_INCLUDE $ENV{HOME}/anaconda/include)

IF (${CMAKE_SIZEOF_VOID_P} MATCHES 4)
ELSE (${CMAKE_SIZEOF_VOID_P} MATCHES 4)
# TODO: place a symlink in EXTERNAL_LIB pointing to lapack and blas with
# an unversioned so name
SET (MKLROOT
/opt/intel/compilers_and_libraries/linux/mkl
)
SET (BLAS_ARCHIVE
#http://software.intel.com/en-us/articles/intel-mkl-link-line-advisor
#requires duplicate library for 1-pass linker
-Wl,--start-group
${MKLROOT}/lib/intel64/libmkl_intel_lp64.a
${MKLROOT}/lib/intel64/libmkl_core.a
${MKLROOT}/lib/intel64/libmkl_sequential.a
-Wl,--end-group
)
SET (ZLIB_ARCHIVE $ENV{HOME}/anaconda/lib/libz.a)
SET (SQLITE3_ARCHIVE $ENV{HOME}/anaconda/lib/libsqlite3.a)
SET (TCL_STUB $ENV{HOME}/anaconda/lib/libtclstub8.5.a)
SET (TCL_ARCHIVE -L$ENV{HOME}/anaconda/lib -ltcl8.5 -ldl)
SET (PYTHON_ARCHIVE -L$ENV{HOME}/anaconda/lib -lpython2.7)
ENDIF (${CMAKE_SIZEOF_VOID_P} MATCHES 4)



#ENDIF (${DEVSIM_CONFIG} STREQUAL "redhat_6.5")


//
// MATLAB Compiler: 7.0.1 (R2019a)
// Date: Tue May 19 17:24:55 2020
// Arguments: "-B""macro_default""-W""cpplib:libunwrap""-T""link:lib""myUnwrap"
//

#define EXPORTING_libunwrap 1
#include "libunwrap.h"

static HMCRINSTANCE _mcr_inst = NULL;

#if defined( _MSC_VER) || defined(__LCC__) || defined(__MINGW64__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define NOMINMAX
#include <windows.h>
#undef interface

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
    return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0;
    size_t len = 0;
    len = strlen(s);
    written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
    if (len > 0 && s[ len-1 ] != '\n')
        written += mclWrite(2 /* stderr */, "\n", sizeof(char));
    return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libunwrap_C_API
#define LIB_libunwrap_C_API /* No special import/export declaration */
#endif

LIB_libunwrap_C_API 
bool MW_CALL_CONV libunwrapInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("libunwrap"), path_to_dll, _MAX_PATH))
        return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(&_mcr_inst,
                                                             error_handler, 
                                                             print_handler,
                                                             ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
    return true;
}

LIB_libunwrap_C_API 
bool MW_CALL_CONV libunwrapInitialize(void)
{
    return libunwrapInitializeWithHandlers(mclDefaultErrorHandler, 
                                         mclDefaultPrintHandler);
}

LIB_libunwrap_C_API 
void MW_CALL_CONV libunwrapTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

LIB_libunwrap_C_API 
void MW_CALL_CONV libunwrapPrintStackTrace(void) 
{
    char** stackTrace;
    int stackDepth = mclGetStackTrace(&stackTrace);
    int i;
    for(i=0; i<stackDepth; i++)
    {
        mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
        mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
    }
    mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libunwrap_C_API 
bool MW_CALL_CONV mlxMyUnwrap(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "myUnwrap", nlhs, plhs, nrhs, prhs);
}

LIB_libunwrap_CPP_API 
void MW_CALL_CONV myUnwrap(int nargout, mwArray& Unwrapped_Phase, const mwArray& 
                           Wrapped_Phase)
{
    mclcppMlfFeval(_mcr_inst, "myUnwrap", nargout, 1, 1, &Unwrapped_Phase, &Wrapped_Phase);
}


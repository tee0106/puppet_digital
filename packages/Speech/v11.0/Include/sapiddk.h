

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* Compiler settings for sapiddk.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __sapiddk_h__
#define __sapiddk_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISpTokenUI_FWD_DEFINED__
#define __ISpTokenUI_FWD_DEFINED__
typedef interface ISpTokenUI ISpTokenUI;
#endif 	/* __ISpTokenUI_FWD_DEFINED__ */


#ifndef __ISpObjectTokenEnumBuilder_FWD_DEFINED__
#define __ISpObjectTokenEnumBuilder_FWD_DEFINED__
typedef interface ISpObjectTokenEnumBuilder ISpObjectTokenEnumBuilder;
#endif 	/* __ISpObjectTokenEnumBuilder_FWD_DEFINED__ */


#ifndef __ISpErrorLog_FWD_DEFINED__
#define __ISpErrorLog_FWD_DEFINED__
typedef interface ISpErrorLog ISpErrorLog;
#endif 	/* __ISpErrorLog_FWD_DEFINED__ */


#ifndef __ISpGrammarCompiler_FWD_DEFINED__
#define __ISpGrammarCompiler_FWD_DEFINED__
typedef interface ISpGrammarCompiler ISpGrammarCompiler;
#endif 	/* __ISpGrammarCompiler_FWD_DEFINED__ */


#ifndef __ISpGrammarCompiler2_FWD_DEFINED__
#define __ISpGrammarCompiler2_FWD_DEFINED__
typedef interface ISpGrammarCompiler2 ISpGrammarCompiler2;
#endif 	/* __ISpGrammarCompiler2_FWD_DEFINED__ */


#ifndef __ISpGramCompBackend_FWD_DEFINED__
#define __ISpGramCompBackend_FWD_DEFINED__
typedef interface ISpGramCompBackend ISpGramCompBackend;
#endif 	/* __ISpGramCompBackend_FWD_DEFINED__ */


#ifndef __ISpITNProcessor_FWD_DEFINED__
#define __ISpITNProcessor_FWD_DEFINED__
typedef interface ISpITNProcessor ISpITNProcessor;
#endif 	/* __ISpITNProcessor_FWD_DEFINED__ */


#ifndef __ISpPhraseBuilder_FWD_DEFINED__
#define __ISpPhraseBuilder_FWD_DEFINED__
typedef interface ISpPhraseBuilder ISpPhraseBuilder;
#endif 	/* __ISpPhraseBuilder_FWD_DEFINED__ */


#ifndef __ISpThreadControl_FWD_DEFINED__
#define __ISpThreadControl_FWD_DEFINED__
typedef interface ISpThreadControl ISpThreadControl;
#endif 	/* __ISpThreadControl_FWD_DEFINED__ */


#ifndef __ISpTaskManager_FWD_DEFINED__
#define __ISpTaskManager_FWD_DEFINED__
typedef interface ISpTaskManager ISpTaskManager;
#endif 	/* __ISpTaskManager_FWD_DEFINED__ */


#ifndef __ISpTTSEngineSite_FWD_DEFINED__
#define __ISpTTSEngineSite_FWD_DEFINED__
typedef interface ISpTTSEngineSite ISpTTSEngineSite;
#endif 	/* __ISpTTSEngineSite_FWD_DEFINED__ */


#ifndef __ISpPromptEngineSite_FWD_DEFINED__
#define __ISpPromptEngineSite_FWD_DEFINED__
typedef interface ISpPromptEngineSite ISpPromptEngineSite;
#endif 	/* __ISpPromptEngineSite_FWD_DEFINED__ */


#ifndef __ISpTTSEngine_FWD_DEFINED__
#define __ISpTTSEngine_FWD_DEFINED__
typedef interface ISpTTSEngine ISpTTSEngine;
#endif 	/* __ISpTTSEngine_FWD_DEFINED__ */


#ifndef __ISpPromptEngine_FWD_DEFINED__
#define __ISpPromptEngine_FWD_DEFINED__
typedef interface ISpPromptEngine ISpPromptEngine;
#endif 	/* __ISpPromptEngine_FWD_DEFINED__ */


#ifndef __ISpCFGInterpreterSite_FWD_DEFINED__
#define __ISpCFGInterpreterSite_FWD_DEFINED__
typedef interface ISpCFGInterpreterSite ISpCFGInterpreterSite;
#endif 	/* __ISpCFGInterpreterSite_FWD_DEFINED__ */


#ifndef __ISpCFGInterpreter_FWD_DEFINED__
#define __ISpCFGInterpreter_FWD_DEFINED__
typedef interface ISpCFGInterpreter ISpCFGInterpreter;
#endif 	/* __ISpCFGInterpreter_FWD_DEFINED__ */


#ifndef __ISpSREngineSite_FWD_DEFINED__
#define __ISpSREngineSite_FWD_DEFINED__
typedef interface ISpSREngineSite ISpSREngineSite;
#endif 	/* __ISpSREngineSite_FWD_DEFINED__ */


#ifndef __ISpSREngineSite2_FWD_DEFINED__
#define __ISpSREngineSite2_FWD_DEFINED__
typedef interface ISpSREngineSite2 ISpSREngineSite2;
#endif 	/* __ISpSREngineSite2_FWD_DEFINED__ */


#ifndef __ISpSREngine_FWD_DEFINED__
#define __ISpSREngine_FWD_DEFINED__
typedef interface ISpSREngine ISpSREngine;
#endif 	/* __ISpSREngine_FWD_DEFINED__ */


#ifndef __ISpSREngine2_FWD_DEFINED__
#define __ISpSREngine2_FWD_DEFINED__
typedef interface ISpSREngine2 ISpSREngine2;
#endif 	/* __ISpSREngine2_FWD_DEFINED__ */


#ifndef __ISpSRAlternates_FWD_DEFINED__
#define __ISpSRAlternates_FWD_DEFINED__
typedef interface ISpSRAlternates ISpSRAlternates;
#endif 	/* __ISpSRAlternates_FWD_DEFINED__ */


#ifndef __ISpSRAlternates2_FWD_DEFINED__
#define __ISpSRAlternates2_FWD_DEFINED__
typedef interface ISpSRAlternates2 ISpSRAlternates2;
#endif 	/* __ISpSRAlternates2_FWD_DEFINED__ */


#ifndef ___ISpPrivateEngineCall_FWD_DEFINED__
#define ___ISpPrivateEngineCall_FWD_DEFINED__
typedef interface _ISpPrivateEngineCall _ISpPrivateEngineCall;
#endif 	/* ___ISpPrivateEngineCall_FWD_DEFINED__ */


#ifndef __ISpPrivateEngineCallEx_FWD_DEFINED__
#define __ISpPrivateEngineCallEx_FWD_DEFINED__
typedef interface ISpPrivateEngineCallEx ISpPrivateEngineCallEx;
#endif 	/* __ISpPrivateEngineCallEx_FWD_DEFINED__ */


#ifndef __SpDataKey_FWD_DEFINED__
#define __SpDataKey_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpDataKey SpDataKey;
#else
typedef struct SpDataKey SpDataKey;
#endif /* __cplusplus */

#endif 	/* __SpDataKey_FWD_DEFINED__ */


#ifndef __SpObjectTokenEnum_FWD_DEFINED__
#define __SpObjectTokenEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpObjectTokenEnum SpObjectTokenEnum;
#else
typedef struct SpObjectTokenEnum SpObjectTokenEnum;
#endif /* __cplusplus */

#endif 	/* __SpObjectTokenEnum_FWD_DEFINED__ */


#ifndef __SpPhraseBuilder_FWD_DEFINED__
#define __SpPhraseBuilder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhraseBuilder SpPhraseBuilder;
#else
typedef struct SpPhraseBuilder SpPhraseBuilder;
#endif /* __cplusplus */

#endif 	/* __SpPhraseBuilder_FWD_DEFINED__ */


#ifndef __SpITNProcessor_FWD_DEFINED__
#define __SpITNProcessor_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpITNProcessor SpITNProcessor;
#else
typedef struct SpITNProcessor SpITNProcessor;
#endif /* __cplusplus */

#endif 	/* __SpITNProcessor_FWD_DEFINED__ */


#ifndef __SpGrammarCompiler_FWD_DEFINED__
#define __SpGrammarCompiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpGrammarCompiler SpGrammarCompiler;
#else
typedef struct SpGrammarCompiler SpGrammarCompiler;
#endif /* __cplusplus */

#endif 	/* __SpGrammarCompiler_FWD_DEFINED__ */


#ifndef __SpW3CGrammarCompiler_FWD_DEFINED__
#define __SpW3CGrammarCompiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpW3CGrammarCompiler SpW3CGrammarCompiler;
#else
typedef struct SpW3CGrammarCompiler SpW3CGrammarCompiler;
#endif /* __cplusplus */

#endif 	/* __SpW3CGrammarCompiler_FWD_DEFINED__ */


#ifndef __SpGramCompBackend_FWD_DEFINED__
#define __SpGramCompBackend_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpGramCompBackend SpGramCompBackend;
#else
typedef struct SpGramCompBackend SpGramCompBackend;
#endif /* __cplusplus */

#endif 	/* __SpGramCompBackend_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "sapi.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sapiddk_0000_0000 */
/* [local] */ 






#define SPRECOEXTENSION   L"RecoExtension"
#define SPALTERNATESCLSID L"AlternatesCLSID"
#define SR_LOCALIZED_DESCRIPTION L"Description"


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0000_v0_0_s_ifspec;

#ifndef __ISpTokenUI_INTERFACE_DEFINED__
#define __ISpTokenUI_INTERFACE_DEFINED__

/* interface ISpTokenUI */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpTokenUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8E690F0-39CB-4843-B8D7-C84696E1119D")
    ISpTokenUI : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            __in_opt  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ ISpObjectToken *pToken,
            /* [in] */ IUnknown *punkObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpTokenUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTokenUI * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTokenUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTokenUI * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpTokenUI * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpTokenUI * This,
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            __in_opt  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ ISpObjectToken *pToken,
            /* [in] */ IUnknown *punkObject);
        
        END_INTERFACE
    } ISpTokenUIVtbl;

    interface ISpTokenUI
    {
        CONST_VTBL struct ISpTokenUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTokenUI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTokenUI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTokenUI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTokenUI_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported) ) 

#define ISpTokenUI_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTokenUI_INTERFACE_DEFINED__ */


#ifndef __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__
#define __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__

/* interface ISpObjectTokenEnumBuilder */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectTokenEnumBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06B64F9F-7FDA-11d2-B4F2-00C04F797396")
    ISpObjectTokenEnumBuilder : public IEnumSpObjectTokens
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAttribs( 
            /* [annotation] */ 
            __in_opt  LPCWSTR pszReqAttribs,
            /* [annotation] */ 
            __in_opt  LPCWSTR pszOptAttribs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokens( 
            ULONG cTokens,
            ISpObjectToken **pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromDataKey( 
            ISpDataKey *pDataKey,
            LPCWSTR pszSubKey,
            LPCWSTR pszCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromTokenEnum( 
            IEnumSpObjectTokens *pTokenEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sort( 
            LPCWSTR pszTokenIdToListFirst) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenEnumBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectTokenEnumBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectTokenEnumBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ ISpObjectToken **pelt,
            /* [out][annotation] */ 
            __out_opt  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ISpObjectTokenEnumBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpObjectTokenEnumBuilder * This,
            /* [out] */ IEnumSpObjectTokens **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG Index,
            /* [out] */ ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ISpObjectTokenEnumBuilder * This,
            /* [out] */ ULONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttribs )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation] */ 
            __in_opt  LPCWSTR pszReqAttribs,
            /* [annotation] */ 
            __in_opt  LPCWSTR pszOptAttribs);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokens )( 
            ISpObjectTokenEnumBuilder * This,
            ULONG cTokens,
            ISpObjectToken **pToken);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromDataKey )( 
            ISpObjectTokenEnumBuilder * This,
            ISpDataKey *pDataKey,
            LPCWSTR pszSubKey,
            LPCWSTR pszCategoryId);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromTokenEnum )( 
            ISpObjectTokenEnumBuilder * This,
            IEnumSpObjectTokens *pTokenEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Sort )( 
            ISpObjectTokenEnumBuilder * This,
            LPCWSTR pszTokenIdToListFirst);
        
        END_INTERFACE
    } ISpObjectTokenEnumBuilderVtbl;

    interface ISpObjectTokenEnumBuilder
    {
        CONST_VTBL struct ISpObjectTokenEnumBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectTokenEnumBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectTokenEnumBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectTokenEnumBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectTokenEnumBuilder_Next(This,celt,pelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pelt,pceltFetched) ) 

#define ISpObjectTokenEnumBuilder_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define ISpObjectTokenEnumBuilder_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISpObjectTokenEnumBuilder_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define ISpObjectTokenEnumBuilder_Item(This,Index,ppToken)	\
    ( (This)->lpVtbl -> Item(This,Index,ppToken) ) 

#define ISpObjectTokenEnumBuilder_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 


#define ISpObjectTokenEnumBuilder_SetAttribs(This,pszReqAttribs,pszOptAttribs)	\
    ( (This)->lpVtbl -> SetAttribs(This,pszReqAttribs,pszOptAttribs) ) 

#define ISpObjectTokenEnumBuilder_AddTokens(This,cTokens,pToken)	\
    ( (This)->lpVtbl -> AddTokens(This,cTokens,pToken) ) 

#define ISpObjectTokenEnumBuilder_AddTokensFromDataKey(This,pDataKey,pszSubKey,pszCategoryId)	\
    ( (This)->lpVtbl -> AddTokensFromDataKey(This,pDataKey,pszSubKey,pszCategoryId) ) 

#define ISpObjectTokenEnumBuilder_AddTokensFromTokenEnum(This,pTokenEnum)	\
    ( (This)->lpVtbl -> AddTokensFromTokenEnum(This,pTokenEnum) ) 

#define ISpObjectTokenEnumBuilder_Sort(This,pszTokenIdToListFirst)	\
    ( (This)->lpVtbl -> Sort(This,pszTokenIdToListFirst) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0002 */
/* [local] */ 

#if 0
typedef void *SPWORDHANDLE;

typedef void *SPRULEHANDLE;

typedef void *SPGRAMMARHANDLE;

typedef void *SPRECOCONTEXTHANDLE;

typedef void *SPPHRASERULEHANDLE;

typedef void *SPPHRASEPROPERTYHANDLE;

typedef void *SPTRANSITIONID;

#else
DECLARE_HANDLE(SPWORDHANDLE);
DECLARE_HANDLE(SPRULEHANDLE);
DECLARE_HANDLE(SPGRAMMARHANDLE);
DECLARE_HANDLE(SPRECOCONTEXTHANDLE);
DECLARE_HANDLE(SPPHRASERULEHANDLE);
DECLARE_HANDLE(SPPHRASEPROPERTYHANDLE);
DECLARE_HANDLE(SPTRANSITIONID);
#endif


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0002_v0_0_s_ifspec;

#ifndef __ISpErrorLog_INTERFACE_DEFINED__
#define __ISpErrorLog_INTERFACE_DEFINED__

/* interface ISpErrorLog */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpErrorLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4711347-E608-11d2-A086-00C04F8EF9B5")
    ISpErrorLog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddError( 
            const long lLineNumber,
            HRESULT hr,
            LPCWSTR pszDescription,
            /* [annotation] */ 
            __in_opt  LPCWSTR pszHelpFile,
            DWORD dwHelpContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpErrorLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpErrorLog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpErrorLog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpErrorLog * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddError )( 
            ISpErrorLog * This,
            const long lLineNumber,
            HRESULT hr,
            LPCWSTR pszDescription,
            /* [annotation] */ 
            __in_opt  LPCWSTR pszHelpFile,
            DWORD dwHelpContext);
        
        END_INTERFACE
    } ISpErrorLogVtbl;

    interface ISpErrorLog
    {
        CONST_VTBL struct ISpErrorLogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpErrorLog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpErrorLog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpErrorLog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpErrorLog_AddError(This,lLineNumber,hr,pszDescription,pszHelpFile,dwHelpContext)	\
    ( (This)->lpVtbl -> AddError(This,lLineNumber,hr,pszDescription,pszHelpFile,dwHelpContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpErrorLog_INTERFACE_DEFINED__ */


#ifndef __ISpGrammarCompiler_INTERFACE_DEFINED__
#define __ISpGrammarCompiler_INTERFACE_DEFINED__

/* interface ISpGrammarCompiler */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGrammarCompiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1E29D58-A675-11D2-8302-00C04F8EE6C0")
    ISpGrammarCompiler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompileStream( 
            IStream *pSource,
            IStream *pDest,
            /* [annotation] */ 
            __in_opt  IStream *pHeader,
            /* [annotation] */ 
            __in_opt  IUnknown *pLoader,
            /* [annotation] */ 
            __in_opt  ISpErrorLog *pErrorLog,
            DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpGrammarCompilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarCompiler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarCompiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarCompiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompileStream )( 
            ISpGrammarCompiler * This,
            IStream *pSource,
            IStream *pDest,
            /* [annotation] */ 
            __in_opt  IStream *pHeader,
            /* [annotation] */ 
            __in_opt  IUnknown *pLoader,
            /* [annotation] */ 
            __in_opt  ISpErrorLog *pErrorLog,
            DWORD dwFlags);
        
        END_INTERFACE
    } ISpGrammarCompilerVtbl;

    interface ISpGrammarCompiler
    {
        CONST_VTBL struct ISpGrammarCompilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGrammarCompiler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGrammarCompiler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGrammarCompiler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGrammarCompiler_CompileStream(This,pSource,pDest,pHeader,pLoader,pErrorLog,dwFlags)	\
    ( (This)->lpVtbl -> CompileStream(This,pSource,pDest,pHeader,pLoader,pErrorLog,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGrammarCompiler_INTERFACE_DEFINED__ */


#ifndef __ISpGrammarCompiler2_INTERFACE_DEFINED__
#define __ISpGrammarCompiler2_INTERFACE_DEFINED__

/* interface ISpGrammarCompiler2 */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGrammarCompiler2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A0E05CF-50E8-462d-B84E-7FE25DA91A2F")
    ISpGrammarCompiler2 : public ISpGrammarCompiler
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDefaultBaseUrl( 
            LPCWSTR pszBaseUrl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpGrammarCompiler2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarCompiler2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarCompiler2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarCompiler2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompileStream )( 
            ISpGrammarCompiler2 * This,
            IStream *pSource,
            IStream *pDest,
            /* [annotation] */ 
            __in_opt  IStream *pHeader,
            /* [annotation] */ 
            __in_opt  IUnknown *pLoader,
            /* [annotation] */ 
            __in_opt  ISpErrorLog *pErrorLog,
            DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultBaseUrl )( 
            ISpGrammarCompiler2 * This,
            LPCWSTR pszBaseUrl);
        
        END_INTERFACE
    } ISpGrammarCompiler2Vtbl;

    interface ISpGrammarCompiler2
    {
        CONST_VTBL struct ISpGrammarCompiler2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGrammarCompiler2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGrammarCompiler2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGrammarCompiler2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGrammarCompiler2_CompileStream(This,pSource,pDest,pHeader,pLoader,pErrorLog,dwFlags)	\
    ( (This)->lpVtbl -> CompileStream(This,pSource,pDest,pHeader,pLoader,pErrorLog,dwFlags) ) 


#define ISpGrammarCompiler2_SetDefaultBaseUrl(This,pszBaseUrl)	\
    ( (This)->lpVtbl -> SetDefaultBaseUrl(This,pszBaseUrl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGrammarCompiler2_INTERFACE_DEFINED__ */


#ifndef __ISpGramCompBackend_INTERFACE_DEFINED__
#define __ISpGramCompBackend_INTERFACE_DEFINED__

/* interface ISpGramCompBackend */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGramCompBackend;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DDCA27C-665C-4786-9F97-8C90C3488B61")
    ISpGramCompBackend : public ISpGrammarBuilder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSaveObjects( 
            IStream *pStream,
            ISpErrorLog *pErrorLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromBinaryGrammar( 
            const SPBINARYGRAMMAR *pBinaryData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpGramCompBackendVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGramCompBackend * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGramCompBackend * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGramCompBackend * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            ISpGramCompBackend * This,
            /* [in] */ WORD NewLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            ISpGramCompBackend * This,
            /* [in] */ LPCWSTR pszRuleName,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ DWORD dwAttributes,
            /* [in] */ BOOL fCreateIfNotExist,
            /* [out] */ SPSTATEHANDLE *phInitialState);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            ISpGramCompBackend * This,
            SPSTATEHANDLE hState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            ISpGramCompBackend * This,
            SPSTATEHANDLE hState,
            SPSTATEHANDLE *phState);
        
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            ISpGramCompBackend * This,
            SPSTATEHANDLE hFromState,
            SPSTATEHANDLE hToState,
            LPCWSTR psz,
            LPCWSTR pszSeparators,
            SPGRAMMARWORDTYPE eWordType,
            float Weight,
            const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            ISpGramCompBackend * This,
            SPSTATEHANDLE hFromState,
            SPSTATEHANDLE hToState,
            SPSTATEHANDLE hRule,
            float Weight,
            const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            ISpGramCompBackend * This,
            /* [in] */ SPSTATEHANDLE hRuleState,
            /* [in] */ LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            __in_opt  LPCWSTR pszResourceValue);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpGramCompBackend * This,
            DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetSaveObjects )( 
            ISpGramCompBackend * This,
            IStream *pStream,
            ISpErrorLog *pErrorLog);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromBinaryGrammar )( 
            ISpGramCompBackend * This,
            const SPBINARYGRAMMAR *pBinaryData);
        
        END_INTERFACE
    } ISpGramCompBackendVtbl;

    interface ISpGramCompBackend
    {
        CONST_VTBL struct ISpGramCompBackendVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGramCompBackend_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGramCompBackend_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGramCompBackend_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGramCompBackend_ResetGrammar(This,NewLanguage)	\
    ( (This)->lpVtbl -> ResetGrammar(This,NewLanguage) ) 

#define ISpGramCompBackend_GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState)	\
    ( (This)->lpVtbl -> GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState) ) 

#define ISpGramCompBackend_ClearRule(This,hState)	\
    ( (This)->lpVtbl -> ClearRule(This,hState) ) 

#define ISpGramCompBackend_CreateNewState(This,hState,phState)	\
    ( (This)->lpVtbl -> CreateNewState(This,hState,phState) ) 

#define ISpGramCompBackend_AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo) ) 

#define ISpGramCompBackend_AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo) ) 

#define ISpGramCompBackend_AddResource(This,hRuleState,pszResourceName,pszResourceValue)	\
    ( (This)->lpVtbl -> AddResource(This,hRuleState,pszResourceName,pszResourceValue) ) 

#define ISpGramCompBackend_Commit(This,dwFlags)	\
    ( (This)->lpVtbl -> Commit(This,dwFlags) ) 


#define ISpGramCompBackend_SetSaveObjects(This,pStream,pErrorLog)	\
    ( (This)->lpVtbl -> SetSaveObjects(This,pStream,pErrorLog) ) 

#define ISpGramCompBackend_InitFromBinaryGrammar(This,pBinaryData)	\
    ( (This)->lpVtbl -> InitFromBinaryGrammar(This,pBinaryData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGramCompBackend_INTERFACE_DEFINED__ */


#ifndef __ISpITNProcessor_INTERFACE_DEFINED__
#define __ISpITNProcessor_INTERFACE_DEFINED__

/* interface ISpITNProcessor */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpITNProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12D7360F-A1C9-11d3-BC90-00C04F72DF9F")
    ISpITNProcessor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadITNGrammar( 
            /* [annotation] */ 
            __in  LPWSTR pszCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ITNPhrase( 
            ISpPhraseBuilder *pPhrase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpITNProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpITNProcessor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpITNProcessor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpITNProcessor * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadITNGrammar )( 
            ISpITNProcessor * This,
            /* [annotation] */ 
            __in  LPWSTR pszCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *ITNPhrase )( 
            ISpITNProcessor * This,
            ISpPhraseBuilder *pPhrase);
        
        END_INTERFACE
    } ISpITNProcessorVtbl;

    interface ISpITNProcessor
    {
        CONST_VTBL struct ISpITNProcessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpITNProcessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpITNProcessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpITNProcessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpITNProcessor_LoadITNGrammar(This,pszCLSID)	\
    ( (This)->lpVtbl -> LoadITNGrammar(This,pszCLSID) ) 

#define ISpITNProcessor_ITNPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> ITNPhrase(This,pPhrase) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpITNProcessor_INTERFACE_DEFINED__ */


#ifndef __ISpPhraseBuilder_INTERFACE_DEFINED__
#define __ISpPhraseBuilder_INTERFACE_DEFINED__

/* interface ISpPhraseBuilder */
/* [restricted][unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISpPhraseBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88A3342A-0BED-4834-922B-88D43173162F")
    ISpPhraseBuilder : public ISpPhrase
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitFromPhrase( 
            const SPPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromSerializedPhrase( 
            const SPSERIALIZEDPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddElements( 
            ULONG cElements,
            const SPPHRASEELEMENT *pElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRules( 
            const SPPHRASERULEHANDLE hParent,
            const SPPHRASERULE *pRule,
            SPPHRASERULEHANDLE *phNewRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperties( 
            const SPPHRASEPROPERTYHANDLE hParent,
            const SPPHRASEPROPERTY *pProperty,
            SPPHRASEPROPERTYHANDLE *phNewProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddReplacements( 
            ULONG cReplacements,
            const SPPHRASEREPLACEMENT *pReplacements) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpPhraseBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhraseBuilder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhraseBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhraseBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhraseBuilder * This,
            /* [out] */ SPPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhraseBuilder * This,
            /* [out] */ SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhraseBuilder * This,
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            __out_ecount_opt(1)  BYTE *pbDisplayAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhraseBuilder * This,
            /* [in] */ DWORD dwValueTypes);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromPhrase )( 
            ISpPhraseBuilder * This,
            const SPPHRASE *pPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromSerializedPhrase )( 
            ISpPhraseBuilder * This,
            const SPSERIALIZEDPHRASE *pPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *AddElements )( 
            ISpPhraseBuilder * This,
            ULONG cElements,
            const SPPHRASEELEMENT *pElement);
        
        HRESULT ( STDMETHODCALLTYPE *AddRules )( 
            ISpPhraseBuilder * This,
            const SPPHRASERULEHANDLE hParent,
            const SPPHRASERULE *pRule,
            SPPHRASERULEHANDLE *phNewRule);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperties )( 
            ISpPhraseBuilder * This,
            const SPPHRASEPROPERTYHANDLE hParent,
            const SPPHRASEPROPERTY *pProperty,
            SPPHRASEPROPERTYHANDLE *phNewProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddReplacements )( 
            ISpPhraseBuilder * This,
            ULONG cReplacements,
            const SPPHRASEREPLACEMENT *pReplacements);
        
        END_INTERFACE
    } ISpPhraseBuilderVtbl;

    interface ISpPhraseBuilder
    {
        CONST_VTBL struct ISpPhraseBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhraseBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhraseBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhraseBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhraseBuilder_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseBuilder_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseBuilder_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpPhraseBuilder_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpPhraseBuilder_InitFromPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> InitFromPhrase(This,pPhrase) ) 

#define ISpPhraseBuilder_InitFromSerializedPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> InitFromSerializedPhrase(This,pPhrase) ) 

#define ISpPhraseBuilder_AddElements(This,cElements,pElement)	\
    ( (This)->lpVtbl -> AddElements(This,cElements,pElement) ) 

#define ISpPhraseBuilder_AddRules(This,hParent,pRule,phNewRule)	\
    ( (This)->lpVtbl -> AddRules(This,hParent,pRule,phNewRule) ) 

#define ISpPhraseBuilder_AddProperties(This,hParent,pProperty,phNewProperty)	\
    ( (This)->lpVtbl -> AddProperties(This,hParent,pProperty,phNewProperty) ) 

#define ISpPhraseBuilder_AddReplacements(This,cReplacements,pReplacements)	\
    ( (This)->lpVtbl -> AddReplacements(This,cReplacements,pReplacements) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhraseBuilder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0008 */
/* [local] */ 

#if defined(__cplusplus)
interface ISpTask
{
virtual HRESULT STDMETHODCALLTYPE Execute(
                 void *pvTaskData,
                 volatile const BOOL* pfContinueProcessing) = 0;
};
#else
typedef void *ISpTask;

#endif
#if defined(__cplusplus)
interface ISpThreadTask
{
virtual HRESULT STDMETHODCALLTYPE InitThread(
                 void * pvTaskData,
                 HWND hwnd) = 0;
virtual HRESULT STDMETHODCALLTYPE ThreadProc(
                 void *pvTaskData,
                 HANDLE hExitThreadEvent,
                 HANDLE hNotifyEvent,
                 HWND hwndWorker,
                 volatile const BOOL * pfContinueProcessing) = 0;
virtual LRESULT STDMETHODCALLTYPE WindowMessage(
                 void *pvTaskData,
                 HWND hWnd,
                 UINT Msg,
                 WPARAM wParam,
                 LPARAM lParam) = 0;
};
#else
typedef void *ISpThreadTask;

#endif


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0008_v0_0_s_ifspec;

#ifndef __ISpThreadControl_INTERFACE_DEFINED__
#define __ISpThreadControl_INTERFACE_DEFINED__

/* interface ISpThreadControl */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpThreadControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6BE4D73-4403-4358-B22D-0346E23B1764")
    ISpThreadControl : public ISpNotifySink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartThread( 
            DWORD dwFlags,
            HWND *phwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForThreadDone( 
            BOOL fForceStop,
            HRESULT *phrThreadResult,
            ULONG msTimeOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateThread( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ThreadHandle( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE ThreadId( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE NotifyEvent( void) = 0;
        
        virtual HWND STDMETHODCALLTYPE WindowHandle( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ThreadCompleteEvent( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ExitThreadEvent( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpThreadControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpThreadControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpThreadControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpThreadControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISpThreadControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartThread )( 
            ISpThreadControl * This,
            DWORD dwFlags,
            HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForThreadDone )( 
            ISpThreadControl * This,
            BOOL fForceStop,
            HRESULT *phrThreadResult,
            ULONG msTimeOut);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateThread )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ThreadHandle )( 
            ISpThreadControl * This);
        
        DWORD ( STDMETHODCALLTYPE *ThreadId )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *NotifyEvent )( 
            ISpThreadControl * This);
        
        HWND ( STDMETHODCALLTYPE *WindowHandle )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ThreadCompleteEvent )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ExitThreadEvent )( 
            ISpThreadControl * This);
        
        END_INTERFACE
    } ISpThreadControlVtbl;

    interface ISpThreadControl
    {
        CONST_VTBL struct ISpThreadControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpThreadControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpThreadControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpThreadControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpThreadControl_Notify(This)	\
    ( (This)->lpVtbl -> Notify(This) ) 


#define ISpThreadControl_StartThread(This,dwFlags,phwnd)	\
    ( (This)->lpVtbl -> StartThread(This,dwFlags,phwnd) ) 

#define ISpThreadControl_WaitForThreadDone(This,fForceStop,phrThreadResult,msTimeOut)	\
    ( (This)->lpVtbl -> WaitForThreadDone(This,fForceStop,phrThreadResult,msTimeOut) ) 

#define ISpThreadControl_TerminateThread(This)	\
    ( (This)->lpVtbl -> TerminateThread(This) ) 

#define ISpThreadControl_ThreadHandle(This)	\
    ( (This)->lpVtbl -> ThreadHandle(This) ) 

#define ISpThreadControl_ThreadId(This)	\
    ( (This)->lpVtbl -> ThreadId(This) ) 

#define ISpThreadControl_NotifyEvent(This)	\
    ( (This)->lpVtbl -> NotifyEvent(This) ) 

#define ISpThreadControl_WindowHandle(This)	\
    ( (This)->lpVtbl -> WindowHandle(This) ) 

#define ISpThreadControl_ThreadCompleteEvent(This)	\
    ( (This)->lpVtbl -> ThreadCompleteEvent(This) ) 

#define ISpThreadControl_ExitThreadEvent(This)	\
    ( (This)->lpVtbl -> ExitThreadEvent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpThreadControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0009 */
/* [local] */ 

typedef /* [restricted] */ struct SPTMTHREADINFO
    {
    long lPoolSize;
    long lPriority;
    ULONG ulConcurrencyLimit;
    ULONG ulMaxQuickAllocThreads;
    } 	SPTMTHREADINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0009_v0_0_s_ifspec;

#ifndef __ISpTaskManager_INTERFACE_DEFINED__
#define __ISpTaskManager_INTERFACE_DEFINED__

/* interface ISpTaskManager */
/* [object][restricted][unique][helpstring][uuid][local] */ 


EXTERN_C const IID IID_ISpTaskManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BAEEF81-2CA3-4331-98F3-26EC5ABEFB03")
    ISpTaskManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetThreadPoolInfo( 
            /* [in] */ const SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadPoolInfo( 
            /* [out] */ SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueTask( 
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out][in] */ DWORD *pdwGroupId,
            /* [out] */ DWORD *pTaskID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateReoccurringTask( 
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out] */ ISpNotifySink **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateThreadControl( 
            /* [in] */ ISpThreadTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ long nPriority,
            /* [out] */ ISpThreadControl **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTask( 
            /* [in] */ DWORD dwTaskId,
            /* [in] */ ULONG ulWaitPeriod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTaskGroup( 
            /* [in] */ DWORD dwGroupId,
            /* [in] */ ULONG ulWaitPeriod) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpTaskManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTaskManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTaskManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTaskManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [in] */ const SPTMTHREADINFO *pPoolInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [out] */ SPTMTHREADINFO *pPoolInfo);
        
        HRESULT ( STDMETHODCALLTYPE *QueueTask )( 
            ISpTaskManager * This,
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out][in] */ DWORD *pdwGroupId,
            /* [out] */ DWORD *pTaskID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateReoccurringTask )( 
            ISpTaskManager * This,
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out] */ ISpNotifySink **ppTaskCtrl);
        
        HRESULT ( STDMETHODCALLTYPE *CreateThreadControl )( 
            ISpTaskManager * This,
            /* [in] */ ISpThreadTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ long nPriority,
            /* [out] */ ISpThreadControl **ppTaskCtrl);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateTask )( 
            ISpTaskManager * This,
            /* [in] */ DWORD dwTaskId,
            /* [in] */ ULONG ulWaitPeriod);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateTaskGroup )( 
            ISpTaskManager * This,
            /* [in] */ DWORD dwGroupId,
            /* [in] */ ULONG ulWaitPeriod);
        
        END_INTERFACE
    } ISpTaskManagerVtbl;

    interface ISpTaskManager
    {
        CONST_VTBL struct ISpTaskManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTaskManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTaskManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTaskManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTaskManager_SetThreadPoolInfo(This,pPoolInfo)	\
    ( (This)->lpVtbl -> SetThreadPoolInfo(This,pPoolInfo) ) 

#define ISpTaskManager_GetThreadPoolInfo(This,pPoolInfo)	\
    ( (This)->lpVtbl -> GetThreadPoolInfo(This,pPoolInfo) ) 

#define ISpTaskManager_QueueTask(This,pTask,pvTaskData,hCompEvent,pdwGroupId,pTaskID)	\
    ( (This)->lpVtbl -> QueueTask(This,pTask,pvTaskData,hCompEvent,pdwGroupId,pTaskID) ) 

#define ISpTaskManager_CreateReoccurringTask(This,pTask,pvTaskData,hCompEvent,ppTaskCtrl)	\
    ( (This)->lpVtbl -> CreateReoccurringTask(This,pTask,pvTaskData,hCompEvent,ppTaskCtrl) ) 

#define ISpTaskManager_CreateThreadControl(This,pTask,pvTaskData,nPriority,ppTaskCtrl)	\
    ( (This)->lpVtbl -> CreateThreadControl(This,pTask,pvTaskData,nPriority,ppTaskCtrl) ) 

#define ISpTaskManager_TerminateTask(This,dwTaskId,ulWaitPeriod)	\
    ( (This)->lpVtbl -> TerminateTask(This,dwTaskId,ulWaitPeriod) ) 

#define ISpTaskManager_TerminateTaskGroup(This,dwGroupId,ulWaitPeriod)	\
    ( (This)->lpVtbl -> TerminateTaskGroup(This,dwGroupId,ulWaitPeriod) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTaskManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0010 */
/* [local] */ 

typedef 
enum SPVSKIPTYPE
    {	SPVST_SENTENCE	= ( 1L << 0 ) 
    } 	SPVSKIPTYPE;

typedef 
enum SPVESACTIONS
    {	SPVES_CONTINUE	= 0,
	SPVES_ABORT	= ( 1L << 0 ) ,
	SPVES_SKIP	= ( 1L << 1 ) ,
	SPVES_RATE	= ( 1L << 2 ) ,
	SPVES_VOLUME	= ( 1L << 3 ) 
    } 	SPVESACTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0010_v0_0_s_ifspec;

#ifndef __ISpTTSEngineSite_INTERFACE_DEFINED__
#define __ISpTTSEngineSite_INTERFACE_DEFINED__

/* interface ISpTTSEngineSite */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpTTSEngineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9880499B-CCE9-11d2-B503-00C04F797396")
    ISpTTSEngineSite : public ISpEventSink
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetActions( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ const void *pBuff,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRate( 
            /* [out] */ long *pRateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolume( 
            /* [out] */ USHORT *pusVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSkipInfo( 
            /* [out] */ SPVSKIPTYPE *peType,
            /* [out] */ long *plNumItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompleteSkip( 
            /* [in] */ long ulNumSkipped) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngineSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngineSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvents )( 
            ISpTTSEngineSite * This,
            /* [in] */ const SPEVENT *pEventArray,
            /* [in] */ ULONG ulCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventInterest )( 
            ISpTTSEngineSite * This,
            /* [out] */ ULONGLONG *pullEventInterest);
        
        DWORD ( STDMETHODCALLTYPE *GetActions )( 
            ISpTTSEngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpTTSEngineSite * This,
            /* [in] */ const void *pBuff,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            ISpTTSEngineSite * This,
            /* [out] */ long *pRateAdjust);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            ISpTTSEngineSite * This,
            /* [out] */ USHORT *pusVolume);
        
        HRESULT ( STDMETHODCALLTYPE *GetSkipInfo )( 
            ISpTTSEngineSite * This,
            /* [out] */ SPVSKIPTYPE *peType,
            /* [out] */ long *plNumItems);
        
        HRESULT ( STDMETHODCALLTYPE *CompleteSkip )( 
            ISpTTSEngineSite * This,
            /* [in] */ long ulNumSkipped);
        
        END_INTERFACE
    } ISpTTSEngineSiteVtbl;

    interface ISpTTSEngineSite
    {
        CONST_VTBL struct ISpTTSEngineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTTSEngineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTTSEngineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTTSEngineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTTSEngineSite_AddEvents(This,pEventArray,ulCount)	\
    ( (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount) ) 

#define ISpTTSEngineSite_GetEventInterest(This,pullEventInterest)	\
    ( (This)->lpVtbl -> GetEventInterest(This,pullEventInterest) ) 


#define ISpTTSEngineSite_GetActions(This)	\
    ( (This)->lpVtbl -> GetActions(This) ) 

#define ISpTTSEngineSite_Write(This,pBuff,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pBuff,cb,pcbWritten) ) 

#define ISpTTSEngineSite_GetRate(This,pRateAdjust)	\
    ( (This)->lpVtbl -> GetRate(This,pRateAdjust) ) 

#define ISpTTSEngineSite_GetVolume(This,pusVolume)	\
    ( (This)->lpVtbl -> GetVolume(This,pusVolume) ) 

#define ISpTTSEngineSite_GetSkipInfo(This,peType,plNumItems)	\
    ( (This)->lpVtbl -> GetSkipInfo(This,peType,plNumItems) ) 

#define ISpTTSEngineSite_CompleteSkip(This,ulNumSkipped)	\
    ( (This)->lpVtbl -> CompleteSkip(This,ulNumSkipped) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTTSEngineSite_INTERFACE_DEFINED__ */


#ifndef __ISpPromptEngineSite_INTERFACE_DEFINED__
#define __ISpPromptEngineSite_INTERFACE_DEFINED__

/* interface ISpPromptEngineSite */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpPromptEngineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08F4AD5C-B3C6-472E-9B61-37854B7B9CD2")
    ISpPromptEngineSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRemoteFile( 
            /* [string][in] */ LPCWSTR pszFileName,
            /* [out] */ IStream **ppStream,
            /* [out][annotation] */ 
            __deref_opt_out  LPWSTR *ppwcsMIMEType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpPromptEngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPromptEngineSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPromptEngineSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPromptEngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteFile )( 
            ISpPromptEngineSite * This,
            /* [string][in] */ LPCWSTR pszFileName,
            /* [out] */ IStream **ppStream,
            /* [out][annotation] */ 
            __deref_opt_out  LPWSTR *ppwcsMIMEType);
        
        END_INTERFACE
    } ISpPromptEngineSiteVtbl;

    interface ISpPromptEngineSite
    {
        CONST_VTBL struct ISpPromptEngineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPromptEngineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPromptEngineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPromptEngineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPromptEngineSite_GetRemoteFile(This,pszFileName,ppStream,ppwcsMIMEType)	\
    ( (This)->lpVtbl -> GetRemoteFile(This,pszFileName,ppStream,ppwcsMIMEType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPromptEngineSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0012 */
/* [local] */ 

typedef struct SPVTEXTFRAG
    {
    struct SPVTEXTFRAG *pNext;
    SPVSTATE State;
    LPCWSTR pTextStart;
    ULONG ulTextLen;
    ULONG ulTextSrcOffset;
    } 	SPVTEXTFRAG;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0012_v0_0_s_ifspec;

#ifndef __ISpTTSEngine_INTERFACE_DEFINED__
#define __ISpTTSEngine_INTERFACE_DEFINED__

/* interface ISpTTSEngine */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpTTSEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A74D7C8E-4CC5-4f2f-A6EB-804DEE18500E")
    ISpTTSEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ DWORD dwSpeakFlags,
            /* [in] */ REFGUID rguidFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ const SPVTEXTFRAG *pTextFragList,
            /* [in] */ ISpTTSEngineSite *pOutputSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [in] */ const GUID *pTargetFmtId,
            /* [in] */ const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [out] */ GUID *pOutputFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemOutputWaveFormatEx) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *Speak )( 
            ISpTTSEngine * This,
            /* [in] */ DWORD dwSpeakFlags,
            /* [in] */ REFGUID rguidFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ const SPVTEXTFRAG *pTextFragList,
            /* [in] */ ISpTTSEngineSite *pOutputSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            ISpTTSEngine * This,
            /* [in] */ const GUID *pTargetFmtId,
            /* [in] */ const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [out] */ GUID *pOutputFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemOutputWaveFormatEx);
        
        END_INTERFACE
    } ISpTTSEngineVtbl;

    interface ISpTTSEngine
    {
        CONST_VTBL struct ISpTTSEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTTSEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTTSEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTTSEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTTSEngine_Speak(This,dwSpeakFlags,rguidFormatId,pWaveFormatEx,pTextFragList,pOutputSite)	\
    ( (This)->lpVtbl -> Speak(This,dwSpeakFlags,rguidFormatId,pWaveFormatEx,pTextFragList,pOutputSite) ) 

#define ISpTTSEngine_GetOutputFormat(This,pTargetFmtId,pTargetWaveFormatEx,pOutputFormatId,ppCoMemOutputWaveFormatEx)	\
    ( (This)->lpVtbl -> GetOutputFormat(This,pTargetFmtId,pTargetWaveFormatEx,pOutputFormatId,ppCoMemOutputWaveFormatEx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTTSEngine_INTERFACE_DEFINED__ */


#ifndef __ISpPromptEngine_INTERFACE_DEFINED__
#define __ISpPromptEngine_INTERFACE_DEFINED__

/* interface ISpPromptEngine */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpPromptEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E27E125-0243-4C26-BA1E-9D5E91E3145B")
    ISpPromptEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBackupVoice( 
            /* [in] */ ISpObjectToken *pVoiceToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadDatabase( 
            /* [string][in] */ LPCWSTR pwcsLocalName,
            /* [string][in] */ LPCWSTR pwcsAlias) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadDatabase( 
            /* [string][in] */ LPCWSTR pwcsAlias) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpPromptEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPromptEngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPromptEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPromptEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBackupVoice )( 
            ISpPromptEngine * This,
            /* [in] */ ISpObjectToken *pVoiceToken);
        
        HRESULT ( STDMETHODCALLTYPE *LoadDatabase )( 
            ISpPromptEngine * This,
            /* [string][in] */ LPCWSTR pwcsLocalName,
            /* [string][in] */ LPCWSTR pwcsAlias);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadDatabase )( 
            ISpPromptEngine * This,
            /* [string][in] */ LPCWSTR pwcsAlias);
        
        END_INTERFACE
    } ISpPromptEngineVtbl;

    interface ISpPromptEngine
    {
        CONST_VTBL struct ISpPromptEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPromptEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPromptEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPromptEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPromptEngine_SetBackupVoice(This,pVoiceToken)	\
    ( (This)->lpVtbl -> SetBackupVoice(This,pVoiceToken) ) 

#define ISpPromptEngine_LoadDatabase(This,pwcsLocalName,pwcsAlias)	\
    ( (This)->lpVtbl -> LoadDatabase(This,pwcsLocalName,pwcsAlias) ) 

#define ISpPromptEngine_UnloadDatabase(This,pwcsAlias)	\
    ( (This)->lpVtbl -> UnloadDatabase(This,pwcsAlias) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPromptEngine_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0014 */
/* [local] */ 

typedef /* [restricted] */ struct SPWORDENTRY
    {
    SPWORDHANDLE hWord;
    WORD LangID;
    WCHAR *pszDisplayText;
    WCHAR *pszLexicalForm;
    SPPHONEID *aPhoneId;
    void *pvClientContext;
    } 	SPWORDENTRY;

typedef /* [restricted] */ struct SPRULEENTRY
    {
    SPRULEHANDLE hRule;
    SPSTATEHANDLE hInitialState;
    DWORD Attributes;
    void *pvClientRuleContext;
    void *pvClientGrammarContext;
    } 	SPRULEENTRY;

typedef 
enum SPTRANSITIONTYPE
    {	SPTRANSEPSILON	= 0,
	SPTRANSWORD	= ( SPTRANSEPSILON + 1 ) ,
	SPTRANSRULE	= ( SPTRANSWORD + 1 ) ,
	SPTRANSTEXTBUF	= ( SPTRANSRULE + 1 ) ,
	SPTRANSWILDCARD	= ( SPTRANSTEXTBUF + 1 ) ,
	SPTRANSDICTATION	= ( SPTRANSWILDCARD + 1 ) 
    } 	SPTRANSITIONTYPE;

typedef /* [restricted] */ struct SPTRANSITIONENTRY
    {
    SPTRANSITIONID ID;
    SPSTATEHANDLE hNextState;
    BYTE Type;
    char RequiredConfidence;
    struct 
        {
        DWORD fHasProperty;
        } 	;
    float Weight;
    union 
        {
        struct 
            {
            SPSTATEHANDLE hRuleInitialState;
            SPRULEHANDLE hRule;
            void *pvClientRuleContext;
            } 	;
        struct 
            {
            SPWORDHANDLE hWord;
            void *pvClientWordContext;
            } 	;
        struct 
            {
            void *pvGrammarCookie;
            } 	;
        } 	;
    } 	SPTRANSITIONENTRY;

typedef /* [restricted] */ struct SPTRANSITIONPROPERTY
    {
    LPCWSTR pszName;
    ULONG ulId;
    LPCWSTR pszValue;
    VARIANT vValue;
    } 	SPTRANSITIONPROPERTY;

typedef /* [restricted] */ struct SPSTATEINFO
    {
    ULONG cAllocatedEntries;
    SPTRANSITIONENTRY *pTransitions;
    ULONG cEpsilons;
    ULONG cRules;
    ULONG cWords;
    ULONG cSpecialTransitions;
    } 	SPSTATEINFO;

typedef /* [restricted] */ struct SPPATHENTRY
    {
    SPTRANSITIONID hTransition;
    SPPHRASEELEMENT elem;
    } 	SPPATHENTRY;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0014_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0014_v0_0_s_ifspec;

#ifndef __ISpCFGInterpreterSite_INTERFACE_DEFINED__
#define __ISpCFGInterpreterSite_INTERFACE_DEFINED__

/* interface ISpCFGInterpreterSite */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpCFGInterpreterSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A6FFAD8-78B6-473d-B844-98152E4FB16B")
    ISpCFGInterpreterSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddTextReplacement( 
            /* [in] */ SPPHRASEREPLACEMENT *pReplace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ const SPPHRASEPROPERTY *pProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceValue( 
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemResource) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreterSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreterSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddTextReplacement )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ SPPHRASEREPLACEMENT *pReplace);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ const SPPHRASEPROPERTY *pProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceValue )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemResource);
        
        END_INTERFACE
    } ISpCFGInterpreterSiteVtbl;

    interface ISpCFGInterpreterSite
    {
        CONST_VTBL struct ISpCFGInterpreterSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpCFGInterpreterSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpCFGInterpreterSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpCFGInterpreterSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpCFGInterpreterSite_AddTextReplacement(This,pReplace)	\
    ( (This)->lpVtbl -> AddTextReplacement(This,pReplace) ) 

#define ISpCFGInterpreterSite_AddProperty(This,pProperty)	\
    ( (This)->lpVtbl -> AddProperty(This,pProperty) ) 

#define ISpCFGInterpreterSite_GetResourceValue(This,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResourceValue(This,pszResourceName,ppCoMemResource) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpCFGInterpreterSite_INTERFACE_DEFINED__ */


#ifndef __ISpCFGInterpreter_INTERFACE_DEFINED__
#define __ISpCFGInterpreter_INTERFACE_DEFINED__

/* interface ISpCFGInterpreter */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpCFGInterpreter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3D3F926-11FC-11d3-BB97-00C04F8EE6C0")
    ISpCFGInterpreter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitGrammar( 
            /* [in] */ LPCWSTR pszGrammarName,
            /* [in] */ const void **pvGrammarData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interpret( 
            /* [in] */ ISpPhraseBuilder *pPhrase,
            /* [in] */ const ULONG ulFirstElement,
            /* [in] */ const ULONG ulCountOfElements,
            /* [in] */ ISpCFGInterpreterSite *pSite) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreter * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitGrammar )( 
            ISpCFGInterpreter * This,
            /* [in] */ LPCWSTR pszGrammarName,
            /* [in] */ const void **pvGrammarData);
        
        HRESULT ( STDMETHODCALLTYPE *Interpret )( 
            ISpCFGInterpreter * This,
            /* [in] */ ISpPhraseBuilder *pPhrase,
            /* [in] */ const ULONG ulFirstElement,
            /* [in] */ const ULONG ulCountOfElements,
            /* [in] */ ISpCFGInterpreterSite *pSite);
        
        END_INTERFACE
    } ISpCFGInterpreterVtbl;

    interface ISpCFGInterpreter
    {
        CONST_VTBL struct ISpCFGInterpreterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpCFGInterpreter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpCFGInterpreter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpCFGInterpreter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpCFGInterpreter_InitGrammar(This,pszGrammarName,pvGrammarData)	\
    ( (This)->lpVtbl -> InitGrammar(This,pszGrammarName,pvGrammarData) ) 

#define ISpCFGInterpreter_Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite)	\
    ( (This)->lpVtbl -> Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpCFGInterpreter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0016 */
/* [local] */ 

typedef 
enum SPCFGNOTIFY
    {	SPCFGN_ADD	= 0,
	SPCFGN_REMOVE	= ( SPCFGN_ADD + 1 ) ,
	SPCFGN_INVALIDATE	= ( SPCFGN_REMOVE + 1 ) ,
	SPCFGN_ACTIVATE	= ( SPCFGN_INVALIDATE + 1 ) ,
	SPCFGN_DEACTIVATE	= ( SPCFGN_ACTIVATE + 1 ) 
    } 	SPCFGNOTIFY;

typedef 
enum SPRESULTTYPE
    {	SPRT_CFG	= 0,
	SPRT_SLM	= 1,
	SPRT_PROPRIETARY	= 2,
	SPRT_TYPE_MASK	= 3,
	SPRT_FALSE_RECOGNITION	= ( 1L << 2 ) ,
	SPRT_EMULATED	= ( 1L << 3 ) ,
	SPRT_EXTENDABLE_PARSE	= ( 1L << 4 ) ,
	SPRT_SIMULATED	= ( 1L << 5 ) 
    } 	SPRESULTTYPE;

typedef struct tagSPPHRASEALT
    {
    ISpPhraseBuilder *pPhrase;
    ULONG ulStartElementInParent;
    ULONG cElementsInParent;
    ULONG cElementsInAlternate;
    void *pvAltExtra;
    ULONG cbAltExtra;
    } 	SPPHRASEALT;

typedef struct SPRECORESULTINFO
    {
    ULONG cbSize;
    SPRESULTTYPE eResultType;
    BOOL fHypothesis;
    BOOL fProprietaryAutoPause;
    ULONGLONG ullStreamPosStart;
    ULONGLONG ullStreamPosEnd;
    SPGRAMMARHANDLE hGrammar;
    ULONG ulSizeEngineData;
    void *pvEngineData;
    ISpPhraseBuilder *pPhrase;
    SPPHRASEALT *aPhraseAlts;
    ULONG ulNumAlts;
    } 	SPRECORESULTINFO;

#if 0
typedef struct SPRECORESULTINFOEX
    {
    ULONG cbSize;
    SPRESULTTYPE eResultType;
    BOOL fHypothesis;
    BOOL fProprietaryAutoPause;
    ULONGLONG ullStreamPosStart;
    ULONGLONG ullStreamPosEnd;
    SPGRAMMARHANDLE hGrammar;
    ULONG ulSizeEngineData;
    void *pvEngineData;
    ISpPhraseBuilder *pPhrase;
    SPPHRASEALT *aPhraseAlts;
    ULONG ulNumAlts;
    ULONGLONG ullStreamTimeStart;
    ULONGLONG ullStreamTimeEnd;
    } 	SPRECORESULTINFOEX;

#else
typedef struct SPRECORESULTINFOEX : public SPRECORESULTINFO
{
    ULONGLONG         ullStreamTimeStart;
    ULONGLONG         ullStreamTimeEnd;
} SPRECORESULTINFOEX;
#endif
typedef 
enum SPWORDINFOOPT
    {	SPWIO_NONE	= 0,
	SPWIO_WANT_TEXT	= 1
    } 	SPWORDINFOOPT;

typedef 
enum SPRULEINFOOPT
    {	SPRIO_NONE	= 0
    } 	SPRULEINFOOPT;

typedef struct SPPARSEINFO
    {
    ULONG cbSize;
    SPRULEHANDLE hRule;
    ULONGLONG ullAudioStreamPosition;
    ULONG ulAudioSize;
    ULONG cTransitions;
    SPPATHENTRY *pPath;
    GUID SREngineID;
    ULONG ulSREnginePrivateDataSize;
    const BYTE *pSREnginePrivateData;
    BOOL fHypothesis;
    } 	SPPARSEINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0016_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0016_v0_0_s_ifspec;

#ifndef __ISpSREngineSite_INTERFACE_DEFINED__
#define __ISpSREngineSite_INTERFACE_DEFINED__

/* interface ISpSREngineSite */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B414AEC-720C-4883-B9EF-178CD394FB3A")
    ISpSREngineSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataAvailable( 
            /* [out] */ ULONG *pcb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferNotifySize( 
            /* [in] */ ULONG cbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseFromTransitions( 
            /* [in] */ const SPPARSEINFO *pParseInfo,
            /* [out] */ ISpPhraseBuilder **ppNewPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recognition( 
            /* [in] */ const SPRECORESULTINFO *pResultInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEvent( 
            /* [in] */ const SPEVENT *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [in] */ ULONGLONG ullProcessedThruPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWordInfo( 
            /* [out][in] */ SPWORDENTRY *pWordEntry,
            /* [in] */ SPWORDINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordClientContext( 
            SPWORDHANDLE hWord,
            void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuleInfo( 
            /* [out][in] */ SPRULEENTRY *pRuleEntry,
            /* [in] */ SPRULEINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleClientContext( 
            SPRULEHANDLE hRule,
            void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateInfo( 
            SPSTATEHANDLE hState,
            SPSTATEINFO *pStateInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResource( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransitionProperty( 
            /* [in] */ SPTRANSITIONID ID,
            /* [out] */ SPTRANSITIONPROPERTY **ppCoMemProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAlternate( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ SPRULEHANDLE hAltRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxAlternates( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [out] */ ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMaxAlternates( 
            /* [in] */ SPRECOCONTEXTHANDLE hContext,
            /* [out] */ ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRecoPos( 
            /* [in] */ ULONGLONG ullCurrentRecoPos) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSREngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngineSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngineSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpSREngineSite * This,
            /* [in] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead);
        
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ISpSREngineSite * This,
            /* [out] */ ULONG *pcb);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpSREngineSite * This,
            /* [in] */ ULONG cbSize);
        
        HRESULT ( STDMETHODCALLTYPE *ParseFromTransitions )( 
            ISpSREngineSite * This,
            /* [in] */ const SPPARSEINFO *pParseInfo,
            /* [out] */ ISpPhraseBuilder **ppNewPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *Recognition )( 
            ISpSREngineSite * This,
            /* [in] */ const SPRECORESULTINFO *pResultInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvent )( 
            ISpSREngineSite * This,
            /* [in] */ const SPEVENT *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            ISpSREngineSite * This,
            /* [in] */ ULONGLONG ullProcessedThruPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetWordInfo )( 
            ISpSREngineSite * This,
            /* [out][in] */ SPWORDENTRY *pWordEntry,
            /* [in] */ SPWORDINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordClientContext )( 
            ISpSREngineSite * This,
            SPWORDHANDLE hWord,
            void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuleInfo )( 
            ISpSREngineSite * This,
            /* [out][in] */ SPRULEENTRY *pRuleEntry,
            /* [in] */ SPRULEINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleClientContext )( 
            ISpSREngineSite * This,
            SPRULEHANDLE hRule,
            void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateInfo )( 
            ISpSREngineSite * This,
            SPSTATEHANDLE hState,
            SPSTATEINFO *pStateInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransitionProperty )( 
            ISpSREngineSite * This,
            /* [in] */ SPTRANSITIONID ID,
            /* [out] */ SPTRANSITIONPROPERTY **ppCoMemProperty);
        
        HRESULT ( STDMETHODCALLTYPE *IsAlternate )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ SPRULEHANDLE hAltRule);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMaxAlternates )( 
            ISpSREngineSite * This,
            /* [in] */ SPRECOCONTEXTHANDLE hContext,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPos )( 
            ISpSREngineSite * This,
            /* [in] */ ULONGLONG ullCurrentRecoPos);
        
        END_INTERFACE
    } ISpSREngineSiteVtbl;

    interface ISpSREngineSite
    {
        CONST_VTBL struct ISpSREngineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngineSite_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpSREngineSite_DataAvailable(This,pcb)	\
    ( (This)->lpVtbl -> DataAvailable(This,pcb) ) 

#define ISpSREngineSite_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 

#define ISpSREngineSite_ParseFromTransitions(This,pParseInfo,ppNewPhrase)	\
    ( (This)->lpVtbl -> ParseFromTransitions(This,pParseInfo,ppNewPhrase) ) 

#define ISpSREngineSite_Recognition(This,pResultInfo)	\
    ( (This)->lpVtbl -> Recognition(This,pResultInfo) ) 

#define ISpSREngineSite_AddEvent(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEvent(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite_Synchronize(This,ullProcessedThruPos)	\
    ( (This)->lpVtbl -> Synchronize(This,ullProcessedThruPos) ) 

#define ISpSREngineSite_GetWordInfo(This,pWordEntry,Options)	\
    ( (This)->lpVtbl -> GetWordInfo(This,pWordEntry,Options) ) 

#define ISpSREngineSite_SetWordClientContext(This,hWord,pvClientContext)	\
    ( (This)->lpVtbl -> SetWordClientContext(This,hWord,pvClientContext) ) 

#define ISpSREngineSite_GetRuleInfo(This,pRuleEntry,Options)	\
    ( (This)->lpVtbl -> GetRuleInfo(This,pRuleEntry,Options) ) 

#define ISpSREngineSite_SetRuleClientContext(This,hRule,pvClientContext)	\
    ( (This)->lpVtbl -> SetRuleClientContext(This,hRule,pvClientContext) ) 

#define ISpSREngineSite_GetStateInfo(This,hState,pStateInfo)	\
    ( (This)->lpVtbl -> GetStateInfo(This,hState,pStateInfo) ) 

#define ISpSREngineSite_GetResource(This,hRule,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResource(This,hRule,pszResourceName,ppCoMemResource) ) 

#define ISpSREngineSite_GetTransitionProperty(This,ID,ppCoMemProperty)	\
    ( (This)->lpVtbl -> GetTransitionProperty(This,ID,ppCoMemProperty) ) 

#define ISpSREngineSite_IsAlternate(This,hRule,hAltRule)	\
    ( (This)->lpVtbl -> IsAlternate(This,hRule,hAltRule) ) 

#define ISpSREngineSite_GetMaxAlternates(This,hRule,pulNumAlts)	\
    ( (This)->lpVtbl -> GetMaxAlternates(This,hRule,pulNumAlts) ) 

#define ISpSREngineSite_GetContextMaxAlternates(This,hContext,pulNumAlts)	\
    ( (This)->lpVtbl -> GetContextMaxAlternates(This,hContext,pulNumAlts) ) 

#define ISpSREngineSite_UpdateRecoPos(This,ullCurrentRecoPos)	\
    ( (This)->lpVtbl -> UpdateRecoPos(This,ullCurrentRecoPos) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngineSite_INTERFACE_DEFINED__ */


#ifndef __ISpSREngineSite2_INTERFACE_DEFINED__
#define __ISpSREngineSite2_INTERFACE_DEFINED__

/* interface ISpSREngineSite2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngineSite2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BC6E012-684A-493e-BDD4-2BF5FBF48CFE")
    ISpSREngineSite2 : public ISpSREngineSite
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddEventEx( 
            /* [in] */ const SPEVENTEX *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRecoPosEx( 
            /* [in] */ ULONGLONG ullCurrentRecoPos,
            ULONGLONG ullCurrentRecoTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuleTransition( 
            /* [in] */ ULONG ulGrammarID,
            /* [in] */ ULONG RuleIndex,
            /* [out] */ SPTRANSITIONENTRY *pTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecognitionEx( 
            /* [in] */ const SPRECORESULTINFOEX *pResultInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSREngineSite2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngineSite2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngineSite2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngineSite2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpSREngineSite2 * This,
            /* [in] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead);
        
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ISpSREngineSite2 * This,
            /* [out] */ ULONG *pcb);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpSREngineSite2 * This,
            /* [in] */ ULONG cbSize);
        
        HRESULT ( STDMETHODCALLTYPE *ParseFromTransitions )( 
            ISpSREngineSite2 * This,
            /* [in] */ const SPPARSEINFO *pParseInfo,
            /* [out] */ ISpPhraseBuilder **ppNewPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *Recognition )( 
            ISpSREngineSite2 * This,
            /* [in] */ const SPRECORESULTINFO *pResultInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvent )( 
            ISpSREngineSite2 * This,
            /* [in] */ const SPEVENT *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            ISpSREngineSite2 * This,
            /* [in] */ ULONGLONG ullProcessedThruPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetWordInfo )( 
            ISpSREngineSite2 * This,
            /* [out][in] */ SPWORDENTRY *pWordEntry,
            /* [in] */ SPWORDINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordClientContext )( 
            ISpSREngineSite2 * This,
            SPWORDHANDLE hWord,
            void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuleInfo )( 
            ISpSREngineSite2 * This,
            /* [out][in] */ SPRULEENTRY *pRuleEntry,
            /* [in] */ SPRULEINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleClientContext )( 
            ISpSREngineSite2 * This,
            SPRULEHANDLE hRule,
            void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateInfo )( 
            ISpSREngineSite2 * This,
            SPSTATEHANDLE hState,
            SPSTATEINFO *pStateInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            ISpSREngineSite2 * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransitionProperty )( 
            ISpSREngineSite2 * This,
            /* [in] */ SPTRANSITIONID ID,
            /* [out] */ SPTRANSITIONPROPERTY **ppCoMemProperty);
        
        HRESULT ( STDMETHODCALLTYPE *IsAlternate )( 
            ISpSREngineSite2 * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ SPRULEHANDLE hAltRule);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpSREngineSite2 * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMaxAlternates )( 
            ISpSREngineSite2 * This,
            /* [in] */ SPRECOCONTEXTHANDLE hContext,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPos )( 
            ISpSREngineSite2 * This,
            /* [in] */ ULONGLONG ullCurrentRecoPos);
        
        HRESULT ( STDMETHODCALLTYPE *AddEventEx )( 
            ISpSREngineSite2 * This,
            /* [in] */ const SPEVENTEX *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPosEx )( 
            ISpSREngineSite2 * This,
            /* [in] */ ULONGLONG ullCurrentRecoPos,
            ULONGLONG ullCurrentRecoTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuleTransition )( 
            ISpSREngineSite2 * This,
            /* [in] */ ULONG ulGrammarID,
            /* [in] */ ULONG RuleIndex,
            /* [out] */ SPTRANSITIONENTRY *pTrans);
        
        HRESULT ( STDMETHODCALLTYPE *RecognitionEx )( 
            ISpSREngineSite2 * This,
            /* [in] */ const SPRECORESULTINFOEX *pResultInfo);
        
        END_INTERFACE
    } ISpSREngineSite2Vtbl;

    interface ISpSREngineSite2
    {
        CONST_VTBL struct ISpSREngineSite2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngineSite2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngineSite2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngineSite2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngineSite2_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpSREngineSite2_DataAvailable(This,pcb)	\
    ( (This)->lpVtbl -> DataAvailable(This,pcb) ) 

#define ISpSREngineSite2_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 

#define ISpSREngineSite2_ParseFromTransitions(This,pParseInfo,ppNewPhrase)	\
    ( (This)->lpVtbl -> ParseFromTransitions(This,pParseInfo,ppNewPhrase) ) 

#define ISpSREngineSite2_Recognition(This,pResultInfo)	\
    ( (This)->lpVtbl -> Recognition(This,pResultInfo) ) 

#define ISpSREngineSite2_AddEvent(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEvent(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite2_Synchronize(This,ullProcessedThruPos)	\
    ( (This)->lpVtbl -> Synchronize(This,ullProcessedThruPos) ) 

#define ISpSREngineSite2_GetWordInfo(This,pWordEntry,Options)	\
    ( (This)->lpVtbl -> GetWordInfo(This,pWordEntry,Options) ) 

#define ISpSREngineSite2_SetWordClientContext(This,hWord,pvClientContext)	\
    ( (This)->lpVtbl -> SetWordClientContext(This,hWord,pvClientContext) ) 

#define ISpSREngineSite2_GetRuleInfo(This,pRuleEntry,Options)	\
    ( (This)->lpVtbl -> GetRuleInfo(This,pRuleEntry,Options) ) 

#define ISpSREngineSite2_SetRuleClientContext(This,hRule,pvClientContext)	\
    ( (This)->lpVtbl -> SetRuleClientContext(This,hRule,pvClientContext) ) 

#define ISpSREngineSite2_GetStateInfo(This,hState,pStateInfo)	\
    ( (This)->lpVtbl -> GetStateInfo(This,hState,pStateInfo) ) 

#define ISpSREngineSite2_GetResource(This,hRule,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResource(This,hRule,pszResourceName,ppCoMemResource) ) 

#define ISpSREngineSite2_GetTransitionProperty(This,ID,ppCoMemProperty)	\
    ( (This)->lpVtbl -> GetTransitionProperty(This,ID,ppCoMemProperty) ) 

#define ISpSREngineSite2_IsAlternate(This,hRule,hAltRule)	\
    ( (This)->lpVtbl -> IsAlternate(This,hRule,hAltRule) ) 

#define ISpSREngineSite2_GetMaxAlternates(This,hRule,pulNumAlts)	\
    ( (This)->lpVtbl -> GetMaxAlternates(This,hRule,pulNumAlts) ) 

#define ISpSREngineSite2_GetContextMaxAlternates(This,hContext,pulNumAlts)	\
    ( (This)->lpVtbl -> GetContextMaxAlternates(This,hContext,pulNumAlts) ) 

#define ISpSREngineSite2_UpdateRecoPos(This,ullCurrentRecoPos)	\
    ( (This)->lpVtbl -> UpdateRecoPos(This,ullCurrentRecoPos) ) 


#define ISpSREngineSite2_AddEventEx(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEventEx(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite2_UpdateRecoPosEx(This,ullCurrentRecoPos,ullCurrentRecoTime)	\
    ( (This)->lpVtbl -> UpdateRecoPosEx(This,ullCurrentRecoPos,ullCurrentRecoTime) ) 

#define ISpSREngineSite2_GetRuleTransition(This,ulGrammarID,RuleIndex,pTrans)	\
    ( (This)->lpVtbl -> GetRuleTransition(This,ulGrammarID,RuleIndex,pTrans) ) 

#define ISpSREngineSite2_RecognitionEx(This,pResultInfo)	\
    ( (This)->lpVtbl -> RecognitionEx(This,pResultInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngineSite2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0018 */
/* [local] */ 

typedef 
enum SPPROPSRC
    {	SPPROPSRC_RECO_INST	= 0,
	SPPROPSRC_RECO_CTX	= ( SPPROPSRC_RECO_INST + 1 ) ,
	SPPROPSRC_RECO_GRAMMAR	= ( SPPROPSRC_RECO_CTX + 1 ) 
    } 	SPPROPSRC;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0018_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0018_v0_0_s_ifspec;

#ifndef __ISpSREngine_INTERFACE_DEFINED__
#define __ISpSREngine_INTERFACE_DEFINED__

/* interface ISpSREngine */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F472991-854B-4465-B613-FBAFB3AD8ED8")
    ISpSREngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSite( 
            /* [in] */ ISpSREngineSite *pSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputAudioFormat( 
            /* [in] */ const GUID *pguidSourceFormatId,
            /* [in] */ const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [out] */ GUID *pguidDesiredFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemDesiredWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecognizeStream( 
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ HANDLE hRequestSync,
            /* [in] */ HANDLE hDataAvailable,
            /* [in] */ HANDLE hExit,
            /* [in] */ BOOL fNewAudioStream,
            /* [in] */ BOOL fRealTimeAudio,
            /* [in] */ ISpObjectToken *pAudioObjectToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoProfile( 
            ISpObjectToken *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateGrammar( 
            /* [in] */ void *pvEngineRecoContext,
            /* [in] */ SPGRAMMARHANDLE hSAPIGrammar,
            /* [out] */ void **ppvEngineGrammarContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteGrammar( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProprietaryGrammar( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataParam,
            /* [in] */ ULONG ulDataSize,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadProprietaryGrammar( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleState( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState,
            /* [out] */ ULONG *pcRulesChanged) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleIdState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadSLM( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszTopicName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadSLM( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSLMState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [in] */ void *pvEngineGrammar,
            /* [in][annotation] */ 
            __in_ecount(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateRecoContext( 
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [out] */ void **ppvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteRecoContext( 
            /* [in] */ void *pvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCall( 
            /* [in] */ void *pvEngineContext,
            /* [out][in] */ PVOID pCallFrame,
            /* [in] */ ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [in] */ void *pvEngineContext,
            /* [annotation] */ 
            __in_ecount(cch)  const WCHAR *pAdaptationData,
            const ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyNum( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [in] */ LONG lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyNum( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [out] */ LONG *lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPGRAMMARSTATE eGrammarState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WordNotify( 
            SPCFGNOTIFY Action,
            ULONG cWords,
            const SPWORDENTRY *pWords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RuleNotify( 
            SPCFGNOTIFY Action,
            ULONG cRules,
            const SPRULEENTRY *pRules) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCallEx( 
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextState( 
            /* [in] */ void *pvEngineContext,
            /* [in] */ SPCONTEXTSTATE eContextState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSREngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            ISpSREngine * This,
            /* [in] */ ISpSREngineSite *pSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputAudioFormat )( 
            ISpSREngine * This,
            /* [in] */ const GUID *pguidSourceFormatId,
            /* [in] */ const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [out] */ GUID *pguidDesiredFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemDesiredWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *RecognizeStream )( 
            ISpSREngine * This,
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ HANDLE hRequestSync,
            /* [in] */ HANDLE hDataAvailable,
            /* [in] */ HANDLE hExit,
            /* [in] */ BOOL fNewAudioStream,
            /* [in] */ BOOL fRealTimeAudio,
            /* [in] */ ISpObjectToken *pAudioObjectToken);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpSREngine * This,
            ISpObjectToken *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineRecoContext,
            /* [in] */ SPGRAMMARHANDLE hSAPIGrammar,
            /* [out] */ void **ppvEngineGrammarContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *LoadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataParam,
            /* [in] */ ULONG ulDataSize,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState,
            /* [out] */ ULONG *pcRulesChanged);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleIdState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *LoadSLM )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszTopicName);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadSLM )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetSLMState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in][annotation] */ 
            __in_ecount(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateRecoContext )( 
            ISpSREngine * This,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [out] */ void **ppvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteRecoContext )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCall )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [out][in] */ PVOID pCallFrame,
            /* [in] */ ULONG ulCallFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [annotation] */ 
            __in_ecount(cch)  const WCHAR *pAdaptationData,
            const ULONG cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [in] */ LONG lValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [out] */ LONG *lValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPGRAMMARSTATE eGrammarState);
        
        HRESULT ( STDMETHODCALLTYPE *WordNotify )( 
            ISpSREngine * This,
            SPCFGNOTIFY Action,
            ULONG cWords,
            const SPWORDENTRY *pWords);
        
        HRESULT ( STDMETHODCALLTYPE *RuleNotify )( 
            ISpSREngine * This,
            SPCFGNOTIFY Action,
            ULONG cRules,
            const SPRULEENTRY *pRules);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCallEx )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ SPCONTEXTSTATE eContextState);
        
        END_INTERFACE
    } ISpSREngineVtbl;

    interface ISpSREngine
    {
        CONST_VTBL struct ISpSREngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngine_SetSite(This,pSite)	\
    ( (This)->lpVtbl -> SetSite(This,pSite) ) 

#define ISpSREngine_GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx)	\
    ( (This)->lpVtbl -> GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx) ) 

#define ISpSREngine_RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken)	\
    ( (This)->lpVtbl -> RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken) ) 

#define ISpSREngine_SetRecoProfile(This,pProfile)	\
    ( (This)->lpVtbl -> SetRecoProfile(This,pProfile) ) 

#define ISpSREngine_OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext)	\
    ( (This)->lpVtbl -> OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext) ) 

#define ISpSREngine_OnDeleteGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> OnDeleteGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine_LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options)	\
    ( (This)->lpVtbl -> LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options) ) 

#define ISpSREngine_UnloadProprietaryGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadProprietaryGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine_SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged)	\
    ( (This)->lpVtbl -> SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged) ) 

#define ISpSREngine_SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState)	\
    ( (This)->lpVtbl -> SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState) ) 

#define ISpSREngine_LoadSLM(This,pvEngineGrammar,pszTopicName)	\
    ( (This)->lpVtbl -> LoadSLM(This,pvEngineGrammar,pszTopicName) ) 

#define ISpSREngine_UnloadSLM(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadSLM(This,pvEngineGrammar) ) 

#define ISpSREngine_SetSLMState(This,pvEngineGrammar,NewState)	\
    ( (This)->lpVtbl -> SetSLMState(This,pvEngineGrammar,NewState) ) 

#define ISpSREngine_SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo) ) 

#define ISpSREngine_SetTextSelection(This,pvEngineGrammar,pInfo)	\
    ( (This)->lpVtbl -> SetTextSelection(This,pvEngineGrammar,pInfo) ) 

#define ISpSREngine_IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable) ) 

#define ISpSREngine_OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext)	\
    ( (This)->lpVtbl -> OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext) ) 

#define ISpSREngine_OnDeleteRecoContext(This,pvEngineContext)	\
    ( (This)->lpVtbl -> OnDeleteRecoContext(This,pvEngineContext) ) 

#define ISpSREngine_PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize) ) 

#define ISpSREngine_SetAdaptationData(This,pvEngineContext,pAdaptationData,cch)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,pvEngineContext,pAdaptationData,cch) ) 

#define ISpSREngine_SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine_GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine_SetPropertyString(This,eSrc,pvSrcObj,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,eSrc,pvSrcObj,pName,pValue) ) 

#define ISpSREngine_GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue) ) 

#define ISpSREngine_SetGrammarState(This,pvEngineGrammar,eGrammarState)	\
    ( (This)->lpVtbl -> SetGrammarState(This,pvEngineGrammar,eGrammarState) ) 

#define ISpSREngine_WordNotify(This,Action,cWords,pWords)	\
    ( (This)->lpVtbl -> WordNotify(This,Action,cWords,pWords) ) 

#define ISpSREngine_RuleNotify(This,Action,cRules,pRules)	\
    ( (This)->lpVtbl -> RuleNotify(This,Action,cRules,pRules) ) 

#define ISpSREngine_PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine_SetContextState(This,pvEngineContext,eContextState)	\
    ( (This)->lpVtbl -> SetContextState(This,pvEngineContext,eContextState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngine_INTERFACE_DEFINED__ */


#ifndef __ISpSREngine2_INTERFACE_DEFINED__
#define __ISpSREngine2_INTERFACE_DEFINED__

/* interface ISpSREngine2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngine2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BA627D8-33F9-4375-90C5-9985AEE5EDE5")
    ISpSREngine2 : public ISpSREngine
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrivateCallImmediate( 
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData2( 
            /* [in] */ void *pvEngineContext,
            /* [in][annotation] */ 
            __in_ecount(cch)  const WCHAR *pAdaptationData,
            /* [in] */ const ULONG cch,
            /* [in] */ LPCWSTR pTopicName,
            SPADAPTATIONSETTINGS eSettings,
            SPADAPTATIONRELEVANCE eRelevance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarPrefix( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in][annotation] */ 
            __in_opt  LPCWSTR pszPrefix,
            /* [in] */ BOOL fIsPrefixRequired) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRulePriority( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientRuleContext,
            /* [in] */ int nRulePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmulateRecognition( 
            /* [in] */ ISpPhrase *pPhrase,
            /* [in] */ DWORD dwCompareFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSLMWeight( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleWeight( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientRuleContext,
            /* [in] */ float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrainingState( 
            BOOL fDoingTraining,
            BOOL fAdaptFromTrainingData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetAcousticModelAdaptation( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadCFG( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPBINARYGRAMMAR *pGrammarData,
            /* [in] */ ULONG ulGrammarID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUnloadCFG( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ ULONG ulGrammarID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSREngine2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngine2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngine2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngine2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            ISpSREngine2 * This,
            /* [in] */ ISpSREngineSite *pSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputAudioFormat )( 
            ISpSREngine2 * This,
            /* [in] */ const GUID *pguidSourceFormatId,
            /* [in] */ const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [out] */ GUID *pguidDesiredFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemDesiredWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *RecognizeStream )( 
            ISpSREngine2 * This,
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ HANDLE hRequestSync,
            /* [in] */ HANDLE hDataAvailable,
            /* [in] */ HANDLE hExit,
            /* [in] */ BOOL fNewAudioStream,
            /* [in] */ BOOL fRealTimeAudio,
            /* [in] */ ISpObjectToken *pAudioObjectToken);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpSREngine2 * This,
            ISpObjectToken *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateGrammar )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineRecoContext,
            /* [in] */ SPGRAMMARHANDLE hSAPIGrammar,
            /* [out] */ void **ppvEngineGrammarContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteGrammar )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *LoadProprietaryGrammar )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataParam,
            /* [in] */ ULONG ulDataSize,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadProprietaryGrammar )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleState )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState,
            /* [out] */ ULONG *pcRulesChanged);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleIdState )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *LoadSLM )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszTopicName);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadSLM )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetSLMState )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in][annotation] */ 
            __in_ecount(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateRecoContext )( 
            ISpSREngine2 * This,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [out] */ void **ppvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteRecoContext )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCall )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [out][in] */ PVOID pCallFrame,
            /* [in] */ ULONG ulCallFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [annotation] */ 
            __in_ecount(cch)  const WCHAR *pAdaptationData,
            const ULONG cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpSREngine2 * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [in] */ LONG lValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpSREngine2 * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [out] */ LONG *lValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpSREngine2 * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpSREngine2 * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [out][annotation] */ 
            __deref_out  LPWSTR *ppCoMemValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPGRAMMARSTATE eGrammarState);
        
        HRESULT ( STDMETHODCALLTYPE *WordNotify )( 
            ISpSREngine2 * This,
            SPCFGNOTIFY Action,
            ULONG cWords,
            const SPWORDENTRY *pWords);
        
        HRESULT ( STDMETHODCALLTYPE *RuleNotify )( 
            ISpSREngine2 * This,
            SPCFGNOTIFY Action,
            ULONG cRules,
            const SPRULEENTRY *pRules);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCallEx )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ SPCONTEXTSTATE eContextState);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCallImmediate )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData2 )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineContext,
            /* [in][annotation] */ 
            __in_ecount(cch)  const WCHAR *pAdaptationData,
            /* [in] */ const ULONG cch,
            /* [in] */ LPCWSTR pTopicName,
            SPADAPTATIONSETTINGS eSettings,
            SPADAPTATIONRELEVANCE eRelevance);
        
        HRESULT ( STDMETHODCALLTYPE *SetGrammarPrefix )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in][annotation] */ 
            __in_opt  LPCWSTR pszPrefix,
            /* [in] */ BOOL fIsPrefixRequired);
        
        HRESULT ( STDMETHODCALLTYPE *SetRulePriority )( 
            ISpSREngine2 * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientRuleContext,
            /* [in] */ int nRulePriority);
        
        HRESULT ( STDMETHODCALLTYPE *EmulateRecognition )( 
            ISpSREngine2 * This,
            /* [in] */ ISpPhrase *pPhrase,
            /* [in] */ DWORD dwCompareFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetSLMWeight )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ float flWeight);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleWeight )( 
            ISpSREngine2 * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientRuleContext,
            /* [in] */ float flWeight);
        
        HRESULT ( STDMETHODCALLTYPE *SetTrainingState )( 
            ISpSREngine2 * This,
            BOOL fDoingTraining,
            BOOL fAdaptFromTrainingData);
        
        HRESULT ( STDMETHODCALLTYPE *ResetAcousticModelAdaptation )( 
            ISpSREngine2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnLoadCFG )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPBINARYGRAMMAR *pGrammarData,
            /* [in] */ ULONG ulGrammarID);
        
        HRESULT ( STDMETHODCALLTYPE *OnUnloadCFG )( 
            ISpSREngine2 * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ ULONG ulGrammarID);
        
        END_INTERFACE
    } ISpSREngine2Vtbl;

    interface ISpSREngine2
    {
        CONST_VTBL struct ISpSREngine2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngine2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngine2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngine2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngine2_SetSite(This,pSite)	\
    ( (This)->lpVtbl -> SetSite(This,pSite) ) 

#define ISpSREngine2_GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx)	\
    ( (This)->lpVtbl -> GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx) ) 

#define ISpSREngine2_RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken)	\
    ( (This)->lpVtbl -> RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken) ) 

#define ISpSREngine2_SetRecoProfile(This,pProfile)	\
    ( (This)->lpVtbl -> SetRecoProfile(This,pProfile) ) 

#define ISpSREngine2_OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext)	\
    ( (This)->lpVtbl -> OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext) ) 

#define ISpSREngine2_OnDeleteGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> OnDeleteGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine2_LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options)	\
    ( (This)->lpVtbl -> LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options) ) 

#define ISpSREngine2_UnloadProprietaryGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadProprietaryGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine2_SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged)	\
    ( (This)->lpVtbl -> SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged) ) 

#define ISpSREngine2_SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState)	\
    ( (This)->lpVtbl -> SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState) ) 

#define ISpSREngine2_LoadSLM(This,pvEngineGrammar,pszTopicName)	\
    ( (This)->lpVtbl -> LoadSLM(This,pvEngineGrammar,pszTopicName) ) 

#define ISpSREngine2_UnloadSLM(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadSLM(This,pvEngineGrammar) ) 

#define ISpSREngine2_SetSLMState(This,pvEngineGrammar,NewState)	\
    ( (This)->lpVtbl -> SetSLMState(This,pvEngineGrammar,NewState) ) 

#define ISpSREngine2_SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo) ) 

#define ISpSREngine2_SetTextSelection(This,pvEngineGrammar,pInfo)	\
    ( (This)->lpVtbl -> SetTextSelection(This,pvEngineGrammar,pInfo) ) 

#define ISpSREngine2_IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable) ) 

#define ISpSREngine2_OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext)	\
    ( (This)->lpVtbl -> OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext) ) 

#define ISpSREngine2_OnDeleteRecoContext(This,pvEngineContext)	\
    ( (This)->lpVtbl -> OnDeleteRecoContext(This,pvEngineContext) ) 

#define ISpSREngine2_PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize) ) 

#define ISpSREngine2_SetAdaptationData(This,pvEngineContext,pAdaptationData,cch)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,pvEngineContext,pAdaptationData,cch) ) 

#define ISpSREngine2_SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine2_GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine2_SetPropertyString(This,eSrc,pvSrcObj,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,eSrc,pvSrcObj,pName,pValue) ) 

#define ISpSREngine2_GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue) ) 

#define ISpSREngine2_SetGrammarState(This,pvEngineGrammar,eGrammarState)	\
    ( (This)->lpVtbl -> SetGrammarState(This,pvEngineGrammar,eGrammarState) ) 

#define ISpSREngine2_WordNotify(This,Action,cWords,pWords)	\
    ( (This)->lpVtbl -> WordNotify(This,Action,cWords,pWords) ) 

#define ISpSREngine2_RuleNotify(This,Action,cRules,pRules)	\
    ( (This)->lpVtbl -> RuleNotify(This,Action,cRules,pRules) ) 

#define ISpSREngine2_PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine2_SetContextState(This,pvEngineContext,eContextState)	\
    ( (This)->lpVtbl -> SetContextState(This,pvEngineContext,eContextState) ) 


#define ISpSREngine2_PrivateCallImmediate(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallImmediate(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine2_SetAdaptationData2(This,pvEngineContext,pAdaptationData,cch,pTopicName,eSettings,eRelevance)	\
    ( (This)->lpVtbl -> SetAdaptationData2(This,pvEngineContext,pAdaptationData,cch,pTopicName,eSettings,eRelevance) ) 

#define ISpSREngine2_SetGrammarPrefix(This,pvEngineGrammar,pszPrefix,fIsPrefixRequired)	\
    ( (This)->lpVtbl -> SetGrammarPrefix(This,pvEngineGrammar,pszPrefix,fIsPrefixRequired) ) 

#define ISpSREngine2_SetRulePriority(This,hRule,pvClientRuleContext,nRulePriority)	\
    ( (This)->lpVtbl -> SetRulePriority(This,hRule,pvClientRuleContext,nRulePriority) ) 

#define ISpSREngine2_EmulateRecognition(This,pPhrase,dwCompareFlags)	\
    ( (This)->lpVtbl -> EmulateRecognition(This,pPhrase,dwCompareFlags) ) 

#define ISpSREngine2_SetSLMWeight(This,pvEngineGrammar,flWeight)	\
    ( (This)->lpVtbl -> SetSLMWeight(This,pvEngineGrammar,flWeight) ) 

#define ISpSREngine2_SetRuleWeight(This,hRule,pvClientRuleContext,flWeight)	\
    ( (This)->lpVtbl -> SetRuleWeight(This,hRule,pvClientRuleContext,flWeight) ) 

#define ISpSREngine2_SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData)	\
    ( (This)->lpVtbl -> SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData) ) 

#define ISpSREngine2_ResetAcousticModelAdaptation(This)	\
    ( (This)->lpVtbl -> ResetAcousticModelAdaptation(This) ) 

#define ISpSREngine2_OnLoadCFG(This,pvEngineGrammar,pGrammarData,ulGrammarID)	\
    ( (This)->lpVtbl -> OnLoadCFG(This,pvEngineGrammar,pGrammarData,ulGrammarID) ) 

#define ISpSREngine2_OnUnloadCFG(This,pvEngineGrammar,ulGrammarID)	\
    ( (This)->lpVtbl -> OnUnloadCFG(This,pvEngineGrammar,ulGrammarID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngine2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0020 */
/* [local] */ 

typedef struct tagSPPHRASEALTREQUEST
    {
    ULONG ulStartElement;
    ULONG cElements;
    ULONG ulRequestAltCount;
    void *pvResultExtra;
    ULONG cbResultExtra;
    ISpPhrase *pPhrase;
    ISpRecoContext *pRecoContext;
    } 	SPPHRASEALTREQUEST;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0020_v0_0_s_ifspec;

#ifndef __ISpSRAlternates_INTERFACE_DEFINED__
#define __ISpSRAlternates_INTERFACE_DEFINED__

/* interface ISpSRAlternates */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSRAlternates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FECE8294-2BE1-408f-8E68-2DE377092F0E")
    ISpSRAlternates : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAlternates( 
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [out] */ SPPHRASEALT **ppAlts,
            /* [out] */ ULONG *pcAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [in] */ SPPHRASEALT *pAlt,
            /* [out] */ void **ppvResultExtra,
            /* [out] */ ULONG *pcbResultExtra) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSRAlternatesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSRAlternates * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSRAlternates * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSRAlternates * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpSRAlternates * This,
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [out] */ SPPHRASEALT **ppAlts,
            /* [out] */ ULONG *pcAlts);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpSRAlternates * This,
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [in] */ SPPHRASEALT *pAlt,
            /* [out] */ void **ppvResultExtra,
            /* [out] */ ULONG *pcbResultExtra);
        
        END_INTERFACE
    } ISpSRAlternatesVtbl;

    interface ISpSRAlternates
    {
        CONST_VTBL struct ISpSRAlternatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSRAlternates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSRAlternates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSRAlternates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSRAlternates_GetAlternates(This,pAltRequest,ppAlts,pcAlts)	\
    ( (This)->lpVtbl -> GetAlternates(This,pAltRequest,ppAlts,pcAlts) ) 

#define ISpSRAlternates_Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)	\
    ( (This)->lpVtbl -> Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSRAlternates_INTERFACE_DEFINED__ */


#ifndef __ISpSRAlternates2_INTERFACE_DEFINED__
#define __ISpSRAlternates2_INTERFACE_DEFINED__

/* interface ISpSRAlternates2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSRAlternates2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F338F437-CB33-4020-9CAB-C71FF9CE12D3")
    ISpSRAlternates2 : public ISpSRAlternates
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitText( 
            SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation] */ 
            __in_opt  LPCWSTR pcszNewText,
            SPCOMMITFLAGS commitFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpSRAlternates2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSRAlternates2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSRAlternates2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSRAlternates2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpSRAlternates2 * This,
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [out] */ SPPHRASEALT **ppAlts,
            /* [out] */ ULONG *pcAlts);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpSRAlternates2 * This,
            /* [in] */ SPPHRASEALTREQUEST *pAltRequest,
            /* [in] */ SPPHRASEALT *pAlt,
            /* [out] */ void **ppvResultExtra,
            /* [out] */ ULONG *pcbResultExtra);
        
        HRESULT ( STDMETHODCALLTYPE *CommitText )( 
            ISpSRAlternates2 * This,
            SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation] */ 
            __in_opt  LPCWSTR pcszNewText,
            SPCOMMITFLAGS commitFlags);
        
        END_INTERFACE
    } ISpSRAlternates2Vtbl;

    interface ISpSRAlternates2
    {
        CONST_VTBL struct ISpSRAlternates2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSRAlternates2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSRAlternates2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSRAlternates2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSRAlternates2_GetAlternates(This,pAltRequest,ppAlts,pcAlts)	\
    ( (This)->lpVtbl -> GetAlternates(This,pAltRequest,ppAlts,pcAlts) ) 

#define ISpSRAlternates2_Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)	\
    ( (This)->lpVtbl -> Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra) ) 


#define ISpSRAlternates2_CommitText(This,pAltRequest,pcszNewText,commitFlags)	\
    ( (This)->lpVtbl -> CommitText(This,pAltRequest,pcszNewText,commitFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSRAlternates2_INTERFACE_DEFINED__ */


#ifndef ___ISpPrivateEngineCall_INTERFACE_DEFINED__
#define ___ISpPrivateEngineCall_INTERFACE_DEFINED__

/* interface _ISpPrivateEngineCall */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__ISpPrivateEngineCall;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E7C791E-4467-11d3-9723-00C04F72DB08")
    _ISpPrivateEngineCall : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallEngine( 
            /* [out][in][annotation] */ 
            __inout_bcount(ulCallFrameSize)  void *pCallFrame,
            /* [in] */ ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CallEngineEx( 
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_ecount_opt(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ISpPrivateEngineCallVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISpPrivateEngineCall * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISpPrivateEngineCall * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISpPrivateEngineCall * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngine )( 
            _ISpPrivateEngineCall * This,
            /* [out][in][annotation] */ 
            __inout_bcount(ulCallFrameSize)  void *pCallFrame,
            /* [in] */ ULONG ulCallFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngineEx )( 
            _ISpPrivateEngineCall * This,
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_ecount_opt(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize);
        
        END_INTERFACE
    } _ISpPrivateEngineCallVtbl;

    interface _ISpPrivateEngineCall
    {
        CONST_VTBL struct _ISpPrivateEngineCallVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISpPrivateEngineCall_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISpPrivateEngineCall_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISpPrivateEngineCall_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISpPrivateEngineCall_CallEngine(This,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> CallEngine(This,pCallFrame,ulCallFrameSize) ) 

#define _ISpPrivateEngineCall_CallEngineEx(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineEx(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ISpPrivateEngineCall_INTERFACE_DEFINED__ */


#ifndef __ISpPrivateEngineCallEx_INTERFACE_DEFINED__
#define __ISpPrivateEngineCallEx_INTERFACE_DEFINED__

/* interface ISpPrivateEngineCallEx */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpPrivateEngineCallEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEFD682A-FE0A-42b9-BFA1-56D3D6CECFAF")
    ISpPrivateEngineCallEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallEngineSynchronize( 
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_bcount(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CallEngineImmediate( 
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_bcount(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpPrivateEngineCallExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPrivateEngineCallEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPrivateEngineCallEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPrivateEngineCallEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngineSynchronize )( 
            ISpPrivateEngineCallEx * This,
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_bcount(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngineImmediate )( 
            ISpPrivateEngineCallEx * This,
            /* [in][annotation] */ 
            __in_bcount(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            __deref_out_bcount(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            __out_ecount(1)  ULONG *pulOutFrameSize);
        
        END_INTERFACE
    } ISpPrivateEngineCallExVtbl;

    interface ISpPrivateEngineCallEx
    {
        CONST_VTBL struct ISpPrivateEngineCallExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPrivateEngineCallEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPrivateEngineCallEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPrivateEngineCallEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPrivateEngineCallEx_CallEngineSynchronize(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineSynchronize(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#define ISpPrivateEngineCallEx_CallEngineImmediate(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineImmediate(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPrivateEngineCallEx_INTERFACE_DEFINED__ */



#ifndef __SpeechDDKLib_LIBRARY_DEFINED__
#define __SpeechDDKLib_LIBRARY_DEFINED__

/* library SpeechDDKLib */
/* [version][uuid][helpstring] */ 


EXTERN_C const IID LIBID_SpeechDDKLib;

EXTERN_C const CLSID CLSID_SpDataKey;

#ifdef __cplusplus

class DECLSPEC_UUID("49428a60-c997-4d0e-9808-9e326c178d58")
SpDataKey;
#endif

EXTERN_C const CLSID CLSID_SpObjectTokenEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("48dd5993-724f-40c8-a4ea-9b1423cd5871")
SpObjectTokenEnum;
#endif

EXTERN_C const CLSID CLSID_SpPhraseBuilder;

#ifdef __cplusplus

class DECLSPEC_UUID("3208c7c9-d5a4-4d2c-bbab-b87486c7520e")
SpPhraseBuilder;
#endif

EXTERN_C const CLSID CLSID_SpITNProcessor;

#ifdef __cplusplus

class DECLSPEC_UUID("063a108d-de22-449c-8734-c778adaf26db")
SpITNProcessor;
#endif

EXTERN_C const CLSID CLSID_SpGrammarCompiler;

#ifdef __cplusplus

class DECLSPEC_UUID("ead0b17d-0eff-4d69-928f-b386668b6bc0")
SpGrammarCompiler;
#endif

EXTERN_C const CLSID CLSID_SpW3CGrammarCompiler;

#ifdef __cplusplus

class DECLSPEC_UUID("8ceaeefb-b7ec-46c3-9f63-8f5288304ca1")
SpW3CGrammarCompiler;
#endif

EXTERN_C const CLSID CLSID_SpGramCompBackend;

#ifdef __cplusplus

class DECLSPEC_UUID("4f19fa90-7a78-4a56-9e68-8f114490df02")
SpGramCompBackend;
#endif
#endif /* __SpeechDDKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



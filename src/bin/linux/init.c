/*++

    Copyright (c) Microsoft Corporation.
    Licensed under the MIT License.

Abstract:

    Library init routines

--*/

#define QUIC_TEST_APIS 1
#include "quic_platform.h"

void MsQuickChainLoadPlatformSymbolsNoOp()
{
    QUIC_CREDENTIAL_CONFIG* SelfSignedCertParams = (QUIC_CREDENTIAL_CONFIG*)CxPlatGetSelfSignedCert(CXPLAT_SELF_SIGN_CERT_USER, FALSE, NULL);
    CxPlatFreeSelfSignedCert(SelfSignedCertParams);
}

void
MsQuicLibraryLoad(
    void
    );

void
MsQuicLibraryUnload(
    void
    );

static
void
Entry(
    void
    ) __attribute__((constructor));

static
void
Exit(
    void
    ) __attribute__((destructor));

static
void
Entry(
    void
    )
{
    MsQuicLibraryLoad();
}

static
void
Exit(
    void
    )
{
    MsQuicLibraryUnload();
}

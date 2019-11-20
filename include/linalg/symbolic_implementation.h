
#pragma once

#include "matrix_interface.h"
#include <tuple>
#include <assert.h>
#include <iostream>

using std::cout;

struct SI{};

#define IMPL_COUT(M) \
std::ostream & operator << (std::ostream &out, M<SI> &c) \
{ \
    out << #M; \
    return out; \
}

IMPL_COUT(L)
IMPL_COUT(U)
IMPL_COUT(EL)
IMPL_COUT(EU)
IMPL_COUT(ELH)
IMPL_COUT(EUH)
IMPL_COUT(P)
IMPL_COUT(A)


#define MM(A,B,C) \
C<SI> matmul(A<SI> a, B<SI> b){\
    C<SI> c;\
	(void) a;\
	(void) b;\
    return c;\
};


MM(A,A,A)
MM(D,D,D)
MM(L,L,L)
MM(U,U,U)
MM(L,U,A)


#define APPLY_INVERSE(A,B,C) \
C<SI> apply_inverse(A<SI> a, B<SI> b){\
    C<SI> c;\
	(void) a;\
	(void) b;\
    return c;\
};

APPLY_INVERSE(L,L,L)
APPLY_INVERSE(U,U,U)
APPLY_INVERSE(L,A,A)
APPLY_INVERSE(U,A,A)


#define IMPL_FACT(TYPE,F1,F2,F3,F4,f1,f2,f3,f4) \
std::tuple<F1<SI> , F2<SI> , F3<SI> , F4<SI>> TYPE##_fact(A<SI> a){ \
    L<SI> l; \
    EL<SI> el; \
	EU<SI> eu;\
	ELH<SI> elh;\
	EUH<SI> euh;\
    U<SI> u;\
    P<SI> p;\
	(void)a;\
	(void)el;\
	(void)eu;\
	(void)elh;\
	(void)euh;\
    return std::make_tuple( f1,f2,f3,f4);\
}

IMPL_FACT(LEUP,  L,EL,U,P,  l,el,u,p)
IMPL_FACT(PLEU,  P,L,EU,U,  p,l,eu,u)
IMPL_FACT(UELP,  U,EUH,L,P, u,euh,l,p)
IMPL_FACT(PUEL,  P,U,ELH,L, p,u,elh,l)



L<SI> commute( EL<SI> el1, L<SI> l1 ){
    L<SI> l;
	(void) l1;
	(void) el1;
    return l;
}

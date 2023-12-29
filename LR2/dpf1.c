// Header: 1-я программа ДПФ действительных последовательностей
// File Name: 
// Author:
// Date:
#pragma SMALL
#pragma CODE
#pragma NOCO
#include "dpf1.h"
#include <math.h>
#define Var 5

/////////////////////// FunR_DPF
#if Var == 0
void FunR_DPF( void ) {
  register unsigned char k, i;
  for ( k = 0; k < n; k++ ) {
    SReal_out[ k ] = SImag_out[ k ] = 0.f;
    for ( i = 0; i < n; i++ )	{
      SReal_out[ k ] += SReal[ i ]* cos( M_PI/ nd2 * k * i );
      SImag_out[ k ] -= SReal[ i ]* sin( M_PI/ nd2 * k * i );
    }
  }
}
#elif Var == 1
void FunR_DPF( void ) {
  register unsigned char k, i;
  for ( k = 0; k < n; k++ ) {
    SReal_out[ k ] = SImag_out[ k ] = 0.f;
    for ( i = 0; i < n; i++ )	{
      SReal_out[ k ] += SReal[ i ]* cos( 2 * M_PI/ n * k * i );
      SImag_out[ k ] -= SReal[ i ]* sin( 2 * M_PI/ n * k * i );
    }
  }
}
#elif Var == 2
void FunR_DPF( void ) {
  register unsigned char k, i;
  for ( k = 0; k < n; k++ ) {
    SReal_out[ k ] = SImag_out[ k ] = 0.f;
    for ( i = 0; i < n; i++ )	{
      SReal_out[ k ] += SReal[ i ]* cos( k * i * 2 * M_PI/ n );
      SImag_out[ k ] -= SReal[ i ]* sin( k * i * 2 * M_PI/ n );
    }
  }
}
#elif Var == 3  // Post
void FunR_DPF( void ) {
  register unsigned char k, i;
	SImag_out[ 0 ] = SReal_out[ 0 ] = 0.f;
  for ( i = 0; i < n; i++ )
	  SReal_out[ 0 ] += SReal[ i ];
  for ( k = 1; k < n; k++ ) {
    SReal_out[ k ] = SImag_out[ k ] = 0.f;
    for ( i = 0; i < n; i++ )	{
      SReal_out[ k ] += SReal[ i ]* cos( k * i * 2 * M_PI/ n );
      SImag_out[ k ] -= SReal[ i ]* sin( k * i * 2 * M_PI/ n );
    }
  }
}
#elif Var == 4  // Post
void FunR_DPF( void ) {
  register unsigned char k, i;
	register float WorkR;
	SImag_out[ 0 ] = 0.f;
	WorkR = SReal[ 0 ];
  for ( i = 1; i < n; i++ )
	  WorkR += SReal[ i ];
	SReal_out[ 0 ] = WorkR;
  for ( k = 1; k < n; k++ ) {
    SReal_out[ k ] = SImag_out[ k ] = 0.f;
    for ( i = 0; i < n; i++ )	{
      SReal_out[ k ] += SReal[ i ]* cos( k * i * 2 * M_PI/ n );
      SImag_out[ k ] -= SReal[ i ]* sin( k * i * 2 * M_PI/ n );
    }
  }
}
#else
void FunR_DPF( void ) {
  register unsigned char k, i;
	float WorkR, WorkI, arg, A, sig, wrk;
	SImag_out[ 0 ] = 0.f;
	WorkR = SReal[ 0 ];
  for ( i = 1; i < n; i++ )
	  WorkR += SReal[ i ];
	SReal_out[ 0 ] = WorkR;
	arg = 2 * M_PI/ n;
  for ( k = 1; k < n; k++ ) {
	  WorkI = 0.f;
		WorkR = SReal[ 0 ];
    for ( i = 1; i < n; i++ )	{
			wrk = cos( A = k * i * arg );
			sig = SReal[ i ];
			WorkR = wrk * sig + WorkR;
			WorkI -= sin( A )* sig;
    }
    SReal_out[ k ] = WorkR;
		SImag_out[ k ] = WorkI;
  }
}

#endif

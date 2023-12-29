// Header: 1-я программа ДПФ действительных последовательностей
// File Name: 
// Author:
// Date:

#include "dpf0.h"
#include <math.h>

/////////////////////// FunR_DPF
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

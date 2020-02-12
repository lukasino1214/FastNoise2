#include "Generator.h"

#include "FS_Class.inl"
#ifdef FASTSIMD_INCLUDE_CHECK
#include __FILE__
#endif
#include "FS_Class.inl"
#pragma once

namespace FastNoise
{
    FASTSIMD_CLASS_DECLARATION_CHILD( White, Generator )
    {
        FASTSIMD_CLASS_SETUP( FastSIMD::COMPILED_SIMD_LEVELS );

    public:
        FS_INTERNAL( float32v FS_VECTORCALL Gen( int32v seed, float32v x, float32v y ) override { return GenT( seed, x, y ); } );
        FS_INTERNAL( float32v FS_VECTORCALL Gen( int32v seed, float32v x, float32v y, float32v z ) override { return GenT( seed, x, y, z ); } );

        FS_INTERNAL( template<typename... P> float32v FS_INLINE GenT( int32v seed, P... pos ); )
    };
}

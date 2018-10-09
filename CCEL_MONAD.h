#include "CCEL_FUNCTOR.h"

//Monad 应该采用依赖注入来解决

/*
    monad{
        monad类型 const char* name
        值类型 -> val
    }

    ret->this

    fmap function 检查 function returntype == val type
    if(__builtin_types_compatible_p(typeof(ret),typeof(val))){
    this->functor->value = f.call(value)

*/
#define monad_sign(name,type) struct monad_##name{\
    char name[0];\
    type value;\
}

#define monad_return(name,val) monad_sign(name,typeof(val));\
    struct monad_##name monad_##name* = (struct monad_##name *)malloc(sizeof(struct monad_##name));\
    monad_##name->value = val;



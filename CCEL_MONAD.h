#include "CCEL_FUNCTOR.h"

//Monad 应该采用依赖注入来解决

/*
    monad{
        值类型 -> val
    }

    ret->this

    fmap function 检查 function returntype == val type
    if(__builtin_types_compatible_p(typeof(ret),typeof(val))){
    this->functor->value = f.call(value)

*/
#define monad_sign(name,type) struct monad_##name{\
    type value;\
}

#define monad_return(name,val) monad_sign(name,typeof(val));\
    struct monad_##name monad_##name* = (struct monad_##name *)malloc(sizeof(struct monad_##name));\
    monad_##name->value = val

#define monad_flatmap(name,lambda) monad_##name->value = lambda->call(value)
#define monad_free(name) free(monad_##name)


/*
    status
    1 finished
    0 unfinished//uninitialized
*/

#define promise(type,name)\
    struct promise_##name {\
        int status;\
        type value;\
        type(*get)(struct promise_##name *p);\
    }

//instead of return
#define promise_init(type,name) struct promise_##name *promise_##name = (struct promise_##name*)malloc(sizeof(struct promise_##name));\
    promise_##name->status = 0;promise_##name->value=0; promise_##name->get=lambda(type,(struct promise_##name *p),\
    {if(p->status == 1){return p->value;}else{printf("Warning! promise not finished or faild\n");}})

//flatmapping
#define promise_flatmap(name,lambda) promise_##name->value = lambda->call(value)
#define promise_set(name,dat) promise_##name->value = dat;\
    promise_##name->status = 1


#define promise_get(name) name->get(name)
#define promise_free(name) free(promise_##name)

//maybe
// 0 Nothing
// 1 Just
#define maybe(type,name)\
    struct maybe_##name {\
        int status;\
        type value;\
        type(*get)(struct maybe_##name *m);\
    }

//instead of return
#define maybe_init(type,name) struct maybe_##name *maybe_##name = (struct maybe_##name*)malloc(sizeof(struct maybe_##name));\
    maybe_##name->get=lambda(type,(struct maybe_##name *p),\
    {if(p->status == 1){return p->value;}else{printf("Nothing!\n");return 0;}})


//flatmapping
#define maybe_flatmap(name,lambda) maybe_##name->value = lambda->call(value)
#define maybe_some(name,val) maybe_##name->value = val;\
    maybe_##name->status = 1


#define maybe_get(name) maybe_##name->get(maybe_##name)
#define maybe_free(name) free(maybe_##name)


//either
// 0 left
// 1 right
#define either(typea,typeb,name)\
    struct either_##name {\
        int status;\
        typea left;\
        typeb right;\
        typea(*get_left)(struct either_##name *m);\
        typeb(*get_right)(struct either_##name *m);\
    }

//instead of return
#define either_init(typea,typeb,name) struct either_##name *either_##name = (struct either_##name*)malloc(sizeof(struct either_##name));\
    either_##name->status = 0;either_##name->left = 0;either_##name->right=0; either_##name->get_left=lambda(typea,(struct either_##name *p),\
    {if(either_##name->status == 0){return p->left;}else{printf("This either is not Left");return 0;}});\
    either_##name->get_right=lambda(typeb,(struct either_##name *p),\
    {if(either_##name->status == 1){return p->right;}else{printf("This either is not Right");return 0;}})

//flatmapping
#define either_flatmap(name,lam) either_##name->right = lam(either_##name->right)

#define either_left(name,dat) either_##name->left = dat;either_##name->status = 0
#define either_right(name,dat) either_##name->right = dat;either_##name->status = 1

#define either_get_left(name) name->get_left(name)
#define either_get_right(name) name->get_right(name)
#define either_swap(name) typeof(either_##name->left) __tmp = either_##name->left;\
either_##name->left = right;\
either_##name->right = __tmp;\
if(either_##name->status == 1){either_##name->status = 0}else{either_##name->status = 1}

#define either_free(name) free(either_##name)

//CPS

// -> Monoid  1)semigroup{empty,append} 2Monoid{empty,append})
// <>::a->a->a
// <> = append
#define monoid_sign(name,type) struct monoid_##name{\
    type value;\
}

#define monoid_init(name) monoid_sign(name,typeof(val));\
    struct monoid_##name monoid_##name* = (struct monoid_##name *)malloc(sizeof(struct monoid_##name))

#define monoid_empty(name) monoid_##name->value = 0

#define monoid_append(name,val) monoid_##name->value = val

#define monoid_free(name) free(monoid_##name)
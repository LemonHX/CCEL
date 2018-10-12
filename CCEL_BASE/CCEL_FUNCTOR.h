#include "CCEL_BASE.h"
/*
class Cat (c::*->*->*) where
    id::c a a
    (.)::c y z -> c x y -> c x z

with hask defined
Class Cat Hask where
  id x = x
  (f . g) x = f (g x)

as id a => a
as (f.g)x => f(g(x))

class Functor t where
    fmap::(a->b)->(t a -> t b)

as fmap _ Nothing => Nothing
as fmap f (Just a) => Just(f a)

Natural Transformations

Nat c f g = c (f a) (g a)
NatHask f g = f a -> g a

class Monad m where
    ret::a -> m a
    (>>=)::M a -> (a -> M b) -> M b


*/

#define cat_id(a) a
#define cat_compose(f,g, ...) f(g(__VA_ARGS__))

//functor is (a -> b)
//fromtype and totype will never have a value
#define functor_define(name,typea,fuckme,typeb) struct functor_##name{\
    typea fromtype;\
    typeb totype;\
    typea value;\
}
#define functor_init(name) struct functor_##name *functor_##name = (struct functor_##name*)malloc(sizeof(struct functor_##name))
#define functor_set(name,val) functor_##name->value = val
#define functor_free(name) free(functor_##name)

#define nat_hask(name,f,g) functor_define(name,typeof(g->fromtype),->,typeof(g->totype));functor_init(name);functor_set(name,f->value)

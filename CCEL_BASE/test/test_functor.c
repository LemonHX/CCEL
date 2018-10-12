#include "../CCEL_FUNCTOR.h"

int main(){
    functor_define(ITI,int,->,int);
    functor_init(ITI);
    functor_set(ITI,10);

    functor_define(FTI,float,->,int);
    functor_init(FTI);
    
    nat_hask(FFTI,functor_ITI,functor_FTI);

}
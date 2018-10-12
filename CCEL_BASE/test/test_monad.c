
#include "../CCEL_MONAD.h"
    int main(){
        promise(int,val);
        promise_init(int,val);
        promise_set(val,99);
        typeof(promise_val->value) ppp = promise_get(promise_val);
        //promise_free(promise_val);
        // free(val);
        printf("current status is %d,and ppp is %d\n",promise_val->status,ppp);

        maybe(int,has);
        maybe_init(int,has);
        maybe_some(has,21);
        int resm = maybe_get(has);
        printf("maybe val is %d\n",resm);


        either(int,float,is);
        either_init(int,float,is);
        either_left(is,4);
        either_right(is,0);

        float(*lama)(float) = lambda(float,(float x),{return x+1;});
        either_flatmap(is,lama);
        float ffff = either_get_right(either_is);
        printf("either right is %f\n",ffff);

        either_get_left(either_is);

        promise_free(val);
        maybe_free(has);
    }
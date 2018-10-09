#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CCEL_BASE.h"

int main(){

    lambda_type_sign(ado,->,int,::,int,int);
    lambda_init(ado);
    lambda_set(ado) = lambda(int,(int a,int b),{return a+b;});
    //lambda_free(ado);

    lambda_type_sign(lamad,->,int,::,lambda_type(ab,->,int,::,int,int),int,int);
    lambda_init(lamad);
    
    //before calling the lambda from arg initialize it first(write the type sign)
    lambda_set(lamad) = lambda(int,(lambda_type(ab,->,int,::,int,int),int a,int b),{lambda_type_sign(ab,->,int,::,int,int);return lambda_ab->call(a,b);});


    printf("%d\n",lambda_lamad->call(lambda_ado,2,3));
    lambda_free(ado);
    lambda_free(lamad);

    return 0;
}
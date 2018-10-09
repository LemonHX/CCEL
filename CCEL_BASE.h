//编译器只有用gcc才可以编译

#define match _Generic
/*
match((x),
    int:fun_int,
    float:fun_float,
)(x)
*/

#define lambda_type(name,fuck,return_type,fuck2,...) struct lambda_##name* lambda_##name
#define lambda_type_sign(name,fuck,return_type,fuck2,...) struct lambda_##name{\
    return_type(*call)(__VA_ARGS__);\
}

#define lambda_init(name) struct lambda_##name *lambda_##name = (struct lambda_##name*)malloc(sizeof(struct lambda_##name)) 
#define lambda_set(name) lambda_##name->call
#define lambda_free(name) free(lambda_##name)
#define lambda(return_type,args,block)({\
    inline return_type __temLamb1 args block;\
    __temLamb1;\
})



#define promise(type,name)\
    _Atomic struct promise_##name {\
        int status;\
        type data;\
        int(*get)(struct promise_##name *p);\
    }\
/*
    status
    1 finished
    0 unfinished//uninitialized
    -1 failed
*/
#define promise_init(name) struct promise_##name *promise_##name = (struct promise_##name*)malloc(sizeof(struct promise_##name));\
    promise_##name->status = 0;promise_##name->data=NULL; promise_##name->get=lambda(int,(struct promise_##name *p),\
    {if(p->status != -1 && p->status != 0){return p->data;}else{printf("Warning! promise not finished or faild\n");}})
//return 1 for setted
#define promise_set(name,dat)({promise_##name->data = dat;\
    promise_##name->status = 1;1;})
//return value
#define promise_get(name) name->get(name)
#define promise_free(name) free(promise_##name)

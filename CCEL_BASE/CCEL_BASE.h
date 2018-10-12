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
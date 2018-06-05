//编译器只有用gcc才可以编译

#define match _Generic
/*
match((x),
    int:fun_int,
    float:fun_float,
)(x)
*/

#define parallel _Atomic
//parallel(int a)
//_Atomic类型能在pthread中顺序使用
//匿名函数的实现
//假如,想直接获得返回值
//记住,使用c语言,一定要忽略IDE报错
/*int a = ({
    int l(){
        return 10;
    };
    l();
});
//想赋值为函数
int(*a)() = ({
    int l(){
        //dosomething
    };
    l;
});
*/

//根据以上c语言内置的魔幻规则我们可以定义这样的宏
#define $lambda(return_type,args,function_block) ({\
    return_type ____l args function_block;\
    ____l;\
})
//用法 $lambda(int,(int a,int b),{return a+b;})

//(.)::(b->c)->(a->b)->a->c
#define $combine(functiona,functionb,argb) functiona(functionb(argb)) //目前只能这样........

//promise

#define promise(type,name) typedef _Atomic struct Promise_##name{\
        int status;\
        type data;\
    } Promise_##name;\
    Promise_##name promise_##name;\
    promise_##name.status = 0;\
    promise_##name.data = NULL;
/*
    1 finished
    0 unfinished//uninitialized
    -1 failed
*/
#define promise_group(type,name,fix_length) typedef _Atomic struct Promise_##name{\
        int status;\
        type data;\
    } Promise_##name;\
    Promise_##name promise_##name[fix_length];\
    for(int i = 0;i<fix_length-1;i++){promise_##name[i].status = 0;promise_##name[i].data = NULL;}

#define promise_set_value(promise,value) promise.data = value;promise.status = 1;
#define promise_ref_set_value(promise,value) promise->data = value;promise->status = 1;

//坑1 lambda 不要传递指针,不要!!!!!

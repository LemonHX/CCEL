#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <stdbool.h>
#include "CCEL_BASE.h"
#include "CCEL_LIST.h"

int main(int argc, char const *argv[]){
    int array[9] = {2,3,4,5,6,7,8,9,10};
    List *l = List_new(1,sizeof(int));
    //这种用法保证了有个头部,虽然我自己也觉得不是很爽
    //但是限制了初始化一个空的这种不好的做法

    List_append_array(l,sizeof(int),array,9);
    //一个宏

    List_show(l,"%d\n");
    //show当前的list
    printf("size is:%d\n",l->size);
    int(*add_one)(int) = $lambda(int,(int x),{return x+1;});
    List *m = List_map(l,sizeof(int),add_one);
    List_show(m,"map is: %d\n");

    bool(*bigger_than5)(int) = $lambda(bool,(int x),{if (x > 5) {return true;}return false;});
    List *f = List_filter(l,sizeof(int),bigger_than5);
    List_show(f,"filter is: %d\n");

    int(*add)(int,int) = $lambda(int,(int x,int y),{return x+y;});
    int fl = List_fold_left(l,0,add);
    printf("fold is:%d\n",fl);

    printf("that is\n");
    return 0;
}


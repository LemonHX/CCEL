#include <stdlib.h>
//#include <string.h>
#include "../CCEL_DATATYPE/CCEL_MONADICTYPE.h"

list_typeof(int);
list_isremoveable(int);
list_isfreeable(int)
list_isshowable(int,"%d\n")
list_isreverseable(int)

list_typeof(char);
list_isremoveable(char);
list_isfreeable(char)
list_isshowable(char,"%s\n")
list_isreverseable(char)

list_typeof(double);
list_isremoveable(double);
list_isfreeable(double)
list_isshowable(double,"%d\n")
list_isreverseable(double)

list_typeof(float);
list_isremoveable(float);
list_isfreeable(float)
list_isshowable(float,"%f\n")
list_isreverseable(float)

list_typeof(long);
list_isremoveable(long);
list_isfreeable(long)
list_isshowable(long,"%ld\n")
list_isreverseable(long)

list_typeof(List_char);

int main(){
    List_int * list = list_empty_int();
    list_append_int(list,2);
    list_append_int(list,4);
    list_show_int(list);
    list_remove_int(list,3);
    list_show_int(list);
}
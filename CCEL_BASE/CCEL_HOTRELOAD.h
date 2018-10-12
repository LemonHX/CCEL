#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <signal.h>
#include <errno.h>

int main(){

    FILE *t = NULL;
    t = fopen("./test.c","a+");
    fprintf(t,"#include <stdio.h>\nvoid phello(){printf(\"fuck ya~♂\\n\");};int addo(int a, int b){return a+b;};");
    fclose(t);
    system("gcc test.c -shared -fPIC -o libtest.so");

    void *dlib = dlopen("./libtest.so",RTLD_NOW|RTLD_GLOBAL);
    void(*hello)() = dlsym(dlib,"phello");
    int(*ado)(int,int) = dlsym(dlib,"addo");
    hello();
    printf("%d\n",ado(1,2));
}

// -ldl

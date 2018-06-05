#include "CCEL_BASE.h"


typedef struct Node{   
    unsigned int size;
    void* head;                  
    struct Node *tail;              
}List;

List* List_new(void* head,size_t size){
    List* l = (List*)malloc(sizeof(List));
    l->head = (void*)malloc(size);
    l->head = head;
    l->size = (int)malloc(sizeof(int));
    l->size = 1;
    l->tail = NULL;
    return l;
}
//buggy
void List_append(List* l,List* l2){
    l->size += l2->size;
    List *r = l;
    while(r->tail != NULL){
        r = r->tail;
    }
    l->tail = l2;
}
//buggy
void List_append_element(List* l,void* head,size_t size){
    l->size += 1;
    List* r = l;
    while(r->tail != NULL){
        r = r->tail;
    }
    r->tail = List_new(head,size);
}

#define List_append_array(list_pointer,size,a,array_length){\
    for(int i =0;i<array_length;i++){\
        List_append_element(list_pointer,a[i],size);\
    }\
}

void* List_index(List* l,unsigned int number){
    if(number >= l->size){
        printf("\n-- Error! （＃￣～￣＃）index invalid,your index might be too big or too small --\n");
        return NULL;
    }
    else{
        List *r = l;
        for(int i = 0; i < number; i++){
            r = r->tail;
        }
        return r->head;
    }
    printf("\n-- Error! ━━∑(￣□￣*|||━━ how did you get here??? --\n");
}

//pop the end
void* List_pop(List* l){
    void* res;
    if(l->size == 1){
        res = l->head;
        free(l);
        return res;
    }
    else{
        l->size -= 1;
        List *r = l;
        while(r->tail->tail != NULL){
            r = r->tail;
        }
        res = r->tail->head;
        free(r->tail);
        r->tail = NULL;
        return res;
    }
    printf("\n-- Error! ━━∑(￣□￣*|||━━ how did you get here??? --\n");
}

List* List_map(List* l,size_t size,void*(*function)(void*)){
    List *r = l;
    
    if (l->size <= 1) {
        List *res = List_new(function(l->head),size);
        return res;
    }
    else {
        List *res = List_new(function(l->head),size);
        while(r->tail != NULL){
            r = r->tail;
            List_append_element(res,function(r->head),size);
        }
        return res;
    }
    printf("\n-- Error! ━━∑(￣□￣*|||━━ how did you get here??? --\n");
}

List* List_filter(List* l,size_t size,bool(*function)(void*)){
    List* r = List_new((void*)1,size);
    //先占位
    List* i = l;
    
    while(i->tail != NULL){
        if (function(i->head)) {
            List_append_element(r,i->head,size);
        }
        i = i->tail;        
    }
    if (function(i->head)) {
            List_append_element(r,i->head,size);
    }
    r->tail->size = r->size -1;
    r = r->tail;
    return r;
}

//not working
List* List_reverse(List* l,size_t size){
    List *r = List_new(List_index(l,l->size-1),size);
    
    for(int i = l->size-2; i < 0; i--){
        List_append_element(r,List_index(l,i),size);
    }
    return r;
}

void* List_fold_left(List *l,void* first,void*(*function)(void*,void*)){
    void* tmp = first;
    for(int i = 0; i < l->size; i++){
        tmp = function(tmp,List_index(l,i));
    }
    
    return tmp;
}

//--------------
bool List_equals_to(List *l,List* l2){
    if(l->size == l2->size){
        List *lt = l;
        List *l2t = l2;
        while(lt->tail != NULL && l2t->tail != NULL){
            if(lt->head == l2t->head){
                lt = lt->tail;
                l2t = l2t->tail;
            }
            else{
                return false;
            }
        }
        if(lt->head == l2t->head){return true;}else{return false;}
    }
    else{
        return false;
    }
    printf("\n-- Error! ━━∑(￣□￣*|||━━ how did you get here??? --\n");
    return false;
}

//--------------
void List_show(List* l,char* msg){
    List* r = l;
    printf("\n---strat showing\n");
    while(r->tail != NULL){
        printf(msg,r->head);
        r = r->tail;
    }
    printf(msg,r->head);
    printf("\n---end showing\n");
}
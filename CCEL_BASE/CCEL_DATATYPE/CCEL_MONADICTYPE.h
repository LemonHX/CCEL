#include "../CCEL_MONAD.h"

#define list_typeof(type)\
typedef struct node_##type Node_##type;\
typedef struct list_##type List_##type;\
struct node_##type {\
  type data;\
  struct node_##type * next;\
};\
struct list_##type {\
  Node_##type * head; \
};\
Node_##type * createnode_##type(type data);\
Node_##type * createnode_##type(type data){\
  Node_##type * newNode_##type = malloc(sizeof(Node_##type));\
  if (!newNode_##type) {\
    return NULL;\
  }\
  newNode_##type->data = data;\
  newNode_##type->next = NULL;\
  return newNode_##type;\
}\
List_##type * list_empty_##type(){\
  List_##type * list_##type = malloc(sizeof(List_##type));\
  if (!list_##type) {\
    return NULL;\
  }\
  list_##type->head = NULL;\
  return list_##type;\
}\
void list_append_##type( List_##type * list_##type,type data){\
  Node_##type * current = NULL;\
  if(list_##type->head == NULL){\
    list_##type->head = createnode_##type(data);\
  }\
  else {\
    current = list_##type->head; \
    while (current->next!=NULL){\
      current = current->next;\
    }\
    current->next = createnode_##type(data);\
  }\
}\









#define list_isfreeable(type)\
void list_free_##type(List_##type * list_##type){\
  Node_##type * current = list_##type->head;\
  Node_##type * next = current;\
  while(current != NULL){\
    next = current->next;\
    free(current);\
    current = next;\
  }\
  free(list_##type);\
}

#define list_isreverseable(type)\
void list_reverse_##type(List_##type * list_##type){\
  Node_##type * reversed = NULL;\
  Node_##type * current = list_##type->head;\
  Node_##type * temp = NULL;\
  while(current != NULL){\
    temp = current;\
    current = current->next;\
    temp->next = reversed;\
    reversed = temp;\
  }\
  list_##type->head = reversed;\
}

#define list_isshowable(type,fmt)\
void list_show_##type(List_##type * list_##type) {\
  Node_##type * current = list_##type->head;\
  if(list_##type->head == NULL) \
    return;\
  for(; current != NULL; current = current->next) {\
    printf(fmt, current->data);\
  }\
}

#define list_isremoveable(type)\
void list_remove_##type( List_##type * list_##type,type data){\
  Node_##type * current = list_##type->head;\      
  Node_##type * previous = current;\
  while(current != NULL){\
    if(current->data == data){\
      previous->next = current->next;\
      if(current == list_##type->head)\
        list_##type->head = current->next;\
      free(current);\
      return;\
    }\    
    previous = current;\      
    current = current->next;\      
  }\          
}


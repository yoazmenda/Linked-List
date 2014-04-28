#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prints the linked list on STDOUT;*/
void print_list(LinkedList *list){
  if (list==0){
   return; 
  }
  link *cur;
  cur = list->first;
  while(cur != 0){
  printf("[%i,%s]->",cur->id,cur->name);
  cur = cur->next;
  }
  printf("NULL\n");
}

/*Creates a new link [x,name] and adds it to the end of the list;*/
LinkedList *add(LinkedList *list, int x,char *name){
  link *cur;
  link *new_link;
  if (list == 0){
    return 0;
  }
  new_link = (link*)malloc(sizeof(link));
  new_link->id = x;
  new_link->name = (char*)malloc(strlen(name)+1);
  strcpy(new_link->name,name);
  new_link->next = 0;
  
  if (list->first == 0){
    list->first = new_link;
  }
  else{
  cur = list->first;
  while(cur->next != 0){
   cur = cur->next; 
  }
  cur->next = new_link;
  }
  return list;
}

/*Returns a newly constructed linked list initialized with default values*/
LinkedList *init(){
  
  LinkedList *new_list;
  new_list = (LinkedList*)malloc(sizeof(LinkedList));
  new_list->first = 0;
  return new_list;
}

/*free a chain of links until it reaches NULL (using a tail recursion)*/
void free_links(link* link_to_free){
  if (link_to_free!=0){
    link *next_link;
    next_link = link_to_free->next;
    free(link_to_free->name);
    free(link_to_free);
    free_links(next_link);
  }
 }
/*free all the resources associated with the list*/
void free_list(LinkedList *list){
    if (list != 0){
    free_links(list->first);
    free(list);
    }
}



int main(){
  /*usage example*/
  LinkedList *list = init();

  list = add(list,1,"hello");
  list = add(list,2,"world");
  list = add(list,3,"black");
  print_list(list);
  free_list(list); 
  list = init();
  list = add(list,4,"white");
  list = add(list,5,"game of thrones");
  print_list(list);
  free_list(list);
 
  
  return 0; 
}



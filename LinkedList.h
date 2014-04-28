typedef struct link{
  int id;
  char *name;
  struct link *next;
} link;

typedef struct LinkedList{
  link *first;
} LinkedList;
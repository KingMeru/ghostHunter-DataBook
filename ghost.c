#include "defs.h"
/*
  Function: initGhostList
  Purpose:  initializes a GhostListType(linked list head and tail)
  out:   The initialized GhostListType
   return:   void
*/
void initGhostList(GhostListType *list){
  list->head = NULL;
  list->tail = NULL;
}
/*
  Function: initGhost
  Purpose: initializes a GhostType
  in: The id of the ghost
  in: THe type of ghost
  in: The room the ghost is in
  in: The likelihood of the ghost being in said room
  out: The initialized ghost.
  return:   void
*/
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType** ghost){
  *ghost = (GhostType*) calloc(1, sizeof(GhostType));
  (**ghost).id = id;
  (**ghost).ghostType = gt;
  (**ghost).likelihood = like;
  (**ghost).room = r;
}
/*
  Function: addGhost
  Purpose: adds a ghost to the GhostListType
  in/out: The GhostListType
  in: The ghost
  return:   void
*/
void addGhost(GhostListType *list, GhostType *ghost){
  NodeType* newNode = (NodeType*) calloc(1, sizeof(NodeType));
  newNode->data = ghost;
  newNode->next = NULL;

  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  }
  else{
    list->tail->next = newNode;
    list->tail = newNode;
  }
}
/*
  Function: addGhostByLikelihood
  Purpose: adds Ghosts in descending order of likelihood
  in/out: The List
  in: The ghost
  return:   void
*/
void addGhostByLikelihood(GhostListType *list, GhostType *ghost){
  if(list->head == NULL){// If head is null
    NodeType* newNode = malloc(sizeof(NodeType));

    newNode->data = ghost;
    newNode->next = NULL;
    list->tail = newNode;
    list->head = newNode;
    return;
  }
  if(list->head->next == NULL){// if there's just one element in the list

    if(list->head->data->likelihood >= ghost->likelihood){// element is greater or equal
      NodeType* newNode = malloc(sizeof(NodeType));
      newNode->data = ghost;
      newNode->next = NULL;

      list->tail = newNode;
      list->head->next = newNode;
      return;
    }
    else if(list->head->data->likelihood < ghost->likelihood){//element is less
      NodeType* temp = list->head;
      NodeType* newNode = malloc(sizeof(NodeType));
      newNode->next = temp;
      newNode->data = ghost;

      list->tail = temp;
      list->head = newNode;
      return;
    }
  }

  if(list->head->data->likelihood < ghost->likelihood){// if there's more than one element and head is less than new element
    NodeType* temp = list->head;
    NodeType* newNode = malloc(sizeof(NodeType));
    newNode->next = temp;
    newNode->data = ghost;

    list->head = newNode;
    return;
  }

  if(list->tail->data->likelihood >= ghost->likelihood){//if tail is greater than element
    NodeType* temp = list->tail;
    NodeType* newNode = malloc(sizeof(NodeType));
    newNode->next = NULL;
    newNode->data = ghost;

    temp->next = newNode;

    list->tail = newNode;
    return;
  }


  else{// if new element fits somewhere in the middle of the list
    NodeType* prev = list->head;
    NodeType* curr = list->head->next;

    NodeType* new = malloc(sizeof(NodeType));
    new->data = ghost;


    while(prev != NULL){
      if((prev->data->likelihood > ghost->likelihood) && (curr->data->likelihood <= ghost->likelihood)){

        new->next = prev->next;
        prev->next = new;
        break;

      }
      prev = curr;
      curr = prev->next;
    }

    return;
  }
  return;
}
/*
  Function: cleanupGhostData
  Purpose: frees up the allocated space for the ghost data
  in: The List
  return:   void
*/
void cleanupGhostData(GhostListType *list){
  NodeType* prev = list->head;

  while(prev != NULL){
    free(prev->data);
    prev = prev->next;
  }

}
/*
  Function: cleanupGhostList
  Purpose: frees up allocated space for the ghost nodes
  in: The List
  return: void
*/
void cleanupGhostList(GhostListType *list){
  NodeType* prev = list->head;
  while(prev != NULL){
    NodeType* temp = prev->next;
    free(prev);
    prev = temp;
  }


}
/*
  Function: printGhost
  Purpose: prints the ghost's data
  in: The ghost
  return:   void
*/
void printGhost(GhostType *ghost){
  printf("ID: %d|", ghost->id);
  if(ghost->room == NULL){
    printf("ROOM NAME: %15s|", "UNKNOWN");
  }
  else{

    printf("ROOM NAME: %15s|", ghost->room->name);
  }

  if(ghost->ghostType == POLTERGEIST){
    printf("GHOST TYPE: %15s|", "POLTERGEIST");
  }
  else if(ghost->ghostType == WRAITH){
    printf("GHOST TYPE: %15s|", "WRAITH");
  }
  else if(ghost->ghostType == PHANTOM){
    printf("GHOST TYPE: %15s|", "PHANTOM");
  }
  else if(ghost->ghostType == OTHER){
    printf("GHOST TYPE: %15s|", "OTHER");
  }
  else if(ghost->ghostType == BULLIES){
    printf("GHOST TYPE: %15s|", "BULLIES");
  }
  else{
    printf("GHOST TYPE: %15s|", "UNKNOWN");
  }

  printf("LIKELIHOOD: %16.1f|\n", ghost->likelihood);
}
/*
  Function: printGhosts
  Purpose: prints all ghosts in a GhostListType
  in: The List
  return:   void
*/
void printGhosts(GhostListType *list, int ends){
    NodeType *currNode = list->head;

    if(list->head == NULL){
      printf("empty list");
      return;
    }

    while (currNode != NULL) {
        printGhost(currNode->data);
        currNode = currNode->next;

    }
  }

  /*
    Function: printByLikelihood
    Purpose: prints all ghost in the list in descending order of likelihood
    in: The List 
    return:   void
  */
void printByLikelihood(GhostListType *origList, int ends){
  GhostListType localList;
  initGhostList(&localList);

  NodeType *currNode = origList->head;

  while (currNode != NULL) {
    addGhostByLikelihood(&localList, currNode->data);
    currNode = currNode->next;
  }
  printGhosts(&localList, ends);
  cleanupGhostList(&localList);
}

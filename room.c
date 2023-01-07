#include "defs.h"
/*
  Function:  initRoomArray
  Purpose:   initializes the RoomArrayType
   in/out:   the RoomArrayType with an initial size set
   return:   void
*/
void initRoomArray(RoomArrayType *arr){
  arr->size = 0;
}
/*
  Function:  initRoom
  Purpose: initializes the RoomType with the given parameters
  in: the id to be set
  in: the name of the room
  out: the RoomType
 return:   void
*/
void initRoom(int id, char *name, RoomType** room){
  *room = (RoomType*) calloc(1, sizeof(RoomType));
  (*room)->id = id;
  strcpy((*room)->name, name);
  GhostListType* newGhostList = (GhostListType*) calloc(1, sizeof(GhostListType));
  initGhostList(newGhostList);
  (*room)->ghosts = newGhostList;


}
/*
  Function:  addRoom
  Purpose:   adds a RoomType to a RoomArrayType
  in:   The RoomType to be added to the RoomArrayType
  out: The updated RoomArrayType
  return:   void
*/
void addRoom(RoomArrayType *arr, RoomType *r){
  arr->elements[arr->size] = r;
  arr->size += 1;
}
/*
  Function:  cleanupRoomArray
  Purpose:   frees up the allocated space for the RoomArrayType and its attributes
   in:   The RoomArrayType to be 'cleaned'
   return:   void
*/
void cleanupRoomArray(RoomArrayType *arr){
  for(int i = 0; i< arr->size; i++){
    cleanupGhostList(arr->elements[i]->ghosts);
    free(arr->elements[i]->ghosts);
    free(arr->elements[i]);
  }

}
/*
  Function:  printRooms
  Purpose:   displays the Rooms along with their attributes in a RoomArrayType
   in:   The RoomArrayType
   return:   void
*/
void printRooms(RoomArrayType *arr){


  for(int i = 0; i< arr->size; i++){
    printf("ID: %d", arr->elements[i]->id);
    printf("|ROOM: %15s|\n", arr->elements[i]->name);
    printGhosts(arr->elements[i]->ghosts, C_FALSE);
    printf("\n");
  }
}

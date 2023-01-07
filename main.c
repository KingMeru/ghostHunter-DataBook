#include "defs.h"

int main(){
  BuildingType localBuilding;
  initBuilding(&localBuilding);
  loadBuildingData(&localBuilding);

  int choice;

  printMenu(&choice);
  if(choice == 0){
    cleanupBuilding(&localBuilding);
    return 0;
  }

  while(choice != 0){
    if(choice == 1){
      printRooms(&localBuilding.rooms);
    }

    if(choice == 2){
      printGhosts(&localBuilding.ghosts, 1);
    }

    if(choice == 3){
      printByLikelihood(&localBuilding.ghosts,1);
    }
    printMenu(&choice);
  }

  cleanupBuilding(&localBuilding);
  return(0);
}
/*
  Function:  printMenu
  Purpose:   displays the menu for the user
   out:   The Notebook whose capacity is to be increased
   return:   void
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

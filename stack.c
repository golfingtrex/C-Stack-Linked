#include "lstack.h"
#include "menu.h"

//void Print(StackEntry x);

int main(void) {

    system("clear");
    Stack st;
    CreateStack(&st);

    //while(!StackFull(&st)){
      //  Push('a', &st);
   // }
    while(TRUE)
        DoCommand(GetCommand(), &st);

    return 0;
}

/*
void Print(StackEntry x) {
    printf("%c ", x);
}
*/

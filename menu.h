#include <ctype.h>
#include <unistd.h> // for system("clear")

void Help(void); /* checked */
char GetCommand(void);
void DoCommand(char command, Stack *s);
void Print(StackEntry x);

/* Help
 * Pre:     None.
 * Post:    A help screen for the program has been printed.
 * */
void Help(void) {
    printf("\nThis program allows one command to be entered on each line.\n"
            "For example, if the command I is entered at the command line\n"
            "then the program will ask for a character and\n"
            "then push it onto the stack.\n");
    printf("Valid commands are:\n"
            "\tI - Insert (push) value onto the stack.\n"
            "\tD - Delete top entry (pop) from the stack.\n"
            "\tP - Print the stack.\n"
            "\tE - Peek the top entry of the stack.\n"
            "\tT - Traverse the stack (same as print).\n"
            "\tS - Size of the stack.\n"
            "\tC - Clear (delete all) the stack.\n"
            "\tH - This help screen.\n"
            "\tQ - Quit.\n"
            "\tK - Clear screen.\n"
            "Press <Enter> to continue.");
    while (getchar() != '\n')
        ;
    system("clear");
}

/* GetCommand
 * Pre:     A menu listing valid options is listed.
 * Post:    Valid option is returned in command variable.
 * */
char GetCommand(void) {
    char command;
    printf("\n\t[I]nsert entry\t\t[D]elete entry\t\t[P]rint stack"
            "\n\tp[E]ek top entry\t[T]raverse stack\t[S]ize of stack"
            "\n\t[C]lear stack\t\t[H]elp\t\t\t[Q]uit\n"
            "\t\t\t\t[K]clear screen\n"
            "Select command and press <Enter>:");
    while(TRUE) {
        while((command = getchar())=='\n')
            ;
        command = tolower(command);
        if( command == 'i' || command == 'd' || command == 'p' ||
            command == 'e' || command == 't' || command == 's' ||
            command == 'c' || command == 'h' || command == 'q' ||
            command == 'k') {
            while(getchar() != '\n')
                ;
            return command;
        }
        printf("Please enter a valid command or H for help:");
    }
}

/* DoCommand
 * Pre:     Command contains a valid command.
 * Post:    Performs command on stack.
 * */
void DoCommand(char command, Stack *s) {
    StackEntry x;
    switch(command) {
        case 'i':
            system("clear");
            if(StackFull(s)){
                Warning("Cannot push, stack is full.");
            }
            else {
                printf("Enter new item to Push:");
                while((x = getchar()) != '\n' && !StackFull(s)) {
                    Push(x, s);
                    printf("%c ", x);
                }
                printf("Pushed.\n");
                if(x != '\n') {
                    Warning("The stack is full, cannot push any more entries.");
                    while((x = getchar()) != '\n')
                        ;
                }
            }
            break;

        case 'd':
            system("clear");
            if(StackEmpty(s)) {
                Warning("Cannot pop, stack is empty.");
            }
            else {
                StackTop(&x, s);
                printf("Popping %c\n", x);
                Pop(s);
            }
            break;

        case 'p':
            system("clear");
            if(StackEmpty(s))
                Warning("Cannot print, stack is empty.");
            else {
                printf("TOP\t");
                TraverseStack(s, Print);
                printf("\tBOTTOM\n");
            }
            break;

        case 'e':
            system("clear");
            if(StackEmpty(s))
                Warning("Cannot print, stack is empty.");
            else {
                StackTop(&x, s);
                printf("Peeking %c\n", x);
            }
            break;

        case 't':
            system("clear");
            if(StackEmpty(s))
                Warning("Cannot print, stack is empty.");
            else {
                printf("TOP\t");
                TraverseStack(s, Print);
                printf("\tBOTTOM\n");
            }
            break;

        case 's':
            system("clear");
            if(StackEmpty(s))
                Warning("Stack size is 0.");
            else {
                printf("Stack size: %d", StackSize(s));
            }
            break;

        case 'c':
            system("clear");
            if(StackEmpty(s))
                Warning("Cannot print, stack is empty.");
            else {
                ClearStack(s);
                printf("Stack cleared.\n");
            }
            break;

        case 'h':
            system("clear");
            Help();
            break;

        case 'q':
            printf("Simple list demonstration finished.\n");
            exit(0);

        case 'k':
            system("clear");
            break;
    }
}

/* Print:   display a StackEntry
 * Pre:     x contains a valid stack entry.
 * Post:    Prints value of x.
 * */
void Print(StackEntry x) {
    printf(" %c", x);
}


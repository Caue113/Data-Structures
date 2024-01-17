#include <stdio.h>
#include <string.h>

typedef struct player{
    //Data and states
    int health;

    //Behavior
    void (*shout)();
    void (*addHealth)();
} player;


char message[256] = {"Hello!\0"};

void shout(char *message){
    if(message != NULL){
        printf("%s\n",message);
    }
    else{
        printf("The message is NULL");
    }
}

void addHealth(player *plr, int health){
    printf("[addHealth] - adding health %d\n", health);

    plr->health += health;
}

player constructPlayer(int health){
    player p = {health, shout, addHealth};
    return p;
}


int main(int argc, char const *argv[])
{
    player myPlr1 = {1, &shout, &addHealth};
    player myPlr2 = constructPlayer(5);

    printf("Initial Player States\n");
    printf("Player  \t|\tHealth\n");
    printf("Player 1\t|\t%d\n",myPlr1.health);
    printf("Player 2\t|\t%d\n",myPlr2.health);

    printf("==============\n");

    printf("Begin Testing struct\n");
    printf("Test 1 - Reading its data\n");
    printf("Health - %d\n", myPlr1.health);

    printf("Test 2 - One way functions\n");
    printf("Player Shout:\n");
    myPlr1.shout(&message);

    printf("Test 3 - 'two way' functions\n");
    myPlr1.addHealth(&myPlr1, 1);
    printf("Player 1 data:\n\tHealth: %d", myPlr1.health);

    scanf("%c");
    return 0;
}

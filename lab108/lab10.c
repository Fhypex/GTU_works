#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Block{
    char type;  // . C - F
    int cost;   // type C = 0 

};

int checkGame(struct Block Board[10][10]){

    int i,j;
    int checkCar_x,checkCar_y,checkFinish_x,checkFinish_y;
    int count = 0;
    for(i = 0; i < 10;i++){
        
        for(j = 0; j < 10;j++){
           if(Board[i][j].type == 'F'){
                count++;
           }
        }
    }
    if(count == 2){
        return 0;
    }
    return 1;
}

int LocateCar(struct Block Board[10][10],char move){
    int cost = 0;
    int i,j;
    int checkCar_x,checkCar_y,checkFinish_x,checkFinish_y;
    for(i = 0; i < 10;i++){
        
        for(j = 0; j < 10;j++){
           if(Board[i][j].type == 'C'){
                checkCar_x = i;
                checkCar_y = j;
           } 
           if(Board[i][j].type == 'F'){
                checkFinish_x = i;
                checkFinish_y = j;
           }  
        }
    }
    struct Block temp;
    switch(move){
        case 'w':
            if((checkCar_x - 1 == checkFinish_x) && (checkCar_y == checkFinish_y)){
                Board[checkCar_x][checkCar_y].type = 'F';
                Board[checkCar_x][checkCar_y].cost = '0';
                break;
            }
            if(checkCar_x != 0){
            temp = Board[checkCar_x - 1][checkCar_y];
            cost += temp.cost;
            temp.type = '-';
            Board[checkCar_x - 1][checkCar_y].type = 'C';
            Board[checkCar_x - 1][checkCar_y].cost = '0';
            
            Board[checkCar_x][checkCar_y] = temp;
            }
        
            
        break;
        case 'a':
        if((checkCar_x == checkFinish_x) && (checkCar_y - 1 == checkFinish_y)){
                Board[checkCar_x][checkCar_y].type = 'F';
                Board[checkCar_x][checkCar_y].cost = '0';
                break;
            }
        if(checkCar_y != 0){
            temp = Board[checkCar_x][checkCar_y - 1];
            temp.type = '-';
            cost += temp.cost;
            Board[checkCar_x][checkCar_y - 1].type = 'C';
            Board[checkCar_x][checkCar_y - 1].cost = '0';
            Board[checkCar_x][checkCar_y] = temp;
        }
        
        break;
        case 's':
        if((checkCar_x + 1 == checkFinish_x) && (checkCar_y == checkFinish_y)){
                Board[checkCar_x][checkCar_y].type = 'F';
                Board[checkCar_x][checkCar_y].cost = '0';
                break;
            }
        
        if(checkCar_x != 9){
            temp = Board[checkCar_x + 1][checkCar_y];
            cost += temp.cost;
            temp.type = '-';
            Board[checkCar_x + 1][checkCar_y].type = 'C';
            Board[checkCar_x + 1][checkCar_y].cost = '0';
            Board[checkCar_x][checkCar_y] = temp;
        }
            
        break;
        case 'd':
            if((checkCar_x == checkFinish_x) && (checkCar_y + 1 == checkFinish_y)){
                Board[checkCar_x][checkCar_y].type = 'F';
                Board[checkCar_x][checkCar_y].cost = '0';
                break;
            }
            if(checkCar_y != 9){
                temp = Board[checkCar_x][checkCar_y + 1];
                cost += temp.cost;
                temp.type = '-';
                Board[checkCar_x][checkCar_y + 1].type = 'C';
                Board[checkCar_x][checkCar_y + 1].cost = '0';
                Board[checkCar_x][checkCar_y] = temp;
            }

        break;
        default:
            printf("Invalid Move");
    }
    return cost;
}

void printBoard(struct Block Board[10][10]){
    int i,j;
    for(i = 0; i < 10;i++){
        printf("\n");
        for(j = 0; j < 10;j++){
            printf("%c",Board[i][j].type);
        }
    }
}

int generateRandom(int limit){

    return rand() % limit + 1;
}

void initBoard(struct Block Board[10][10]){

    int i,j;
    int C_x,C_y,F_x,F_y;
    C_x = rand() % 10 + 1;
    C_y = rand() % 10 + 1;
    F_x = rand() % 10 + 1;
    F_y = rand() % 10 + 1;
    while((C_x == F_x) && (C_y == F_y)){
        F_x = rand() % 10 + 1;
        F_y = rand() % 10 + 1;
    }
    struct Block Car;
    Car.cost = 0;
    Car.type = 'C';
    struct Block Finish;
    Finish.cost = 0;
    Finish.type = 'F';
    struct Block temp;
    temp.cost =  generateRandom(10);
    temp.type = '.';
    for(i = 0; i < 10;i++){
        
        for(j = 0; j < 10;j++){
            temp.cost =  generateRandom(10);
            if( (i != C_x || j != C_y ) ||  (i != F_x || j != F_y ) ){

                Board[i][j] = temp;
            }
        }
    }
    Board[C_x][C_y] = Car;
    Board[F_x][F_y] = Finish;
}

void printMoves(char Moves[], int size){

    int i;
    printf("\nMoves = ' ");
    for(i = 0; i < size ;i++){
        printf("%c , ",Moves[i]);
    }
}

int randomRecursive(int array[], int size, int query,int index, int current){

    if(index == size){
        printf("Closest number is: %d",current);
        return current;
    }

    if(abs(query - array[index]) < abs(query - current)){
        current = array[index];
    }
    
    randomRecursive(array,size,query,index + 1,current);
}

int gamePlay(struct Block Board[10][10], char Moves[]){
    int buffer;
    initBoard(Board);
    char move;
    int cost = 0;
    int temp = 0;
    char array[50] = "asdasdasdasd";
    int cur = 0;
    int i;
    while(checkGame(Board)){
        printBoard(Board);
        printMoves(Moves,4);
        printf("\nEnter Move: ");
        scanf("%d",&buffer);
        scanf("%c",&move);
        switch(move){
            case 'w':
                array[cur] = '^';
            break;
             case 'a':
                array[cur] = '<';
            break;
             case 's':
                array[cur] = 'v';
            break;
             case 'd':
                array[cur] = '>';
            break;
        }
        if(move == 'r') break;
        cur++;
        printf("Current moves: ");
        for(i = 0; i < cur; i++){
            printf("%c - ",array[i]);
        }
        temp = LocateCar(Board,move);
        printf("\n%d is current cost",temp);
        cost += temp;
    }
    printf("Total cost is : %d",cost);
}

int main(){
    
    srand(time(NULL));
    int Array[10];
    int i,j;
    for(i = 0; i < 10; i++){

        Array[i] = generateRandom(1000);
        printf("%d - ",Array[i]);
    }

    int query;
   // printf("Enter Query: ");
   // scanf("%d",&query);
    //randomRecursive(Array,10,query,0,Array[0]);
    
    struct Block Board[10][10];
    char Moves[4] = {'v' ,'^' , '>' , '<'};
    gamePlay(Board,Moves);





    return 0;
}
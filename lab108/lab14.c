#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct path{
    int cost;
    int dest;
}path;

typedef struct node{
    int pathcount;
    int num;
    struct node* next;
    path paths[10];   
}node;

typedef struct treeHouse{
    int count;
    node* array;

}treeHouse;

void newTreeHouse(node* head, int newnum){
    node* newnode = malloc(sizeof(node));
    newnode->pathcount = 0;
    newnode->num = newnum;
    newnode->next = NULL;
    //printf("newnode = %d",newnode->pathcount);
    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
}

void printList(node* head){
    node* temp = head;
    int i;
    printf("<--- printing map --->\n");
    while(temp != NULL){
        printf("Tree House %d\n",temp->num);
        printf("head ->");
        for(i = 0; i < temp->pathcount; i++){
            
            printf("%d(%d) ->",temp->paths[i].dest , temp->paths[i].cost);
        }
        printf("\n");
        temp = temp->next;
    }
}

void freeList(node* head){
    node* temp = head;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->paths);
        free(temp);   
    }
}

void addPath(node* head , int num1 , int num2, int newcost){
    node* current = head;
   
    while(current->num != num1){
     
        current = current->next;
    }
    current->paths[current->pathcount].cost = newcost;
    current->paths[current->pathcount].dest = num2;
   
    current->pathcount++;
    
    //printf("new path count is = %d\n",current->pathcount);
     
}

void init_map(node* head){

    addPath(head,1,2,30);
    addPath(head,1,3,20);
    addPath(head,2,4,30);  
    addPath(head,2,9,50);
    addPath(head,3,5,5);
    addPath(head,3,7,30);
    addPath(head,3,8,10);
    addPath(head,4,6,30);
    addPath(head,4,5,5);
    addPath(head,5,6,10);
    addPath(head,7,5,5);
    addPath(head,7,6,10);
    addPath(head,8,6,31);
    addPath(head,8,4,12);
    addPath(head,9,6,1);
}


void solve_puzzle(node* head,int health){

    node* current = head;
    int tempo;
    int random = rand() % current->pathcount;
    
    printf("\nPath: ");

    while(current->num != 6){

        random = rand() % current->pathcount;
        printf("%d -> ",current->num);
        if(current->num > current->paths[random].dest){
            tempo = current->paths[random].dest;
            
            node* temp = head;
            health -= current->paths[random].cost;
            while(temp->num != tempo){
                temp = temp->next;
                
            }
            current = temp;
        }else{
            
            health -= current->paths[random].cost;
            
            tempo = current->paths[random].dest;
            while(current->num != tempo){
                current = current->next;
                
            }
        }
    }
    printf("6 Heros remaining health = %d",health);
}
int main(){

    srand(time(NULL));
    node* head = malloc(sizeof(node));
    head->next = NULL;
    head->num = 1;
    head->pathcount = 0;
    newTreeHouse(head,2);
    newTreeHouse(head,3);
    newTreeHouse(head,4);
    newTreeHouse(head,5);
    newTreeHouse(head,6);
    newTreeHouse(head,7);
    newTreeHouse(head,8); 
    newTreeHouse(head,9);
    init_map(head);
    printList(head);
    solve_puzzle(head,100);
    freeList(head);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct shape{
    float x[4];
    float y[4];
    int n;
    float area;
    struct shape* next;
}shape;

shape* read(char* filename){
    FILE* fp = fopen("shape1.txt","r");
    shape* temp;
    temp = NULL;
    temp = malloc(sizeof(shape));
    shape* head;
    head = NULL;
    char temp4;
    char* array;
    char temp3;
    int temp2;
    int count = 0;
  //  while(fp != EOF){
        while(fscanf(fp,"%c%c%d,%f,%f,%f\n",&temp4 ,&temp3 ,&temp2 , &temp->x[1] , &temp->x[2] , &temp->x[3]) == 6){
            
            printf("== x %.2f - %.2f - %.2f",temp->x[1],temp->x[2],temp->x[3]);
            fscanf(fp,"%c%c%d,%f,%f,%f\n",&temp4 ,&temp3 ,&temp2 , &temp->y[1] , &temp->y[2] , &temp->y[3]);
            printf("\n== y %.2f - %.2f - %.2f",temp->y[1],temp->y[2],temp->y[3]);
            if(head == NULL){
                head = malloc(sizeof(shape));
                head = temp;
                free(temp);
            }else{
                printf("\n");
                shape* another = head;
                head = another;
                if(another->next == NULL){
                    head->next = temp;
                }else{
                    while(another->next != NULL){
                        printf("ONEMLI");
                        another = another->next;
                    }
                    another->next = temp;
                }
                
                free(temp);
            }
            temp = malloc(sizeof(shape));
            temp->next = NULL;
        }
 //   }
    return head;
    fclose(fp);
}

void calc_areas(shape* head){
    shape* temp = malloc(sizeof(shape));
    temp = head;
    printf("Shape1 Areas: \n");
    printf("%.2f",temp->x[1]);
    while(temp->next != NULL){
        printf("GIGAA");
        temp->area = 0.5 * (((temp->x[1] * temp->y[2]) - (temp->x[2] * temp->y[1])) + ((temp->x[2] * temp->y[3]) - (temp->x[3] * temp->y[2])) + ((temp->x[3] * temp->y[1]) - (temp->x[1] * temp->y[3])));
        printf("%.2f",temp->area);
        temp = temp->next;
    }
}






int main(){

    shape* A;
    A = malloc(sizeof(shape));
    A = read("shape.txt");
    calc_areas(A);



    return 0;
}
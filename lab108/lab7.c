#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COL 15
#define MAX_ROW 20

void readFFloat(char *file_name , float output[][MAX_COL], int numrows, int numcols){
    
    char *nan = "NaN";
    char *check;
    char asd;
    char line[100];
    int i,j;
    float temp;
    for(i = 0; i < 15 ;i++){

        for(j = 0; j < 20 ;j++){
            output[i][j] = 0.0;
        }

    }
    FILE* fp = fopen(file_name , "r");
   
    int index1,index2;
    index1 = 0; index2 = 0;
    int count = 0;
    while(fp != NULL){
       /* fgets(line,count,fp);
        while(line != "\n"){
            if(sscanf(line,"%f,",&temp) == 1){
                output[index1][index2] = temp;
                printf("Float");
            }
            else if(sscanf(line,"%s,",&check) == 1 && (strcmp(nan,check) == 0)){
                output[index1][index2] = 0;
            
            }
            
        }
        count++;
     */
        if(fscanf(fp,"%f,",&temp) == 1){
            output[index1][index2] = temp;
           
            count++;
        }
        else if(fscanf(fp,"Na%c,",&asd) == 1){
            output[index1][index2] = 0;
           
            count++;
        }
        else{
            break;
        }
        index2++;
        if(count == 15){
        index1++;
        count = 0;
        index2 = 0;
        }       
    }
    
    for(j = 0; j < index1; j++){
        printf("\n");
        for(i = 0; i < 20 ;i++){
            printf("%.2f - ",output[j][i]);
        }
    }
    printf("\n");
    for(i = 0; i < index2 ; i++){
        
        printf("%.2f - ",output[j][i]);
        
    }
    fclose(fp);
   
}

int CountLetter(char *target , char letter ,int size){
    int i;
    int counter = 0;
    for(i = 0; i < size ;i++){
        if(target[i] == letter){
            counter++;
        }
    }
    return counter;
}

void mostCountedLetter(char *target, char *alphabet,int size){

    int i;
    int countArr[26];

    for(i  = 0; i < 26 ; i++){
       countArr[i] = 0;
    }

    for(i  = 0; i < 26 ; i++){
        countArr[i] = CountLetter(target , alphabet[i] , 92);
    }
    int index1,index2,index3;
    int index;
    int max = 0;
    for(i = 0; i < 26 ; i++){
        if(countArr[i] > max ){
            max = countArr[i];
            index = i;
        }
    }
    index1 = index;
    max = 0; 
    index = 0;
    for(i = 0; i < 26 ; i++){
        if(countArr[i] > max && i != index1){
            max = countArr[i];
            index = i;
        }
    }
    index2 = index;
    index = 0;
    max = 0; 
    for(i = 0; i < 26 ; i++){
        if(countArr[i] > max && i != index1 && i != index2){
            max = countArr[i];
            index = i;
        }
    }
    index3 = index;
    printf("1st letter: %c - %d times, ", alphabet[index1], countArr[index1]);
    printf("2nd letter: %c - %d times, ", alphabet[index2], countArr[index2]);
    printf("3rd letter: %c - %d times  ", alphabet[index3], countArr[index3]);
}

int main(){

    char array[92] = {"silent shadows waltz with the moons gentle glow painting poetry upon the canvas of the night"};
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i,j;
    int values[15][20];
    char *filename = "dosya.txt";
    
    mostCountedLetter(array , alphabet , 92);
    float output[MAX_COL][MAX_ROW];
    readFFloat(filename,output,15,20);
    return 0;
}
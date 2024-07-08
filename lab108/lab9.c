#include <stdio.h>
#include <math.h>
#include <string.h>

int hailstone(int nums[],int *count,int maxit){
    int temp = 0;
    printf("%d - ",nums[*count]);
    if(nums[*count] == 1 && *count < maxit){
        return 1;
    }
    if(nums[*count] % 2 == 0){
        temp = nums[*count] / 2;
    }
    else{
        temp = nums[*count] * 3;
        temp++;
    }
    
    *count = *count + 1;
    nums[*count] = temp;
    hailstone(nums,count,maxit);
}

int palindrome(char* string, int length, int index){
    if(index == length/2 && length % 2 == 0){
        printf("\n%s is a palindrome\n",string);
        return 1;
    }else if(index == (length-1) / 2 && length % 2 == 1){
        printf("\n%s is a palindrome\n",string);
        return 1;
    }
    if(string[index] == string[length-1-index]){
        palindrome(string,length,index+1);
    }else{
        printf("\n%s is not palindrome\n",string);
        return 0;
    }
}

void substring(char* string,int length, int index,char start,int startindex){
   /* if(start == string[index] && index != 0){
        int i;
        for(i = startindex; i < index ;i++){
            printf("%c",string[i]);
        }
    }
    index++;
    if(start != string[index]){
        start = string[index]; 
        startindex = index;
        substring(string,length,index,start,startindex);
    }
    substring(string,length,index,start,startindex);
    */
   if(index == 0){
        substring(string,length,index + 1,string[index],startindex);
   }
   else if(string[index] != start && index < length){  
      
        substring(string,length,index + 1,string[index],index);
        substring(string,length,index + 1,start,startindex);
   }
   else if(string[index] == start){
        int i;
        for(i = startindex; i < index+1 ;i++){
            printf("%c",string[i]);
        }
        printf("\n");
   }
   
    
}


int main(){
    int count = 0;
    int arr[100];
    int i;
    
    for(i = 0; i < 100; i++){
        arr[i] = 0;
    }
    arr[0] = 4;
   // hailstone(arr,&count,100);
    char* word = "weklterkyn";
    char* word2 = "qejtlqelkgnqlne";
    char* word3 = "caba";
    int length1,length2;
    length1 = strlen(word);
    length2 = strlen(word2);
   // palindrome(word,length1,0);
   // palindrome(word2,length2,0);
    substring(word3,4,0,word3[0],0);

    return 0;
}
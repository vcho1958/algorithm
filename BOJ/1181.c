#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    char **wordList = NULL; 
    int *wordListN = NULL;
    scanf("%d", &N);
    wordListN = (char*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        wordList[i] = (char*)malloc(sizeof(char)*51);
    }
    
    for(int i = 0; i < N; i++){
        scanf("%s", wordList[i]);
        wordListN[i] = 0;
        for(char* a = wordList[i]; *a;a++){
            wordListN[i]++;
        }
    }
    for(int i = 0; i < N-1; i++){
        int minIndex = i;
        for(int j = i+1; j < N; j++){
            char* word = wordList[j];
            int wordN = wordListN[j];
            if(wordListN[minIndex] > wordListN[j])minIndex = j;
            else if(wordListN[minIndex] == wordListN[j]){
                for(char* minP = wordList[minIndex], *wordP = word; *minP;minP++,wordP++){
                    if(*minP > *wordP)minIndex = j;
                }
            }
        }
        if(minIndex == i)continue;
        char *tmp = wordList[minIndex];
        wordList[minIndex] = wordList[i];
        wordList[i] = tmp;
    }
    for(int i = 0; i < N; i++){
        for(char *p = wordList[i]; *p; p++){
            printf("%s\n", p);
        }
    }
}
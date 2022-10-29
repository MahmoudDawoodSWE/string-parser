//mahmoud dawood
//322943408
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// method to read "file.txt" file
void readHistory();
int main() {
    char word [510];
    while(1){
        int charNumber=0;
        int wordNumber=0;
        // the word without spaces
        char cutWord[510];
        printf("Enter String, or “exit” to end program:\n");
            fgets(word,510,stdin);
            word[strlen(word)-1]='\0';
            strcpy(cutWord,word);
        // To keep track of non-space character count
        int count = 0;
        for (int i = 0; cutWord[i]; i++)
            if (cutWord[i] != ' ')
                cutWord[count++] = cutWord[i]; // count++
        cutWord[count] = '\0';

        //if exit was entered stop the loop
        if(strcmp(cutWord,"exit")==0)
            break;
        //if history was entered ,call method to print the history and continue to the next iteration
        if(strcmp(cutWord,"history")==0){
            readHistory();
            continue;}
        //if the user entered empty input continue to the next iteration
        if(strcmp(cutWord,"")==0){
            continue;}
        //open file to add new information
        FILE *file = fopen("file.txt","a");
        if(file == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }
        //write the word
        fputs(word,file);
        fputc('\n',file);
        // counting the word
        // counting the chars

        for (int i=0;i<strlen(word);i++){
            //if in  the first place there are word
            if (i==0&&word[i]!=' ')
                wordNumber++;
            //if ' ' came before char in sequence this mean there is word
            if(word[i]==' '&&word[i+1]!=' '&&word[i+1]!='\0')
                wordNumber++;
            //char counter without ' '
            if( word[i]!=' '){
                charNumber++;}
        }
        printf("%d words \n",wordNumber);
        printf("%d chars \n",charNumber);
        fclose(file);
    }
    return 0;
}
void  readHistory(){
    FILE *read = fopen("file.txt","r");
    if(read == NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    char line[511];
    int numberLine=0;
    while(fgets(line,511,read)){
        numberLine++;
        printf("%d : %s",numberLine,line);}
    fclose(read);
}
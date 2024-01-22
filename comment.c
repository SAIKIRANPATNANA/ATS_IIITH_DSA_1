#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comment.h"

comment* createComment(comment* firstComment, char* username, char** content, int num_lines){
    comment* newComment = (comment*)malloc(sizeof(comment));
    if(newComment!=NULL) {
        newComment->username = strdup(username);
        newComment->content = (char**)malloc(sizeof(char*)*num_lines);
        for(int i=0; i<num_lines; i++){
           newComment->content[i] = strdup(content[i]);
        }newComment->nextComment = NULL;
        newComment->num_lines = num_lines;
        if(firstComment==NULL) {
            newComment->id = 1;
            firstComment = newComment;
            return firstComment;
        }comment* tempComment = firstComment;
        while(tempComment->nextComment!=NULL){
            tempComment = tempComment->nextComment;
        }newComment->id = tempComment->id+1;
        tempComment->nextComment = newComment;
        return newComment;
    }return NULL;
}







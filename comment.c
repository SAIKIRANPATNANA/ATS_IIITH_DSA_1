#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comment.h"
#include "platform.h"
#include "post.h"

comment* createComment(char* username, char** content){
    comment* newComment = (comment*)malloc(sizeof(comment));
    int num_lines;
    if(newComment!=NULL) {
        char unformatted_username[25];
        sscanf(username, "%[^_]_%d", unformatted_username, &num_lines);
        newComment->username = strdup(unformatted_username);
        newComment->content = (char**)malloc(sizeof(char*)*num_lines);
        for(int i=0; i<num_lines; i++){
           newComment->content[i] = strdup(content[i]);
        }newComment->nextComment = NULL;
        newComment->num_lines = num_lines;
        if(pf->lastViewedPost->comments==NULL) {
            newComment->id = 1;
            pf->lastViewedPost->comments = newComment;
            return pf->lastViewedPost->comments;
        }comment* tempComment = pf->lastViewedPost->comments;
        while(tempComment->nextComment!=NULL){
            tempComment = tempComment->nextComment;
        }newComment->id = tempComment->id+1;
        tempComment->nextComment = newComment;
        return newComment;
    }return NULL;
}







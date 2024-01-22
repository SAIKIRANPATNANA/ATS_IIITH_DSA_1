#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"
#include "comment.h"

post* createPost(post** firstPost, char* username, char** caption,int num_lines){
    post* newPost = (post*)malloc(sizeof(post));
    if(newPost!=NULL){
        newPost->username = strdup(username);
        newPost->caption = (char**)malloc(sizeof(char*)*num_lines);
        for(int i=0; i<num_lines; i++){
           newPost->caption[i] = strdup(caption[i]);
        }newPost->num_comments = 0;
        newPost->num_lines = num_lines;
        newPost->nextPost = NULL;
        newPost->comments = NULL;
        if(*firstPost==NULL) {
            newPost->id = 1;
            *firstPost = newPost;
            return *firstPost;
        }post* tempPost = *firstPost;
        while(tempPost->nextPost!=NULL){
            tempPost = tempPost->nextPost;
        }newPost->id = tempPost->id+1;
        tempPost->nextPost = newPost;
        return newPost;
    }return NULL;
}


















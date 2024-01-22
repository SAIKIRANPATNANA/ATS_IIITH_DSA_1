#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "platform.h"
#include "post.h"
#include "comment.h"

platform* createPlatform(platform* pf) {
    platform* newPlatform = (platform*)malloc(sizeof(platform));
    if(newPlatform!=NULL && pf==NULL){
        newPlatform->num_posts = 0;
        newPlatform->lastViewedPost = NULL;
        newPlatform->posts = NULL;
        return newPlatform;
    }return NULL;
}int addPost(platform* pf, char* username, char** caption, int num_lines){
    post* newPost = createPost(&(pf->posts),username,caption,num_lines);
    if(newPost!=NULL){
        if(pf->lastViewedPost==NULL){
            pf->lastViewedPost = newPost;
        }pf->num_posts += 1;
        return 1;
    }return 0;
}void freeComments(comment* comments){
    while(comments!=NULL){
        comment* tempComment = comments;
        freeContent(tempComment->content, tempComment->num_lines);
        free(tempComment);
        comments = comments->nextComment;
    }return;
}void freeContent(char** content, int num_lines){
    for(int i=0; i<num_lines; i++){
        free(content[i]);
    }free(content);
    return;
}int deletePost(platform *pf, int n){
    if(n<=pf->num_posts){
        post* tempPost = pf->posts;
        if(n==1){
            pf->posts = tempPost->nextPost;
            freeContent(tempPost->caption,tempPost->num_lines);
            freeComments(tempPost->comments);
            free(tempPost);
            return 1;
        }while(tempPost->nextPost!=NULL && tempPost->nextPost->id!=n){
            tempPost = tempPost->nextPost;
        }if(tempPost->nextPost!=NULL){
            post* delPost = tempPost->nextPost;
            tempPost->nextPost = tempPost->nextPost->nextPost;
            freeComments(delPost->comments);
            free(delPost);
            return 1;
        }
    }return 0;
}post* viewPost(platform* pf, int n){
    if(n<=pf->num_posts){
        post* tempPost = pf->posts;
        if(tempPost==NULL){
        }while(tempPost!=NULL && tempPost->id!=n){
            tempPost = tempPost->nextPost;
        }if(tempPost!=NULL){
            pf->lastViewedPost = tempPost;
            return tempPost;
        }
    }return NULL;
}post* currPost(platform* pf){
    if(pf->lastViewedPost!=NULL){
        return pf->lastViewedPost;
    }return NULL;
}post* nextPost(platform* pf){
    if(pf->lastViewedPost!=NULL){
        if(pf->lastViewedPost->id ==  1){
            return pf->lastViewedPost;
        }else{
            int nextPost_id = pf->lastViewedPost->id-1;
            post* tempPost = pf->posts;
            while(tempPost!=NULL &&  tempPost->id!=nextPost_id){
                tempPost = tempPost->nextPost;
            }if(tempPost!=NULL){
                pf->lastViewedPost = tempPost;
                return tempPost;
            }
        }
    }return NULL;
}post* previousPost(platform* pf){
    if(pf->lastViewedPost!=NULL &&  pf->num_posts>=pf->lastViewedPost->id){
        if(pf->num_posts == pf->lastViewedPost->id){
            return pf->lastViewedPost;
        }else{
            int previousPost_id = pf->lastViewedPost->id+1;
            post* tempPost = pf->posts;
            while(tempPost!=NULL &&  tempPost->id!=previousPost_id){
                tempPost = tempPost->nextPost;
            }if(tempPost!=NULL){
                pf->lastViewedPost = tempPost;
                return tempPost;
            }
        }
    }return NULL;
}int addComment(platform* pf, char* username , char** content, int num_lines){
    if(pf->lastViewedPost!=NULL){
       comment* newComment = createComment(pf->lastViewedPost->comments,username,content,num_lines);
       if(newComment!=NULL){
           pf->lastViewedPost->num_comments += 1;
           return 1;
       }
    }return 0;
}int deleteComment(platform* pf, int n){
    if(pf->lastViewedPost!=NULL &&  n<=pf->lastViewedPost->num_comments){
        comment* tempComment = pf->lastViewedPost->comments;
        if(n==1){
            pf->lastViewedPost->comments = tempComment->nextComment;
            freeContent(tempComment->content,tempComment->num_lines);
            free(tempComment);
            return 1;
        }while(tempComment->nextComment!=NULL &&  tempComment->nextComment->id!=n){
            tempComment = tempComment->nextComment;
        }if(tempComment->nextComment!=NULL){
            comment* delComment = tempComment->nextComment;
            tempComment->nextComment = tempComment->nextComment->nextComment;
            free(delComment);
            return 1;
        }
    }return 0;
}comment* viewComments(platform* pf){
    if(pf->lastViewedPost!=NULL &&  pf->lastViewedPost->comments!=NULL){
        return pf->lastViewedPost->comments;
    }return NULL;
}










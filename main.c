#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"
#include "post.h"
#include "comment.h"

platform* pf = NULL;
struct post* firstPost = NULL;
struct comment* firstComment = NULL;
int flag = 1;

int main() {
   
    char cmd[20];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"create_platform")==0){
            if(pf==NULL) {
                pf = createPlatform();
                if(pf==NULL){
                    printf("Platform creation is NOT SUCCESSFUL.\n");
                    break;
                }printf("Platform creation is SUCCESSFUL.\n");
            }else{
                printf("Platform  is already created.\n");
            }
        }else if(strcmp(cmd,"add_post")==0){
            char username[25];
            char formatted_username[38];
            char* caption[30];
            char line[100];
            printf("username: ");
            scanf("%s",username);
            printf("caption(enter POST to stop!): \n");
            fgets(line,sizeof(line),stdin);
            int i = 0;
            while(strcmp(line,"POST\n")!=0) {
                caption[i] = strdup(line);
                fgets(line,sizeof(line),stdin);
                i++;
            }sprintf(formatted_username,"%s_%d",username,i);
            if(addPost(formatted_username,caption)){
                printf("Post addition is SUCCESSFUL.\n");
            }else {
                printf("Post addition is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"delete_post")==0){
            int n;
            scanf("%d", &n);
            if(deletePost(n)){
                printf("Post deletion is SUCCESSFUL.\n");
            }else {
                printf("Post deletion is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"view_post")==0){
            int n;
            scanf("%d", &n);
            post* view_post = viewPost(n);
            if(view_post!=NULL){
                printf("%s\n",view_post->username);
                for(int i=1; i<view_post->num_lines; i++){
                    printf("%s",view_post->caption[i]);
                }printf("View post is SUCCESSFUL.\n");
            }else {
                printf("View post is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"current_post")==0){
            post* current_post = currPost();
            if(current_post!=NULL){
                printf("%s\n",current_post->username);
                for(int i=1; i<current_post->num_lines; i++){
                    printf("%s",current_post->caption[i]);
                }printf("Current post is SUCCESSFUL.\n");
            }else{
                printf("Current post is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"previous_post")==0){
            post* previous_post = previousPost();
            if(previous_post!=NULL){
                printf("%s\n",previous_post->username);
                for(int i=1; i<previous_post->num_lines; i++){
                    printf("%s",previous_post->caption[i]);
                }printf("Previous post is SUCCESSFUL.\n");
            }else{
                printf("Previous post is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"next_post")==0){
            post* next_post = nextPost();
            if(next_post!=NULL){
                printf("%s\n",next_post->username);
                for(int i=1; i<next_post->num_lines; i++){
                    printf("%s",next_post->caption[i]);
                }printf("Next post is SUCCESSFUL.\n");
            }else{
                printf("Next post is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"add_comment")==0){
            char formatted_username[38];
            char username[25];
            char* content[30];
            char line[100];
            printf("username: ");
            scanf("%s",username);
            printf("content(enter COMMENT to stop!): \n");
            fgets(line,sizeof(line),stdin);
            int i = 0;
            while(strcmp(line,"COMMENT\n")!=0) {
                content[i] = strdup(line);
                fgets(line,sizeof(line),stdin);
                i++;
            }sprintf(formatted_username,"%s_%d",username,i);
            if(addComment(formatted_username,content)){
                printf("Comment addition is SUCCESSFUL.\n");
            }else {
                printf("Comment addition is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"view_comments")==0){
            comment* comments = viewComments();
            if(comments!=NULL){
                comment* tempComment = comments;
                while(tempComment!=NULL){
                    printf("%s\n",tempComment->username);
                    for(int i=1; i<tempComment->num_lines; i++){
                        printf("%s",tempComment->content[i]);
                    }tempComment = tempComment->nextComment;
                }printf("View Comments is SUCCESSFUL.\n");
            }else{
                printf("View Comments is NOT SUCCESSFUL.\n");
                break;
            }
        }else if(strcmp(cmd,"delete_comment")==0){
            int n;
            scanf("%d", &n);
            if(deleteComment(n)){
                printf("Comment deletion is SUCCESSFUL.\n");
            }else{
                printf("Comment deletion is NOT SUCCESSFUL.\n");
                break;
            }
        }else {
            break;
        }
    }return 0;
}


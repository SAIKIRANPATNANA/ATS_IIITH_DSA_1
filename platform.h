typedef struct post post;  
typedef struct comment comment;

typedef struct platform {
    struct post* posts;
    int num_posts;
    struct post* lastViewedPost;
}platform;

platform* createPlatform(platform* pf);
int addPost(platform* pf, char* username, char** caption, int num_lines);
void freeComments(comment* comments);
void freeContent(char** content, int num_lines);
int deletePost(platform *pf, int n);
post* viewPost(platform* pf, int n);
post* currPost(platform* pf);
post* nextPost(platform* pf);
post* previousPost(platform* pf);
int addComment(platform* pf, char* username , char** content, int num_lines);
int deleteComment(platform* pf, int n);
comment* viewComments(platform* pf);





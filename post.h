typedef struct comment comment;
typedef struct platform platform;

typedef struct post{
    int id;
    char* username;
    char** caption;
    struct comment* comments;
    int num_comments;
    struct post* nextPost;
    int num_lines;
}post;

post* createPost(post** fisrtPost, char* username, char** caption, int num_lines);









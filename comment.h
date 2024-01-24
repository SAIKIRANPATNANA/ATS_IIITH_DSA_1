typedef struct platform platform;
typedef struct post post;

typedef struct comment{
    int id;
    char* username;
    char** content;
    struct comment* nextComment;
    int num_lines;
}comment;

comment* createComment(char* username, char** content);



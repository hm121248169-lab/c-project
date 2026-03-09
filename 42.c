#include<stdio.h>
#include<string.h>

struct Book{
    char book_id[20];
    char title[100];
    char author[50];
    float price;
};

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        struct Book book[100];
        int i;
        for(i=0;i<n;i++){
            scanf("%s", book[i].book_id);
            getchar(); // 读取换行符
            fgets(book[i].title, sizeof(book[i].title), stdin);
            // 移除fgets读取的换行符
            if(book[i].title[strlen(book[i].title)-1] == '\n')
                book[i].title[strlen(book[i].title)-1] = '\0';
            fgets(book[i].author, sizeof(book[i].author), stdin);
            // 移除fgets读取的换行符
            if(book[i].author[strlen(book[i].author)-1] == '\n')
                book[i].author[strlen(book[i].author)-1] = '\0';
            scanf("%f", &book[i].price);
        }
        char id[20];
        scanf("%s", id);
        int find=0;
        for(i=0;i<n;i++){
            if(strcmp(book[i].book_id, id)==0){
                printf("%s %s %s %.2f\n", book[i].book_id, book[i].title, book[i].author, book[i].price);
                find=1;
                break;
            }
        }
        if(!find){
            printf("No find!\n");
        }
    }
    return 0;
}
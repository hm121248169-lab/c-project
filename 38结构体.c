#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];       // 学号
    char name[50];     // 姓名
    char gender;       // 性别
    float score;       // C语言成绩
};

int main() {
    struct Student stu;
    
    // 循环读取多组学生信息，直到没有输入为止
    while (scanf("%s", stu.id) != EOF) {
        // 读取姓名（可能包含空格）
        getchar(); // 读取前面的换行符
        fgets(stu.name, sizeof(stu.name), stdin);
        // 移除姓名末尾的换行符
        stu.name[strcspn(stu.name, "\n")] = 0;
        
        // 读取性别和成绩
        scanf(" %c %f", &stu.gender, &stu.score);
        
        // 按格式输出学生信息
        printf("%s %s %c %.1f\n", stu.id, stu.name, stu.gender, stu.score);
    }
    
    return 0;
}
#include <stdio.h>
#include <string.h>

// 定义复数结构体
struct Complex {
    double real;      // 实部
    double imag;      // 虚部
};

// 解析复数字符串 "(a+bi)" 格式
struct Complex parseComplex(char *str) {
    struct Complex c;
    // 格式化输入 "(a+bi)" 或 "(a-bi)"
    char sign;
    sscanf(str, "(%lf%c%lfi)", &c.real, &sign, &c.imag);
    if (sign == '-') {
        c.imag = -c.imag;
    }
    return c;
}

// 复数加法
struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// 复数减法
struct Complex subtract(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

// 打印复数，保留两位小数
void printComplex(struct Complex c) {
    if (c.imag >= 0) {
        printf("%.2f+%.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f%.2fi\n", c.real, c.imag);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 读取换行符
    
    for (int i = 0; i < n; i++) {
        char line[100];
        fgets(line, sizeof(line), stdin);
        
        // 解析输入行 "(-1+2i)+(-2-3i)"
        struct Complex c1, c2;
        char op;
        char part1[50], part2[50];
        
        // 使用 sscanf 提取两部分复数和操作符
        sscanf(line, "%[^)]%c(%[^)])", part1, &op, part2);
        strcat(part1, ")"); // 补全第一个复数的右括号
        
        c1 = parseComplex(part1);
        c2 = parseComplex(part2);
        
        struct Complex result;
        if (op == '+') {
            result = add(c1, c2);
        } else if (op == '-') {
            result = subtract(c1, c2);
        }
        
        printComplex(result);
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 定义系统常量
#define MAX_ITEMS 1000                    // 系统最大存储项目数量
#define FILE_PROP "properties.txt"        // 房产信息文件名
#define FILE_OWNER "owners.txt"           // 业主信息文件名
#define FEE_PREFIX "fees_"                // 收费记录文件名前缀

// --- 数据结构定义 ---
// 房产信息结构体，用于存储房产相关数据
typedef struct {
    char id[50];        // 房产编号 (格式如：2-1-501)
    float area;         // 建筑面积（平方米）
    char type[50];      // 户型（如：2室1厅）
    char status[20];    // 使用状态（入住、闲置、出租、未售）
    float fee;          // 物业费金额
} Property;

// 业主信息结构体，用于存储业主相关数据
typedef struct {
    char name[50];      // 业主姓名
    char prop_id[50];   // 关联的房产编号
    char cert_no[50];   // 房产证号
    char id_card[50];   // 身份证号
    char phone[20];     // 联系电话
} Owner;

// 收费记录结构体，用于存储收费相关信息
typedef struct {
    char name[50];                      // 业主姓名
    char prop_id[50];                   // 房产编号
    float w_start, w_end;               // 水表读数（起始和结束）
    float e_start, e_end;               // 电表读数（起始和结束）
    float prop_fee;                     // 物业费金额
    float w_fee;                        // 水费金额
    float e_fee;                        // 电费金额
    float total;                        // 总金额（负数表示欠费）
} FeeRecord;

// --- 全局变量 (内存缓存) ---
// 使用全局变量作为内存缓存，提高数据访问效率
Property props[MAX_ITEMS];              // 房产信息数组
int prop_count = 0;                     // 当前房产数量

Owner owners[MAX_ITEMS];                // 业主信息数组
int owner_count = 0;                    // 当前业主数量

// --- 文件操作辅助函数 ---

// 保存房产信息到文件
// 将内存中的房产信息写入到properties.txt文件中
void save_props() {
    FILE *fp = fopen(FILE_PROP, "w");
    if (!fp) return;
    int i; 
    for (i = 0; i < prop_count; i++) {
        fprintf(fp, "%s %.2f %s %s %.2f\n", props[i].id, props[i].area, props[i].type, props[i].status, props[i].fee);
    }
    fclose(fp);
}

// 从文件加载房产信息
// 从properties.txt文件读取房产信息到内存中
void load_props() {
    FILE *fp = fopen(FILE_PROP, "r");
    if (!fp) return;
    prop_count = 0;
    while (fscanf(fp, "%s %f %s %s %f", props[prop_count].id, &props[prop_count].area, props[prop_count].type, props[prop_count].status, &props[prop_count].fee) != EOF) {
        prop_count++;
    }
    fclose(fp);
}

// 保存业主信息到文件
// 将内存中的业主信息写入到owners.txt文件中
void save_owners() {
    FILE *fp = fopen(FILE_OWNER, "w");
    if (!fp) return;
    int i;
    for (i = 0; i < owner_count; i++) {
        fprintf(fp, "%s %s %s %s %s\n", owners[i].name, owners[i].prop_id, owners[i].cert_no, owners[i].id_card, owners[i].phone);
    }
    fclose(fp);
}

// 从文件加载业主信息
// 从owners.txt文件读取业主信息到内存中
void load_owners() {
    FILE *fp = fopen(FILE_OWNER, "r");
    if (!fp) return;
    owner_count = 0;
    while (fscanf(fp, "%s %s %s %s %s", owners[owner_count].name, owners[owner_count].prop_id, owners[owner_count].cert_no, owners[owner_count].id_card, owners[owner_count].phone) != EOF) {
        owner_count++;
    }
    fclose(fp);
}

// 根据房产编号查找房产在数组中的索引
// 参数：id - 要查找的房产编号
// 返回值：找到则返回索引，否则返回-1
int find_prop_index(char *id) {
	int i;
    for (i = 0; i < prop_count; i++) {
        if (strcmp(props[i].id, id) == 0) return i;
    }
    return -1;
}

// --- 1. 房产管理模块 ---

// 添加房产信息
// 用户可以批量添加房产信息，输入END结束
void add_property() {
    printf("\n--- 添加房产 (输入 END 结束) ---\n");
    while (prop_count < MAX_ITEMS) {
        char id[50];
        printf("房产编号 (如 2-1-501): ");
        scanf("%s", id);
        if (strcmp(id, "END") == 0) break;

        if (find_prop_index(id) != -1) {
            printf("错误：编号重复！\n");
            continue;
        }

        strcpy(props[prop_count].id, id);
        printf("建筑面积: "); scanf("%f", &props[prop_count].area);
        printf("户型 (如 2室1厅): "); scanf("%s", props[prop_count].type);
        printf("状态 (入住/闲置/出租/未售): "); scanf("%s", props[prop_count].status);
        printf("物业费: "); scanf("%f", &props[prop_count].fee);
        
        prop_count++;
    }
    save_props();
    printf("房产信息已保存。\n");
}

// 修改房产状态
// 根据房产编号修改其使用状态
void modify_property() {
    char id[50];
    printf("\n输入要修改的房产编号: ");
    scanf("%s", id);
    int idx = find_prop_index(id);
    if (idx == -1) {
        printf("未找到该房产。\n");
        return;
    }

    printf("当前状态: %s\n", props[idx].status);
    printf("输入新状态 (入住/闲置/出租/未售): ");
    scanf("%s", props[idx].status);
    
    save_props();
    printf("修改成功。\n");
}


void query_property() {
    printf("\n--- 房产查询 (输入 * 跳过某条件) ---\n");
    char q_id[50], q_type[50], q_status[50];
    float q_area;
    char area_str[20];

    printf("房产编号 (*跳过): "); scanf("%s", q_id);
    printf("建筑面积 (*跳过): "); scanf("%s", area_str);
    printf("户型 (*跳过): "); scanf("%s", q_type);
    printf("状态 (*跳过): "); scanf("%s", q_status);

    printf("\n查询结果:\n");
    printf("%-10s %-8s %-10s %-8s %-8s\n", "编号", "面积", "户型", "状态", "物业费");
    int i;
    for (i = 0; i < prop_count; i++) {
        int match = 1;
        if (strcmp(q_id, "*") != 0 && strcmp(props[i].id, q_id) != 0) match = 0;
        if (strcmp(area_str, "*") != 0 && fabs(props[i].area - atof(area_str)) > 0.01) match = 0;
        if (strcmp(q_type, "*") != 0 && strcmp(props[i].type, q_type) != 0) match = 0;
        if (strcmp(q_status, "*") != 0 && strcmp(props[i].status, q_status) != 0) match = 0;

        if (match) {
            printf("%-10s %-8.2f %-10s %-8s %-8.2f\n", 
                props[i].id, props[i].area, props[i].type, props[i].status, props[i].fee);
        }
    }
}

// 显示所有房产信息
// 按表格格式显示系统中所有房产信息
void show_all_props() {
    printf("\n--- 所有房产 ---\n");
    printf("%-10s %-8s %-10s %-8s %-8s\n", "编号", "面积", "户型", "状态", "物业费");
    int i;
    for (i = 0; i < prop_count; i++) {
         printf("%-10s %-8.2f %-10s %-8s %-8.2f\n", 
                props[i].id, props[i].area, props[i].type, props[i].status, props[i].fee);
    }
}

// --- 2. 业主管理模块 ---

// 业主信息管理功能
// 包括添加、修改、删除、查询和显示所有业主信息
void manage_owners() {
    int choice;
    printf("\n1.添加 2.修改 3.删除 4.查询 5.显示所有\n选择: ");
    scanf("%d", &choice);

    if (choice == 1) { // 添加业主信息
        if (owner_count >= MAX_ITEMS) return;
        char pid[50];
        printf("关联房产编号: "); scanf("%s", pid);
        if (find_prop_index(pid) == -1) {
            printf("房产不存在！\n");
            return;
        }
        strcpy(owners[owner_count].prop_id, pid);
        printf("业主姓名: "); scanf("%s", owners[owner_count].name);
        printf("房产证号: "); scanf("%s", owners[owner_count].cert_no);
        printf("身份证号: "); scanf("%s", owners[owner_count].id_card);
        printf("联系电话: "); scanf("%s", owners[owner_count].phone);
        owner_count++;
        save_owners();
        printf("添加成功。\n");
    } 

    else if (choice == 2) { // 修改业主信息
        char name[50];
        printf("输入业主姓名: ");
        if(scanf("%49s", name) != 1) {
            printf("输入错误！\n");
            return;
        }
        
        int found = 0;
        int owner_index = -1;
        int i;
        for (i=0; i<owner_count; i++) {
            if (strcmp(owners[i].name, name) == 0) {
                printf("找到业主: %s, 房号: %s, 电话: %s, 身份证: %s, 房产证号: %s\n", 
                       owners[i].name, owners[i].prop_id, owners[i].phone, 
                       owners[i].id_card, owners[i].cert_no);
                owner_index = i;
                found = 1;
                break;
            }
        }
        
        if(!found) {
            printf("未找到该业主。\n");
            return;
        }
        
        int field_choice;
        printf("\n选择要修改的字段:\n");
        printf("1.电话 2.房产证号 3.身份证号 4.房产编号 5.姓名\n选择: ");
        scanf("%d", &field_choice);
        
        switch(field_choice) {
            case 1: // 修改电话
                printf("输入新电话: ");
                if(scanf("%49s", owners[owner_index].phone) != 1) {
                    printf("输入错误！\n");
                    return;
                }
                printf("电话修改成功！\n");
                break;
            case 2: // 修改房产证号
                printf("输入新房产证号: ");
                if(scanf("%49s", owners[owner_index].cert_no) != 1) {
                    printf("输入错误！\n");
                    return;
                }
                printf("房产证号修改成功！\n");
                break;
            case 3: // 修改身份证号
                printf("输入新身份证号: ");
                if(scanf("%49s", owners[owner_index].id_card) != 1) {
                    printf("输入错误！\n");
                    return;
                }
                printf("身份证号修改成功！\n");
                break;
            case 4: // 修改房产编号
                printf("输入新房产编号: ");
                if(scanf("%49s", owners[owner_index].prop_id) != 1) {
                    printf("输入错误！\n");
                    return;
                }
                printf("房产编号修改成功！\n");
                break;
            case 5: // 修改姓名
                printf("输入新姓名: ");
                if(scanf("%49s", owners[owner_index].name) != 1) {
                    printf("输入错误！\n");
                    return;
                }
                printf("姓名修改成功！\n");
                break;
            default:
                printf("无效选择！\n");
                return;
        }
        
        save_owners();
    }
    else if (choice == 3) { // 删除业主信息
        char name[50];
        printf("输入删除业主姓名: "); scanf("%s", name);
        int found = 0;
        int i;
        for (i=0; i<owner_count; i++) {
            if (strcmp(owners[i].name, name) == 0) {
                // 移动数组元素实现删除
                int j;
                for(j=i; j<owner_count-1; j++) owners[j] = owners[j+1];
                owner_count--;
                found = 1;
                i--; // 回退索引
            }
        }
        if(found) save_owners();
        else printf("未找到。\n");
    }
    else if (choice == 4) { // 查询业主信息（按姓名、身份证或电话）
        char key[50];
        printf("输入姓名或身份证或电话: "); scanf("%s", key);
        int i;
        for(i=0; i<owner_count; i++) {
            if(strstr(owners[i].name, key) || strstr(owners[i].id_card, key) || strstr(owners[i].phone, key)) {
                 printf("%s %s %s\n", owners[i].name, owners[i].prop_id, owners[i].phone);
            }
        }
    }
    else if (choice == 5) { // 显示所有业主信息
    	int i;
        for(i=0; i<owner_count; i++) {
            printf("%s 房号:%s 电话:%s\n", owners[i].name, owners[i].prop_id, owners[i].phone);
        }
    }
}

// --- 3. 收费管理模块 ---

// 获取上个月的止码作为本月起码
// 用于连续记录水电表读数
void get_prev_readings(char *curr_date, char *prop_id, float *w_start, float *e_start) {
    int y, m;
    sscanf(curr_date, "%d.%d", &y, &m);
    if (m == 1) { y--; m = 12; } else { m--; }
    
    char prev_file[50];
    sprintf(prev_file, "%s%d.%02d.txt", FEE_PREFIX, y, m);
    
    FILE *fp = fopen(prev_file, "r");
    *w_start = 0; *e_start = 0; // 默认值
    
    if (fp) {
         // 从上个月的记录文件中读取数据
        FeeRecord rec;
        while (fscanf(fp, "%s %s %f %f %f %f %f %f %f %f", 
               rec.name, rec.prop_id, &rec.w_start, &rec.w_end, 
               &rec.e_start, &rec.e_end, &rec.prop_fee, &rec.w_fee, &rec.e_fee, &rec.total) != EOF) {
            if (strcmp(rec.prop_id, prop_id) == 0) {
                 // 找到匹配的房产ID，将上个月的结束读数作为本月的起始读数
                *w_start = rec.w_end;
                *e_start = rec.e_end;
                break;
            }
        }
        fclose(fp);
    }
}

// 创建月度收费文件
// 根据业主信息和水电表读数生成收费记录
void create_fee_file() {
    char date[20];
    printf("输入年月 (格式 YYYY.MM): ");
    scanf("%s", date);
    
    char filename[50];
    sprintf(filename, "%s%s.txt", FEE_PREFIX, date);
    
    FILE *fp = fopen(filename, "w");
    if (!fp) { printf("创建文件失败。\n"); return; }

    printf("开始录入收费数据...\n");
    int i;
    for (i = 0; i < owner_count; i++) {
        FeeRecord rec;
        strcpy(rec.name, owners[i].name);
        strcpy(rec.prop_id, owners[i].prop_id);
        
        // 查找房产信息获取物业费和状态
        int p_idx = find_prop_index(rec.prop_id);
        if (p_idx == -1) continue; // 数据不一致，跳过
        
        Property p = props[p_idx];
        rec.prop_fee = p.fee;

        // 获取上月止码作为本月起码
        get_prev_readings(date, rec.prop_id, &rec.w_start, &rec.e_start);

        // 判断是否为闲置房屋（闲置房屋不产生水电费）
        int is_idle = (strcmp(p.status, "闲置") == 0);

        printf("\n业主: %s, 房号: %s, 状态: %s\n", rec.name, rec.prop_id, p.status);
        if (rec.w_start == 0 && rec.e_start == 0) {
             printf("请输入上月止码/本月起码 (水 电): ");
             scanf("%f %f", &rec.w_start, &rec.e_start);
        } else {
             printf("自动获取起码: 水=%.1f, 电=%.1f\n", rec.w_start, rec.e_start);
        }
        // 根据房屋状态计算水电费
        if (is_idle) {
            rec.w_end = rec.w_start;
            rec.e_end = rec.e_start;
            rec.w_fee = 0;
            rec.e_fee = 0;
            printf("房屋闲置，无水电费。\n");
        } else {
            printf("请输入本月止码 (水 电): ");
            scanf("%f %f", &rec.w_end, &rec.e_end);
            rec.w_fee = (rec.w_end - rec.w_start) * 3.0;  // 水费单价3元/吨
            rec.e_fee = (rec.e_end - rec.e_start) * 0.6;  // 电费单价0.6元/度
        }

        // 计算总费用，以负数表示欠费
        float total_cost = rec.prop_fee + rec.w_fee + rec.e_fee;
        rec.total = -total_cost; // 负数表示欠费/需缴纳

        fprintf(fp, "%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
                rec.name, rec.prop_id, rec.w_start, rec.w_end, rec.e_start, rec.e_end,
                rec.prop_fee, rec.w_fee, rec.e_fee, rec.total);
    }
    fclose(fp);
    printf("收费文件已生成: %s\n", filename);
}

// 查询收费信息
// 根据业主姓名或房号查询月度收费详情
/*void query_fees() {
    char date[20];
    printf("输入年月 (YYYY.MM): "); scanf("%s", date);
    char filename[50];
    sprintf(filename, "%s%s.txt", FEE_PREFIX, date);

    FILE *fp = fopen(filename, "r");
    if (!fp) { printf("文件不存在。\n"); return; }

    char key[50];
    printf("输入业主姓名或房号: "); scanf("%s", key);
    
    FeeRecord rec;
    int found = 0;
    // 从文件中逐行读取费用记录并解析数据
    while (fscanf(fp, "%s %s %f %f %f %f %f %f %f %f", 
           rec.name, rec.prop_id, &rec.w_start, &rec.w_end, 
           &rec.e_start, &rec.e_end, &rec.prop_fee, &rec.w_fee, &rec.e_fee, &rec.total) != EOF) {
        // 检查记录中的姓名或房号是否与查询关键字匹配
        if (strcmp(rec.name, key) == 0 || strcmp(rec.prop_id, key) == 0) {
            printf("\n%s (%s):\n", rec.name, rec.prop_id);
            printf("  物业费: %.2f\n", rec.prop_fee);
            printf("  水费: %.2f (%.1f -> %.1f)\n", rec.w_fee, rec.w_start, rec.w_end);
            printf("  电费: %.2f (%.1f -> %.1f)\n", rec.e_fee, rec.e_start, rec.e_end);
            printf("  总计欠费: %.2f\n", rec.total); // 显示负数
            found = 1;
        }
    }
    if (!found) printf("未找到记录。\n");
    fclose(fp);
}*/

// 列出欠费业主名单（增强版）
// 支持：1.按单月查询所有欠费 2.按年份查询全年欠费 3.按年月查询单个业主欠费
void list_overdue() {
    printf("\n--- 欠费名单查询 ---\n");
    printf("1. 按单月查询所有欠费业主\n");
    printf("2. 按年份查询全年欠费业主\n");
    printf("3. 按年月查询单个业主欠费\n");
    printf("请选择查询方式: ");
    
    int query_type;
    scanf("%d", &query_type);

    // 通用变量
    char year_str[10], month_str[10], date[20], filename[50];
    int target_year, target_month;
    char owner_key[50]; // 单个业主查询关键字（姓名/房号）
    FILE *fp;
    FeeRecord rec;
    int has_data = 0;

    switch(query_type) {
        case 1: // 1. 按单月查询所有欠费业主（原有功能）
            printf("输入查询月份 (YYYY.MM): ");
            scanf("%s", date);
            sprintf(filename, "%s%s.txt", FEE_PREFIX, date);
            
            fp = fopen(filename, "r");
            if (!fp) { 
                printf("错误：该月份收费文件不存在！\n");
                return;
            }

            printf("\n--- %s 欠费名单 ---\n", date);
            printf("%-12s %-12s %-10s\n", "业主姓名", "房产编号", "欠费金额");
            while (fscanf(fp, "%s %s %f %f %f %f %f %f %f %f", 
                   rec.name, rec.prop_id, &rec.w_start, &rec.w_end, 
                   &rec.e_start, &rec.e_end, &rec.prop_fee, &rec.w_fee, &rec.e_fee, &rec.total) != EOF) {
                if (rec.total < 0) { // 负数表示欠费
                    printf("%-12s %-12s %-10.2f\n", rec.name, rec.prop_id, -rec.total);
                    has_data = 1;
                }
            }
            fclose(fp);
            break;

        case 2: // 2. 按年份查询全年欠费业主
            printf("输入查询年份 (YYYY): ");
            scanf("%s", year_str);
            target_year = atoi(year_str);

            printf("\n--- %s年 欠费名单（按月份汇总） ---\n", year_str);
            printf("%-6s %-12s %-12s %-10s\n", "月份", "业主姓名", "房产编号", "欠费金额");
            
            // 遍历1-12月
            for (int m = 1; m <= 12; m++) {
                sprintf(date, "%d.%02d", target_year, m);
                sprintf(filename, "%s%s.txt", FEE_PREFIX, date);
                
                fp = fopen(filename, "r");
                if (!fp) continue; // 该月无文件则跳过

                while (fscanf(fp, "%s %s %f %f %f %f %f %f %f %f", 
                       rec.name, rec.prop_id, &rec.w_start, &rec.w_end, 
                       &rec.e_start, &rec.e_end, &rec.prop_fee, &rec.w_fee, &rec.e_fee, &rec.total) != EOF) {
                    if (rec.total < 0) {
                        printf("%02d月     %-12s %-12s %-10.2f\n", m, rec.name, rec.prop_id, -rec.total);
                        has_data = 1;
                    }
                }
                fclose(fp);
            }
            break;

        case 3: // 3. 按年月查询单个业主欠费
            printf("输入查询年月 (YYYY.MM): ");
            scanf("%s", date);
            printf("输入业主姓名/房产编号: ");
            scanf("%s", owner_key);

            sprintf(filename, "%s%s.txt", FEE_PREFIX, date);
            fp = fopen(filename, "r");
            if (!fp) { 
                printf("错误：该月份收费文件不存在！\n");
                return;
            }

            printf("\n--- %s 业主【%s】欠费详情 ---\n", date, owner_key);
            printf("%-12s %-12s %-8s %-8s %-8s %-10s\n", 
                   "业主姓名", "房产编号", "物业费", "水费", "电费", "总欠费");
            
            while (fscanf(fp, "%s %s %f %f %f %f %f %f %f %f", 
                   rec.name, rec.prop_id, &rec.w_start, &rec.w_end, 
                   &rec.e_start, &rec.e_end, &rec.prop_fee, &rec.w_fee, &rec.e_fee, &rec.total) != EOF) {
                // 匹配业主姓名或房产编号
                if ((strcmp(rec.name, owner_key) == 0 || strcmp(rec.prop_id, owner_key) == 0) && rec.total < 0) {
                    printf("%-12s %-12s %-8.2f %-8.2f %-8.2f %-10.2f\n", 
                           rec.name, rec.prop_id, rec.prop_fee, rec.w_fee, rec.e_fee, -rec.total);
                    has_data = 1;
                    break; // 找到目标业主后退出循环
                }
            }
            fclose(fp);
            break;

        default:
            printf("无效的查询方式！\n");
            return;
    }

    if (!has_data) {
        printf("无欠费记录。\n");
    }
}

// --- 主菜单 ---

// 程序主函数
// 系统入口点，提供用户交互界面
int main() {
    load_props();      // 启动时加载房产信息
    load_owners();     // 启动时加载业主信息

    int choice;
    do {
        printf("\n========== 小区物业管理系统 ==========\n");
        printf("1. 房产信息管理 (增/改/查/显)\n");
        printf("2. 业主信息管理 (增/改/删/查)\n");
        printf("3. 物业收费管理 (生成/查/欠费)\n");
        printf("0. 退出系统\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n1.创建 2.修改状态 3.查询 4.显示所有\n选择: ");
                int c1; scanf("%d", &c1);
                if (c1==1) add_property();      // 添加房产
                else if (c1==2) modify_property();  // 修改房产状态
                else if (c1==3) query_property();   // 查询房产
                else if (c1==4) show_all_props();   // 显示所有房产
                break;
            case 2:
                manage_owners();  // 业主管理功能
                break;
            case 3:
                printf("\n1.创建月收费 2.查询收费 \n选择: ");
                int c3; scanf("%d", &c3);
                if (c3==1) create_fee_file();  // 创建收费文件
                else if (c3==2) list_overdue();  // 查询收费信息
                
                break;
            case 0:
                printf("退出程序。\n");
                break;
            default:
                printf("无效输入。\n");
        }
    } while (choice != 0);

    return 0;
}


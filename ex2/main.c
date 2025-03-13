#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義員工結構體
typedef struct employee {
    int id;
    char name[50];
    int age;
    double salary;
} employee_t;

// 函數宣告
void emp_info(employee_t emp);
int emp_average_age(employee_t emp[], int n);
void emp_writefile(employee_t emp[], int n);
void emp_readfile(employee_t emp[], int *size);

int main() {
    employee_t emp[3] = {
        {1, "IU", 20, 30000.0},
        {2, "taylor", 26, 36000.0},
        {3, "swift", 31, 90000.0}
    };

    // 計算平均年齡
    int age = emp_average_age(emp, 3);
    printf("Average age: %d\n\n", age);

    // 顯示員工資訊
    for (int i = 0; i < 3; i++) {
        emp_info(emp[i]);
    }

    // 將員工資訊寫入檔案
    emp_writefile(emp, 3);

    // 讀取員工資訊
    employee_t read_emp[10]; // 假設最多讀取10筆資料
    int size = 0;
    emp_readfile(read_emp, &size);

    // 顯示讀取後的資料
    for (int i = 0; i < size; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}

// 顯示單一員工資訊
void emp_info(employee_t emp) {
    printf("Employee ID = %d\n", emp.id);
    printf("Employee Name = %s\n", emp.name);
    printf("Employee Age = %d\n", emp.age);
    printf("Employee Salary = %.2f\n\n", emp.salary);
}

// 計算員工平均年齡
int emp_average_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

// 將員工資料寫入檔案
void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "wb");
    if (fp == NULL) {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }

    fclose(fp);
}

// 從檔案讀取員工資料
void emp_readfile(employee_t emp[], int *size) {
    FILE *fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        printf("Failed to open file for reading!\n");
        return;
    }

    int i = 0;
    while (fread(&emp[i], sizeof(employee_t), 1, fp)) {
        i++;
    }

    *size = i;
    fclose(fp);
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �w�q���u���c��
typedef struct employee {
    int id;
    char name[50];
    int age;
    double salary;
} employee_t;

// ��ƫŧi
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

    // �p�⥭���~��
    int age = emp_average_age(emp, 3);
    printf("Average age: %d\n\n", age);

    // ��ܭ��u��T
    for (int i = 0; i < 3; i++) {
        emp_info(emp[i]);
    }

    // �N���u��T�g�J�ɮ�
    emp_writefile(emp, 3);

    // Ū�����u��T
    employee_t read_emp[10]; // ���]�̦hŪ��10�����
    int size = 0;
    emp_readfile(read_emp, &size);

    // ���Ū���᪺���
    for (int i = 0; i < size; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}

// ��ܳ�@���u��T
void emp_info(employee_t emp) {
    printf("Employee ID = %d\n", emp.id);
    printf("Employee Name = %s\n", emp.name);
    printf("Employee Age = %d\n", emp.age);
    printf("Employee Salary = %.2f\n\n", emp.salary);
}

// �p����u�����~��
int emp_average_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

// �N���u��Ƽg�J�ɮ�
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

// �q�ɮ�Ū�����u���
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



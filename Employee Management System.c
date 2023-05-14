#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100 // Maximum number of employees

// Employee struct definition
typedef struct {
    char name[50];
    int id;
    float salary;
    char job_title[50];
} Employee;

// Function prototypes
void addEmployee(Employee employees[], int* numEmployees);
void displayEmployees(Employee employees[], int numEmployees);
void searchEmployee(Employee employees[], int numEmployees);
void updateEmployee(Employee employees[], int numEmployees);
void deleteEmployee(Employee employees[], int* numEmployees);

int main() {
    Employee employees[MAX_EMPLOYEES]; // Array to hold employees
    int numEmployees = 0; // Number of employees in the array
    int choice; // User's menu choice

    do {
        // Display menu options
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                displayEmployees(employees, numEmployees);
                break;
            case 3:
                searchEmployee(employees, numEmployees);
                break;
            case 4:
                updateEmployee(employees, numEmployees);
                break;
            case 5:
                deleteEmployee(employees, &numEmployees);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to add an employee to the array
void addEmployee(Employee employees[], int* numEmployees) {
    if (*numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    Employee employee;

    // Prompt user for employee data
    printf("Enter employee name: ");
    scanf("%s", employee.name);
    printf("Enter employee ID: ");
    scanf("%d", &employee.id);
    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);
    printf("Enter employee job title: ");
    scanf("%s", employee.job_title);

    // Add employee to array and increment numEmployees
    employees[*numEmployees] = employee;
    (*numEmployees)++;
}

// Function to display all employees in the array
void displayEmployees(Employee employees[], int numEmployees) {
    if (numEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee ID  Employee Name  Salary  Job Title\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%-12d%-15s%-8.2f%-15s\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].job_title);
    }
}

// Function to search all employees in the array
void search_employee() {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].employee_id == id) {
            printf("Employee found:\n");
            print_employee(employees[i]);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found\n", id);
    }
}

void delete_employee() {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].employee_id == id) {
            found = 1;
            for (int j = i; j < num_employees-1; j++) {
                employees[j] = employees[j+1];
            }
            num_employees--;
            printf("Employee with ID %d deleted\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found\n", id);
    }
  }


void update_employee() {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].employee_id == id) {
            printf("Enter updated employee name: ");
            fgets(employees[i].name, 50, stdin);
            printf("Enter updated employee salary: ");
            scanf("%f", &employees[i].salary);
            printf("Enter updated employee job title: ");
            fgets(employees[i].job_title, 50, stdin);
            
            printf("Employee information updated:\n");
            print_employee(employees[i]);
            found = 1;
            break;
        }
   }
}

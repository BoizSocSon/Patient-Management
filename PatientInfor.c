#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
#include <unistd.h>

struct Date {
    int Day;
    int Month;
    int Year;
};

struct Human {
    char name[100];
    char id[50];
    char gender[20];
    struct Date date_Of_Birth;
    char address[1000];
    char mobile_Phone[20];
    char ICD10[100]
    char medical_History[10000];
    struct Date onset_Symptom_Date;
    struct Date date_Of_Diagnosis;
};
    
typedef struct Human PatientInfor;

PatientInfor Patient[1000];

void login_Func();
void general_Menu_Func();
void show_Patient_Menu_Func();
void update_Patient_Menu_Func();

int main(){
    int is_Running = 1;
    while(is_Running) {

    }
}

void general_Menu_Func() {
    printf("\n\tPatients Management System\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t======================\n");
    printf("\t\t[1] Add Patient\n");
    printf("\t\t[2] Show Patient\n");
    printf("\t\t[3] Update Patient\n");
    printf("\t\t[4] Searching Patient\n");
    printf("\t\t[0] Exit the Program.\n");
}

void show_Patient_Menu_Func() {
    printf("\n\tShow Patient Menu\n");
    printf("\t\t======================\n");
    printf("\t\t[1] \n");
    printf("\t\t[2] Show All Patients\n");
    printf("\t\t[3] Show Patient\n");
    printf("\t\t[4] Show Patients Have Same ICD10\n");
    printf("\t\t[0] Exit or Go back the Program.\n");
}


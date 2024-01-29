#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<unistd.h>

struct Date {
    int Day;
    int Month;
    int Year;
};

struct Human {
    char name[100];
    char id[50];
    char email[100];
    char gender[20];
    struct Date date_Of_Birth;
    char address[1000];
    char mobile_Phone[20];
    char ICD10[100];
    char medical_History[10000];
    struct Date onset_Symptom_Date;
    struct Date date_Of_Diagnosis;
};
    
typedef struct Human PatientInfor;

PatientInfor Patient[1000];
int total_Patients = 0;

int login_Func();

// Phần hàm menu ----------------------------------------------------------------------------
void general_Menu_Func();
void show_Patient_Menu_Func();
void update_Patient_Menu_Func();

// Phần hàm chức năng phụ--------------------------------------------------------------------
int check_String();
int is_Already_Exists();
void add_Patient();
void searching_Patient();
void show_Patient();
void exit_Program();


// Phần hàm chức năng chính------------------------------------------------------------------
void add_Patient_List_Func();
void Show_Patient_List_Func();
void update_Patient_Infor_Func();
void searching_Patient_Func();
void exit_Or_Back_Program_Func();

// Phần hàm thực hiện chức năng--------------------------------------------------------------
int main(){
    if(login_Func() == 0) {
        //exit_Or_Back_Program_Func();
        exit(0);
    } else {
        int is_Running = 1;
        while(is_Running) {
            int Option;
            general_Menu_Func();
            scanf("%d", &Option);
            switch (Option)
            {
            case 1:
                system("cls");
                exit_Or_Back_Program_Func();
                break;
            case 2:
                system("cls");
                exit_Or_Back_Program_Func();
                break;
            case 3:
                system("cls");
                exit_Or_Back_Program_Func();
                break;
            case 4:
                system("cls");
                exit_Or_Back_Program_Func();
                break;
            default:
                break;
            }
        }
    }
}

// Hàm login---------------------------------------------------------------------------------
int login_Func(){
    char lg_Name[100];
    char lg_PassWord[100];
    int is_Correct_lgName = 0;
    int is_Correct_lgPass = 0;
    int cnt = 0;
    while(is_Correct_lgName == 0 || is_Correct_lgPass == 0) {
        if(cnt >= 1) {
            printf("\nPlease Login Again\n");
        }
        // Login Name
        printf("Enter your login Name: ");      
        fgets(lg_Name, 100, stdin);     
        lg_Name[strlen(lg_Name) - 1] ='\0';
        //Login PassWord
        printf("Enter your PassWord: ");    
        fgets(lg_PassWord, 100, stdin); 
        lg_PassWord[strlen(lg_PassWord) - 1] ='\0';

        if(check_String(lg_Name) == 1){
            is_Correct_lgName = 1;
        }
        if(check_String(lg_PassWord) == 1) {
            is_Correct_lgPass = 1;
        }
        if(is_Correct_lgName == 0 || is_Correct_lgPass == 0) {
            cnt++;
        }
        if(cnt == 6){
            break;
        }
    }
    if(cnt == 6) {
        return 0;
    }
    return 1;
}

// Hàm Menu----------------------------------------------------------------------------------
void general_Menu_Func() {
    printf("\n\t\tPatients Management System\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t======================\n");
    printf("\t\t[1] Add Patient List\n");
    printf("\t\t[2] Show Patient List\n");
    printf("\t\t[3] Update Patient Infor\n");
    printf("\t\t[4] Searching Patient\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t============================\n");
    printf("\t\tEnter your choice");
}

void show_Patient_Menu_Func() {
    printf("\n\t\tShow Patient Menu\n");
    printf("\t\t======================\n");
    printf("\t\t[1] Show All Patients\n");
    printf("\t\t[2] Show Patient by Name\n");
    printf("\t\t[3] Show Patient by ID\n");
    printf("\t\t[4] Show Patients Have Same ICD10\n");
    printf("\t\t[0] Exit or Go back the Program.\n");
}

void update_Patient_Menu_Func() {
    printf("\n\t\tUpdate Patient Menu\n");
    printf("\t\tChoose type of infor to update\n");
    printf("\t\t======================\n");
    printf("\t\t[1] Update Name\n");
    printf("\t\t[2] Update ID\n");
    printf("\t\t[3] Update Gender\n");
    printf("\t\t[4] Update Date Of Birth\n");
    printf("\t\t[5] Update Address\n");
    printf("\t\t[6] Update Mobile Phone\n");
    printf("\t\t[7] Update ICD10\n");
    printf("\t\t[8] Update Medical History\n");
    printf("\t\t[9] Update Onset Symptom Date\n");
    printf("\t\t[10] Update Date Of Diagnosis\n");
    printf("\t\t[0] Exit or Go back the Program.\n");
}

// Phần hàm chức năng phụ--------------------------------------------------------------------

int check_String(char str_Keyword[]){
    int length = strlen(str_Keyword);
    for(int i = 0; i < length; i++) {
        if(isalpha(str_Keyword[i]) == 0 && isdigit(str_Keyword[i]) == 0){
            return 0;
        }
    }
    return 1;
}

int is_Already_Exists(char checking_String[100], char patient_ID[50]) {
    int is_Exists = 0;
    for(int i = 0; i < total_Patients; i++) {
        if(strcmp(patient_ID, Patient[i].id) == 0) {
            if(strcmp(checking_String, Patient[i].id)) { // ID check
                is_Exists++;
            } else if (strcmp(checking_String, Patient[i].mobile_Phone)) { // Mobile check
                is_Exists++;
            } else if (strcmp(checking_String, Patient[i].email)) { // email check
                is_Exists++;
            }
            break;
        }
    }
    return is_Exists;
}

void add_Patient(PatientInfor Patient) {
    while(){

    }
    printf("Write patient's Name: ");
    printf("Write patient's ID: ");
    printf("Write patient's Email: ");
    printf("Write patient's Gender: ");
    printf("Write patient's DateOfBirth: ");
    printf("Write patient's Address: "); 
    printf("Write patient's MobilePhone: ");
    printf("Write patient's ICD10 (first 4 character): ");
    printf("Write patient's Medical History: ");
    printf("Write patient's Onset Symptom Date: ");
    printf("Write patient's Date Of Diagnosis: ");
}

void exit_Program() {
    system("cls");
    int i;
    char ThankYou[100]     = " ========= Thank You =========\n";
    char SeeYouSoon[100]   = " ========= See You Soon ======\n";
    for(i=0; i<strlen(ThankYou); i++) {
        printf("%c",ThankYou[i]);
        Sleep(40);
    }
    for(i=0; i<strlen(SeeYouSoon); i++) {
        printf("%c",SeeYouSoon[i]);
        Sleep(40);
    }
    exit(0);
}

// Phần hàm chức năng chính------------------------------------------------------------------
void add_Patient_List_Func() {
    int NOP;
    printf("Enter the number of patients: ");
    scanf("%d", NOP);
    total_Patients = NOP;
    for(int i = 0; i < total_Patients; i++){
        add_Patient(Patient[i]);
    }
}

void exit_Or_Back_Program_Func() {
    getchar();
    char Option;
    printf(" Go back(b)? or Exit(0)?: ");
    scanf("%c",&Option);
    if(Option == '0') {
        exit_Program();
    }
    else {
        system("cls");
    }
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

int main () {
    int is_Running = 1;
    while(is_Running) {
        
    }
    return 0;
}

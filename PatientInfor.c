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
int total_ICD10 = 23;

int login_Func();

// Phần hàm menu ----------------------------------------------------------------------------
void general_Menu_Func();
void show_Patient_Menu_Func();
void update_Patient_Menu_Func();

// Phần hàm chức năng phụ--------------------------------------------------------------------
int check_Digit_String();
int check_Alpha_String();
int check_String();
int check_Phone_Number();
int check_Correct_Mail();
int count_Number_Letter();
int is_Already_Exists();
void data_Seed_ICD10();
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
                // system("cls");
                add_Patient_List_Func();
                exit_Or_Back_Program_Func();
                break;
            case 2:
                // system("cls");
                exit_Or_Back_Program_Func();
                break;
            case 3:
                // system("cls");
                exit_Or_Back_Program_Func();
                break;
            case 4:
                // system("cls");
                exit_Or_Back_Program_Func();
                break;
            default:
                exit_Program();
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
    while(is_Correct_lgName == 0 || is_Correct_lgPass == 0) 
    {
        if(cnt >= 1) 
        {
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

        if(check_String(lg_Name) == 1)
        {
            is_Correct_lgName = 1;
        }
        if(check_String(lg_PassWord) == 1) 
        {
            is_Correct_lgPass = 1;
        }
        if(is_Correct_lgName == 0 || is_Correct_lgPass == 0) 
        {
            cnt++;
        }
        if(cnt == 6)
        {
            break;
        }
    }
    if(cnt == 6) {
        return 0;
    }
    return 1;
}

// Hàm Menu----------------------------------------------------------------------------------
void general_Menu_Func() 
{
    printf("\n\t\tPatients Management System\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t===========================\n");
    printf("\t\t[1] Add Patient List.\n");
    printf("\t\t[2] Show Patient List.\n");
    printf("\t\t[3] Update Patient Infor.\n");
    printf("\t\t[4] Searching Patient.\n");
    printf("\t\t[5] Save Patient's Information.")
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t===========================\n");
    printf("\t\tEnter your choice: ");
}

void show_Patient_Menu_Func() 
{
    printf("\n\t\tShow Patient Menu\n");
    printf("\t\t======================\n");
    printf("\t\t[1] Show All Patients\n");
    printf("\t\t[2] Show Patient by Name\n");
    printf("\t\t[3] Show Patient by ID\n");
    printf("\t\t[4] Show Patients Have Same ICD10\n");
    printf("\t\t[0] Exit or Go back the Program.\n");
}

void update_Patient_Menu_Func() 
{
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

int check_Digit_String(char check_digit_string[])
{
    int length = strlen(check_digit_string);
    for(int i = 0; i < length; i++)
    {
        if(isdigit(check_digit_string[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int check_Alpha_String(char check_alpha_string[]) 
{
    int correct = 1;
    int length = strlen(check_alpha_string);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(check_alpha_string[i]) == 0)
        {
            correct = 0;
        }
        if(check_alpha_string[i] == ' ')
        {
            correct = 1;
        }
    }
    return correct;
}

int check_String(char str_Keyword[])
{
    int correct = 1;
    int length = strlen(str_Keyword);
    for(int i = 0; i < length; i++) 
    {
        if(isalpha(str_Keyword[i]) == 0 && isdigit(str_Keyword[i]) == 0)
        {
            correct = 0;
        }
    }
    return correct;
}

int check_Phone_Number(char phone_num[])
{
    if(check_Digit_String(phone_num) == 0)
    {
        return 0;
    }
    return 1;
}

int check_Correct_Mail(char mail[])
{
    char checked_String[100];
    int correct = 0;
    int length = strlen(mail);
    int pos = 0;
    for(int i = 0; i < length; i++)
    {
        if((mail[i] == '@' ) || mail[i] == '.') 
        {
            correct++;
            if(mail[i] == '@')
            {
                pos = i;
            }
        }
    }
    strncpy(checked_String, mail, pos);
    checked_String[pos] = '\0';
    if(check_String(checked_String) == 0)
    {
        correct = 0;
    }
    return correct;
}

int count_Number_Letter(int check) {
    int cnt = 0;
    while(check) {
        check/=10;
        cnt++;
    }
    return cnt;
}

int is_Already_Exists(char checking_String[100], char patient_ID[50]) 
{
    int is_Exists = 0;
    for(int i = 0; i < total_Patients; i++) 
    {
        if(strcmp(patient_ID, Patient[i].id) == 0) 
        {
            if(strcmp(checking_String, Patient[i].id))  // ID check
            { 
                is_Exists++;
            } 
            else if (strcmp(checking_String, Patient[i].mobile_Phone))  // Mobile check
            { 
                is_Exists++;
            } 
            else if (strcmp(checking_String, Patient[i].email))  // email check
            { 
                is_Exists++;
            }
            break;
        }
    }
    return is_Exists;
}

char **data_Seed_ICD10()
{
    char **ICD10_Data = (char**)malloc(1000*sizeof(char*));
    for(int i = 0; i < 1000; i++)
    {
        *(ptr+i) = (char*)malloc(1000*sizeof(char));
    }
    *(ptr+0) = "C40.00: K xuong vai";
    *(ptr+1) = "C40.01: K dau tren xuong canh tay";
    *(ptr+2) = "C40.02: K dau duoi xuong canh tay";
    *(ptr+3) = "C40.03: K dau duoi xuong quay";
    *(ptr+4) = "C40.04: K dau duoi xuong tru";
    *(ptr+5) = "C40.05: K xuong ban, xuong ngon tay";
    *(ptr+6) = "C40.06: K xuong suon";
    *(ptr+7) = "C40.20: K dau tren xuong dui";
    *(ptr+8) = "C40.21: K dau duoi xuong dui";
    *(ptr+9) = "C40.22: K dau tren xuong chay";
    *(ptr+10) = "C40.23: K dau duoi xuong chay";
    *(ptr+11) = "C40.24: K xuong mac";
    *(ptr+12) = "C40.3: K xuong chau ngan chi duoi";
    *(ptr+13) = "C41.4: K xuong chau";
    *(ptr+14) = "C49.1: K phan mem chi tren, vai";
    *(ptr+15) = "C49.2: K phan mem chi duoi";
    *(ptr+16) = "D16.0: U lanh xuong vai va xuong dai chi tren";
    *(ptr+17) = "D16.1: U lanh xuong ngan chi tren";
    *(ptr+18) = "D16.2: U lanh xuong dai chi duoi";
    *(ptr+19) = "D16.7: U lanh xuong suon, xuong don";
    *(ptr+20) = "D16.8: U lanh xuong chau";
    *(ptr+21) = "D21.1: U phan mem chi tren";
    *(ptr+22) = "D16.3: U lanh xuong ngan chi duoi";
    return ICD10_Data
}

char **test() {
    char **ptr = (char**)malloc(23*sizeof(char*));
    for(int i = 0; i < 23; i++){
        ptr[i] = (char*)malloc(1000*sizeof(char));
    }
    *(ptr+0) = "cd1";
    *(ptr+1) = "cd2";
    *(ptr+2) = "cd3";
    *(ptr+3) = "cd4";
    *(ptr+4) = "cd5";
    *(ptr+5) = "cd6";
    *(ptr+6) = "cd7";
    *(ptr+7) = "cd8";
    *(ptr+8) = "cd9";
    *(ptr+9) = "cd10";
    *(ptr+10) = "cd11";
    *(ptr+11) = "cd12";
    *(ptr+12) = "cd13";
    *(ptr+13) = "cd14";
    return ptr;
}

// PatientInfor Patient
void add_Patient(int order) 
{
    getchar();
    char Name[100];
    char Id[50];
    char Email[100];
    char Gender[20];
    struct Date DOB;
    char Address[1000];
    char MP[20];
    char ICD10[100];
    char MH[10000];
    struct Date OSD;
    struct Date DOD;


    // Nhập vào tên bệnh nhân 
    int is_Correct_Name = 1;
    while(is_Correct_Name)
    {
        printf("Write patient's Name: ");
        fgets(Name, 100, stdin);
        Name[strlen(Name) - 1] = '\0';
        if(strlen(Name) > 20) 
        {
            printf(" Error: Name can not be more than 20 characters.\n\n");
            is_Correct_Name = 1;
        } 
        else if(strlen(Name) <= 0) 
        {
            printf(" Error: Name can not be empty.\n\n");
            is_Correct_Name = 1;
        } 
        else if(check_Alpha_String(Name) == 0) 
        {
            printf(" Error: Name is inValid.\n\n");
            is_Correct_Name = 1;
        }
        else 
        {
            is_Correct_Name = 0;
        }
    }

    // Nhập vào ID bệnh nhân 
    int is_Correct_ID = 1;
    while(is_Correct_ID)
    {
        printf("Write patient's ID: ");
        fgets(Id, 50, stdin);
        Id[strlen(Id) - 1] = '\0';
        if(is_Already_Exists(Id, Id) > 0)
        {
            printf(" Error: This ID is already exists.\n\n");
            is_Correct_ID = 1;
        }
        else if(strlen(Id) > 10)
        {
            printf(" Error: ID can not be more than 10 characters.\n\n");
            is_Correct_ID = 1;
        }
        else if(strlen(Id) <= 0)
        {
            printf(" Error: ID can not be empty.\n\n");
            is_Correct_ID = 1;
        }
        else if(check_String(Id) == 0)
        {
            printf(" Error: ID is inValid.\n\n");
            is_Correct_ID = 1;
        }
        else
        {
            is_Correct_ID = 0;
        }
    }

    // Nhập vào email bệnh nhân 
    int is_Correct_Email = 1;
    while(is_Correct_Email) {
        printf("Write patient's Email: ");
        fgets(Email, 100, stdin);
        Email[strlen(Email) - 1] = '\0';
        if(is_Already_Exists(Email, Id) > 0) 
        {
            printf(" This Email is Already Exists.\n");
            is_Correct_Email = 1;
        } 
        else if(strlen(Email) > 30) 
        {
            printf(" Error: Email can not be more than 30 characters.\n\n");
            is_Correct_Email = 1;
        }
        else if(strlen(Email) <= 0)
        {
            printf(" Error: Email can not be empty.\n\n");
            is_Correct_Email = 1;
        }
        else if(check_Correct_Mail(Email) == 0) 
        {
            printf(" Error: Incorrect syntax for Email.\n\n");
            is_Correct_Email = 1;
        }
        else
        {
            is_Correct_Email = 0;
        }
    }

    // Nhập vào giới tính bệnh nhân 
    int is_Correct_Gender = 1;
    while(is_Correct_Gender) 
    {
        int Option;
        printf("Select patient's Gender: \n");
        printf("[1] Male\n");
        printf("[2] Female\n");
        printf("[3] Other\n");
        scanf("%d", &Option);
        switch(Option)
        {
        case 1:
            strcpy(Gender, "Male");
            printf("Gender: male\n");
            is_Correct_Gender = 0;
            break;
        case 2:
            strcpy(Gender, "Female");
            printf("Gender: Female\n");
            is_Correct_Gender = 0;
            break;
        case 3:
            strcpy(Gender, "Other");
            printf("Gender: Other\n");
            is_Correct_Gender = 0;
            break;
        default:    
            printf(" Error: Gender is inValid.\n\n");
            is_Correct_Gender = 1;
            break;
        }
    }

    // Nhập vào ngày sinh bệnh nhân 
    int is_Correct_DOB = 1;
    while(is_Correct_DOB) 
    {
        printf("Write patient's DateOfBirth: ");
        scanf("%d %d %d", &DOB.Day, &DOB.Month, &DOB.Year);
        int cnt_DOB_Day = count_Number_Letter(DOB.Day);
        int cnt_DOB_Month = count_Number_Letter(DOB.Month);
        int cnt_DOB_Year = count_Number_Letter(DOB.Year);
        if(cnt_DOB_Day > 2) 
        {
            printf(" Error: Day is inValid.\n");
            is_Correct_DOB = 1;
        }
        if(cnt_DOB_Month > 2)
        {
            printf(" Error: Month is inValid.\n");
            is_Correct_DOB = 1;
        }
        if(cnt_DOB_Year > 4) 
        {
            printf(" Error: Year is inValid.\n");
            is_Correct_DOB = 1;
        }
        else
        {
            is_Correct_DOB = 0;   
        }
    }

    // Nhập vào địa chỉ bệnh nhân 
    int is_Correct_Address = 1;
    while(is_Correct_Address) {
        printf("Write patient's Address: "); 
        getchar();
        fgets(Address, 1000, stdin);
        Address[strlen(Address) - 1] = '\0';
        is_Correct_Address = 0;
    }

    // Nhập vào số điện thoại bệnh nhân 
    int is_Correct_Phone = 1;
    while(is_Correct_Phone) {
        printf("Write patient's MobilePhone: ");
        fgets(MP, 20, stdin);
        MP[strlen(MP) - 1] = '\0';
        if(is_Already_Exists(MP, Id) > 0)
        {
            printf(" This Phone Number is Already Exists\n");
            is_Correct_Phone = 1;
        }
        else if(strlen(MP) > 20)
        {
            printf(" Error: Phone can not be more than 20 characters.\n\n");
            is_Correct_Phone = 1;
        }
        else if(strlen(MP) <= 0)
        {
            printf(" Error: Phone can not be empty.\n\n");
            is_Correct_Phone = 1;
        }
        else if(check_Phone_Number(MP) == 0) 
        {
            printf(" Error: Phone number contains alpha word.\n\n");
            is_Correct_Phone = 1;
        }
        else
        {
            is_Correct_Phone = 0;
        }
    }

    // Nhập vào ICD10
    int is_Correct_ICD10 = 1;
    while(is_Correct_ICD10) {
        printf("Write patient's ICD10 (first 4 character): ");
        fgets(ICD10, 100, stdin);
        ICD10[strlen(ICD10) - 1] = '\0';
        int length = strlen(ICD10);
        if(ICD10 > 6)
        {   
            printf(" Error: Invalid ICD10");
        }
    }

    // Nhập vào tiểu sử bệnh lý của bệnh nhân 
    int is_Correct_MH = 1;
    while(is_Correct_MH) {
        printf("Write patient's Medical History: ");
        fgets(MH, 10000, stdin);
        MH[strlen(MH) - 1] = '\0';
        is_Correct_MH = 0;
    }

    // Nhập vào ngày phát hiện trệu chứng của bệnh 
    int is_Correct_OSD = 1;
    while(is_Correct_OSD) {
        printf("Write patient's Onset Symptom Date: ");
        scanf("%d %d %d", &OSD.Day, &OSD.Month, &OSD.Year);
        int cnt_OSD_Day = count_Number_Letter(OSD.Day);
        int cnt_OSD_Month = count_Number_Letter(OSD.Month);
        int cnt_OSD_Year = count_Number_Letter(OSD.Year);
        if(cnt_OSD_Day > 2) 
        {
            printf(" Error: Day is inValid.\n");
            is_Correct_OSD = 1;
        }
        if(cnt_OSD_Month > 2)
        {
            printf(" Error: Month is inValid.\n");
            is_Correct_OSD = 1;
        }
        if(cnt_OSD_Year > 4) 
        {
            printf(" Error: Year is inValid.\n");
            is_Correct_OSD = 1;
        }
        else
        {
            is_Correct_OSD = 0;   
        }
    }

    // Nhập vào ngày chuẩn đoán bệnh 
    int is_Correct_DOD = 1;
    while(is_Correct_DOD) {
        printf("Write patient's Date Of Diagnosis: ");
        scanf("%d %d %d", &DOD.Day, &DOD.Month, &DOD.Year);
        int cnt_DOD_Day = count_Number_Letter(DOD.Day);
        int cnt_DOD_Month = count_Number_Letter(DOD.Month);
        int cnt_DOD_Year = count_Number_Letter(DOD.Year);
        if(cnt_DOD_Day > 2) 
        {
            printf(" Error: Day is inValid.\n");
            is_Correct_DOD = 1;
        }
        if(cnt_DOD_Month > 2)
        {
            printf(" Error: Month is inValid.\n");
            is_Correct_DOD = 1;
        }
        if(cnt_DOD_Year > 4) 
        {
            printf(" Error: Year is inValid.\n");
            is_Correct_DOD = 1;
        }
        else
        {
            is_Correct_DOD = 0;   
        }
    }    

    strcpy(Patient[order].name, Name);
    strcpy(Patient[order].id, Id);
    strcpy(Patient[order].email, Email);
    strcpy(Patient[order].gender, Gender);
    strcpy(Patient[order].address, Address);
    strcpy(Patient[order].mobile_Phone, MP);
    strcpy(Patient[order].ICD10, ICD10);
    strcpy(Patient[order].medical_History, MH);

    Patient[order].date_Of_Birth.Day = DOB.Day;
    Patient[order].date_Of_Birth.Month = DOB.Month;
    Patient[order].date_Of_Birth.Year = DOB.Year;

    Patient[order].onset_Symptom_Date.Day = OSD.Day;
    Patient[order].onset_Symptom_Date.Month = OSD.Month;
    Patient[order].onset_Symptom_Date.Year = OSD.Year;

    Patient[order].date_Of_Diagnosis.Day = DOD.Day;
    Patient[order].date_Of_Diagnosis.Month = DOD.Month;
    Patient[order].date_Of_Diagnosis.Year = DOD.Year;
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
    scanf("%d", &NOP);
    total_Patients = NOP;
    for(int i = 0; i < total_Patients; i++){
        printf("\n\n");
        add_Patient(i);
    }
}

void exit_Or_Back_Program_Func() {
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
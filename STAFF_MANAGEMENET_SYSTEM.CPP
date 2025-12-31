#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
// ================== STRUCTS ==================
struct staff {
    int id;
    string name;
    string department;
    string designation;
    float salary;
    string type;
    int experience;
    string joindate;
    string contact;
};
struct leave {
    int staffid;
    string name;
    string leavetype;
    string fromdate;
    string todate;
    string status;
    string reason;
};
struct complaint {
    int staffid;
    string name;
    string complainttype;
    string description;
    string status;
    string date;
};
struct bonus {
    int staffid;
    string name;
    float bonusamount;
    string date;
    string reason;
};
struct attendance {
    int staffid;
    string date;
    bool present;
};
// ==================GLOBAL VARIABLES==================
staff stafflist[100];
leave leavelist[100];
complaint complaintlist[50];
bonus bonuslist[50];
attendance attendancelist[200];
int staffcount = 0;
int leavecount = 0;
int complaintcount = 0;
int bonuscount = 0;
int attendancecount = 0;
// ==================UTILITY FUNCTIONS==================
void clearscreen() {
    system("cls");
}
void pressenter() {
	cout<<endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.get();
}
void displayheader(string title) {
    cout<<endl;
    cout<<setfill('=')<<setw(60)<<""<<endl;
    cout<<setfill(' ')<<setw(30)<<title<<endl;
    cout<<setfill('=')<<setw(60)<<""<<endl;
    cout<<endl;
}
// 1. ADD STAFF FUNCTION
void addstaff() {
    clearscreen();
    displayheader("ADD NEW STAFF MEMBER");
    if(staffcount >= 100) {
        cout << "ERROR: DATABASE IS FULL! MAXIMUM 100 STAFF MEMBERS."<<endl;
        pressenter();
        return;
    }
    staff newstaff;
    cout << "ENTER STAFF ID: ";
    cin >> newstaff.id;
    // CHECK IF ID EXISTS
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == newstaff.id) {
            cout << "ERROR: STAFF ID ALREADY EXISTS!"<<endl;
            pressenter();
            return;
        }
    }
    cin.ignore();
    cout << "ENTER FULL NAME: ";
    getline(cin, newstaff.name);
    cout << "ENTER DEPARTMENT: ";
    getline(cin, newstaff.department);
    cout << "ENTER DESIGNATION: ";
    getline(cin, newstaff.designation);
    cout << "ENTER SALARY: ";
    cin >> newstaff.salary;
    cin.ignore();
    cout << "ENTER CONTACT NUMBER: ";
    getline(cin, newstaff.contact);
    cout << "ENTER EXPERIENCE (YEARS): ";
    cin >> newstaff.experience;
    cin.ignore();
    cout << "ENTER JOIN DATE (DD-MM-YYYY): ";
    getline(cin, newstaff.joindate);
    cout << "SELECT STAFF TYPE:\n";
    cout << "1. PERMANENT\n";
    cout << "2. CONTRACT\n";
    cout << "3. TEMPORARY\n";
    cout << "ENTER CHOICE (1-3): ";
    int typechoice;
    cin >> typechoice;
    if(typechoice == 1) 
	{
		newstaff.type = "PERMANENT";
	}
    else if(typechoice == 2) 
    {
    	newstaff.type = "CONTRACT";
	}
    else if(typechoice == 3) 
	{
		newstaff.type = "TEMPORARY";
	}
    else 
    {
    	newstaff.type = "UNKNOWN";
	}
    stafflist[staffcount] = newstaff;
    staffcount++;
    cout << "\nSUCCESS: STAFF MEMBER ADDED SUCCESSFULLY!\n";
    cout << "TOTAL STAFF: " << staffcount << "/100 \n";
    pressenter();
}
// 2. VIEW ALL STAFF FUNCTION
void viewallstaff() {
    clearscreen();
    displayheader("ALL STAFF RECORDS");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "TOTAL STAFF MEMBERS: " << staffcount << "\n";
    cout << setfill('=') << setw(148) << "" << endl;
    cout << left << setw(8) << "ID" 
         << setw(20) << "NAME" 
         << setw(20) << "DEPARTMENT" 
         << setw(20) << "DESIGNATION" 
         << setw(20) << "SALARY" 
         << setw(20) << "TYPE" 
         << setw(40) << "EXPERIENCE" << endl;
    cout << setfill('=') << setw(148) << "" << endl;
    for(int i = 0; i < staffcount; i++) {
        cout << left << setw(8) << stafflist[i].id 
             << setw(20) << stafflist[i].name 
             << setw(20) << stafflist[i].department 
             << setw(20) << stafflist[i].designation 
             << setw(20) << stafflist[i].salary 
             << setw(20) << stafflist[i].type 
             << setw(40) << stafflist[i].experience << endl;
    }
    pressenter();
}
// 3. SEARCH STAFF FUNCTION
void searchstaff() {
    clearscreen();
    displayheader("SEARCH STAFF MEMBER");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "SEARCH BY:\n";
    cout << "1. STAFF ID\n";
    cout << "2. NAME\n";
    cout << "3. DEPARTMENT\n";
    cout << "ENTER CHOICE (1-3): ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        int searchid;
        cout << "ENTER STAFF ID: ";
        cin >> searchid;    
        bool found = false;
        for(int i = 0; i < staffcount; i++) {
            if(stafflist[i].id == searchid) {
                cout << "\nSTAFF FOUND!\n";
                cout << setfill('-') << setw(40) << "" << endl;
                cout << "ID: " << stafflist[i].id << endl;
                cout << "NAME: " << stafflist[i].name << endl;
                cout << "DEPARTMENT: " << stafflist[i].department << endl;
                cout << "DESIGNATION: " << stafflist[i].designation << endl;
                cout << "SALARY: " << stafflist[i].salary << endl;
                cout << "TYPE: " << stafflist[i].type << endl;
                cout << "EXPERIENCE: " << stafflist[i].experience << " YEARS" << endl;
                cout << "JOIN DATE: " << stafflist[i].joindate << endl;
                cout << "CONTACT: " << stafflist[i].contact << endl;
                found = true;
                break;
            }
        }  
        if(!found) {
            cout << "ERROR: STAFF WITH ID " << searchid << " NOT FOUND!\n";
        }
    }
    else if(choice == 2) {
        cin.ignore();
        string searchname;
        cout << "ENTER NAME TO SEARCH: ";
        getline(cin, searchname);  
        bool found = false;
        for(int i = 0; i < staffcount; i++) {
            string name = stafflist[i].name;
            bool match = false;
            if(name.length() >= searchname.length()) {
                match = true;
                for(int j = 0; j < searchname.length(); j++) {
                    if(toupper(name[j]) != toupper(searchname[j])) {
                        match = false;
                        break;
                    }
                }
            }
            if(match) {
                if(!found) {
                    cout << "\nSEARCH RESULTS:\n";
                    cout << setfill('-') << setw(40) << "" << endl;
                }
                cout << "ID: " << stafflist[i].id << " | NAME: " << stafflist[i].name 
                     << " | DEPARTMENT: " << stafflist[i].department << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "ERROR: NO STAFF FOUND WITH THAT NAME!\n";
        }
    }
    else if(choice == 3) {
        cin.ignore();
        string searchdept;
        cout << "ENTER DEPARTMENT: ";
        getline(cin, searchdept);
        bool found = false;
        for(int i = 0; i < staffcount; i++) {
            if(stafflist[i].department == searchdept) {
                if(!found) {
                    cout << "\nSTAFF IN " << searchdept << " DEPARTMENT:\n";
                    cout << setfill('-') << setw(60) << "" << endl;
                    found = true;
                }
                cout << "ID: " << stafflist[i].id << " | NAME: " << stafflist[i].name 
                     << " | DESIGNATION: " << stafflist[i].designation 
                     << " | SALARY: " << stafflist[i].salary << endl;
            }
        }
        if(!found) {
            cout << "ERROR: NO STAFF IN " << searchdept << " DEPARTMENT!\n";
        }
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 4. UPDATE STAFF FUNCTION
void updatestaff() {
    clearscreen();
    displayheader("UPDATE STAFF INFORMATION");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    int staffid;
    cout << "ENTER STAFF ID TO UPDATE: ";
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF WITH ID " << staffid << " NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nCURRENT INFORMATION:\n";
    cout << "NAME: " << stafflist[index].name << endl;
    cout << "DEPARTMENT: " << stafflist[index].department << endl;
    cout << "DESIGNATION: " << stafflist[index].designation << endl;
    cout << "SALARY: " << stafflist[index].salary << endl;
    cout << "CONTACT: " << stafflist[index].contact << endl;
    cout << "\nENTER NEW INFORMATION:\n";
    cin.ignore();
    cout << "NEW NAME: ";
    getline(cin, stafflist[index].name);
    cout << "NEW DEPARTMENT: ";
    getline(cin, stafflist[index].department);
    cout << "NEW DESIGNATION: ";
    getline(cin, stafflist[index].designation);
    cout << "NEW SALARY: ";
    cin >> stafflist[index].salary;
    cin.ignore();
    cout << "NEW CONTACT: ";
    getline(cin, stafflist[index].contact);
    cout << "\nSUCCESS: STAFF INFORMATION UPDATED!\n";
    pressenter();
}
// 5. DELETE STAFF FUNCTION
void deletestaff() {
    clearscreen();
    displayheader("DELETE STAFF MEMBER");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    int staffid;
    cout << "ENTER STAFF ID TO DELETE: ";
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF WITH ID " << staffid << " NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nSTAFF TO BE DELETED:\n";
    cout << "ID: " << stafflist[index].id << endl;
    cout << "NAME: " << stafflist[index].name << endl;
    cout << "DEPARTMENT: " << stafflist[index].department << endl;
    char confirm;
    cout << "\nARE YOU SURE? (Y/N): ";
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y') {
        for(int i = index; i < staffcount - 1; i++) {
            stafflist[i] = stafflist[i + 1];
        }
        staffcount--;
        cout << "\nSUCCESS: STAFF DELETED!\n";
        cout << "TOTAL STAFF: " << staffcount << "/100\n";
    }
    else {
        cout << "\nDELETION CANCELLED!\n";
    }
    pressenter();
}
// 6. VIEW LEAVE APPLICATION FUNCTION
void viewleaveapplication() {
    clearscreen();
    displayheader("LEAVE APPLICATIONS");
    if(leavecount == 0) {
        cout << "NO LEAVE APPLICATIONS FOUND!\n";
        pressenter();
        return;
    }
    cout << "1. VIEW PENDING LEAVES\n";
    cout << "2. VIEW APPROVED LEAVES\n";
    cout << "3. VIEW ALL LEAVES\n";
    cout << "ENTER CHOICE (1-3): ";
    int choice;
    cin >> choice;
    clearscreen();
    if(choice == 1) {
        displayheader("PENDING LEAVE APPLICATIONS");
        bool found = false;
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(15) << "LEAVE TYPE" 
             << setw(12) << "FROM DATE" 
             << setw(12) << "TO DATE" << endl;
        cout << setfill('-') << setw(69) << "" << endl;
        for(int i = 0; i < leavecount; i++) {
            if(leavelist[i].status == "PENDING") {
                cout << left << setw(10) << leavelist[i].staffid 
                     << setw(20) << leavelist[i].name 
                     << setw(15) << leavelist[i].leavetype 
                     << setw(12) << leavelist[i].fromdate 
                     << setw(12) << leavelist[i].todate << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "NO PENDING LEAVE APPLICATIONS!\n";
        }
    }
    else if(choice == 2) {
        displayheader("APPROVED LEAVE APPLICATIONS");
        bool found = false;
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(15) << "LEAVE TYPE" 
             << setw(12) << "FROM DATE" 
             << setw(12) << "TO DATE" << endl;
        cout << setfill('-') << setw(69) << "" << endl;
        for(int i = 0; i < leavecount; i++) {
            if(leavelist[i].status == "APPROVED") {
                cout << left << setw(10) << leavelist[i].staffid 
                     << setw(20) << leavelist[i].name 
                     << setw(15) << leavelist[i].leavetype 
                     << setw(12) << leavelist[i].fromdate 
                     << setw(12) << leavelist[i].todate << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "NO APPROVED LEAVE APPLICATIONS!\n";
        }
    }
    else if(choice == 3) {
        displayheader("ALL LEAVE APPLICATIONS");
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(15) << "LEAVE TYPE" 
             << setw(12) << "FROM DATE" 
             << setw(12) << "TO DATE" 
             << setw(12) << "STATUS" << endl;
        cout << setfill('-') << setw(81) << "" << endl;
        for(int i = 0; i < leavecount; i++) {
            cout << left << setw(10) << leavelist[i].staffid 
                 << setw(20) << leavelist[i].name 
                 << setw(15) << leavelist[i].leavetype 
                 << setw(12) << leavelist[i].fromdate 
                 << setw(12) << leavelist[i].todate 
                 << setw(12) << leavelist[i].status << endl;
        }
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 7. PROCESS LEAVE APPLICATIONS
void processleaveapplications() {
    clearscreen();
    displayheader("PROCESS LEAVE APPLICATIONS");
    if(leavecount == 0) {
        cout << "NO LEAVE APPLICATIONS FOUND!\n";
        pressenter();
        return;
    }
    cout << "PENDING LEAVE APPLICATIONS:\n";
    cout << setfill('-') << setw(80) << "" << endl;
    bool found = false;
    for(int i = 0; i < leavecount; i++) {
        if(leavelist[i].status == "PENDING") {
            cout << "APPLICATION " << i+1 << ":\n";
            cout << "STAFF ID: " << leavelist[i].staffid << endl;
            cout << "NAME: " << leavelist[i].name << endl;
            cout << "LEAVE TYPE: " << leavelist[i].leavetype << endl;
            cout << "FROM: " << leavelist[i].fromdate << " TO: " << leavelist[i].todate << endl;
            cout << "REASON: " << leavelist[i].reason << endl;
            cout << setfill('-') << setw(40) << "" << endl;
            found = true;
        }
    }
    if(!found) {
        cout << "NO PENDING LEAVE APPLICATIONS!\n";
        pressenter();
        return;
    }
    int appindex;
    cout << "\nENTER APPLICATION NUMBER TO PROCESS: ";
    cin >> appindex;
    appindex--; // CONVERT TO ARRAY INDEX
    if(appindex < 0 || appindex >= leavecount) {
        cout << "ERROR: INVALID APPLICATION NUMBER!\n";
        pressenter();
        return;
    }
    if(leavelist[appindex].status != "PENDING") {
        cout << "ERROR: THIS APPLICATION IS ALREADY PROCESSED!\n";
        pressenter();
        return;
    }
    cout << "\nPROCESSING LEAVE FOR: " << leavelist[appindex].name << endl;
    cout << "1. APPROVE\n";
    cout << "2. REJECT\n";
    cout << "ENTER CHOICE (1-2): ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        leavelist[appindex].status = "APPROVED";
        cout << "\nSUCCESS: LEAVE APPLICATION APPROVED!\n";
    }
    else if(choice == 2) {
        leavelist[appindex].status = "REJECTED";
        cout << "\nSUCCESS: LEAVE APPLICATION REJECTED!\n";
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 8. VIEW COMPLAINTS FUNCTION
void viewcomplaints() {
    clearscreen();
    displayheader("COMPLAINTS MANAGEMENT");
    if(complaintcount == 0) {
        cout << "NO COMPLAINTS FOUND!\n";
        pressenter();
        return;
    }
    cout << "1. VIEW PENDING COMPLAINTS\n";
    cout << "2. VIEW RESOLVED COMPLAINTS\n";
    cout << "3. VIEW ALL COMPLAINTS\n";
    cout << "ENTER CHOICE (1-3): ";
    int choice;
    cin >> choice;
    clearscreen();
    if(choice == 1) {
        displayheader("PENDING COMPLAINTS");
        bool found = false;
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(20) << "COMPLAINT TYPE" 
             << setw(25) << "DESCRIPTION" << endl;
        cout << setfill('-') << setw(75) << "" << endl;
        for(int i = 0; i < complaintcount; i++) {
            if(complaintlist[i].status == "PENDING") {
                string shortdesc = complaintlist[i].description;
                if(shortdesc.length() > 20) {
                    shortdesc = shortdesc.substr(0, 17) + "...";
                }
                cout << left << setw(10) << complaintlist[i].staffid 
                     << setw(20) << complaintlist[i].name 
                     << setw(20) << complaintlist[i].complainttype 
                     << setw(25) << shortdesc << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "NO PENDING COMPLAINTS!\n";
        }
    }
    else if(choice == 2) {
        displayheader("RESOLVED COMPLAINTS");
        bool found = false;
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(20) << "COMPLAINT TYPE" 
             << setw(20) << "DATE" << endl;
        cout << setfill('-') << setw(70) << "" << endl;
        for(int i = 0; i < complaintcount; i++) {
            if(complaintlist[i].status == "RESOLVED") {
                cout << left << setw(10) << complaintlist[i].staffid 
                     << setw(20) << complaintlist[i].name 
                     << setw(20) << complaintlist[i].complainttype 
                     << setw(20) << complaintlist[i].date << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "NO RESOLVED COMPLAINTS!\n";
        }
    }
    else if(choice == 3) {
        displayheader("ALL COMPLAINTS");
        cout << left << setw(10) << "STAFF ID" 
             << setw(20) << "NAME" 
             << setw(20) << "COMPLAINT TYPE" 
             << setw(15) << "DATE" 
             << setw(12) << "STATUS" << endl;
        cout << setfill('-') << setw(77) << "" << endl;
        for(int i = 0; i < complaintcount; i++) {
            cout << left << setw(10) << complaintlist[i].staffid 
                 << setw(20) << complaintlist[i].name 
                 << setw(20) << complaintlist[i].complainttype 
                 << setw(15) << complaintlist[i].date 
                 << setw(12) << complaintlist[i].status << endl;
        }
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 9. RESOLVE COMPLAINTS
void resolvecomplaints() {
    clearscreen();
    displayheader("RESOLVE COMPLAINTS");
    if(complaintcount == 0) {
        cout << "NO COMPLAINTS FOUND!\n";
        pressenter();
        return;
    }
    cout << "PENDING COMPLAINTS:\n";
    cout << setfill('-') << setw(80) << "" << endl;
    bool found = false;
    for(int i = 0; i < complaintcount; i++) {
        if(complaintlist[i].status == "PENDING") {
            cout << "COMPLAINT " << i+1 << ":\n";
            cout << "STAFF ID: " << complaintlist[i].staffid << endl;
            cout << "NAME: " << complaintlist[i].name << endl;
            cout << "COMPLAINT TYPE: " << complaintlist[i].complainttype << endl;
            cout << "DESCRIPTION: " << complaintlist[i].description << endl;
            cout << "DATE: " << complaintlist[i].date << endl;
            cout << setfill('-') << setw(40) << "" << endl;
            found = true;
        }
    }
    if(!found) {
        cout << "NO PENDING COMPLAINTS!\n";
        pressenter();
        return;
    }
    int compindex;
    cout << "\nENTER COMPLAINT NUMBER TO RESOLVE: ";
    cin >> compindex;
    compindex--; // CONVERT TO ARRAY INDEX
    if(compindex < 0 || compindex >= complaintcount) {
        cout << "ERROR: INVALID COMPLAINT NUMBER!\n";
        pressenter();
        return;
    }
    if(complaintlist[compindex].status != "PENDING") {
        cout << "ERROR: THIS COMPLAINT IS ALREADY PROCESSED!\n";
        pressenter();
        return;
    }
    cout << "\nRESOLVING COMPLAINT FOR: " << complaintlist[compindex].name << endl;
    cout << "1. MARK AS RESOLVED\n";
    cout << "2. KEEP AS PENDING\n";
    cout << "ENTER CHOICE (1-2): ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        complaintlist[compindex].status = "RESOLVED";
        cout << "\nSUCCESS: COMPLAINT MARKED AS RESOLVED!\n";
    }
    else if(choice == 2) {
        cout << "\nCOMPLAINT REMAINS PENDING.\n";
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 10. GIVE BONUS FUNCTION
void givebonus() {
    clearscreen();
    displayheader("GIVE BONUS TO STAFF");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "1. GIVE BONUS TO INDIVIDUAL\n";
    cout << "2. GIVE BONUS TO DEPARTMENT\n";
    cout << "3. GIVE BONUS TO ALL STAFF\n";
    cout << "ENTER CHOICE (1-3): ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        int staffid;
        cout << "ENTER STAFF ID: ";
        cin >> staffid;
        int index = -1;
        for(int i = 0; i < staffcount; i++) {
            if(stafflist[i].id == staffid) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            cout << "ERROR: STAFF NOT FOUND!\n";
            pressenter();
            return;
        }
        cout << "STAFF NAME: " << stafflist[index].name << endl;
        cout << "CURRENT SALARY: " << stafflist[index].salary << endl;
        float bonusamount;
        cout << "ENTER BONUS AMOUNT: ";
        cin >> bonusamount;
        stafflist[index].salary += bonusamount;
        cout << "\nSUCCESS: BONUS GIVEN!\n";
        cout << "NEW SALARY: " << stafflist[index].salary << endl;
    }
    else if(choice == 2) {
        cin.ignore();
        string department;
        cout << "ENTER DEPARTMENT: ";
        getline(cin, department);
        float bonuspercentage;
        cout << "ENTER BONUS PERCENTAGE (e.g., 10 for 10%): ";
        cin >> bonuspercentage;
        int count = 0;
        for(int i = 0; i < staffcount; i++) {
            if(stafflist[i].department == department) {
                float bonusamount = stafflist[i].salary * (bonuspercentage / 100);
                stafflist[i].salary += bonusamount;
                count++;
            }
        }
        if(count > 0) {
            cout << "\nSUCCESS: BONUS GIVEN TO " << count << " STAFF IN " << department << " DEPARTMENT!\n";
        }
        else {
            cout << "\nERROR: NO STAFF FOUND IN " << department << " DEPARTMENT!\n";
        }
    }
    else if(choice == 3) {
        float bonusamount;
        cout << "ENTER BONUS AMOUNT FOR EACH STAFF: ";
        cin >> bonusamount;
        for(int i = 0; i < staffcount; i++) {
            stafflist[i].salary += bonusamount;
        }
        cout << "\nSUCCESS: BONUS GIVEN TO ALL " << staffcount << " STAFF MEMBERS!\n";
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}
// 9. VIEW SALARY SUMMARY FUNCTION
void viewsalarysummary() {
    clearscreen();
    displayheader("SALARY SUMMARY REPORT");   
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    float totalsalary = 0;
    float averagesalary = 0;
    float highestsalary = 0;
    string highestpaid;
    for(int i = 0; i < staffcount; i++) {
        totalsalary += stafflist[i].salary;
        if(stafflist[i].salary > highestsalary) {
            highestsalary = stafflist[i].salary;
            highestpaid = stafflist[i].name;
        }
    }
    averagesalary = totalsalary / staffcount;
    cout << "TOTAL STAFF: " << staffcount << endl;
    cout << "TOTAL MONTHLY SALARY: " << totalsalary << endl;
    cout << "AVERAGE SALARY: " << averagesalary << endl;
    cout << "HIGHEST PAID STAFF: " << highestpaid << " (" << highestsalary << ")" << endl;
    cout << "\nDEPARTMENT WISE SUMMARY:\n";
    cout << setfill('-') << setw(50) << "" << endl;
    string departments[10];
    float deptsalary[10] = {0};
    int deptcount[10] = {0};
    int uniquedepartments = 0;
    for(int i = 0; i < staffcount; i++) {
        bool found = false;
        for(int j = 0; j < uniquedepartments; j++) {
            if(departments[j] == stafflist[i].department) {
                deptsalary[j] += stafflist[i].salary;
                deptcount[j]++;
                found = true;
                break;
            }
        }
        if(!found) {
            departments[uniquedepartments] = stafflist[i].department;
            deptsalary[uniquedepartments] = stafflist[i].salary;
            deptcount[uniquedepartments] = 1;
            uniquedepartments++;
        }
    }
    cout << left << setw(20) << "DEPARTMENT" 
         << setw(10) << "STAFF" 
         << setw(15) << "TOTAL SALARY" 
         << setw(15) << "AVG SALARY" << endl;
    cout << setfill('-') << setw(60) << "" << endl;
    for(int i = 0; i < uniquedepartments; i++) {
        float avgsalary = deptsalary[i] / deptcount[i];
        cout << left << setw(20) << departments[i]
             << setw(10) << deptcount[i]
             << setw(15) << deptsalary[i]
             << setw(15) << avgsalary << endl;
    }
    pressenter();
}
// 10. VIEW ATTENDANCE SUMMARY FUNCTION
void viewattendancesummary() {
    clearscreen();
    displayheader("ATTENDANCE SUMMARY");
    
    cout << "ATTENDANCE REPORT FOR DECEMBER 2024:\n";
    cout << setfill('-') << setw(40) << "" << endl;   
    cout << "TOTAL WORKING DAYS: 22\n";
    cout << "TOTAL STAFF: " << staffcount << endl;
    if(staffcount > 0) {
        cout << "\nSAMPLE ATTENDANCE DATA:\n";
        cout << setfill('-') << setw(60) << "" << endl;
        int limit = (staffcount < 5) ? staffcount : 5;
        cout << left << setw(8) << "ID" 
             << setw(20) << "NAME" 
             << setw(15) << "PRESENT DAYS" 
             << setw(15) << "ABSENT DAYS" 
             << setw(12) << "PERCENTAGE" << endl;
        cout << setfill('-') << setw(70) << "" << endl;
        for(int i = 0; i < limit; i++) {
            int present = 18 + (i % 5);
            int absent = 22 - present;
            float percentage = (present * 100.0) / 22;
            cout << left << setw(8) << stafflist[i].id 
                 << setw(20) << stafflist[i].name 
                 << setw(15) << present 
                 << setw(15) << absent 
                 << setw(12) << fixed << setprecision(1) << percentage << "%" << endl;
        }
    }
    cout << "\nNOTE: THIS IS SAMPLE DATA. ACTUAL ATTENDANCE SYSTEM NOT IMPLEMENTED.\n";
    pressenter();
}
// 11. STAFF PROMOTION FUNCTION
void staffpromotion() {
    clearscreen();
    displayheader("STAFF PROMOTION");   
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "STAFF ELIGIBLE FOR PROMOTION (3+ YEARS EXPERIENCE):\n";
    cout << setfill('-') << setw(60) << "" << endl;
    bool found = false;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].experience >= 3) {
            cout << "ID: " << stafflist[i].id 
                 << " | NAME: " << stafflist[i].name 
                 << " | EXPERIENCE: " << stafflist[i].experience << " YEARS"
                 << " | CURRENT: " << stafflist[i].designation << endl;
            found = true;
        }
}
    if(!found) {
        cout << "NO STAFF ELIGIBLE FOR PROMOTION!\n";
        pressenter();
        return;
    }   
    cout << "\nENTER STAFF ID TO PROMOTE: ";
    int staffid;
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid && stafflist[i].experience >= 3) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF NOT FOUND OR NOT ELIGIBLE!\n";
        pressenter();
        return;
    }
    cout << "\nCURRENT DESIGNATION: " << stafflist[index].designation << endl;
    cout << "ENTER NEW DESIGNATION: ";
    cin.ignore();
    getline(cin, stafflist[index].designation);
    stafflist[index].salary *= 1.10;
    cout << "\nSUCCESS: STAFF PROMOTED!\n";
    cout << "NEW DESIGNATION: " << stafflist[index].designation << endl;
    cout << "NEW SALARY: " << stafflist[index].salary << endl;
    pressenter();
}
// 12. STAFF TRANSFER FUNCTION
void stafftransfer() {
    clearscreen();
    displayheader("STAFF TRANSFER");
    
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }   
    int staffid;
    cout << "ENTER STAFF ID TO TRANSFER: ";
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nCURRENT INFORMATION:\n";
    cout << "NAME: " << stafflist[index].name << endl;
    cout << "CURRENT DEPARTMENT: " << stafflist[index].department << endl;
    cout << "\nENTER NEW DEPARTMENT: ";
    cin.ignore();
    getline(cin, stafflist[index].department);
    cout << "\nSUCCESS: STAFF TRANSFERRED!\n";
    cout << "NEW DEPARTMENT: " << stafflist[index].department << endl;
    pressenter();
}
// 13. VIEW PERFORMANCE REPORTS FUNCTION
void viewperformancereports() {
    clearscreen();
    displayheader("PERFORMANCE REPORTS");   
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "PERFORMANCE RATING SYSTEM:\n";
    cout << "A = EXCELLENT (90-100%)\n";
    cout << "B = GOOD (75-89%)\n";
    cout << "C = AVERAGE (60-74%)\n";
    cout << "D = NEEDS IMPROVEMENT (Below 60%)\n";
    cout << "\nPERFORMANCE REPORT:\n";
    cout << setfill('-') << setw(70) << "" << endl;
    cout << left << setw(8) << "ID" 
         << setw(20) << "NAME" 
         << setw(15) << "DEPARTMENT" 
         << setw(12) << "RATING" 
         << setw(15) << "PERFORMANCE" << endl;
    cout << setfill('-') << setw(70) << "" << endl;
    for(int i = 0; i < staffcount && i < 10; i++) {
        int performance = 60 + (i * 3);
        char rating;
        string remark;
        if(performance >= 90) {
            rating = 'A';
            remark = "EXCELLENT";
        }
        else if(performance >= 75) {
            rating = 'B';
            remark = "GOOD";
        }
        else if(performance >= 60) {
            rating = 'C';
            remark = "AVERAGE";
        }
        else {
            rating = 'D';
            remark = "NEEDS IMPROVEMENT";
        }
        cout << left << setw(8) << stafflist[i].id 
             << setw(20) << stafflist[i].name 
             << setw(15) << stafflist[i].department 
             << setw(12) << rating 
             << setw(15) << remark << endl;
    }
    cout << "\nNOTE: THIS IS SAMPLE PERFORMANCE DATA.\n";
    pressenter();
}
// 14. VIEW RETIREMENT RECORDS FUNCTION
void viewretirementrecords() {
    clearscreen();
    displayheader("RETIREMENT RECORDS");   
    cout << "RETIREMENT AGE: 60 YEARS\n";
    cout << "STAFF APPROACHING RETIREMENT (55+ YEARS):\n";
    cout << setfill('-') << setw(60) << "" << endl;
    bool found = false;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].experience >= 30) {
            int yearsToRetire = 60 - (25 + stafflist[i].experience);
            if(yearsToRetire <= 5) {
                cout << "ID: " << stafflist[i].id 
                     << " | NAME: " << stafflist[i].name 
                     << " | EXPERIENCE: " << stafflist[i].experience << " YEARS"
                     << " | RETIRES IN: " << yearsToRetire << " YEARS" << endl;
                found = true;
            }
        }
    }
    if(!found) {
        cout << "NO STAFF NEARING RETIREMENT AGE.\n";
    }
    cout << "\nRETIREMENT BENEFITS:\n";
    cout << "1. GRATUITY = LAST SALARY * 15 * YEARS OF SERVICE / 26\n";
    cout << "2. PENSION = 70% OF LAST DRAWN SALARY\n";
    cout << "3. LEAVE ENCASHMENT\n";
    cout << "4. PROVIDENT FUND\n";
    pressenter();
}
// 15. GENERATE REPORTS FUNCTION
void generatereports() {
    clearscreen();
    displayheader("GENERATE REPORTS");   
    cout << "SELECT REPORT TYPE:\n";
    cout << "1. STAFF REPORT\n";
    cout << "2. FINANCIAL REPORT\n";
    cout << "3. ATTENDANCE REPORT\n";
    cout << "4. LEAVE REPORT\n";
    cout << "ENTER CHOICE (1-4): ";
    int choice;
    cin >> choice;
    clearscreen();
    if(choice == 1) {
        displayheader("STAFF REPORT");
        cout << "TOTAL STAFF: " << staffcount << endl;
        cout << "DEPARTMENT WISE DISTRIBUTION:\n";
        cout << setfill('-') << setw(30) << "" << endl;
        string departments[10];
        int deptcount[10] = {0};
        int uniquedepartments = 0;
        for(int i = 0; i < staffcount; i++) {
            bool found = false;
            for(int j = 0; j < uniquedepartments; j++) {
                if(departments[j] == stafflist[i].department) {
                    deptcount[j]++;
                    found = true;
                    break;
                }
            }
            if(!found) {
                departments[uniquedepartments] = stafflist[i].department;
                deptcount[uniquedepartments] = 1;
                uniquedepartments++;
            }
        }
        for(int i = 0; i < uniquedepartments; i++) {
            cout << departments[i] << ": " << deptcount[i] << " STAFF (" 
                 << (deptcount[i] * 100 / staffcount) << "%)\n";
        }
    }
    else if(choice == 2) {
        displayheader("FINANCIAL REPORT");
        
        float totalsalary = 0;
        for(int i = 0; i < staffcount; i++) {
            totalsalary += stafflist[i].salary;
        }
        cout << "MONTHLY SALARY EXPENDITURE: " << totalsalary << endl;
        cout << "ANNUAL SALARY EXPENDITURE: " << totalsalary * 12 << endl;
        if(staffcount > 0) {
            float averagesalary = totalsalary / staffcount;
            cout << "AVERAGE SALARY: " << averagesalary << endl;
        }
    }
    else if(choice == 3) {
        displayheader("ATTENDANCE REPORT");
        cout << "ATTENDANCE SUMMARY:\n";
        cout << "TOTAL STAFF: " << staffcount << endl;
        cout << "WORKING DAYS PER MONTH: 22\n";
        cout << "TOTAL MAN-DAYS PER MONTH: " << staffcount * 22 << endl;
        float estimatedattendance = 0.85;
        cout << "ESTIMATED ATTENDANCE RATE: " << estimatedattendance * 100 << "%\n";
        cout << "ESTIMATED PRESENT DAYS: " << staffcount * 22 * estimatedattendance << endl;
    }
    else if(choice == 4) {
        displayheader("LEAVE REPORT");
        cout << "TOTAL LEAVE APPLICATIONS: " << leavecount << endl;
        int pending = 0, approved = 0, rejected = 0;
        for(int i = 0; i < leavecount; i++) {
            if(leavelist[i].status == "PENDING") pending++;
            else if(leavelist[i].status == "APPROVED") approved++;
            else if(leavelist[i].status == "REJECTED") rejected++;
        }
        cout << "PENDING: " << pending << endl;
        cout << "APPROVED: " << approved << endl;
        cout << "REJECTED: " << rejected << endl;
        if(leavecount > 0) {
            cout << "APPROVAL RATE: " << (approved * 100 / leavecount) << "%\n";
        }
    }
    else {
        cout << "ERROR: INVALID CHOICE!\n";
    }
    pressenter();
}

// 10. VIEW MY LEAVE APPLICATIONS
void viewmyleaveapplications() {
    clearscreen();
    displayheader("MY LEAVE APPLICATIONS");
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    bool found = false;
    int applicationCount = 0;
    for(int i = 0; i < leavecount; i++) {
        if(leavelist[i].staffid == staffid) {
            applicationCount++;
        }
    }
    if(applicationCount == 0) {
        cout << "YOU HAVE NO LEAVE APPLICATIONS!\n";
        pressenter();
        return;
    }
    cout << "\nYOUR LEAVE APPLICATIONS (" << applicationCount << "):\n";
    cout << setfill('-') << setw(80) << "" << endl;
    for(int i = 0; i < leavecount; i++) {
        if(leavelist[i].staffid == staffid) {
            cout << "APPLICATION " << i+1 << ":\n";
            cout << "LEAVE TYPE: " << leavelist[i].leavetype << endl;
            cout << "FROM: " << leavelist[i].fromdate << " TO: " << leavelist[i].todate << endl;
            cout << "REASON: " << leavelist[i].reason << endl;
            cout << "STATUS: " << leavelist[i].status << endl;
            cout << setfill('-') << setw(40) << "" << endl;
            found = true;
        }
    }
    pressenter();
}
// 11. VIEW MY COMPLAINTS 
void viewmycomplaints() {
    clearscreen();
    displayheader("MY COMPLAINTS");
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    bool found = false;
    int complaintCount = 0;
    for(int i = 0; i < complaintcount; i++) {
        if(complaintlist[i].staffid == staffid) {
            complaintCount++;
        }
    }
    if(complaintCount == 0) {
        cout << "YOU HAVE NO COMPLAINTS!\n";
        pressenter();
        return;
    }
    cout << "\nYOUR COMPLAINTS (" << complaintCount << "):\n";
    cout << setfill('-') << setw(80) << "" << endl;
    for(int i = 0; i < complaintcount; i++) {
        if(complaintlist[i].staffid == staffid) {
            cout << "COMPLAINT " << i+1 << ":\n";
            cout << "COMPLAINT TYPE: " << complaintlist[i].complainttype << endl;
            cout << "DESCRIPTION: " << complaintlist[i].description << endl;
            cout << "DATE: " << complaintlist[i].date << endl;
            cout << "STATUS: " << complaintlist[i].status << endl;
            cout << setfill('-') << setw(40) << "" << endl;
            found = true;
        }
    }
    pressenter();
}
// ================== EXISTING USER FUNCTIONS ==================
// 1. VIEW ALL STAFF DATA USER
void viewallstaffuser() {
    clearscreen();
    displayheader("STAFF DIRECTORY");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << left << setw(8) << "ID" 
         << setw(20) << "NAME" 
         << setw(15) << "DEPARTMENT" 
         << setw(15) << "DESIGNATION" 
         << setw(12) << "CONTACT" << endl;
    cout << setfill('-') << setw(70) << "" << endl;
    for(int i = 0; i < staffcount; i++) {
        cout << left << setw(8) << stafflist[i].id 
             << setw(20) << stafflist[i].name 
             << setw(15) << stafflist[i].department 
             << setw(15) << stafflist[i].designation 
             << setw(12) << stafflist[i].contact << endl;
    }
    pressenter();
}
// 2. SEARCH STAFF USER
void searchstaffuser() {
    clearscreen();
    displayheader("SEARCH STAFF");
    if(staffcount == 0) {
        cout << "NO STAFF RECORDS FOUND!\n";
        pressenter();
        return;
    }
    cout << "ENTER NAME TO SEARCH: ";
    cin.ignore();
    string searchname;
    getline(cin, searchname);
    bool found = false;
    for(int i = 0; i < staffcount; i++) {
        string name = stafflist[i].name;
        bool match = false;
        if(name.length() >= searchname.length()) {
            match = true;
            for(int j = 0; j < searchname.length(); j++) {
                if(toupper(name[j]) != toupper(searchname[j])) {
                    match = false;
                    break;
                }
            }
    }   
        if(match) {
            if(!found) {
                cout << "\nSEARCH RESULTS:\n";
                cout << setfill('-') << setw(50) << "" << endl;
            }
            cout << "NAME: " << stafflist[i].name << endl;
            cout << "DEPARTMENT: " << stafflist[i].department << endl;
            cout << "DESIGNATION: " << stafflist[i].designation << endl;
            cout << "CONTACT: " << stafflist[i].contact << endl;
            cout << setfill('-') << setw(30) << "" << endl;
            found = true;
        }
    }
    if(!found) {
        cout << "NO STAFF FOUND WITH THAT NAME!\n";
    }
    pressenter();
}
// 3. APPLY FOR LEAVE USER
void applyforleaveuser() {
    clearscreen();
    displayheader("APPLY FOR LEAVE");
    if(leavecount >= 100) {
        cout << "ERROR: LEAVE DATABASE IS FULL!\n";
        pressenter();
        return;
    }
    leave newleave;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> newleave.staffid;
    bool staffexists = false;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == newleave.staffid) {
            staffexists = true;
            newleave.name = stafflist[i].name;
            break;
        }
    }
    if(!staffexists) {
        cout << "ERROR: STAFF ID NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nSELECT LEAVE TYPE:\n";
    cout << "1. SICK LEAVE\n";
    cout << "2. CASUAL LEAVE\n";
    cout << "3. ANNUAL LEAVE\n";
    cout << "4. EMERGENCY LEAVE\n";
    cout << "ENTER CHOICE (1-4): ";
    int leavetype;
    cin >> leavetype;
    if(leavetype == 1) newleave.leavetype = "SICK LEAVE";
    else if(leavetype == 2) newleave.leavetype = "CASUAL LEAVE";
    else if(leavetype == 3) newleave.leavetype = "ANNUAL LEAVE";
    else if(leavetype == 4) newleave.leavetype = "EMERGENCY LEAVE";
    else newleave.leavetype = "OTHER";
    cin.ignore();
    cout << "FROM DATE (DD-MM-YYYY): ";
    getline(cin, newleave.fromdate);
    cout << "TO DATE (DD-MM-YYYY): ";
    getline(cin, newleave.todate);
    cout << "REASON: ";
    getline(cin, newleave.reason);
    newleave.status = "PENDING";
    leavelist[leavecount] = newleave;
    leavecount++;
    cout << "\nSUCCESS: LEAVE APPLICATION SUBMITTED!\n";
    cout << "YOUR APPLICATION IS PENDING APPROVAL.\n";
    pressenter();
}
// 4. CHECK LEAVE STATUS USER
void checkleavestatus() {
    clearscreen();
    displayheader("CHECK LEAVE STATUS");
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    bool found = false;
    for(int i = 0; i < leavecount; i++) {
        if(leavelist[i].staffid == staffid) {
            if(!found) {
                cout << "\nYOUR LEAVE APPLICATIONS:\n";
                cout << setfill('-') << setw(60) << "" << endl;
                found = true;
            }
            cout << "LEAVE TYPE: " << leavelist[i].leavetype << endl;
            cout << "FROM: " << leavelist[i].fromdate << endl;
            cout << "TO: " << leavelist[i].todate << endl;
            cout << "STATUS: " << leavelist[i].status << endl;
            cout << setfill('-') << setw(30) << "" << endl;
        }
    }
    if(!found) {
        cout << "NO LEAVE APPLICATIONS FOUND FOR YOUR ID!\n";
    }
    pressenter();
}
// 5. SUBMIT COMPLAINT USER
void submitcomplaintuser() {
    clearscreen();
    displayheader("SUBMIT COMPLAINT");
    if(complaintcount >= 50) {
        cout << "ERROR: COMPLAINT DATABASE IS FULL!\n";
        pressenter();
        return;
    }
    complaint newcomplaint;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> newcomplaint.staffid;
    bool staffexists = false;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == newcomplaint.staffid) {
            staffexists = true;
            newcomplaint.name = stafflist[i].name;
            break;
        }
    }
    if(!staffexists) {
        cout << "ERROR: STAFF ID NOT FOUND!\n";
        pressenter();
        return;
    }
    cin.ignore();
    cout << "COMPLAINT TYPE: ";
    getline(cin, newcomplaint.complainttype);
    cout << "DESCRIPTION: ";
    getline(cin, newcomplaint.description);
    cout << "DATE (DD-MM-YYYY): ";
    getline(cin, newcomplaint.date);
    newcomplaint.status = "PENDING";
    complaintlist[complaintcount] = newcomplaint;
    complaintcount++;
    cout << "\nSUCCESS: COMPLAINT SUBMITTED!\n";
    cout << "YOUR COMPLAINT IS NOW PENDING REVIEW.\n";
    pressenter();
}
// 6. VIEW ATTENDANCE USER
void viewattendanceuser() {
    clearscreen();
    displayheader("YOUR ATTENDANCE");
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    bool staffexists = false;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            staffexists = true;
            break;
        }
    }
    if(!staffexists) {
        cout << "ERROR: STAFF ID NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nATTENDANCE REPORT FOR DECEMBER 2024:\n";
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "TOTAL WORKING DAYS: 22\n";
    cout << "PRESENT DAYS: 18\n";
    cout << "ABSENT DAYS: 2\n";
    cout << "LEAVE DAYS: 2\n";
    cout << "ATTENDANCE PERCENTAGE: 81.8%\n";
    cout << "\nMONTHLY SUMMARY:\n";
    cout << "JAN: 85% | FEB: 90% | MAR: 88% | APR: 82%\n";
    cout << "MAY: 95% | JUN: 87% | JUL: 91% | AUG: 89%\n";
    cout << "SEP: 86% | OCT: 92% | NOV: 88% | DEC: 82%\n";
    cout << "\nNOTE: THIS IS SAMPLE ATTENDANCE DATA.\n";
    pressenter();
}
// 7. VIEW SALARY DETAILS USER
void viewsalarydetails() {
    clearscreen();
    displayheader("SALARY DETAILS");
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF ID NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nSALARY DETAILS FOR " << stafflist[index].name << ":\n";
    cout << setfill('-') << setw(40) << "" << endl;
    float basicsalary = stafflist[index].salary;
    float tax = basicsalary * 0.05;
    float netsalary = basicsalary - tax;
    cout << "BASIC SALARY: " << basicsalary << endl;
    cout << "TAX DEDUCTION (5%): " << tax << endl;
    cout << "NET SALARY: " << netsalary << endl;
    cout << "STAFF TYPE: " << stafflist[index].type << endl;
    cout << "DESIGNATION: " << stafflist[index].designation << endl;
    pressenter();
}
// 8. UPDATE PROFILE (USER)
void updateprofileuser() {
    clearscreen();
    displayheader("UPDATE YOUR PROFILE");   
    int staffid;
    cout << "ENTER YOUR STAFF ID: ";
    cin >> staffid;
    int index = -1;
    for(int i = 0; i < staffcount; i++) {
        if(stafflist[i].id == staffid) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "ERROR: STAFF ID NOT FOUND!\n";
        pressenter();
        return;
    }
    cout << "\nCURRENT INFORMATION:\n";
    cout << "NAME: " << stafflist[index].name << endl;
    cout << "CONTACT: " << stafflist[index].contact << endl;
    cout << "\nYOU CAN UPDATE ONLY CONTACT INFORMATION:\n";
    cin.ignore();
    cout << "NEW CONTACT NUMBER: ";
    getline(cin, stafflist[index].contact);
    cout << "\nSUCCESS: PROFILE UPDATED!\n";
    pressenter();
}
// 9. VIEW NOTIFICATIONS (USER)
void viewnotifications() {
    clearscreen();
    displayheader("NOTIFICATIONS");   
    cout << "RECENT NOTIFICATIONS:\n";
    cout << setfill('-') << setw(50) << "" << endl;
    cout << "1. NEW LEAVE POLICY ANNOUNCED (01-DEC-2024)\n";
    cout << "2. HOLIDAY SCHEDULE FOR DECEMBER (05-DEC-2024)\n";
    cout << "3. SALARY DISBURSEMENT ON 1ST JANUARY (10-DEC-2024)\n";
    cout << "4. ANNUAL PARTY ON 25TH DECEMBER (15-DEC-2024)\n";
    cout << "5. SYSTEM MAINTENANCE ON SUNDAY (20-DEC-2024)\n";
    cout << "\nUNREAD: 2\n";
    cout << "TOTAL: 5\n";
    pressenter();
}
// ================== MAIN FUNCTION ==================
int main() {
    if(staffcount == 0) {
        stafflist[0] = {101, "ALI AHMED", "IT", "SOFTWARE ENGINEER", 80000, "PERMANENT", 3, "01-01-2022", "0300-1234567"};
        stafflist[1] = {102, "SARA KHAN", "HR", "HR MANAGER", 60000, "PERMANENT", 5, "15-03-2020", "0312-9876543"};
        stafflist[2] = {103, "USMAN ALI", "FINANCE", "ACCOUNTANT", 50000, "CONTRACT", 2, "01-06-2023", "0333-5555555"};
        stafflist[3] = {104, "FATIMA ZAHRA", "IT", "WEB DEVELOPER", 70000, "PERMANENT", 4, "10-09-2021", "0345-1112222"};
        stafflist[4] = {105, "BILAL AHMED", "MARKETING", "MARKETING MANAGER", 55000, "TEMPORARY", 1, "01-01-2024", "0321-9998888"};
        staffcount = 5;       
        leavelist[0] = {101, "ALI AHMED", "SICK LEAVE", "01-12-2024", "03-12-2024", "PENDING", "FEVER"};
        leavelist[1] = {102, "SARA KHAN", "CASUAL LEAVE", "05-12-2024", "07-12-2024", "APPROVED", "FAMILY FUNCTION"};
        leavecount = 2;
        complaintlist[0] = {103, "USMAN ALI", "TECHNICAL", "LAPTOP NOT WORKING", "PENDING", "01-12-2024"};
        complaintlist[1] = {101, "ALI AHMED", "ADMINISTRATIVE", "SALARY DELAY", "RESOLVED", "28-11-2024"};
        complaintcount = 2;
    }
    int mainchoice;
    int adminchoice;
    int userchoice;
    do {
        clearscreen();
        cout << "\n";
        cout << setfill('=') << setw(60) << "" << endl;
        cout << "           STAFF MANAGEMENT SYSTEM" << endl;
        cout << setfill('=') << setw(60) << "" << endl;
        cout << "\nMAIN MENU:\n";
        cout << "1. ADMIN LOGIN\n";
        cout << "2. USER LOGIN\n";
        cout << "3. EXIT\n";
        cout << setfill('-') << setw(30) << "" << endl;
        cout << "ENTER YOUR CHOICE (1-3): ";
        cin >> mainchoice;
        switch(mainchoice) {
            case 1:  // ADMIN MENU
                {
                    int password;
                    cout << "\nENTER ADMIN PASSWORD: ";
                    cin >> password;
                    if(password == 72511) {
                        cout << "ACCESS GRANTED!\n";
                        pressenter();
                        do {
                            clearscreen();
                            displayheader("ADMIN DASHBOARD");
                            //ADMIN MENU
                            cout << "1.  ADD STAFF\n";
                            cout << "2.  VIEW ALL STAFF\n";
                            cout << "3.  SEARCH STAFF\n";
                            cout << "4.  UPDATE STAFF\n";
                            cout << "5.  DELETE STAFF\n";
                            cout << "6.  VIEW LEAVE APPLICATIONS\n";
                            cout << "7.  PROCESS LEAVE APPLICATIONS (NEW)\n";
                            cout << "8.  VIEW COMPLAINTS\n";
                            cout << "9.  RESOLVE COMPLAINTS (NEW)\n";
                            cout << "10. GIVE BONUS\n";
                            cout << "11. VIEW SALARY SUMMARY\n";
                            cout << "12. VIEW ATTENDANCE SUMMARY\n";
                            cout << "13. STAFF PROMOTION\n";
                            cout << "14. STAFF TRANSFER\n";
                            cout << "15. VIEW PERFORMANCE REPORTS\n";
                            cout << "16. VIEW RETIREMENT RECORDS\n";
                            cout << "17. GENERATE REPORTS\n";
                            cout << "18. BACK TO MAIN MENU\n";
                            cout << setfill('-') << setw(40) << "" << endl;
                            cout << "ENTER YOUR CHOICE (1-18): ";
                            cin >> adminchoice;
                            switch(adminchoice) {
                                case 1: addstaff(); break;
                                case 2: viewallstaff(); break;
                                case 3: searchstaff(); break;
                                case 4: updatestaff(); break;
                                case 5: deletestaff(); break;
                                case 6: viewleaveapplication(); break;
                                case 7: processleaveapplications(); break;  
                                case 8: viewcomplaints(); break;
                                case 9: resolvecomplaints(); break;  
                                case 10: givebonus(); break;
                                case 11: viewsalarysummary(); break;
                                case 12: viewattendancesummary(); break;
                                case 13: staffpromotion(); break;
                                case 14: stafftransfer(); break;
                                case 15: viewperformancereports(); break;
                                case 16: viewretirementrecords(); break;
                                case 17: generatereports(); break;
                                case 18: 
                                    cout << "\nRETURNING TO MAIN MENU...\n";
                                    pressenter();
                                    break;
                                default: 
                                    cout << "ERROR: INVALID CHOICE!\n";
                                    pressenter();
                            }
                        } while(adminchoice != 18);
                    }
                    else {
                        cout << "ACCESS DENIED! WRONG PASSWORD.\n";
                        pressenter();
                    }
                }
                break;
            case 2:  // USER MENU
                do {
                    clearscreen();
                    displayheader("USER DASHBOARD");
                    // USER MENU FUNCTIONS
                    cout << "1.  VIEW ALL STAFF DATA\n";
                    cout << "2.  SEARCH STAFF\n";
                    cout << "3.  APPLY FOR LEAVE\n";
                    cout << "4.  VIEW MY LEAVE APPLICATIONS (NEW)\n";
                    cout << "5.  CHECK LEAVE STATUS\n";
                    cout << "6.  SUBMIT COMPLAINT\n";
                    cout << "7.  VIEW MY COMPLAINTS (NEW)\n";
                    cout << "8.  VIEW ATTENDANCE\n";
                    cout << "9.  VIEW SALARY DETAILS\n";
                    cout << "10. UPDATE PROFILE\n";
                    cout << "11. VIEW NOTIFICATIONS\n";
                    cout << "12. BACK TO MAIN MENU\n";
                    cout << setfill('-') << setw(40) << "" << endl;
                    cout << "ENTER YOUR CHOICE (1-12): ";
                    cin >> userchoice;
                    switch(userchoice) {
                        case 1: viewallstaffuser(); break;
                        case 2: searchstaffuser(); break;
                        case 3: applyforleaveuser(); break;
                        case 4: viewmyleaveapplications(); break;  
                        case 5: checkleavestatus(); break;
                        case 6: submitcomplaintuser(); break;
                        case 7: viewmycomplaints(); break;  
                        case 8: viewattendanceuser(); break;
                        case 9: viewsalarydetails(); break;
                        case 10: updateprofileuser(); break;
                        case 11: viewnotifications(); break;
                        case 12: 
                            cout << "\nRETURNING TO MAIN MENU...\n";
                            pressenter();
                            break;
                        default: 
                            cout << "ERROR: INVALID CHOICE!\n";
                            pressenter();
                    }
                } while(userchoice != 12);
                break;
            case 3:  // EXIT
                clearscreen();
                cout << "\n";
                cout << setfill('=') << setw(60) << "" << endl;
                cout << "           THANK YOU FOR USING OUR SYSTEM!" << endl;
                cout << setfill('=') << setw(60) << "" << endl;
                cout << "\n";
                return 0;
            default:
                cout << "ERROR: INVALID CHOICE! PLEASE ENTER 1-3.\n";
                pressenter();
        }
    } while(true);
    return 0;
}

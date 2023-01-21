#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cctype>   // Header file containing character functions
#include<direct.h> //contains functions for manipulating file system directories.
#include<process.h>//instructs the preprocessor to look into the present folder or the standard folder of all header files,
#include<ctime>   //converts the given time since epoch to a calendar local time and then to a character representation
#include<string>
#include<windows.h>
using namespace std;
//Declaring Functions Prototype
void studentcalculate();//calculate grade
void getdata();		//collect data
void add();			// add a record
void search();		// search a record
void list(); 		//display the record
void del(); 		// delete the record
void modify();		// mpdify the record
void rec(); 		//scan the new record
void mainPage(); 	//starting page
int logScreen();	// login screen
void callExit();	// exit function
void menu();		// Main Menu
void date();		// to get current date
void empty();		// used in deleting the record
void title();		// title bar
void result ();
//Declaring Global varaibles
char username[30], name[10];
char password[30], pass[10],grade;
int i,rollno, p_marks, c_marks, m_marks, e_marks, cs_marks;
float per;
constexpr auto SPACE = "\t\t\t\t" ;
struct information
{
  char ID[15];		 //Student ID
  char name[30];	//Student name
  char cls[10]; 	//Class of Student
  char Branch[35];  //Branch of class
  char address[50]; //Address of Student
  char email[30];   //Email of Student
  char rollno[15];  //Roll No Of a Student
  char phoneno[15]; //Phone No Of a Student
};
information c;
FILE *fpt;

int loginPassword(char *password){
	  system("CLS");
      string pass ="";
      char ch;
	  cout<<"\n\n\n\n\n\n\t\t\t\t\t---------------------------------------";
	  cout<<"\n\t\t\t\t\tPUCIT STUDENT INFORMATION MANAGEMENT LOGIN\n";
	  cout<<"\t\t\t\t\t--------------------------------------\n";
      cout << "\n\n\t\t\t\t\tEnter Password: ";
      ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch); //Appends character ch to the end of the string, increasing its length by one.
      cout << '*';
      ch = _getch();
   }
   if(pass == password){
   	
      cout << "\n\n\n\t\t\t\t\tAccess Granted \n\n\n";
      system("PAUSE");
   }else{
      cout << "\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!\n";
      system("PAUSE");//pause the program
      loginPassword(password);
   		}
	  return 0 ;
}

void tittle(){
	cout<<"\n\n\n\t"<<SPACE<<"\n";
	cout<<SPACE<<"    ---------------------------------------------\n";
	cout<<SPACE<<"    |PUCIT STUDENT INFORMATION MANAGEMENT SYSTEM|\n";
	cout<<SPACE<<"    ---------------------------------------------\n";
	cout<<"\n\n"<<SPACE;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void mainPage(){
	int process=0;
	system("cls");
	cout<<"\n\n\n\t"<<SPACE<<"\n";
	cout<<SPACE<<"    ---------------------------------------------\n";
	cout<<SPACE<<"    |PUCIT STUDENT INFORMATION MANAGEMENT SYSTEM|\n";
	cout<<SPACE<<"    ---------------------------------------------\n";
	cout<<"\n\n"<<SPACE;
	cout<<"Prepared By    :   H.M.Asad Jamil\n\n"<<SPACE;
	cout<<" Project   :   Student Management System\n\n"<<SPACE;
	cout<<"\n\n"<<SPACE;
	cout<<"    Press Enter to continue......\n\n"<<SPACE;
	getch();
	cout<<"Loading";
	for(process=0;process<25;process++)
  {
    delay(150);
    printf(".");
  }
}
void menu()
{
  int input;
  system("cls");
  tittle();
  cout<<" 1. Enter new Records\n\n"<<SPACE;
  cout<<" 2. Modify Records\n\n"<<SPACE;
  cout<<" 3. Delete Records\n\n"<<SPACE;
  cout<<" 4. Search and view Records\n\n"<<SPACE;
  cout<<" 5. Exit\n\n"<<SPACE;
  cout<<"Choose options:[1/2/3/4/5]:";
  fflush(stdin);// used to clear the stream/buffer
  cin>>input;
  switch(input)
  {
    case 1:
    {
      system("cls");
      add();
    }
    break;

    case 2:
    {
      system("cls");
      modify();
      getchar();
    }
    break;

    case 3:
    {
      system("cls");
      del();
    }
    break;

    case 4:
    {
      system("cls");
      search();
    }break;

    case 5:
    {
      system("cls");
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      fflush(stdin);// used to clear the stream/buffer
      cout<<SPACE;
      cout<<"Brought To You By Asad jamil";
      cout<<"\n\n\n\n";
      exit(0);
    }
    break;

    default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<SPACE;
      cout<<"      Invalid input!\n\n";
      cout<<SPACE;
      cout<<"Press Enter to choose again...";
      getchar();
      menu();
    }
  }
  }
int logScreen(char *username,char *password){

  char username1[30];
  char password1[30];
  int ttry = 0;
  int true1 = 1;
  do
  {
  	cout<<"\n\n\n\n\n\n\n\n\n\n\t"<<SPACE<<"Username: ";
  	cin>>username1;
  	cout<<SPACE<<"\t\n"<<SPACE;
  	cout<<"Password: ";
  	cin>>password1;
  	if(strcmp(username1,username)==0 && strcmp(password1,password)==0)
      {
      	cout<<"\n\n"<<SPACE;
      	cout<<"You are accessed to the system!\n\n";
      	cout<<"\t\t\t\t   Press Enter to continue...";
      	fflush(stdin);
        getchar();
        menu();
        system("cls");
        getchar();
        true1 =0;
      }
      else
      {
        system("cls");
        ttry = ttry+1;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
        cout<<SPACE;
        cout<<"No. of attempts remain: "<<3-ttry;
        fflush(stdin);
        getchar();
        if(ttry>=3)
        {
          cout<<"\t\t\t\t\t\t\n"<<SPACE;
          cout<<"   No permission to enter the system!";
          getchar();
          callExit();
          getchar();
      }
  }
}
while(true1==1);
return 0;
}


  void add()
  {
    char input;
    system("cls");
    cout<<" \n";
    cout<<SPACE;
    cout<<"\n";
    cout<<SPACE;
    cout<<endl;
    cout<<SPACE;
    cout<<endl;
    cout<<"\n\n\n\n";
    cout<<SPACE;
    cout<<"Enter The Information Below: \n\n";
    cout<<SPACE;
    cout<<"Enter ID        :  ";

    fflush(stdin);
    gets(c.ID);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Full Name       :  ";
    fflush(stdin);
    gets(c.name);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Class           :  ";
    fflush(stdin);
    gets(c.cls);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Branch          :  ";
    fflush(stdin);
    gets(c.Branch);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Address         :  ";
    fflush(stdin);
    gets(c.address);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Email Address   :  ";
    fflush(stdin);
    gets(c.email);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Roll No.        :  ";
    fflush(stdin);
    gets(c.rollno);
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Phone No.       :  ";
    fflush(stdin);
    gets(c.phoneno);
    fflush(stdin);
    fpt=fopen("data.txt","a");//opens a file 
    fwrite(&c,sizeof(c),1,fpt);//write on a file
    fclose(fpt);//closes a file
    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Record added successfully!!";

    cout<<"\n\n";
    cout<<SPACE;
    cout<<"Do you want to add more?(Y/N)";
    cin>>input;
    if(input=='Y' || input=='y')
    {
      add();
    }
    else
    menu();
    getchar();
    }

void callExit()
      {
       system("cls");
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
       cout<<SPACE;
       fflush(stdin);
       cout<<"You are out of the System.";
       cout<<"\n\n";
       cout<<SPACE;
       cout<<"   Press Enter to Continue Exit Program...";
       getchar();
       exit(0);
      }

void search()
      {
        int ch;
        char sid[30];
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
        cout<<SPACE;

        fflush(stdin);
        cout<<"Enter Full Name: ";
        cin>>sid;

        fpt=fopen("data.txt","r");//Open a text file for reading. The file must exist. 
        while (fread(&c, sizeof(c), 1, fpt)==1)
        {
          if(strcmp(sid,c.name)==0)//comparision 
          {
            ch=1;
            break;
          }
        }
        if(ch==1)
        {
          system("cls");
          cout<<"\n\n\n\n\n\n\n\t";
          cout<<SPACE;

          cout<<"<<==Search Succesfull==>>";
          fflush(stdin);
          getchar();
          list(); //display the record
          cout<<"\n\n\n\t";
          cout<<SPACE;
          cout<<"Press Enter For Main Menu...";
          getchar();
          menu();
        }
        else
        {
          system("cls");
          getchar();
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
          cout<<SPACE;

          cout<<"<<--Record Not Found-->>";
          cout<<("\n\n\n\t");
          cout<<SPACE;
          cout<<"Press Enter For Main Menu...";
          getchar();
          menu();
        }

        fclose(fpt);
      }

void list()
{
      cout<<" ";
     cout<<"\n";
      cout<<SPACE;
      cout<<SPACE;
      cout<<"\n";
      cout<<SPACE;
      cout<<"\n";
      cout<<SPACE;
      cout<<"\tID            :   "<<c.ID;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Full Name       :   "<<c.name;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Class           :   "<<c.cls;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Branch          :   "<<c.Branch;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Address         :   "<<c.address;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Email Address   :   "<<c.email;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Roll No.        :   "<<c.rollno;
      cout<<"\n\n";
      cout<<SPACE;
      cout<<"Phone No.       :   "<<c.phoneno;

}

void del()
       {
         FILE *fpt,*temp;
         int ch;
         char sid[30];

         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
         cout<<SPACE;
         cout<<"Enter Full Name:";
         fflush(stdin);
         scanf("%[^\n]s",sid);
         fflush(stdin);
         cout<<SPACE;
         cout<<"\t\n\t";
         cout<<SPACE;
         cout<<"Record Deleted Successfully.\n\n\t";
         cout<<"\n";
         cout<<SPACE;
         cout<<"Press Enter For Main Menu...";
         getchar();
         menu();
         fpt=fopen("data.txt","r");
         temp = fopen("temp.txt", "w");
         while (fread(&c, sizeof(c), 1, fpt)==1)
         {
           if(strcmp(sid,c.name)==0)
           {
             {
                 fwrite(&c,sizeof(c),1,temp);
           }
         }
         fclose(fpt);
         fclose(temp);
         remove("data.txt");
         rename("temp.txt","data.txt");
         }
       }


void empty()
      {
        strcpy(c.ID," ");
        strcpy(c.name," ");
        strcpy(c.cls," ");
        strcpy(c.Branch," ");
        strcpy(c.address," ");
        strcpy(c.email," ");
        strcpy(c.rollno," ");
        strcpy(c.phoneno," ");
      }
int main(){
	int entry ;
	tittle();
	cout<<"\t1 Admin \n\t\t\t\t\t2 User\n";
	cin>>entry;
	switch(entry){
		case 1:
		{
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	cin>>pass;
	if(strcmp(pass,"admin")==0)
	{
    	cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    	getch();
    
	}
		result ();
	break;
}
	case 2:
	{
		cout<<SPACE<<"\tENTER USER NAME"<<SPACE;
		cin>>username;
		cout<<endl;
		cout<<SPACE<<"\tEnter Password"<<SPACE;
		cin>>password;
		system("cls");
		loginPassword(password);
		system("cls");
		mainPage();
		system("cls");
		logScreen(username, password);
	break;
	  }
	defalt :
		{
		cout<<"invalid input";
		}
	 }
}

void modify()
{
  char mid[30];

  int found=0;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t\t\t";
  fflush(stdin);
  cout<<"Enter Full Name: ";
  cin>>mid;
  fflush(stdin);
  FILE *fpt, *temp;
  temp =fopen("temp.txt","w");
  fpt = fopen("data.txt","r+");
  while(fread(&c, sizeof(c),1,fpt) == 1)
  {
      if(strcmp(mid, c.name) == 0)
      {
          fflush(stdin);
          system("cls");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"<<<==Old Record==>>>";
          cout<<"\n";
          cout<<"\t\t\t\t\t";
          list();
          cout<<"\n\n";
          cout<<"\t\t\t\t\t";

          cout<<"Press Enter to modify the record...";


          getchar();
          system("cls");
          rec(); // this will ask to enter new record
          fseek(fpt, ftell(fpt) - sizeof(c),0);
          fwrite(&c, sizeof(c), 1, fpt); //The new name will be added to the record.
          found = 1;
          cout<<"\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"Record Saved !!!";
          getchar();
        }
        fclose(fpt);
        menu();
      }

      if(!found)
      {
        {
          system("cls");
          delay(200);
          fflush(stdin);

          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";
          fflush(stdin);

          cout<<"<<--Record Not Found-->>";
          getchar();
          menu();
        }
      }
      fclose(fpt);
}

void showdata()
{
	system("CLS");
	cout<<"\t---------------------------------------------";
	cout<<"\n\tPUCIT STUDENT INFORMATION MANAGMENT SYSTEM\n";
	cout<<"\t---------------------------------------------";
	cout<<"\n\n\tRoll number of student : "<<rollno;
	cout<<"\n\n\tName of student : "<<name;
	cout<<"\n\n\tMarks in Physics : "<<p_marks;
	cout<<"\n\n\tMarks in Chemistry : "<<c_marks;
	cout<<"\n\n\tMarks in Maths : "<<m_marks;
	cout<<"\n\n\tMarks in English : "<<e_marks;
	cout<<"\n\n\tMarks in Computer Science :"<<cs_marks;
	cout<<"\n\n\tPercentage of student is  :"<<per;
	cout<<"\n\n\tGrade of student is :"<<grade;
}
	
	
void result(){

	char ch;
	int rollno;
	system("CLS");
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\t1. Student Report Card";
	cout<<"\n\n\t2. Exit ";
	cout<<"\n\n\n\tEnter Choice (1/2)? ";
	cin>>ch;
	switch(ch)
	{
	case '1' :
		  getdata();
		  showdata();
		   break;
	case '2' :
			break;
	default :
			cout<<"\a";
	}
}



void getdata()
{
	system("CLS");
	cout<<"\nEnter The roll number of student: ";
	cin>>rollno;
	cout<<"\nEnter The Name of Student: ";
	cin>>name;
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	studentcalculate();
}


void studentcalculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=80)
		grade='A';
	else if(per>=70)
		grade='B';
	else if(per>=60)
		grade='C';
	else if(per>=50)
		grade='D';
	else if(per>=40)
		grade='E';
	else if(per>=33)
		grade='F';
	else
		grade='F';
}


void rec()
       {
         cout<<" ";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\n\n\n\n";
         cout<<"\t\t\t\t";

         cout<<"Enter The Information Below: \n\n";
         cout<<"\t\t\t\t";
         cout<<"\tID      :  %s\n\n",c.ID;
         cout<<"\t\t\t\t";
         cout<<"Full Name       :  ";
         fflush(stdin);
         cin>>c.name;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Class           :  ";
         fflush(stdin);
         cin>>c.cls;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Branch          :  ";
         fflush(stdin);
         cin>>c.Branch;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Address         :  ";
         fflush(stdin);
         cin>>c.address;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Email Address   :  ";
         fflush(stdin);
         cin>>c.email;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Roll No.        :  ";
         fflush(stdin);
         cin>>c.rollno;
         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"Phone No.       :  ";
         fflush(stdin);
         cin>>c.phoneno;
         fflush(stdin);
}


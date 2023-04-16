#include <bits/stdc++.h>
#define clr() system("cls")
using namespace std;
struct node
{
  int age;
  string name, uname, pass, title, school, nat;
  int score, zer, ten, twe, thi, fort, fif; //for playing record
  int strk, mxstrk; //for "achievement" section
};

struct node *ob = NULL;
int wow;
// Declaration of all functions to be used...
void start();
void signup();
void sign();
int check(char);
void login();
int srch(string,string);
void menu();
void play();
void leaderb();
void profile();
void afans();
void ansa(char a);
void ansb(char a);
void ansc(char a);
void ansd(char a);
void root_set();
void set1();
void rules();
void achieve();
void record();
void info();
void rem(char un[20]);
void update(char un[20]);
void admin();

void cons() // Construct an identity
{
  cout << "In cons";
  ob->age = 0;
  ob->name = "null";// strcpy(ob->name, "null");
  // cout << "Name";
  ob->uname = "null";// strcpy(ob->uname, "null");
  ob->pass = "null";// strcpy(ob->pass, "null");
  ob->title = "null";// strcpy(ob->title, "null");
  ob->school = "null";// strcpy(ob->school, "null");
  ob->nat = "null";// strcpy(ob->nat, "null");
  // Initializing all the scores to zero
  ob->score = ob->zer = ob->ten = ob->twe = ob->thi = ob->fort = ob->fif = 0;
  ob->strk = ob->mxstrk = 0;
  cout << "Going out of cons" << endl;
}

void fordelay(int j) // Showing the processings
{
  int i, k;
  for (i = 0; i < j; i++)
    k = i;
}

int check(string u)
{
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  FILE *fin = fopen("quiz.dat", "rb");
  fseek(fin, 0, SEEK_SET);
  while (fread(tmp, sizeof(struct node), 1, fin))
  {
    if (tmp->uname == u)
      return 0;
  }

  return 1;
}

void sign()
{
  clr();
  cout << "In sign fun" << endl;
  system("color F9");
  int op, len, i;
  char ch;
  string p1, p2;

  cout << "\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\  SIGNUP  \xB1\xB1\xB1\xB1\xB1\xB1\n\n";
  // printf("1.Name* : %s\n2.Age* : %d\n3.User name* : %s\n", ob->name, ob->age, ob->uname);
  // printf("4.Password* : %s\n5.Title : %s\n6.School : %s\n7.Nationality : %s\n",
  //        ob->pass, ob->title, ob->school, ob->nat);
  cout << "1. Name* : " << ob->name << endl;
  cout << "2. Age* : " << ob->age << endl;
  cout << "3. User name : " << ob->uname << endl;
  cout << "4. Password* : " << ob->pass << endl;
  cout << "5. Title : " << ob->title << endl;
  cout << "6. School : " << ob->school << endl;
  cout << "7. Nationality : " << ob->nat << endl;
  cout << "8. Submit " << endl;
  cout << "9. Back to Start Menu " << endl;

  cout << "\nNote-fields marked with asterix(*) should be filled mandatorily";
  cout << "\n    -username is unique and can't be changed later";
  cout << "\n    -password should contain only alphanumerics";
  cout << "\n    -age should be above 5 and below 120 to be eligible\n\n";
  cout << "Enter option\n";
  cin >> op;
  // scanf("%d", &op);

  switch (op)
  {
  case 1:
    cout << "Enter name: " << endl;
    fflush(stdin);
    getline(cin,ob->name);
    cout << "Name entered" << endl;
    // scanf(" %[^\n]s", ob->name);
    getchar();
    sign();
    break;
  case 2:
    cout << "Enter age :" << endl;
    fflush(stdin);
    cin >> ob->age;
    // scanf("%d", &(ob->age));
    if (ob->age <= 5 || ob->age >= 100)
    {
      cout << "Age should be above 5 and below 100 to be eligible" << endl;
      ob->age = 0;
    }
    getchar();
    sign();
    break;
  case 3:
    cout << "Enter username " << endl;
    fflush(stdin);
    getline(cin,ob->uname);
    // scanf(" %[^\n]s", ob->uname);
    if (!check(ob->uname))
    {
      cout << "User name already exists" << endl;
      ob->uname = "null";
    }
    getchar();
    sign();
    break;
  case 4:
    cout << "Enter password " << endl;
    i = 0;
    fflush(stdin);
    do
    {
      p1[i] = getchar();
      i++;
      if ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122))
        cout << "*";
    } while ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122));
    p1[i - 1] = '\0';

    cout << "\nEnter password again for confirmation " << endl;
    i = 0;
    do
    {
      p2[i] = getchar();
      i++;
      if ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122))
        cout << "*";
    } while ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122));
    p2[i - 1] = '\0';

    if (p1 == p2)
    {
      len = p1.size();
      for (i = 0; i < len; ++i)
      {
        if (!((p1[i] >= 48 && p1[i] <= 57) || (p1[i] >= 65 && p1[i] <= 90) || (p1[i] >= 97 && p1[i] <= 122)))
          break;
      }

      if (i != len)
      {
        cout << "Password should contain only alphanumerics " << endl;
        cout << "Password not created " << endl;
      }
      else
        ob->pass = p1;// strcpy(ob->pass, p1);
    }
    else
      cout << "Password not created" << endl;

    getchar();
    sign();
    break;
  case 5:
    cout << "Enter title " << endl;
    getline(cin,ob->title);// scanf(" %[^\n]s", ob->title);
    getchar();
    sign();
    break;
  case 6:
    cout << "Enter school " << endl;
    getline(cin,ob->school);// scanf(" %[^\n]s", ob->school);
    getchar();
    sign();
    break;
  case 7:
    cout << "Enter nationality " << endl;
    getline(cin,ob->nat);// scanf(" %[^\n]s", ob->nat);
    getchar();
    sign();
    break;
  case 8:
    cout << "Are you sure(y/n)? " << endl;
    cin >> ch;
    if (ch == 'y')
    {
      if (ob->name != "null" && ob->age != 0 && ob->uname != "null" && ob->pass != "null")
        wow = 1;
      else
      {
        cout << "Please fill all the mandatory fields.\nPress any key to try again." << endl;
        getchar();
        sign();
      }
    }
    else
    {
      cout << "Press any key to continue " << endl;
      getchar();
      sign();
    }
    break;
  case 9:
    return;
  default:
    cout << "Wrong input \n Press any key to try again " << endl;
    getchar();
    sign();
  }
}
void signup()
{
  cout << "In signup" << endl;
  wow = 0;

  ob = (struct node *)malloc(sizeof(struct node));
  cout << "ob cons" << endl;
  cons();

  sign();

  if (wow)
  {
    FILE *out = fopen("quiz.dat", "ab");
    fwrite(ob, sizeof(struct node), 1, out);
    fclose(out);
    printf("\nPROCESSING");
    for (int i = 0; i <= 5; i++)
    {
      fordelay(100000000);
      printf(".");
    }
    clr();

    cout << endl << "Congratulations!\nYou have successfully registered." << endl;
    getchar();
  }

  free(ob);

  start();
}

void login() // Login option
{
  int x, i;
  char ch;
  string s1,p;
  system("color FD");
  do
  {
    clr();

    ch = 'n';

    cout << "\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  LOGIN  \xB1\xB1\xB1\xB1\xB1\xB3\n\n";
    cout << "Enter username : " << endl;
    getline(cin,s1);
    cout << "Enter password : " << endl;

    i = 0;
    do
    {
      p[i] = getchar();
      i++;
      if ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122))
        printf("*");
    } while ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122));
    p[i - 1] = '\0';

    x = srch(s1, p);

    if (!x)
    {
      cout << "\ninvalid credentials\n";
      cout << "do you wish to try again?(y/n)\n";
      cin >> ch;
    }

    else
    {
      cout << "\nLOADING";
      for (int i = 0; i <= 5; i++)
      {
        fordelay(100000000);
        printf(".");
      }
    //   menu();
    }

  } while (ch == 'y');

  start();
}


int srch(string u, string p)
{
  int f = 0;

  FILE *in = fopen("quiz.dat", "rb");
  fseek(in, 0, SEEK_SET);

  struct node *tmp = (struct node *)malloc(sizeof(struct node));

  while (fread(tmp, sizeof(struct node), 1, in))
  {
    if (u == tmp->uname && p == tmp->pass)
    {
      ob = (struct node *)malloc(sizeof(struct node));
      ob = tmp;
      {
        f = 1;
        break;
      }
    }
  }

  fclose(in);

  return f;
}
void start()
{
    int op, x;
    system("color 09");
    do
    {
        bool b = true;
        clr();
        cout << "\t\t\t\t\t\xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\       QUIZWIZ        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3\n\n";
        cout << "\t\t\t\t\t1.Login\n\t\t\t\t\t2.Signup\n\t\t\t\t\t3.Exit\n\n";
        cout << "\t\t\t\t\tEnter option\n\t\t\t\t\t";
        cin >> op;

        switch (op)
        {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        case 3:
            exit(0);
        // case 4:
        //     admin();
        //     break;
        default:
            cout << "Wrong input \n try again";
            b = false;
        }

    } while (!x);
}
int main()
{
    start();
    return 0;
}

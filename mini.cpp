#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>
#include <time.h>

#define nl "\n"
#define sp " "
#define ll long long int
#define mod (ll)(1e9 + 7)
#define underline "\033[4m"
using namespace std;

//Functions => Function Prototypes
void main_function();
void creating();
void bubble_sort();
void display();
void menue();
void inserting();
void deleting();
void searching();
void displaying();
void undisplay();
ll Lower_bound(int num);

//Animation => Function Prototypes
void red();
void yellow();
void green();
void cyan();
void blue();
void white();
void reset();
void ultrabox(int x, int y, int len1, int len2);
void box(int x, int y, int len1, int len2);
void gotoxy(int x, int y);

//Variables
const int sz = 100000;
int arr[sz] = {0};
int n = 0;

int main()
{

    main_function();

    return 0;
}

// main_function
void main_function()
{
    green();
    box(5, 1, 80, 15);
    yellow();
    gotoxy(30, 2);
    cout << underline << "Welcome to the Project" << nl;
    reset();
    gotoxy(20,5);
    cout << "Enter The Size Of The Array : ";
    cin >> n;
    getchar();
    gotoxy(20, 10);
    cout << "Press Enter To Create An Array : ";
    getchar();
    creating();
    system("cls");
}

// menu te 4ta option thakbe: Insert, Delete, Search, Display, Exit

// inserting
void inserting()
{
    box(5, 1, 70, 20);
    display();
    yellow();
    gotoxy(37, 3);
    cout << underline << "Inserting";
    reset();
    cyan();
    gotoxy(19, 8);
    cout << "Enter a number :    ";
    ll num;
    cin >> num;
    n = n + 1;
    arr[n] = num;
    int rt = n - 1;

    while (rt >= 1 && arr[rt] > num)
    {
        arr[rt + 1] = arr[rt];
        rt--;
    }
    arr[rt + 1] = num;
    display();
    gotoxy(19, 11);
    cout << "Number Inserted at " << rt+1 << " Successfully !!!  ";
    gotoxy(20, 18);
    white();
    cout << "Press Enter To Return Homepage :   ";
    getchar();
    getchar();
    menue();
}

void deleting()
{
    box(5, 1, 70, 20);
    display();
    yellow();
    gotoxy(37, 3);
    cout << underline << "Deleting";
    reset();
    cyan();
    gotoxy(14, 8);
    cout << "Enter a number to delete :    ";
    ll num;
    cin >> num;
    //cout << num << nl;
    int pos = Lower_bound(num);
    //cout << arr[pos] << sp << pos << nl;
    if (arr[pos] == num)
    {
        gotoxy(19, 11);
        n = n - 1;
        for(int i = pos; i <= n; i++)
        {
            arr[i] = arr[i+1];
        }
        display();
        gotoxy(19, 15);
        cout << "Number Deleted Successfully From Position " << pos << " !!!  ";
    }
    else
    {
        gotoxy(19, 11);
        cout << "Number Not Found !!!  ";
    }
    gotoxy(20, 18);
    white();
    cout << "Press Enter To Return Homepage :   ";
    getchar();
    getchar();
    menue();
}

void searching()
{
    box(5, 1, 80, 20);
    display();
    yellow();
    gotoxy(37, 3);
    cout << underline << "Searching";
    reset();
    cyan();
    gotoxy(14, 8);
    cout << "Enter a number to find :    ";
    ll num;
    cin >> num;

    int pos = Lower_bound(num);
    if (arr[pos] == num)
    {
        gotoxy(19,11);
        cout << "Number Found at Index " << pos << " Successfully !!!      ";
    }
    else
    {
        gotoxy(19, 11);
        cout << "Number Not Found !!!  ";
    }
    gotoxy(20, 18);
    white();
    cout << "Press Enter To Return Homepage :   ";
    getchar();
    getchar();
    menue();
}

void displaying()
{
    int i, j = 0;
    box(5, 1, 85, 25);
    yellow();
    gotoxy(30, 2);
    cout << underline << "Displaying" << nl;
    reset();
    blue();
    gotoxy(15, 4);
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << sp;
        if (i % 10 == 0)
        {
            j++;
            cout << nl;
            gotoxy(15, 4 + j);
        }
    }
    gotoxy(15, 4 + j+2);
    white();
    cout << "Press Enter To Return Homepage :   ";
    getchar();
    //getchar();
    menue();

}

// LowerBound Binary Search
ll Lower_bound(int num)
{
    ll i, j, mid;
    ll hi, lo;
    lo = 0;
    hi = n;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        //l < x && hi >= x
        if (arr[mid] >= num)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

// menu
void menue()
{
    box(5, 1, 70, 20);
    display(); // Latest change
    yellow();
    gotoxy(15 + 22, 3);
    cout << underline << "Menu Box";
    reset();
    green();
    gotoxy(7, 5);
    cout << "Select Option && Press Enter:";
    blue();
    gotoxy(18, 7);
    cout << "-->";
    int menu_item = 0, run, pos = 7;
    bool ok = true;

    while (ok)
    {
        green();
        gotoxy(22, 7);
        cout << "1. Insert";
        gotoxy(22, 8);
        cout << "2. Delete";
        gotoxy(22, 9);
        cout << "3. Display";
        gotoxy(22, 10);
        cout << "4. Searching\n";
        gotoxy(22,11);
        cout << "5. Exit\n";
        blue();
        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN))
        {
            if (pos == 11)
            {
                gotoxy(18, pos);
                cout << "   ";

                pos = 6;
                pos++;
                gotoxy(18, pos);
                cout << "-->";
                menu_item = 0;
                continue;
            }
            else
            {
                gotoxy(18, pos);
                cout << "   ";
                pos++;
                gotoxy(18, pos);
                cout << "-->";
                menu_item++;
                continue;
            }
        }
        if (GetAsyncKeyState(VK_UP))
        {
            if (pos == 7)
            {
                gotoxy(18, pos);
                cout << "   ";
                pos = 11;
                gotoxy(18, pos);
                cout << "-->";
                menu_item = 4;
                continue;
            }
            else
            {
                gotoxy(18, pos);
                cout << "   ";
                pos--;
                gotoxy(18, pos);
                cout << "-->";
                menu_item--;
                continue;
            }
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            //cout << menu_item << nl;
            reset();
            ok = false;
            switch (menu_item)
            {
            case 0:
                inserting();
                return;
            case 1:
                deleting();
                return;
            case 2:
                displaying();
                return;
            case 3:
                searching();
                return;
            default:
                return;
            }
        }
        getchar();
        break;
    }

    getchar();
}
// creating
void creating()
{
    int i;
    time_t t;
    srand((unsigned)time(&t));
    for (i = 1; i <= n; i++)
    {
        arr[i] = rand() % mod;
    }

    undisplay();

    bubble_sort();

    display();
    white();
    cout << "Press Enter to Access Menu : ";
    reset();
    getchar();
    menue();
}
// Display Unsorted Array
void undisplay()
{
    int i, j = 0;
    box(5, 1, 70, 30);
    yellow();
    gotoxy(30, 2);
    cout << underline << "The Array ( Without Sort )" << nl;
    reset();
    blue();
    gotoxy(15, 4);
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << sp;
        if (i % 10 == 0)
        {
            j++;
            cout << nl;
            gotoxy(15, 4 + j);
        }
    }
    gotoxy(15, 4 + j + 1);
    reset();

    cout << "Press Enter to Show Sorted Array : ";
    getchar();
}
// display sorted Array
void display()
{
    int i, j = 0;
    ultrabox(80, 1, 70, 30);
    yellow();
    gotoxy(100, 2);
    cout << underline << "The Sorted Array" << nl;
    reset();
    blue();
    gotoxy(85, 4);
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << sp;
        if (i % 10 == 0)
        {
            j++;
            cout << nl;
            gotoxy(85, 4 + j);
        }
    }
    gotoxy(85, 4 + j + 1);
    reset();
}
// bubble sort
void bubble_sort()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Animation
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//SetUp Box
void box(int x, int y, int len1, int len2)
{
    system("cls");
    int i, j;

    for (i = 0; i <= len1 + 1; i++)
    {
        gotoxy(x + i, y);
        if (i == 0)
            printf("%c", 218);
        else if (i == len1 + 1)
            printf("%c\n", 191);
        else
            printf("%c", 196);
    }

    for (i = 1; i <= len2; i++)
    {
        gotoxy(x, y + i);
        printf("%c", 179);
        for (j = 1; j <= len1; j++)
            printf(" ");
        printf("%c\n", 179);
    }

    for (i = 0; i <= len1 + 1; i++)
    {
        gotoxy(x + i, y + len2);
        if (i == 0)
            printf("%c", 192);
        else if (i == len1 + 1)
            printf("%c\n", 217);
        else
            printf("%c", 196);
    }
    gotoxy(0, 2);
}
void ultrabox(int x, int y, int len1, int len2)
{

    int i, j;

    for (i = 0; i <= len1 + 1; i++)
    {
        gotoxy(x + i, y);
        if (i == 0)
            printf("%c", 218);
        else if (i == len1 + 1)
            printf("%c\n", 191);
        else
            printf("%c", 196);
    }

    for (i = 1; i <= len2; i++)
    {
        gotoxy(x, y + i);
        printf("%c", 179);
        for (j = 1; j <= len1; j++)
            printf(" ");
        printf("%c\n", 179);
    }

    for (i = 0; i <= len1 + 1; i++)
    {
        gotoxy(x + i, y + len2);
        if (i == 0)
            printf("%c", 192);
        else if (i == len1 + 1)
            printf("%c\n", 217);
        else
            printf("%c", 196);
    }
    gotoxy(0, 2);
}
//color
void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[0;33m");
}
void blue()
{
    printf("\033[1;34m");
}
void cyan()
{
    printf("\033[0;36m");
}
void white()
{
    printf("\033[1;37m");
}
void green()
{
    printf("\033[1;32m");
}
void reset()
{
    printf("\033[0m");
}

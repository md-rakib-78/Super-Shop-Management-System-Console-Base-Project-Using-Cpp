#include <iostream>
#include <string>
using namespace std;

struct pi
{

    string name;
    int code;
    int price;
    string stock;
};

struct ei
{

    string name;
    int id;
    int nid;
    int phoneNumber;
    string email;
    string homeTown;
    string jobPost;
};

struct pi product_info[100];
struct ei employee_info[100];
int total_product = 0;
int total_employee = 0;

////////////////////////////////////////////////  PART OF PRODUCT \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


/// PRODUCT INSERT
int addProduct()
{

    if (total_product == 100)
    {
        cout << "No space!!";
    }

    struct pi pro_i;

    cout << "Product name  : ";
    cin.ignore();
    getline(cin, pro_i.name);
    for (auto &x : pro_i.name)
    {
        x = tolower(x);
    }
    cout << "Product code  : ";
    cin >> pro_i.code;
    cout << "Product price : ";
    cin >> pro_i.price;
    cout << "Product Status: ";
    cin.ignore();
    getline(cin, pro_i.stock);

    product_info[total_product++] = pro_i;

    cout << "\nProduct Add Successfully !!!\n";

    return 0;
}

/// Update Product Information

int upgraidInfo(int value)
{

    int count = 0;

    if (total_product == 0)
    {
        cout << " Sorry!! First add product\n";
    }

    else
    {
        for (int i = 0; i < total_product; i++)
        {

            if (product_info[i].code == value)
            {
                cout << "\n";
                count = count + 1;
                cout << " Product Name        : " << product_info[i].name << "\n";
                cout << " Re-edit Product Name: ";
                cin.ignore();
                getline(cin, product_info[i].name);
                cout << " Product Code        : " << product_info[i].code << "\n";
                cout << " Re-edit Product Code: ";
                cin >> product_info[i].code;
                cout << " Product Price       : " << product_info[i].price << "\n";
                cout << " Re-edit Product Price: ";
                cin >> product_info[i].price;
                cout << " Product Status      : " << product_info[i].stock << "\n";
                cout << " Re-edit Product Name: ";
                cin.ignore();
                getline(cin, product_info[i].stock);
                cout << "\n"
                     << "Product Info update successfully!!!!" << "\n";

                return 0;
            }
        }
    }
    cout << "\n Sorry this product code invalid ! please insert correct code.\n\n";
}

/// Delete Product Info
void deleteProduct(string nameP)
{
    int index = 0;
    if (total_product == 0)
    {
        cout << "No product!!\n";
    }

    else
    {
        for (int i = 0; i < total_product; i++)
        {
            if (product_info[i].name == nameP)
            {
                index = i;
            }
        }

        for (int j = index; j < total_product; j++)
        {
            product_info[j] = product_info[j + 1];
        }
        cout << "\nProduct Information Successfully Deleted !!!\n";
        total_product--;
    }
}

/// Searching Product
void searchingProduct(string nameProduct)
{

    int count = 0;

    if (total_product == 0)
    {
        cout << " Sorry!! First add product\n";
    }

    else
    {
        for (int i = 0; i < total_product; i++)
        {

            if (product_info[i].name == nameProduct)
            {
                cout << "Found product!!\n\n";
                count = count + 1;
                cout << " Product Name   : " << product_info[i].name << "\n";
                cout << " Product Code   : " << product_info[i].code << "\n";
                cout << " Product Price  : " << product_info[i].price << "\n";
                cout << " Product Status : " << product_info[i].stock << "\n";
            }
        }
        if (count == 0)
        {
            cout << "\n Sorry This Product out of stock!!\n";
        }
    }
}

/// Display Product
void displayAllProduct()
{
    if (total_product == 0)
    {
        cout << " Sorry!!! No product Adding\n";
    }
    else
    {

        for (int i = 0; i < total_product; i++)
        {
            cout << " \nProduct No. " << i + 1 << "\n\n";
            cout << " Product Name   : " << product_info[i].name << "\n";
            cout << " Product Code   : " << product_info[i].code << "\n";
            cout << " Product Price  : " << product_info[i].price << "\n";
            cout << " Product Status : " << product_info[i].stock << "\n";
        }
    }
}

////////////////////////////////////////////////  END    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


////////////////////////////////////////// EMPLOYEE PART START  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/// EMPLOYEE INFO ADDING
int addEmployee()
{

    if (total_employee == 100)
    {
        cout << "No space!!";
    }

    struct ei emp_i;

    cout << "NAME         : ";
    cin.ignore();
    getline(cin, emp_i.name);
    cout << "ID           : ";
    cin >> emp_i.id;
    cout << "NID          : ";
    cin >> emp_i.nid;
    cout << "PHONE NUMBER : ";
    cin >> emp_i.phoneNumber;
    cout << "EMAIL        : ";
    cin.ignore();
    getline(cin, emp_i.email);

    cout << "HOME TOWN    : ";
    getline(cin, emp_i.homeTown);

    cout << "JOB POST     : ";
    getline(cin, emp_i.jobPost);

    employee_info[total_employee++] = emp_i;

    cout << "\nNew Employee Info Add Successfully !!!";
    return 0;
}

/// Employee Info Delete
void deleteEmployee(int id)
{
    int indexD = 0;
    if (total_employee == 0)
    {
        cout << "Not Found!!\n";
    }

    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (employee_info[i].id == id)
            {
                indexD = i;
            }
        }

        for (int j = indexD; j < 100; j++)
        {
            employee_info[j] = employee_info[j + 1];
        }
        cout << "\nEmployee Information Successfully Deleted !!!\n";
        total_employee--;
    }
}

/// Display All Employee Information
void displayAllEmployee()
{
    if (total_employee == 0)
    {
        cout << " Sorry!!! No Employee Adding\n";
    }
    else
    {

        for (int i = 0; i < total_employee; i++)
        {
            cout << " \nEmployee No. " << i + 1 << "\n";
            cout << "----------------\n";
            cout << " Employee Name      : " << employee_info[i].name << endl;
            cout << " Employee Id        : " << employee_info[i].id << endl;
            cout << " Employee Nid       : " << employee_info[i].nid << endl;
            cout << " Employee Phone no. : " << employee_info[i].phoneNumber << endl;
            cout << " Employee Email     : " << employee_info[i].email << endl;
            cout << " Employee Home Town : " << employee_info[i].homeTown << endl;
            cout << " Employee Position  : " << employee_info[i].jobPost << endl;
        }
    }
}

/// Searching Employee
void searchingEmployee(int id2)
{
    int count = 0;

    if (total_employee == 0)
    {
        cout << " Sorry!! First add employee info\n";
    }

    else
    {
        for (int i = 0; i < total_employee; i++)
        {

            if (employee_info[i].id == id2)
            {
                cout << "\n";
                cout << "Found Employee!!\n\n";
                count = count + 1;
                cout << " Employee Name      : " << employee_info[i].name << "\n";
                cout << " Employee Id        : " << employee_info[i].id << "\n";
                cout << " Employee Nid       : " << employee_info[i].nid << "\n";
                cout << " Employee Phone no. : " << employee_info[i].phoneNumber << "\n";
                cout << " Employee Email     : " << employee_info[i].email << "\n";
                cout << " Employee Home Town : " << employee_info[i].homeTown << "\n";
                cout << " Employee Position  : " << employee_info[i].jobPost << "\n";
            }
        }
        if (count == 0)
        {
            cout << "\n Sorry could not found!!\n";
        }
    }
}

// void

/// Main Function
int main()
{
    int choice1, choice2, choice3, choice4;

    do
    {
    mainMenu:
        system("CLS");

        cout << "\n -------------------------------------------\n";
        cout << "|        SUPER SHOP MANAGEMENT SYSTEM        |\n";
        cout << " -------------------------------------------\n";
        cout << "         i.   Product.\n";
        cout << "         ii.  Employee.\n";
        cout << "         iii. About us.\n";
        cout << "         iv.  Exit.\n";
        cout << "\n Please enter your choice: ";
        cin >> choice1;
        cout << "\n\n";

        switch (choice1)
        {
        case 1:

            do
            {
                string nameP;
                string nameProduct;
                int value;
                cout << "--------------------------------------------------------------\n";
                cout <<" PRODUCT INFO\n";
                cout << "--------------------------------------------------------------\n";
                cout << "  i.   Adding Product.\n";
                cout << "  ii.  Delete product.\n";
                cout << "  iii. Display All Product.\n";
                cout << "  iv.  Searching Product.\n";
                cout << "  v.   update Product Information.\n";
                cout << "  vi.  Back main menu.\n";
                cout << "\nEnter your choice :";
                cin >> choice2;
                cout << "\n";

                switch (choice2)
                {
                case 1:

                    addProduct();
                    cout << "--------------------------------------------------------------\n\n\n";
                    break;

                case 2:

                    cout << "Which product you delete? : ";
                    cin.ignore();
                    getline(cin, nameP);
                    deleteProduct(nameP);
                    cout << "\n\n";
                    break;

                case 3:

                    displayAllProduct();
                    cout << "\n\n";
                    break;
                case 4:

                    cout << "Search Product : ";
                    cin.ignore();
                    getline(cin, nameProduct);
                    for (auto &x : nameProduct)
                    {
                        x = tolower(x);
                    }
                    cout << "\n";
                    searchingProduct(nameProduct);
                    cout << "\n\n";
                    break;

                case 5:
                    cout << "Enter the product code for update info: ";
                    cin >> value;

                    upgraidInfo(value);

                    break;

                default:
                    cout << "wrong choice please try again!!\n";
                    break;
                }

            } while (choice2 != 6);

            break;

        case 2:

            do
            {
                int id, id2;
                cout << "\n--------------------------------------------------------------\n";
                cout << "EMPLOYEE INFO\n";
                cout << "--------------------------------------------------------------\n";
                cout << "  i.   Adding Employee Info.\n";
                cout << "  ii.  Delete Employee Info.\n";
                cout << "  iii. Display All Employee Info.\n";
                cout << "  iv.  Searching Employee.\n";
                cout << "  v.   Back main menu.\n";
                cout << "\nEnter your choice :";
                cin >> choice3;
                cout << "\n";

                switch (choice3)
                {
                case 1:

                    addEmployee();
                    cout << "\n\n";
                    break;

                case 2:

                    cout << "Enter Employee ID : ";
                    cin >> id;
                    deleteEmployee(id);

                    break;

                case 3:

                    displayAllEmployee();

                    break;
                case 4:

                    cout << "Enter Employee Id: ";
                    cin >> id2;
                    searchingEmployee(id2);
                    cout << "\n";
                    break;

                case 5:
                    break;

                default:
                    cout << "wrong choice please try again!!\n";
                    break;
                }

            } while (choice3 != 5);

            break;
        case 3:

            while (1)
            {
                cout << "\n--------------------------------------------------------------\n";
                cout << "ABOUT US\n";
                cout << "--------------------------------------------------------------\n";
                cout << "     i. Policy Adding\n";
                cout << "    ii. Policy Update\n";
                cout << "   iii. Policy Display\n";
                cout << "    iv. Exit\n\n";
                cout << "Enter your choice: ";
                cin >> choice4;

                switch (choice4)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    goto mainMenu;
                default:
                    cout << "Please try again and enter the right choice!!!";
                }
            }

            break;

        default:
            cout << "wrong choice please try again!!\n";
            break;
        }

    } while (choice1 != 4);
}

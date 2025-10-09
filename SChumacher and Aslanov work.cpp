///WELCOME TO SCHUMACHER AND ASLANOV'S PARTS SHOP///
///THE CODE CONSISTS OF 4 PARTS////////////////////
/// 1.STRUCTRES(PRODUCT,CUSTOMER INFO AND CAR INDO)
/// 2.FUNCTIONS(PRINTING THE INFO AND SAVING THE DATA INTO BINARY
/// 3.SUB-MENU DESIGN
/// 4.MAIN MENU DESIGN
///FOR 14.05.2025 IT IS WORKING AND ALL FEATURES ARE ENABLED
/// FEATURES:
/// SORTING THE CART,SAVING INTO BINARY,ADMINISTRATOR PANEL,
/// BROAD VARIETY OF PARTS,COMFORTABLE USER INTEFACE



///Basic libraries for this project ///
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

// Structures for customer, product, and car information
struct customer {
    string name;
    string surname;
    string address;
    string postal_code;
};

struct product {
    string pr_name;
    float price;
    int quantity = 1;  // Default quantity is 1
};

struct car {
    string brand;
    string model;
    string year;
};

// Global variables to store orders, current customer, and car details
vector<product> orders;
customer current_customer;
car user;

// Displays the contents of the cart with options to sort by price or name
void printClient(vector<product>& orders) {
    if (orders.empty()) {
        cout << "No products in the cart." << endl;
        return;
    }

    int sortChoice;
    cout << "How would you like to sort the cart?" << endl;
    cout << "1. By Price" << endl;
    cout << "2. By Name" << endl;
    cin >> sortChoice;

    if (sortChoice == 1) {
        sort(orders.begin(), orders.end(), [](const product& a, const product& b) {
            return a.price < b.price;
            });
    }
    else if (sortChoice == 2) {
        sort(orders.begin(), orders.end(), [](const product& a, const product& b) {
            return a.pr_name < b.pr_name;
            });
    }
    else {
        cout << "Invalid choice, displaying unsorted list." << endl;
    }

    cout << "----- CART CONTENTS -----" << endl;
    float grandTotal = 0;
    for (const auto& item : orders) {
        cout << "Product: " << item.pr_name << " - " << item.price << " €" << endl;
        grandTotal += item.price;
    }
    cout << "-------------------------" << endl;
    cout << "Total Amount: " << grandTotal << " €" << endl;
}

// Prints the current customer's registration information
void printCustomer(const customer& current_customer) {
    if (current_customer.name.empty()) {
        cout << "No customer signed up." << endl;
    }
    else {
        cout << "CUSTOMER #1 INFORMATION" << endl;
        cout << "Name: " << current_customer.name << endl;
        cout << "Surname: " << current_customer.surname << endl;
        cout << "Address: " << current_customer.address << endl;
        cout << "Postal Code: " << current_customer.postal_code << endl;
    }
}

// Prints the current car's information
void printCar(const car& user) {
    if (user.brand.empty()) {
        cout << "No car signed up." << endl;
    }
    else {
        cout << "Car info" << endl;
        cout << "Brand: " << user.brand << endl;
        cout << "Model: " << user.model << endl;
        cout << "Year: " << user.year << endl;
    }
}

// Saves customer, car, and product (order) data to a binary file
void saveToFile(const customer& cust, const car& vehicle, const vector<product>& items) {
    ofstream outFile("user_data.bin", ios::binary | ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    size_t length;

    // Save number of products in the order
    size_t count = items.size();
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

    // Save each product's name and price
    for (const auto& item : items) {
        length = item.pr_name.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(item.pr_name.c_str(), length);
        outFile.write(reinterpret_cast<const char*>(&item.price), sizeof(item.price));
    }

    // Save customer's personal details (name, surname, address, postal code)
    length = cust.name.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(cust.name.c_str(), length);

    length = cust.surname.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(cust.surname.c_str(), length);

    length = cust.address.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(cust.address.c_str(), length);

    length = cust.postal_code.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(cust.postal_code.c_str(), length);

    // Save car information (brand, model, year)
    length = vehicle.brand.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(vehicle.brand.c_str(), length);

    length = vehicle.model.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(vehicle.model.c_str(), length);

    length = vehicle.year.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(vehicle.year.c_str(), length);

    outFile.close();
    cout << "Data saved successfully to user_data.bin." << endl;
}

// Tuning submenu: manage engine, wheels, and exterior modifications
void sub_sub_tuning(vector<product>& selected) {
    int choice;
    do {
        // Display tuning categories
        map<int, string> categoryNames = {
            {1, "Engine"},
            {2, "Wheels"},
            {3, "Exterior"},
            {4, "Back"}
        };

        for (const auto& category : categoryNames) {
            cout << "---" << category.first << ".--- " << category.second << "---" << endl;
        }
        cout << "Please, select the category:" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Engine tuning options: Chips, Turbo, and Exhaust modifications
            map<string, map<string, float>> engine_tuning = {
                {"Chips", {{"Stage_1", 165}, {"Stage_2", 110}, {"Stage_3", 195}, {"Stage_eco", 60}}},
                {"Turbo", {{"Single_Turbo", 500}, {"Twin_Turbo", 1000}, {"Quad_Turbo", 2000}}},
                {"Exhaust", {{"Bosal", 161.70}, {"Walker", 96.40}, {"Akropovic", 1430}}}
            };

            cout << "Choose the part category:" << endl;
            int category_choice = 1;
            for (const auto& category : engine_tuning) {
                cout << category_choice++ << ". " << category.first << endl;
            }

            int choice0;
            cout << "Choose the part your car needs:" << endl;
            cin >> choice0;

            switch (choice0) {
            case 1: {
                cout << "Available chips:" << endl;
                for (const auto& option : engine_tuning["Chips"]) {
                    cout << "---" << option.first << "---" << option.second << " euro." << endl;
                }
                string choice1;
                cin >> choice1;
                if (engine_tuning["Chips"].find(choice1) != engine_tuning["Chips"].end()) {
                    cout << "You selected " << choice1 << " for €" << engine_tuning["Chips"][choice1] << endl;
                    product selected;
                    selected.pr_name = choice1;
                    selected.price = engine_tuning["Chips"][choice1];
                    orders.push_back(selected);
                }
                else {
                    cout << "Product not found. Please try again with a valid option." << endl;
                }
                break;
            }
            case 2: {
                cout << "Available exhausts:" << endl;
                for (const auto& option : engine_tuning["Exhaust"]) {
                    cout << "---" << option.first << "---" << option.second << " euro." << endl;
                }
                string choice1;
                cin >> choice1;
                if (engine_tuning["Exhaust"].find(choice1) != engine_tuning["Exhaust"].end()) {
                    cout << "You selected " << choice1 << " for €" << engine_tuning["Exhaust"][choice1] << endl;
                    product selected;
                    selected.pr_name = choice1;
                    selected.price = engine_tuning["Exhaust"][choice1];
                    orders.push_back(selected);
                }
                else {
                    cout << "Product not found. Please try again with a valid option." << endl;
                }
                break;
            }
            case 3: {
                cout << "Available turbos:" << endl;
                for (const auto& option : engine_tuning["Turbo"]) {
                    cout << "---" << option.first << "---" << option.second << " euro." << endl;
                }
                string choice1;
                cin >> choice1;
                if (engine_tuning["Turbo"].find(choice1) != engine_tuning["Turbo"].end()) {
                    cout << "You selected " << choice1 << " for €" << engine_tuning["Turbo"][choice1] << endl;
                    product selected;
                    selected.pr_name = choice1;
                    selected.price = engine_tuning["Turbo"][choice1];
                    orders.push_back(selected);
                }
                else {
                    cout << "Product not found. Please try again with a valid option." << endl;
                }
                break;
            }
            default: {
                return;
            }
            }
            break;
        }
        case 2: {
            // Options for wheels modifications
            map<string, float> wheel_parts = {
                {"Slicks", 300},
                {"Offroad", 250},
                {"Drift", 280}
            };

            cout << "Available wheels:" << endl;
            for (const auto& option : wheel_parts) {
                cout << "---" << option.first << "---" << option.second << " euro." << endl;
            }

            string choice1;
            cin >> choice1;
            if (wheel_parts.find(choice1) != wheel_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = wheel_parts[choice1];
                orders.push_back(selected);
            }
            else {
                cout << "Product not found." << endl;
            }
            break;
        }
        case 3: {
            // Options for exterior modifications
            map<string, float> exterior_parts = {
                {"Livery", 100}, {"Stickers", 20}, {"Neon_Red", 150}, {"Neon_Blue", 150},
                {"Neon_Green", 150}, {"Neon_Yellow", 150}, {"Neon_Purple", 150}, {"Neon_White", 150},
                {"Parachute", 400}, {"StradaCops", 350}, {"Painting", 200}, {"Spoilers", 220},
                {"Body_Clean", 180}, {"Body_Drift", 190}, {"Body_Street", 210}, {"Body_Hard", 250}
            };

            cout << "Available exterior tuning parts:" << endl;
            for (const auto& option : exterior_parts) {
                cout << "---" << option.first << "---" << option.second << " euro." << endl;
            }

            string choice1;
            cin >> choice1;
            if (exterior_parts.find(choice1) != exterior_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = exterior_parts[choice1];
                orders.push_back(selected);
            }
            else {
                cout << "Product not found." << endl;
            }
            break;
        }
        case 4:
            return;
        }
    } while (choice != 4);
}

// Spare parts submenu: selecting parts from various spare parts categories
void sub_sub_spare(vector<product>& selected) {
    int choice;
    do {
        cout << "Spare Parts Categories:" << endl;
        cout << "1. Electric Parts" << endl;
        cout << "2. Engine Parts" << endl;
        cout << "3. Electric Car Parts" << endl;
        cout << "4. Go Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            map<string, float> electric_parts = {
                {"Head_Lights", 120},
                {"Back_Lights", 110},
                {"Accumulator", 150}
            };
            cout << "Electric Parts:" << endl;
            for (auto& part : electric_parts) {
                cout << "---" << part.first << "---" << part.second << " euro." << endl;
            }
            string choice1;
            cin >> choice1;
            if (electric_parts.find(choice1) != electric_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = electric_parts[choice1];
                orders.push_back(selected);
            }
            break;
        }
        case 2: {
            map<string, float> engine_parts = {
                {"Filters", 75},
                {"Sparks", 45},
                {"Oil_Filter", 35},
                {"Fuel_Pump", 90},
                {"Timing_Belt", 130}
            };
            cout << "Engine Parts:" << endl;
            for (auto& part : engine_parts) {
                cout << "---" << part.first << "---" << part.second << " euro." << endl;
            }
            string choice1;
            cin >> choice1;
            if (engine_parts.find(choice1) != engine_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = engine_parts[choice1];
                orders.push_back(selected);
            }
            break;
        }
        case 3: {
            map<string, float> ev_parts = {
                {"Battery", 1000},
                {"Charger", 400}
            };
            cout << "Electric Vehicle Parts:" << endl;
            for (auto& part : ev_parts) {
                cout << "---" << part.first << "---" << part.second << " euro." << endl;
            }
            string choice1;
            cin >> choice1;
            if (ev_parts.find(choice1) != ev_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = ev_parts[choice1];
                orders.push_back(selected);
            }
            break;
        }
        case 4:
            return;
        }
    } while (choice != 4);
}

// Body parts submenu: selecting main body and glass parts
void sub_sub_body(vector<product>& selected) {
    int choice;
    do {
        cout << "Body Parts Categories:" << endl;
        cout << "1. Main Body Parts (Bumpers, Hood, Roof, etc.)" << endl;
        cout << "2. Glass Parts" << endl;
        cout << "3. Go Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            map<string, float> body_main = {
                {"Bumper", 150},
                {"Hood", 180},
                {"Roof", 170},
                {"Bagagge", 140}
            };
            cout << "Body Main Parts:" << endl;
            for (auto& part : body_main) {
                cout << "---" << part.first << "---" << part.second << " euro." << endl;
            }
            string choice1;
            cin >> choice1;
            if (body_main.find(choice1) != body_main.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = body_main[choice1];
                orders.push_back(selected);
            }
            break;
        }
        case 2: {
            map<string, float> glass_parts = {
                {"Front_Window", 130},
                {"Back_Window", 125},
                {"Side_Window", 115}
            };
            cout << "Glass Parts:" << endl;
            for (auto& part : glass_parts) {
                cout << "---" << part.first << "---" << part.second << " euro." << endl;
            }
            string choice1;
            cin >> choice1;
            if (glass_parts.find(choice1) != glass_parts.end()) {
                product selected;
                selected.pr_name = choice1;
                selected.price = glass_parts[choice1];
                orders.push_back(selected);
            }
            break;
        }
        case 3:
            return;
        }
    } while (choice != 3);
}

// Submenu for ordering: allows navigating different categories and viewing the cart
void submenu_order() {
    int choice;
    do {
        cout << "-----CATEGORIES----------" << endl;
        cout << "---1.--------Tuning-------" << endl;
        cout << "---2.------Body parts-----" << endl;
        cout << "---3.-----Spare Parts-----" << endl;
        cout << "---4.------Show Cart------" << endl;
        cout << "---5.---Go back to menu---" << endl;
        cout << "Choice:" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            sub_sub_tuning(orders);
            break;
        case 2:
            sub_sub_body(orders);
            break;
        case 3:
            sub_sub_spare(orders);
            break;
        case 4:
            // Show cart using the printClient function
            printClient(orders);
            break;
        case 5:
            cout << "Driving back to menu....." << endl;
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 5);
}

// Main menu for the application: handles sign-up, ordering, saving data, and administrator functions
void menu() {
    int choice;
    do {
        cout << "SCHUMACHER AND ASLANOV'S PART SHOP" << endl;
        cout << "---1.-----------Sign up ----------" << endl;
        cout << "---2.--------Order Parts----------" << endl;
        cout << "---3.---------Save Info-----------" << endl;
        cout << "---4.------Close the program------" << endl;
        cout << "---5.------Help and Contacts------" << endl;
        cout << "---6.-----Administrator Panel-----" << endl;
        cout << "Choice:";
        cin >> choice;
        switch (choice) {
        case 2:
            submenu_order();
            break;
        case 6: {
            string username, password, upassword;
            cout << "Enter your username:" << endl;
            cin >> username;
            map<string, char> Users = {
                {"Courier", 0},
                {"Administrator", 1}
            };

            if (Users.find(username) != Users.end()) {
                // Assign default passwords based on the user role
                switch (Users[username]) {
                case 0:
                    password = "IAmCourier123";
                    break;
                case 1:
                    password = "IAmAdmin123";
                    break;
                }

                cout << "Please enter your password:" << endl;
                cin >> upassword;

                if (upassword == password) {
                    printCustomer(current_customer);
                    printCar(user);
                    if (Users[username] == 1) {
                        cout << "------ALL ORDERS-------" << endl;
                        // Print the entire cart contents for the administrator
                        printClient(orders);
                    }
                }
                else {
                    cout << "Incorrect password!" << endl;
                }
            }
            else {
                cout << "User not found." << endl;
            }
            break;
        }
        case 3:
            saveToFile(current_customer, user, orders);
            break;
        case 4:
            cout << "See you! Bye!" << endl;
            break;
        case 5:
            cout << "To use program, you need to go in //Sign up// section and fill up your credentials" << endl;
            cout << "Then, in ///Order Parts/// section you can add some parts to your cart.If it is needed, in ///Show the Cart// section";
            cout << "you can see parts you add and want to buy.And here is the finish line! ";
            cout << "If you need additional help,feel free to ask!" << endl << "E-mail:ali.aslanov.2007@gmail.com" << endl << "Telehone number:XXXXXXXXXXXX" << endl << "With love for cars and for our customers from support team!" << endl;
            break;
        case 1: {
            // Sign up: gather customer and car information
            cout << "--------SIGN UP---------" << endl;
            cout << "Enter your name:" << endl;
            cin >> current_customer.name;
            cout << "Enter your surname:" << endl;
            cin >> current_customer.surname;
            cout << "Enter your address:" << endl;
            cin >> current_customer.address;
            cout << "Enter your postal code:" << endl;
            cin >> current_customer.postal_code;
            cout << "You signed up successfully!" << endl;

            cout << "-----CAR INFO -------" << endl;
            cout << "Brand of vehicle:" << endl;
            cin >> user.brand;
            cout << "Model of vehicle:" << endl;
            cin >> user.model;
            cout << "Year of vehicle:" << endl;
            cin >> user.year;
            break;
        }
        default:
            cout << "Wrong choice, try again!" << endl;
            break;
        }
    } while (choice != 5);
}

// Entry point of the program
int main() {
    menu();
    return 0;
}

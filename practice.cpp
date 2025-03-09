#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <sstream>

using namespace std;

void clear_screen(){
    system("cls");
}

class car {
    private:
        string name;
        string model;
        string color;
        int year;
        int price;
        int id;
        int quantity;

    public:

        void setCar(string name, string model, string color, int year, int price, int id, int quantity) {
            this->name = name;
            this->model = model;
            this->color = color;
            this->year = year;
            this->price = price;
            this->id = id;
            this->quantity = quantity; // Use the class member variable.
        }

        void getCar() {
            cout << "Name: " << name << endl;
            cout << "Model: " << model << endl;
            cout << "Color: " << color << endl;
            cout << "Year: " << year << endl;
            cout << "Price: " << price << endl;
            cout << "ID: " << id << endl;
            cout << "Quantity: " << quantity << endl;
        }

        string getName() {
            return name;
        }

        string getModel() {
            return model;
        }

        string getColor() {
            return color;
        }

        int getYear() {
            return year;
        }

        int getPrice() {
            return price;
        }

        int getId() {
            return id;
        }

        void setQuantity(int q) {
            quantity = q;
        }
        

        int getQuantity() {
            return quantity;
        }
};

class customer{
    private:
        string name;
        string address;
        string phone;
        int id;

    public:

        void setCustomer(string name, string address, string phone, int id) {
            this->name = name;
            this->address = address;
            this->phone = phone;
            this->id = id;
        }

        void getCustomer() {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "ID: " << id << endl;
        }

        string getName() {
            return name;
        }

        string getAddress() {
            return address;
        }

        string getPhone() {
            return phone;
        }

        int getId() {
            return id;
        }
};

// Define the RentalTransaction structure
struct RentalTransaction {
    int customer_id;
    int car_id;
    string action;  // Rented or Returned
};

class rental_system{
    private:
        vector<car> cars;
        vector<customer> customers;

        void safe_to_file(){
            ofstream file;
            file.open("cars.txt");
            for(int i = 0; i < cars.size(); i++){
                file << cars[i].getName() << endl;
                file << cars[i].getModel() << endl;
                file << cars[i].getColor() << endl;
                file << cars[i].getYear() << endl;
                file << cars[i].getPrice() << endl;
                file << cars[i].getId() << endl;
                file << cars[i].getQuantity() << endl;
            }
            file.close();
        }

        void load_from_file(){
            ifstream file("cars.txt");
            if (!file) {
                cout << "Error: Could not open file!" << endl;
                return;
            }
        
            string name, model, color;
            int year, price, id, quantity;
        
            while (getline(file, name)) {  // Read name (1st line)
                getline(file, model);      // Read model (2nd line)
                getline(file, color);      // Read color (3rd line)
                file >> year >> price >> id >> quantity; // Read remaining integers (4th, 5th, 6th, 7th line)
                file.ignore();  // Ignore the newline character after reading numbers
        
                car c;
                c.setCar(name, model, color, year, price, id, quantity);
                cars.push_back(c);
            }
        
            file.close();
        }
        

        void save_customers_in_file(){
            ofstream file;
            file.open("customers.txt");
            for(int i = 0; i < customers.size(); i++){
                file << customers[i].getName() << endl;
                file << customers[i].getAddress() << endl;
                file << customers[i].getPhone() << endl;
                file << customers[i].getId() << endl;
            }
            file.close();
        }

        void load_customers_from_file(){
            ifstream file;
            file.open("customers.txt");
            string name, address, phone;
            int id;
        
            // Read customer data line by line
            while (getline(file, name)) {
                getline(file, address);    // Read the address line
                getline(file, phone);      // Read the phone number line
                file >> id;                // Read the ID number
                file.ignore();             // Ignore the newline character after reading the ID
                
                // Create a customer object and add it to the customers vector
                customer c;
                c.setCustomer(name, address, phone, id);
                customers.push_back(c);
            }
            file.close();
        }
        

    public:
    
            rental_system(){
                load_from_file();
                load_customers_from_file();
            }
    
            void add_car(string name, string model, string color, int year, int price, int id, int quantity){
                // Check if the car ID already exists
                for (int i = 0; i < cars.size(); i++) {
                    if (cars[i].getId() == id) {
                        cout << "Error: Car with ID " << id << " already exists!" << endl;
                        return; // Exit the function without adding the car
                    }
                }
            
                // If no duplicate ID is found, add the new car
                car c;
                c.setCar(name, model, color, year, price, id, quantity);
                cars.push_back(c);
                safe_to_file();
                cout << "Car added successfully!" << endl;
            }
            
    
            void add_customer(string name, string address, string phone, int id){
                // Check if the customer ID already exists
                for (int i = 0; i < customers.size(); i++) {
                    if (customers[i].getId() == id) {
                        cout << "Error: Customer with ID " << id << " already exists!" << endl;
                        return; // Exit the function without adding the customer
                    }
                }
            
                // If no duplicate ID is found, add the new customer
                customer c;
                c.setCustomer(name, address, phone, id);
                customers.push_back(c);
                save_customers_in_file();
                cout << "Customer added successfully!" << endl;
            }
            
    
            void show_cars(){
                for(int i = 0; i < cars.size(); i++){
                    cars[i].getCar();
                    cout << endl;
                }
            }
    
            void show_customers(){
                for(int i = 0; i < customers.size(); i++){
                    customers[i].getCustomer();
                    cout << endl;
                }
            }
    
            void rent_car(int car_id, int customer_id) {
                for (int i = 0; i < cars.size(); i++) {
                    if (cars[i].getId() == car_id) {  // Check if the car exists
                        for (int j = 0; j < customers.size(); j++) {
                            if (customers[j].getId() == customer_id) {  // Check if the customer exists
                                if (cars[i].getQuantity() > 0) {  // Check if the car is available
                                    cout << "Car rented successfully!" << endl;
                                    cars[i].setQuantity(cars[i].getQuantity() - 1);  // Decrease the quantity of available cars
                                    safe_to_file();  // Save updated inventory
                                    save_rental_transaction(car_id, customer_id, "Rented");  // Log the rental transaction
                                    return;
                                } else {
                                    cout << "Car is out of stock!" << endl;
                                    return;
                                }
                            }
                        }
                        cout << "Customer not found!" << endl;
                        return;
                    }
                }
                cout << "Car not found!" << endl;
            }
            
            
            void return_car(int car_id, int customer_id) {
                ifstream rentalFile("rented_cars.txt");
                ofstream tempFile("temp.txt");
                bool found = false;
            
                if (!rentalFile || !tempFile) {
                    cout << "Error: Unable to open rental records!" << endl;
                    return;
                }
            
                string line;
                while (getline(rentalFile, line)) {
                    int rentedCarId, rentedCustomerId;
                    char action[10];
            
                    sscanf(line.c_str(), "Customer ID: %d | Car ID: %d | Action: %s", &rentedCustomerId, &rentedCarId, action);
            
                    if (rentedCarId == car_id && rentedCustomerId == customer_id && string(action) == "Rented") {
                        found = true;  // Valid rental found
                    } else {
                        tempFile << line << endl;  // Keep other transactions
                    }
                }
            
                rentalFile.close();
                tempFile.close();
            
                if (found) {
                    for (int i = 0; i < cars.size(); i++) {
                        if (cars[i].getId() == car_id) {
                            cars[i].setQuantity(cars[i].getQuantity() + 1);
                            cout << "Car returned successfully!" << endl;
                            safe_to_file();
                            save_rental_transaction(car_id, customer_id, "Returned");
            
                            remove("rented_cars.txt");
                            rename("temp.txt", "rented_cars.txt");
                            return;
                        }
                    }
                    cout << "Error: Car not found in inventory!" << endl;
                } else {
                    cout << "Error: This customer did not rent this car!" << endl;
                }
            }
            

            void save_rental_transaction(int car_id, int customer_id, string action) {
                ofstream file("rented_cars.txt", ios::app);  // Append mode
                if (!file) {
                    cout << "Error: Unable to open rental file!" << endl;
                    return;
                }
                file << "Customer ID: " << customer_id << " | Car ID: " << car_id << " | Action: " << action << endl;
                file.close();
            }

            void load_rental_transactions() {
                ifstream file("rented_cars.txt");  // Open the rental records file
                if (!file) {
                    cout << "Error: Unable to open rental file!" << endl;
                    return;
                }
            
                string line;
                vector<RentalTransaction> transactions;  // Vector to hold all rental transactions
            
                while (getline(file, line)) {
                    RentalTransaction transaction;
                    stringstream ss(line);
                    string temp;
            
                    // Extract Customer ID
                    getline(ss, temp, ':');
                    ss >> transaction.customer_id;
                    getline(ss, temp, '|');
            
                    // Extract Car ID
                    getline(ss, temp, ':');
                    ss >> transaction.car_id;
                    getline(ss, temp, '|');
            
                    // Extract Action
                    getline(ss, temp, ':');
                    getline(ss, transaction.action);
            
                    // Store the transaction in the vector
                    transactions.push_back(transaction);
                }
            
                file.close();
            
                // Display loaded rental transactions
                cout << "Loaded rental transactions:" << endl;
                for (const auto& t : transactions) {
                    cout << "Customer ID: " << t.customer_id 
                         << " | Car ID: " << t.car_id 
                         << " | Action: " << t.action << endl;
                }
            }
                        
};

int main () {
    rental_system r;
    int choice;
    do{
        clear_screen();
        cout << "1. Add car" << endl;
        cout << "2. Add customer" << endl;
        cout << "3. Show cars" << endl;
        cout << "4. Show customers" << endl;
        cout << "5. Rent car" << endl;
        cout << "6. Return car" << endl;
        cout << "7. Show rental transactions" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        clear_screen();

        if(choice < 1 || choice > 7){
            cout << "Invalid choice!" << endl;
            continue;
        }

        switch(choice){
            case 1:
            {
                string name, model, color;
                int year, price, id, quantity;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter model: ";
                cin >> model;
                cout << "Enter color: ";
                cin >> color;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter quantity: ";
                cin >> quantity;
                r.add_car(name, model, color, year, price, id, quantity);
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 2:
            {
                string cname, address, phone;
                int cid;
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, cname);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter phone: ";
                cin >> phone;
                cout << "Enter id: ";
                cin >> cid;
                r.add_customer(cname, address, phone, cid);
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 3:
            {
                r.show_cars();
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 4:
            {
                r.show_customers();
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 5:
            {
                int car_id, customer_id;
                cout << "Enter car id: ";
                cin >> car_id;
                cout << "Enter customer id: ";
                cin >> customer_id;
                r.rent_car(car_id, customer_id);
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 6:
            {
                int car_id1, customer_id1;
                cout << "Enter car id: ";
                cin >> car_id1;
                cout << "Enter customer id: ";
                cin >> customer_id1;
                r.return_car(car_id1, customer_id1);
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 7:
            {
                r.load_rental_transactions();
                cout << "Press ENTER to continue..." << endl;
                getch();
                break;
            }

            case 8:
            {
                cout << "Exiting..." << endl;
                break;
            }

            default:
                cout << "Invalid choice!" << endl;
        }
    }while(choice != 8);

    return 0;
}
# Car-Rental-System

#### **Overview**
The Rental Car System is a comprehensive software solution designed to manage a car rental business. This system allows users to add cars, customers, and manage the rental process effectively. The system handles car availability, customer data, rental transactions, and the return process. Additionally, it stores all relevant data in text files, allowing the system to persist across sessions.

#### **Key Features**
- **Add Car**: Add new cars to the system's inventory.
- **Add Customer**: Register new customers into the system.
- **Rent Car**: Allows a customer to rent a car if available.
- **Return Car**: Enables customers to return rented cars, updating the inventory and rental records.
- **Show Cars**: Displays details of all cars in the system's inventory.
- **Show Customers**: Displays details of all registered customers.
- **Show Rental Transactions**: Displays a record of all rental transactions, whether rented or returned.
- **Data Persistence**: All car and customer information is saved in text files (`cars.txt`, `customers.txt`, and `rented_cars.txt`), ensuring that data is preserved between sessions.

#### **System Components**
1. **Car Class**:
    - **Attributes**:
        - `name`: The name of the car (e.g., "Toyota Corolla").
        - `model`: The model of the car (e.g., "2022").
        - `color`: The color of the car (e.g., "Red").
        - `year`: The manufacturing year of the car.
        - `price`: The rental price per day for the car.
        - `id`: Unique identifier for each car.
        - `quantity`: The number of available units of the car.
    - **Methods**:
        - `setCar()`: Initializes a car with its attributes.
        - `getCar()`: Displays the details of the car.
        - `getName()`, `getModel()`, `getColor()`, `getYear()`, `getPrice()`, `getId()`, `getQuantity()`: Return the car's respective attribute.
        - `setQuantity()`: Sets the available quantity of the car.

2. **Customer Class**:
    - **Attributes**:
        - `name`: The name of the customer.
        - `address`: The address of the customer.
        - `phone`: The phone number of the customer.
        - `id`: Unique identifier for each customer.
    - **Methods**:
        - `setCustomer()`: Initializes a customer with their details.
        - `getCustomer()`: Displays the customer's information.
        - `getName()`, `getAddress()`, `getPhone()`, `getId()`: Return the customer's respective attribute.

3. **RentalTransaction Structure**:
    - **Attributes**:
        - `customer_id`: The ID of the customer involved in the transaction.
        - `car_id`: The ID of the car involved in the transaction.
        - `action`: A string indicating whether the car was rented or returned.

4. **RentalSystem Class**:
    - **Attributes**:
        - `cars`: A vector containing all the cars in the system.
        - `customers`: A vector containing all registered customers.
    - **Methods**:
        - `safe_to_file()`: Saves car data to a file (`cars.txt`).
        - `load_from_file()`: Loads car data from a file (`cars.txt`).
        - `save_customers_in_file()`: Saves customer data to a file (`customers.txt`).
        - `load_customers_from_file()`: Loads customer data from a file (`customers.txt`).
        - `add_car()`: Adds a new car to the system's inventory.
        - `add_customer()`: Registers a new customer.
        - `show_cars()`: Displays all cars in the system.
        - `show_customers()`: Displays all customers in the system.
        - `rent_car()`: Allows a customer to rent a car if available.
        - `return_car()`: Enables a customer to return a rented car and updates the inventory.
        - `save_rental_transaction()`: Saves rental transactions to a file (`rented_cars.txt`).
        - `load_rental_transactions()`: Displays rental transactions from the file (`rented_cars.txt`).

#### **Data Flow**

1. **Adding Cars**:
   - The user can add a new car by providing the car's name, model, color, year, price, ID, and quantity. The car is then added to the system, and the data is saved to the `cars.txt` file for persistence.
   
2. **Adding Customers**:
   - A new customer can be added by providing the customer's name, address, phone, and ID. The customer is added to the system, and the data is saved in the `customers.txt` file.

3. **Renting Cars**:
   - When a customer rents a car, the system checks if the car is available. If the car is in stock, it is rented to the customer by decreasing the car's available quantity. The rental transaction is logged in the `rented_cars.txt` file.

4. **Returning Cars**:
   - When a car is returned, the system verifies if the car was rented by the customer. If so, it updates the car's quantity and logs the return in the `rented_cars.txt` file. The system also updates the `cars.txt` file to reflect the new car quantity.

5. **Rental Transactions**:
   - All rental transactions (both rented and returned cars) are stored in the `rented_cars.txt` file for later reference. The system can load and display these transactions upon request.

#### **File Management**
- **cars.txt**: Stores information about the cars available for rent, including their name, model, color, year, price, ID, and quantity.
- **customers.txt**: Stores information about the customers, including their name, address, phone, and ID.
- **rented_cars.txt**: Stores rental transactions, including customer ID, car ID, and action (rented or returned).

#### **System Workflow Example**
1. **Add Car**:
   - The user enters the car details (e.g., name, model, price).
   - The system checks for duplicate car IDs.
   - If no duplicate exists, the car is added, and the data is saved to `cars.txt`.
   
2. **Rent Car**:
   - The user selects a car and a customer.
   - The system checks if the car is available.
   - If available, the car's quantity is reduced, and the rental transaction is saved in `rented_cars.txt`.
   
3. **Return Car**:
   - The user returns a rented car.
   - The system verifies the rental transaction, updates the car's availability, and saves the return in `rented_cars.txt`.

#### **Error Handling**
- **Invalid Choices**: The system checks for invalid user choices and prompts the user to make a valid selection.
- **File Access Issues**: If the system cannot open a file (e.g., `cars.txt`, `customers.txt`), it will display an error message and halt the operation.

#### **Conclusion**
The Rental Car System is a well-structured solution for managing car rentals, handling customer information, and maintaining rental transactions. By leveraging text file storage, the system ensures data persistence, enabling users to access car and customer information seamlessly across multiple sessions. The system also maintains records of rental actions, making it easy to track rental history for auditing or customer service purposes.


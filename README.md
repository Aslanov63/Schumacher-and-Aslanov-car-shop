# Schumacher & Aslanov's Parts Shop 🏎️

A robust C++ console application designed for managing an automotive parts and tuning shop. This project demonstrates proficiency in object-oriented logic, data structures, and persistent file storage.

## 🌟 Features

* **User Registration:** Comprehensive system to collect customer credentials and vehicle details.
* **Structured Catalog:** Organized categories including Engine Tuning, Body Parts, and Spare Parts.
* **Smart Shopping Cart:** Allows users to add multiple items and review their selection.
* **Advanced Sorting:** Built-in logic to sort the cart by **Price** or **Product Name** using custom sorting algorithms.
* **Administrator Panel:** A secure, password-protected interface for staff to monitor customer data and active orders.
* **Data Persistence:** Saves all session information (customer, car, and orders) into a binary file (`user_data.bin`) for future use.

## 🛠 Technologies & Concepts Applied

This project showcases the following C++ technical skills:
* **STL Containers:** Extensive use of `std::vector` for dynamic lists and `std::map` for efficient key-value data management.
* **File I/O:** Implementation of `std::ofstream` with `ios::binary` for low-level data serialization.
* **Lambda Expressions:** Modern C++ approach used within `std::sort` for flexible data organization.
* **Data Modeling:** Utilizing `struct` (Product, Customer, Car) to create clean, maintainable data objects.

## 🚀 Getting Started

### Prerequisites
* A C++ compiler (GCC, Clang, or MSVC) supporting C++11 or higher.

### Installation & Execution
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/parts-shop-cpp.git](https://github.com/your-username/parts-shop-cpp.git)
    ```
2.  **Navigate to the project directory:**
    ```bash
    cd parts-shop-cpp
    ```
3.  **Compile the source code:**
    ```bash
    g++ main.cpp -o PartsShop
    ```
4.  **Run the application:**
    ```bash
    ./PartsShop
    ```

## 📂 Project Structure
* `main.cpp` — The core logic and entry point of the application.
* `user_data.bin` — Binary storage file (generated automatically upon saving).
* `README.md` — Project documentation.

## 👥 Authors
* **Schumacher**
* **Aslanov** (ali.aslanov.2007@gmail.com)

---
*Developed for educational purposes. Last stable build: May 14, 2025.*

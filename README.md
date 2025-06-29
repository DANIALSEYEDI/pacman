# **Student Management System**

This project is a **Java** application designed for managing student information, utilizing **inheritance** to structure its classes efficiently. It allows adding students and handling access permissions, processing and storing data with simple data structures while supporting specific input formats.

## **Features**
- **Add Student**: Register student details such as first name, last name, student ID, password, birth year, and address.
- **Access Management**: Supports **Admin** and **Regular User** roles with different access levels.
- **Inheritance-Based Design**: Uses Java inheritance to organize classes, enhancing code modularity and reusability.
- **Persian Language Support**: Processes Persian inputs for names and addresses.

![Student Management System](https://via.placeholder.com/600x300.png?text=Student+Management+System)

## **Installation and Setup**
To use this project, you need the Java Development Kit (JDK) installed. Follow these steps:

1. **Install JDK**: Ensure JDK version 8 or higher is installed.
   ```bash
   java -version
   ```
2. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/student-management-system.git
   ```
3. **Compile and Run**:
   ```bash
   cd student-management-system
   javac Main.java
   java Main
   ```

## **Required Inputs**
The program requires the following inputs to register a student:

- **Admin Username**: `admin`
- **Admin Password**: `AdminPass`
- **Student ID**: A unique identifier (e.g., `14010011234`)
- **Password**: Student's password (e.g., `Passwd`)
- **First Name**: Student's first name (e.g., `Test`)
- **Last Name**: Student's last name (e.g., `Testi`)
- **Phone Number**: A 10-digit phone number (e.g., `0123456789`)
- **Birth Year**: Year of birth (e.g., `1382`)
- **Address**: Student's address (e.g., `Tehran, Mirdamad`)

Example input format:
```
add-student # admin|AdminPass|14010011234|Passwd|Test|Testi|0123456789|1382|Tehran, Mirdamad
```

## **Usage**
1. Run the program using the commands above.
2. Enter the required inputs in the specified format.
3. The program will process and store the student information.

## **Screenshots**
![Sample Input](https://via.placeholder.com/600x300.png?text=Sample+Input+Screen)
*Caption: Example of input format for adding a student.*

## **Contributing**
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## **Contact**
For questions or suggestions, feel free to open an issue or contact the repository owner.
# Student Management System in C

## Description
This is a C program to manage student records efficiently.  
It allows the user to input student details, calculate totals, averages, assign grades, identify the topper, and save all results to a file for future reference.

---

## Features
- Add student details (Roll Number, Name, Marks for 3 subjects)  
- Calculate total marks, average marks, and assign grades  
- Display a formatted result table  
- Identify and display the topper  
- Save all student data automatically to a file (`students.txt`)  

---

## How to Run
1. Open terminal or command prompt.  
2. Navigate to the folder containing `main.c`.  
3. Compile the program:

## Sample Output

```
Total number of students you want: 2

-----------STUDENT DETAIL--------
Roll No: 1
Name: Riya
Marks for 3 subjects: 90 85 95

-----------STUDENT DETAIL--------
Roll No: 2
Name: Jiya
Marks for 3 subjects: 78 82 80

Roll | Name | Total | Average | Grade
1    | Riya | 270.00 | 90.00 | A
2    | Jiya | 240.00 | 80.00 | B

Topper Details 
Name: Riya
Roll No: 1
Total Marks: 270.00
Average: 90.00
Grade: A
```

---

## File Handling

All student data is automatically saved to **students.txt**.

Each line in the file is stored in this format:

```
RollNumber,Name,Mark1,Mark2,Mark3,Average,Grade
```

### Example:

```
1,Riya,90.00,85.00,95.00,90.00,A
2,Jiya,78.00,82.00,23.00,61.00,C
```
##Author
Kanishka Jain
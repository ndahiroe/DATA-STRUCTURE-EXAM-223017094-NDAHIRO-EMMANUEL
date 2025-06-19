# Insurance Quote System

## Description

This project simulates an insurance premium calculation system using C++. It demonstrates key concepts of object-oriented programming, including:

- Struct definitions
- Dynamic memory allocation with arrays
- Inheritance and polymorphism
- Pointer arithmetic
- Dynamic resizing of arrays for adding/removing elements

The program calculates insurance premiums based on applicants' ages and vehicle types, using different premium brackets for basic and premium insurance plans.

---

## Assigned Tasks and Implementation

### Task 1: Define Structs and Dynamic Array Allocation

- Defined two structs: `Applicant` (holding VIN, age, and vehicle type) and `Bracket` (with age ranges and premium).
- Dynamically allocated a `Bracket*` array to store multiple premium brackets.

### Task 2: Abstract Base Class and Derived Classes

- Created an abstract base class `QuoteEngine` with a pure virtual function `calculate()`.
- Derived two classes: `BasicQuoteEngine` and `PremiumQuoteEngine`.
- Implemented `calculate()` in each derived class to compute premiums based on the applicant's age and premium brackets.

### Task 3: Polymorphism with Dynamic Array of QuoteEngines

- Stored pointers to `QuoteEngine` objects in a dynamic `QuoteEngine**` array.
- Demonstrated polymorphic behavior by calling `calculate()` on each engine via the base class pointer.
- Verified correct premium calculations for multiple applicants.

### Task 4: Pointer Arithmetic

- Used pointer arithmetic on the `Bracket*` array to find the premium bracket matching the applicant’s age.

### Task 5: Dynamic Resizing of Bracket Arrays

- Implemented `addBracket()` to dynamically add new premium brackets by resizing the `Bracket*` array.
- Implemented `removeBracket()` to remove a bracket at a given index and resize the array.
- Verified adding and removing brackets works correctly by displaying the bracket list.

---

## How It Was Completed

- The project was implemented in one C++ source file.
- Each task was developed incrementally, building upon the previous one.
- Memory management was handled carefully to avoid leaks by deleting dynamically allocated arrays.
- Pointer arithmetic and dynamic polymorphism demonstrated advanced C++ concepts.
- The `main()` function creates sample applicants and quote engines, then outputs calculated premiums for verification.
- Added comments throughout the code to explain the purpose of variables and functions.

---

## Running the Program

1. Compile with any standard C++ compiler (e.g., `g++ insurance.cpp -o insurance`).
2. Run the executable.
3. The output will show premium calculations for three sample applicants under basic and premium engines.
4. Additional output demonstrates pointer arithmetic and dynamic bracket resizing.

---

## Sample Output

```
--- Applicant 1 ---
VIN: VIN0000000000001, Age: 22, Type: car
Basic Engine Premium: 1000 RWF
Premium Engine Premium: 1200 RWF

--- Applicant 2 ---
VIN: VIN0000000000002, Age: 30, Type: car
Basic Engine Premium: 800 RWF
Premium Engine Premium: 960 RWF

--- Applicant 3 ---
VIN: VIN0000000000003, Age: 50, Type: car
Basic Engine Premium: 600 RWF
Premium Engine Premium: 720 RWF

Task 4 - Pointer Arithmetic:
Age: 27 => Premium: 800 RWF

Task 5 - After adding brackets:
Brackets count: 3
Bracket 0: 18-25 Premium: 1000
Bracket 1: 26-35 Premium: 800
Bracket 2: 36-60 Premium: 600

Task 5 - After removing bracket at index 1:
Brackets count: 2
Bracket 0: 18-25 Premium: 1000
Bracket 1: 36-60 Premium: 600
```
---
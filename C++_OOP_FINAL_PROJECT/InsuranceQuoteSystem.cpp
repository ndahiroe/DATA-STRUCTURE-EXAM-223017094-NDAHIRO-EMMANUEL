
#include <iostream>  // For input/output operations
#include <cstring>   // For string handling with char arrays
using namespace std;

// Struct to hold applicant information
struct Applicant {
    char vin[17];            // Vehicle Identification Number (up to 16 chars + null terminator)
    int age;                 // Age of the applicant
    char vehicleType[10];    // Vehicle type as a string (e.g., "car", "bike")
};

// Struct to define premium brackets based on age
struct Bracket {
    float minAge;            // Minimum age for this bracket
    float maxAge;            // Maximum age for this bracket
    float premium;           // Insurance premium for this bracket
};

// Abstract base class for quote engines (polymorphism base)
class QuoteEngine {
public:
    // Pure virtual function to calculate premium for an applicant
    virtual float calculate(const Applicant* applicant) = 0;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~QuoteEngine() {}
};

// Basic insurance quote engine derived from QuoteEngine
class BasicQuoteEngine : public QuoteEngine {
private:
    Bracket* brackets;       // Dynamic array to hold brackets
    int bracketCount;        // Number of brackets currently stored

public:
    // Constructor initializes an empty bracket list
    BasicQuoteEngine() : brackets(nullptr), bracketCount(0) {}

    // Adds a new bracket by resizing the dynamic array
    void addBracket(Bracket b) {
        Bracket* newBrackets = new Bracket[bracketCount + 1];
        for (int i = 0; i < bracketCount; ++i)
            newBrackets[i] = brackets[i];
        newBrackets[bracketCount] = b;
        delete[] brackets;
        brackets = newBrackets;
        ++bracketCount;
    }

    // Calculate premium based on applicant's age
    float calculate(const Applicant* applicant) override {
        for (int i = 0; i < bracketCount; ++i) {
            Bracket* b = brackets + i;
            if (applicant->age >= b->minAge && applicant->age <= b->maxAge)
                return b->premium;
        }
        return -1.0f;
    }

    // Destructor to free allocated memory
    ~BasicQuoteEngine() {
        delete[] brackets;
    }
};

// Premium insurance quote engine derived from QuoteEngine
class PremiumQuoteEngine : public QuoteEngine {
private:
    Bracket* brackets;
    int bracketCount;

public:
    PremiumQuoteEngine() : brackets(nullptr), bracketCount(0) {}

    void addBracket(Bracket b) {
        Bracket* newBrackets = new Bracket[bracketCount + 1];
        for (int i = 0; i < bracketCount; ++i)
            newBrackets[i] = brackets[i];
        newBrackets[bracketCount] = b;
        delete[] brackets;
        brackets = newBrackets;
        ++bracketCount;
    }

    float calculate(const Applicant* applicant) override {
        for (int i = 0; i < bracketCount; ++i) {
            Bracket* b = brackets + i;
            if (applicant->age >= b->minAge && applicant->age <= b->maxAge)
                return b->premium * 1.2f;
        }
        return -1.0f;
    }

    ~PremiumQuoteEngine() {
        delete[] brackets;
    }
};

// Class to demonstrate dynamic add and remove bracket (Task 5)
class DynamicBracketEngine {
private:
    Bracket* brackets;
    int bracketCount;

public:
    DynamicBracketEngine() : brackets(nullptr), bracketCount(0) {}

    void addBracket(Bracket b) {
        Bracket* newBrackets = new Bracket[bracketCount + 1];
        for (int i = 0; i < bracketCount; ++i)
            newBrackets[i] = brackets[i];
        newBrackets[bracketCount] = b;
        delete[] brackets;
        brackets = newBrackets;
        ++bracketCount;
    }

    void removeBracket(int index) {
        if (index < 0 || index >= bracketCount)
            return;

        Bracket* newBrackets = new Bracket[bracketCount - 1];
        int j = 0;
        for (int i = 0; i < bracketCount; ++i) {
            if (i != index) {
                newBrackets[j] = brackets[i];
                ++j;
            }
        }
        delete[] brackets;
        brackets = newBrackets;
        --bracketCount;
    }

    void display() const {
        cout << "Brackets count: " << bracketCount << endl;
        for (int i = 0; i < bracketCount; ++i) {
            cout << "Bracket " << i << ": " << brackets[i].minAge
                 << "-" << brackets[i].maxAge
                 << " Premium: " << brackets[i].premium << endl;
        }
    }

    ~DynamicBracketEngine() {
        delete[] brackets;
    }
};

// Main function to test the entire insurance quote system
int main() {
    Applicant a1 = {"VIN0000000000001", 22, "car"};
    Applicant a2 = {"VIN0000000000002", 30, "car"};
    Applicant a3 = {"VIN0000000000003", 50, "car"};

    QuoteEngine** engines = new QuoteEngine*[2];

    BasicQuoteEngine* basic = new BasicQuoteEngine();
    basic->addBracket({18, 25, 1000});
    basic->addBracket({26, 35, 800});
    basic->addBracket({36, 60, 600});

    PremiumQuoteEngine* premium = new PremiumQuoteEngine();
    premium->addBracket({18, 25, 1500});
    premium->addBracket({26, 35, 1200});
    premium->addBracket({36, 60, 1000});

    engines[0] = basic;
    engines[1] = premium;

    Applicant applicants[3] = {a1, a2, a3};

    for (int j = 0; j < 3; ++j) {
        cout << "\n--- Applicant " << (j + 1) << " ---\n";
        cout << "VIN: " << applicants[j].vin
             << ", Age: " << applicants[j].age
             << ", Type: " << applicants[j].vehicleType << endl;

        for (int i = 0; i < 2; ++i) {
            float premiumAmount = engines[i]->calculate(&applicants[j]);
            if (i == 0)
                cout << "Basic Engine Premium: " << premiumAmount << " RWF" << endl;
            else
                cout << "Premium Engine Premium: " << premiumAmount << " RWF" << endl;
        }
    }

    cout << "\nTask 4 - Pointer Arithmetic Example:\n";
    Bracket* brackets = new Bracket[3]{
        {18, 25, 1000},
        {26, 35, 800},
        {36, 60, 600}
    };
    int testAge = 27;
    float foundPremium = -1.0f;
    for (int i = 0; i < 3; ++i) {
        Bracket* b = brackets + i;
        if (testAge >= b->minAge && testAge <= b->maxAge) {
            foundPremium = b->premium;
            break;
        }
    }
    cout << "Age: " << testAge << " => Premium: " << foundPremium << " RWF" << endl;
    delete[] brackets;

    cout << "\nTask 5 - Dynamic Add and Remove Brackets:\n";
    DynamicBracketEngine dynEngine;

    dynEngine.addBracket({18, 25, 1000});
    dynEngine.addBracket({26, 35, 800});
    dynEngine.addBracket({36, 60, 600});

    cout << "After adding brackets:\n";
    dynEngine.display();

    dynEngine.removeBracket(1);

    cout << "\nAfter removing bracket at index 1:\n";
    dynEngine.display();

    delete basic;
    delete premium;
    delete[] engines;

    return 0;
}

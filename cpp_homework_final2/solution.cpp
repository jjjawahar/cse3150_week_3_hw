
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <stdexcept>

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if (size == capacity) {
        throw std::string("List full");
    }

    names[size] = name;
    gpas[size] = gpa;

    size++;
}

// TODO: implement updateGPA

void updateGPA(double* gpaPtr, double newGpa){
    if ( gpaPtr != nullptr ) {
        *gpaPtr = newGpa;
    }
}

// TODO: implement printStudent

 void printStudent(const char* name, const double& gpa){
    std::cout << name << ": " << gpa << std::endl;
 }

// TODO: implement averageGPA

double averageGPA(const double gpas[], int size){
    if (size == 0) {
        throw std::string("No students");
    }
    double avg = 0.0;

    for(int i = 0; i < size; ++i){
        avg += gpas[i];
    }

    return avg/size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char name[100];
                double gpa;
                std::cin >> name >> gpa;
                char* newName = new char[strlen(name)+1];
                strcpy(newName, name);
                try{
                    addStudent(newName, gpa, names, gpas, size, capacity);
                } catch(const std::string& e){
                    std::cout << e << std::endl;
                }
                // TODO: implement menu logic
                break;
            }
            case 2: {
                int index;

                double gpa;
                std::cin >> index >> gpa;

                if (index < 0 || index >= size) {
                    throw std::string("Invalid index");
                }

                updateGPA(&gpas[index],gpa);
                // TODO: implement menu logic
                break;
            }
            case 3: {
                for (int i = 0; i < size; ++i){
                    printStudent(names[i], gpas[i]);
                }
                // TODO: implement menu logic
                break;
            }
            case 4: {
                try{
                    std::cout << "Average GPA: "<<static_cast<int>(averageGPA(gpas, size)) << std::endl;
                } catch (const std::string& e){
                    std::cout << e << std::endl;
                }

                // TODO: implement menu logic
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for(int i = 0; i < size; ++i){
        delete[] names[i];
    }
    // TODO: free memory

    return 0;
}

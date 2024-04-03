#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

class GradeManager {
private:
    vector<string> studentNames; // Vector to store student names
    vector<float> grades; // Vector to store corresponding grades

public:
    void addStudentGrade(const string& name, float grade) {
        studentNames.push_back(name); // Add student name to vector
        grades.push_back(grade); // Add grade to vector
    }

    void displayGrades() const {
        cout << "Student Grades:\n";
        for (size_t i = 0; i < studentNames.size(); ++i) {
            cout << studentNames[i] << ": " << grades[i];
            // Display "PASS" or "FAIL" next to each grade based on the grade value
            if (grades[i] >= 40) {
                cout << " (PASS)";
            } else {
                cout << " (FAIL)";
            }
            cout << endl;
        }
    }

    float calculateAverageGrade() const {
        if (grades.empty()) return 0.0; // Check if there are no grades

        float sum = 0.0;
        for (float grade : grades) {
            sum += grade; // Sum all grades
        }
        return sum / grades.size(); // Calculate and return average
    }

    void displayAverageGrade() const {
        // Display the average grade to the console
        cout << "Average Grade: " << calculateAverageGrade() << endl;
    }

    void displayHighestAndLowestGrades() const {
        if (grades.empty()) {
            cout << "No grades available." << endl;
            return;
        }

        float maxGrade = grades[0]; // Assume first grade is the highest initially
        float minGrade = grades[0]; // Assume first grade is the lowest initially

        // Iterate through grades to find the actual highest and lowest
        for (float grade : grades) {
            if (grade > maxGrade) maxGrade = grade;
            if (grade < minGrade) minGrade = grade;
        }

        // Display the highest and lowest grades
        cout << "Highest Grade: " << maxGrade << endl;
        cout << "Lowest Grade: " << minGrade << endl;
    }

    void run() {
        // Print the heading "GRADE ENTRY FORM" with a square pattern around it
        cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                         CodSoft Internship (March 05 - April 05)                                    |" << endl;
        cout << "|                                             Student Grade Management System                                         |" << endl;
        cout << "|                                              Developed with C++ Programming                                         |" << endl;
        cout << "|                                                Priteesh Madhav Reddy Karra                                          |" << endl;
        cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

        string studentName;
        float grade;

        while (true) {
            cout << "Enter student name (or type 'done' to finish): ";
            getline(cin, studentName); // Read a line from cin, allowing for spaces in names
            if (studentName == "done") break; // Exit loop if user types "done"

            while (true) {
                cout << "Enter " << studentName << "'s grade (1-100): ";
                cin >> grade;
                // Validate grade input; it must be between 1 and 100
                if (cin.fail() || grade < 1 || grade > 100) {
                    cin.clear(); // Reset cin state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
                    cout << "Grade limits not more than 100 and should be between 1-100." << endl;
                } else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer after valid input
                    break; // Exit the inner loop on valid input
                }
            }

            addStudentGrade(studentName, grade); // Add the valid grade and student name to the lists
        }

        // Display all grades, average grade, and the highest and lowest grades
        displayGrades();
        displayAverageGrade();
        displayHighestAndLowestGrades();
    }
};

int main() {
    GradeManager manager;
    manager.run(); // Start the GradeManager
    return 0;
}

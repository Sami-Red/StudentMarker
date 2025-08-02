#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Variables for mark ranges
    int mark1 = 0, mark2 = 0, mark3 = 0, mark4 = 0;
    int TotalMarks = 0, Counter = 0, Average = 0;
    int pass = 0, lowest = 0, highest = 0;
    int n;

    cout << "How many students in class?: ";
    cin >> n;

    vector<int> mark(n); // Dynamic array to store student marks

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter the student's Marks: ";
        cin >> mark[i];

        // Validate mark range
        if (mark[i] < 0 || mark[i] > 100) {
            cout << "Enter a correct number from 0 to 100!" << endl;
            i--; // Retry current student
            continue;
        }

        TotalMarks += mark[i];
        Counter++;

        if (mark[i] <= 29) {
            mark1++;
            lowest++;
        }
        else if (mark[i] <= 39) {
            mark2++;
        }
        else if (mark[i] <= 69) {
            mark3++;
            pass++;
        }
        else { // mark between 70 and 100
            mark4++;
            pass++;
            highest++;
        }
    }

    cout << "\nNumber of students with Marks   (0-29)  | ";
    for (int i = 0; i < mark1; i++) cout << "*";

    cout << "\nNumber of students with Marks  (30-39)  | ";
    for (int i = 0; i < mark2; i++) cout << "*";

    cout << "\nNumber of students with Marks  (40-69)  | ";
    for (int i = 0; i < mark3; i++) cout << "*";

    cout << "\nNumber of students with Marks (70-100) | ";
    for (int i = 0; i < mark4; i++) cout << "*";

    cout << endl;

    Average = TotalMarks / Counter;

    // Find highest and lowest marks
    int locationMax = 0, locationMin = 0;
    for (int c = 1; c < n; c++) {
        if (mark[c] > mark[locationMax])
            locationMax = c;
        if (mark[c] < mark[locationMin])
            locationMin = c;
    }

    // Output stats
    cout << "\nTotal number of students who entered exam: " << Counter << endl;
    cout << "Average Mark: " << Average << endl;
    cout << "Number of passing students: " << pass << endl;
    cout << "Highest Mark: " << mark[locationMax] << endl;
    cout << "Lowest Mark: " << mark[locationMin] << endl;

    return 0;
}

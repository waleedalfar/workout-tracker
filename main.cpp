#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addNewExercise();
void defaultExercises(fstream &exercisesFile);
void listExercises();
bool fileExists(const string &newWorkoutFileName);
void newWorkout();
void editPreviousWorkout();
void menu();
int quit();

void addNewExercise()
{
    fstream exercisesFile("/Users/waleedalfar/Desktop/workouttracker/exercises.txt", ios::in | ios::out | ios::app);
    listExercises();
    cin.ignore();
    cout << "Enter new exercise: ";
    string userInput;
    getline(cin, userInput);
    exercisesFile << userInput << endl;
}

void defaultExercises(fstream &exercisesFile)
{
    exercisesFile << "Bench Press" << endl;
    exercisesFile << "Squat" << endl;
    exercisesFile << "Deadlift" << endl;
}

void listExercises()
{
    string line;
    fstream exercisesFile("/Users/waleedalfar/Desktop/workouttracker/exercises.txt", ios::in | ios::out | ios::app);
    // ifstream exercisesFile("/Users/waleedalfar/Desktop/exercises.txt");

    if (exercisesFile.tellg() == 0) // If the file pointer is at the start (empty file)
    {
        defaultExercises(exercisesFile);
    }

    exercisesFile.seekg(0, ios::beg);

    if (exercisesFile.is_open())
    {
        while (getline(exercisesFile, line))
            cout << line << '\n';
        exercisesFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

bool fileExists(const string &newWorkoutFileName) // check if the file name already exists
{
    ifstream file(newWorkoutFileName);
    return file.good();
}

void newWorkout()
{
    int workoutCount = 0;
    string newWorkoutFileName;

    cin.ignore(); // clear input buffer

    do
    {
        newWorkoutFileName = "workout" + to_string(workoutCount) + ".txt"; // create new file name based on workoutcount
        workoutCount++;                                                    // increment workout count
    } while (fileExists(newWorkoutFileName)); // while this file exists
    ofstream newFile(newWorkoutFileName); // open the file, newFile is just an alias or name for the stream to the newWorkoutFileName
    if (newFile.is_open())                // while that bitch is open
    {
        cout << newWorkoutFileName + " was opened" << endl;
        cout << "Enter your exercises and reps: ";
        string userInput;
        getline(cin, userInput);
        newFile << userInput;
        newFile.close();
    }
}

void editPreviousWorkout()
{
    cout << "two";
}

int quit()
{
    return 0;
}

void menu()
{
    cout << "1. Create new workout" << endl;
    cout << "2. Edit previous workout" << endl;
    cout << "3. Add new exercise" << endl;
    cout << "4. List current exercises" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        newWorkout();
    }
    else if (choice == 2)
    {
        editPreviousWorkout();
    }
    else if (choice == 3)
    {
        addNewExercise();
    }
    else if (choice == 4)
    {
        listExercises();
    }
    else if (choice == 5)
    {
        quit();
    }
}

int main(int argc, char *argv[])
{
    cout << "Greetings! What would you like to do today?" << endl;
    menu();
}
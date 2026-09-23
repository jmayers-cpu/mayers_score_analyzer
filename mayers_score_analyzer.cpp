#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Function Prototypes for Part A ---
void printArray(const int* arr, int size);
int findMin(const int* arr, int size);
int findMax(const int* arr, int size);
double calculateAverage(const int* arr, int size);
int countAboveAverage(const int* arr, int size, double average);

int main() {
    // ==========================================
    // PART A: Dynamic Array
    // ==========================================
    int numScores = 0;
    
    // 1. Ask user for size and validate (reject < 1)
    while (numScores < 1) {
        cout << "How many scores will be entered? (Must be at least 1): ";
        cin >> numScores;
    }

    // 2. Allocate dynamic array
    // Memory management: allocate memory on the heap for the requested size
    int* scores = new int[numScores];

    // 3. Read and validate scores (0 through 100)
    for (int i = 0; i < numScores; ++i) {
        int inputScore = -1;
        while (inputScore < 0 || inputScore > 100) {
            cout << "Enter score " << (i + 1) << " (0-100): ";
            cin >> inputScore;
        }
        scores[i] = inputScore;
    }

    // 4. Process array with functions
    cout << "\n--- Part A: Dynamic Array Analysis ---\n";
    cout << "Original dynamic array values: ";
    printArray(scores, numScores);

    int minScore = findMin(scores, numScores);
    int maxScore = findMax(scores, numScores);
    double averageScore = calculateAverage(scores, numScores);
    int aboveAvgCount = countAboveAverage(scores, numScores, averageScore);

    cout << "Minimum score: " << minScore << "\n";
    cout << "Maximum score: " << maxScore << "\n";
    cout << "Average score: " << averageScore << "\n";
    cout << "Scores above average: " << aboveAvgCount << "\n";

    // 5. Demonstrate pointer arithmetic
    cout << "\nPointer arithmetic demonstration:\n";
    /*
     * EXPLANATION: *(scores + i) is equivalent to scores[i]. 
     * The array name 'scores' acts as a pointer to the first element's memory address. 
     * Adding 'i' to the pointer shifts the address forward by 'i' times the size of an integer.
     * Dereferencing it with '*' accesses the value stored at that calculated address.
     */
    int displayCount = (numScores < 3) ? numScores : 3; // Prevent out-of-bounds if user enters < 3
    for (int i = 0; i < displayCount; ++i) {
        cout << "Element " << i << " using *(scores + " << i << "): " << *(scores + i) << "\n";
    }

    // ==========================================
    // PART B: STL Vector and Algorithms
    // ==========================================
    
    // 1. Copy to vector BEFORE deleting dynamic array
    vector<int> vecScores(scores, scores + numScores);

    // 6. Release dynamic memory exactly once and nullify pointer
    // Memory management: free the heap memory to prevent leaks
    delete[] scores;
    scores = nullptr;

    cout << "\n--- Part B: STL Vector Analysis ---\n";
    
    // 2. Display vector using an iterator
    cout << "Vector contents using iterator: ";
    for (auto it = vecScores.begin(); it != vecScores.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // 3. Ask for a target score and use std::find
    int target;
    cout << "\nEnter a target score to search for: ";
    cin >> target;
    
    auto searchIt = std::find(vecScores.begin(), vecScores.end(), target);
    if (searchIt != vecScores.end()) {
        cout << "Target search result: Score " << target << " was FOUND in the vector.\n";
    } else {
        cout << "Target search result: Score " << target << " was NOT FOUND.\n";
    }

    // 4. Sort vector in ascending order using std::sort
    std::sort(vecScores.begin(), vecScores.end());
    cout << "\nSorted vector: ";
    for (int s : vecScores) {
        cout << s << " ";
    }
    cout << "\n";

    // 5. Use STL algorithms for min and max
    auto stlMin = std::min_element(vecScores.begin(), vecScores.end());
    auto stlMax = std::max_element(vecScores.begin(), vecScores.end());
    cout << "Vector STL Minimum: " << *stlMin << "\n";
    cout << "Vector STL Maximum: " << *stlMax << "\n";

    // 6. Display size and capacity
    cout << "Vector Size: " << vecScores.size() << "\n";
    cout << "Vector Capacity: " << vecScores.capacity() << "\n";

    return 0;
}

// --- Function Definitions ---

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findMin(const int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(const int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double calculateAverage(const int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int countAboveAverage(const int* arr, int size, double average) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > average) {
            count++;
        }
    }
    return count;
}

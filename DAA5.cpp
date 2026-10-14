#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;

int partitionArray(vector<int>& a, int low, int high, int choice) {
    int pivotIndex;

    if (choice == 1)
        pivotIndex = low;          // First element
    else if (choice == 2)
        pivotIndex = high;         // Last element
    else
        pivotIndex = low + rand() % (high - low + 1); // Random element

    swap(a[pivotIndex], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;

        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high, int choice) {
    if (low < high) {
        int p = partitionArray(a, low, high, choice);

        quickSort(a, low, p - 1, choice);
        quickSort(a, p + 1, high, choice);
    }
}

void display(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    string choice;

    while (true) {
        cout << "\n--- Quick Sort Menu ---\n";
        cout << "1. First Element Pivot\n";
        cout << "2. Last Element Pivot\n";
        cout << "3. Random Pivot\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3") {
            int n;

            cout << "Enter number of elements: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid size\n";
                continue;
            }

            vector<int> a(n);

            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) cin >> a[i];

            cout << "Original array: ";
            display(a);

            comparisons = 0;

            quickSort(a, 0, n-1, stoi(choice));

            cout << "Sorted array: ";
            display(a);

            cout << "Number of comparisons: " << comparisons << endl;
        }
        else if (choice == "4") {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

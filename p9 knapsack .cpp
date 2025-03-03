#include <iostream>
#include <algorithm>
using namespace std;

// A structure to store the item details
struct Item {
    double value;
    double weight;
    double valuePerWeight;
};

// Function to compare two items based on their value-to-weight ratio
bool compareItems(const Item &a, const Item &b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// Function to calculate the maximum value of the fractional knapsack
double fractionalKnapsack(double capacity, double values[], double weights[], int n) {
    Item items[n];

    // Populate the items array
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].valuePerWeight = values[i] / weights[i];
    }

    // Sort the items based on their value-to-weight ratio
    sort(items, items + n, compareItems);

    double totalValue = 0.0;

    // Loop through the items
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // If the item can fit completely, take it
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the item that fits
            totalValue += items[i].valuePerWeight * capacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    double values[n], weights[n];
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value: ";
        cin >> values[i];
        cout << "Item " << i + 1 << " weight: ";
        cin >> weights[i];
    }

    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, values, weights, n);

    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}


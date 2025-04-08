//WRITE A PROGRAM TO PERFORM DIFFERENT FUNCTIONS IN A PRE EXISTING ARRAY BASED ON OPTION CHOOSED FROM THE GIVEN MENU .//


#include <stdio.h>

#define SIZE 100

void displayArray(int arr[], int size);
void insertElement(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);
void linearSearch(int arr[], int size, int element);
void binarySearch(int arr[], int size, int element);
void sortArray(int arr[], int size);

int main() {
    int arr[SIZE];
    int size, choice, element, position, searchChoice;

    printf("Enter number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n=== Array Operations Menu ===\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                displayArray(arr, size);
                break;
            case 4:
                printf("Choose Search Method:\n");
                printf("1. Linear Search\n");
                printf("2. Binary Search\n");
                scanf("%d", &searchChoice);
                printf("Enter element to search: ");
                scanf("%d", &element);
                if (searchChoice == 1) {
                    linearSearch(arr, size, element);
                } else if (searchChoice == 2) {
                    sortArray(arr, size);
                    binarySearch(arr, size, element);
                } else {
                    printf("Invalid search option.\n");
                }
                displayArray(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= SIZE || position < 0 || position > *size) {
        printf("Invalid position or array full.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted.\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted.\n");
}

void linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at position %d (Linear Search).\n", i);
            return;
        }
    }
    printf("Element not found (Linear Search).\n");
}

void binarySearch(int arr[], int size, int element) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            printf("Element found at position %d (Binary Search).\n", mid);
            return;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found (Binary Search).\n");
}

void sortArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

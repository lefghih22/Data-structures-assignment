#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, i, pos, value;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    printf("\nEnter position to insert (0-based index): ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
    } else {
        for (i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = value;
        n++;

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }


    printf("\nEnter position to delete (0-based index): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
    } else {
        for (i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;

        printf("Array after deletion:\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}

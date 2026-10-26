#include <stdio.h>

struct Order {
int token;
char name[30];
char item[30];
};

int main() {
struct Order orders[100];
int front = 0, rear = -1;
int choice, i, token, found;
do {
    printf("\n--- SMART CANTEEN SYSTEM ---\n");
    printf("1. Place Order\n");
    printf("2. View Orders\n");
    printf("3. Process Order\n");
    printf("4. Search Order\n");
    printf("0. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            if (rear == 99) {
                printf("Queue is full!\n");
            } else {
                rear++;

                orders[rear].token = rear + 101;

                printf("Enter customer name: ");
                scanf(" %29[^\n]", orders[rear].name);

                printf("Enter food item: ");
                scanf(" %29[^\n]", orders[rear].item);

                printf("Your token number is: %d\n",
                       orders[rear].token);
            }
            break;

        case 2:
            if (front > rear) {
                printf("No pending orders!\n");
            } else {
                printf("\nPending Orders:\n");

                for (i = front; i <= rear; i++) {
                    printf("Token: %d, Name: %s, Item: %s\n",
                           orders[i].token,
                           orders[i].name,
                           orders[i].item);
                }
            }
            break;

        case 3:
            if (front > rear) {
                printf("No orders to process!\n");
            } else {
                printf("Order completed: %d - %s\n",
                       orders[front].token,
                       orders[front].item);

                front++;
            }
            break;

        case 4:
            printf("Enter token number: ");
            scanf("%d", &token);

            found = 0;

            for (i = front; i <= rear; i++) {
                if (orders[i].token == token) {
                    printf("Order found!\n");
                    printf("Name: %s\n", orders[i].name);
                    printf("Item: %s\n", orders[i].item);
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("Order not found!\n");
            }
            break;

        case 0:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

} while (choice != 0);

return 0;

}

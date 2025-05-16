// #include<stdio.h>
// #include<stdlib.h>

// //create a union Car with 3 attributes: brand, status, cost
// typedef union {
//     char brand[10];
//     char status;
//     int cost;
// } Car;

// int main(){
//     Car car1;

//     printf("Enter the brand of the car: ");
//     scanf("%9s", car1.brand);//limit input to avoid buffer overflow
//     printf("Brand: %s\n", car1.brand);   

//     //clear input buffer
//     while(getchar() != '\n'); // clear the input buffer'
    
//     printf("Enter the status of car (N/O): ");
//     scanf(" %c", &car1.status);
//     //add a space before %c to ignore any whitespace characters
//     printf("Status: %c\n", car1.status);

//     printf("Enter the cost of car: ");
//     scanf("%d", &car1.cost);
//     printf("Cost: %d\n", car1.cost);    

//     printf("Size of union: %lu\n", sizeof(car1)); 

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

// Create a union Car with 3 attributes: brand, status, cost
typedef union {
    char brand[10];
    char status;
    int cost;
} Car;

int main() {
    Car car1;
    char tempBrand[10];
    char tempStatus;
    int tempCost;

    // Input and store brand
    printf("Enter the brand of the car: ");
    scanf("%9s", car1.brand); // Limit input to avoid buffer overflow
    snprintf(tempBrand, sizeof(tempBrand), "%s", car1.brand); // Store brand in temp variable

    // Clear the input buffer
    while (getchar() != '\n');

    // Input and store status
    printf("Enter the status of car (N/O): ");
    scanf(" %c", &car1.status); // Add a space before %c to handle newline
    tempStatus = car1.status; // Store status in temp variable

    // Input and store cost
    printf("Enter the cost of car: ");
    scanf("%d", &car1.cost);
    tempCost = car1.cost; // Store cost in temp variable

    // Display all values
    printf("Brand: %s\n", tempBrand);
    printf("Status: %c\n", tempStatus);
    printf("Cost: %d\n", tempCost);

    // Display size of the union
    printf("Size of union: %lu\n", sizeof(car1));

    return 0;
}
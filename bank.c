#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int acc_no;
    float balance;
} Account;

Account accounts[100]; // store up to 100 accounts
int account_count = 0; // keeps track of how many accounts exist

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

int main() {
    int choice;
    while (1) {
        printf("\n\n**** Bank Management System ****");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit_money(); break;
            case 3: withdraw_money(); break;
            case 4: check_balance(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}

void create_account() {
    if (account_count >= 100) {
        printf("Account limit reached!\n");
        return;
    }

    Account acc;
    printf("Enter your name: ");
    scanf(" %[^\n]", acc.name);  // scanset to read spaces
    printf("Enter your account number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0.0;

    accounts[account_count++] = acc;
    printf("Account created successfully!\n");
}

void deposit_money() {
    int acc_no;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].acc_no == acc_no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw_money() {
    int acc_no;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].acc_no == acc_no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void check_balance() {
    int acc_no;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].acc_no == acc_no) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}



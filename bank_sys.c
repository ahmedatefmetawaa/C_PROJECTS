/*
 * ******************************************************************************
 * @author   : ahmed atef ahmed
 * @file     : bank_sys.c
 * @version  : 1.0.0
 * @date     : 4/5/2023
 * *******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account
{
    int id;
    char name[50];
    double balance;
    struct account *next;
} Account;

// Function to create a new account node
Account *createAccount(int id, char name[], double balance)
{
    Account *new_account = (Account *)malloc(sizeof(Account));
    new_account->id = id;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = NULL;
    return new_account;
}

// Function to add a new account to the linked list
void addAccount(Account **head, int id, char name[], double balance)
{
    Account *new_account = createAccount(id, name, balance);
    if (*head == NULL)
    {
        *head = new_account;
    }
    else
    {
        Account *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_account;
    }
}

// Function to search for an account by ID and return a pointer to the account node
Account *findAccount(Account *head, int id)
{
    Account *curr = head;
    while (curr != NULL && curr->id != id)
    {
        curr = curr->next;
    }
    return curr;
}

// Function to remove an account from the linked list
void removeAccount(Account **head, int id)
{
    Account *curr = *head;
    Account *prev = NULL;
    while (curr != NULL && curr->id != id)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Account with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL)
    {
        *head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }
    free(curr);
}

// Function to print all the accounts in the linked list
void printAccounts(Account *head)
{
    Account *curr = head;
    while (curr != NULL)
    {
        printf("ID: %d, Name: %s, Balance: %.2f\n", curr->id, curr->name, curr->balance);
        curr = curr->next;
    }
}

int main()
{
    Account *head = NULL;
    addAccount(&head, 1, "Messi", 1000000.00);
    addAccount(&head, 2, "Ronaldo", 5000000.00);
    addAccount(&head, 3, "Mpabe", 200000.00);
    printAccounts(head);
    printf("\n");
    removeAccount(&head, 2);
    printAccounts(head);
    printf("\n");
    Account *acct = findAccount(head, 1);
    if (acct != NULL)
    {
        printf("Account found: ID: %d, Name: %s, Balance: %.2f\n", acct->id, acct->name, acct->balance);
    }
    else
    {
        printf("Account not found.\n");
    }
    return 0;
}

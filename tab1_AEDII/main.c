//
//  main.c
//  tab1_AEDII
//
//  Created by Caio Arthur on 6/1/16.
//  Copyright © 2016 Caio Arthur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int key;
    struct noh *left;
    struct noh *right;
}noh;

int selectedOption;
noh *mainRoot;

int Menu(void);
void insert(noh *node, noh *root), selectOption(int value);

int main()
{
    selectedOption = Menu();
    selectOption(selectedOption);
    main();
}

noh *createNode(int value)
{
    noh *newNode;
    newNode = (noh *)malloc(sizeof(noh));
    
    newNode->key = value;
    newNode->right = NULL;
    newNode->left = NULL;
    
    return newNode;
}

void insertOut()
{
    int valuetoBeInserted;
    
    printf("Número à ser inserido: ");
    scanf("%d", &valuetoBeInserted);
    insert(createNode(valuetoBeInserted), mainRoot);
    
}

void insert(noh *node, noh *root)
{
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        if (node->key < (root)->key)
        {
            insert(node, (root)->left);
        }
        else if (node->key > (root)->key)
        {
            insert(node, (root)->right);
        }
    }
}

void showValues(noh *root)
{
    if (root != NULL)
    {
        printf("%d, ", (root)->key);
        showValues(root->left);
        showValues(root->right);
    }
}

int Menu(void)
{
    int option;
    printf("Inserir na árvore - 1\n\nExibir - 0\nOpção: ");
    scanf("%d", &option);
    return option;
}


void selectOption(int value)
{
   if (value == 1)
   {
       insertOut();
   }
   else if (value == 0)
   {
       showValues(mainRoot);
   }
}

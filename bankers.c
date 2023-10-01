#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define max_processes 100
#define max_resources 100

int available[max_resources];
int maximum[max_processes][max_resources];
int allocation[max_processes][max_resources];
int need[max_processes][max_resources];
int number_processes, number_resources;

void input_lega()
{
    printf("number of processes dalo ");
    scanf("%d", &number_processes);

    printf("number of resources dalo ");
    scanf("%d", &number_resources);

    printf("available resource dalo  ");
    for (int i = 0; i < number_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("enter max demand of each process ");
    for (int i = 0; i < number_processes; i++)
    {
        for (int j = 0; j < number_resources; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("resource allocation for each process dalo ");
    for (int i = 0; i < number_processes; i++)
    {
        for (int j = 0; j < number_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool safe_hai_ya_nhi(int hmm[])
{
    bool finish[number_processes];
    int sequence[number_processes];
    int seq_count = 0;

    for (int i = 0; i < number_processes; i++)
    {
        finish[i] = false;
    }

    while (seq_count < number_processes)
    {
        bool found = false;

        for (int i = 0; i < number_processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < number_resources; j++)
                {
                    if (need[i][j] > hmm[j])
                    {
                        break;
                    }
                }

                if (j == number_resources)
                {
                    for (int k = 0; k < number_resources; k++)
                    {
                        hmm[k] += allocation[i][k];
                    }

                    finish[i] = true;
                    sequence[seq_count++] = i;
                    found = true;
                }
            }
        }

        if (!found)
        {
            return false;
        }
    }

    printf("safe seqience hai ");
    for (int i = 0; i < number_processes; i++)
    {
        printf("%d \n", sequence[i]);
    }

    return true;
}

int main()
{

    return 0;
}

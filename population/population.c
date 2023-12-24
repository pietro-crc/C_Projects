#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("start size of the group: ");
    }
    while (start_size < 9);
    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("end size of the group: ");
    }
    while ( end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    double counting = start_size;
    double new_born;
    double dead;

    do
    {
        new_born = counting/3;



        dead = counting/4;

        counting +=  new_born - dead;

        if (start_size == end_size)
        {
            year = 0;

        }
        else if (end_size >= counting)
        {
            year++;

        }
    }
    while (end_size > counting);
    printf("Years: %i", year);
    // TODO: Print number of years
}

This project generates a family tree of blood types, starting with a child and their two parents, and recursively generating two generations of grandparents for each parent. The blood type of each person is randomly generated from the three possible alleles: A, B, and O.

Detailed explanation of the code:

The code starts by defining a constant for the number of generations, GENERATIONS, and a constant for the indentation length, INDENT_LENGTH.

The create_family function takes an integer parameter, generations, which specifies the number of generations to create. The function first allocates memory for a new person struct using malloc. If there are more generations left to create, the function recursively calls create_family to create the parents of the current person. The parent pointers for the current person are set to the pointers returned by the recursive calls. The function then randomly assigns alleles to the current person based on the alleles of their parents.

The free_family function takes a pointer to a person struct, p, as input. The function first checks if p is NULL, and if it is, it returns without doing anything. Otherwise, it recursively calls free_family to free the memory for p's parents. Finally, it frees the memory for p itself using free.

The print_family function takes a pointer to a person struct, p, as input and an integer, generation, which specifies the current generation. The function first checks if p is NULL, and if it is, it returns without doing anything. Otherwise, it prints the indentation for the current generation, prints the person's blood type, and then recursively calls print_family to print the parents of the current person.

The random_allele function takes no parameters and returns a random blood type allele. The function generates a random integer, r, between 0 and 2, and then returns the corresponding allele: 'A' if r is 0, 'B' if r is 1, and 'O' if r is 2.

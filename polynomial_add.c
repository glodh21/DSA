#include <stdio.h>

struct terms {
    int coeff, exp;
};

typedef struct polynomial {
    int n_term;
    struct terms term[10];
} poly;

int main() {
    poly p[10];
    struct terms all_terms[100]; // Adjust size if necessary
    int n_poly, i, j, k, total_terms = 0;
    int term_found;

    printf("How many polynomials? ");
    scanf("%d", &n_poly);

    // Input polynomials
    for (i = 0; i < n_poly; i++) {
        printf("\nEnter the %dth polynomial", i + 1);
        printf("\nHow many terms? ");
        scanf("%d", &p[i].n_term);

        for (j = 0; j < p[i].n_term; j++) {
            printf("\nEnter coeff and exp: ");
            scanf("%d %d", &p[i].term[j].coeff, &p[i].term[j].exp);
            all_terms[total_terms] = p[i].term[j];
            total_terms++;
        }
    }

   printf("\nInput Polynomials:\n");
    for (i = 0; i < n_poly; i++) {
        printf("Polynomial %d: ", i + 1);
        for (j = 0; j < p[i].n_term; j++) {
            if (p[i].term[j].coeff != 0) {
                if (j > 0 && p[i].term[j].coeff > 0) {
                    printf(" + ");
                }
                if (p[i].term[j].exp == 0) {
                    printf("%d", p[i].term[j].coeff);
                } else if (p[i].term[j].exp == 1) {
                    printf("%dx", p[i].term[j].coeff);
                } else {
                    printf("%dx^%d", p[i].term[j].coeff, p[i].term[j].exp);
                }
            }
        }
        printf("\n");
    }

    // Merge terms
    for (i = 0; i < total_terms; i++) {
        for (j = i + 1; j < total_terms; j++) {
            if (all_terms[i].exp == all_terms[j].exp) {
                all_terms[i].coeff += all_terms[j].coeff;
                // Shift the terms to remove the merged term
                for (k = j; k < total_terms - 1; k++) {
                    all_terms[k] = all_terms[k + 1];
                }
                total_terms--;
                j--; // Adjust index after removing a term
            }
        }
    }

    // Display the final added polynomial
    printf("\nAdded Polynomial is:\n");
    for (i = 0; i < total_terms; i++) {
        if (all_terms[i].coeff != 0) {
            if (i > 0 && all_terms[i].coeff > 0) {
                printf(" + ");
            }
            if (all_terms[i].exp == 0) {
                printf("%d", all_terms[i].coeff);
            } else if (all_terms[i].exp == 1) {
                printf("%dx", all_terms[i].coeff);
            } else {
                printf("%dx^%d", all_terms[i].coeff, all_terms[i].exp);
            }
        }
    }
    printf("\n");

    return 0;
}

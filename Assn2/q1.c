#include "poly.h"
int main() {
  int choice;
  double constant;
  struct polynomial *head1 = NULL;
  struct polynomial *head2 = NULL;
  do{
    printf("1.Input and display a polynomial\n2.Add 2 polynomials\n3.Subtract 2 polynomials\n4.Multiply constant to a polynomial\n5.Multiply 2 polynomials\n6.Find degree of a polynomial\n7.Exit\n");
    printf("\nEnter a choice:");
    scanf(" %d", &choice);
    switch (choice) {
      case 1: head1 = NULL; read_poly(&head1); display_poly(&head1); break;
      case 2:
        printf("P1(x)=:\n");
        head1 = NULL; read_poly(&head1);
        printf("P2(x)=:\n");
        head2 = NULL; read_poly(&head2);
        printf("P1(x)+P2(x):\n");
        add_poly(&head1, &head2);
        break;
      case 3:
        printf("P1(x)=:\n");
        head1 = NULL; read_poly(&head1);
        printf("P2(x)=:\n");
        head2 = NULL; read_poly(&head2);
        printf("P1(x)-P2(x):\n");
        subtract_poly(&head1, &head2);
        break;
      case 4:
        printf("Enter the constant you want to multiply:");
        scanf("%lf", &constant);
        head1 = NULL; read_poly(&head1);
        printf("P(x)*%lf:\n", constant);
        multiply_const(&head1, constant);
        break;
      case 5:
        printf("P1(x)=:\n");
        head1 = NULL; read_poly(&head1);
        printf("P2(x)=:\n");
        head2 = NULL; read_poly(&head2);
        printf("P1(x)*P2(x):\n");
        multiply_poly(&head1, &head2);
        break;
      case 6:
        head1 = NULL; read_poly(&head1);
        printf("Degree of the polynomial:"); display_poly(&head1); printf("is:");
        get_degree(head1);
        printf("\n");
        break;
      case 7: exit(0);
    }
  }while(1);
  return 0;
}


#include <stdio.h>
#include <gsl/gsl_poly.h>


bool find_polynomialroots (double coeff[], double roots[], int size)
{
  int ct_i;
  /* coefficients of P(x) =  -1 + x^5  */
//  double a[6] = { -1, 0, 0, 0, 0, 1 };
//  double z[10];

  gsl_poly_complex_workspace * w = gsl_poly_complex_workspace_alloc (size);

  gsl_poly_complex_solve (coeff, size, w, roots);

  gsl_poly_complex_workspace_free (w);

  for (ct_i = 0; ct_i < size-1; ct_i++)
    {
      printf ("z%d = %+.18f %+.18f\n",
              ct_i, roots[2*ct_i], roots[2*ct_i+1]);
    }

  return 0;
}

int main(void){
    int size = 6;
    double a[6] = { -1, 0, 0, 0, 0, 1 };
    double roots[10];
    return find_polynomialroots(a,roots,size);
}

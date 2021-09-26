#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#endif // _OPENMP

int main()
{
  int nb_taches = 0;

#ifdef _OPENMP
  #pragma omp parallel
  {
    int rang = omp_get_thread_num();
    fprintf(stdout, "   Bonjour depuis le thread de rang %d\n", rang);

    nb_taches = omp_get_num_threads();
  } // omp end parallel
#endif // _OPENMP

  if (nb_taches == 0)
    fprintf(stdout, "   Execution de hello_world en sequentiel\n");
  else
    fprintf(stdout, "   Execution de hello_world en parallele avec %d threads\n", nb_taches);

  return EXIT_SUCCESS;
}

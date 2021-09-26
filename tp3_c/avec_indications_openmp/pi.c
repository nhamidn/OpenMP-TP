////////////////////////////////////////////////////////////////////////////////
// pi.c --- TP3 : calcul de Pi par int�gration num�rique.
//
// Auteur          : Jeremie Gaidamour (CNRS/IDRIS) <gaidamou@idris.fr>
// Cr�� le         : Mon Aug 26 15:51:03 2013
// Dern. mod. par  : Jeremie Gaidamour (CNRS/IDRIS) <gaidamou@idris.fr>
// Dern. mod. le   : Mon Aug 26 15:51:03 2013
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#ifdef _OPENMP
#include <omp.h>
#endif // _OPENMP

// Fonction a integrer
double f(double a) {
  return 4/(1 + a*a);
}

// Dimension par defaut de la taille des matrices
#ifndef VAL_N
#define VAL_N 30000000
#endif

int main() {

  //                  __
  //  But : calcul de || par la methode des rectangles (point milieu).
  //
  //                   / 1
  //                  |       4            __
  //                  |   ----------  dx = ||
  //                  |    1 + x**2
  //                 / 0

#ifdef _OPENMP
  int nb_taches;
#pragma omp parallel
  { nb_taches = omp_get_num_threads(); }
  fprintf(stdout, "\n\n   Execution jacobi en parallele avec %d threads\n", nb_taches);
#endif // _OPENMP

  int n=VAL_N;
  double Pi_calcule;

  // Longueur de l'intervalle d'integration.
  double h = 1.0 / n;

  // Temps CPU de calcul initial.
  clock_t t_cpu_0 = clock();

  // Temps elapsed de reference.
  struct timeval t_elapsed_0;
  gettimeofday(&t_elapsed_0, NULL);

  // Boucle artificielle a ne pas toucher
  for(int k=0; k<100; k++) {

    // Calcul de Pi
    Pi_calcule = 0;
#pragma omp ......................................................
    for(int i = 0; i<n; i++) {
      double x = h * (i + 0.5);
      Pi_calcule += f(x);
    }
    Pi_calcule = h * Pi_calcule;

  }

  // Temps elapsed final
  struct timeval t_elapsed_1;
  gettimeofday(&t_elapsed_1, NULL);
  double t_elapsed = (t_elapsed_1.tv_sec - t_elapsed_0.tv_sec) + (t_elapsed_1.tv_usec - t_elapsed_0.tv_usec) / (double)1000000;

  // Temps CPU de calcul final
  clock_t t_cpu_1 = clock();
  double t_cpu = (t_cpu_1 - t_cpu_0) / (double)CLOCKS_PER_SEC;

  // Ecart entre la valeur estimee et la valeur calculee de Pi.
  double Pi_estime = acos(-1);   // Valeur estim�e de Pi
  double ecart = fabs(Pi_estime - Pi_calcule);

  // Impression du resultat
  fprintf(stdout, "\n\n"
	  "   Nombre d intervalles       : %10d\n"
	  "   | Pi_estime - Pi_calcule | : %10.3E\n"
	  "   Temps elapsed              : %10.3E sec.\n"
	  "   Temps CPU                  : %10.3E sec.\n",
	  n, ecart, t_elapsed, t_cpu
	  );

  return EXIT_SUCCESS;
}

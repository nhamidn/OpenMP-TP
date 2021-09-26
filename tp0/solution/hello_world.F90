program hello_world
!$ use OMP_LIB
  implicit none

  integer :: rang, nb_taches

  nb_taches = 0

  !$OMP PARALLEL PRIVATE(rang)
  !$ nb_taches = OMP_GET_NUM_THREADS()

  !$ rang = OMP_GET_THREAD_NUM()
  !$ print '(3X,"Bonjour depuis le thread de rang ",i2)', rang
  !$OMP END PARALLEL

  if (nb_taches == 0) then
    print '(//,3X,"Execution de hello_world en sequentiel")'
  else
    print '(//,3X,"Execution de hello_world en parallele avec ",i2," threads")', nb_taches
  endif

end program hello_world

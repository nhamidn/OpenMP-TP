# Analyse de performance avec F_PROGINF
export F_PROGINF=no

# Execution monoprocesseur
./pi_mono.exe

# Choix du OMP_SCHEDULE
export OMP_SCHEDULE="STATIC"

# Execution parallele avec 1 thread
export OMP_NUM_THREADS=1
./pi_omp.exe

# Execution parallele avec 2 threads
export OMP_NUM_THREADS=2
./pi_omp.exe

# Execution parallele avec 4 threads
export OMP_NUM_THREADS=4
./pi_omp.exe

# Execution parallele avec 6 threads
export OMP_NUM_THREADS=6
./pi_omp.exe

# Execution parallele avec 8 threads
export OMP_NUM_THREADS=8
./pi_omp.exe

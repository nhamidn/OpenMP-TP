#                               -*- Mode: Sh -*-
# job.sh ---  Job LoadLeveler de soumission de travaux sur IBM x3750
#
# Auteur          : Jalel Chergui (CNRS/IDRIS) <Jalel.Chergui@idris.fr>
# Cr�� le         : Thu Jan 11 16:23:06 2001
# Dern. mod. par  : Jeremie Gaidamour (CNRS/IDRIS) <gaidamou@idris.fr>
# Dern. mod. le   : Fri Aug 02 10:00:19 2013
#

# @ job_type = serial
# @ parallel_threads = 8
# @ wall_clock_limit = 1800
# @ error  = omp_tp7.res
# @ output = omp_tp7.res
# @ class = cours
# @ queue

# Echo des commandes passees
set -x

# On se met dans le repertoire de soumission
cd $LOADL_STEP_INITDIR

# Execution
for exec in $(ls *_omp.exe)
do
    exec=$(basename $exec _omp.exe)
    echo -n "Execution de $exec ... "
    ./run_solutions.sh $exec > omp_tp7_$exec.res 2>&1
    echo "done"
done

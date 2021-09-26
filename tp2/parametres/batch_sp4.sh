#                               -*- Mode: Sh -*-
# job.sh ---  Job LoadLeveler de soumission de travaux sur IBM SP
#
# Auteur          : Jalel Chergui (CNRS/IDRIS) <Jalel.Chergui@idris.fr>
# Cr�� le         : Thu Jan 11 16:23:06 2001
# Dern. mod. par  : Jeremie Gaidamour (CNRS/IDRIS) <gaidamou@idris.fr>
# Dern. mod. le   : Wed Jun 12 11:20:14 2013
#

# @ job_type = serial
# @ resources = ConsumableCpus(8)
# @ job_cpu_limit = 300
# @ error  = omp_tp2.res
# @ output = omp_tp2.res
# @ shell = /bin/ksh
# @ class = cours
# @ queue

# Echo des commandes passees
set -x

# On se met dans le repertoire de soumission
cd $LOADL_STEP_INITDIR

# Execution
./run.sh

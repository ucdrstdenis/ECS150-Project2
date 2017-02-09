#!/bin/bash
# Remote compile script. 
# Copy project to CSIF and compile it
# Only works on Linux for now ...

# Works best if local rsa key is added to
# ~/.ssh/authorized_keys on CSIF acount for
# passwordless rsync / ssh
########################################################

# CSIF Username
USERNAME='rstdenis'

# CSIF computer	
PC='pc46'

# PATH of project on local machine
# keep this script in project directory
PROJECT_FROM=`pwd`

# PATH of project on CSIF account, assume ~/ prefix	
PROJECT_TO="ECS150-Project2"

########################################################

rsync_="$PROJECT_FROM $USERNAME@$PC.cs.ucdavis.edu:~/"
ssh_="$USERNAME@$PC.cs.ucdavis.edu cd $PROJECT_TO; make clean; make"

# Copy the project from host to CSIF client
rsync -azvuhP --del $rsync_

# SSH and compile
ssh $ssh_


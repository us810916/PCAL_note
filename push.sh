#!/bin/bash

##To pull the master
#git pull origin master

echo "commit message: $*"

##To push
git add --all
git status
git commit -m "$*"
git push origin master

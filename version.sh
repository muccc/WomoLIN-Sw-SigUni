#!/bin/bash -e

cp $1/$3 $2/$3

cd $1

if [[ `git status --short` || `git diff origin/master` ]]; then
   GIT_HASH="NO_HASH"
   RELEASE="LOCAL"
   #DATE=`TZ="Europe/Berlin" && date +%d-%m-%Y %H:%M:%S`
   DATE=`date`
else
   GIT_HASH=`git rev-parse --short HEAD`
   RELEASE="RELEASE"
   DATE=`git log -1 --pretty=%ad ${GIT_HASH}` 
fi

sed -i "s/@GIT_HASH@/${GIT_HASH}/g" $2/$3 
sed -i "s/@RELEASE@/${RELEASE}/g" $2/$3 
sed -i "s/@DATE@/${DATE}/g" $2/$3 

#! /bin/sh

rm -rf ./.git
project_name=${PWD##*/}
read -p "Use git locale? [y/n] " lgit

if [ $lgit == "y" ]; then
  git init
  git checkout -b main

  read -p "Use git remote? (repository: $project_name) [y/n] " rgit
  read -p "Github username: " github_username

  if [ $rgit == "y" ]; then
    git remote add origin git@github.com:$github_username/$project_name
  fi
fi

rm -f ./setup.sh

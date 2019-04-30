#!/bin/bash

PROJECT_NAME=project-example

# go to project root
cd $(dirname $(realpath "$0")) && cd ..

# build
./scripts/build.sh $1

# run
echo "Running docker container '$PROJECT_NAME'..." ; echo ""
mkdir -p ./build/data
echo $(pwd)/build/data/
docker run \
    --mount type=bind,src=$(pwd)/build/data/,dst=/opt/project/build/bin/data/ \
    -p 8080:8080 \
    -i \
    $PROJECT_NAME
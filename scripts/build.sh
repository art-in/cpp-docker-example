#!/bin/bash

# creates docker image with necessary tools and builds project inside it.
# options:
# --tools - recreates docker image with build tools even if it already exists.
#           use it when changing build tools or project dependencies.

PROJECT_NAME=project-example

DOCKER_IMAGE_BUILD=$PROJECT_NAME
DOCKER_IMAGE_TOOLS=$PROJECT_NAME-tools

DOCKER_IMAGE_TOOLS_EXISTS=$(docker image ls | grep $DOCKER_IMAGE_TOOLS)

# go to project root
cd $(dirname $(realpath "$0")) && cd ..

# create docker image with build tools if not exists yet
if [ -z "$DOCKER_IMAGE_TOOLS_EXISTS" ] || [ "$1" == "--tools" ] ; then
    echo "Creating docker image '$DOCKER_IMAGE_TOOLS'..."
    docker build --no-cache -f ./docker/Dockerfile-tools -t $DOCKER_IMAGE_TOOLS .
else
    echo "Skip creating docker image '$DOCKER_IMAGE_TOOLS' as it already exists."
fi

# create docker image for build
echo "Creating docker image '$DOCKER_IMAGE_BUILD'..."
docker image rm --force $DOCKER_IMAGE_BUILD
docker build . --no-cache -f ./docker/Dockerfile -t $DOCKER_IMAGE_BUILD
echo "Created docker image '$DOCKER_IMAGE_BUILD'."
 _This project has been created as part of the 42 curriculum by apuddu_
## Description
This project asks you to set up a docker network inside a vm, using compose. The network runs wordpress in tandem with nginx and mariadb. 
These three services are hosted on different containers. 
Docker volumes are used to make the database persistent and to share the source files across wordpress and nginx, as defined by the subject

## Instructions
To run this ... # TODO complete

## Resources
- [nginx install guide for alpine](https://nginx.org/en/linux_packages.html#Alpine)


### AI usage
I used LLMs as a learning tool and to help correct this readme.  
Nothing was copy pasted from an LLM to this project

# Project description
## What's a container?
A **container** is a user-space that's separated from the main user-space. This allows having a clean environment in which to install and run applications without interfering with the main environment. It being portable also allows for easy installation, copying and deployment.  
Notice that containers are NOT virtual machines, as they don't use an hypervisor, and directly run on the host's OS.  
One of the main isolation mechanisms used by containers is at file system level: containers have their own file system that's completely separated from the host (with configurable exceptions)
A container **image** is a snapshot that defines the container's environment at boot.  

**Docker** is one of the most used containerization platforms, and provides standard ways to build container images and container networks.  
Docker Hub is a platform that hosts images that can be easily downloaded, run and published. 

## Building an image
To create an image, docker needs a `Dockerfile`, which has a simple syntax that allows changing files and executing commands. Images are built incrementally, starting from other images. This also helps shorten build times: by caching intermediate images, docker can avoid restarting the build from scratch when the `Dockerfile` is modified.

The command to build a docker image is  
`$docker build <Dockerfile dir> -t img_name`  
Images can then be run by using `docker run img_name`

## Composing containers
Containers can also be organized into a network. This is often used as a way to separate responsibilities across different containers. The network can be configured by using a `compose.yaml` file, where the configuration of all docker images is specified. 

The `docker compose up` command can be used to set up the network and start the containers as defined in `compose.yaml`



FROM ubuntu:16.04

MAINTAINER inocop

RUN sed -i.bak -e "s%http://archive.ubuntu.com/ubuntu/%http://ftp.jaist.ac.jp/pub/Linux/ubuntu/%g" /etc/apt/sources.list

#Update the package lists
RUN apt-get update

# Install *gcc*(and related dependencies), cmake, Python, node.js, Java(optional, only needed for Closure Compiler minification), git, apache2
RUN apt-get -y install  build-essential \
                        cmake \
                        python \
                        nodejs \
                        default-jre \
                        git-core \
                        apache2 \
                        wget

WORKDIR /tmp
RUN wget https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz
RUN tar -zxvf emsdk-portable.tar.gz
WORKDIR /tmp/emsdk-portable

# Fetch the latest registry of available tools.
RUN ./emsdk update

# Download and install the latest SDK tools.
RUN ./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes ~/.emscripten file)
RUN ./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
RUN source ./emsdk_env.sh

# exec
CMD apachectl -D FOREGROUND

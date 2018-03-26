#!/bin/bash

set -eux

# Setting remote desktop
apt-get -y install fluxbox \
                   x11vnc \
                   xvfb \
                   net-tools

git clone https://github.com/novnc/noVNC.git /opt/novnc \
&&  git clone https://github.com/kanaka/websockify /opt/novnc/utils/websockify

# Install opengl
apt-get -y install freeglut3-dev \
                   libglfw3-dev \
                   libglew-dev \
                   libglm-dev \
                   mesa-utils \
                   vim

# Install debugger
apt-get -y install g++ \
                   gdb \
                   gdbserver

# create symbolic link
ln -s /opt/src/output_wasm /opt/novnc/output_wasm \
&&  ln -s /opt/src/output_asm /opt/novnc/output_asm

# Clean up
apt-get autoclean \
&& apt-get autoremove \
&& rm -rf /var/lib/apt/lists/*
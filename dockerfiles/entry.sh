#!/bin/bash

set -eux

/usr/bin/Xvfb :0 -screen 0 1024x600x24 &
/usr/bin/x11vnc -display :0 -forever -shared &
/usr/bin/fluxbox -display :0 &
/opt/novnc/utils/launch.sh --vnc localhost:5900 --listen 6080 &

tail -f /dev/null
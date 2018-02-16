# docker-emscripten-develop

## Local machine environment

| #   | Version |
| --- | ---|
| OS  | Windows10 pro |
| VM  | Docker version 17.12.0-ce, build c97c6d6 |
| IDE | Visual Studio 2017 |


## Compile & debug environment
```
$ git clone https://github.com/inocop/docker-emscripten-develop.git
$ cd docker-emscripten-develop
$ docker-compose up -d
```

## Debugging

#### Visual Studio 2017

1. Enable IntelliSense
```
$ docker exec docker_emscripten bash -c "sh /opt/src/rsync_lib.sh"
```

[Project property] > [Configuration properties] > [Linker] > [Input]  
Library dependent file = m;GL;GLU;glut

[Project property] > [Configuration properties] > [VC++ directory]  
Include directory += $(ProjectDir)../lib

2. Connection SSH

[Option] > [Cross platform] > [Connection Manager]
```
Host: 127.0.0.1
Port: 2020
User: root
Auth type: Password
Password: root
```

[Project property] > [Configuration properties] > [General]  
Remote build machine = 127.0.0.1 (username=root, port=2020, authentication=Password)

3. Debug run

#### Show

http://localhost:6080/vnc.html


## Emscripten

#### Compile
```
$ docker exec -it docker_emscripten bash
# /opt/src/build_wasm.sh /opt/src/sample/main.c
```

#### Show

http://localhost:6080/em_wasm/
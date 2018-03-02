# docker-emscripten-develop

## Local machine environment

| #      | Version |
| :----- | :------ |
| OS     | Windows10 pro |
| VM     | Docker version 17.12.0-ce, build c97c6d6 |
| Editor | Visual Studio Code |
| vscode plugin | C/C++ |


## Compile & debug environment

```
$ git clone https://github.com/inocop/docker-emscripten-develop.git
$ cd docker-emscripten-develop
$ docker-compose up -d
```

## Load Linux library (for Enable intelliSense)

```
$ docker exec docker_emscripten bash -c 'sh /opt/src/rsync_include.sh'
```

## Run on Linux

#### Run

Start vscode debug

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

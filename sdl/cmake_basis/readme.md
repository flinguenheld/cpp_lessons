### Basic directory structure

Thanks to : https://www.willusher.io/pages/sdl2/

```
cmake_basis/
    build/
        executables in here
    res/
      myApp/
            myApp's assets are stored here
    myApp/
        src/
            myApp's source code
    include/
        Headers shared between apps
```

##### To compile:

```
mkcd build
cmake .. && make && ./myApp/myapp
```

##### To generate LSP files:

```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
```

# psdk-demo

## JSON Parsing

`git@github.com:nlohmann/json.git`

## Build

``` bash
cmake .
cmake --build .
```

## Test

``` bash
./PSDK_Demo_3.53.1 '{"total":"40.4","tax":"3.434","taxRate":"0.085","grandTotal":"43.833999999999996"}' 192.168.31.27
```

Where the IP is the address of the terminal you are testing

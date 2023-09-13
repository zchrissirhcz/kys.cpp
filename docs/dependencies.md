## Prepare ~/.bashrc or ~/.zshrc
```bash
if [ -f ~/.pathrc ]; then
    . ~/.pathrc
fi
```

Paste the above config in either `~/.bashrc` or `~/.zshrc`.

We will put every customed installation paths inside `~/.pathrc`.

## Install CMake

The newer the better. Currently(2023.09.13) I use 3.27.4

vim `~/.pathrc`
```bash
CMAKE_BIN_DIR=/home/zz/soft/cmake-3.27.4/bin
export PATH=$VCPKG_BIN_DIR:$CMAKE_BIN_DIR:$PATH
```

## Install vcpkg
```bash
cd ~/work
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# You may setup an proxy for fast download, c.f. https://github.com/microsoft/vcpkg/issues/2350
# export HTTP_PROXY=http://xxx:yyy@proxy.com:1234
# export HTTPS_PROXY=http://xxx:yyy@proxy.com:1234
./bootstrap-vcpkg.sh
```

vim `~/.pathrc` by adding:
```bash
VCPKG_BIN_DIR=$HOME/work/vcpkg
export VCPKG_DISABLE_METRICS=1
export PATH=$VCPKG_BIN_DIR:$PATH
```

## Use fixed version of dependencies

Though downvoted, disliked, we still try it - the vcpkg's manifest mode, with `cvpkg.json` file, specifying each imported libraries' version. (ref: https://github.com/microsoft/vcpkg/issues/21357)

https://learn.microsoft.com/zh-cn/vcpkg/reference/vcpkg-json

Steps:
- Write vcpkg.json
- Get initial baseline value: (https://github.com/microsoft/vcpkg/discussions/25622)
```bash
vcpkg x-update-baseline --add-initial-baseline
```
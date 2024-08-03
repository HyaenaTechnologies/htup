[C Language]: https://isocpp.org/
[Documentation]: https://github.com/HyaenaTechnologies/htup/tree/main/doc
[Fleet]: https://jetbrains.com/fleet/
[VSCode]: https://code.visualstudio.com/docs
[Zig Language]: https://ziglang.org/

# htup

htup is a system update tool

[Documentation][Documentation]

## Build

- [C][C Language]
- [JetBrains Fleet][Fleet]
- [Visual Studio Code][VSCode]
- [Zig][Zig Language]

```shell
git clone

zig cc ./src/*.h

zig cc ./src/*.c -include-pch ./src/*.pch -o ./bin/htup -target x86_64-linux

rm ./src/*.pch
```

OR

```shell
git clone

clang ./src/*.h

clang ./src/*.c -include-pch ./src/*.pch -o ./bin/htup

rm ./src/*.pch
```

## RUN

```shell
SUDO ./bin/htup -h
```
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

zig cc ./src/*.c -include ./bin/*.h -o ./bin/htup -target x86_64-linux
```

```shell
git clone

clang ./src/*.c -include ./bin/*.h -o ./bin/htup
```

## Install

```shell
echo 'export PATH="$PATH:/usr/lib/htup"' >> ~/.profile
```
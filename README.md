# Lunar

This is *Lunar*, a completely standalone implementation of the 5.5 version of the [Lua programming language](https://lua.org) written in a modern standard of C++. *Lunar* is still in its infancy, so its stability or even its basic functionality cannot be guaranteed at this time.

To ensure this is as clean as possible, this project does not rely on any Lua code, or read any original source code in the primary development repositories. This project is implemented purely by reading the publicly available [reference manual](https://www.lua.org/manual/5.5/)

## Why?

Fair question. I've started Lunar as a personal project. I don't want to compete with the original Lua in any capacity, nor step on the heels of any other projects. I also started this partially as my own answer to the [`sol2`](https://github.com/ThePhD/sol2) repository being abandoned, with its last known commits being over a year ago as of November 2026.
<!-- NOTE: update this if sol2 randomly comes back to life. -->

Besides those... it's purely personal. I'm not chasing the **fastest possible Lua**, or to extend it with my own features. This is just Lua, importable, linkable, extremely boring. Like any good software.

## Other Lua Versions?

Not yet! I want to ensure 5.5 is in a stable place before I start accepting PRs for other versions, forks, or a JIT implementation.

## Compiling

> [!NOTE]
> This section is left intentionally blank as there is nothing to compile

## Licenses

Lunar as a project is licensed under the permissive **zlib license** that you can find in the [`LICENSE`](./LICENSE) file.

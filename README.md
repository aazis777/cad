# cad

A recreational-purpose, slightly edgy but undeniably cool *cat* command clone for UNIX/Linux systems.  

## Getting Started

Clone the repo like a normal way to clone github repo project:

```bash
git clone https://github.com/aazis777/cad.git
cd ./cad
```

## Build

There are two ways to build cad:

1. Makefile
2. Shell script / Bash

If you’re a Makefile enjoyer, just do:

```bash
make        # build
make all    # or explicitly
make run    # build & run
```

If you’re more of a script minimalist, go with:

```bash
chmod +x ./build.sh   # give it some rights
./build.sh            # build
```

Either way, you’ll end up with an executable named cad.
Run it, flex it, and enjoy it.

---

**OPTIONAL**: Install to your local system
If you wanna execute *cad* globally, follow these steps:

```bash
mkdir -p ~/.local/bin
```

- If you using Bash:
```bash
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
```

- If you using Zsh:
```bash
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
```

## Examples

Say you’ve got a file named file.c that looks like this:

```c
#include <stdio.h>

int main(void)
{
    printf("File 1\n");
    return 0;
}
```

And you’re curious about what’s inside (even though you already know it lol) just by typing:

```bash
./cad file.c
```

```bash
#include <stdio.h>

int main(void)
{
    printf("File 1\n");
    return 0;
}
```

Boom — clean output.
But you can spice it up with some flags:

```bash
./cad -ln -fn file.c
```

```bash
file.c

1   #include <stdio.h>
2   int main(void)
3   {
4       printf("File 1\n");
5       return 0;
6   }
```

And that's it, it's pretty clean yet readable, right?

### Options

Flag            Description

-h, --help      Show quick menu available commands
-v, --version   Show cad version
-ln	            Show line numbers
-fn	            Show filename at the top
-show-all       Show both line numbers and filename

## What's next?

Because cad isn’t about being better — it’s about being yours.
A tiny tool that reminds you why you started coding in the first place:
    "to build stuff, no matter how small, and have a little fun doing it."


## License

MIT — use it, hack it, break it, fix it.
Just don’t forget where it came from:)

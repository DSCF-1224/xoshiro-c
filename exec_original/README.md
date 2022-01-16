# `exec_original/include`

## Objective

- Execute programs using the original source code.
- Compare the values of the original and my implementation.

## File Organization

- `./`
  - (local)&nbsp;[compile_all.sh](compile_all.sh)
    - compile all programs to execute the original generators.
  - (local)&nbsp;[run_all.sh](run_all.sh)
    - run all programs to execute the original generators.
- `include`
  - (local)&nbsp;[fprintf_sample_64bit.c](fprintf_sample_64bit.c)
  - (link)&nbsp;[xoroshiro1024plusplus.c](https://prng.di.unimi.it/xoroshiro1024plusplus.c)
  - (link)&nbsp;[xoroshiro1024star.c](https://prng.di.unimi.it/xoroshiro1024star.c)
  - (link)&nbsp;[xoroshiro1024starstar.c](https://prng.di.unimi.it/xoroshiro1024starstar.c)
  - (link)&nbsp;[xoroshiro128plus.c](https://prng.di.unimi.it/xoroshiro128plus.c)
  - (link)&nbsp;[xoroshiro128plusplus.c](https://prng.di.unimi.it/xoroshiro128plusplus.c)
  - (link)&nbsp;[xoroshiro128starstar.c](https://prng.di.unimi.it/xoroshiro128starstar.c)
  - (link)&nbsp;[xoshiro256plus.c](https://prng.di.unimi.it/xoshiro256plus.c)
  - (link)&nbsp;[xoshiro256plusplus.c](https://prng.di.unimi.it/xoshiro256plusplus.c)
  - (link)&nbsp;[xoshiro256starstar.c](https://prng.di.unimi.it/xoshiro256starstar.c)
  - (link)&nbsp;[xoshiro512plus.c](https://prng.di.unimi.it/xoshiro512plus.c)
  - (link)&nbsp;[xoshiro512plusplus.c](https://prng.di.unimi.it/xoshiro512plusplus.c)
  - (link)&nbsp;[xoshiro512starstar.c](https://prng.di.unimi.it/xoshiro512starstar.c)
- `xoroshiro1024plusplus`
  - [main.c](xoroshiro1024plusplus/main.c)
- `xoroshiro1024star`
  - [main.c](xoroshiro1024star/main.c)
- `xoroshiro1024starstar`
  - [main.c](xoroshiro1024starstar/main.c)
- `xoroshiro128plus`
  - [main.c](xoroshiro128plus/main.c)
- `xoroshiro128plusplus`
  - [main.c](xoroshiro128plusplus/main.c)
- `xoroshiro128starstar`
  - [main.c](xoroshiro128starstar/main.c)
- `xoshiro256plus`
  - [main.c](xoshiro256plus/main.c)
- `xoshiro256plusplus`
  - [main.c](xoshiro256plusplus/main.c)
- `xoshiro256starstar`
  - [main.c](xoshiro256starstar/main.c)
- `xoshiro512plus`
  - [main.c](xoshiro512plus/main.c)
- `xoshiro512plusplus`
  - [main.c](xoshiro512plusplus/main.c)
- `xoshiro512starstar`
  - [main.c](xoshiro512starstar/main.c)

## How to Use

Change the current directory to the directory where the README is located.  
Then, execute the following command.

```shell
./run_all.sh
```

<!-- EOF -->

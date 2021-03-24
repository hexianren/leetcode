Introduction
-------------------------

lzbench is an in-memory benchmark of open-source LZ77/LZSS/LZMA compressors. It joins all compressors into a single exe.
At the beginning an input file is read to memory.
Then all compressors are used to compress and decompress the file and decompressed file is verified.
This approach has a big advantage of using the same compiler with the same optimizations for all compressors.
The disadvantage is that it requires source code of each compressor (therefore Slug or lzturbo are not included).

|Status   |
|---------|
| [![Build Status][travisMasterBadge]][travisLink] [![Build status][AppveyorMasterBadge]][AppveyorLink]  |

[travisMasterBadge]: https://travis-ci.org/inikep/lzbench.svg?branch=master "Continuous Integration test suite"
[travisLink]: https://travis-ci.org/inikep/lzbench
[AppveyorMasterBadge]: https://ci.appveyor.com/api/projects/status/u7kjj8ino4gww40v/branch/master?svg=true "Visual test suite"
[AppveyorLink]: https://ci.appveyor.com/project/inikep/lzbench


Usage
-------------------------

```
usage: lzbench [options] input [input2] [input3]

where [input] is a file or a directory and [options] are:
 -b#   set block/chunk size to # KB (default = MIN(filesize,1747626 KB))
 -c#   sort results by column # (1=algname, 2=ctime, 3=dtime, 4=comprsize)
 -e#   #=compressors separated by '/' with parameters specified after ',' (deflt=fast)
 -iX,Y set min. number of compression and decompression iterations (default = 1, 1)
 -j    join files in memory but compress them independently (for many small files)
 -l    list of available compressors and aliases
 -m#   set memory limit to # MB (default = no limit)
 -o#   output text format 1=Markdown, 2=text, 3=text+origSize, 4=CSV (default = 2)
 -p#   print time for all iterations: 1=fastest 2=average 3=median (default = 1)
 -r    operate recursively on directories
 -s#   use only compressors with compression speed over # MB (default = 0 MB)
 -tX,Y set min. time in seconds for compression and decompression (default = 1, 2)
 -v    disable progress information
 -x    disable real-time process priority
 -z    show (de)compression times instead of speed

Example usage:
  lzbench -ezstd filename = selects all levels of zstd
  lzbench -ebrotli,2,5/zstd filename = selects levels 2 & 5 of brotli and zstd
  lzbench -t3 -u5 fname = 3 sec compression and 5 sec decompression loops
  lzbench -t0 -u0 -i3 -j5 -ezstd fname = 3 compression and 5 decompression iter.
  lzbench -t0u0i3j5 -ezstd fname = the same as above with aggregated parameters
```


Compilation
-------------------------
For Linux/MacOS/MinGW (Windows):
```
make
```

For 32-bit compilation:
```
make BUILD_ARCH=32-bit

```

The default linking for Linux is dynamic and static for Windows. This can be changed with `make BUILD_STATIC=0/1`.

To remove one of compressors you can add `-DBENCH_REMOVE_XXX` to `DEFINES` in Makefile (e.g. `DEFINES += -DBENCH_REMOVE_LZ4` to remove LZ4).
You also have to remove corresponding `*.o` files (e.g. `lz4/lz4.o` and `lz4/lz4hc.o`).

lzbench was tested with:
- Ubuntu: gcc 4.8 (both 32-bit and 64-bit), 4.9, 5 (32-bit and 64-bit), 6 (32-bit and 64-bit), 7, 8, 9 and clang 3.5, 3.6, 3.8, 3.9, 4.0, 5.0, 6.0, 7, 8, 9
- MacOS: Apple LLVM version 9.1.0
- MinGW (Windows): gcc 5.3 (32-bit), gcc 6.2 (both 32-bit and 64-bit), gcc 9.1



Supported compressors
-------------------------
**Warning**: some of the compressors listed here have security issues and/or are
no longer maintained.  For information about the security of the various compressors,
see the [CompFuzz Results](https://github.com/nemequ/compfuzz/wiki/Results) page.

 - [blosclz 2.0.0](https://github.com/Blosc/c-blosc2)
 - [brieflz 1.3.0](https://github.com/jibsen/brieflz)
 - [brotli 1.0.9](https://github.com/google/brotli)
 - [bzip2 1.0.8](http://www.bzip.org/downloads.html)
 - [crush 1.0](https://sourceforge.net/projects/crush/)
 - [csc 2016-10-13](https://github.com/fusiyuan2010/CSC) - WARNING: it can throw SEGFAULT compiled with Apple LLVM version 7.3.0 (clang-703.0.31)
 - [density 0.14.2](https://github.com/centaurean/density) - WARNING: it contains bugs (shortened decompressed output))
 - [fastlz 0.5.0](http://fastlz.org)
 - [fast-lzma2 1.0.1](https://github.com/conor42/fast-lzma2)
 - [gipfeli 2016-07-13](https://github.com/google/gipfeli)
 - [glza 0.8](https://encode.su/threads/2427-GLZA)
 - [libdeflate v1.6](https://github.com/ebiggers/libdeflate)
 - [lizard v1.0 (formerly lz5)](https://github.com/inikep/lizard)
 - [lz4/lz4hc v1.9.3](https://github.com/lz4/lz4)
 - [lzf 3.6](http://software.schmorp.de/pkg/liblzf.html)
 - [lzfse/lzvn 1.0](https://github.com/lzfse/lzfse)
 - [lzg 1.0.10](https://liblzg.bitsnbites.eu/)
 - [lzham 1.0](https://github.com/richgel999/lzham_codec)
 lzjb 2010
 - [lzlib 1.12-rc2](http://www.nongnu.org/lzip)
 - [lzma v19.00](http://7-zip.org)
 - [lzmat 1.01 v1.0](https://github.com/nemequ/lzmat) - WARNING: it contains bugs (decompression error; returns 0); it can throw SEGFAULT compiled with gcc 4.9+ -O3
 - [lzo 2.10](http://www.oberhumer.com/opensource/lzo)
 - [lzrw 15-Jul-1991](https://en.wikipedia.org/wiki/LZRW)
 - [lzsse 2019-04-18 (1847c3e827)](https://github.com/ConorStokes/LZSSE)
 - [pithy 2011-12-24](https://github.com/johnezang/pithy) - WARNING: it contains bugs (decompression error; returns 0)
 - [quicklz 1.5.0](http://www.quicklz.com)
 - [shrinker 0.1](https://code.google.com/p/data-shrinker) - WARNING: it can throw SEGFAULT compiled with gcc 4.9+ -O3
 - [slz 1.2.0](http://www.libslz.org/) - only a compressor, uses zlib for decompression
 - [snappy 2020-07-11 (4dd277f)](https://github.com/google/snappy)
 - [tornado 0.6a](http://freearc.org)
 - [ucl 1.03](http://www.oberhumer.com/opensource/ucl/)
 - [wflz 2015-09-16](https://github.com/ShaneWF/wflz) - WARNING: it can throw SEGFAULT compiled with gcc 4.9+ -O3
 - [xpack 2016-06-02](https://github.com/ebiggers/xpack)
 - [xz 5.2.4](https://tukaani.org/xz/)
 - [yalz77 2015-09-19](https://github.com/ivan-tkatchev/yalz77)
 - [yappy 2014-03-22](https://encode.su/threads/2825-Yappy-(working)-compressor) - WARNING: fails to decompress properly on ARM
 - [zlib 1.2.11](http://zlib.net)
 - [zling 2018-10-12](https://github.com/richox/libzling) - according to the author using libzling in a production environment is not a good idea
 - [zstd 1.4.9](https://github.com/facebook/zstd)
 - [nvcomp 1.2.2](https://github.com/NVIDIA/nvcomp) - If CUDA is available.


CUDA support
-------------------------

If CUDA is available, lzbench supports additional compressors:
  - [cudaMemcpy](https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__MEMORY.html#group__CUDART__MEMORY_1gc263dbe6574220cc776b45438fc351e8) - similar to the reference `memcpy` benchmark, using GPU memory
  - [nvcomp 1.2.2](https://github.com/NVIDIA/nvcomp) LZ4 GPU-only compressor

The directory where the CUDA compiler and libraries are available can be passed to `make` via the `CUDA_BASE` variable, *e.g.*:
```
make CUDA_BASE=/usr/local/cuda
```

Benchmarks
-------------------------

The following results are obtained with `lzbench 1.8` with the `-t16,16 -eall` options using 1 core of Intel Core i7-8700K, Ubuntu 18.04.3 64-bit, and clang 9.0.1
with ["silesia.tar"](https://drive.google.com/file/d/0BwX7dtyRLxThenZpYU9zLTZhR1k/view?usp=sharing) which contains tarred files from [Silesia compression corpus](http://sun.aei.polsl.pl/~sdeor/index.php?page=silesia).
The results sorted by ratio are available [here](lzbench18_sorted.md).

| Compressor name         | Compress.  |Decompress. | Ratio |
| ---------------         | -----------| -----------| ----- |
| memcpy                  | 10362 MB/s | 10790 MB/s |100.00 |
| bzip2 1.0.8 -1          |    18 MB/s |    52 MB/s | 28.54 |
| bzip2 1.0.8 -5          |    16 MB/s |    44 MB/s | 26.29 |
| bzip2 1.0.8 -9          |    15 MB/s |    41 MB/s | 25.75 |
| lz4hc 1.9.2 -1          |   131 MB/s |  4071 MB/s | 39.54 |
| lz4hc 1.9.2 -4          |    81 MB/s |  4210 MB/s | 37.65 |
| lz4hc 1.9.2 -9          |    33 MB/s |  4378 MB/s | 36.75 |
| lz4hc 1.9.2 -12         |    11 MB/s |  4427 MB/s | 36.45 |
| lzma 19.00 -0           |    34 MB/s |    80 MB/s | 30.20 |
| lzma 19.00 -2           |    25 MB/s |    91 MB/s | 27.77 |
| lzma 19.00 -4           |    14 MB/s |    95 MB/s | 26.99 |
| lzma 19.00 -5           |  3.28 MB/s |   103 MB/s | 23.45 |
| lzma 19.00 -9           |  2.66 MB/s |   107 MB/s | 22.98 |
| zlib 1.2.11 -1          |   119 MB/s |   383 MB/s | 36.45 |
| zlib 1.2.11 -6          |    35 MB/s |   407 MB/s | 32.19 |
| zlib 1.2.11 -9          |    14 MB/s |   404 MB/s | 31.92 |

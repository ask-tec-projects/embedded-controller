# Metronome

## Building

Requires PlatformIO CLI.

```
$ sudo pio run
```

## Documentation

### User manual

Build using

```
$ cd doc
$ make user_manual.pdf
```

A PDF previewer must be specified in `$HOME/.latexmkrc` for previewing.

### Code specification

Build using

```
$ doxygen Doxyfile
$ cd latex
$ make
```
